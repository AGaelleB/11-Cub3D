/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:02:00 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/22 10:15:06 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	verif_zero_close(t_parser *parser)
{
	int	i;
	int	j;

	i = 0;
	while (i < parser->map_height)
	{
		j = 0;
		while ((j < parser->map_width) && parser->map[i][j])
		{
			if (parser->map[i][j] == '0')
			{
				if (parser->map[i][0] == '0')
					return (1);
				if (i > 0 && (parser->map[i - 1][j] == ' '
					|| !parser->map[i - 1][j]))
					return (1);
				if (i < parser->map_height - 1 && (parser->map[i + 1][j] == ' '
					|| !parser->map[i + 1][j]))
					return (1);
				if (j > 0 && parser->map[i][j - 1] == ' ')
					return (1);
				if (j < parser->map_width - 1 && parser->map[i][j + 1] == ' ')
					return (1);
			}
			j++;
		}
		if (parser->map[i][--j] == '0')
			return (1);
		i++;
	}
	return (0);
}

int	verif_space_close(t_parser *parser)
{
	int	i;
	int	j;
	int	row_length;

	i = 0;
	while (i < parser->map_height)
	{
		j = 0;
		row_length = ft_strlen(parser->map[i]);
		while (j < row_length)
		{
			if (parser->map[i][j] == ' ')
			{
				if ((i > 0) && (j < ft_strlen(parser->map[i - 1]))
					&& ((parser->map[i - 1][j] != '1')
					&& (parser->map[i - 1][j] != ' ')))
					return (1);
				if ((i < parser->map_height - 1)
					&& (j < ft_strlen(parser->map[i + 1]))
					&& ((parser->map[i + 1][j] != '1')
					&& (parser->map[i + 1][j] != ' ')))
					return (1);
				if ((j > 0 && parser->map[i][j - 1])
					&& (parser->map[i][j - 1] != '1'
					&& (parser->map[i][j - 1] != ' ')))
					return (1);
				if ((j < parser->map_width - 1) && (parser->map[i][j + 1])
					&& ((parser->map[i][j + 1] != '1')
					&& (parser->map[i][j + 1] != ' ')))
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

int	convert_tab_in_map(t_parser *parser)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (parser->tab[i])
		i++;
	parser->map = malloc(sizeof(char *) * (i + 1));
	if (parser->map == NULL)
		return (1);
	tmp = parser->index_start_map;
	i = 0;
	while (parser->tab[tmp])
	{
		j = 0;
		if ((ft_strlen(parser->tab[tmp]) == 0)
			|| is_all_space(parser->tab[tmp]))
		{
			while (i > 0)
				free(parser->map[--i]);
			free(parser->map);
			return (1);
		}
		parser->map[i] = malloc(sizeof(char) * (ft_strlen(parser->tab[tmp]) + 1));
		if (parser->map[i] == NULL)
		{
			while (i > 0)
				free(parser->map[--i]);
			free(parser->map);
			return (1);
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
	return (0);
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
	if (convert_tab_in_map(parser))
	{
		free_tab(parser->tab);
		return (err("Error\nEmpty line in the map\n"));
	}
	// print_tab(parser->map);
	parms_map_size(parser);
	if (verif_char(parser->map))
	{
		free_tab(parser->tab);
		free_tab(parser->map);
		return (err("Error\nInvalid char in the map\n"));
	}
	if (verif_zero_close(parser))
	{
		free_tab(parser->tab);
		free_tab(parser->map);
		return (err("Error\nA zero isn't closed\n"));
	}
	if (verif_space_close(parser))
	{
		free_tab(parser->tab);
		free_tab(parser->map);
		return (err("Error\nThe map isn't closed\n"));
	}
	return (0);
}
