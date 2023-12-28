/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_filename.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:55:15 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/28 16:48:18 by abonnefo         ###   ########.fr       */
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
			data->texture_NO = ft_calloc(1, sizeof(t_img));
			if (!data->texture_NO)
				return (1);
			data->texture_NO->filename = ft_strdup(texture_path);
		}
		else if (ft_strncmp_cub3d(data->valid_param[i], "SO ", 3) == 0)
		{
			texture_path = trim_texture_path(data->valid_param[i]);
			data->texture_SO = ft_calloc(1, sizeof(t_img));
			if (!data->texture_SO)
				return (1);
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
			data->texture_WE = ft_calloc(1, sizeof(t_img));
			if (!data->texture_WE)
				return (1);
			data->texture_WE->filename = ft_strdup(texture_path);
		}
		else if (ft_strncmp_cub3d(data->valid_param[i], "EA ", 3) == 0)
		{
			texture_path = trim_texture_path(data->valid_param[i]);
			data->texture_EA = ft_calloc(1, sizeof(t_img));
			if (!data->texture_EA)
				return (1);
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
	return (0);
}
