/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:31:46 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/05 13:23:36 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	total;

	total = nmemb * size;
	if (nmemb && size && (total / nmemb != size))
		return (NULL);
	arr = malloc(total);
	if (!arr)
		return (NULL);
	ft_memset(arr, 0, total);
	return (arr);
}
