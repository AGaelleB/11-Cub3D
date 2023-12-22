/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:40:20 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/22 11:23:14 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	err(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return (1);
}

char	*copy_from(char *str, char c_start)
{
	char	*pos;
	char	*dest;
	int		size;

	pos = ft_strchr(str, c_start);
	if (pos != NULL)
	{
		size = ft_strlen(pos);
		dest = malloc(sizeof(char) * (size + 1));
		ft_strcpy(dest, pos);
		return (dest);
	}
	else
		return (NULL);
}

int	find_start_of_map(t_parser *parser)
{
	int	i;
	int	j;
	int	is_map_line;

	i = 0;
	while (parser->tab[i])
	{
		j = 0;
		is_map_line = 1;
		while (parser->tab[i][j])
		{
			if (parser->tab[i][j] != '1' && parser->tab[i][j] != ' ')
			{
				is_map_line = 0;
				break ;
			}
			j++;
		}
		if (is_map_line && j > 0)
			return (i);
		i++;
	}
	return (1);
}

int	is_all_space(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (!(input[i] >= 9 && input[i] <= 13) && input[i] != 32)
			return (0);
		i++;
	}
	return (1);
}
