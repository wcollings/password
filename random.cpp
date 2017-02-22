/*
	generates random password

	takes args: website name, # of characters, illegal character (optional)
	generates password: random chars, length based on arg
	appends temp_backup.txt

	start point of pw
*/
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	ofstream out;
	out.open("temp_backup.txt", std::ios_base::app);
	srand(time(NULL));
	int rand1, digits, counter=0;
	string cast, illegal;
	int i=0;
	if (argc > 3)
	{
		while (++i < strlen(argv[3])-1)
		{
			illegal+=argv[3][i];
		}
	}
	digits=atoi(argv[2]);
	rand1=rand()%1000;
		if (rand1 > 50 && rand1 < 143)
		{
			rand1-=17;
			if (argc >= 3)
			{
				int i=0;
				while (i++ < strlen(argv[3]))
				{
					if (rand1 == argv[3][i])
					continue;
				}
			}
			cast=static_cast<char>(rand1);
		}
	while(counter < digits)
	{
		rand1=rand()%1000;
		if (rand1 > 50 && rand1 < 143)
		{
			rand1-=17;
			cast+=static_cast<char>(rand1);
			counter++;
		}
	}
	<<"The new password for "<<argv[1] <<" is " <<cast <<endl;
	out <<endl <<argv[1] <<endl <<cast;
	

	return 0;
}
