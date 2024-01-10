/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:18:55 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/08 09:56:41 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_x10(t_data *data, int x, int y, int color)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = x;
	tmp_y = y;
	while (y < (tmp_y + 6))
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
			if (i == (int)data->game->pos_y
				&& index_tab == (int)data->game->pos_x)
				put_x10(data, x, y, COLOR_BLACK);
			else if (data->valid_map[index_tab][i]
				&& data->valid_map[index_tab][i] == '1')
				put_x10(data, x, y, COLOR_BRICK);
			x += 6;
			i++;
		}
		y += 6;
		index_tab++;
	}
}
