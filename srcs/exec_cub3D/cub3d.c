/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:39:45 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/26 10:56:26 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	exec_game(t_parser *parser)
{
	t_data	data;

	init_data_game(&data, parser);
	// print_stuff_before_init(&data); // PRINT
	if (init_windows(&data))
		return ;
	init_textures_adress(&data); // deplace ici sinon bug car init_mlx dans init_windows
	// print_stuff_after_init(&data); // PRINT
	mlx_key_hook(data.img_blank->window, handle_key_esc, &data);
	mlx_hook(data.img_blank->window, 17, 0, close_window, &data);
	mlx_loop_hook(data.img_blank->mlx, &display_game, &data);
	mlx_loop(data.img_blank->mlx);
}
