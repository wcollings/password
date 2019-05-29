#include <form.h>
#include <cstring>
#include <string>

std::string email;
FIELD *field[3];
FORM *my_form;
WINDOW *w, *lower, *current;
int handleFields(int ch);
int handleAccept(int ch);
int main()
{
	int ch,x,y, status=0;
	initscr();
	cbreak();
	noecho();
	start_color();
	init_pair(1,COLOR_RED, COLOR_BLACK);
	init_pair(2,COLOR_RED, COLOR_BLACK);
	keypad(stdscr,TRUE);
	field[0]=new_field(1,10,2,1,0,0);
	field[1]=new_field(1,10,4,1,0,0);
	field[2]=NULL;

	//COLORS
	set_field_fore(field[0], COLOR_PAIR(1));
	set_field_back(field[0], COLOR_PAIR(2));
	set_field_fore(field[1], COLOR_PAIR(1));
	set_field_back(field[1], COLOR_PAIR(2));

	//Other options
	set_field_back(field[0], A_UNDERLINE); 
 	field_opts_off(field[0], O_AUTOSKIP); 
	set_field_back(field[1], A_UNDERLINE); 
 	field_opts_off(field[1], O_AUTOSKIP); 
	my_form=new_form(field);
	scale_form(my_form,&y,&x);
	w=newwin(LINES/2,x+4,0,0);
	lower=newwin(LINES/2,x+4,LINES/2+1,0);
	box(w,0,0);
	refresh();
	set_form_win(my_form,w);
	set_form_sub(my_form,derwin(w,y,x,2,2));
	post_form(my_form);
	refresh();
	mvwprintw(w,3,3,"email:");
	mvwprintw(w,5,3,"Value 2:");
	mvwprintw(lower,1,1,"SUBMIT");
	refresh();
	wrefresh(w);
	wrefresh(lower);
	current=w;
	refresh();
//	form_driver(my_form, REQ_NEXT_FIELD);
	ch=wgetch(current);
	while(1)
	{
		if (current==w) status=handleFields(ch);
		if (current==lower) status=handleAccept(ch);
		if (status==-1) break;
		ch=wgetch(current);
	}
	unpost_form(my_form);
	free_form(my_form);
	free_field(field[0]);
	free_field(field[1]);
	endwin();
	return 0;
}

int handleFields(int ch)
{
	curs_set(1);
	static int sel=0;
	switch(ch)
	{
		case 27:
			return -1;
		case 10:
			sel++;
			if (sel < 2)
			{
				form_driver(my_form, REQ_NEXT_FIELD);
				set_current_field(my_form, field[1]);
			}
			else
			{
				curs_set(0);
				current=lower;
			}
			break;
		default:
			form_driver(my_form, ch);
			break;
	}
	wrefresh(w);
	return 0;
}

int handleAccept(int ch)
{
	static int times_entered=0;
	if (ch=='q') return -1;
	if (ch==10 && times_entered==0)
	{
		times_entered++;
		wattron(lower,A_REVERSE);
		mvwprintw(lower,1,1,"SUBMIT");
		wattroff(lower, A_REVERSE);
		return 0;
	}
		
	if (ch==10 && times_entered==1)
	{
		email=field_buffer(field[0],0);
		mvwprintw(lower,3,3,"You entered %s", email.c_str());
	}
	return 0;
}
