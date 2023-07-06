/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:22:19 by tikhacha          #+#    #+#             */
/*   Updated: 2023/07/06 21:09:17 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strstr(char *s1, char *s2)
{
	int	i;
	int	j;

	i = -1;
	if (s2[0] == '\0')
		return (s1);
	while (s1[++i])
	{
		j = 0;
		while (s2[j] && s1[i + j] == s2[j] && s1[i + j])
			j++;
		if (s2[j] == '\0')
			return (s1 + i);
		i++;
	}
	return (NULL);
}

char	*strinmatrix(char **matrix, char *to_find)
{
	int		i;
	char	*s;

	i = -1;
	while (matrix[++i] != NULL)
	{
		s = ft_strstr(matrix[i], to_find);
		if (s != NULL)
			return (s);
	}
	return (NULL);
}
