# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pstringe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/02 14:49:53 by pstringe          #+#    #+#              #
#    Updated: 2019/06/21 22:25:37 by pstringe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = minishell
INCD = ./includes/
LIB = libft.a
INCD = ./includes/
SRCD = ./srcs/
LIBD = $(INCD)libft/
SRCS = minishell\

OBJS = $(patsubst $(SRCD)%, %.o, $(SRCS))
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -g
SFLAGS = -fsanitize=address -fno-omit-frame-pointer

all: $(NAME)

$(NAME): $(INCD)$(LIB)
	$(CC) $(CFLAGS) -o $(NAME) ./srcs/builtins/ls/ft_ls.o $(patsubst %, $(SRCD)%.c, $(SRCS)) -L$(LIBD) -lft -I $(INCD) 
debug: fclean $(INCD)$(LIB)
	$(CC) $(CFLAGS) $(DFLAGS) -o $(NAME) $(patsubst %, $(SRCD)%.c, $(SRCS)) -L$(LIBD) -lft -I $(INCD)
sanitize: fclean $(INCD)$(LIB)
	$(CC) $(CFLAGS) $(SFLAGS) -o $(NAME) $(patsubst %, $(SRCD)%.c, $(SRCS)) -L$(LIBD) -lft -I $(INCD)
$(INCD)$(LIB):
	make -C $(INCD)libft
clean:
	make -C $(INCD)libft clean
	rm -rf *.o
	rm -rf *.dSYM
fclean: clean
	make -C $(INCD)libft fclean
	rm -rf $(NAME)
re: fclean
	make

