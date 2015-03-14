#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>
//#include<iostream>
#include "read_map.h"
#include "open.h"

using namespace std;

int main( int argc, char  *argv[])
{

if(argc>1)
{
char *file = new char[argc];
int i =0;

char cwd[1024];
getcwd(cwd,sizeof(cwd));

file = cwd;
strcat(file,"/");

for(i =1; i<argc; i++)
{
strcat(file,argv[1]);
}





open_process(file);



}
else 
{
printf(" Usage:   open <filename>    see manual for more instructions \n");


}




return 0;
}
