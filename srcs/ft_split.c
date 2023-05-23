/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:47:01 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/18 23:47:12 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

static int	ft_count_words(char const *str, char ch)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (str[i])
	{
		while (str[i] == ch && str[i] != '\0')
			i++;
		if (str[i] != ch && str[i])
			counter++;
		while (str[i] != ch && str[i])
			i++;
	}
	return (counter);
}

static int	word_len(char const *str, char ch)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != ch)
		i++;
	return (i);
}

static int	ft_split_word(char const *s, int len, char **sentence, int i)
{
	int	j;

	j = 0;
	sentence[i] = (char *)malloc(sizeof(char) * (len + 1));
	if (!sentence[i])
		return (0);
	while (j < len)
	{
		sentence[i][j] = s[j];
		j++;
	}
	sentence[i][j] = '\0';
	return (1);
}

static char	**ft_free(char ***sentence, int row_n)
{
	while (row_n > 0)
		free(*sentence[row_n--]);
	free(*sentence);
	sentence = NULL;
	return (*sentence);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word_lenght;
	int		words_num;
	char	**sentence;

	if (!s)
		return (0);
	i = 0;
	word_lenght = 0;
	words_num = ft_count_words(s, c) + 1;
	sentence = (char **)malloc(sizeof(char *) * words_num);
	if (!sentence)
		return (0);
	while (i < words_num - 1 && *s)
	{
		while (*s == c && *s)
			s++;
		word_lenght = word_len(s, c);
		if (!ft_split_word(s, word_lenght, sentence, i))
			return (ft_free(&sentence, i));
		s += word_lenght;
		i++;
	}
	sentence[i] = NULL;
	return (sentence);
}
