#include "header.h"

void student_init(void) {
	
	student.position.x = 2;
	student.position.y = 1;
	student.position.vx = 0;
	student.position.vy = 0;
	student.position.last_vx = 0;
        student.position.last_vy = 0;


	student.speed = 60000;
	student.coins_collected = 0;
	student.lives = 3;
}

