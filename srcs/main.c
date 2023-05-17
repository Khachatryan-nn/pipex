/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:17:24 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/17 13:42:52 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int	main(int argv, char **argc, char **envp)
{
	int	i;

	i = -1;
	while (envp[++i] != NULL)
		printf("%s\n", envp[i]);
	printf("%s\n", strinmatrix(envp, "env"));
}