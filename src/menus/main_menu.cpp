#include "main_menu.hpp"
Main::Main(int y, int x)
{
	name="Main";
	choices.push_back("short password");
	choices.push_back("long password");
	choices.push_back("random password");
	choices.push_back("view database");
	choices.push_back("quit");
	width=calculateWidth(choices);
	max=choices.size();
	this->menu=newwin(30,width+2,y,x);
}

window Main::handleSelection(int selection)
{
	switch(selection)
	{
		case 0: return SHORT;
		case 1: return LONG;
		case 2: return RANDOM;
		case 3: return VIEW;
		case 4: return QUIT;
	}
	return QUIT;
}
