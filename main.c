#include "rc.h"



int test()
{
	// char info[BFSIZE];
	// if(readcmd("iw dev wlan0 station dump",info) == 0)
	// 	printf("%s \n", info);
	// else
	// 	printf("error.\n");
		
	// char *str = "100  ";
	// printf(" value = %d \n", atoi(str));
	struct sta stalist[MAXSTAS];
	struct local_info local = 
	{
		.local_ip = "168.192.1.15",
	};
	// char local_ip[20] = "192.168.1.15";
	// char local_mac[20];
	
	get_stas(stalist, &local.sta_num);
	printf("sta num: %d", local.sta_num);
	// char mac[100];
	// ip_mac(mac, "c4:6e:1f:1e:1e:ea", 0);
	// printf("ip: %s \n", mac);
	
	//get_local_mac(local_mac);
	// printf("locl mac: %s \n", local_mac);
	

	// routing_ctrl ctrl0;
	
	
	
	return 0;
}

int main()
{
	test();
	
	return 0;
}
