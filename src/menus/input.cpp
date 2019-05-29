#include "input.hpp"

Input::Input(std::string Name, int Y, int X, window sel)
{
	title[0]="";
	title[1]="Short";
	title[2]="Long";
	title[3]="Rand";
	Lower=false;
	times_entered=0;
	name=Name;
	_x=X;
	int y;
	field[0]=new_field(1,10,4,2,0,0);
	field[1]=new_field(1,10,6,2,0,0);
	field[2]=NULL;
	//set other options
	set_field_back(field[0], A_UNDERLINE); 
 	field_opts_off(field[0], O_AUTOSKIP); 
	set_field_back(field[1], A_UNDERLINE); 
 	field_opts_off(field[1], O_AUTOSKIP); 
	form=new_form(field);
	scale_form(form,&y,&width);
	//making the windows
//	width+=4;
//	width=(width >10?width : 10);
//	width=(width >name.size()?width : name.size());
	menu=newwin(30,width+4,Y,X);
	refresh();
	set_form_win(form,menu);
	WINDOW * sub=derwin(menu,26,width,2,2);
	set_form_sub(form,sub);
	box(menu,0,0);
	post_form(form);
//	wrefresh(menu);
	mvwprintw(menu,1,3,"Generating");
	mvwprintw(menu,2,3,"%s",title[(int)sel].c_str());
	mvwprintw(menu,3,3,"email:");
	mvwprintw(menu,5,3,"Value 2:");
	mvwprintw(menu,7,3,"SUBMIT");
	wrefresh(menu);
	wrefresh(sub);
	refresh();
}
void Input::destroy()
{
	wattron(stdscr, A_REVERSE);
	mvprintw(LINES/2,COLS/2-3,"LOADING");
	wattroff(stdscr, A_REVERSE);
	refresh();
	unpost_form(form);
	free_form(form);
	free_field(field[0]);
	free_field(field[1]);
}
window Input::handleSelection(int IGNORE)
{
	curs_set(1);
	int sel=0;
	int ch;
	while(1)
	{
		ch=getch();
		switch(ch)
		{
			case 27: return LAST;
			case 10:
				sel++;
				if (sel < 2)
				{
					form_driver(form, REQ_NEXT_FIELD);
				}
				else
				{
					curs_set(0);
					goto ACCEPT;
				}
				break;
			default:
				form_driver(form, ch);
				break;
		}
	}
	ACCEPT:
	handleAccept();
	wrefresh(menu);
	return Null;
}

window Input::handleAccept()
{
	wattron(stdscr,A_REVERSE);
	mvprintw(7,_x+3,"SUBMIT");
	wattroff(stdscr, A_REVERSE);
	int ch;
	while ((ch=getch())!=10) if (ch=='q') return QUIT;
	email=field_buffer(field[0],0);
	mvprintw(15,_x+3,"You entered %s", email.c_str());
	refresh();
	return DATA;
}
