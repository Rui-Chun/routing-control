#include "rc.h"

int main()
{
    cmd("iperf3 -s -D -J -1 -V -p 10240 --logfile flow0");
    cmd("iperf3 -s -D -J -1 -V -p 10241 --logfile flow1");
    cmd("iperf3 -s -D -J -1 -V -p 10242 --logfile flow2");
    cmd("iperf3 -s -D -J -1 -V -p 10243 --logfile flow3");
    cmd("iperf3 -s -D -J -1 -V -p 10244 --logfile flow4");
    cmd("iperf3 -s -D -J -1 -V -p 10245 --logfile flow5");
    cmd("iperf3 -s -D -J -1 -V -p 10246 --logfile flow6");    
    cmd("iperf3 -s -D -J -1 -V -p 10247 --logfile flow7");
    cmd("iperf3 -s -D -J -1 -V -p 10248 --logfile flow8");
    cmd("iperf3 -s -D -J -1 -V -p 10249 --logfile flow9");
    
    return 0;
}