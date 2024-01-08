/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:39:45 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/06 15:32:55 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#include <X11/X.h>
#include <sys/time.h>

int	close_window(t_data *data)
{
	free_all(data);
	exit(0);
}

int	mouse_move(int x, int y, t_data *data)
{
	int	EDGE_THRESHOLD;

	EDGE_THRESHOLD = (WIDTH / 3);
	mlx_mouse_get_pos(data->img_blank->mlx, data->img_blank->window, &x, &y);
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
	{
		data->keys.mouse_rot_right = 0;
		data->keys.mouse_rot_left = 0;
	}
	else if ((x > (WIDTH - EDGE_THRESHOLD)) && !(x >= WIDTH))
	{
		data->keys.mouse_rot_right = 1;
		data->keys.mouse_rot_left = 0;
	}
	else if ((x < EDGE_THRESHOLD) && (x > 0))
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

int	mouse_move_out(int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	data->keys.mouse_rot_right = 0;
	data->keys.mouse_rot_left = 0;
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
	mlx_hook(data.img_blank->window, MotionNotify, PointerMotionMask, mouse_move, &data);
	mlx_hook(data.img_blank->window, KeyRelease, KeyReleaseMask, key_release, &data);
	mlx_hook(data.img_blank->window, 17, 0, close_window, &data);
	mlx_loop_hook(data.img_blank->mlx, &display_game, &data);
	mlx_loop(data.img_blank->mlx);
}
