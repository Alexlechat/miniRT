/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:51:15 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/07 14:22:35 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	identifier_check(char *arg);

int	mandatory_check(char **line)
{
	if (!identifier_check(line[0]))
		return (0);
	if (line[0][0] == 'A')
		return(ambient(line));
	else if (line[0][0] == 'L')
		return(light(line));
	else if (line[0][0] == 'C')
		return(camera(line));
	return (0);
}

static int	identifier_check(char *arg)
{
	if (arg[1] != '\0')
		return (0);
	if (arg[0] != 'A' && arg[0] != 'C' && arg[0] != 'L')
		return (0);
	return (1);
}
