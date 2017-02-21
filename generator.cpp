/*
	generates standard password

	takes args: website name
	generates a password
	appends temp_backup
	start point of the "pw" command
*/
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

struct sites
{
	string site_name;
	string password;
};

int num_calc(char to_convert);
string cap(string site);

int main(int argc, char const *argv[])
{
	sites current_site;
	ofstream out;
	out.open("temp_backup.txt", std::ios_base::app);
	string password;	
	time_t t=time(0);
	struct tm * now = localtime(& t);
	if (argc == 0)
	{
		cout <<"I need an argument, buddy\n";
		return -1;
	}
	password=to_string(num_calc(argv[1][0]));
	password+=to_string(num_calc(argv[1][1]));
	password+=toupper(argv[1][2]);
	if (now->tm_mon+1 < 10)
	{
		password+="0";
		password+=to_string(now->tm_mon+1);
	}
	else password+=to_string(now->tm_mon+1);
	if (now->tm_mday+1 < 10)
	{
		password+="0";
		password+=to_string(now->tm_mday+1);	
	}
	else password+=to_string(now->tm_mday+1);
	password+=cap(argv[1]);
	cout <<"the password is " <<password <<endl;
	out <<argv[1] <<endl <<password <<"\n\n";
	return 0;
}

int num_calc(char to_convert) //For the first part of the password: convert letter to number
{
	switch(to_convert)
	{
		case 'a': return 1;
			break;
		case 'b': return 2;
			break;
		case 'c': return 3;
			break;
		case 'd': return 4;
			break;
		case 'e': return 5;
			break;
		case 'f': return 6;
			break;
		case 'g': return 7;
			break;
		case 'h': return 8;
			break;
		case 'i': return 9;
			break;
		case 'j': return 10;
			break;
		case 'k': return 11;
			break;
		case 'l': return 12;
			break;
		case 'm': return 13;
			break;
		case 'n': return 14;
			break;
		case 'o': return 15;
			break;
		case 'p': return 16;
			break;
		case 'q': return 17;
			break;
		case 'r': return 18;
			break;
		case 's': return 19;
			break;
		case 't': return 20;
			break;
		case 'u': return 21;
			break;
		case 'v': return 22;
			break;
		case 'w': return 23;
			break;
		case 'x': return 24;
			break;
		case 'y': return 25;
			break;
		case 'z':return 26;
	}
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
