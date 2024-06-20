
NAME = minishell

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SRCS = minishell.c \
       builtins.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

all : $(NAME)


$(NAME) : $(OBJS)
	$(MAKE) --no-print-directory -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lreadline -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean, all

.PHONY: all, clean, fclean, re

.SILENT:
