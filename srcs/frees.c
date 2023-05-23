/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:18:35 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/19 11:20:27 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void	free_matrix(char **x)
{
	int	i;

	i = -1;
	while (x[++i] != NULL)
		free(x[i]);
	free(x);
	x = 0;
}