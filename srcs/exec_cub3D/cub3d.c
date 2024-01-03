/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:39:45 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/03 16:44:42 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	close_window(t_data *data)
{
	mlx_destroy_window(data->img_blank->mlx, data->img_blank->window);
	exit (0);
}

int	capture_mouse(int x, int y, t_data *data)
{
	(void)y;
	const int EDGE_THRESHOLD = (WIDTH / 3);
	if (x > WIDTH - EDGE_THRESHOLD) // && y <= WIDTH)
	{
		data->keys.mouse_rot_right = 1;
		data->keys.mouse_rot_left = 0;
	}
	else if (x < EDGE_THRESHOLD) // && y <= WIDTH)
	{
		data->keys.mouse_rot_left = 1;
		data->keys.mouse_rot_right = 0;
	}
	else
	{
		data->keys.mouse_rot_right = 0;
		data->keys.mouse_rot_left = 0;
	}
	return (0);
}

void	exec_game(t_parser *parser)
{
	t_data	data;

	init_data_game(&data, parser);
	if (init_windows(&data))
		return ;
	init_textures_adress(&data);
	mlx_hook(data.img_blank->window, KeyPress, KeyPressMask, key_press, &data);
	mlx_hook(data.img_blank->window, MotionNotify, PointerMotionMask, capture_mouse, &data);
	mlx_hook(data.img_blank->window, KeyRelease, KeyReleaseMask, key_release, &data);
	mlx_hook(data.img_blank->window, 17, 0, close_window, &data);
	mlx_loop_hook(data.img_blank->mlx, &display_game, &data);
	mlx_loop(data.img_blank->mlx);
}
