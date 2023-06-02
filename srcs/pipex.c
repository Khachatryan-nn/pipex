/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:06:18 by tikhacha          #+#    #+#             */
/*   Updated: 2023/06/02 17:51:15 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void		pipex_init(t_pipex *pipex, int argv, char **argc, char **env);
void static	handle_process(t_pipex *pipex, int i);
void		processsing(t_pipex *pipex);

void	pipex_init(t_pipex *pipex, int argv, char **argc, char **env)
{
	(void) env;
	(*pipex).cmd_args = NULL;
	(*pipex).cmd_path = NULL;
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

	i = -1 + pipex->here_doc;
	child_pid = 0;
	if (pipex->here_doc)
		read_input(pipex);
	pipex->exec_cmd = pipex->here_doc + 2;
	while (++i < pipex->cmd_n + pipex->here_doc)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Fork_err");
			exit(1);
		}
		else if (child_pid == 0)
			handle_process(pipex, i);
		pipex->exec_cmd++;
	}
}

void static	handle_process(t_pipex *pipex, int i)
{
	if (i == 0)
		child_start(pipex, i);
	else if (i == pipex->pipes_n)
		child_end(pipex, i);
	else
		child_middle(pipex, i);
	exit(0);
}
