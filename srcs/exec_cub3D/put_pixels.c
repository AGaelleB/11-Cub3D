/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:51:26 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/28 15:06:08 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_pixel(t_data *data, int x, int y, int C_or_F)
{
	char	*dest;

	if (x < 0 || y < 0 || y > HEIGHT - 1 || x > WIDTH - 1)
		return ;
	dest = data->img_blank->data_addr + (y * data->img_blank->size_line) + x
		* (data->img_blank->bits_per_pixels / 8);
	*(int *)dest = C_or_F;
}

int	get_rgb(t_data *data, int C_or_F)
{
	int	color;

	if (C_or_F == 0)
		color = ((data->colors_ceiling.red & MAX_COLOR_VALUE) << 16)
			|((data->colors_ceiling.green & MAX_COLOR_VALUE) << 8)
			|(data->colors_ceiling.blue & MAX_COLOR_VALUE);
	else if (C_or_F == 1)
		color = ((data->colors_floor.red & MAX_COLOR_VALUE) << 16)
			|((data->colors_floor.green & MAX_COLOR_VALUE) << 8)
			|(data->colors_floor.blue & MAX_COLOR_VALUE);
	return (color);
}

int	get_color(t_data *data, t_img *texture)
{
	char	*dest;

	if (data->game->texture_x < 0 || data->game->texture_y < 0
		|| data->game->texture_y > HEIGHT - 1
		|| data->game->texture_x > WIDTH - 1)
		return (0);
	dest = texture->data_addr + (data->game->texture_y
			* texture->size_line + data->game->texture_x
			* (texture->bits_per_pixels / 8));

	// printf("Texture X: %d, Texture Y: %d\n", data->game->texture_x, data->game->texture_y);
	// printf("Size Line: %d, Bits Per Pixel: %d\n", texture->size_line, texture->bits_per_pixels);
	// printf("Data Addr: %p\n", texture->data_addr);

	if (dest == NULL) {
		// printf("Dest is NULL\n");
		return 0;
	}

	return (*(int *)dest); // (put_pixels.c:52)
}


/* 
	on dirait que qd j ai un segfault c est paceque la touche w reste enfoncee 
	et ne se reinit pas apres le changement de touche 
	
	==320880== Process terminating with default action of signal 11 (SIGSEGV)
	==320880==  Access not within mapped region at address 0x528E088
	==320880==    at 0x10FE6E: get_color (put_pixels.c:53)
	==320880==    by 0x10F30D: draw_vertical_column (display_pixels.c:69)
	==320880==    by 0x10ED0B: display_game (display_game.c:43)
	==320880==    by 0x116B4C: mlx_loop (in /home/gaelle/Documents/Stud-42/11-Cub3D/cub3D)
	==320880==    by 0x10EBD7: exec_game (cub3d.c:29)
	==320880==    by 0x10EA87: main (main.c:40)
	==320880==  If you believe this happened as a result of a stack
	==320880==  overflow in your program's main thread (unlikely but
	==320880==  possible), you can try to increase the size of the
	==320880==  main thread stack using the --main-stacksize= flag.
	==320880==  The main thread stack size used in this run was 8388608.
	==320880== 
	==320880== HEAP SUMMARY:
	==320880==     in use at exit: 79,823 bytes in 166 blocks
	==320880==   total heap usage: 16,084 allocs, 15,918 frees, 1,549,225 bytes allocated
 */