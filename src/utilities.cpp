//Copyright 2018 William Collings
//UTILITIES
//
//has all the misc. functions

#include "include/site.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sysexits.h>

using namespace std;
using json= nlohmann::json;
int returnCode=0;
bool exists(std::string);
bool readIn();
int convertToNumber(char);
void Find(std::string);
void help();
void write();
void logNewEntry(site);
void print(json::iterator);
void print(site);
void logMessages(int);
void printsettings();
site copyToSite(std::string);

ofstream systemLog;
bool exists(string toFind)
{
	auto find=record.find(toFind);
	if (find!= record.end())
	{
		cout <<"from database:\n";
		Find(toFind);
		return true;
	}
	return false;
}

bool readIn()
{
	ifstream in;
	in.open("../settings.json");
	if (in)
	{
		in >>settings;
		in.close();
		in.open(settings.at("save_file").get<std::string>());
		if (in)
		{
			in >>record;
		}
		else logMessages(-2);
		return true;
	}
	else logMessages(-1);
	return false;
}

int convertToNumber(char c)
{
	char temp=toupper(c);
	int num=(static_cast<int>(temp))-64;
   return num;	
}

void Find(string a)
{
	auto find=record.find(a);
	if (find != record.end())
	{
		print(find);
	}
}

void print(json::iterator a)
{
	cout <<"data for site \"" <<a.key() <<"\":\n";
	json j=a.value();
	for (auto i=j.begin(); i != j.end(); ++i)
		cout <<'\t' <<i.key() <<':' <<i.value().dump(3) <<'\n';
}

void print(site s)
{
	cout <<"data for site \"" <<s.website <<"\":\n";
	if (s.email != "") cout <<'\t' <<"email: " <<s.email <<'\n';
	cout <<'\t' <<"password: " <<s.password <<'\n';
	if (s.uname != "") cout <<'\t' <<"username:" <<s.uname <<'\n';
}


void help()
{
	cout <<"summary of arguments:\n"
		  <<"\t-p: print all entries\n"
		  <<"\t-l: generate a long password\n"
		  <<"\t-s: generate a shorter (8 or 9 char) password\n"
		  <<"\t-r: generate a random series of characters. must specify a length as well\n";
}

void write()
{
	ofstream out;
	out.open(settings.at("save_file").get<std::string>());
	out <<record.dump(3);
	logMessages(2);
	out.close();
}

void logNewEntry(site s)
{
	json j;
	j["password"]=s.password;
	if (s.uname != "")
		j["username"]=s.uname;
	if (s.email != "")
		j["email"]=s.email;
	if (s.notes != "")
		j+=json::parse(s.notes);
	record[s.website]=j;
}

void logMessages(int code)
{
	time_t t=time(0);
	struct tm * now = localtime(&t);
	std::string time_str=asctime(now);
	systemLog <<'[' <<time_str.substr(0, time_str.size()-1) <<"] ";
	switch (code)
	{
		case -1:
		{
			systemLog <<"Settings file could not be located. Aborting";
			returnCode=EX_SOFTWARE;	
		}
			break;
		case -2:
		{
			systemLog <<"Database file could not be read. Aborting";
			returnCode=EX_DATAERR;	
		}
			break;
		default: systemLog <<"unknown error occurred";
	}
	systemLog <<'\n';
}

site copyToSite(std::string)
{
	
}
