#include <string>
#include <vector>
#ifndef __SITE_H_
#define __SITE_H_

struct site{
	std::string name;
	std::string uname;
	std::string password;
	std::vector<std::string> notes;
	site(char * file);
	site();
};
std::vector<site> entry;

#endif