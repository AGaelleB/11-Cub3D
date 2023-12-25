/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:39:45 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/25 13:01:01 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_data_game(t_data *data, t_parser *parser)
{
	data->valid_map = parser->map;
	data->valid_param = parser->tab;
	init_colors(data);
	init_filename_textures(data);
	init_pos_player(data);
	// data->texture_NO->data_addr =
	// data->texture_SO->data_addr =
	// data->texture_WE->data_addr =
	// data->texture_EA->data_addr =
}

void	print_stuff(t_data	*data)
{
	printf("colors_floor rgb = %d,%d,%d \n", data->colors_floor.red, data->colors_floor.green, data->colors_floor.blue);
	printf("colors_ceiling rgb = %d,%d,%d \n\n", data->colors_ceiling.red, data->colors_ceiling.green, data->colors_ceiling.blue);
	
	printf("filename NO = %s\n", data->texture_NO->filename);
	printf("filename SO = %s\n", data->texture_SO->filename);
	printf("filename WE = %s\n", data->texture_WE->filename);
	printf("filename EA = %s\n\n", data->texture_EA->filename);

	printf("pos_player_x = %d\n", data->pos_player_x);
	printf("pos_player_y = %d\n\n", data->pos_player_y);

	// printf("texture north = %s\n", data->texture_NO->data_addr);
	// printf("texture south = %s\n", data->texture_SO->data_addr);
	// printf("texture west = %s\n", data->texture_WE->data_addr);
	// printf("texture east = %s\n\n", data->texture_EA->data_addr);
	
}

void	exec_game(t_parser *parser)
{
	t_data	data;

	init_data_game(&data, parser);
	print_stuff(&data); //////////////////////////////////////////////////////
	if (init_windows(&data))
		return ;

	// Gérer les appuis de touches
	mlx_key_hook(data.img->window, handle_key_esc, &data);

	// Gérer la fermeture de la fenêtre
	mlx_hook(data.img->window, 17, 0, close_window, &data);
	
	mlx_loop(data.img->mlx);
}