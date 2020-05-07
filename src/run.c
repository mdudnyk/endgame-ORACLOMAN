#include "header.h"

void center2(int row, char *title);
    
void run(void)
{   
 char *t;
    int len;   
	    init_pair(1, COLOR_CYAN, COLOR_BLACK);
		init_pair(2, COLOR_GREEN, COLOR_BLACK);
		init_pair(3, COLOR_RED, COLOR_BLACK);
		init_pair(4, COLOR_BLACK, COLOR_WHITE);
		init_pair(5, COLOR_BLACK, COLOR_CYAN);
		init_pair(6, COLOR_YELLOW, COLOR_BLACK);
	attrset(COLOR_PAIR(1));
	box(stdscr,'*','*'); 	
   	
		attrset(COLOR_PAIR(2) | A_BOLD);
  
 center2(1, "                   (    /   )  /     ))\\))  (  )    )                    ");
 center2(2, "                (  )   \\   )\\(          |  ))( )  (|                    ");
 center2(3, "              >)     ))/   |          )/  \\((  ) \\                      ");
 center2(4, "              (     (      .        -.     V )/   )(    (                 ");       
 center2(5, "             )(    ,'))     \\ /          \\( `.    )                     ");
 center2(6, "             (\\>  ,'/__      ))            __`.  /                       ");
 center2(7, "            ( \\   | /  ___   ( \\/     ___   \\ | ( (                    ");
 center2(8, "             \\.)  |/  /   \\__      __/  \\   \\|  ))                    ");
 center2(9, "            .  \\. |>  \\      | __ |      /   <|  /                      ");
center2(10, "                 )/   \\____/ :..: \\____/     \\ <                      ");
center2(11, "        ) (  \\ (|__  .      / ;: \\          __| )  (                   ");
center2(12, "         ((    )\\)  ~--_     --  --      _--~    /  ))                  ");
center2(13, "         \\    (    |  ||               ||  |   (  /                     ");
center2(14, "               \\.  |  ||_             _||  |  /                         ");
center2(15, "       )            > :  |  ~V+-I_I_I-+V~  |  : (.        )              ");
center2(16, "    (            (  \\:  T\\   _     _   /T  : ./     )                  ");
center2(17, "                  \\  :    T^T T-+-T T^T    ;<      (    (               ");
center2(18, "       (  )            \\..`_       -+-       _'  )          )           ");
center2(19, "       )     )        . `--=.._____..=--'. ./         (  )               ");
center2(20, "        (  ((     ) (  )        )             (     ) (   )              "); 
center2(21, "      )   (  > _^/) ))__ (   ( /(.      ))     ))._/(__))                ");
attrset(COLOR_PAIR(6) | A_BOLD);
center2(23, "           $$$$  $$$$$   $$$$   $$$$  $$      $$$$            ");
center2(24, "          $$  $$ $$  $$ $$  $$ $$  $$ $$     $$  $$           ");
center2(25, "          $$  $$ $$$$$  $$$$$$ $$     $$     $$  $$           ");
center2(26, "          $$  $$ $$  $$ $$  $$ $$  $$ $$     $$  $$           ");
center2(27, "           $$$$  $$  $$ $$  $$  $$$$  $$$$$$  $$$$            ");






attrset(COLOR_PAIR(5) | A_BOLD | A_STANDOUT);
char robot2[] = "Start (F)";
len = strlen(robot2);
    t = robot2;           /* initialize pointer */
    while(len)
    {
        move(5, COLS/2 + 25);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(60);         /* .1 sec. delay */
        len--;
}
attrset(COLOR_PAIR(5) | A_BOLD | A_STANDOUT);
char robot3[] = "Control (C)";
len = strlen(robot3);
    t = robot3;           /* initialize pointer */
    while(len)
    {
        move(7, COLS/2 + 25);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(60);         /* .1 sec. delay */
        len--;
}

attrset(COLOR_PAIR(5) | A_BOLD | A_STANDOUT);
char robot4[] = "Exit (ESC)";
len = strlen(robot4);
    t = robot4;           /* initialize pointer */
    while(len)
    {
        move(9, COLS/2 + 25);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(60);         /* .1 sec. delay */
        len--;
}
attrset(COLOR_PAIR(3) | A_BOLD);
char robot1[] = "your best friend until death";
mvprintw(28, (COLS/2 - strlen(robot1)/2), robot1);

attrset(COLOR_PAIR(2) | A_BOLD);
char robot5[] = "ENDGAME";
len = strlen(robot5);
    t = robot5;           /* initialize pointer */
    while(len)
    {
        move(13, COLS/2 + 25);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(100);         /* .1 sec. delay */
        len--;
}

attrset(COLOR_PAIR(6) | A_BOLD );
char robot[] = "                                                                                                                                                                            /\\_/\\(00-w-00)/\\_/\\                          \\(*o*)/";
len = strlen(robot);
    t = robot;           /* initialize pointer */
    while(len)
    {
        move(29,1);      /* insert same spot */
        insch(*(t+len-1));  /* work backwards */
        refresh();
        napms(40);         /* .1 sec. delay */
        len--;

}
    int ch;
    ch = getch();
        switch(ch) {
            case 'f':
            case 'F': break;
            case 'c':
            case 'C': clear(); refresh(); control(); break;
            case 27: endwin(); exit(0); 
        }

    clear();
    refresh();
    return;
}   

void center2(int row, char *title)
{   
    int len,indent,y,width;
    getmaxyx(stdscr,y,width);
    len = strlen(title);
    indent = (width - len)/2;
    mvaddstr(row,indent,title);
    refresh();
}

