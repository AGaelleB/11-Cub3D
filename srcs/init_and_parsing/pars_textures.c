/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:53:17 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/18 17:06:40 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_error_textures(t_parser *parser, char *str)
{
	char	*dest;

	dest = copy_from(str, 't');
	if (access(dest, F_OK) != 0)
	{
		err("Error\nBad texture\n");
		free(dest);
		ft_free_tab(parser->tab);
		exit(1);
	}
	free(dest);
	return (0);
}

int	validate_line(char *line)
{
	char	**split_line;
	int		count;

	split_line = ft_split(line, ' ');
	count = 0;
	while (split_line[count])
		count++;
	if (count != 2)
	{
		ft_free_tab(split_line);
		return (0);
	}
	ft_free_tab(split_line);
	return (1);
}

int	set_texture(t_parser *parser, char *line,
	char *cardinal_point, int *flag)
{
	if (ft_strncmp_cub3d(line, cardinal_point, 3) == 0)
	{
		if (!validate_line(line))
		{
			err("Error\nBad texture\n");
			ft_free_tab(parser->tab);
			exit(1);
		}
		if (check_error_textures(parser, line) == 0)
			(*flag)++;
	}
	return (1);
}

int	verif_wall(t_parser *parser)
{
	int	i;

	i = 0;
	while (i < parser->index_start_map)
	{
		if (!set_texture(parser, parser->tab[i], "NO ", &parser->flag_north)
			|| !set_texture(parser, parser->tab[i], "SO ", &parser->flag_south)
			|| !set_texture(parser, parser->tab[i], "WE ", &parser->flag_west)
			|| !set_texture(parser, parser->tab[i], "EA ", &parser->flag_east))
			return (0);
		i++;
	}
	if (parser->flag_north == 1 && parser->flag_south == 1
		&& parser->flag_west == 1 && parser->flag_east == 1)
		return (0);
	else
	{
		ft_free_tab(parser->tab);
		return (err("Error\nBad texture\n"));
	}
	return (0);
}

int	master_verif_textures(char *map, t_parser *parser)
{
	ft_put_in_tab(map, parser);
	parser->index_start_map = find_start_of_map(parser);
	if (verif_wall(parser) != 0)
		return (1);
	if (verif_floor_and_ceiling(parser) != 0)
		return (1);
	return (0);
}

/*
// print tab
int i = 0;
	while(parser->tab[i])
	{
		printf("%s\n", parser->tab[i]);
		i++;
	}
*/
