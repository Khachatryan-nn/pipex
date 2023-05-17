/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:17:53 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/17 13:41:18 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>

//void	parsing()

char	*strinmatrix(char **matrix, char *to_find);
char	*ft_strstr(char *s1, char *s2);
int		ft_strlen(char *s);





#endif
