/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_run_mid_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 20:00:00 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/27 05:08:55 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_mid_cmd(t_pipex *pipex, char **env, int i)
{
	pipex->child[i] = fork();
	if (pipex->child[i] < 0)
	{
		free_pipex(pipex);
		pipex_error();
	}
	else if (pipex->child[i] == 0)
	{
		close(pipex->pipe[i][0]);
		dup2(pipex->pipe[i - 1][0], STDIN_FILENO);
		dup2(pipex->pipe[i][1], STDOUT_FILENO);
		close(pipex->pipe[i - 1][0]);
		close(pipex->pipe[i][1]);
		execve(pipex->cmds[i], pipex->args[i], env);
		free_pipex(pipex);
		pipex_error();
	}
	else
	{
		close(pipex->pipe[i - 1][0]);
		close(pipex->pipe[i][1]);
	}
}
