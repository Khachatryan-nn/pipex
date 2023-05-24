/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:17:27 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/24 16:09:23 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void	parsing(char **arg, t_pipex *pipex, char **env);
int static	check_cmd(char **arg, t_pipex *pipex);
// int static	checker(t_pipex *pipex, int i);

void	parsing(char **arg, t_pipex *pipex, char **env)
{
	(*pipex).f_2rd = arg[1];
	(*pipex).f_2wr = arg[(*pipex).arg_n - 1];
	(*pipex).fd_2rd = open((*pipex).f_2rd, O_RDONLY);
	if ((*pipex).fd_2rd < 0)
		return (perror((*pipex).f_2rd));
	(*pipex).fd_2wr = open((*pipex).f_2wr, O_CREAT | O_WRONLY);
	if ((*pipex).fd_2wr < 0)
		return (perror((*pipex).f_2wr));
	(*pipex).path = ft_split(strinmatrix(env, "PATH"), ':');
	if (!(*pipex).path)
		return ((void) write(2, "Error: Unexpected\n", 18));
	if (!check_cmd (arg, pipex))
	{
		free_matrix((*pipex).path);
		return ((void) write(2, "Error: Unexpected\n", 18));
	}
	(*pipex).done = 1;
}

int static	check_cmd(char **arg, t_pipex *pipex)
{
	int	i;

	i = -1;
	(*pipex).cmd_n = (*pipex).arg_n - 3;
	(*pipex).cmd = (char **)malloc(sizeof(char *) * ((*pipex).arg_n + 1));
	(*pipex).cmd_args = (char ***)malloc(sizeof(char **) *((*pipex).arg_n + 1));
	if ((*pipex).cmd == NULL || (*pipex).cmd_args == NULL)
		return (0);
	(*pipex).cmd[(*pipex).cmd_n] = NULL;
	(*pipex).cmd_args[(*pipex).cmd_n] = NULL;
	while (++i < (*pipex).cmd_n)
	{
		(*pipex).cmd_args[i] = ft_split(arg[i + 2], ' ');
		(*pipex).cmd[i] = (*pipex).cmd_args[i][0];
	}
	return (1);
}
/*
int static	checker(t_pipex *pipex, int i)
{
	int		j;
	char	*path_cmd;
	char	*temp;

	j = -1;
	while ((*pipex).path[++j])
	{
		temp = ft_strjoin((*pipex).path[j], "/");
		path_cmd = ft_strjoin(temp, (*pipex).cmd[i]);
		if (access(path_cmd, X_OK) == 0)
		{
			free(path_cmd);
			free(temp);
			return (1);
		}
		free(path_cmd);
		free(temp);
	}
	perror((*pipex).cmd[i]);
	return (0);
}
*/