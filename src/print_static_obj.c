#include "header.h"

void print_static_obj(void) {
	const int width = map.x;
	const int height = map.y;   	
	int offsetx = (COLS - width) / 2;
	int offsety = (LINES - height) / 2;
	game_win = newwin(height, width, offsety, offsetx);   
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			switch(map.symbol[i][j]) {
				case '#': mvwaddch(game_win, i, j, ACS_DIAMOND | A_ALTCHARSET | COLOR_PAIR(1) | A_BOLD); break;
				case ' ': break;
				default: mvwaddch(game_win, i, j, map.symbol[i][j] | COLOR_PAIR(4) | A_BOLD); break;
			}
		}
	}
	wrefresh(game_win);
	return;
}
