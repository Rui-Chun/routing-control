#include "rc.h"

int main()
{
    cmd("iperf3 -s -D -J -1 -V -p 10240 --logfile ./data/flow0");
    cmd("iperf3 -s -D -J -1 -V -p 10241 --logfile ./data/flow1");
    cmd("iperf3 -s -D -J -1 -V -p 10242 --logfile ./data/flow2");
    cmd("iperf3 -s -D -J -1 -V -p 10243 --logfile ./data/flow3");
    cmd("iperf3 -s -D -J -1 -V -p 10244 --logfile ./data/flow4");
    cmd("iperf3 -s -D -J -1 -V -p 10245 --logfile ./data/flow5");
    cmd("iperf3 -s -D -J -1 -V -p 10246 --logfile ./data/flow6");    
    cmd("iperf3 -s -D -J -1 -V -p 10247 --logfile ./data/flow7");
    cmd("iperf3 -s -D -J -1 -V -p 10248 --logfile ./data/flow8");
    cmd("iperf3 -s -D -J -1 -V -p 10249 --logfile ./data/flow9");

    return 0;
}