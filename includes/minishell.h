/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 18:37:22 by pstringe          #+#    #+#             */
/*   Updated: 2019/06/24 22:15:14 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define BUILTINS	3
#include "../srcs/builtins/ls/ft_ls.h"
#include "libft/libft.h"

typedef struct	s_builtin
{
	char	*name;
	char	*description;
	int		(*cmd)(char **);
	int		len;
}				t_builtin;

typedef struct	s_shell
{
	char *prompt;
	char **tokens;
	char *input;	
}				t_shell;

/*
**	builtins
*/

int cmd_cd(char **args);
int	cmd_exit(char **args);
int cmd_help(char **args);

t_builtin g_builtins[BUILTINS] = {
	{"cd", "change directory", cmd_cd, 2},
	{"exit", "exit proccess", cmd_exit, 4},
	{"help", "show built-in commands", cmd_help, 4}
};

