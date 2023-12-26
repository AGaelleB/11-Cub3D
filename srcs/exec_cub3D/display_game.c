/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:57:41 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/26 16:47:14 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int display_game(t_data *data)
{
	int	x;

	x = 0;
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
	// ajouter les mouvements clavier
	return (0);
}


	// mlx_put_image_to_window(data->img_blank->mlx, data->img_blank->window,
	// 	data->texture_NO->img_ptr, 0, 0);
	// mlx_put_image_to_window(data->img_blank->mlx, data->img_blank->window,
	// 	data->texture_SO->img_ptr, 100, 0);
	// mlx_put_image_to_window(data->img_blank->mlx, data->img_blank->window,
	// 	data->texture_WE->img_ptr, 200, 0);
	// mlx_put_image_to_window(data->img_blank->mlx, data->img_blank->window,
	// 	data->texture_EA->img_ptr, 300, 0);

