#include "header.h"

int main() {
	setlocale(LC_ALL, "");	
	srand(time(0));
	map_init();
	student_init();
	oracle_init();
	oracle2_init();
	oracle3_init();
	initscr();
	curs_set(0);
	noecho();

	start_color();
	keypad(game_win, TRUE);
	run();
	init_pair(1, COLOR_GREEN , COLOR_MAGENTA);  //walls of gamefield
	init_pair(2, COLOR_BLUE, COLOR_BLACK);	    //student
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);    //coins
	init_pair(4, COLOR_GREEN, COLOR_BLACK);     //text on gamefield
	init_pair(5, COLOR_RED, COLOR_BLACK);       //oracle
	init_pair(6, COLOR_RED, COLOR_RED);
	attron(COLOR_PAIR(2) | A_BOLD);
	box(stdscr, 0, 0);
	refresh();
	attroff(COLOR_PAIR(2) | A_BOLD);
	print_static_obj();
	print_health();
	coins_init();
	
	nodelay(game_win, TRUE);
	int stop = 0;
	while(stop == 0) {
		dev_info();
		play_input();
		oracle_logic();
		oracle2_logic();
		oracle3_logic();
		student_logic();
		coin_logic();
		switch(student.lives) {
			case(1): attron(COLOR_PAIR(6)); mvprintw(LINES/2 + map.y/2 + 2, (COLS - map.x)/2 + 5, "   "); refresh(); attroff(COLOR_PAIR(6)); attron(COLOR_PAIR(2)); mvprintw(LINES/2 + map.y/2 + 2, (COLS - map.x)/2 + 8, "       "); refresh(); attroff(COLOR_PAIR(2)); break;
			case(2): attron(COLOR_PAIR(6)); mvprintw(LINES/2 + map.y/2 + 2, (COLS - map.x)/2 + 5, "      "); refresh(); attroff(COLOR_PAIR(6)); attron(COLOR_PAIR(2)); mvprintw(LINES/2 + map.y/2 + 2, (COLS - map.x)/2 + 11, "    "); refresh(); attroff(COLOR_PAIR(2));break;
			case(3): attron(COLOR_PAIR(6)); mvprintw(LINES/2 + map.y/2 + 2, (COLS - map.x)/2 + 5, "          "); refresh(); attroff(COLOR_PAIR(6)); break;
		} 

		switch(status.game) {
			case(1): wclear(game_win); student_init(); coins_init(); print_static_obj(); nodelay(game_win, TRUE);  status.game = 0; break;    //if player push restart
			case(2): stop = 1; break;                            //if palyer push exit game
			case(3): student.position.x = 2; student.position.y = 1; student.position.vx = 0; student.position.vy = 0; status.game = 0; break;     //if oracle has cotch the student
			case(4): clear(); refresh(); stop = 1; game_over(); break;
			case(5): clear(); refresh(); stop = 1; win(); break;
			default: break;
		}
	}
	
	delwin(game_win);
	endwin();  
	return 0;
}
