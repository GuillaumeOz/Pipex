/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_run_fisrt_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:21:20 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/27 05:27:34 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	it_is_here_doc_parent(t_pipex *pipex)
{
	if (pipex->here_doc == false)
		close(pipex->fd_file1);
	else
		close(pipex->here_doc_pipe[0]);
}

static void	it_is_here_doc_child(t_pipex *pipex)
{
	if (pipex->here_doc == false)
		dup2(pipex->fd_file1, STDIN_FILENO);
	else
		dup2(pipex->here_doc_pipe[0], STDIN_FILENO);
}

void	run_first_cmd(t_pipex *pipex, char **env)
{
	pipex->child[0] = fork();
	if (pipex->child[0] < 0)
	{
		free_pipex(pipex);
		pipex_error();
	}
	else if (pipex->child[0] == 0)
	{
		close(pipex->pipe[0][0]);
		it_is_here_doc_child(pipex);
		dup2(pipex->pipe[0][1], STDOUT_FILENO);
		if (pipex->here_doc == false)
			close(pipex->fd_file1);
		close(pipex->pipe[0][1]);
		execve(pipex->cmds[0], pipex->args[0], env);
		free_pipex(pipex);
		pipex_error();
	}
	else
	{
		it_is_here_doc_parent(pipex);
		close(pipex->pipe[0][1]);
	}
}
