/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_filename.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:55:15 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/28 15:43:14 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*trim_texture_path(char *str)
{
	int i = 2;
	ft_memset(str, ' ', 2);
	while (str[i] == ' ' || str[i] == '\t')
	{
		i++;
	}
	return (trim_start(str));
}


int	init_textures_filename_north_and_south(t_data *data)
{
	int		i;
	char	*texture_path;

	i = 0;
	while (data->valid_param[i])
	{
		if (ft_strncmp_cub3d(data->valid_param[i], "NO ", 3) == 0)
		{
			texture_path = trim_texture_path(data->valid_param[i]);
			// data->texture_NO = malloc(sizeof(t_img));
			data->texture_NO = ft_calloc(1, sizeof(t_img));
			if (!data->texture_NO)
				return (1);
			// ft_memset(data->texture_NO, 0, sizeof(t_img)); /////// test
			data->texture_NO->filename = ft_strdup(texture_path);
		}
		else if (ft_strncmp_cub3d(data->valid_param[i], "SO ", 3) == 0)
		{
			texture_path = trim_texture_path(data->valid_param[i]);
			// data->texture_SO = malloc(sizeof(t_img));
			data->texture_SO = ft_calloc(1, sizeof(t_img));
			if (!data->texture_SO)
				return (1);
			// ft_memset(data->texture_SO, 0, sizeof(t_img)); /////// test
			data->texture_SO->filename = ft_strdup(texture_path);
		}
		i++;
	}
	return (0);
}

int	init_textures_filename_west_and_east(t_data *data)
{
	int		i;
	char	*texture_path;

	i = 0;
	while (data->valid_param[i])
	{
		if (ft_strncmp_cub3d(data->valid_param[i], "WE ", 3) == 0)
		{
			texture_path = trim_texture_path(data->valid_param[i]);
			// data->texture_WE = malloc(sizeof(t_img));
			data->texture_WE = ft_calloc(1, sizeof(t_img));
			if (!data->texture_WE)
				return (1);
			// ft_memset(data->texture_WE, 0, sizeof(t_img)); /////// test
			data->texture_WE->filename = ft_strdup(texture_path);
		}
		else if (ft_strncmp_cub3d(data->valid_param[i], "EA ", 3) == 0)
		{
			texture_path = trim_texture_path(data->valid_param[i]);
			// data->texture_EA = malloc(sizeof(t_img));
			data->texture_EA = ft_calloc(1, sizeof(t_img));
			if (!data->texture_EA)
				return (1);
			// ft_memset(data->texture_EA, 0, sizeof(t_img)); /////// test
			data->texture_EA->filename = ft_strdup(texture_path);
		}
		i++;
	}
	return (0);
}

int	init_textures_filename(t_data *data)
{
	init_textures_filename_north_and_south(data);
	init_textures_filename_west_and_east(data);

	
	// printf("Texture X: %d, Texture Y: %d\n", data->game->texture_x, data->game->texture_y);
	// printf("Size Line: %d, Bits Per Pixel: %d\n", texture->size_line, texture->bits_per_pixels);
	// printf("Data Addr: %p\n", texture->data_addr);
	
	return (0);
}
