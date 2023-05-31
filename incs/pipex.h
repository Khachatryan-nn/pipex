/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:17:53 by tikhacha          #+#    #+#             */
/*   Updated: 2023/06/01 01:18:45 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_cmd
{
	char	**argc;
	int		argv;
}			t_arg;

/*
*char	**cmd_args;
*char	**path;
*char	**cmd;
*int	cmd_n;
*int	arg_n;
*int	fd_2rd;
*int	fd_2wr;
*int	here_doc;
*int	exec_cmd;
*int	done;
int		(*pipes)[2];
*t_arg	arg;
*/
typedef struct s_pipex
{
	char	**cmd_args;
	char	**path;
	char	**cmd;
	int		pipes_n;
	int		cmd_n;
	int		arg_n;
	int		fd_2rd;
	int		fd_2wr;
	int		here_doc;
	int		exec_cmd;
	int		done;
	int		(*pipes)[2];
	t_arg	arg;
}			t_pipex;

void	pipex_init(t_pipex *pipex, int argv, char **argc, char **env);
char	*ft_strjoin(char const *s1, char const *s2);
char	*strinmatrix(char **matrix, char *to_find);
void	parsing(t_pipex *pipex, char **env);
char	**ft_split(char const *s, char c);
void	first_cmd(int i, t_pipex *pipex);
char	*ft_strstr(char *s1, char *s2);
void	processsing_hd(t_pipex *pipex);
int		ft_strcmp(char *s1, char *s2);
void	processsing(t_pipex *pipex);
int		ft_strlen(char const *s);
void	free_matrix(char **x);

#endif
