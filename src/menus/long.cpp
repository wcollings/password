#include "long.hpp"

Long::Long()
{
	name="LONG";
	choices.push_back("generate password");
	choices.push_back("back");
	choices.push_back("quit");
	width=calculateWidth(choices);
	max=choices.size();
	this->menu=newwin(30, width+2,x,y);
	wrefresh(menu);
}
