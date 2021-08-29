/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_t_pipex.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:03:29 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/27 05:51:38 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_T_PIPEX_H
# define PIPEX_T_PIPEX_H

typedef struct s_pipex
{
	int		cmd_nb;
	int		pipe_nb;
	int		path_nb;
	char	**env;
	char	***args;
	char	**cmds;
	pid_t	*child;
	int		**pipe;
	int		fd_file1;
	int		fd_file2;
	bool	here_doc;
	int		here_doc_pipe[2];
	char	*limiter;
}				t_pipex;

t_pipex	*malloc_pipex(void);
t_pipex	create_pipex(void);
void	destroy_pipex(t_pipex pipex);
void	free_pipex(t_pipex *pipex);

#endif