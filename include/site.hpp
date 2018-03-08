#include <string>
#include <vector>
#include "json.hpp"
#ifndef __SITE_H_
#define __SITE_H_


nlohmann::json settings;
nlohmann::json record;

struct site{
	std::string uname, website, notes, illegal, password, email;
	int length;
	site();
}temp;

site::site()
{
	uname=website=notes=illegal=password=email="";
	length=10;
}
#endif