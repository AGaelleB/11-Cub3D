/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:57:41 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/25 19:29:48 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


// int	display_game(t_data *data)
// {
// 	int	x;

// 	x = 0;
// 	while (x < WIDTH)
// 	{
// 		init_raydir_delta(data, x);
// 		init_sidedist(data);
// 		throw_rays(data);
// 		get_draw_point(data);
// 		draw_total_frame(data, x, 0, data->line_height);
// 		x++;
// 	}
// 	// if (cub->mouse_on == 0)
// 	// 	mlx_mouse_move(cub->img->mlx, cub->img->win, WIDTH / 2, HEIGHT / 2);
// 	// display_minimap(cub, 0, 0);
// 	mlx_put_image_to_window(data->img_blank->mlx, data->img_blank->window,
// 		data->img_blank->img_ptr, 0, 0);
// 	return (0);
// }



int display_game(t_data *data)
{

	

	// mlx_put_image_to_window(data->img_blank->mlx, data->img_blank->window,
	// 	data->texture_NO->img_ptr, 0, 0);
	// mlx_put_image_to_window(data->img_blank->mlx, data->img_blank->window,
	// 	data->texture_SO->img_ptr, 100, 0);
	// mlx_put_image_to_window(data->img_blank->mlx, data->img_blank->window,
	// 	data->texture_WE->img_ptr, 200, 0);
	// mlx_put_image_to_window(data->img_blank->mlx, data->img_blank->window,
	// 	data->texture_EA->img_ptr, 300, 0);


	mlx_put_image_to_window(data->img_blank->mlx, data->img_blank->window,
		data->img_blank->img_ptr, 0, 0);
	return (0);
}
