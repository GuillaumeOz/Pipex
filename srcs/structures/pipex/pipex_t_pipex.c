/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_t_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:35:55 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/27 05:06:44 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	*malloc_pipex(void)
{
	t_pipex	*pipex;

	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (pipex == NULL)
		pipex_error();
	*pipex = create_pipex();
	return (pipex);
}

t_pipex	create_pipex(void)
{
	t_pipex	pipex;

	ft_memset(&pipex, 0, sizeof(t_pipex));
	pipex.env = NULL;
	pipex.args = NULL;
	pipex.cmds = NULL;
	pipex.child = NULL;
	pipex.pipe = NULL;
	pipex.limiter = NULL;
	pipex.here_doc = false;
	return (pipex);
}

void	destroy_pipex(t_pipex pipex)
{
	int	i;

	i = -1;
	while (++i < pipex.cmd_nb)
		ft_tab_free(pipex.args[i]);
	i = -1;
	while (++i < pipex.pipe_nb)
		free(pipex.pipe[i]);
	free(pipex.pipe);
	free(pipex.args);
	ft_tab_free(pipex.env);
	ft_tab_free(pipex.cmds);
	free(pipex.child);
	if (pipex.here_doc == true)
		free(pipex.limiter);
	ft_memset(&pipex, 0, sizeof(t_pipex));
}

void	free_pipex(t_pipex *pipex)
{
	destroy_pipex(*pipex);
	free(pipex);
}
