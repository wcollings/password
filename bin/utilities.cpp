//UTILITIES
//
//has all the misc. functions.
//exists, readIn

#include "../include/site.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using json= nlohmann::json;

bool exists(string toFind);
bool readIn();
int convertToNumber(char c);
void Find(std::string);
void help();
void write();
void logNewEntry(site);


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
	in.open("settings.json");
	if (in)
	{
		//cout <<"I opened settings\n";
		in >>settings;
		in.close();
		in.open(settings.at("save_file").get<std::string>());
		if (in)
		{
			//cout <<"I opened the file!\n";
			in >>record;
		}
		else cout <<"The database file doesn't exist or is formatted wrong\n";
		return true;
	}
	else cout <<"couldn't find the settings file. quitting\n";
	return false;
}

int convertToNumber(char c)
{
	char temp=toupper(c);
	int num=(static_cast<int>(temp))-64;
	cout <<num <<endl;
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
	cout <<"data for site \"" <<site.website <<"\":\n";
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