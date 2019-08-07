#include "rc.h"

int main()
{
    char cmdBuff[BUFSIZ];

    // set type as mesh
    cmd("sudo ifconfig wlan0 down");
    cmd("sudo iw wlan0 set type mesh");
    cmd("sudo ifconfig wlan0 up");

    //set mesh ip addr
    memset(cmdBuff,0,sizeof(char)*BFSIZE);
    strcat(cmdBuff,"sudo ifconfig wlan0 ");
    strcat(cmdBuff,LOCALIP);
    cmd(cmdBuff);

    // set tx power
    cmd("sudo iw wlan0 set txpower fixed 0");

    // join or create a mesh net
    cmd("sudo iw wlan0 mesh join RaspMesh freq 2442");

    // set eth0 ip for ssh
    memset(cmdBuff,0,sizeof(char)*BFSIZE);
    strcat(cmdBuff,"sudo ifconfig eth0 ");
    strcat(cmdBuff,ETH0IP);
    cmd(cmdBuff);

    return 0;
}