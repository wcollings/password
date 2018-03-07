//ALGORITHMS
//has the algorithms for actually making the passwords

#include "include/site.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
#include <algorithm>

using namespace std;
using json= nlohmann::json;

//generate a long password: 3 words strung together
void longpw(string name, string uname)
{
	srand(time(NULL));
	ifstream in;
	in.open(settings["words_file"]);
	int i=0, r=rand()%68571;
	string pw, temp;
	vector<string> list;
	while (in)
	{
		in >>temp;
		list.push_back(temp);
	}
	if (settings["verbose"])
		cout <<"read in " <<i <<" entries\n";
	in.close();
	for (int x=0; x != 3; ++x)
	{
		pw+=list[r];
		if (x <2) pw+="_";
		r=rand()%68571;
	}
	record.insert(record.end(), {name, { "password", pw}});

}

//generate a normal password
void shortpw(string name, string uname)
{
	time_t t=time(0);
	struct tm * now = localtime(& t);
	string pw;
		
	pw=to_string(static_cast<int>(name[0])-98);
	pw +=to_string(static_cast<int>(name[1])-98);
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
	try
	{
		if (name.size() < 3)
			throw -1;
		pw+=name.substr(name.size()-4,3);
	}
	catch (int e)
	{
		switch (e)
		{
			case -1:pw+="com";
		
		}
	}
	cout <<name <<": " <<uname <<endl <<pw <<endl;
}

//x number of random digits 
void randpw(string name, string uname, string illegal, int num)
{
	//valid between 50 143
	string pw;
	srand(time(NULL));
	int r=rand()%143;
	int i=0;
	while (i <num)
	{
		r=rand()%143;
		if (r > 50)
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
	json o= {
		{"site", name},
		{"username", temp.uname},
		{"password", pw}
	};
	cout <<pw <<endl;
}
