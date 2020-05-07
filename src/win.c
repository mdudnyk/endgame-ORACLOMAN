#include "header.h"

void center1(int row, char *title);
    
void win(void)
{   
 char *t;
    int len;  
	    	init_pair(1, COLOR_CYAN, COLOR_BLACK);
		init_pair(2, COLOR_GREEN, COLOR_BLACK);
		init_pair(3, COLOR_RED, COLOR_BLACK);
            init_pair(4, COLOR_BLUE, COLOR_BLACK);
            init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	attrset(COLOR_PAIR(1));
	box(stdscr,'*','*'); 	
   	



center1(10,"##  ##  ####  ##  ##");
center1(11," ####  ##  ## ##  ##");
center1(12," ##   ##  ## ##  ##");
center1(13," ##   ##  ## ##  ##");
center1(14,"##    ####   ####");
center1(16,"			##   # ###### ##  ##");
center1(17,"			##   #   ##   ### ##");
center1(18,"			## # #   ##   ## ###");
center1(19,"			######   ##   ##  ##");
center1(20,"	       	                 ## ## ###### ##  ##");
attrset(COLOR_PAIR(3));

center1(2,"                (@@)      ");
center1(3,"/\\_)(_/\\e ");
center1(4,"g/\\(=--=)/\\e");
center1(5," //\\\\    ");
center1(6,"  __| |__    ");




attrset(COLOR_PAIR(4));
char robot[] = "VBrykov, MDudnyk, IMovchan, VRydkovsky";

len = strlen(robot);
    t = robot;           /* initialize pointer */
    while(len)
    {
        move(22,1);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(10);         /* .1 sec. delay */
        len--;
	
}
attrset(COLOR_PAIR(2));
char robot6[] = "GAME OVER UCODER";

len = strlen(robot6);
    t = robot6;           /* initialize pointer */
    while(len)
    {
        move(2,6);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(10);         /* .1 sec. delay */
        len--;
    
}

char robot7[] = "Angry Orakle backed   ";

len = strlen(robot7);
    t = robot7;           /* initialize pointer */
    while(len)
    {
        move(3,6);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(10);         /* .1 sec. delay */
        len--;
    
}

attrset(COLOR_PAIR(2));
char robot8[] = "Goo for new battle   ";

len = strlen(robot8);
    t = robot8;           /* initialize pointer */
    while(len)
    {
        move(4,6);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(10);         /* .1 sec. delay */
        len--;
    
}

attrset(COLOR_PAIR(2));
char robot1[] = "Press (esc) to Exit    ";

len = strlen(robot1);
    t = robot1;           /* initialize pointer */
    while(len)
    {
        move(6,6);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(10);         /* .1 sec. delay */
        len--;
    
}

char robot10[] = "Press (R) to Restart  ";

len = strlen(robot10);
    t = robot10;           /* initialize pointer */
    while(len)
    {
        move(5,6);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(10);         /* .1 sec. delay */
        len--;
    
}
attrset(COLOR_PAIR(5));
char robot11[] = "Loser...../\\_/\\(0-0RAKL0-0)/\\_/\\....Loser";
len = strlen(robot11);
    t = robot11;           /* initialize pointer */
    while(len)
    {
        move(8,30);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(50);         /* .1 sec. delay */
        len--;

}

char robot12[] = "    I*LL be Back                  /\\_/\\(0-0RAKL0-0)/\\_/\\                I*m you horror";
len = strlen(robot12);
    t = robot12;           /* initialize pointer */
    while(len)
    {
        move(15,6);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(50);         /* .1 sec. delay */
        len--;

}

    getch();
    return;
}   

void center1(int row, char *title)
{   
    int len,indent,y,width;
    getmaxyx(stdscr,y,width);
    len = strlen(title);
    indent = (width - len)/2;
    mvaddstr(row,indent,title);
    refresh();
}

