/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:40:03 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/28 10:52:49 by abonnefo         ###   ########.fr       */
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
	ATTENTION SEGFAULT SI :
	
	- F and C dans la map ne se trouvent pas en dernier argument 









	sefault si je fais, gauche et que je me prend direct le mur d en face, je peux plus bouger 

	==296468== Process terminating with default action of signal 2 (SIGINT)
	==296468==    at 0x10F0A0: draw_vertical_column (display_pixels.c:56)
	==296468==    by 0x10EC4D: display_game (display_game.c:27)
	==296468==    by 0x1167CC: mlx_loop (in /home/gaelle/Documents/Stud-42/11-Cub3D/cub3D)
	==296468==    by 0x10EBC2: exec_game (cub3d.c:32)
	==296468==    by 0x10EA87: main (main.c:40)


	./cub3D maps/test_gaga.cub
	[1]    328558 segmentation fault (core dumped)  ./cub3D maps/test_gaga.cub
	
	==328651== Process terminating with default action of signal 11 (SIGSEGV)
	==328651==  Access not within mapped region at address 0x0
	==328651==    at 0x10FE91: get_color (put_pixels.c:59)
	==328651==    by 0x10F20C: draw_vertical_column (display_pixels.c:63)
	==328651==    by 0x10ED0B: display_game (display_game.c:61)
	==328651==    by 0x116BAC: mlx_loop (in /home/gaelle/Documents/Stud-42/11-Cub3D/cub3D)
	==328651==    by 0x10EBD7: exec_game (cub3d.c:29)
	==328651==    by 0x10EA87: main (main.c:40)
	==328651==  If you believe this happened as a result of a stack
	==328651==  overflow in your program's main thread (unlikely but
	==328651==  possible), you can try to increase the size of the
	==328651==  main thread stack using the --main-stacksize= flag.
	==328651==  The main thread stack size used in this run was 8388608.



 */