#include "header.h"

void oracle_logic() {
	wattron(game_win, COLOR_PAIR(5));
        mvwaddch(game_win, oracle.position.y, oracle.position.x, 'O' | A_INVIS);
	
	//oracle.position.vx = 0;
	//oracle.position.vy = 0;

	int ran = rand_value(1, 6);
        if(ran == 1) {
		if(oracle.position.last_vx != -1) {
        		oracle.position.vx = +1;
        		oracle.position.vy = 0;
		}
        }
        else if(ran == 2) {
		if(oracle.position.last_vx != +1) {
        		oracle.position.vx = -1;
        		oracle.position.vy = 0;
		}
        }
        else if(ran == 3) {
		if(oracle.position.last_vy != -1) {
        		oracle.position.vx = 0;
        		oracle.position.vy = +1;
		}
        }
        else if(ran == 4) {
		if(oracle.position.last_vy != +1) {
        		oracle.position.vx = 0;
        		oracle.position.vy = -1;
		}
        }


	int next_x = oracle.position.x + oracle.position.vx;
	int next_y = oracle.position.y + oracle.position.vy;

	int last_next_x = oracle.position.last_vx + oracle.position.x;;
        int last_next_y = oracle.position.last_vy + oracle.position.y;;

	if(map.symbol[next_y][next_x] == '#') {
                if(map.symbol[last_next_y][last_next_x] == '#') {
                        oracle.position.vx = 0;
                        oracle.position.vy = 0;
                }
                if(map.symbol[last_next_y][last_next_x] != '#') {
                        oracle.position.vx = oracle.position.last_vx;
                        oracle.position.vy = oracle.position.last_vy;
               }
        }

	//if(map.symbol[next_x][next_y] == '#') {
	//	if(map.symbol[last_next_y][last_next_x] == '#') {
	//		
	//	int ran = rand_value(1, 4);
	//	if(ran == 1) { 
        //	       	oracle.position.vx = +1;
        //       	oracle.position.vy = 0;
        //	}
        //	else if(ran == 2) {
        //       	oracle.position.vx = -1;
        //       	oracle.position.vy = 0;
        //	}
        //	else if(ran == 3) {
        //       	oracle.position.vx = 0;
        //       	oracle.position.vy = +1;
        //	}
        //	else if(ran == 4) {
        //       	oracle.position.vx = 0;
        //       	oracle.position.vy = -1;
        //	}
	//
	//	}
	//	if(map.symbol[last_next_y][last_next_x] != '#') {
	//		oracle.position.vx = oracle.position.last_vx;
	//		oracle.position.vy = oracle.position.last_vy;
	//	}
	//}
	
	oracle.position.x += oracle.position.vx;
	oracle.position.y += oracle.position.vy;
	
	oracle.position.last_vx = oracle.position.vx;
	oracle.position.last_vy = oracle.position.vy;
	
	mvwaddch(game_win, oracle.position.y, oracle.position.x, 'O' | A_BOLD);
        wrefresh(game_win);
//        usleep(student.speed);
        wattroff(game_win, COLOR_PAIR(2));
}
