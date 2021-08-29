/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_fill_stdin_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 21:45:56 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/27 04:53:29 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	here_doc_gnl_recursive(int fd, char **line, int index)
{
	char	buffer;
	int		ret;

	ret = read(fd, &buffer, 1);
	if (ret == -1)
		return (-1);
	if (ret == 1 && buffer != '\n')
	{
		ret = here_doc_gnl_recursive(fd, line, index + 1);
		if (ret == -1)
			return (-1);
		(*line)[index] = buffer;
	}
	else
	{
		(*line) = (char *)malloc(sizeof(char) * (index + 1));
		if ((*line) == NULL)
			return (-1);
		(*line)[index] = '\0';
	}
	return (ret);
}

static int	here_doc_get_next_line_bonus(int fd, char **line)
{
	int	ret;

	ret = here_doc_gnl_recursive(fd, line, 0);
	if (line == NULL || ret == -1)
		return (-1);
	return (ret);
}

void	here_doc_fill_stdin_bonus(t_pipex *pipex)
{
	char	*line;
	size_t	len;

	line = NULL;
	pipe(pipex->here_doc_pipe);
	write(1, "> ", 2);
	while (here_doc_get_next_line_bonus(0, &line) > 0)
	{
		if (ft_strcmp(line, pipex->limiter) == true)
		{
			write(1, "\n", 1);
			free(line);
			break ;
		}
		else
		{
			len = ft_strlen(line);
			write(pipex->here_doc_pipe[1], line, len);
			write(pipex->here_doc_pipe[1], "\n", 1);
			write(1, "> ", 2);
			free(line);
		}
	}
	close(pipex->here_doc_pipe[1]);
}
