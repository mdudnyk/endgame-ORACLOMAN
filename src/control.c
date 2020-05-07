#include "header.h"

void center3(int row, char *title);
    
void control(void)
{   
 char *t;
    int len;   	
	    	init_pair(1, COLOR_CYAN, COLOR_BLACK);
		init_pair(2, COLOR_GREEN, COLOR_BLACK);
	attrset(COLOR_PAIR(1));
	box(stdscr,'*','*'); 	
   	
		attrset(COLOR_PAIR(1));
    	center3(5, "Oraklo Control");
    	center3(9, "Up - W");
    	center3(11, " Right - A");
    	center3(13, "Down - S");
	center3(15, "Left - D");
	center3(17, "Restart - R");
	center3(19, "Start game - F");
	center3(21, "Exit - esc");

curs_set(0);
attrset(COLOR_PAIR(2) | A_BOLD);
char robot[] = "/\\_/\\(0-0RAKL0-0)/\\_/\\.....................\\(*o*)/";
len = strlen(robot);
    t = robot;           /* initialize pointer */
    while(len)
    {
        move(25,5);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(50);         /* .1 sec. delay */
        len--;

}
    getch();

    return;
}   

void center3(int row, char *title)
{   
    int len,indent,y,width;
    getmaxyx(stdscr,y,width);
    len = strlen(title);
    indent = (width - len)/2;
    mvaddstr(row,indent,title);
    refresh();
}

