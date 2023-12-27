/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:40:03 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/27 12:27:30 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_parser	init_data_parsing(void)
{
	t_parser	parser;

	parser.tab = NULL;
	parser.map = NULL;
	parser.index_start_map = 0;
	parser.flag_north = false;
	parser.flag_south = false;
	parser.flag_east = false;
	parser.flag_west = false;
	parser.flag_floor = false;
	parser.flag_ceiling = false;
	parser.map_width = 0;
	parser.map_height = 0;
	return (parser);
}

int	main(int ac, char **av)
{
	t_parser	parser;

	parser = init_data_parsing();
	if (master_parsing(ac, av, &parser) != 0)
		return (1);
	exec_game(&parser);
	free_tab(parser.tab);
	free_tab(parser.map);
	return (0);
}

/*
	sefault si je fonce direct dans un mur je peux plus bouger 

	==296468== Process terminating with default action of signal 2 (SIGINT)
	==296468==    at 0x10F0A0: draw_vertical_column (display_pixels.c:56)
	==296468==    by 0x10EC4D: display_game (display_game.c:27)
	==296468==    by 0x1167CC: mlx_loop (in /home/gaelle/Documents/Stud-42/11-Cub3D/cub3D)
	==296468==    by 0x10EBC2: exec_game (cub3d.c:32)
	==296468==    by 0x10EA87: main (main.c:40)

 */