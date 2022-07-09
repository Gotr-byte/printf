NAME := libftprintf.a
LIBFT_DIR = libft/
LIBFT_EXEC = libft/libft.a
SRCFILES := $(SRC_DIR)ft_itoa_lu.c \
		$(SRC_DIR)ft_itoa_x.c \
		$(SRC_DIR)ft_itoa_xx.c \
		$(SRC_DIR)ft_printf.c \
		$(SRC_DIR)ft_putchar.c \
		$(SRC_DIR)ft_putstr.c \
		$(SRC_DIR)print_hex_address.c \
		$(SRC_DIR)prt_par_lu.c \
		$(SRC_DIR)prt_par_per.c \
		$(SRC_DIR)prt_par_x.c \
		$(SRC_DIR)prt_par_xx.c

CC = gcc
CFLAGS = -Wextra -Werror -Wall

OBJS := $(SRCFILES:.c=.o) 

all: lib $(NAME)

$(NAME): $(OBJS) lib
	@ar r $(NAME) libft/libft.a $(OBJS)

lib: force
	make -C libft/

force: ;

clean:
	# rm -f *.o
	rm -f $(OBJS)
	make clean -C libft
fclean:	clean
	rm -f $(NAME)
	make fclean -C libft
	
re:		fclean all

.PHONY: clean fclean re
