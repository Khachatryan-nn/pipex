/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:17:24 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/24 17:18:02 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void static preparing(t_pipex *pipex);
void static	child_p(t_pipex *pipex, int i);

int	main(int argv, char **argc, char **env)
{
	(void) argv;
	(void) argc;
	(void) env;
	t_pipex	pipex;

	if (argv < 5)
	{
		write(2, "Error: Too few arguments!\n", 26);
		return (0);
	}
	pipex.done = 0;
	pipex.arg_n = argv;
	pipex.pipes_n = pipex.arg_n - 1;
	parsing(argc, &pipex, env);
	if (pipex.done == 0)
		return (0);
	preparing(&pipex);
}

void static preparing(t_pipex *pipex)
{
	int	i;
	int	p_id;

	i = -1;
	while (++i < (*pipex).pipes_n)
	{
		p_id = fork();
		if (p_id == -1)
			continue ;
		if (p_id == 0)
			handle_childp(pipex, i);
	}
}

void static	child_p(t_pipex *pipex, int i);
{
	if (i == 0)
		//some staff for first command
	eles if (i == (*pipex).pipes_n)
		//some staff for ending command
	else
		//some staff for middle commands
}
