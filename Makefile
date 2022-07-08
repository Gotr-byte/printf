NAME = libftprintf.a
LIBFT_DIR = libft/
SRC_DIR = src/
OBJ_DIR = obj/
#INC_DIR = inc/ 
LIBFT_EXEC = libft.a

# place all source files here
SCR =	$(SRC_DIR)flags.c \
		$(SRC_DIR)ft_itoa_lu.c \
		$(SRC_DIR)ft_putchar.c \
		$(SRC_DIR)hext.c \
		$(SRC_DIR)hexxt.c \
		$(SRC_DIR)print_hex_address.c \
		$(SRC_DIR)ft_printf.c

# takes all named source files and converts them to .o files in the /obj directory
# OBJ = $(SRC:src/%.c = obj/%.o)

# define compiler and flags
CC = gcc
#CFLAGS = -Wall -Werror -Wextra -g -I $(INC_DIR)
CFLAGS = -Wall -Werror -Wextra -g -I
# prevents rules from being considered as files
.PHONY: all clean fclean re

all: $(OBJ_DIR) $(OBJ) $(NAME)

# creates subdirectory /obj
$(OBJ_DIR):
	mkdir obj/
	$(SRC:src/%.c = obj/%.o)
# makes sure to make a /obj dir before compiling .o files
# $(OBJ): |$(OBJ_DIR)

# compiles .c files into .o files and puts them in the /obj folder
$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c OBJ
	ar r -c $< -o $@

# compiles all object files and builds executable file 'pipex'
$(NAME): $(OBJ)
	mkdir $(OBJ_DIR)
	$(MAKE) -C libft
	
	ar rcs $(LIBFT_DIR)$(LIBFT_EXEC) $^ -o $@
#	$(CC) $(CFLAGS) src/*.c PATH_TO_LIBFT/pipex/libft/libft.a -o pipex


# removes all object files and the /obj directory and cleans libft
clean:
	$(MAKE) clean -C libft
	rm -f $(OBJ)
	rmdir $(OBJ_DIR)

# calls 'clean' and removes the executable
fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

# re-makes the whole compilation from scratch
re: fclean all
