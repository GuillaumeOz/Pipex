/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parsing_basic.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:36:32 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/27 05:29:32 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parsing_basic(t_pipex *pipex, int argc, char **argv, char **env)
{
	if (argc != 5)
		pipex_error();
	open_files(pipex, argv[1], argv[4]);
	parse_cmd(pipex, argc, argv, env);
}
