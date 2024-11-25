
NAME = minishell

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

BUILT = src/builtins/
	   	
SRCS =	src/utils/free.c \
		src/main/exec_line.c \
		src/main/minishell.c \
		src/main/main.c \
		src/main/parsing_extended.c \
		src/main/check_builtins.c \
       	$(BUILT)cd.c \
		$(BUILT)pwd.c \
		$(BUILT)echo.c \
		$(BUILT)env.c \
		$(BUILT)export.c \
		$(BUILT)export_bis.c \
		$(BUILT)export_fork.c \
		$(BUILT)unset.c \
		$(BUILT)exit.c \
	   	src/exec/command.c \
	   	src/exec/environ.c \
	   	src/exec/init.c \
	   	src/exec/pipex.c \
	   	src/exec/pipex_utils.c \
		src/exec/pipex_utils2.c \
	   	src/lexing/create_token.c \
	   	src/lexing/token_quoting.c \
	   	src/lexing/tokenizer.c \
	   	src/utils/utils.c \
	   	src/utils/is_what.c \
	   	src/parsing/here_doc.c \
		src/parsing/here_doc_2.c \
	   	src/parsing/parsing.c \
		src/parsing/print_error.c \
	   	src/redirections/redirections.c \
	   	src/word_expansion/create_new_word.c \
	   	src/word_expansion/get_value.c  \
	   	src/word_expansion/var_extension.c \
	   	src/word_expansion/word_expansion.c \
		src/word_expansion/my_getenv.c \
		src/word_expansion/quote_gone.c \
		src/signals/signal.c \
		src/signals/signals_handlers.c \
	   	include/get_next_line/get_next_line.c \
	   	include/get_next_line/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

LIBFT = include/libft/libft.a

all : $(NAME)


$(NAME) : $(OBJS)
	$(MAKE) --no-print-directory -C ./include/libft
	$(CC) -fPIE $(CFLAGS) $(OBJS) $(LIBFT) -lreadline -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean  all

.PHONY: all, clean, fclean, re

#  .SILENT:
