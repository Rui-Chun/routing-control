#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BFSIZE 1024
#define MACLEN 6
#define MAXSTAS 20
#define INFONUM 10

#define DEBUG 1 


struct sta
{
	int mac_addr[MACLEN];
	char mac_addr_str[MACLEN*3];
	
	int rxbytes;
	int rxpackets;
	
	int txbytes;
	int txpackets;
	int txfailed;
	int txretries;
	
	int signal; // dbm
	
	float txbitrate; //Mbps
	float rxbitrate;
	

};


int readcmd(char* cmd, char* output);
int cmd(char* cmd);
int get_stas(struct sta* stalist);
int ip_mac(char* ip, char* mac, int ip_to_mac);
int get_local_mac(char* local_mac);
