/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:40:03 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/28 16:50:39 by abonnefo         ###   ########.fr       */
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
	ATTENTION SEGFAULT :
	
	valgrind --leak-check=full ./cub3D maps/test_gaga.cub 
	==413307== Memcheck, a memory error detector
	==413307== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
	==413307== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
	==413307== Command: ./cub3D maps/test_gaga.cub
	==413307== 
	==413307== Invalid read of size 4
	==413307==    at 0x10FE6E: get_color (put_pixels.c:52)
	==413307==    by 0x10F2B9: draw_vertical_column (display_pixels.c:67)
	==413307==    by 0x10ED47: display_game (display_game.c:43)
	==413307==    by 0x116C5C: mlx_loop (in /home/gaelle/Documents/Stud-42/11-Cub3D/cub3D)
	==413307==    by 0x10EC13: exec_game (cub3d.c:33)
	==413307==    by 0x10EA87: main (main.c:40)
	==413307==  Address 0x528e0ac is not stack'd, malloc'd or (recently) free'd
	==413307== 
	==413307== 
	==413307== Process terminating with default action of signal 11 (SIGSEGV)
	==413307==  Access not within mapped region at address 0x528E0AC
	==413307==    at 0x10FE6E: get_color (put_pixels.c:52)
	==413307==    by 0x10F2B9: draw_vertical_column (display_pixels.c:67)
	==413307==    by 0x10ED47: display_game (display_game.c:43)
	==413307==    by 0x116C5C: mlx_loop (in /home/gaelle/Documents/Stud-42/11-Cub3D/cub3D)
	==413307==    by 0x10EC13: exec_game (cub3d.c:33)
	==413307==    by 0x10EA87: main (main.c:40)
	==413307==  If you believe this happened as a result of a stack
	==413307==  overflow in your program's main thread (unlikely but
	==413307==  possible), you can try to increase the size of the
	==413307==  main thread stack using the --main-stacksize= flag.
	==413307==  The main thread stack size used in this run was 8388608.
	==413307== 
	==413307== HEAP SUMMARY:
	==413307==     in use at exit: 66,984 bytes in 159 blocks
	==413307==   total heap usage: 15,592 allocs, 15,433 frees, 1,554,616 bytes allocated
	==413307== 
	==413307== LEAK SUMMARY:
	==413307==    definitely lost: 0 bytes in 0 blocks
	==413307==    indirectly lost: 0 bytes in 0 blocks
	==413307==      possibly lost: 0 bytes in 0 blocks
	==413307==    still reachable: 66,984 bytes in 159 blocks
	==413307==         suppressed: 0 bytes in 0 blocks
	==413307== Reachable blocks (those to which a pointer was found) are not shown.
	==413307== To see them, rerun with: --leak-check=full --show-leak-kinds=all
	==413307== 
	==413307== For lists of detected and suppressed errors, rerun with: -s
	==413307== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 1 from 1)
	[1]    413307 segmentation fault (core dumped)  valgrind --leak-check=full ./cub3D maps/test_gaga.cub
 */