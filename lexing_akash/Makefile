
NAME = minishell

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

BUILT = src/builtins/
SRCS =	src/minishell.c \
		src/main.c \
       	$(BUILT)cd.c \
		$(BUILT)pwd.c \
		$(BUILT)echo.c \
		$(BUILT)env.c \
		$(BUILT)export.c \
		$(BUILT)unset.c \
	   	src/exec/command.c \
	   	src/exec/environ.c \
	   	src/exec/init.c \
	   	src/exec/pipex.c \
	   	src/exec/pipex_utils.c \
	   	src/lexing/create_token.c \
	   	src/lexing/token_quoting.c \
	   	src/lexing/tokenizer.c \
	   	src/utils/free.c \
	   	src/utils/utils.c \
	   	src/utils/is_what.c \
	   	src/parsing/here_doc.c \
	   	src/parsing/parsing.c \
	   	src/redirections/redirections.c \
	   	src/word_expansion/create_new_word.c \
	   	src/word_expansion/get_value.c  \
	   	src/word_expansion/var_extension.c \
	   	src/word_expansion/word_expansion.c \
	   	include/get_next_line/get_next_line.c \
	   	include/get_next_line/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

LIBFT = include/libft/libft.a

all : $(NAME)


$(NAME) : $(OBJS)
	$(MAKE) --no-print-directory -C ./include/libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lreadline -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean, all

.PHONY: all, clean, fclean, re

.SILENT:
