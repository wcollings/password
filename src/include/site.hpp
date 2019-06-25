//copyright 2018 William Collings
#include <string>
#include <vector>
#include "json.hpp"
#ifndef __SITE_H_
#define __SITE_H_

#define VERSION_NUMBER 0.5.2
nlohmann::json settings;
nlohmann::json record;

struct site{
	std::string uname, website, illegal, password, email;
	std::vector<std::string> notes;
	int length;
	site();
};

site::site()
{
	uname=website=illegal=password=email="";
	length=10;
}

struct acct{
	std::string uname, website, notes, password, email;
};
#endif
