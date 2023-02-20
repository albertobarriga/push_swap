SRCS = main.c \
	   ft_check_arg.c \
	   atol.c \
	   ft_error.c \
	   utils.c \
	   moves.c \
	   moves2.c \
	   target.c \
	   cost.c \
	   order.c \
	   orderall.c 

SRCS_CHECKER =	checker.c \
				moves_checker.c \
				ft_check_arg.c \
				atol.c \
				ft_error.c \
				utils.c \
				moves.c \
				moves2.c \
				target.c \
				cost.c \
				order.c \
				orderall.c
	   

OBJ =  ${SRCS:.c=.o}

OBJ_CHECKER =  ${SRCS_CHECKER:.c=.o}

AR = ar -crs

LIB_DIR = libft/

LIB = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = 	rm -f

NAME = push_swap

CHECKER = checker

all: $(NAME) $(CHECKER)

$(NAME): $(OBJ)
	make -C $(LIB_DIR)
	cp $(LIB_DIR)$(LIB) .
	$(CC) -o $(NAME) $(OBJ) $(LIB)
	
$(CHECKER): $(OBJ)
	$(CC) -o $(CHECKER) $(OBJ_CHECKER) $(LIB)

clean:
	$(RM) ${OBJ}
	@make clean -C $(LIB_DIR)
fclean:	clean
	${RM} ${NAME}
	${RM} ${CHECKER}
	$(RM) $(LIB)
	$(RM) $(LIB_DIR)$(LIB)

re:	fclean all