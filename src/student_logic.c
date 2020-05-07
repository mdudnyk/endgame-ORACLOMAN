#include "header.h"

void student_logic() {
	wattron(game_win, COLOR_PAIR(2));
	mvwaddch(game_win, student.position.y, student.position.x, '@' | A_INVIS);
	
	int next_x = student.position.x + student.position.vx;
	int next_y = student.position.y + student.position.vy;
	
	int last_next_x = student.position.last_vx + student.position.x;;
	int last_next_y = student.position.last_vy + student.position.y;;

	if(student.position.x == oracle.position.x && student.position.y == oracle.position.y) {
                status.game = 3;
                student.lives -= 1;
        }
        if(student.position.x == oracle2.position.x && student.position.y == oracle2.position.y) {
                status.game = 3;
                student.lives -= 1;
        }
        if(student.position.x == oracle3.position.x && student.position.y == oracle3.position.y) {
                status.game = 3;
                student.lives -= 1;
        }

	if(map.symbol[next_y][next_x] == '#') {
		if(map.symbol[last_next_y][last_next_x] == '#') {
			student.position.vx = 0;
			student.position.vy = 0;
		}
		if(map.symbol[last_next_y][last_next_x] != '#') {
			student.position.vx = student.position.last_vx;
			student.position.vy = student.position.last_vy;
		}
	}

	student.position.x += student.position.vx;
	student.position.y += student.position.vy;
	
	if(student.position.x == oracle.position.x && student.position.y == oracle.position.y) {
                status.game = 3;
                student.lives -= 1;
        }
        if(student.position.x == oracle2.position.x && student.position.y == oracle2.position.y) {
                status.game = 3;
                student.lives -= 1;
        }
        if(student.position.x == oracle3.position.x && student.position.y == oracle3.position.y) {
                status.game = 3;
                student.lives -= 1;
        }
	
	if(student.lives == 0) {
		status.game = 4;
	}

	student.position.last_vx = 0;
	student.position.last_vy = 0;
	if(status.game != 3) {
		mvwaddch(game_win, student.position.y, student.position.x, '@' | A_BOLD | A_UNDERLINE);
	}
	wrefresh(game_win);
	usleep(student.speed);
	wattroff(game_win, COLOR_PAIR(2));
}
