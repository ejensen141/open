#include "read_map.h"
#include<stdio.h>
#include<string>
#include<string.h>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

const char* getprogram(char *file, char *flag){
int N = 1000; // number of extensions allowed to search for
const char* program = "program"; 
char *extension; // the file extension
int index = -1;


	struct type types[N];
	int end =0;
	int num =0;
	
	std::string prog; // program to run
	std::string ext;  //  extension for that program
	std::string line; // input line from settings file
	std::string def;  // set default program 
	
	std::size_t pos =1;
	std::size_t last = 0;
	std::string homedir = getenv("HOME"); 
	std::string settingsFile = homedir;
	
	
	settingsFile.append("/.extension_map.setting");

	
	std::ifstream fp (settingsFile.c_str());
	
	while(getline (fp,line) )
	{	
		
	pos = line.find("\"");
	last =line.find_last_of("\"");
	if(pos > sizeof(line))
	{	break;}
	ext = line.substr(0,pos-1);
	prog = line.substr(pos+1,last-pos-1);
	
		if(ext == "default")
		{
			def = prog;
		}
		
		
		
		types[num].ext = ext;
		types[num].prog = prog;

		num++;
	}

	end = num;

	// debug purposes 
	/*for(int jj =0; jj<end; jj++)
	{
		std::cout<<types[jj].ext<<"	"<<types[jj].prog<<std::endl;
	}
	*/
	
	index = (int)(strchr(file,'.')-file);
	
		if(strcmp(flag,"") != 0)
		{
		for(int j =0; j<end; j++)
		{

		
		
		if(strcmp(flag,types[j].ext.c_str())==0)
		{
		return types[j].prog.c_str();
		}

		
	
		}

		}

	
	if(index>0 && index <1000)
	{
		extension = strrchr(file,'.');
		
		
		for(int j =0; j<end; j++)
		{

		
		
		if(strcmp(extension,types[j].ext.c_str())==0)
		{
		return types[j].prog.c_str();
		}

		
	
		}

	
	return def.c_str();


	}
	else
	{
	
	
	 return def.c_str();
	}


return program;
}


