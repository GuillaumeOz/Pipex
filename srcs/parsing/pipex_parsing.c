/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:45:15 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/27 05:29:21 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parsing(t_pipex *pipex, int argc, char **argv, char **env)
{
	if (BONUS == true)
		parsing_bonus(pipex, argc, argv, env);
	else
		parsing_basic(pipex, argc, argv, env);
	cmd_handler(pipex);
	child_creator(pipex);
	pipe_creator(pipex);
}
