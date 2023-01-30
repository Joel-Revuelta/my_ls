##
## EPITECH PROJECT, 2022
## CPool_10
## File description:
## Makefile
##

SRC	= 	src/main.c 		\
		src/my_ls.c 	\
		src/get_args.c 	\
		src/print_dir.c	\
		src/l_lists.c

NAME = my_ls

CC = gcc

CFLAGS = -g3 -w -Wall -Wextra -Werror -I include/ -L lib/ -lmy

TESTS = tests/printf_tests.c

T_NAME = unit_tests

T_FLAGS = -w -Wall -Wextra -Werror -I include/ -L ./ -lmy --coverage -lcriterion

all: 	$(NAME)

$(NAME): dolib $(OBJ)
	$(CC) -o $(NAME) $(SRC) $(CFLAGS)

dolib:
	cd lib; make

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f *.gcda
	rm -f *.gcno
	cd lib; make clean

fclean:	clean
	rm -f $(NAME)
	rm -f $(T_NAME)
	cd lib; make fclean

re:	fclean all
	make clean

unit_tests: fclean all
	gcc -o $(T_NAME) $(TESTS) $(T_FLAGS)

run_tests: unit_tests
	./$(T_NAME)
