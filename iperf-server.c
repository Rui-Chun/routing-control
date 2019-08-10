#include "rc.h"

int main()
{
    cmd("iperf3 -s -D -J -1 -V -p 10240 --logfile ./data/flow0.json");
    cmd("iperf3 -s -D -J -1 -V -p 10241 --logfile ./data/flow1.json");
    cmd("iperf3 -s -D -J -1 -V -p 10242 --logfile ./data/flow2.json");
    cmd("iperf3 -s -D -J -1 -V -p 10243 --logfile ./data/flow3.json");
    cmd("iperf3 -s -D -J -1 -V -p 10244 --logfile ./data/flow4.json");
    cmd("iperf3 -s -D -J -1 -V -p 10245 --logfile ./data/flow5.json");
    cmd("iperf3 -s -D -J -1 -V -p 10246 --logfile ./data/flow6.json");    
    cmd("iperf3 -s -D -J -1 -V -p 10247 --logfile ./data/flow7.json");
    cmd("iperf3 -s -D -J -1 -V -p 10248 --logfile ./data/flow8.json");
    cmd("iperf3 -s -D -J -1 -V -p 10249 --logfile ./data/flow9.json");

    return 0;
}