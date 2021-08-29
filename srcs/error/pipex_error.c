/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 14:10:00 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/27 05:45:46 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_error(void)
{
	char	*error_msg;

	error_msg = strerror(errno);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
	exit(errno);
}
