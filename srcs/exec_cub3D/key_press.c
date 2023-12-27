/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:49:57 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/27 12:21:41 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(int key, t_data *data)
{
	// printf("%skey_press before KEY_W = %d%s\n", MAGENTA, data->keys.w, RESET);
	// printf("%skey_press before KEY_A = %d%s\n", MAGENTA, data->keys.a, RESET);
	// printf("%skey_press before KEY_S = %d%s\n", MAGENTA, data->keys.s, RESET);
	// printf("%skey_press before KEY_D = %d%s\n\n", MAGENTA, data->keys.d, RESET);
	if (key == KEY_W)
		data->keys.w = 1;
	if (key == KEY_A)
		data->keys.a = 1;
	if (key == KEY_S)
		data->keys.s = 1;
	if (key == KEY_D)
		data->keys.d = 1;
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(data->img_blank->mlx, data->img_blank->window);
		exit (0);
	}
	// printf("%skey_press after KEY_W = %d%s\n", MAGENTA, data->keys.w, RESET);
	// printf("%skey_press after KEY_A = %d%s\n", MAGENTA, data->keys.a, RESET);
	// printf("%skey_press after KEY_S = %d%s\n", MAGENTA, data->keys.s, RESET);
	// printf("%skey_press after KEY_D = %d%s\n\n", MAGENTA, data->keys.d, RESET);
	return (0);
}

int	key_release(int key, t_data *data)
{
	// printf("%skey_release before KEY_W = %d%s\n", GREEN, data->keys.w, RESET);
	// printf("%skey_release before KEY_A = %d%s\n", GREEN, data->keys.a, RESET);
	// printf("%skey_release before KEY_S = %d%s\n", GREEN, data->keys.s, RESET);
	// printf("%skey_release before KEY_D = %d%s\n\n", GREEN, data->keys.d, RESET);
	if (key == KEY_W)
		data->keys.w = 0;
	if (key == KEY_A)
		data->keys.a = 0;
	if (key == KEY_S)
		data->keys.s = 0;
	if (key == KEY_D)
		data->keys.d = 0;
	// printf("%skey_release after KEY_W = %d%s\n", GREEN, data->keys.w, RESET);
	// printf("%skey_release after KEY_A = %d%s\n", GREEN, data->keys.a, RESET);
	// printf("%skey_release after KEY_S = %d%s\n", GREEN, data->keys.s, RESET);
	// printf("%skey_release after KEY_D = %d%s\n\n", GREEN, data->keys.d, RESET);
	return (0);
}
