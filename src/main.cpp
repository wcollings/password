//copyright 2018 William Collings
//MAIN
//has the main function, and that's it
<<<<<<< HEAD

#include <string>
#include "include/site.hpp"
#include "algorithms.cpp"
=======
#include <iostream>
#include <string>
#include "include/site.hpp"
#include "algorithms.cpp"
#include <getopt.h>
#include <unistd.h>
#include <optional>
>>>>>>> 5fc3506071b23b41be99fe74f179c5caeb3a9ce2
using namespace std;

enum selector:int{Short=0, Long=1, Rand=2};
void create_password(site, selector);

<<<<<<< HEAD
int main(int argc, char * argv[])
{
	systemLog.open("/var/log/pw-gen.log", std::ofstream::app);
	logMessages(0);
	site temp;
	if (!readIn()) return -1;
	temp.illegal=settings.at("illegal").get<std::string>();
	temp.length=settings.at("default_length").get<int>();
	bool generate=false;
	selector flag;
	if (argc < 2)
	{
		help();
		return 0;
	}
	for (int i=1; i < argc; ++i)
	{
	 	if (argv[i][0]=='-')
			switch(argv[i][1])
			{
				case 'L':
				{
					flag=Long;
					generate=true;
				}
					break;
				case 'S':
				{
					flag=Short;
					generate=true;
				}
					break;
				case 'R':
				{
						flag=Rand;
						generate=true;
				}
					break;
				case 'i':
				{
					temp.illegal=argv[++i];
				}
					break;
				case 'n':
				{
					//read in notes. will have to be a prompt
				}
					break;
				case 'f':
				{
					exists(argv[++i]);
				}
					break;
				case 'u':
				{
					temp.uname=argv[++i];
				}
					break;
				case 'l':
				{
					temp.length=atoi(argv[++i]);
				}
					break;
				case 'e':
					temp.email=argv[++i];
			}
		else temp.website=argv[i];
		//cout <<i <<'=' <<argv[i] <<'\n';
	}
	//cout <<temp.website <<'\n';
	if (generate)
		create_password(temp, flag);
	write();
	systemLog.close();
=======
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
		return returnCode;
	}
	if (process(argc, argv))
		write();
	systemLog.close();
	return returnCode;
>>>>>>> 5fc3506071b23b41be99fe74f179c5caeb3a9ce2
}

void create_password(site temp, selector flag)
{
<<<<<<< HEAD
	if (!exists(temp.website))
=======
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
>>>>>>> 5fc3506071b23b41be99fe74f179c5caeb3a9ce2
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
<<<<<<< HEAD

}
=======
}
>>>>>>> 5fc3506071b23b41be99fe74f179c5caeb3a9ce2
