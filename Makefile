NAME	 =	minishell
SRC		 =	main.c \
			execution/execution.c \
			execution/execution_util.c \
			execution/execution_util_2.c \
			execution/pipe_control.c \
			execution/exec_builtins.c \
			execution/wait_child.c \
			execution/searching_for_cmd.c \
			redirections/redirections.c \
			redirections/redirections_utils.c \
			redirections/heredoc.c \
			minishell_util/mini_util.c \
			minishell_util/mini_utils2.c \
			ft_env/ft_env.c \
			ft_env/ft_env_util.c\
			ft_export/ft_export.c\
			ft_export/affich_export.c \
			ft_export/ft_export_util.c \
			ft_unset/ft_unset.c \
			ft_cd/ft_cd.c \
			ft_cd/ft_cd2.c \
			ft_cd/ft_cd_utils.c\
			ft_pwd/ft_pwd.c \
			ft_echo/ft_echo.c\
			ft_exit/ft_exit.c\
			signal_handlers/signal_handlers.c \
			msg_error/msg_error_export_unset.c \
			msg_error/msg_error_cd.c \
			parsing/parsing.c \
			parsing/line_handling.c \
			parsing/parsing_utils.c \
			parsing/utils1.c \
			parsing/tokenization.c \
			parsing/expend_utils.c \
			parsing/expend.c \
			parsing/syntax_error.c \
			parsing/expend_utils1.c \
			parsing/ft_free.c
OBJ = $(SRC:.c=.o)
RM = rm -rf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
INCLUDE = include/minishell.h include/struct.h

all : $(NAME)

%.o:%.c $(INCLUDE)
	$(CC) $(CFLAGS) -I $(shell brew --prefix readline)/include -c $< -o $@

$(NAME) : $(OBJ)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ) -L $(shell  brew --prefix readline)/lib -o $(NAME) $(LIBFT) -lreadline

clean :
	${MAKE} -C libft clean
	$(RM) $(OBJ)

fclean : clean
	${MAKE} -C libft fclean
	$(RM) $(NAME)
	
re : fclean all
