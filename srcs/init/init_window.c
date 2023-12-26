/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:55:31 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/25 18:03:29 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_windows(t_data *data)
{
	data->img_blank = malloc(sizeof(t_img));
	if (!data->img_blank)
		return (1);
	data->img_blank->mlx = mlx_init();
	if (!data->img_blank->mlx)
		err("Error\nInit mlx failed\n");
	data->img_blank->window = mlx_new_window(data->img_blank->mlx,
			WIDTH, HEIGHT, "cub3D");
	if (!data->img_blank->window)
		err("Error\nInit window failed\n");
	/* 	mlx_new_image pour creer l image qui recevra ensuite les pixels
	pensez a faire mlx_destroy_image a la fin */
	data->img_blank->img_ptr = mlx_new_image(data->img_blank->mlx,
			WIDTH, HEIGHT);
	return (0);
}

int	handle_key_esc(int key, t_data *data)
{
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(data->img_blank->mlx, data->img_blank->window);
		exit (0);
	}
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->img_blank->mlx, data->img_blank->window);
	exit (0);
}
