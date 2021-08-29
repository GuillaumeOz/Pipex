/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipe_creator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 02:51:48 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/27 05:42:49 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_creator(t_pipex *pipex)
{
	int	i;

	i = 0;
	pipex->pipe = (int **)malloc(sizeof(int *) * (pipex->cmd_nb - 1));
	if (pipex->pipe == NULL)
		pipex_error();
	while (i < (pipex->cmd_nb - 1))
	{
		pipex->pipe[i] = (int *)malloc(sizeof(int) * 2);
		if (pipex->pipe[i] == NULL)
			pipex_error();
		pipe(pipex->pipe[i]);
		i++;
	}
}
