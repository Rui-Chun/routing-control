#include "rc.h"

int main()
{
    FILE *fp;
    char buffer[BFSIZE];
    char tempNum[20];
    int ctrl[50];

    while(1)
    {
        fp = fopen("ctrl.txt","r");
        if(!fp) {sleep(3); continue;};

        memset(buffer,0,sizeof(char)*BFSIZE);
        fgets(buffer, BFSIZE, fp);
        if(buffer[0] == '0')
        {
            sleep(3); continue;
        }

        // dst ip(4) port(1) time(1) datarate(1)
        str2num(buffer,ctrl,10,7);
        
        memset(buffer,0,sizeof(char)*BFSIZE);
        sprintf(buffer, "iperf3 -c %d.%d.%d.%d -p %d -t %d -b %dM -J -V --logfile ./data/cl-flow.json", ctrl[0], ctrl[1], ctrl[2], ctrl[3], ctrl[4], ctrl[5], ctrl[6]);

        cmd(buffer);
        fclose(fp);

        fp = fopen("ctrl.txt","w");
        if(!fp) {sleep(3); continue;};
        fprintf(fp,"0");
        fclose(fp);

    }

    return 0;
}