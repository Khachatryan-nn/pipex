/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:06:09 by tikhacha          #+#    #+#             */
/*   Updated: 2023/06/02 17:52:43 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (str + i);
	}
	if (str[i] == c)
		return (str + i);
	return (NULL);
}
