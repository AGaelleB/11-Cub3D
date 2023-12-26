/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:51:26 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/25 12:01:39 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	put_pixel(t_data *data, int x, int y, int color)
// {
// 	char	*dest;

// 	if (x < 0 || y < 0 || y > HEIGHT - 1 || x > WIDTH - 1)
// 		return ;
// 	dest = data->img->data_addr + (y * data->img->size_line) + x * (data->img->bits_per_pixels
// 			/ 8);
// 	*(int *)dest = color;
// }

// void	put_x10(t_data *data, int x, int y, int color) // pour la mini map
// {
// 	int	tmp_x;
// 	int	tmp_y;

// 	tmp_x = x;
// 	tmp_y = y;
// 	while (y < (tmp_y + 6))
// 	{
// 		x = tmp_x;
// 		while (x < (tmp_x + 6))
// 		{
// 			put_pixel(data, x, y, color);
// 			x++;
// 		}
// 		y++;
// 	}
// }