/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:03:02 by anpicard          #+#    #+#             */
/*   Updated: 2025/02/28 09:02:06 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*new_s;

	if (!s)
		return (NULL);
	i = 0;
	len_s = ft_strlen(s);
	if (start >= len_s)
		len = 0;
	else if (start + len >= len_s)
		len = ft_strlen(s + start);
	new_s = malloc(sizeof(char) * (len + 1));
	if (!new_s)
		return (NULL);
	while (start + i < len_s && i < len)
	{
		new_s[i] = s[start + i];
		i++;
	}
	new_s[i] = 0;
	return (new_s);
}
