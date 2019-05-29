#ifndef __menu_hpp_
#define __menu_hpp_

#include <ncurses.h>
#include <string>
#include <vector>

int calculateWidth(std::vector<std::string> c);
enum window{MAIN,SHORT,LONG,RANDOM,VIEW,DATA,PASSWORD,LAST,QUIT, Null};
class Menu{
	protected:
	int width;
	public:
		std::string name;
		std::vector<std::string> choices;
		int max;
		WINDOW * menu;
		void destroy();
		void print(int highlight);
		virtual window handleSelection(int)=0;
		int getWidth();
};
#endif
