/*
	generates random password

	takes args: website name, # of characters
	generates password: random chars, length based on arg
	appends temp_backup.txt

	start point of pw
*/
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[])
{
	cout <<"starting random\n";
	ofstream out;
	out.open("temp_backup.txt", std::ios_base::app);
	srand(time(NULL));
	int rand1, digits, counter=0;
	string cast;
	digits=atoi(argv[2]);
	rand1=rand()%1000;
		if (rand1 > 50 && rand1 < 143)
		{
			rand1-=17;
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
	cout <<"The new password for "<<argv[1] <<" is " <<cast <<endl;
	out <<endl <<argv[1] <<endl <<cast;
	

	return 0;
}