/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 18:37:22 by pstringe          #+#    #+#             */
/*   Updated: 2019/06/21 22:38:56 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define BUILTINS	1
#include "libft/libft.h"

typedef struct	s_builtin
{
	char	*name;
	int		(*cmd)(char **, int);
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

int cmd_ls(char **argv, int argc);

t_builtin g_builtins[BUILTINS] = {
	{"ls", cmd_ls, 2}
};

