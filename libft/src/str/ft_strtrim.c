/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:03:16 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 09:02:06 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_find_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	int		in_set;

	i = 0;
	while (s1[i])
	{
		in_set = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				in_set = 1;
			j++;
		}
		if (!in_set)
		{
			return ((char *) s1 + i);
		}
		i++;
	}
	return ((char *) s1 + i);
}

static char	*ft_find_end(char const *s1, char const *set, char const *start)
{
	size_t	i;
	size_t	j;
	int		in_set;

	in_set = 0;
	i = ft_strlen(s1) - 1;
	j = 0;
	while (s1 + i >= start)
	{
		in_set = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				in_set = 1;
			j++;
		}
		if (!in_set)
			break ;
		i--;
	}
	if (s1 + i < start)
		return ((char *) start);
	return ((char *) s1 + i);
}

static char	*ft_calc_s(char const *start, char const *end)
{
	char	*new_s;
	size_t	i;

	new_s = malloc(sizeof(char) * (end - start + 2));
	if (!new_s)
		return (NULL);
	i = 0;
	while (start + i <= end)
	{
		new_s[i] = start[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*new_s;

	start = ft_find_start(s1, set);
	end = ft_find_end(s1, set, s1);
	if (!s1[0] || end < start)
	{
		new_s = malloc(sizeof(char) * 1);
		if (!new_s)
			return (NULL);
		new_s[0] = '\0';
	}
	else
		new_s = ft_calc_s(start, end);
	if (!new_s)
		return (NULL);
	return (new_s);
}
