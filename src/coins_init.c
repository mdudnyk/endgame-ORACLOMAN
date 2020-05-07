#include "header.h"

void coins_init(void) {
	int i = 0;
	int y_rand;
	int x_rand;
	coins.amount = 10;                //here you can define amount of coins to appear on the game field (max 10);
	while(i < coins.amount) {
		y_rand = rand_value(1, map.y - 1);
		x_rand = rand_value(1, map.x - 1);
		if(map.symbol[y_rand][x_rand] == ' ') {
			coins.position[i][0] = y_rand;
			coins.position[i][1] = x_rand;	
			i++;
                }
	}
}
