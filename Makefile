SRCS = main2.c \
	   ft_check_arg.c \
	   atoi.c

OBJ =  ${SRCS:.c=.o}

AR = ar -crs

LIB_DIR = libft/

LIB = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = 	rm -f

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_DIR)
	cp $(LIB_DIR)$(LIB) .
	$(CC) -o $(NAME) $(OBJ) $(LIB)
	

clean:
	$(RM) ${OBJ}
	@make clean -C $(LIB_DIR)
fclean:	clean
	${RM} ${NAME}
	$(RM) $(LIB)
	$(RM) $(LIB_DIR)$(LIB)

re:	fclean all