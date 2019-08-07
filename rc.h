#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BFSIZE 1024
#define IPLEN 20
#define IPNUM 4
#define MACLEN 20
#define MACNUM 6
#define MAXSTAS 10
#define MAXNODES 20
#define INFONUM 10
#define LOCALIP "192.168.1.x"
#define ETH0IP "192.168.2.x"

#define DEBUG 1 

struct ip_addr
{
	char str_v[IPLEN]; //string version
	char int_v[IPNUM]; // int version
};

struct mac_addr
{
	char str_v[MACLEN]; //string version
	char int_v[MACNUM];
};

struct routing_ctrl
{
	struct ip_addr dst_ip;
	struct ip_addr nexthop_ip;
};

struct rate_ctrl
{
	int rate_idx[4]; // see ar5461Phy.c for rate 
	int tries[4];    // num of retires
};

struct node
{
	struct ip_addr ip;
	
	int is_sta; // whether is a sta
	
	struct ip_addr nexthop_ip;

	// TODO: info get form this node
};

struct sta
{
	struct mac_addr mac;
	
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

	struct rate_ctrl rete_series;
};

struct local_info
{
	struct ip_addr ip;
	struct mac_addr mac;

	int sta_num; // num of sta connected with local, nodes that in range of communication
	struct sta stalist[MAXSTAS];

	int node_num; // num of all the node in the netork
	struct node nodelist;

	int tx_power; // dbm
};

int readcmd(char* cmd, char* output);
int cmd(char* cmd);
int str2num(char *str, int* num, int base, int len);
int get_stas(struct sta* stalist, int* num);
int ip_mac(char* ip, char* mac, int ip_to_mac);
int get_local_mac(char* local_mac);
