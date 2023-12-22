/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:14:28 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/22 10:03:58 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_read_and_join(char *map)
{
	char	*s1;
	char	*s2;
	char	*temp;
	int		fd;

	fd = open(map, O_RDWR);
	if (fd < 0)
	{
		err("Error\nInvalid read\n");
		return (NULL);
	}
	s1 = ft_calloc(sizeof(char), 1);
	if (s1 == NULL)
		return (NULL);
	s2 = get_next_line(fd);
	if (!s2)
	{
		err("Error\nThe file is empty\n");
		free(s1);
		return (NULL);
	}
	while (s2)
	{
		temp = s1;
		s1 = ft_strjoin(temp, s2);
		free(temp);
		free(s2);
		s2 = get_next_line(fd);
	}
	close(fd);
	return (s1);
}

int	find_map_start(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && j < 6)
	{
		if (!ft_strncmp_cub3d(&str[i], "NO ", 3) || !ft_strncmp_cub3d(&str[i], "SO ", 3))
			j++;
		if (!ft_strncmp_cub3d(&str[i], "EA ", 3) || !ft_strncmp_cub3d(&str[i], "WE ", 3))
			j++;
		if (!ft_strncmp_cub3d(&str[i], "F ", 2) || !ft_strncmp_cub3d(&str[i], "C ", 2))
			j++;
		i++;
	}
	while (str[i] && str[i] != '\n')
		i++;
	while (str[i] == '\n')
		i++;
	return (i);
}

int	check_empty_line_at_end(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i] == '\0' && str[i - 1] == '\n')
	{
		err("Error\nEmpty line at the end of the map\n");
		free(str);
		exit(1);
	}
	return (0);
}

int	check_empty_line_in_map(char *str)
{
	int	i;

	i = find_map_start(str) - 1;
	while (i > 0 && str[++i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			err("Error\nEmpty line in map\n");
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			free(str);
			exit(1);
		}
	}
	return (0);
}

int	check_no_map(char *str)
{
	int	i;

	i = find_map_start(str) - 1;
	while (i > 0 && str[++i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			err("Error\nEmpty line in map\n");
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			free(str);
			exit(1);
		}
	}
	return (0);
}

void	ft_put_in_tab(char *map, t_parser *parser)
{
	char	*str;

	str = ft_read_and_join(map);
	if (str == NULL)
		exit(1);
	check_empty_line_in_map(str);
	check_empty_line_at_end(str);
	parser->tab = ft_split(str, '\n');
	if (parser->tab == NULL)
		return ;
	free(str);
}
