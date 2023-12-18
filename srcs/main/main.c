/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:40:03 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/18 10:09:40 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_parser	init_data_parsing(void)
{
	t_parser	parser;

	parser.tab = NULL;
	parser.flag_north = false;
	parser.flag_south = false;
	parser.flag_east = false;
	parser.flag_west = false;
	parser.flag_floor = false;
	parser.flag_ceiling = false;
	return (parser);
}

int	main(int ac, char **av)
{
	t_parser	parser;

	parser = init_data_parsing();
	if (master_parsing(ac, av, &parser) != 0)
		return (1);
	// exec_game();
	return (0);
}