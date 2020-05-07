#include "header.h"

void play_input() {
	int key = wgetch(game_win);
        if (key != ERR) {
		student.position.last_vy = student.position.vy;
		student.position.last_vx = student.position.vx;
        	student.position.vx = 0;
        	student.position.vy = 0;
         	switch (key) {
			case KEY_UP:
            		case 'w':
			case 'W': student.position.vy = -1; student.speed = 110000; break;    // cursor up
            		case KEY_DOWN:
			case 's':
			case 'S': student.position.vy = +1; student.speed = 110000; break;    // cursor down
            		case KEY_LEFT:
			case 'a':
			case 'A': student.position.vx = -1; student.speed = 60000; break;     // cursor left
            		case KEY_RIGHT:
			case 'd':
			case 'D': student.position.vx = +1; student.speed = 60000; break;     // cursor right           
			case 'r':
                        case 'R': status.game = 1; break;
                        case 27: status.game = 2; break;
			default: break;
         	}
     	}
}     
