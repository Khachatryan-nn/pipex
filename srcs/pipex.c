/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:06:18 by tikhacha          #+#    #+#             */
/*   Updated: 2023/06/01 01:19:40 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void	pipex_init(t_pipex *pipex, int argv, char **argc, char **env)
void	processsing_hd(t_pipex *pipex);
void	processsing(t_pipex *pipex);

void	pipex_init(t_pipex *pipex, int argv, char **argc, char **env)
{
	(*pipex).cmd_args = NULL;
	(*pipex).pipes = NULL;
	(*pipex).path = NULL;
	(*pipex).cmd = NULL;
	(*pipex).arg_n = argv;
	(*pipex).here_doc = 0;
	(*pipex).pipes_n = 0;
	(*pipex).fd_2rd = 0;
	(*pipex).fd_2wr = 0;
	(*pipex).cmd_n = 0;
	(*pipex).done = 0;
	(*pipex).arg.argc = argc;
	(*pipex).arg.argv = argv;
}

void	processsing(t_pipex *pipex)
{
	int	i;
	int	child_pid;

	i = -1;
	child_pid = 0;
	pipex->exec_cmd = pipex->here_doc + 2;
	while (++i < pipex->cmd_n)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Fork_err");
			exit(1);
		}
		else if (child_pid == 0)
		{
			if (i == 0)
				child_start(pipex, i);
			else if (i == pipex->pipes_n)
				child_middle(pipex, i);
			else
				child_end(pipex, i);
		}
	}
}
