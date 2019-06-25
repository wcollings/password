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
#include <cstdio>
#include <iomanip>
#include <sstream>
using namespace std;
using json= nlohmann::json;
int returnCode=0;
bool exists(site);
bool findAndPrint(site);
bool readIn();
int convertToNumber(char);
void Find(std::string);
void help();
void print(json::iterator, int);
void write();
void logNewEntry(site);
void logMessages(int);
void printsettings();
site copyToSite(std::string);
std::string formatEntry(site*);

ofstream systemLog;
bool findAndPrint(site toFind)
{
	cout <<"looking for an entry with website " <<toFind.website <<'\n';
	if  (!record[toFind.website].is_null())
	{
		cout <<"From database:";
		string s(record[toFind.website].dump());
		std::string tabs="\t";
		for (int i=0; i < s.size(); ++i)
		{
			switch(s[i])
			{
				case '{':
					tabs+='\t';
					cout <<'\n' <<tabs;
					break;
				case '}':
					tabs.pop_back();
					//tabs.pop_back();
					cout <<'\n';
					break;
				case ',':
					cout <<'\n' <<tabs;
					break;
				case '\'':
				case '\"':
					break;
				default:
					cout <<s[i];
			}
		}
	}
	else cout <<"Couldn't find any accounts associated with the website " <<toFind.website <<'\n';
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
		in.open(settings["save_file"]);
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


void help()
{
	cout <<"summary of arguments:\n"
		  <<"\t-p: print all entries\n"
		  <<"\t-l: generate a long password\n"
		  <<"\t-s: generate a shorter (8 or 9 char) password\n"
		  <<"\t-r: generate a random series of characters. must specify a length as well\n";
}

void print(json::iterator j, int level)	//FIX This. Iterator wrapper is not a type, its's a function
{
	//string tab="\n";
	//for (int i=0; i < level; ++i) tab+='\t';
	//cout <<tab <<j <<":";
	//if ((*j).is_structured()) print(*j, level+1);
	//else cout <<*j;
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
	json j=json::parse(formatEntry(&s));
	record[s.website][s.uname]=j;
	std::cout <<"Log successful\n";
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

void copyToSite(site * s)
{
	char buff[50];
	if (!record[s->website].is_null())
	{
		for (auto i: json::iterator_wrapper(record[s->website]))
		{
			if (i.key()=="email") s->email==i.value();
			if (i.key()=="password") s->password=i.value();
			else
			{
				sprintf(buff,"\"%s\":\"%s\"",i.key(),i.value());
				s->notes.push_back(string(buff));
			}
		}
	}
}

std::string formatEntry(site *s)
{
	std::string temp="{";
	temp+="\"passord\":\""+s->password+"\"";
	if (s->email!="")
	temp+=",\"email\":\""+s->email+"\"";
	temp+="}";
	std::cout <<temp <<'\n';
	return temp;
}
