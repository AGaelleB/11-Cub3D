/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos_dir_n_and_s.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:43:17 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/26 17:26:10 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
	Vecteurs de Direction (dir_x, dir_y)
	Ces vecteurs déterminent la direction dans laquelle le joueur regarde.
	Ils peuvent être dérivés de l'angle de vue du joueur. Par exemple :

	Pour le Nord (angle = 270°) :
		dir_x = cos(270°) = 0
		dir_y = sin(270°) = -1
	Pour le Sud (angle = 90°) :
		dir_x = cos(90°) = 0
		dir_y = sin(90°) = 1
	Pour l'Est (angle = 0°) :
		dir_x = cos(0°) = 1
		dir_y = sin(0°) = 0
	Pour l'Ouest (angle = 180°) :
		dir_x = cos(180°) = -1
		dir_y = sin(180°) = 0


	Vecteurs du Plan de la Caméra (plan_x, plan_y)
	Ces vecteurs déterminent le plan de la caméra perpendiculaire à la direction
	du regard, influençant le champ de vision. Pour un champ de vision de 66°,
	vous pouvez utiliser une valeur de 0.66. Le plan de la caméra doit être
	perpendiculaire à la direction du regard :

	Pour le Nord ou le Sud (dir_x = 0) :
		plan_x = 0.66 * dir_y
		plan_y = 0
	Pour l'Est ou l'Ouest (dir_y = 0) :
		plan_x = 0
		plan_y = 0.66 * -dir_x
 */

void	init_pos_dir_w_and_e(t_data *data)
{
	if (data->valid_map[(int)data->game->pos_x][(int)data->game->pos_y] == 'W')
	{
		data->game->dir_x = 0; // pas de mouvement sur l'axe x
		data->game->dir_y = -1; // mouvement négatif sur l'axe y
		data->game->plan_x = 0.66; // plan de caméra pour un champ de vision
		data->game->plan_y = 0; // pas de mouvement vertical sur le plan
	}
	else if (data->valid_map[(int)data->game->pos_x][(int)data->game->pos_y]
		== 'E')
	{
		data->game->dir_x = 0;
		data->game->dir_y = 1;
		data->game->plan_x = -0.66;
		data->game->plan_y = 0;
	}
	return ;
}

void	init_pos_dir_n_and_s(t_data *data)
{
	if (data->valid_map[(int)data->game->pos_x][(int)data->game->pos_y] == 'N')
	{
		data->game->dir_x = -1;
		data->game->dir_y = 0;
		data->game->plan_x = 0;
		data->game->plan_y = 0.66;
	}
	else if (data->valid_map[(int)data->game->pos_x][(int)data->game->pos_y]
		== 'S')
	{
		data->game->dir_x = 1;
		data->game->dir_y = 0;
		data->game->plan_x = 0;
		data->game->plan_y = -0.66;
	}
}

void	init_pos_directions(t_data *data)
{
	init_pos_dir_n_and_s(data);
	init_pos_dir_w_and_e(data);
}
