
NAME = minishell

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SRCS = minishell.c \
       builtins.c \
	   pipex.c \
	   init.c \
	   utils.c \
	   lexing_akash/src/lexing/create_token.c \
	   lexing_akash/src/lexing/token_quoting.c \
	   lexing_akash/src/lexing/tokenizer.c \
	   lexing_akash/src/utils/free.c \
	   lexing_akash/src/utils/utils.c \
	   lexing_akash/src/main.c \

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
