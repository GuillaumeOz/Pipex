/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc_parse_cmd_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:49:10 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/27 05:44:37 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	find_path_line(char **env)
{
	char	*reader;
	char	buff[5];
	int		i;

	i = 0;
	ft_memset(buff, 0, sizeof(char) * 5);
	while (env[i] != NULL)
	{
		if (ft_strlen(env[i]) > 4)
		{
			reader = ft_strncpy(buff, env[i], 4);
			if (ft_strcmp(reader, "PATH") == true)
				break ;
		}
		i++;
	}
	if (env[i] == NULL)
		pipex_error();
	return (i);
}

static void	parse_env(t_pipex *pipex, char **env)
{
	int	index;
	int	i;

	i = 0;
	index = find_path_line(env);
	pipex->env = ft_split(&(env[index][5]), ':');
	while (pipex->env[i] != NULL)
	{
		pipex->env[i] = ft_strappend(pipex->env[i], "/", true, false);
		i++;
	}
	pipex->path_nb = i;
}

static void	parse_args_tab(t_pipex *pipex, int argc, char **argv)
{
	int	len;
	int	i;
	int	j;

	j = 0;
	i = 3;
	len = argc - 4;
	pipex->args = (char ***)malloc(sizeof(char **) * (len + 1));
	if (pipex->args == NULL)
		pipex_error();
	pipex->args[len] = NULL;
	while (j < len)
	{
		pipex->args[j] = ft_split(argv[i], ' ');
		if (pipex->args[j] == NULL)
			pipex_error();
		i++;
		j++;
	}
	pipex->cmd_nb = j;
	pipex->pipe_nb = j - 1;
}

void	here_doc_parse_cmd_bonus(t_pipex *pipex, int argc,
	char **argv, char **env)
{
	parse_env(pipex, env);
	parse_args_tab(pipex, argc, argv);
}
