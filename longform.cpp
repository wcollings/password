/*
	generates silly password
	takes args: website name
	reads in file words.txt
	generates new password, 3 words strung together
	appends temp_backup

	start point of pw
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[])
{
	ofstream out;
	out.open("temp_backup.txt", ios::app);
	ifstream in;
	string password;
	string service;
	int i=0;
	while (argv[1][i] != '\0')
	{
		service += argv[1][i];
		i++;
	}
	in.open("words.txt");
	std::vector<string> list;
	string temp;
	while (in)
	{
		in >>temp;
		list.push_back(temp);
	}
	cout <<service <<endl;
	srand(time(NULL));
	int randomizer=rand()%68571;
		password+='-';
		password=list[randomizer];
	cout <<list[randomizer] <<"-";
	randomizer=rand()%68571;
	cout <<list[randomizer] <<"-";
		password+='-';
		password+=list[randomizer];
	randomizer=rand()%68571;
		password+='-';
		password+=list[randomizer];
	cout <<list[randomizer] <<endl;
	out <<service <<endl <<password <<endl;
	out.close();
	return 0;
}
