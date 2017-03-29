#include "site.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>

using namespace std;

site::site(char *file)
{
	string fname=file;
	string temp;
	ifstream in;
	string path="passwords/"+fname;
	in.open(path.c_str());
	getline(in,password);
	getline(in, name);
	getline(in, uname);
	while(in)
	{
		getline(in, temp);
		notes.push_back(temp);
	}
	cout <<"path: "<<path <<" " <<password <<endl;
	in.close();
}

site::site()
{

}

bool exists(string toFind)
{
	char flag;
	auto val=find_if(entry.begin(), entry.end(), [toFind] (site &entry) { return (entry.name.compare(toFind) ==0 ? true : false);});	
	if (val!=entry.end())
	{
		cout <<toFind <<" already has a password to it's name: " <<val->password <<"\nWould you like to replace it instead? (y/N)\n";
		cin >>flag;
		return flag=='y' ? true : false;
	}
	return false;
}

void readIn()
{
	DIR *pdir=NULL;
	struct dirent *pent=NULL;
	pdir=opendir("passwords/");
	if (pdir==NULL)
		cout <<"Error: could not init pdir\n";
	while (pent =readdir(pdir))
	{
		if (pent ==NULL)
		{
			cout <<"couldn't init right\n";
			break;
		}
		if (pent->d_name[0] == '.')
			continue;
		cout <<pent->d_name <<endl;
		site temp(pent->d_name);
		entry.push_back(temp);
	}
	closedir(pdir);
	
}

bool isalphabetical(string a, string b)
{
	int min_length;
	if (a.size() > b.size())
		min_length = b.size();
	else min_length = a.size();
	for (int i = 0; i < min_length; ++i)
	{
		if (a[i] > b[i])
			return false;
		if (a[i] < b[i])
			return true;
	}
	return true;
}
void sort()
{
	int n=entry.size();
	bool swapped=true;
	while (swapped == true)
	{
		swapped=false;
		for (int i = 0; i < entry.size(); ++i)
		{
			if(!isalphabetical(entry[i].name, entry[i+1].name))
			{
				swapped=true;
				swap(entry[i], entry[i+1]);
			}
		}
		
	}
}

void print()
{
	for_each(entry.begin(), entry.end(), [] (site info)
	{
		cout <<info.name;
		if (info.uname.size() != 0)
			cout <<": " <<info.uname;
		cout <<endl <<info.password <<endl <<endl;
	});
}

void overwrite(int pos, string pw)
{
	entry[pos].password==pw;
}