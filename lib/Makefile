##
## EPITECH PROJECT, 2022
## CPool_10
## File description:
## Makefile
##

SRC	=	my_compute_power_rec.c		\
		my_compute_square_root.c	\
		my_find_prime_sup.c 		\
		my_getnbr.c 				\
		my_is_prime.c				\
		my_isneg.c 					\
		my_put_nbr.c 				\
		my_putchar.c 				\
		my_putstr.c 				\
		my_revstr.c 				\
		my_showstr.c 				\
		my_sort_int_array.c 		\
		my_str_isalpha.c 			\
		my_str_islower.c			\
		my_str_isnum.c 				\
		my_str_isprintable.c 		\
		my_str_isupper.c 			\
		my_str_to_array.c 			\
		my_strcapitalize.c 			\
		my_strcat.c 				\
		my_strcmp.c 				\
		my_strcpy.c 				\
		my_strdup.c 				\
		my_strlen.c 				\
		my_strlowcase.c 			\
		my_strncat.c 				\
		my_strncmp.c 				\
		my_strncpy.c 				\
		my_strstr.c 				\
		my_strupcase.c 				\
		my_swap.c 					\
		my_strdup_from.c 			\
		my_int_len.c 				\
		my_nbrlen.c 				\
		my_int_to_str.c 			\
		open_file.c 				\
		my_arr_len.c 				\

PRINTF_SRC = 	my_printf/my_printf.c 			\
				my_printf/get_flags.c 			\
				my_printf/create_arg.c 			\
				my_printf/fl_b.c 				\
				my_printf/fl_c.c 				\
				my_printf/fl_d.c 				\
				my_printf/fl_f.c 				\
				my_printf/fl_n.c 				\
				my_printf/fl_o.c 				\
				my_printf/fl_p.c 				\
				my_printf/fl_prc.c 				\
				my_printf/fl_s.c 				\
				my_printf/fl_ss.c 				\
				my_printf/fl_u.c 				\
				my_printf/fl_x.c 				\
				my_printf/fl_xx.c

OBJ	=	$(SRC:.c=.o)

PRINTF_OBJ = $(PRINTF_SRC:.c=.o)

CFLAGS = -w -Wall -Wextra -Werror -I .

NAME	=	libmy.a

all: 	$(NAME)

$(NAME):	$(OBJ) $(PRINTF_OBJ)
	ar rc $(NAME) $(OBJ) $(PRINTF_OBJ)
	cp my.h ../include/

clean:
	rm -f $(OBJ) $(PRINTF_OBJ)
	rm -f *~

fclean:	clean
	rm -f $(NAME)
	rm -f ../include/my.h

re:	fclean all
	make clean
