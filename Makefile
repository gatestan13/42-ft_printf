CC 			= 	gcc
FLAGS 		= 	-Wall -Wextra -Werror
NAME 		= 	libftprintf.a
OPTION 		= 	-c
SRC 		= 	ft_printf.c \
				set_flags.c \
				is_x.c \
				process_char.c \
				process_types.c \
				process_width.c \
				process_str.c \
				process_point.c \
				process_int.c \
				process_uint.c \
				process_hex.c \
				process_percent.c \
				util_functions.c \
				util_functions2.c \
				util_functions3.c 
OBJ 		= 	$(SRC:.c=.o)
LIBFTDIR	= 	libft
LIBFT		=	libft.a

all: $(NAME) 

$(NAME):
	make bonus -C $(LIBFTDIR)/
	$(CC) $(FLAGS) $(OPTION) $(SRC)
	cp $(LIBFTDIR)/$(LIBFT) $(NAME)
	ar rcu $(NAME) $(OBJ)
	make clean

clean:
	make clean -C $(LIBFTDIR)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LIBFTDIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus