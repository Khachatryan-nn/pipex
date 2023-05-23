/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:17:27 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/23 12:38:35 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int static	check_cmd(char **arg, t_pipex *pipex);
int static	checker(t_pipex *pipex, int i);

void	parsing(char **arg, t_pipex *pipex, char **env)
{
	(*pipex).file_out = arg[1];
	(*pipex).file_in = arg[(*pipex).arg_n - 1];
	(*pipex).fileout_d = open((*pipex).file_out, O_RDONLY);
	if ((*pipex).fileout_d < 0)
		return (perror("First file"));
	(*pipex).filein_d = open((*pipex).file_in, O_WRONLY);
	if ((*pipex).filein_d < 0)
		return (perror("Second file"));
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
	if ((*pipex).cmd == NULL)
		return (0);
	(*pipex).cmd[(*pipex).cmd_n] = NULL;
	while (++i < (*pipex).cmd_n)
		(*pipex).cmd[i] = arg[i + 2];
	i = -1;
	while (++i < (*pipex).cmd_n)
	{
		if (!checker(pipex, i))
		{
			free((*pipex).cmd[(*pipex).cmd_n]);
			free((*pipex).cmd);
			return (0);
		}
	}
	return (1);
}

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
