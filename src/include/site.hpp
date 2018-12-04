//copyright 2018 William Collings
#include <string>
#include <vector>
#include "json.hpp"
#ifndef __SITE_H_
#define __SITE_H_

<<<<<<< HEAD

=======
#define VERSION_NUMBER 0.5.2
>>>>>>> 5fc3506071b23b41be99fe74f179c5caeb3a9ce2
nlohmann::json settings;
nlohmann::json record;

struct site{
	std::string uname, website, notes, illegal, password, email;
	int length;
	site();
};

site::site()
{
	uname=website=notes=illegal=password=email="";
	length=10;
}
<<<<<<< HEAD
#endif
=======

struct acct{
	std::string uname, website, notes, password, email;
};
#endif
>>>>>>> 5fc3506071b23b41be99fe74f179c5caeb3a9ce2
