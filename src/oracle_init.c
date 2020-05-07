#include "header.h"
  
void oracle_init(void) {

        oracle.position.x = 37;
        oracle.position.y = 1;
        oracle.position.vx = +1;
        oracle.position.vy = 0;
        oracle.position.last_vx = 0;
        oracle.position.last_vy = 0;


        oracle.speed = 60000;
}


