#include "site.h"
#include "utilities.cpp"
#include "algorithms.cpp"


using namespace std;

enum selector:int{Short=0, Long=1, Rand=2};

int main(int argc, char *argv[])
{

	readIn();
	site temp;
	selector flag;
	temp.name=argv[2];
	cout <<"new password for " <<argv[2] <<endl;
	if (argc > 3)
	{
		temp.uname=argv[3];
	}
	switch(argv[1][1])
	{
		case 'L':
		case 'l':flag=Long;
			break;
		case 'S':
		case 's': flag=Short;
			break;
		case 'R':
		case 'r': flag=Rand;
			break;

	}
	cout <<"does " <<temp.name <<" already exist?\n";
	cout <<(exists(temp.name) ? "yes" : "no") <<endl;
	for (int i=0; i < entry.size(); ++i)
	{
		cout <<entry[i].name <<endl;
	}

	
}