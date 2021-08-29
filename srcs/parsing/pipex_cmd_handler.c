/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:37:36 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/27 05:45:15 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_cmds(t_pipex *pipex)
{
	int	i;

	pipex->cmds = (char **)malloc(sizeof(char *) * (pipex->cmd_nb + 1));
	if (pipex->cmds == NULL)
		pipex_error();
	pipex->cmds[pipex->cmd_nb] = NULL;
	i = 0;
	while (i < pipex->cmd_nb)
	{
		pipex->cmds[i] = NULL;
		i++;
	}
}

static void	build_cmd(t_pipex *pipex, int i)
{
	int	ret;
	int	j;

	j = 0;
	while (j < pipex->path_nb)
	{
		pipex->cmds[i] = ft_strappend(pipex->env[j],
				pipex->args[i][0], false, false);
		ret = access(pipex->cmds[i], F_OK | X_OK);
		if (ret == 0)
			break ;
		else
		{
			free(pipex->cmds[i]);
			pipex->cmds[i] = NULL;
		}
		j++;
	}
}

void	cmd_handler(t_pipex *pipex)
{
	int	i;

	i = 0;
	init_cmds(pipex);
	while (i < pipex->cmd_nb)
	{
		build_cmd(pipex, i);
		if (pipex->cmds[i] == NULL)
			pipex_error();
		i++;
	}
}
