/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitchrset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 01:14:33 by aghar             #+#    #+#             */
/*   Updated: 2020/02/26 23:04:51 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_separator(char c, char const *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		++i;
	}
	return (0);
}

static int		count_words(char *str, const char *charset)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i] && is_separator(str[i], charset))
		++i;
	if (str[i] && !is_separator(str[i], charset))
		count = 1;
	while (str[i])
	{
		if (!is_separator(str[i], charset) && is_separator(str[i - 1], charset))
			++count;
		++i;
	}
	return (count);
}

static int		word_size(char *str, char const *charset)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i] && !is_separator(str[i], charset))
	{
		++size;
		++i;
	}
	return (size);
}

char			**ft_strsplitchrset(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		j;
	int		index;

	if (!(tab = (char**)malloc(sizeof(char*) *
					(count_words(str, charset) + 1))))
		return (NULL);
	i = -1;
	index = -1;
	while (str[++i])
		if (!is_separator(str[i], charset))
		{
			if (index == -1 || is_separator(str[i - 1], charset))
			{
				tab[++index] = (char*)malloc(sizeof(char) * (word_size(
						str + i, charset) + 1));
				j = 0;
			}
			tab[index][j] = str[i];
			tab[index][++j] = '\0';
		}
	free(charset);
	tab[++index] = 0;
	return (tab);
}
