#include "site.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
#include <algorithm>

using namespace std;

void longpw(string name, string uname)
{
	srand(time(NULL));
	ifstream in;
	in.open("words.txt");
	int i=0, r=rand()%68571;
	string pw, temp;
	vector<string> list;
	while (in)
	{
		in >>temp;
		list.push_back(temp);
	}
	cout <<"read in " <<i <<" entries\n";
	in.close();
	for (int x=0; x != 3; ++x)
	{
		pw+=list[r];
		if (x <2) pw+="_";
		r=rand()%68571;
	}
	site temp_site;
	temp_site.name=name;
	temp_site.uname=uname;
	temp_site.password=pw;
	entry.push_back(temp_site);
}

string cap(string site) //For the last part of the password: the last 3 letters of the site 
{
	string ending;
	int place=site.size()-3;
	ending=site[place];
	place++;
	ending+=site[place];
	place++;
	ending+=site[place];
	return ending;
}

void shortpw(string name, string uname)
{
	time_t t=time(0);
	struct tm * now = localtime(& t);
	site temp_site;
	string pw;
	pw=to_string(static_cast<int>(name[0]-98));
	pw +=to_string(static_cast<int>(name[1]-98));
	pw+=toupper(name[2]);
	if (now->tm_mon+1 < 10)
	{
		pw+="0";
		pw+=to_string(now->tm_mon+1);
	}
	else pw+=to_string(now->tm_mon+1);
	if (now->tm_mday+1 < 10)
	{
		pw+="0";
		pw+=to_string(now->tm_mday+1);	
	}
	else pw+=to_string(now->tm_mday+1);
	pw+=cap(name);
	cout <<name <<": " <<uname <<endl <<pw <<endl;
	temp_site.name=name;
	temp_site.uname=uname;
	temp_site.password=pw;
	entry.push_back(temp_site);
}

void shortpw(string name)
{
	time_t t=time(0);
	struct tm * now = localtime(& t);
	site temp_site;
	string pw;
	pw=to_string(static_cast<int>(name[0]-98));
	pw +=to_string(static_cast<int>(name[1]-98));
	pw+=toupper(name[2]);
	if (now->tm_mon+1 < 10)
	{
		pw+="0";
		pw+=to_string(now->tm_mon+1);
	}
	else pw+=to_string(now->tm_mon+1);
	if (now->tm_mday+1 < 10)
	{
		pw+="0";
		pw+=to_string(now->tm_mday+1);	
	}
	else pw+=to_string(now->tm_mday+1);
	pw+=cap(name);
	cout <<name <<endl <<pw <<endl;
	temp_site.name=name;
	temp_site.uname="";
	temp_site.password=pw;
	entry.push_back(temp_site);
}

void randpw(string name, string uname, string illegal, int num)
{
	//valid between 50 143
	string pw;
	srand(time(NULL));
	int r=rand()%143;
	int i=0;
	while (i <num)
	{
		r=rand()%200;
		if (r < 143 && r > 50)
			r-=17;
		else continue;
		if (illegal.size() > 0)
		{
			if (any_of(illegal.begin(), illegal.end(), [&r] (char illegal) {return static_cast<char>(r)==illegal;}))
				{
					cout <<"found " <<static_cast<char>(r) <<endl;
					continue;}
		}
		pw+=static_cast<char>(r);
		++i;
		
	}
	cout <<pw <<endl;
}
