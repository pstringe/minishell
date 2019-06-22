/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:50:10 by pstringe          #+#    #+#             */
/*   Updated: 2019/06/21 22:40:09 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void 	execute(t_shell *s)
{
	int pid;

	if (!(pid = fork()))
		execvp(s->tokens[0], s->tokens + 1);
	else if (pid >= 1)
		wait(&pid);
	else
		ft_putendl("invalid pid");
}

void 	display_prompt(char *prompt)
{
	ft_putstr(prompt);
}

int 	is_builtin(t_shell *s, char *token)
{
	int i;

	i = -1;
	while (++i < BUILTINS)
		if (!ft_strncmp(token, g_builtins[i].name, g_builtins[i].len))
			return (g_builtins[i].cmd(s->tokens, ft_strlen((char*)s->tokens)));
	return (0);
}

void 	evaluate(t_shell *s)
{
	is_builtin(s, s->tokens[0]);
		
	/*
	** we'll worry about that after the dipatch works
	*/
	/*else if (is_path(s))
		execute(s);
	else
		error(s);
		*/
}

void	ft_shell(t_shell *s)
{
	display_prompt(s->prompt);
	get_next_line(0, &(s->input));
	s->tokens = ft_strsplit(s->input, ' ');
	evaluate(s);
}

int 	main(void)
{
	t_shell s;

	ft_shell(&s);
	return (0);
}
