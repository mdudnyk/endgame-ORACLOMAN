#ifndef HEADER
#define HEADER

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>

WINDOW *game_win;
WINDOW *health_win;

struct map_for_game {
	int digit[20][60];
	char symbol[20][60];
	int x;
	int y;
} map;

struct game_status {
	int game;
} status;

struct coord {
	int x;
	int y;
	int vx;
	int vy;
	int last_vx;
	int last_vy;
};

struct student_data {
	struct coord position;
	int speed;
	int coins_collected;
	int lives;
} student; 

struct oracle1_data {
        struct coord position;
        int speed;
} oracle;
struct oracle2_data {
        struct coord position;
        int speed;
} oracle2;
struct oracle3_data {
        struct coord position;
        int speed;
} oracle3;

struct coins_data {
	int amount;
	int position[10][2];
} coins;
void print_health(void);
void control(void);
void run(void);
void win(void);
void game_over(void);
void oracle2_logic(void);
void oracle2_init(void);
void oracle3_logic(void);
void oracle3_init(void);
void coins_init(void);
void coin_logic(void);
int rand_value(int min, int max);
void student_init(void);
void oracle_init(void);
void play_input(void);
void student_logic(void);
void oracle_logic(void);
void print_static_obj(void);
void mx_printerr(const char *s);
void map_init(void);
void map_alt(void);
void dev_info(void);
#endif
