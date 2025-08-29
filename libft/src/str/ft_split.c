/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:23:26 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/29 09:30:49 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	nb_words;
	size_t	i;

	i = 0;
	nb_words = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			nb_words++;
		i++;
	}
	return (nb_words);
}

static char	*ft_copy_words(char const *src, size_t len)
{
	char	*str;
	size_t	i;

	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static void	ft_free_str(char **split, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	**split_words(char const *s, char c, char **split)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			split[k] = ft_copy_words(s + j, i - j);
			if (!split[k++])
			{
				ft_free_str(split, k);
				return (NULL);
			}
		}
	}
	split[k] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **) malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!split)
		return (NULL);
	return (split_words(s, c, split));
}
