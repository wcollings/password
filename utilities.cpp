//UTILITIES
//
//has all the misc. functions.
//exists, readIn

#include "include/site.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using json= nlohmann::json;

bool exists(string toFind);
void readIn();
char convertToNumber(char c);

bool exists(string toFind)
{
	if (record[toFind].is_object() )
	{
		cout <<"yes\n";
		return true;
	}
	cout <<"no\n";
	return false;
}

void readIn()
{
	ifstream in;
	in.open("settings.json");
	if (in) cout <<"I opened settings\n";
	in >>settings;
	in.close();
	in.open(settings["save_file"]);
	if (in) cout <<"I opened the file!\n";
	in >>record;
}

char convertToNumber(char c)
{
	char temp=toupper(c);
	int num=static_cast<int>(temp)-64;
	cout <<num <<endl;
       return num;	
}

void find(string a)
{
	//This only prints a boolean. print the information about it instead
	cout <<record[a].is_object() <<'\n';
}


void help()
{
	cout <<"summary of arguments:\n"
		  <<"\t-p: print all entries\n"
		  <<"\t-l: generate a long password\n"
		  <<"\t-s: generate a shorter (8 or 9 char) password\n"
		  <<"\t-r: generate a random series of characters. must specify a length as well\n";
}
