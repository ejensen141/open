#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>
#include "read_map.h"
#include <fcntl.h>


void open_process(char * file, char* flags)
{
const char * path;
path = getprogram(file,flags);


pid_t childpid;


        childpid = fork();
        if(childpid == -1)
        {
            perror("Fork Failed");
            
        }

        if(childpid == 0)
	    {
	        signal(SIGHUP,SIG_IGN); // detach from terminal
		fclose(stdout);
		fclose(stderr);          // suppress output to terminal
		    
		execl(path,"",file, NULL);
            //printf("You are in Child: %ld\n", (long)getpid());
        	    
		
	    }
	else
{
	//printf("parent");
  
}






}




