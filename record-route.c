#include<time.h>
#include<stdio.h>
#include<unistd.h>

#include "rc.h"



int main()
{
	time_t time_now;
	struct tm *time_ptr = NULL;
	char buffer[256];
	
	while(1)
	{
		time(&time_now);
		//printf("time_now : %d \n", time_now);
		
		time_ptr = localtime(&time_now);
		//printf("local time : %d-%d-%d %d:%d:%d \n", (1900+time_ptr->tm_year), (1+time_ptr->tm_mon), (time_ptr->tm_mday), time_ptr->tm_hour, time_ptr->tm_min, time_ptr->tm_sec);
		
		sprintf(buffer, "sudo route -n > /home/pi/routing-control/route-record/routing-%d-%d-%d--%d-%d-%d.txt",\
		(1900+time_ptr->tm_year), (1+time_ptr->tm_mon), (time_ptr->tm_mday), time_ptr->tm_hour, time_ptr->tm_min, time_ptr->tm_sec);
		
		if(time_ptr->tm_min % 3 == 0)
		{
			cmd(buffer);
			sleep(50);
		}
		sleep(50);
	}

	return 0;
}
