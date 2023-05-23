/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:17:24 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/23 12:14:59 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int	main(int argv, char **argc, char **env)
{
	t_pipex	pipex;
	//int		i;
	int		child_p;

	if (argv < 5)
	{
		write(2, "Error: Too few arguments!\n", 26);
		return (0);
	}
	pipex.done = 0;
	pipex.arg_n = argv;
	parsing(argc, &pipex, env);
	if (pipex.done == 0)
		return (0);
	child_p = fork();
	if (child_p == -1)
		perror("Error:");
}
