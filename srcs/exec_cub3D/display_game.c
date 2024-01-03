/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:57:41 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/03 14:20:13 by abonnefo         ###   ########.fr       */
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
	if (data->keys.mouse_on_left == 1 && data->keys.mouse_move == 0) //new
		movement_player(data); //new
	if (data->keys.mouse_on_right == 1 && data->keys.mouse_move == 0) //new
		movement_player(data); //new
}

void	put_x10(t_data *data, int x, int y, int color)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = x;
	tmp_y = y;
	while (y < (tmp_y + 6)) // +6 ??
	{
		x = tmp_x;
		while (x < (tmp_x + 6))
		{
			put_pixel(data, x, y, color);
			x++;
		}
		y++;
	}
}

int	calcul_size_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	display_minimap(t_data *data, int x, int y)
{
	int	i;
	int	index_tab;
	int	len_tab;

	index_tab = 0;
	len_tab = calcul_size_tab(data->valid_map);
	while (index_tab < len_tab)
	{
		i = 0;
		x = 0;
		while (i < ft_strlen(data->valid_map[index_tab]))
		{
			if (i == (int)data->game->pos_y && index_tab == (int)data->game->pos_x)
				put_x10(data, x, y, COLOR_BLACK);
			else if (data->valid_map[index_tab][i] && data->valid_map[index_tab][i] == '1')
				put_x10(data, x, y, COLOR_BRICK);
			x += 6;
			i++;
		}
		y += 6;
		index_tab++;
	}
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
		draw_vertical_column(data, x, 0, data->game->line_height); ///////////
		x++;
	}
	// if (data->keys.mouse_move == 0)
	// 	mlx_mouse_move(data->img_blank->mlx, data->img_blank->window, WIDTH / 2, HEIGHT / 2);
	display_minimap(data, 0, 0);
	mlx_put_image_to_window(data->img_blank->mlx, data->img_blank->window,
		data->img_blank->img_ptr, 0, 0);
	//ici le R fait sa souris
	return (0);
}
