#include "header.h"
  
void oracle2_logic() {
        wattron(game_win, COLOR_PAIR(5));
        mvwaddch(game_win, oracle2.position.y, oracle2.position.x, 'O' | A_INVIS);

        //oracle.position.vx = 0;
        //oracle.position.vy = 0;

        int ran = rand_value(1, 6);
        if(ran == 1) {
                if(oracle2.position.last_vx != -1) {
                        oracle2.position.vx = +1;
                        oracle2.position.vy = 0;
                }
        }
        else if(ran == 2) {
                if(oracle2.position.last_vx != +1) {
                        oracle2.position.vx = -1;
                        oracle2.position.vy = 0;
                }
        }
        else if(ran == 3) {
                if(oracle2.position.last_vy != -1) {
                        oracle2.position.vx = 0;
                        oracle2.position.vy = +1;
                }
        }
        else if(ran == 4) {
                if(oracle2.position.last_vy != +1) {
                        oracle2.position.vx = 0;
                        oracle2.position.vy = -1;
                }
        }


        int next_x = oracle2.position.x + oracle2.position.vx;
        int next_y = oracle2.position.y + oracle2.position.vy;

        int last_next_x = oracle2.position.last_vx + oracle2.position.x;;
        int last_next_y = oracle2.position.last_vy + oracle2.position.y;;

        if(map.symbol[next_y][next_x] == '#') {
                if(map.symbol[last_next_y][last_next_x] == '#') {
                        oracle2.position.vx = 0;
                        oracle2.position.vy = 0;
                }
                if(map.symbol[last_next_y][last_next_x] != '#') {
                        oracle2.position.vx = oracle2.position.last_vx;
                        oracle2.position.vy = oracle2.position.last_vy;
               }
        }
   
        oracle2.position.x += oracle2.position.vx;
        oracle2.position.y += oracle2.position.vy;
        
        oracle2.position.last_vx = oracle2.position.vx;
        oracle2.position.last_vy = oracle2.position.vy;
        
        mvwaddch(game_win, oracle2.position.y, oracle2.position.x, 'O' | A_BOLD);
        wrefresh(game_win);
        //usleep(student.speed);
        wattroff(game_win, COLOR_PAIR(5));
} 
