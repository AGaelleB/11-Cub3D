/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:40:13 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/08 11:01:54 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	master_verif_args(int ac, char **av)
{
	if (ac != 2)
		return (err("Error\nBad parsing\n"));
	(void)ac;
	if (verif_extensions(av[1], av) != 0)
		return (1);
	if (verif_directory(av[1]) != 0)
		return (1);
	return (0);
}

int	master_verif_textures(char *map, t_parser *parser)
{
	ft_put_in_tab(map, parser);
	parser->index_start_map = find_start_of_map(parser);
	if (verif_parameters(parser) != 0)
		return (1);
	if (verif_textures_wall(parser) != 0)
		return (1);
	if (verif_floor_and_ceiling(parser) != 0)
		return (1);
	return (0);
}

int	master_verif_maps(t_parser *parser)
{
	if (convert_tab_in_map(parser))
	{
		free_tab(parser->tab);
		return (err("Error\nBad parsing\n"));
	}
	parms_map_size(parser);
	if (verif_char(parser->map) || verif_pos_player(parser))
	{
		free_tab(parser->tab);
		free_tab(parser->map);
		return (err("Error\nBad parsing\n"));
	}
	if (verif_zero_close(parser))
	{
		free_tab(parser->tab);
		free_tab(parser->map);
		return (err("Error\nBad parsing\n"));
	}
	if (verif_space_close(parser))
	{
		free_tab(parser->tab);
		free_tab(parser->map);
		return (err("Error\nBad parsing\n"));
	}
	return (0);
}

int	master_parsing(int ac, char **av, t_parser *parser)
{
	if (master_verif_args(ac, av) != 0)
		return (1);
	if (master_verif_textures(av[1], parser) != 0)
		return (1);
	if (master_verif_maps(parser) != 0)
		return (1);
	return (0);
}