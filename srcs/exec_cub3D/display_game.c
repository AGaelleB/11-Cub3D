/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:57:41 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/27 12:30:55 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	display_game(t_data *data)
{
	int	x;

	x = 0;
	// ajouter les mouvements clavier et souris
	update_movement(data);
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

int	close_window(t_data *data)
{
	mlx_destroy_window(data->img_blank->mlx, data->img_blank->window);
	exit (0);
}
