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

enum selector:int{Short=0, Long=1, Rand=2, F=3};
void create_password(site, selector);
bool process(int argc, char * argv[]);

int main(int argc, char * argv[])
{
	systemLog.open("/var/log/pw-gen.log", std::ofstream::app);
	cout	<<"Reading in settings\n";
	readIn();
	if (!systemLog)
	{
		cout <<"error: could not initialize log file\n";
		logMessages(-1);
		return returnCode;
	}
	if (process(argc, argv))
		write();
	systemLog.close();
	return returnCode;
}

bool process(int argc, char * argv[])
{
	site temp;
	int option;
	selector s;
	bool generate=false, enough_data=false;
	while ((option=getopt(argc, argv, "L:S:R:f:i:e:l:u:")) !=-1)
	{
		cout <<"option is " <<(char)option <<'\n';
		if (option == '?')
		{
			cout <<"option " <<(char)optopt <<" requires an argument\n";
			break;
		}
		switch (option)
		{
			case 'L': {
					s=Long;
					temp.website=optarg;
					generate=true;
				}
				break;
			case 'S': {
					s=Short;
					temp.website=optarg;
					generate=true;
				}
				break;
			case 'R': {
					s=Rand;
					temp.website=optarg;
					generate=true;
				}
				break;
			case 'f': {
					s=F;
					temp.website=optarg;
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
	if (!enough_data)
	{
		cout <<"Not enough data! I need a username or email adress associated with that as well\n";
		return false;
	}
	if (s==F) findAndPrint(temp);
	else if (generate)
 	{
	 	if (temp.website.find(".")!=std::string::npos)
		{
			temp.website=temp.website.substr(0,temp.website.find(".")-1);
		}
		create_password(temp, s);	
	} 
	return true;
}
void create_password(site temp, selector flag)
{
	if (temp.uname=="" && temp.email!="") temp.uname=temp.email.substr(0,temp.email.find("@"));
	cout <<"no username given, taking " <<temp.uname <<" from email\n";
	if (!record[temp.website][temp.uname].is_null())
	{
		char sel;
		cout <<"A record for that username/site combination already exists\n"
			  <<"would you like to overwrite?(y/n)";
		cin >>sel;
		cout <<sel <<'\n';
		switch(sel)
		{
			case 'y':
			case 'Y': copyToSite(&temp);
				break;
			case 'n':
			case 'N':
				cout <<"Understood. Goodbye\n";
				return;
			default: cout <<"Not a valid option. Goodbye\n";
				return;
		}
	}
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
