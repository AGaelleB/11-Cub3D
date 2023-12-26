/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_filename.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:55:15 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/25 18:02:15 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_textures_filename_north_and_south(t_data *data)
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

int	init_textures_filename_west_and_east(t_data *data)
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

int	init_textures_filename(t_data *data)
{
	init_textures_filename_north_and_south(data);
	init_textures_filename_west_and_east(data);
	return (0);
}
