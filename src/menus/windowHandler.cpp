#include "windowHandler.hpp"

windowHandler::windowHandler()
{
	_h=0;
	_w=0;
	_x=1;
	_y=0;
	w=NULL;
}

void windowHandler::initScreen(void)
{
	set_escdelay(0);
	initscr();
	raw();
	noecho();
	refresh();
	addMain();
	curs_set(0);
	keypad(stdscr, TRUE);
//	mvprintw(0,0,"CURRENT WINDOW: %s", w->name.c_str());
	refresh();
}
void windowHandler::run(void)
{
	int c,ch;
	int highlight=0;
	int choice=-1;
	while(1)
	{
		ch=wgetch(w->menu);
		if (c=='q' || ch =='q') break;
		switch(ch)
		{
			case 'k':
				if (highlight==0)
					highlight=w->max-1;
				else highlight--;
				break;
			case 'j':
				if (highlight==w->max-1)
					highlight=0;
				else highlight++;
				break;
			case '\n': choice=highlight;
				break;
			default: break;
		}
		w->print(highlight);
		if (choice != -1) 
		{
//			mvprintw(0,0,"CURRENT WINDOW: %s", w->name.c_str());
			window r=w->handleSelection(choice);
			switch(r)
			{ 
				case Null: break;
				case SHORT:
					addShort();
					highlight=0;
					w->print(highlight);
//					break;
				case LAST:
					removeWindow();
					w->print(0);
					break;
				case QUIT:
					return;
			}
			choice=-1;
			highlight=0;
			refresh();
		}
	}
}
windowHandler::~windowHandler()
{
	m.back()=std::move(w);
	if (!m.empty())
	{
		for (auto& M:m)
			M->destroy();
		m.clear();
	}
		clrtoeol();
		refresh();
		endwin();
}

void windowHandler::addMain(void)
{
	m.push_back(std::unique_ptr<Menu>(new Main(_y,_x)));
	w=std::move(m.back());
	w->print(0);
	refresh();
	_x+=w->getWidth()+2;
}

void windowHandler::addShort(void)
{
	m.back()=std::move(w);
	m.push_back(std::unique_ptr<Menu>(new Input("Short",_y, _x,SHORT)));
	w=std::move(m.back());
	w->print(0);
	w->handleSelection(0);
	refresh();
	_x+=w->getWidth()+2;
}

void windowHandler::removeWindow(void)
{
	_y-=w->getWidth();
	w->destroy();
	m.pop_back();
	w=std::move(m.back());
	refresh();
}
