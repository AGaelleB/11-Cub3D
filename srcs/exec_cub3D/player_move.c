/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:55:55 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/27 12:29:40 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	movement_player_up_down(t_data *data)
{
	if (data->keys.w == 1)
	{
		if (data->valid_map[(int)(data->game->pos_x + data->game->dir_x
				* SPEED)][(int)(data->game->pos_y)] != '1')
			data->game->pos_x += data->game->dir_x * SPEED;
		if (data->valid_map[(int)(data->game->pos_x)][(int)(data->game->pos_y
			+ data->game->dir_y * SPEED)] != '1')
			data->game->pos_y += data->game->dir_y * SPEED;
	}
	else if (data->keys.s == 1)
	{
		if (data->valid_map[(int)(data->game->pos_x - data->game->dir_x
				* SPEED)][(int)(data->game->pos_y)] != '1')
			data->game->pos_x -= data->game->dir_x * SPEED;
		if (data->valid_map[(int)(data->game->pos_x)][(int)(data->game->pos_y
			- data->game->dir_y * SPEED)] != '1')
			data->game->pos_y -= data->game->dir_y * SPEED;
	}
}

void	movement_player_right_left(t_data *data)
{
	if (data->keys.d == 1)
	{
		if (data->valid_map[(int)(data->game->pos_x + data->game->plan_x
				* SPEED)]
			[(int)(data->game->pos_y)] != '1')
			data->game->pos_x += data->game->plan_x * SPEED;
		if (data->valid_map[(int)(data->game->pos_x)]
			[(int)(data->game->pos_y + data->game->plan_y
					* SPEED)] != '1')
			data->game->pos_y += data->game->plan_y * SPEED;
	}
	else if (data->keys.a == 1)
	{
		if (data->valid_map[(int)(data->game->pos_x - data->game->plan_x
				* SPEED)]
			[(int)(data->game->pos_y)] != '1')
			data->game->pos_x -= data->game->plan_x * SPEED;
		if (data->valid_map[(int)(data->game->pos_x)]
			[(int)(data->game->pos_y - data->game->plan_y * SPEED)] != '1')
			data->game->pos_y -= data->game->plan_y * SPEED;
	}
}

void	movement_player(t_data *data)
{
	movement_player_up_down(data);
	movement_player_right_left(data);
}

void	update_movement(t_data *data)
{
	if (data->keys.w == 1) // avancer
		movement_player(data);
	if (data->keys.s == 1) // reculer
		movement_player(data);
	if (data->keys.d == 1) // droite
		movement_player(data);
	if (data->keys.a == 1) // gauche
		movement_player(data);
}
