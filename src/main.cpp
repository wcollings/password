//copyright 2018 William Collings
//MAIN
//has the main function, and that's it

#include <string>
#include "include/site.hpp"
#include "algorithms.cpp"
using namespace std;

enum selector:int{Short=0, Long=1, Rand=2};
void create_password(site, selector);

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
}

void create_password(site temp, selector flag)
{
	if (!exists(temp.website))
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