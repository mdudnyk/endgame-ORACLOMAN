#include "header.h"

int rand_value(int min, int max) {
  	return rand() % ((max - min) - 1) + min;
}
