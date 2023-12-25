/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:55:31 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/25 12:28:15 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_windows(t_data *data)
{
	data->img = malloc(sizeof(t_img));
	if (!data->img) 
		return (1);

	data->img->mlx = mlx_init();
	if (!data->img->mlx)
		err("Error\nInit mlx failed\n");
		
	data->img->window = mlx_new_window(data->img->mlx, WIDTH, HEIGHT, "cub3D"); 
	if (!data->img->window)
		err("Error\nInit window failedc\n");

	// mlx_new_image pour creer l image qui recevra ensuite les pixels
	// pensez a faire mlx_destroy_image a la fin
	data->img->img_blank = mlx_new_image(data->img->mlx, WIDTH, HEIGHT);

	// mlx_get_data_addr pour avoir l'adresse de l img vierge
	// et permet de manipuler directement les pixels de l image.
	data->img->data_addr = mlx_get_data_addr(data->img->img_blank, &(data->img->bits_per_pixels),
			&(data->img->size_line), &(data->img->endian));

	return (0);
}

int handle_key_esc(int key, t_data *data)
{
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(data->img->mlx, data->img->window);
		exit (0);
	}
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->img->mlx, data->img->window);
	exit (0);
}
