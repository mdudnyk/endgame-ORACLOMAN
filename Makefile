NAME = endgame

INC = inc/header.h
INCOBJ = header.h
SRC = src/*.c
SRC_ADD = src/add/*.c

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -lncurses

all: install clean
install:
	@cp $(INC) .
	@cp $(SRC) .	
	@cp $(SRC_ADD) .
	@clang $(CFLAGS) -o $(NAME) *.c
uninstall: clean
	@rm -rf $(NAME)
clean:
	@rm -rf $(INCOBJ)
	@rm -rf *.c
reinstall: uninstall install
	@rm -rf $(INCOBJ)
	@rm -rf *.c

