NAME := libftprintf.a
LIBFT_DIR = libft/
LIBFT_EXEC = libft/libft.a
SRCFILES := ft_printf.c \
			ft_itoa_xx.c \
			ft_itoa_x.c \
			ft_itoa_lu.c \
			ft_putstr_i.c \
			adr_hex.c \
			ft_putchar_i.c \
			flag.c
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
