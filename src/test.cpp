#include <string>
#include <iostream>
using namespace std;

int main(void)
{
	string site="test.com";
	string uname="wcollings";
	string password="test";

	string ret='\"'+site+"\":{\n\t";
	ret+='\"'+uname+"\":{\n\t\t";
	ret+="\"password\":";
	ret+='\"'+password+"\"\n\t}\n}";
	cout <<ret <<'\n';
	return 0;


}
