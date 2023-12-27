/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:57:41 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/27 16:17:53 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	update_movement_keyboard(t_data *data)
{
	if (data->keys.w == 1)
		movement_player(data);
	if (data->keys.s == 1)
		movement_player(data);
	if (data->keys.d == 1)
		movement_player(data);
	if (data->keys.a == 1)
		movement_player(data);
	if (data->keys.rot_left == 1)
		movement_player(data);
	if (data->keys.rot_right == 1)
		movement_player(data);
}

int	display_game(t_data *data)
{
	int	x;

	x = 0;
	// ajouter les mouvements souris
	update_movement_keyboard(data);
	while (x < WIDTH)
	{
		init_ray(data, x);
		throw_rays(data);
		calcul_wall_drawing_params(data);
		draw_vertical_column(data, x, 0, data->game->line_height);
		x++;
	}
	mlx_put_image_to_window(data->img_blank->mlx, data->img_blank->window,
		data->img_blank->img_ptr, 0, 0);
	return (0);
}
