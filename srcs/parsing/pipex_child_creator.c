/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child_creator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 02:47:02 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/25 16:03:46 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_creator(t_pipex *pipex)
{
	pipex->child = (pid_t *)malloc(sizeof(pid_t) * pipex->cmd_nb);
	if (pipex->child == NULL)
		pipex_error();
}
