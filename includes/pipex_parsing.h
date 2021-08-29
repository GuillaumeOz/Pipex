/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:47:08 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/27 05:01:02 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_PARSING_H
# define PIPEX_PARSING_H

void	pipe_creator(t_pipex *pipex);

void	child_creator(t_pipex *pipex);

void	cmd_handler(t_pipex *pipex);

void	here_doc_fill_stdin_bonus(t_pipex *pipex);

void	here_doc_parse_cmd_bonus(t_pipex *pipex, int argc,
			char **argv, char **env);
void	parse_cmd(t_pipex *pipex, int argc, char **argv, char **env);

void	here_doc_open_files_bonus(t_pipex *pipex, char *file2);
void	open_files(t_pipex *pipex, char *file1, char *file2);

void	parsing_bonus(t_pipex *pipex, int argc, char **argv, char **env);
void	parsing_basic(t_pipex *pipex, int argc, char **argv, char **env);

void	parsing(t_pipex *pipex, int argc, char **argv, char **env);

#endif