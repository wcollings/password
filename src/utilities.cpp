<<<<<<< HEAD
//copyright 2018 William Collings
//UTILITIES
//
//has all the misc. functions.
//exists, readIn
=======
//Copyright 2018 William Collings
//UTILITIES
//
//has all the misc. functions
>>>>>>> 5fc3506071b23b41be99fe74f179c5caeb3a9ce2

#include "include/site.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
<<<<<<< HEAD

using namespace std;
using json= nlohmann::json;

inline bool exists(std::string);
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
inline bool exists(string toFind)
=======
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
>>>>>>> 5fc3506071b23b41be99fe74f179c5caeb3a9ce2
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

<<<<<<< HEAD
inline bool readIn()
{
	ifstream in;
	in.open("settings.json");
=======
bool readIn()
{
	ifstream in;
	in.open("../settings.json");
>>>>>>> 5fc3506071b23b41be99fe74f179c5caeb3a9ce2
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

<<<<<<< HEAD
inline int convertToNumber(char c)
=======
int convertToNumber(char c)
>>>>>>> 5fc3506071b23b41be99fe74f179c5caeb3a9ce2
{
	char temp=toupper(c);
	int num=(static_cast<int>(temp))-64;
   return num;	
}

<<<<<<< HEAD
inline void Find(string a)
=======
void Find(string a)
>>>>>>> 5fc3506071b23b41be99fe74f179c5caeb3a9ce2
{
	auto find=record.find(a);
	if (find != record.end())
	{
		print(find);
	}
}

<<<<<<< HEAD
inline void print(json::iterator a)
=======
void print(json::iterator a)
>>>>>>> 5fc3506071b23b41be99fe74f179c5caeb3a9ce2
{
	cout <<"data for site \"" <<a.key() <<"\":\n";
	json j=a.value();
	for (auto i=j.begin(); i != j.end(); ++i)
		cout <<'\t' <<i.key() <<':' <<i.value().dump(3) <<'\n';
}

<<<<<<< HEAD
inline void print(site s)
=======
void print(site s)
>>>>>>> 5fc3506071b23b41be99fe74f179c5caeb3a9ce2
{
	cout <<"data for site \"" <<s.website <<"\":\n";
	if (s.email != "") cout <<'\t' <<"email: " <<s.email <<'\n';
	cout <<'\t' <<"password: " <<s.password <<'\n';
	if (s.uname != "") cout <<'\t' <<"username:" <<s.uname <<'\n';
}


<<<<<<< HEAD
inline void help()
=======
void help()
>>>>>>> 5fc3506071b23b41be99fe74f179c5caeb3a9ce2
{
	cout <<"summary of arguments:\n"
		  <<"\t-p: print all entries\n"
		  <<"\t-l: generate a long password\n"
		  <<"\t-s: generate a shorter (8 or 9 char) password\n"
		  <<"\t-r: generate a random series of characters. must specify a length as well\n";
}

<<<<<<< HEAD
inline void write()
=======
void write()
>>>>>>> 5fc3506071b23b41be99fe74f179c5caeb3a9ce2
{
	ofstream out;
	out.open(settings.at("save_file").get<std::string>());
	out <<record.dump(3);
	logMessages(2);
	out.close();
}

<<<<<<< HEAD
inline void logNewEntry(site s)
=======
void logNewEntry(site s)
>>>>>>> 5fc3506071b23b41be99fe74f179c5caeb3a9ce2
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

<<<<<<< HEAD
inline void logMessages(int code)
=======
void logMessages(int code)
>>>>>>> 5fc3506071b23b41be99fe74f179c5caeb3a9ce2
{
	time_t t=time(0);
	struct tm * now = localtime(&t);
	std::string time_str=asctime(now);
	systemLog <<'[' <<time_str.substr(0, time_str.size()-1) <<"] ";
	switch (code)
	{
<<<<<<< HEAD
		case -1:	systemLog <<"Settings file could not be located. Aborting";
			break;
		case -2: systemLog <<"Database file could not be read. Aborting";
			break;
		case 0: systemLog <<"Program initialized";
			break;
		case 1: systemLog <<"generated new password";
			break;
		case 2: systemLog <<"Database updated sucessfully";
=======
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
>>>>>>> 5fc3506071b23b41be99fe74f179c5caeb3a9ce2
			break;
		default: systemLog <<"unknown error occurred";
	}
	systemLog <<'\n';
<<<<<<< HEAD
}
=======
}

site copyToSite(std::string)
{
	
}
>>>>>>> 5fc3506071b23b41be99fe74f179c5caeb3a9ce2
