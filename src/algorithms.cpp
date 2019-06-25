//Copyright 2018 William Collings
//ALGORITHMS
//has the algorithms for actually making the passwords

#include "include/site.hpp"
#include "utilities.cpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
#include <algorithm>

using namespace std;
using json= nlohmann::json;

//generate a long password: 3 words strung together
void longpw(site info)
{
	srand(time(NULL));
	ifstream in;
	in.open(settings.at("words_file").get<std::string>());
	int i=0;
	string pw, temp;
	vector<string> list;
	while (in)
	{
		in >>temp;
		list.push_back(temp);
	}
	if (settings.at("verbose").get<bool>())
		cout <<"read in " <<i <<" entries\n";
	in.close();
	int r=rand()%list.size();
	for (int x=0; x <3; ++x)
	{
		pw+=list[r];
		if (x <2) pw+="_";
		r=rand()%list.size();
	}
	info.password=pw;
	cout <<info.website <<": " <<info.uname <<'\n' <<pw <<'\n';
	logNewEntry(info);
}

//generate a normal password
void shortpw(site info)
{
	time_t t=time(0);
	struct tm * now = localtime(& t);
	string pw="";
		
	pw+=to_string(convertToNumber(info.website[0]));
	pw+=to_string(convertToNumber(info.website[1]));
	pw+=toupper(info.website[2]);
	if (now->tm_mon+1 < 10)
	{
		pw+="0";
		pw+=to_string(now->tm_mon+1);
	}
	else pw+=to_string(now->tm_mon+1);
	if (now->tm_mday+1 < 10)
	{
		pw+="0";
		pw+=to_string(now->tm_mday);	
	}
	else pw+=to_string(now->tm_mday);
	try
	{
		if (info.website.size() < 3)
			throw -1;
		pw+=info.website.substr(info.website.size()-3,3);
	}
	catch (int e)
	{
		switch (e)
		{
			case -1:pw+="com";
		
		}
	}
	cout <<info.website <<": " <<info.uname <<'\n' <<pw <<'\n';
	info.password=pw;
	logNewEntry(info);
}

//x number of random digits 
void randpw(site info)
{
	//valid between 50 143
	string pw;
	srand(time(NULL));
	int r=rand()%143;
	int i=0;
	while (i <info.length)
	{
		r=rand()%143;
		if (r > 50)
			r-=17;
		else continue;
		if (info.illegal.size() > 0)
		{
			if (any_of(info.illegal.begin(), info.illegal.end(), [&r] (char illegal) {return static_cast<char>(r)==illegal;}))
			{
				cout <<"found " <<static_cast<char>(r) <<endl;
				continue;
			}
		}
		pw+=static_cast<char>(r);
		++i;
		
	}
	info.password=pw;
	cout <<info.website <<": " <<info.uname <<'\n' <<pw <<'\n';
	logNewEntry(info);
}
