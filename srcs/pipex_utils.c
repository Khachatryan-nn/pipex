/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:51:30 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/25 16:14:09 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void	first_cmd(t_pipex *pipex)
{
	if (!ft_strcmp((*pipex).f_2rd, "here_doc"))
		;
	else
	{
		(*pipex).fd_2rd = open((*pipex).f_2rd, O_RDONLY);
		if ((*pipex).fd_2rd < 0)
			return (perror((*pipex).f_2rd));
		dup2(0, (*pipex).fd_2rd);
		pipe((*pipex).pipes);
		close((*pipex).pipes[1]);
	}
}
