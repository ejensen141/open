#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>
#include "read_map.h"
#include "sopen.h"



int main( int argc, char  *argv[])
{

int start =1;
if(argc>1)
{
char *file = new char[argc];
char *flag;
int i =0;

if(strcmp(argv[1],"-f") == 0)
{
start =2; // folder
flag = argv[1];
}

char cwd[1024];
getcwd(cwd,sizeof(cwd));

file = cwd;
strcat(file,"/");


for(i=start; i<argc; i++)
{
strcat(file,argv[start]);
}
//printf("%s",file);

open_process_s(file,flag);

}
else 
{
printf(" Usage:   open <filename>    see manual for more instructions \n");
printf(" -f to open a folder");

}

return 0;
}
