#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BFSIZE 1024
#define IPLEN 20
#define MACLEN 20
#define MAXSTAS 20
#define INFONUM 10

#define DEBUG 1 


struct sta
{
	int mac_addr_int[MACLEN];
	char mac_addr_str[MACLEN];
	
	int rxbytes;
	int rxpackets;
	
	int txbytes;
	int txpackets;
	int txfailed;
	int txretries;
	
	int signal; // dbm
	
	float txbitrate; //Mbps 
	float rxbitrate;
	// note that info got from 'station dump' has delay 
	

};

struct local_info
{
	char local_ip[IPLEN];
	char local_mac[MACLEN];
	int sta_num; // num of sta connected with local
};

struct routing_ctrl
{
	char dst_ip[IPLEN];
	char dst_mac[MACLEN];
	
	char nexthop_ip[IPLEN];
	char nexthop_mac[MACLEN];
	
	int power;// dbm
	int rate_idx; //see ar5416Phy.c in open-firmwre for reference
};


int readcmd(char* cmd, char* output);
int cmd(char* cmd);
int get_stas(struct sta* stalist, int* num);
int ip_mac(char* ip, char* mac, int ip_to_mac);
int get_local_mac(char* local_mac);
