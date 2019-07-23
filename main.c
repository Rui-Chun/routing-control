#include "rc.h"


int main()
{
	// char info[BFSIZE];
	// if(readcmd("iw dev wlan0 station dump",info) == 0)
	// 	printf("%s \n", info);
	// else
	// 	printf("error.\n");
		
	// char *str = "100  ";
	// printf(" value = %d \n", atoi(str));
	struct sta stalist[MAXSTAS];
	
	get_stas(stalist);
	
	
	
	return 0;
}
