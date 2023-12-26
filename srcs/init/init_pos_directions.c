/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos_directions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:43:17 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/26 17:26:10 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_pos_dig(t_data *data)
{
	if (data->valid_map[(int)data->game->pos_x][(int)data->game->pos_y] == 'W')
	{
		data->game->dir_x = 0;
		data->game->dir_y = -1;
		data->game->plan_x = -0.66;
		data->game->plan_y = 0;
	}
	else if (data->valid_map[(int)data->game->pos_x][(int)data->game->pos_y]
		== 'E')
	{
		data->game->dir_x = 0;
		data->game->dir_y = 1;
		data->game->plan_x = 0.66;
		data->game->plan_y = 0;
	}
	return ;
}

void	init_pos_directions(t_data *data)
{
	if (data->valid_map[(int)data->game->pos_x][(int)data->game->pos_y] == 'N')
	{
		data->game->dir_x = -1;
		data->game->dir_y = 0;
		data->game->plan_x = 0;
		data->game->plan_y = 0.66;
	}
	else if (data->valid_map[(int)data->game->pos_x][(int)data->game->pos_y]
		== 'S')
	{
		data->game->dir_x = 1;
		data->game->dir_y = 0;
		data->game->plan_x = 0;
		data->game->plan_y = -0.66;
	}
	else
		init_pos_dig(data);
}
