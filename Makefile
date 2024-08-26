
NAME = minishell

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SRCS = minishell.c \
       builtins.c \
	   pipex.c \
	   init.c \
	   utils.c \
	   command.c \
	   environ.c \
	   lexing_akash/src/lexing/create_token.c \
	   lexing_akash/src/lexing/token_quoting.c \
	   lexing_akash/src/lexing/tokenizer.c \
	   lexing_akash/src/utils/free.c \
	   lexing_akash/src/utils/utils.c \
	   lexing_akash/src/utils/is_what.c \
	   lexing_akash/src/main.c \
	   lexing_akash/src/parsing/here_doc.c \
	   lexing_akash/src/parsing/parsing.c \
	   lexing_akash/src/redirections/redirections.c \
	   lexing_akash/src/word_expansion/create_new_word.c \
	   lexing_akash/src/word_expansion/get_value.c  \
	   lexing_akash/src/word_expansion/var_extension.c \
	   lexing_akash/src/word_expansion/word_expansion.c \
	   lexing_akash/include/get_next_line/get_next_line.c \
	   lexing_akash/include/get_next_line/get_next_line_utils.c \


OBJS = $(SRCS:.c=.o)

LIBFT = lexing_akash/include/libft/libft.a

all : $(NAME)


$(NAME) : $(OBJS)
	$(MAKE) --no-print-directory -C ./lexing_akash/include/libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lreadline -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean, all

.PHONY: all, clean, fclean, re

.SILENT:
