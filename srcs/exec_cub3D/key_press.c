/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:49:57 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/11 09:37:58 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	help_key_press(int key, t_data *data)
{
	if (key == KEY_W)
	{
		if (data->keys.s == 1)
		{
			data->keys.w = 0;
			data->keys.s = 0;
		}
		else
			data->keys.w = 1;
	}
	else if (key == KEY_S)
	{
		if (data->keys.w == 1)
		{
			data->keys.w = 0;
			data->keys.s = 0;
		}
		else
			data->keys.s = 1;
	}
}

int	key_press(int key, t_data *data)
{
	if (key == KEY_W)
		help_key_press(key, data);
	if (key == KEY_A)
		data->keys.a = 1;
	if (key == KEY_S)
		help_key_press(key, data);
	if (key == KEY_D)
		data->keys.d = 1;
	if (key == KEY_C)
		data->mouse_on = 1;
	if (key == KEY_V)
		data->mouse_on = 0;
	if (key == KEY_LEFT)
		data->keys.rot_left = 1;
	if (key == KEY_RIGHT)
		data->keys.rot_right = 1;
	if (key == KEY_ESCAPE)
	{
		free_all(data);
		exit(0);
	}
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == KEY_W)
		data->keys.w = 0;
	if (key == KEY_A)
		data->keys.a = 0;
	if (key == KEY_S)
		data->keys.s = 0;
	if (key == KEY_D)
		data->keys.d = 0;
	if (key == KEY_LEFT)
		data->keys.rot_left = 0;
	if (key == KEY_RIGHT)
		data->keys.rot_right = 0;
	return (0);
}
