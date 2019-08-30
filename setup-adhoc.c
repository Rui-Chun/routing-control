#include "rc.h"
#include <unistd.h>


int main()
{
    char cmdBuff[BUFSIZ];

    // set type as ibss
    //cmd("sudo ifconfig wlan0 down");
    //usleep(500000);
    //cmd("sudo iw wlan0 set type ibss");
    //usleep(500000);
    //cmd("sudo ifconfig wlan0 up");
    //usleep(500000);

    //set ip addr
    //memset(cmdBuff,0,sizeof(char)*BFSIZE);
    //strcat(cmdBuff,"sudo ifconfig wlan0 ");
    //strcat(cmdBuff,LOCALIP);
    //cmd(cmdBuff);
    //usleep(500000);

    // set tx power
    cmd("sudo iw wlan0 set txpower fixed 0");
    usleep(500000);

    // join or create a ad-hoc net
    //cmd("sudo iw wlan0 ibss join RaspAdhoc 2442");
    //usleep(500000);

    // set eth0 ip for ssh
    //memset(cmdBuff,0,sizeof(char)*BFSIZE);
    //strcat(cmdBuff,"sudo ifconfig eth0 ");
    //strcat(cmdBuff,ETH0IP);
    //cmd(cmdBuff);
    //usleep(500000);

    cmd("sudo nohup /home/pi/OONF/build/olsrd2_static wlan0 &");
    usleep(500000);
    cmd("iperf3 -s -D -J -V --logfile /home/pi/routing-control/iperf-s.json");
    usleep(500000);
    cmd("nohup /home/pi/routing-control/record-route &");
    usleep(500000);

    return 0;
}
