/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:17:27 by tikhacha          #+#    #+#             */
/*   Updated: 2023/06/01 01:43:08 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void		check_cmd(t_pipex *pipex);
void static	count_pipes(t_pipex *pipex);

void	parsing(t_pipex *pipex, char **env)
{
	(*pipex).path = ft_split(strinmatrix(env, "PATH"), ':');
	if (!(*pipex).path)
		return ((void) write(2, "Error: Unexpected\n", 18));
	if (ft_strcmp((*pipex).arg.argc[1], "here_doc") == 0)
		(*pipex).fd_2rd = 1;
	count_pipes(pipex);
	(*pipex).fd_2rd = open((*pipex).arg.argc[1], O_RDONLY);
	if ((*pipex).here_doc)
		(*pipex).fd_2wr = open((*pipex).arg.argc[(*pipex).arg.argv - 1], \
			O_WRONLY | O_CREAT | O_APPEND, 00755);
	else
		(*pipex).fd_2wr = open((*pipex).arg.argc[(*pipex).arg.argv - 1], \
			O_WRONLY | O_CREAT | O_TRUNC, 00755);
}

void	check_cmd(t_pipex *pipex)
{
	pipex->cmd_args = ft_split(pipex->arg.argc[pipex->exec_cmd], ' ');
	if (access(pipex->cmd_args[0], X_OK) == -1)
	{
		if (ft_strchr(pipex->cmd_args[0], '/') != NULL)
		{
			write (2, "Error: Unknown command.\n", 24);
			exit (1);
		}
		else if (!find_cmd(pipex))
		{
			write (2, "Error: Unknown command.\n", 24);
			exit (1);
		}
	}
	return (1);
}

void static	count_pipes(t_pipex *pipex)
{
	(*pipex).cmd_n = (*pipex).arg.argv - (*pipex).here_doc - 3;
	if ((*pipex).here_doc)
		(*pipex).pipes_n = (*pipex).cmd_n;
	else
		(*pipex).pipes_n = (*pipex).cmd_n - 1;
	(*pipex).pipes = malloc(sizeof(int [2]) * (*pipex).pipes_n);
	if (!(*pipex).pipes)
		exit (0);
}
