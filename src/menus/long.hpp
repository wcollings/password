#ifndef __long_hpp__
#define __long_hpp__
#include <ncurses.h>
#include "menu.h"

class Long: public Menu
{
	public:
		Long(int x, int y);
		window handleSelection(int);
};

#endif
