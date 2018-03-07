//MAIN
//has the main function, and that's it

#include <string>
#include "include/site.h"
#include "utilities.cpp"
#include "algorithms.cpp"
using namespace std;

enum selector:int{Short=0, Long=1, Rand=2};

int main(int argc, char * argv[])
{
	string illegal=settings["illegal"];
	int length=settings["default_length"];
	readIn();
	string uname, name;	
	selector flag;
	if (argc < 2)
	{
		help();
		return 0;
	}
	for (int i=1; i < argc-1; ++i)
	{
	 	if (argv[i][0]=='-')
			switch(argv[i][1])
			{
				case 'l':flag=Long;
					break;
				case 's': flag=Short;
					break;
				case 'r':
				{
						flag=Rand;
						length=atoi(argv[++i]);
				}
					break;
				case 'i':
				{
					illegal=argv[++i];
				}
					break;
				case 'n':
				{
					name=argv[++i];
				}
					break;
				case 'p':
				{
					//print the database. make this function in utilities later
				}
					break;
				case 'f':
				{
					find(argv[++i]);
				}
					break;
			}
		else uname=argv[i];
	}
	cout <<"does " <<uname <<" already exist?\n";
	if (!exists(uname))
	{
		switch (flag)
		{
			case Short: shortpw(temp.name, temp.uname);
				break;
			case Long: longpw(name, uname);
				break;
			case Rand: randpw(temp.name, temp.uname, settings["illegal"], length); 
		}
	}
}
