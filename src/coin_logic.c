#include "header.h"

void coin_logic(void) {
	wattron(game_win, COLOR_PAIR(3));
	int amount = coins.amount;
	for(int i = 0; i < amount; i++) {
			if(student.position.y == coins.position[i][0] && student.position.x == coins.position[i][1]) {
				student.coins_collected++;
				coins.position[i][0] = -1;
			}
			else {
				mvwaddch(game_win, coins.position[i][0], coins.position[i][1], '$' | A_BOLD | A_BLINK);
			}
	}
	wrefresh(game_win);
	wattroff(game_win, COLOR_PAIR(3));
	if(student.coins_collected == coins.amount) {
		status.game = 5;
	}
}

