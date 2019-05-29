#ifndef __SHORT_HPP_
#define __SHORT_HPP_

#include <ncurses.h>
#include "menu.hpp"
class Short: public Menu{
	public:
		Short(int y, int x);
		window handleSelection(int);
};
#endif
