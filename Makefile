NAME := libftprintf.a
LIBFT_DIR = libft/
LIBFT_EXEC = libft/libft.a
SRCFILES := ft_printf.c \
			ft_itoa_xx.c
CC = gcc
CFLAGS = -Wextra -Werror -Wall
OBJS := $(SRCFILES:.c=.o) 

all: $(NAME)

exec:
	$(CC) -g $(CFLAGS) $(SRCFILES) libft/ft_itoa.c

$(NAME): $(OBJS)
	make -C libft/
	cp libft/libft.a .
	mv libft.a $(NAME)
	ar r $(NAME) $(OBJS)

clean:
	# rm -f *.o
	rm -f $(OBJS)
	make clean -C libft/
fclean:	clean
	rm -f $(NAME)
	make fclean -C libft/
	
re:		fclean all

.PHONY: clean fclean re
