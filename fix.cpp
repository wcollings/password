/*
	fixes discrepencies between files

	reads in passwords.txt
	reads in ~/Dropbox/passwords.txt, saves entries not logged initially
	writes over passwords.txt
	optional step in pw
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct site
{
	string name;
	string password;
};
vector<site> info;

void read_in(string file1); //reads in the first password file
void checker(string file); //reads in second password file to compare against
bool already_exists(site& to_check); //checks if the current uname/password was already in the other file
void print();

int main()
{
	string file1, file2;
	ifstream in;
	in.open("settings.txt");
	in >>file1 >>file2;
	in.close();
	read_in(file1);
	checker(file2);
	print();

}

void read_in(string file1)
{
	ifstream in;
	string file1,file2;
	in.open(file1.c_str());
	site temp;
	while (in)
	{
		getline(in, temp.name);
		getline(in, temp.password);
		in.ignore(100, '\n');
		info.push_back(temp);
	}
	in.close();
}

void checker(string file2)
{
	ifstream in;
	in.open(file2.c_str());
	site temp;
	int counter;
	while (in)
	{
		getline(in, temp.name);
		getline(in, temp.password);
		in.ignore(100, '\n');
		if (!already_exists(temp))
		{
			info.push_back(temp);
		}
		else counter++;
	}
	cout <<"There are a total of " <<info.size() <<" passwords stored\n";
	cout <<counter <<" passwords were the same\n";
	in.close();
}

bool already_exists(site& to_check)
{
	for (int i=0; i < info.size(); i++)
	{
		if (to_check.name.compare(info[i].name) == 0)
			if (to_check.password.compare(info[i].password) == 0)
				return true;
	}
	return false;
}

void print()
{
	ofstream out;
	out.open("passwords.txt");
	for_each(info.begin(), info.end(), [site printer] {
		cout <<printer.name <<endl <<printer.password <<endl <<endl;
	});
}