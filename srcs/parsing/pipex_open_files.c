/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_open_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:07:39 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/27 05:31:23 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files(t_pipex *pipex, char *file1, char *file2)
{
	pipex->fd_file1 = open(file1, O_RDONLY);
	if (pipex->fd_file1 < 0)
		pipex_error();
	pipex->fd_file2 = open(file2, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->fd_file2 < 0)
		pipex_error();
}
