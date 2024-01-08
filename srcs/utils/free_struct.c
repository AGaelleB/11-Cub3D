/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:07:38 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/05 17:09:32 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_texture_filename_no_so(t_data *data)
{
	if (data->texture_NO)
	{
		free(data->texture_NO->filename);
		if (data->texture_NO->img_ptr)
			mlx_destroy_image(data->img_blank->mlx, data->texture_NO->img_ptr);
		free(data->texture_NO);
	}
	if (data->texture_SO)
	{
		free(data->texture_SO->filename);
		if (data->texture_SO->img_ptr)
			mlx_destroy_image(data->img_blank->mlx, data->texture_SO->img_ptr);
		free(data->texture_SO);
	}
	
}

void	free_texture_filename_ea_we(t_data *data)
{
	if (data->texture_EA)
	{
		free(data->texture_EA->filename);
		if (data->texture_EA->img_ptr)
			mlx_destroy_image(data->img_blank->mlx, data->texture_EA->img_ptr);
		free(data->texture_EA);
	}
	if (data->texture_WE)
	{
		free(data->texture_WE->filename);
		if (data->texture_WE->img_ptr)
			mlx_destroy_image(data->img_blank->mlx, data->texture_WE->img_ptr);
		free(data->texture_WE);
	}
}

void	free_all(t_data *data)
{
	free_texture_filename_no_so(data);
	free_texture_filename_ea_we(data);
	free_tab(data->valid_map);
	free_tab(data->valid_param);
	free(data->game);
	if (data->img_blank->img_ptr)
		mlx_destroy_image(data->img_blank->mlx, data->img_blank->img_ptr);
	mlx_destroy_window(data->img_blank->mlx, data->img_blank->window); 
	mlx_destroy_display(data->img_blank->mlx);
	if (data->img_blank->mlx)
		free(data->img_blank->mlx);
	free(data->img_blank);
}
