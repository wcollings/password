/*
	sorts the entries alphabetically

	read file: temp_backup.txt
	writes to passwords.txt

	end point of pw
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct field
{
	string username;
	string password;
};

string file_loc="temp_backup.txt";
bool sort(vector<field>& inputs);
bool write(vector<field>& inputs);
bool isalphabetical(string a, string b);

int main()
{
	vector<field> inputs;
	field temp;
	ifstream in;
	in.open(file_loc.c_str());
		getline(in, temp.username);
	do
	{
		getline(in, temp.password);
		inputs.push_back(temp);
		in.ignore(100, '\n');
		getline(in, temp.username);
	}while (!in.eof());
	in.close();
	sort(inputs);
	write(inputs);
}

bool sort(vector<field>& inputs)
{
	int n=inputs.size();
	bool swapped=true;
	while (swapped == true)
	{
		swapped=false;
		for (int i = 0; i < inputs.size(); ++i)
		{
			if(!isalphabetical(inputs[i].username, inputs[i+1].username))
			{
				swapped=true;
				swap(inputs[i], inputs[i+1]);
			}
		}
		
	}
}

bool write(vector<field>& inputs)
{
	ofstream out;
	out.open(file_loc.c_str());
	for (int i=0; i < inputs.size(); i++)
	{
		out <<inputs[i].username <<endl <<inputs[i].password <<endl <<endl;
	}
	out.close();
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