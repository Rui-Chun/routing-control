#include "rc.h"

int main()
{
    cmd("sshpass -p \"raspberry\" scp ctrl.txt pi@192.168.1.15:/home/pi/routing-control/ctrl.txt");
    
    return 0;
}