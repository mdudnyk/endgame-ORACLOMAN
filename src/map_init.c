#include "header.h"

//function gets size of map & make some checks of map file
void map_init(void) {	
	char map_name[] = "resource/map_1";                //here you can type new map name
	char buff;
	int symbols = 0;                                   //count of symbols in wide for each row
	int newline = 0;
	int temp_symbols = 0;
	int map_in = open(map_name, O_RDONLY);
	if(map_in == -1) {
		mx_printerr("Error! Map does not exist\n");
		map_alt();
		return;
	} 
	while(read(map_in, &buff, 1)) {
		if(buff != '\n') {
                        symbols++;	
                }
		else {
			newline++;
			if (newline == 1) {
				temp_symbols = symbols;
			}
			else {
				if(symbols != temp_symbols) {
					mx_printerr("Map error\nIt is not rectangular\n");
					exit(1);
				}
			}
			symbols = 0;
		}
	}
	close(map_in);
	map.y = newline;                      //put sizes of map into map_size struct
	map.x = temp_symbols;
					      //this part reads file with map and crate 2 arrays  with int and chars
	int map_digit[newline][temp_symbols];
	char map_char[newline][temp_symbols];

	map_in = open(map_name, O_RDONLY);
		int x = 0;
                int y = 0;
	while(read(map_in, &buff, 1)) {
		if(buff != '\n') {
			map_char[y][x] = buff;
 			if(buff == ' ') {
				map_digit[y][x] = -1;
				x++;
			} 
			else {
				if(buff == '#') {
					map_digit[y][x] = -2;
					x++;
				}
				else {
					map_digit[y][x] = -3;
					x++;
				}
			}
		}
		else {
			x = 0;
			y++;
		}
	}
	close(map_in);
	
/*	for(int i = 0; i < newline; i++) {
		for(int j = 0; j < temp_symbols; j++) {
			printf("%d", map_digit[i][j]);
		}
		printf("\n");
	}
*/
	for(int i = 0; i < newline; i++)
                for(int j = 0; j < temp_symbols; j++)
			map.digit[i][j] = map_digit[i][j];      //puts array with digits in structure

	for(int i = 0; i < newline; i++)
                for(int j = 0; j < temp_symbols; j++)
                        map.symbol[i][j] = map_char[i][j];      //puts array with chars in structure
}

