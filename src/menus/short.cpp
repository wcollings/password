#include "short.hpp"

Short::Short(int y,int x)
{
	name="SHORT";
	choices.push_back("generate password");
	choices.push_back("back");
	choices.push_back("quit");
	width=calculateWidth(choices);
	max=choices.size();
	this->menu=newwin(30, width+2,y,x);
	wrefresh(menu);
}

window Short::handleSelection(int highlight)
{
	switch (highlight)
	{
		case 0: return PASSWORD;
		case 1: return LAST;
		case 2: return QUIT;
	}
	return Null;
}
