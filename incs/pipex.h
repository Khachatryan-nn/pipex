/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:17:53 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/24 15:53:05 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdlib.h>

//typedef struct s_cmd
//{
//	char	**cmd;
//	char	**flags;
//	int		cmd_n;
//};

/*
*char	**cmd_args;
*char	*f_2rd;
*char	*f_2wr;
*char	**path;
*char	**cmd;
*int	cmd_n;
*int	arg_n;
*int	fd_2rd;
*int	fd_2wr;
*int	done;
*/
typedef struct s_pipex
{
	char	***cmd_args;
	char	*f_2rd;
	char	*f_2wr;
	char	**path;
	char	**cmd;
	int		pipes_n;
	int		cmd_n;
	int		arg_n;
	int		fd_2rd;
	int		fd_2wr;
	int		done;
}			t_pipex;

void	parsing(char **arg, t_pipex *pipex, char **env);
char	*ft_strjoin(char const *s1, char const *s2);
char	*strinmatrix(char **matrix, char *to_find);
char	**ft_split(char const *s, char c);
char	*ft_strstr(char *s1, char *s2);
int		ft_strlen(char const *s);
void	free_matrix(char **x);

#endif
