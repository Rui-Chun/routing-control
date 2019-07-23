#include "rc.h"


int main()
{
	// char info[BFSIZE];
	// if(readcmd("iw dev wlan0 station dump",info) == 0)
	// 	printf("%s \n", info);
	// else
	// 	printf("error.\n");
		
	// char *str = "100  ";
	// printf(" value = %d \n", atoi(str));
	struct sta stalist[MAXSTAS];
	char local_ip[20] = "192.168.1.15";
	char local_mac[20];
	
	// get_stas(stalist);
	
	// char mac[100];
	// ip_mac(mac, "c4:6e:1f:1e:1e:ea", 0);
	// printf("ip: %s \n", mac);
	
	get_local_mac(local_mac);
	printf("locl mac: %s \n", local_mac);
	
	return 0;
}
