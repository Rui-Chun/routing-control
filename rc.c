#include "rc.h"

int readcmd(char* cmd, char* output)
{
	char buffer[BFSIZE];
	FILE  *pipe = popen(cmd, "r");
	if(!pipe) return -1;
	output[0] = 0;
	while(!feof(pipe))
	{
		if(fgets(buffer, BFSIZE, pipe))
		{
			strcat(output, buffer);
		}
	}
	
	pclose(pipe);
	return 0;
}

int cmd(char* cmd)
{

	FILE  *pipe = popen(cmd, "r");
	if(!pipe) return -1;
	
	pclose(pipe);
	return 0;
}

int str2num(char *str, int* num, int base, int len)
{
	char *ptr, *ptr1;
	int idx=0;
	num[idx] = strtol(str,&ptr, base);
	idx++;
	ptr++;
	
	while(idx<len)
	{
		num[idx] = strtol(ptr,&ptr1, base);
		ptr = ptr1+1;
		idx++;
	}
	return 0;
}

int get_info_str(char* start, char* temp_info, char* info_val)
{
	char *loc, *loc2;
	int val_len = 0; // length of the info val
	
	loc = strstr(start, temp_info);
	loc2 = strstr(loc, "\n");
	val_len = loc2 - loc - strlen(temp_info) ;
	strncpy(info_val, loc + strlen(temp_info) , val_len);
	info_val[val_len] = '\0';
}

int get_stas(struct sta* stalist, int *num)
{
	char sta_info[BFSIZE];
	char buff[BFSIZE];
	char *start;
	
	char temp_info[100];
	char info_val[100];
	int idx = 0;
	
	
	if(readcmd("iw dev wlan0 station dump", sta_info) != 0)
		return -1;
	start = sta_info;
	if(DEBUG) printf("station info : \n %s", sta_info);
	
	// first time
	
	while(start)
	{
		strcpy(temp_info, "Station ");
		strncpy(stalist[idx].mac.str_v, start+ strlen(temp_info), 17);
		stalist[idx].mac.str_v[17] = '\0';
		str2num(stalist[idx].mac.str_v, stalist[idx].mac.int_v, 16, 6);
		
		strcpy(temp_info, "rx bytes:	");
		get_info_str(start, temp_info, info_val);
		stalist[idx].rxbytes = atoi(info_val);
		
		strcpy(temp_info, "rx packets:	");
		get_info_str(start, temp_info, info_val);
		stalist[idx].rxpackets = atoi(info_val);
		
		strcpy(temp_info, "tx bytes:	");
		get_info_str(start, temp_info, info_val);
		stalist[idx].txbytes = atoi(info_val);

		
		strcpy(temp_info, "tx packets:	");
		get_info_str(start, temp_info, info_val);
		stalist[idx].txpackets = atoi(info_val);
		
		strcpy(temp_info, "tx retries:	");
		get_info_str(start, temp_info, info_val);
		stalist[idx].txretries = atoi(info_val);
		
		strcpy(temp_info, "tx failed:	");
		get_info_str(start, temp_info, info_val);
		stalist[idx].txfailed = atoi(info_val);

		strcpy(temp_info, "signal avg:	");
		get_info_str(start, temp_info, info_val);
		stalist[idx].signal = atoi(info_val);
		
		strcpy(temp_info, "tx bitrate:	");
		get_info_str(start, temp_info, info_val);
		stalist[idx].txbitrate = atof(info_val);

		strcpy(temp_info, "rx bitrate:	");
		get_info_str(start, temp_info, info_val);
		stalist[idx].rxbitrate = atof(info_val);

		if(DEBUG) 
		{
			printf("%s \n", stalist[idx].mac.str_v);
			printf("%d \n", stalist[idx].rxbytes);
			printf("%d \n", stalist[idx].rxpackets);
			printf("%d \n", stalist[idx].txbytes);
			printf("%d \n", stalist[idx].txpackets);
			printf("%d \n", stalist[idx].txretries);
			printf("%d \n", stalist[idx].txfailed);
			printf("%d \n", stalist[idx].signal);
			printf("%f \n", stalist[idx].txbitrate);
			printf("%f \n", stalist[idx].rxbitrate);
		}
		
		// loop for next stations
		strcpy(temp_info, "Station ");
		start = strstr(start + 20, temp_info);
		idx++;

	}
	
	*num = idx;
	
	return 0;
}

int ip_mac(char* ip, char* mac, int ip_to_mac)
{
	char ip_mac_table[BFSIZE*5];
	char buffer[BFSIZE];
	char *loc, *loc2;
	
	FILE *fp = fopen("ip-mac", "r");
	if(!fp) return -1;
	
	while(!feof(fp))
	{
		if(fgets(buffer, BFSIZE, fp))
		{
			strcat(ip_mac_table, buffer);
		}
	}
	
	if(DEBUG)	printf("ip_mac table: \n%s", ip_mac_table);
	
	
	if(ip_to_mac)
	{				
		loc = strstr(ip_mac_table,ip);
		loc2 = strstr(loc,":");
		strncpy(mac, loc2-2, 17);
		strcat(mac, "\0");
	}
	else
	{
		loc = strstr(ip_mac_table,mac);
		loc2 = strstr(loc-3," ");
		// printf("loc2-loc= %d\n",loc2-loc);
		strncpy(ip, loc - 13, loc2 - loc + 13);
		strcat(ip, "\0");
	}

	return 0;
}

int get_local_mac(char* local_mac)
{
	char buff[BFSIZE];
	char *loc;
	readcmd("ifconfig wlan0 | grep \"ether\" ", buff);
	printf("buff = %s \n",buff);
	loc = strstr(buff, "ether");
	strncpy(local_mac, loc + 6, 17);
	return 0;
}


int set_tx_power(struct local_info *local_ptr)
{
	return 0;
}

int set_rate_ctrl(struct local_info *local_ptr)
{
	int i, j;
	struct sta *stas = local_ptr->stalist;
	char buff[50];
	FILE *fp;

	// need to change the firmware and driver to make it easier 

	for(i=0;i<local_ptr->sta_num;i++)
	{
		fp = fopen("/proc/ath9k-htc-rate","w");
		memset(buff,0,sizeof(char)*50);

		strcat(buff,"0");
		strcat(buff," ");

		for(j=0;j<6;j++)
		{
			strcat(buff,itoa(stas[i].mac.int_v[j]));
			strcat(buff," ");
		}
		for(j=0;j<4;j++)
		{
			strcat(buff,itoa(stas[i].rete_series.rate_idx[j]));
			strcat(buff," ");
			strcat(buff,itoa(stas[i].rete_series.tries[j]));
			strcat(buff," ");
		}

		if(!fprintf(fp, buff)) 
			printf("cannot write /proc/ath9k-htc-rate. \n");

		fclose(fp);
	}
}

int set_routing_strl(struct local_info *local_ptr)
{
	// call cmd() to change routing table
	return 0;
}


