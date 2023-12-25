/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:40:03 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/24 19:16:32 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// t_data	init_data_game(void)
// {
// 	t_data	data;

	
// 	return (data);
// }


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
