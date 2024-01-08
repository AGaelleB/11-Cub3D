/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_filename.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:55:15 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/08 10:36:24 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*trim_texture_path(char *str)
{
	int	i;

	i = 2;
	ft_memset(str, ' ', 2);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
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
			data->texture_north = ft_calloc(1, sizeof(t_img));
			if (!data->texture_north)
				return (1);
			data->texture_north->filename = ft_strdup(texture_path);
		}
		else if (ft_strncmp_cub3d(data->valid_param[i], "SO ", 3) == 0)
		{
			texture_path = trim_texture_path(data->valid_param[i]);
			data->texture_south = ft_calloc(1, sizeof(t_img));
			if (!data->texture_south)
				return (1);
			data->texture_south->filename = ft_strdup(texture_path);
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
			data->texture_west = ft_calloc(1, sizeof(t_img));
			if (!data->texture_west)
				return (1);
			data->texture_west->filename = ft_strdup(texture_path);
		}
		else if (ft_strncmp_cub3d(data->valid_param[i], "EA ", 3) == 0)
		{
			texture_path = trim_texture_path(data->valid_param[i]);
			data->texture_east = ft_calloc(1, sizeof(t_img));
			if (!data->texture_east)
				return (1);
			data->texture_east->filename = ft_strdup(texture_path);
		}
		i++;
	}
	return (0);
}

int	init_textures_filename(t_data *data)
{
	if (init_textures_filename_north_and_south(data) == 1)
	{
		free_all(data);
		exit(1);
	}
	if (init_textures_filename_west_and_east(data) == 1)
	{
		free_all(data);
		exit(1);
	}
	return (0);
}
