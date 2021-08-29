/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_run_last_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:23:08 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/27 05:08:52 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_last_cmd(t_pipex *pipex, char **env)
{
	pipex->child[pipex->cmd_nb - 1] = fork();
	if (pipex->child[pipex->cmd_nb - 1] < 0)
	{
		free_pipex(pipex);
		pipex_error();
	}
	else if (pipex->child[pipex->cmd_nb - 1] == 0)
	{
		close(pipex->pipe[pipex->pipe_nb - 1][1]);
		dup2(pipex->pipe[pipex->pipe_nb - 1][0], STDIN_FILENO);
		dup2(pipex->fd_file2, STDOUT_FILENO);
		close(pipex->pipe[pipex->pipe_nb - 1][0]);
		close(pipex->fd_file2);
		execve(pipex->cmds[pipex->cmd_nb - 1],
			pipex->args[pipex->cmd_nb - 1], env);
		free_pipex(pipex);
		pipex_error();
	}
	else
	{
		close(pipex->fd_file2);
		close(pipex->pipe[pipex->pipe_nb - 1][0]);
	}
}
