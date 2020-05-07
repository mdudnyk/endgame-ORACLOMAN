#include "header.h"

void dev_info(void) {
//	mvprintw(1, 1, "Student actual coordinates: x=%d, y=%d  ", student.position.x, student.position.y);
//	mvprintw(2, 1, "Student actual vector: vx=%d, vy=%d  ", student.position.vx, student.position.vy);
//	mvprintw(3, 1, "Student last vector: last_vx=%d, last_vy=%d  ", student.position.last_vx, student.position.last_vy);
	mvprintw(LINES/2 + map.y/2 + 2, (COLS - map.x)/2 + 30, "Coins collected: %d  ", student.coins_collected);
//	mvprintw(5, 1, "Students lifes: %d  ", student.lives );
//	mvprintw(6, 1, "ORACLE_1 actual coordinates: x=%d, y=%d  ", oracle.position.x, oracle.position.y);
//	mvprintw(7, 1, "ORACLE_2 actual coordinates: x=%d, y=%d  ", oracle2.position.x, oracle2.position.y);
//	mvprintw(8, 1, "ORACLE_3 actual coordinates: x=%d, y=%d  ", oracle3.position.x, oracle3.position.y);


	refresh();  
}
