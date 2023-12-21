/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:40:13 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/21 18:36:17 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	verif_directory(char *str)
{
	int	fd;

	fd = open(str, O_DIRECTORY);
	if (fd != -1)
	{
		err("Error\n");
		err(str);
		err(" is a directory\n");
		return (1);
	}
	fd = open(str, O_RDONLY);
	if ((fd < 0))
	{
		perror(str);
		return (1);
	}
	close(fd);
	return (0);
}

int	verif_extensions(char *str, char **av)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i -= 4;
	if (str[i] == '.' && str[i + 1] == 'c' && str[i + 2] == 'u'
		&& str[i + 3] == 'b')
		return (0);
	err("Error\n");
	err(av[1]);
	err(" isn't a .cub file\n");
	return (1);
}

int	master_verif_args(int ac, char **av)
{
	if (ac != 2)
		return (err("Error\nInvalid number of arguments\n"));
	if (verif_extensions(av[1], av) != 0)
		return (1);
	if (verif_directory(av[1]) != 0)
		return (1);
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
