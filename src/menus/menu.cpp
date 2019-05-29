#include "menu.hpp"
 
void Menu::destroy()
{
	wborder(menu, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	werase(menu);
	wrefresh(menu);
	delwin(menu);
}
void Menu::print(int highlight)
{
	int x,y,i;
	x=1;
	y=2;
	box(menu, 0,0);
	for(i=0; i < max; ++i)
	{
		if (highlight==i)
		{
			wattron(menu,A_REVERSE);
			mvwprintw(menu,y,x,"%s",choices[i].c_str());
			wattroff(menu, A_REVERSE);
		}
		else mvwprintw(menu,y,x,"%s",choices[i].c_str());
		++y;
	}
	wrefresh(this->menu);
}

int Menu::getWidth()
{
	return width;
}

int calculateWidth(std::vector<std::string> c)
{
	int max=0;
	for (int i=0; i < c.size(); ++i)
		max=(c[i].size()>max? c[i].size():max);
	return max;
}
