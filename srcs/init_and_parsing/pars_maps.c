/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:13:48 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/19 13:06:38 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* 
	parsing des murs avec 1
	le reste a 0
	parsing 1 perso et 1 direction
 */

int	verif_space_close(t_parser *parser)
{
	int	i;
	int	j;

	i = 0;
	while (i < parser->map_height)
	{
		j = 0;
		while (j < parser->map_width)
		{
			if (parser->map[i][j] == ' ')
			{
				if (i > 0 && (parser->map[i - 1][j] != '1' && parser->map[i - 1][j] != ' '))
					return (1);
				if (i < parser->map_height - 1 && (parser->map[i + 1][j] != '1' && parser->map[i + 1][j] != ' '))
					return (1);
				if (j > 0 && (parser->map[i][j - 1] != '1' && parser->map[i][j - 1] != ' '))
					return (1);
				if (j < parser->map_width - 1 && (parser->map[i][j + 1] != '1' && parser->map[i][j + 1] != ' '))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	parms_map_size(t_parser *parser)
{
	int	i;
	int	j;
	int	max_width;
	int	cur_width;

	i = 0;
	max_width = 0;
	while (parser->map[i])
	{
		cur_width = 0;
		j = 0;
		while (parser->map[i][j])
			j++;
		cur_width = j;
		if (cur_width > max_width)
			max_width = cur_width;
		i++;
	}
	parser->map_height = i;
	parser->map_width = max_width;
}

void	convert_tab_in_map(t_parser *parser)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (parser->tab[i])
		i++;
	parser->map = malloc(sizeof(char*) * (i + 1));
	if (parser->map == NULL)
		return;
	tmp = parser->index_start_map;
	i = 0;
	while (parser->tab[tmp] && i < parser->map_height)
	{
		j = 0;
		parser->map[i] = malloc(sizeof(char) * (ft_strlen(parser->tab[tmp]) + 1));
		if (parser->map[i] == NULL)
		{
			while (i > 0)
				free(parser->map[--i]);
			free(parser->map);
			return;
		}
		while (parser->tab[tmp][j])
		{
			parser->map[i][j] = parser->tab[tmp][j];
			j++;
		}
		parser->map[i][j] = '\0';
		tmp++;
		i++;
	}
	parser->map[i] = NULL;
}

int	verif_char(char **tab)
{
	int	i;
	int	y;
	int	flag_pos;

	i = 0;
	flag_pos = 0;
	while (tab[i])
	{
		y = 0;
		while (tab[i][y])
		{
			if (tab[i][y] != ' ' && tab[i][y] != '0' && tab[i][y] != '1'
				&& tab[i][y] != 'N' && tab[i][y] != 'S' && tab[i][y] != 'E'
				&& tab[i][y] != 'W')
					return (1);
			if (tab[i][y] == 'N' || tab[i][y] == 'S'
				|| tab[i][y] == 'E' || tab[i][y] == 'W')
					flag_pos++;
			y++;
		}
		i++;
	}
	if (flag_pos != 1)
		return (1);
	return (0);
}

int	master_verif_maps(t_parser *parser)
{
	convert_tab_in_map(parser);
			print_tab(parser->map); ////////
	parms_map_size(parser);
			printf("with : %d\n", parser->map_height); ////////
			printf("height : %d\n", parser->map_height); ////////
	if (verif_char(parser->map))
		return (err("Error\nInvalid char in the map.\n"));
	if (verif_space_close(parser) != 0)
		return(err("Error\nThe map isn't closed.\n"));
	return (0);
}
