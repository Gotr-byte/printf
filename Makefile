NAME := libftprintf.a
LIBFT_DIR = libft/
LIBFT_EXEC = libft/libft.a
SRCFILES := ft_itoa_lu.c \
		ft_itoa_x.c \
		ft_itoa_xx.c \
		ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		print_hex_address.c \
		prt_par_lu.c \
		prt_par_per.c \
		prt_par_x.c \
		prt_par_xx.c

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
