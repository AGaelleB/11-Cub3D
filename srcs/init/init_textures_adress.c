/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_adress.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 13:43:50 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/01 12:26:30 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_textures_adress_north(t_data *data)
{
	int	height;
	int	width;

	data->texture_NO->img_ptr = mlx_xpm_file_to_image(data->img_blank->mlx,
			data->texture_NO->filename, &width, &height);
	if (!data->texture_NO->img_ptr)
	{
		err("Error\nNorth mlx_xpm_file_to_image failed\n");
		return ;
	}
	data->texture_NO->data_addr = mlx_get_data_addr(data->texture_NO->img_ptr,
			&data->texture_NO->bits_per_pixels, &data->texture_NO->size_line,
			&data->texture_NO->endian);
}

void	init_textures_adress_south(t_data *data)
{
	int	height;
	int	width;

	data->texture_SO->img_ptr = mlx_xpm_file_to_image(data->img_blank->mlx,
			data->texture_SO->filename, &width, &height);
	if (!data->texture_SO->img_ptr)
	{
		err("Error\nSouth mlx_xpm_file_to_image failed\n");
		return ;
	}
	data->texture_SO->data_addr = mlx_get_data_addr(data->texture_SO->img_ptr,
			&data->texture_SO->bits_per_pixels, &data->texture_SO->size_line,
			&data->texture_SO->endian);
}

void	init_textures_adress_west(t_data *data)
{
	int	height;
	int	width;

	data->texture_WE->img_ptr = mlx_xpm_file_to_image(data->img_blank->mlx,
			data->texture_WE->filename, &width, &height);
	if (!data->texture_WE->img_ptr)
	{
		err("Error\nWest mlx_xpm_file_to_image failed\n");
		return ;
	}
	data->texture_WE->data_addr = mlx_get_data_addr(data->texture_WE->img_ptr,
			&data->texture_WE->bits_per_pixels, &data->texture_WE->size_line,
			&data->texture_WE->endian);
}

void	init_textures_adress_east(t_data *data)
{
	int	height;
	int	width;

	data->texture_EA->img_ptr = mlx_xpm_file_to_image(data->img_blank->mlx,
			data->texture_EA->filename, &width, &height);
	if (!data->texture_EA->img_ptr)
	{
		err("Error\nEast mlx_xpm_file_to_image failed\n");
		return ;
	}
	data->texture_EA->data_addr = mlx_get_data_addr(data->texture_EA->img_ptr,
			&data->texture_EA->bits_per_pixels, &data->texture_EA->size_line,
			&data->texture_EA->endian);
}

void	init_textures_adress(t_data *data)
{
	init_textures_adress_north(data);
	init_textures_adress_south(data);
	init_textures_adress_west(data);
	init_textures_adress_east(data);
}
