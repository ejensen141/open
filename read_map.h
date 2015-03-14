#ifndef _read_map_h
#define _read_map_h


#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>

struct type{

	 std::string ext;
	 std::string prog;
	 



};


const char* getprogram(char *file);


int read_config_file(struct type *types[]); 


#endif
