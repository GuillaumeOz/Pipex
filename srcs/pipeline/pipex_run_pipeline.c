/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_run_pipeline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 02:32:26 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/27 05:33:24 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	wait_childs(t_pipex *pipex)
{
	int	status;
	int	i;

	i = 0;
	status = 0;
	while (i < pipex->cmd_nb)
	{
		waitpid(pipex->child[i], &status, 0);
		i++;
	}
}

void	run_pipeline(t_pipex *pipex, char **env)
{
	int	i;

	i = 1;
	run_first_cmd(pipex, env);
	while (i < pipex->cmd_nb - 1)
	{
		run_mid_cmd(pipex, env, i);
		i++;
	}
	run_last_cmd(pipex, env);
	wait_childs(pipex);
}
