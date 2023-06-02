/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:17:53 by tikhacha          #+#    #+#             */
/*   Updated: 2023/06/02 17:04:46 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_cmd
{
	char	**argc;
	int		argv;
}			t_arg;

/*
*char	**cmd_args;
*char	*cmd_path;
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
	char	*cmd_path;
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
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*strinmatrix(char **matrix, char *to_find);
char	*ft_strjoin(char const *s1, char const *s2);
void	parsing(t_pipex *pipex, char **env);
void	child_middle(t_pipex *pipex, int i);
void	child_start(t_pipex *pipex, int i);
char	**ft_split(char const *s, char c);
void	child_end(t_pipex *pipex, int i);
void	first_cmd(int i, t_pipex *pipex);
char	*ft_strstr(char *s1, char *s2);
char	*ft_strchr(char *str, char c);
int		ft_strcmp(char *s1, char *s2);
void	processsing(t_pipex *pipex);
char	*ft_strdup(const char *s1);
void	read_input(t_pipex *pipex);
void	check_cmd(t_pipex *pipex);
int		ft_strlen(char const *s);
char	*get_next_line(int fd);
void	free_matrix(char **x);

#endif
