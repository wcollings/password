#ifndef __current_hpp_
#define __current_hpp_
#include <memory>
#include "main_menu.hpp"
#include "short.hpp"
#include "input.hpp"

class windowHandler{
	int _h,_w,_x,_y;
	std::vector<std::unique_ptr<Menu>> m;

	public:
		windowHandler();
		~windowHandler();
		std::unique_ptr<Menu> w;
		void initScreen();
		void run();
		void addMain();
		void addShort();
		void addLong();
		void addRandom();
		void addPassword();
		void addView();
		void addData();
		void removeWindow();
		void quit();

};



#endif
