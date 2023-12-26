/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:57:41 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/26 10:57:47 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_pos_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->valid_map[y])
	{
		x = 0;
		while (data->valid_map[y][x])
		{
			if (data->valid_map[y][x] == 'N' || data->valid_map[y][x] == 'S'
				|| data->valid_map[y][x] == 'E' || data->valid_map[y][x] == 'W')
			{
				data->pos_player_x = x;
				data->pos_player_y = y;
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
