/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:50:10 by pstringe          #+#    #+#             */
/*   Updated: 2019/06/24 22:29:13 by pstringe         ###   ########.fr       */
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
			return (g_builtins[i].cmd(s->tokens));
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


int		cmd_cd(char **args)
{
	if (args[1] == NULL)
	{
		ft_dprintf(2, "ftsh: expected argument");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("ftsh");
		}
	}
	return (1);
}

int 	cmd_help(char **args)
{
	int i;

	(void)args;

	ft_putendl("Poitier's Minishell");
	ft_putendl("Type cmd followed by program arguments, press enter.");
	ft_putendl("The following commands are available:");
	
	i = -1;
	while (++i < BUILTINS)
		ft_printf("\t%s: %s\n", g_builtins[i].name, g_builtins[i].description);

	ft_putendl("Use man command for more information.");
	return (1);
}

int		ft_sh_launch(char **args)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
			perror("failed exec");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("lsh");
	}
	else
	{
		wpid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}

int		cmd_exit(char **args)
{
	(void)args;
	return (0);
}

int		ft_sh_exec(char **args)
{
	int i;

	if (args[0] == NULL)
		return (1);
	i = -1;
	while (++i < BUILTINS)
		if (!ft_strcmp(args[0], g_builtins[i].name))
			return (g_builtins[i].cmd(args));
	return (ft_sh_launch(args));
}

void	ft_sh(void)
{
	/*
	display_prompt(s->prompt);
	get_next_line(0, &(s->input));
	s->tokens = ft_strsplit(s->input, ' ');
	evaluate(s);
	*/
	char	*line;
	char	**args;
	int		status;

	line = NULL;
	args = NULL;
	status = 1;
	while (status)
	{
		ft_printf("$> ");
		if (get_next_line(0, &line) >= 0)
			args = ft_strsplit(line, ' ');
		if (args)
			status = ft_sh_exec(args);
		free(line);
		ft_memdel((void**)&args);
	}
}

int 	main(void)
{
	/*
	t_shell s;
	*/

	ft_sh();
	return (0);
	
}
