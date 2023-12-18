/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_floor_and_ceiling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:57:39 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/18 14:56:21 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_error_set_color(char *dest, t_parser *parser, char **tab_color)
{
	err("Error\nBad color\n");
	free(dest);
	ft_free_tab(parser->tab);
	ft_free_tab(tab_color);
	exit(1);
}

int	check_tab_color(t_parser *parser, char *dest, char **tab_color)
{
	int		i;
	int		j;

	i = 0;
	while (tab_color[i])
	{
		j = 0;
		while (tab_color[i][j])
		{
			if (!ft_isdigit(tab_color[i][j]))
				free_error_set_color(dest, parser, tab_color);
			j++;
		}
		if (ft_atoi(tab_color[i]) < 0 || ft_atoi(tab_color[i]) > 255)
			free_error_set_color(dest, parser, tab_color);
		i++;
	}
	if (i != 3)
		free_error_set_color(dest, parser, tab_color);
	return (0);
}

int	check_error_numbers(t_parser *parser, char *str)
{
	char	*dest;
	char	**tab_color;
	int		i;

	i = 0;
	while (str[i] && !ft_isdigit(str[i]))
		i++;
	dest = copy_from(str, str[i]);
	tab_color = ft_split(dest, ',');
	i = 0;
	check_tab_color(parser, dest, tab_color);
	free(dest);
	ft_free_tab(tab_color);
	return (0);
}

int	set_color(t_parser *parser, char *line,
	char *letter, int *flag)
{
	if (ft_strncmp_cub3d(line, letter, 2) == 0)
	{
		if (!validate_line(line))
		{
			err("Error\nBad color\n");
			ft_free_tab(parser->tab);
			exit(1);
		}
		if (check_error_numbers(parser, line) == 0)
			(*flag)++;
	}
	return (1);
}

int	verif_floor_and_ceiling(t_parser *parser)
{
	int	i;

	i = 0;
	while (parser->tab[i])
	{
		if (!set_color(parser, parser->tab[i], "F ", &parser->flag_floor)
			|| !set_color(parser, parser->tab[i], "C ", &parser->flag_ceiling))
			return (0);
		i++;
	}
	if (parser->flag_floor == 1 && parser->flag_ceiling == 1)
		return (0);
	else
	{
		ft_free_tab(parser->tab);
		return (err("Error\nBad color\n"));
	}
	return (0);
}