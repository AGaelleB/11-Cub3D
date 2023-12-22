/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_start_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:40:33 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/22 15:55:21 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	verif_inside_pos_player(t_parser *parser, int i, int j)
{
	int	prev_row_len;
	int	next_row_len;

	prev_row_len = 0;
	next_row_len = 0;
	if (parser->map[i][0] == 'N' || parser->map[i][0] == 'S'
		|| parser->map[i][0] == 'E' || parser->map[i][0] == 'W')
		return (1);
	if (i > 0)
		prev_row_len = ft_strlen(parser->map[i - 1]);
	if (i < parser->map_height - 1)
		next_row_len = ft_strlen(parser->map[i + 1]);
	if ((i > 0 && j < prev_row_len && (parser->map[i - 1][j] == ' '
			|| !parser->map[i - 1][j]))
			|| (i < parser->map_height - 1 && j < next_row_len
			&& (parser->map[i + 1][j] == ' ' || !parser->map[i + 1][j]))
			|| (j > 0 && parser->map[i][j - 1] == ' ')
			|| (j < parser->map_width - 1 && parser->map[i][j + 1] == ' '))
		return (1);
	if ((i > 0 && j >= prev_row_len)
		|| (i < parser->map_height - 1 && j >= next_row_len))
		return (1);
	return (0);
}

int	verif_pos_player(t_parser *parser)
{
	int	i;
	int	j;

	i = 0;
	while (i < parser->map_height)
	{
		j = 0;
		while ((j < parser->map_width) && parser->map[i][j])
		{
			if (parser->map[i][j] == 'N' || parser->map[i][j] == 'S'
				|| parser->map[i][j] == 'E' || parser->map[i][j] == 'W')
			{
				if (verif_inside_pos_player(parser, i, j))
					return (1);
			}
			j++;
		}
		if (parser->map[i][--j] == '0')
			return (1);
		i++;
	}
	return (0);
}
