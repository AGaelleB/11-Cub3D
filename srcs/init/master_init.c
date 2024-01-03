/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:54:32 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/03 13:50:25 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_data_game(t_data *data, t_parser *parser)
{
	data->game = ft_calloc(1, sizeof(t_game));
	if (!data->game)
		return ;
	data->valid_map = parser->map;
	data->valid_param = parser->tab;
	init_colors(data);
	init_pos_player(data);
	data->game->pos_x = data->pos_player_x + 0.5; // ajouter 0.5 place le joueur au centre de la cellule de la grille, et non dans un coin
	data->game->pos_y = data->pos_player_y + 0.5;
	init_textures_filename(data);
	data->game->side = 0;
	data->keys.mouse_move = 0; // new
	init_pos_directions(data);
	init_key_press(data);
}

void	print_stuff_before_init(t_data	*data)
{
	printf("colors_floor rgb = %d,%d,%d \n", data->colors_floor.red,
		data->colors_floor.green, data->colors_floor.blue);
	printf("colors_ceiling rgb = %d,%d,%d \n\n", data->colors_ceiling.red,
		data->colors_ceiling.green, data->colors_ceiling.blue);
	printf("filename NO = %s\n", data->texture_NO->filename);
	printf("filename SO = %s\n", data->texture_SO->filename);
	printf("filename WE = %s\n", data->texture_WE->filename);
	printf("filename EA = %s\n\n", data->texture_EA->filename);
	printf("pos_player_x = %d\n", data->pos_player_x);
	printf("pos_player_y = %d\n\n", data->pos_player_y);
}

void	print_stuff_after_init(t_data	*data)
{
	printf("img_ptr north = %p\n", data->texture_NO->img_ptr);
	printf("img_ptr south = %p\n", data->texture_SO->img_ptr);
	printf("img_ptr west = %p\n", data->texture_WE->img_ptr);
	printf("img_ptr east = %p\n\n", data->texture_EA->img_ptr);
	printf("data_addr north = %p\n", data->texture_NO->data_addr);
	printf("data_addr south = %p\n", data->texture_SO->data_addr);
	printf("data_addr west = %p\n", data->texture_WE->data_addr);
	printf("data_addr east = %p\n\n", data->texture_EA->data_addr);
}
