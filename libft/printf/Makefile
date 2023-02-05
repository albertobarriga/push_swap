SRCS = ft_printf.c ft_putchar.c ft_puthexa.c ft_putnbr.c ft_putnbr_uns.c ft_putstr.c ft_strlen.c ft_puthexap.c
		
OBJ =  ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = 	rm -f

NAME = libftprintf.a

HEAD = ft_printf.h

%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar crs ${NAME} ${OBJ}
	
all: $(NAME)

clean:
	$(RM) ${OBJ}
fclean:	clean
	${RM} ${NAME}
	${RM} a.out

re:	fclean all

.PHONY: all, clean, fclean, re
