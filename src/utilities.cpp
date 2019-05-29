//copyright 2018 William Collings
//UTILITIES
//
//has all the misc. functions.
//exists, readIn

#include "include/site.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using json= nlohmann::json;

//inline auto exists(std::string);
inline bool readIn();
inline int convertToNumber(char);
inline void Find(std::string);
inline void help();
inline void write();
inline void logNewEntry(site);
inline void print(json::iterator);
inline void print(site);
inline void logMessages(int);

ofstream systemLog;
inline auto exists(string toFind)
{
	auto find=record.find(toFind);
	if (find!= record.end())
	{
		cout <<"from database:\n";
		print(find);
	}
	return find;
}

bool readIn()
{
	ifstream in;
	in.open("settings.json");
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

inline int convertToNumber(char c)
{
	char temp=toupper(c);
	int num=(static_cast<int>(temp))-64;
   return num;	
}

inline void Find(string a)
{
	auto find=record.find(a);
	if (find != record.end())
	{
		print(find);
	}
}

inline void print(json::iterator a)
{
	cout <<"data for site \"" <<a.key() <<"\":\n";
	std::cout <<*a;

}

inline void print(site s)
{
	cout <<"data for site \"" <<s.website <<"\":\n";
	if (s.email != "") cout <<'\t' <<"email: " <<s.email <<'\n';
	cout <<'\t' <<"password: " <<s.password <<'\n';
	if (s.uname != "") cout <<'\t' <<"username:" <<s.uname <<'\n';
}


inline void help()
{
	cout <<"summary of arguments:\n"
		  <<"\t-p: print all entries\n"
		  <<"\t-l: generate a long password\n"
		  <<"\t-s: generate a shorter (8 or 9 char) password\n"
		  <<"\t-r: generate a random series of characters. must specify a length as well\n";
}

inline void write()
{
	ofstream out;
	out.open(settings.at("save_file").get<std::string>());
	out <<record.dump(3);
	logMessages(2);
	out.close();
}

inline void logNewEntry(site s)
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
		case -1:	systemLog <<"Settings file could not be located. Aborting";
			break;
		case -2: systemLog <<"Database file could not be read. Aborting";
			break;
		case 0: systemLog <<"Program initialized";
			break;
		case 1: systemLog <<"generated new password";
			break;
		case 2: systemLog <<"Database updated sucessfully";
			break;
		default: systemLog <<"unknown error occurred";
	}
	systemLog <<'\n';
}

