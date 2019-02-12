//copyright 2018 William Collings
//MAIN
//has the main function, and that's it
#include <iostream>
#include <string>
#include "include/site.hpp"
#include "algorithms.cpp"
#include <getopt.h>
#include <unistd.h>
#include <optional>
using namespace std;

enum selector:int{Short=0, Long=1, Rand=2};
void create_password(site, selector);

bool process(int argc, char * argv[])
{
	site temp;
	int option;
	selector s;
	bool generate=false, enough_data=false;
	while ((option=getopt(argc, argv, "LSRf:i:e:l:u:")) !=-1)
	{
		cout <<"option is " <<(char)option;
		if (option == '?')
		{
			cout <<"option " <<(char)optopt <<" requires an argument\n";
			break;
		}
		switch (option)
		{
			case 'L': {
					s=Long;
					generate=true;
				}
				break;
			case 'S': {
					s=Short;
					generate=true;
				}
				break;
			case 'R': {
					s=Rand;
					generate=true;
				}
				break;
			case 'f': {
					exists(optarg);
					enough_data=true;
				}
				break;
			case 'i': temp.illegal=optarg;
				break;
			case 'e': {
					temp.email=optarg;
					enough_data=true;
				}
				break;
			case 'l': temp.length=atoi(optarg);
				break;
			case 'u': {
					temp.uname=optarg; 
					enough_data=true;
				}
		}
	}
	if (optind <argc)
		temp.website=argv[optind];
	if (!enough_data)
	{
		cout <<"Not enough data! I need a username or email adress associated with that as well\n";
		return false;
	}
	else if (generate)
 	{
		create_password(temp, s);	
	} 
	return true;
}

int main(int argc, char * argv[])
{
	systemLog.open("/var/log/pw-gen.log", std::ofstream::app);
	readIn();
	if (!systemLog)
	{
		cout <<"error: could not initialize log file\n";
		logMessages(-1);
		return -1;
	}
	if (process(argc, argv))
		write();
	systemLog.close();
	return 0;
}

void create_password(site temp, selector flag)
{
	if (exists(temp.website))
	{
		int sel;
		cout <<"A record for that site already exists. please select:\n"
			  <<"\t1: update the information for that site\n"
			  <<"\t2: create a new entry for this website\n"
			  <<"\t3: to quit\n";
		cin >>sel;
		if (sel == 1)
		{
					
		}
		else
		{
			return;		
		}
	}
	else
	{
		logMessages(1);
		switch (flag)
		{
			case Short: shortpw(temp);
				break;
			case Long: longpw(temp);
				break;
			case Rand: randpw(temp); 
		}
	}
}
