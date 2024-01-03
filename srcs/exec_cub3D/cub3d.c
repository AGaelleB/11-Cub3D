/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:39:45 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/03 15:02:11 by abonnefo         ###   ########.fr       */
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
	int	previous_x;

	(void)y;
	data->game->mouse_x = WIDTH / 2;
	previous_x = data->game->mouse_x;
	data->game->mouse_x = x;
	if (data->game->mouse_x > previous_x)
		data->game->cam_mouse_right = 1;
	else if (data->game->mouse_x < previous_x)
		data->game->cam_mouse_left = 1;
	else
	{
		data->game->cam_mouse_left = 0;
		data->game->cam_mouse_right = 0;
	}
	return (0);
}

static int	get_keyboard_plus_entry(int keycode)
{
	int	i;
	int	keyboard_plus[6];

	keyboard_plus[0] = 119;
	keyboard_plus[1] = 97;
	keyboard_plus[2] = 11;
	keyboard_plus[3] = 22;
	keyboard_plus[4] = 3;
	keyboard_plus[5] = KEY_RIGHT;
	i = -1;
	while (++i < 6)
	{
		if (keyboard_plus[i] == keycode)
			return (i);
	}
	return (-1);
}

static int	get_keyboard_minus_entry(int keycode)
{
	int	i;
	int	keyboard_minus[6];

	keyboard_minus[0] = 119;
	keyboard_minus[1] = 97;
	keyboard_minus[2] = 11;
	keyboard_minus[3] = 22;
	keyboard_minus[4] = 3;
	keyboard_minus[5] = KEY_LEFT;
	i = -1;
	while (++i < 6)
	{
		if (keyboard_minus[i] == keycode)
			return (i);
	}
	return (-1);
}

void	set_move_player(t_data *data, int keycode, int value)
{
	int	key;

	key = get_keyboard_plus_entry(keycode);
	if (key > -1)
	{
		data->keys.keypressed[key] = value;
		return ;
	}
	key = get_keyboard_minus_entry(keycode);
	if (key > -1)
	{
		data->keys.keypressed[key] = -1 * value;
		return ;
	}
}

int	mouse_move_hook_out(int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	data->keys.keypressed[2] = 0;
	data->keys.keypressed[3] = 0;
	data->keys.keypressed[4] = 0;
	return (0);
}

static int	catch_mickey(int slice)
{
	int	mickey_mouse[8];

	mickey_mouse[0] = 3;
	mickey_mouse[1] = 22;
	mickey_mouse[2] = 11;
	mickey_mouse[3] = 0;
	mickey_mouse[4] = 0;
	mickey_mouse[5] = 1;
	mickey_mouse[6] = 2;
	mickey_mouse[7] = 33;
	if (slice >= 0 && slice <= 7)
		return (mickey_mouse[slice]);
	return (33);
}

int	mouse_move_hook(int x, int y, t_data *data)
{
	int	slice;
	int	mickey;

	mlx_mouse_get_pos(data->img_blank->mlx, data->img_blank->window, &x, &y);
	slice = 8 * x / WIDTH;
	mouse_move_hook_out(x, y, data);
	mickey = catch_mickey(slice);
	if (mickey)
		set_move_player(data, mickey, 1);
	return (0);
}

void	exec_game(t_parser *parser)
{
	t_data	data;

	init_data_game(&data, parser);
	if (init_windows(&data))
		return ;
	init_textures_adress(&data); // deplace ici sinon bug car init_mlx dans init_windows
	mlx_hook(data.img_blank->window, KeyPress, KeyPressMask, key_press, &data);

	// mlx_hook(data.img_blank->window, MotionNotify, PointerMotionMask, &capture_mouse, &data);
	mlx_hook(data.img_blank->window, MotionNotify, PointerMotionMask, &mouse_move_hook, &data);
	mlx_hook(data.img_blank->window, LeaveNotify, PointerMotionMask, &mouse_move_hook_out, &data);

	mlx_hook(data.img_blank->window, KeyRelease, KeyReleaseMask, key_release, &data);
	mlx_hook(data.img_blank->window, 17, 0, close_window, &data);
	mlx_loop_hook(data.img_blank->mlx, &display_game, &data);
	mlx_loop(data.img_blank->mlx);
}
