NAME = libftprintf.a
SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = inc/
LIBFT_DIR = libft/
LIBFT_EXEC = libft.a
SCR = $(SRC_DIR) main.c \
	$(SRC_DIR)helpers.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I $(INC_DIR)
.PHONY = all clean fclean re
all: $(NAME)
$(OBJ_DIR):
	@mkdir $@
$(OBJ): |$(OBJ_DIR)
$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(FLAGS) $(LIBFT_DIR) $(LIBFT_EXEC) -c $ˆ -o $@
$(NAME): $(OBJ)
	$(MAKE) -c libft
	$(CC) $(CFLAGS) $(LIBFT_DIR) $(LIBFT_EXEC) -c $ˆ -o $@
clean:
	$(MAKE) clean -c libft
	rm -f $(OBJ)
	rm -f $(OBJ)
	rmdir $(OBJ_DIR)
fclean: clean
	$(MAKE) fclean -c libft
	rm -f $(NAME)
re: fclean all