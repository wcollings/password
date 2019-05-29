#ifndef main_menu_hpp
#define main_menu_hpp

#include <ncurses.h>
#include <string>
#include <vector>
#include "menu.hpp"
class Main: public Menu{
	public:
		Main(int y, int x);
		window handleSelection(int);
};
#endif
