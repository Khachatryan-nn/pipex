/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:51:30 by tikhacha          #+#    #+#             */
/*   Updated: 2023/07/06 21:09:17 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	read_input(t_pipex *pipex);
void	child_end(t_pipex *pipex, int i);
void	child_start(t_pipex *pipex, int i);
void	child_middle(t_pipex *pipex, int i);

void	child_start(t_pipex *pipex, int i)
{
	int	j;

	j = -1;
	check_cmd(pipex);
	if (dup2(pipex->fd_2rd, STDIN_FILENO) == -1)
	{
		perror("dup2_err");
		exit (1);
	}
	if (dup2(pipex->pipes[i][1], STDOUT_FILENO) == -1)
	{
		perror("dup2_err");
		exit (1);
	}
	while (++j < pipex->pipes_n)
	{
		close(pipex->pipes[j][0]);
		close(pipex->pipes[j][1]);
	}
	if (execve(pipex->cmd_path, pipex->cmd_args, pipex->path) == -1 && \
		execve(pipex->cmd_args[0], pipex->cmd_args, pipex->path) == -1)
	{
		perror("execve_Err");
		exit (1);
	}
}

void	child_middle(t_pipex *pipex, int i)
{
	int	j;

	j = -1;
	check_cmd(pipex);
	if (dup2(pipex->pipes[i - 1][0], STDIN_FILENO) == -1)
	{
		perror("dup2_err");
		exit (1);
	}
	if (dup2(pipex->pipes[i][1], STDOUT_FILENO) == -1)
	{
		perror("dup2_err");
		exit (1);
	}
	while (++j < pipex->pipes_n)
	{
		close(pipex->pipes[j][0]);
		close(pipex->pipes[j][1]);
	}
	if (execve(pipex->cmd_path, pipex->cmd_args, pipex->path) == -1 && \
		execve(pipex->cmd_args[0], pipex->cmd_args, pipex->path) == -1)
	{
		perror("execve_Err");
		exit (1);
	}
}

void	child_end(t_pipex *pipex, int i)
{
	int	j;

	j = -1;
	check_cmd(pipex);
	if (dup2(pipex->pipes[i - 1][0], STDIN_FILENO) == -1)
	{
		perror("dup2_err");
		exit (1);
	}
	if (dup2(pipex->fd_2wr, STDOUT_FILENO) == -1)
	{
		perror("dup2_err");
		exit (1);
	}
	while (++j < pipex->pipes_n)
	{
		close(pipex->pipes[j][0]);
		close(pipex->pipes[j][1]);
	}
	if (execve(pipex->cmd_path, pipex->cmd_args, pipex->path) == -1 && \
		execve(pipex->cmd_args[0], pipex->cmd_args, pipex->path) == -1)
	{
		perror("execve_Err");
		exit (1);
	}
}

void	read_input(t_pipex *pipex)
{
	char	*line;
	char	*end;

	end = ft_strjoin(pipex->arg.argc[2], "\n");
	while (1)
	{
		write (1, "pipe here_doc> ", 15);
		line = get_next_line(0);
		if (line == NULL || !ft_strcmp(line, end))
		{
			free (line);
			break ;
		}
		write (pipex->pipes[0][1], line, ft_strlen(line));
		free (line);
	}
	free (end);
}
