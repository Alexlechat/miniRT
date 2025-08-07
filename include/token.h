/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 08:15:08 by allefran          #+#    #+#             */
/*   Updated: 2025/08/07 08:21:20 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H

# include "utils.h"

typedef enum e_token
{
	TOK_IDENTIFIER = 0,
	TOK_AMBIENT,
	TOK_COLOR,
	TOK_POSITION,
	TOK_ORIENTATION,
	TOK_FOV,
	TOK_BRIGHTNESS,
	TOK_DIAMETER,
	TOK_HEIGHT,
}					t_token;


#endif
