/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:55:15 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/25 12:02:20 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_filename_textures_north_and_south(t_data *data)
{
	int		i;
	char	*texture_path;

	i = 0;
	while (data->valid_param[i])
	{
		if (ft_strncmp_cub3d(data->valid_param[i], "NO ", 3) == 0)
		{
			texture_path = data->valid_param[i] + 3;
			data->texture_NO = malloc(sizeof(t_img));
			if (!data->texture_NO) 
				return (1);
			data->texture_NO->filename = ft_strdup(texture_path);
		}
		else if (ft_strncmp_cub3d(data->valid_param[i], "SO ", 3) == 0)
		{
			texture_path = data->valid_param[i] + 3;
			data->texture_SO = malloc(sizeof(t_img));
			if (!data->texture_SO) 
				return (1);
			data->texture_SO->filename = ft_strdup(texture_path);
		}
		i++;
	}
	return (0);
}

int	init_filename_textures_west_and_east(t_data *data)
{
	int		i;
	char	*texture_path;

	i = 0;
	while (data->valid_param[i])
	{
		if (ft_strncmp_cub3d(data->valid_param[i], "WE ", 3) == 0)
		{
			texture_path = data->valid_param[i] + 3;
			data->texture_WE = malloc(sizeof(t_img));
			if (!data->texture_WE) 
				return (1);
			data->texture_WE->filename = ft_strdup(texture_path);
		}
		else if (ft_strncmp_cub3d(data->valid_param[i], "EA ", 3) == 0)
		{
			texture_path = data->valid_param[i] + 3;
			data->texture_EA = malloc(sizeof(t_img));
			if (!data->texture_EA) 
				return (1);
			data->texture_EA->filename = ft_strdup(texture_path);
		}
		i++;
	}
	return (0);
}

int	init_filename_textures(t_data *data)
{
	init_filename_textures_north_and_south(data);
	init_filename_textures_west_and_east(data);
	return (0);
}
// void	init_texture(t_data *data)
// {
// 	int	height;
// 	int	width;

// 	// data->texture_NO->img_ptr = mlx_xpm_file_to_image(data->texture_EA->mlx,
// 		data->texture_NO->filename, &width, &height);
// 	if (!data->texture_NO->img_ptr)
// 		err("Error texture\n");
// 		data->texture_NO->data_addr = mlx_get_data_addr(data->texture_NO->img_ptr,
// 			data->texture_NO->bits_per_pixels, data->texture_NO->size_line,
// 				data->texture_NO->endian);
// }

/* 
	definir bits_per_pixels
	definir size_line
	definir endian


 */