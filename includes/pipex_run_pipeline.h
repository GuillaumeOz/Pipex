/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_run_pipeline.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 02:39:47 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/27 05:00:26 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_RUN_PIPELINE_H
# define PIPEX_RUN_PIPELINE_H

void	run_last_cmd(t_pipex *pipex, char **env);

void	run_mid_cmd(t_pipex *pipex, char **env, int i);

void	run_first_cmd(t_pipex *pipex, char **env);

void	run_pipeline(t_pipex *pipex, char **env);

#endif