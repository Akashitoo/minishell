NAME = minishell

CC = cc
LIB_PATH = include/libft/
LIB_NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRC_PATH = src/
INC_PATH = include/
SRC = $(SRC_PATH)*/*.c $(INC_PATH)get_next_line/*.c $(SRC_PATH)main.c

all : $(NAME)

$(NAME) : $(SRC) $(LIB_PATH)$(LIB_NAME)
	$(CC) $(FLAGS) $(SRC) $(LIB_PATH)$(LIB_NAME) -o $(NAME)

$(LIB_PATH)$(LIB_NAME) :
	@make --silent -C $(LIB_PATH)
fclean :
	rm -rf $(NAME)
	@make --silent fclean -C $(LIB_PATH)
clean :
	rm -rf $(NAME)
re : fclean all

.PHONY: all re clean fclean