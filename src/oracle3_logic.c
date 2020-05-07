#include "header.h"
  
void oracle3_logic() {
        wattron(game_win, COLOR_PAIR(5));
        mvwaddch(game_win, oracle3.position.y, oracle3.position.x, 'O' | A_INVIS);

        //oracle.position.vx = 0;
        //oracle.position.vy = 0;

        int ran = rand_value(1, 6);
        if(ran == 1) {
                if(oracle3.position.last_vx != -1) {
                        oracle3.position.vx = +1;
                        oracle3.position.vy = 0;
                }
        }
        else if(ran == 2) {
                if(oracle3.position.last_vx != +1) {
                        oracle3.position.vx = -1;
                        oracle3.position.vy = 0;
                }
        }
        else if(ran == 3) {
                if(oracle3.position.last_vy != -1) {
                        oracle3.position.vx = 0;
                        oracle3.position.vy = +1;
                }
        }
        else if(ran == 4) {
                if(oracle3.position.last_vy != +1) {
                        oracle3.position.vx = 0;
                        oracle3.position.vy = -1;
                }
        }


        int next_x = oracle3.position.x + oracle3.position.vx;
        int next_y = oracle3.position.y + oracle3.position.vy;

        int last_next_x = oracle3.position.last_vx + oracle3.position.x;;
        int last_next_y = oracle3.position.last_vy + oracle3.position.y;;

        if(map.symbol[next_y][next_x] == '#') {
                if(map.symbol[last_next_y][last_next_x] == '#') {
                        oracle3.position.vx = 0;
                        oracle3.position.vy = 0;
                }
                if(map.symbol[last_next_y][last_next_x] != '#') {
                        oracle3.position.vx = oracle3.position.last_vx;
                        oracle3.position.vy = oracle3.position.last_vy;
               }
        }
        
        oracle3.position.x += oracle3.position.vx;
        oracle3.position.y += oracle3.position.vy;
        
        oracle3.position.last_vx = oracle3.position.vx;
        oracle3.position.last_vy = oracle3.position.vy;
        
        mvwaddch(game_win, oracle3.position.y, oracle3.position.x, 'O' | A_BOLD);
        wrefresh(game_win);
        //usleep(student.speed);
        wattroff(game_win, COLOR_PAIR(5));
} 
