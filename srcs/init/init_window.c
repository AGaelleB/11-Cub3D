/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:55:31 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/26 22:04:21 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_key_press(t_data *data)
{
	data->keys.w = 0;
	data->keys.a = 0;
	data->keys.s = 0;
	data->keys.d = 0;
	// printf("init_key_press : KEY_W = %d\n", data->keys.w);
	// printf("init_key_press : KEY_A = %d\n", data->keys.a);
	// printf("init_key_press : KEY_S = %d\n", data->keys.s);
	// printf("init_key_press : KEY_D = %d\n", data->keys.d);
}

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
	data->img_blank->data_addr = mlx_get_data_addr(data->img_blank->img_ptr,
			&(data->img_blank->bits_per_pixels),
			&(data->img_blank->size_line), &(data->img_blank->endian));
	return (0);
}

