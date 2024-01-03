/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:54:32 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/03 15:40:22 by abonnefo         ###   ########.fr       */
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
	init_pos_directions(data);
	init_key_press(data);
}
