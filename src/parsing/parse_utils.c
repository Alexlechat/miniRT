/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:45:53 by anpicard          #+#    #+#             */
/*   Updated: 2025/08/05 20:29:43 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

//Vérifie si un caractère est un espace ou une tabulation
static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

//Compte le nombre de tokens dans une ligne (séparés par des espaces/tabs)
static int	count_tokens(char *str)
{
	int	count;
	int	in_token;
	int	i;

	count = 0;
	in_token = 0;
	i = 0;
	while (str[i])
	{
		if (!is_whitespace(str[i]))
		{
			if (!in_token)
			{
				count++;
				in_token = 1;
			}
		}
		else
			in_token = 0;
		i++;
	}
	return (count);
}

//Extrait un token à partir d'une position donnée
static char	*extract_token(char *str, int *pos)
{
	int		start;
	int		len;
	char	*token;
	int		i;

	i = *pos;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (!str[i])
		return (NULL);
	start = i;
	while (str[i] && !is_whitespace(str[i]))
		i++;
	*pos = i;
	len = i - start;
	token = malloc(len + 1);
	if (!token)
		return (NULL);
	ft_strlcpy(token, str + start, len + 1);
	token[len] = '\0';
	return (token);
}

// Nettoie les tokens en cas d'erreur
static void	cleanup_tokens(char **tokens, int count)
{
	while (--count >= 0)
		free(tokens[count]);
	free(tokens);
}

//Split une ligne en tokens en gérant les espaces multiples et tabulations
char	**smart_split(char *line)
{
	char	**tokens;
	int		token_count;
	int		pos;
	int		i;

	token_count = count_tokens(line);
	if (!line || token_count == 0)
		return (NULL);
	tokens = malloc(sizeof(char *) * (token_count + 1));
	if (!tokens)
		return (NULL);
	pos = 0;
	i = -1;
	while (++i < token_count)
	{
		tokens[i] = extract_token(line, &pos);
		if (!tokens[i])
			return (cleanup_tokens(tokens, i), NULL);
	}
	tokens[i] = NULL;
	return (tokens);
}
