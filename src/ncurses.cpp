#include <ncurses.h>
#include <cstring>

int main(void)
{
	int x,y;
	initscr();
	raw();
	getmaxyx(stdscr, y,x);
	noecho();
	char message[]="hello middle screen";
	mvprintw(y/2, (x-strlen(message))/2, "%s", message);
	mvprintw(y-2,0,"This screen is %d x %d",x,y);
	refresh();
	int ch;
	getch();
	endwin();
	return 0;

}
