#ifndef __INPUT_H__
#define __INPUT_H__

#include <form.h>
#include <string>
#include "menu.hpp"
class Input: public Menu
{
	private:
	int times_entered,_x;
	bool Lower;
	FIELD *field[3];
	WINDOW *menu;
	FORM *form;
	std::string email;
	std::string title[4];
	public:
	Input(std::string,int, int, window);
	void destroy();
	window handleAccept();
	window handleSelection(int);

};

#endif
