/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:17:24 by tikhacha          #+#    #+#             */
/*   Updated: 2023/06/02 17:52:08 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void static	preparing(t_pipex *pipex);

int	main(int argv, char **argc, char **env)
{
	t_pipex	pipex;

	if (argv < 6 && !ft_strcmp(argc[1], "here_doc"))
	{
		write(2, "Error: Too few arguments!\n", 26);
		return (0);
	}
	else if (argv < 5)
	{
		write(2, "Error: Too few arguments!\n", 26);
		return (0);
	}
	pipex_init(&pipex, argv, argc, env);
	parsing(&pipex, env);
	preparing(&pipex);
}

void static	preparing(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (++i < (*pipex).pipes_n)
	{
		if (pipe(pipex->pipes[i]) == -1)
		{
			perror("Pipe_err");
			exit(1);
		}
	}
	i = -1;
	processsing(pipex);
	while (++i < pipex->pipes_n)
	{
		close(pipex->pipes[i][0]);
		close(pipex->pipes[i][1]);
	}
	while (wait(NULL) != -1)
		;
}
