#include "header.h"

void print_health(void) {
        const int width = map.x;
        const int height = map.y;
        int offsetx = (COLS - width) / 2 + 3;
        int offsety = LINES / 2 + height / 2 + 1 ;
        health_win = newwin(3, 14, offsety, offsetx);
	wattron(health_win, COLOR_PAIR(2) | A_BOLD);
     	box(health_win, 0 ,0);
	mvwprintw(health_win, 2, 2, "health bar"); 
        wrefresh(health_win);
	wattroff(health_win, COLOR_PAIR(2) | A_BOLD);
        return;
}

