/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parsing_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:16:28 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/27 05:29:28 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parsing_bonus(t_pipex *pipex, int argc, char **argv, char **env)
{
	if (ft_strcmp(argv[1], "here_doc") == true)
	{
		if (argc < 6)
			pipex_error();
		pipex->limiter = ft_strdup(argv[2]);
		if (pipex->limiter == NULL)
			pipex_error();
		here_doc_open_files_bonus(pipex, argv[argc - 1]);
		here_doc_parse_cmd_bonus(pipex, argc, argv, env);
		here_doc_fill_stdin_bonus(pipex);
		pipex->here_doc = true;
	}
	else if (argc > 5)
	{
		open_files(pipex, argv[1], argv[argc - 1]);
		parse_cmd(pipex, argc, argv, env);
	}
	else
		parsing_basic(pipex, argc, argv, env);
}
