#include "rc.h"

int readcmd(char* cmd, char* output)
{
	char buffer[BFSIZE];
	FILE  *pipe = popen(cmd, "r");
	if(!pipe) return -1;
	
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

int get_stas(struct sta* stalist)
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
		strncpy(stalist[idx].mac_addr_str, start+ strlen(temp_info), 17);
		stalist[idx].mac_addr_str[17] = '\0';
		if(DEBUG) printf("%s \n", stalist[idx].mac_addr_str);
		
		strcpy(temp_info, "rx bytes:	");
		get_info_str(start, temp_info, info_val);
		stalist[idx].rxbytes = atoi(info_val);
		printf("%d \n", atoi(info_val));
		
		strcpy(temp_info, "rx packets:	");
		get_info_str(start, temp_info, info_val);
		stalist[idx].rxpackets = atoi(info_val);
		printf("%d \n", atoi(info_val));
		
		strcpy(temp_info, "tx bytes:	");
		get_info_str(start, temp_info, info_val);
		stalist[idx].txbytes = atoi(info_val);
		printf("%d \n", atoi(info_val));
		
		strcpy(temp_info, "tx packets:	");
		get_info_str(start, temp_info, info_val);
		stalist[idx].txpackets = atoi(info_val);
		printf("%d \n", atoi(info_val));
		
		strcpy(temp_info, "tx retries:	");
		get_info_str(start, temp_info, info_val);
		stalist[idx].txretries = atoi(info_val);
		printf("%d \n", atoi(info_val));
		
		strcpy(temp_info, "tx failed:	");
		get_info_str(start, temp_info, info_val);
		stalist[idx].txfailed = atoi(info_val);
		printf("%d \n", atoi(info_val));

		strcpy(temp_info, "signal avg:	");
		get_info_str(start, temp_info, info_val);
		stalist[idx].signal = atoi(info_val);
		printf("%d \n", atoi(info_val));
		
		strcpy(temp_info, "tx bitrate:	");
		get_info_str(start, temp_info, info_val);
		stalist[idx].txbitrate = atof(info_val);
		printf("%f \n", atof(info_val));

		strcpy(temp_info, "rx bitrate:	");
		get_info_str(start, temp_info, info_val);
		stalist[idx].rxbitrate = atof(info_val);
		printf("%f \n", atof(info_val));
		
		
		// loop for rest stations
		strcpy(temp_info, "Station ");
		start = strstr(start + 20, temp_info);
		idx++;
	}
	
	
	return 0;
}

