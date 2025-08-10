/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apicard <apicard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:08:00 by apicard           #+#    #+#             */
/*   Updated: 2025/01/08 18:08:00 by apicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "../../libft/includes/libft.h"
#include <stdlib.h>

static int	trim_trailing_spaces(char *str, int len)
{
	while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t'
			|| str[len - 1] == '\n' || str[len - 1] == '\r'))
		len--;
	return (len);
}

static void	copy_valid_chars(char *src, char *dest, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (src[i] != '\n' && src[i] != '\r' && src[i] != '\t')
		{
			dest[j] = src[i];
			j++;
		}
		i++;
	}
	dest[j] = '\0';
}

char	*trim_newline(char *str)
{
	int		len;
	char	*str_trimed;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	len = trim_trailing_spaces(str, len);
	str_trimed = malloc(sizeof(char) * (len + 1));
	if (!str_trimed)
		return (NULL);
	copy_valid_chars(str, str_trimed, len);
	return (str_trimed);
}
