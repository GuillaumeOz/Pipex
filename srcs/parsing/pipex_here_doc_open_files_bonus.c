/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc_open_files_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:35:11 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/26 20:56:25 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc_open_files_bonus(t_pipex *pipex, char *file2)
{
	pipex->fd_file2 = open(file2, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (pipex->fd_file2 < 0)
		pipex_error();
}
