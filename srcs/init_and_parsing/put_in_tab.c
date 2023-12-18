/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:14:28 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/18 11:14:57 by abonnefo         ###   ########.fr       */
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
		ft_printf("Error : Invalid read\n");
		return (NULL);
	}
	s1 = ft_calloc(sizeof(char), 1);
	if (s1 == NULL)
		return (NULL);
	s2 = get_next_line(fd);
	if (!s2)
	{
		ft_printf("%s", "Error: The file is empty.\n");
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

void	ft_put_in_tab(char *map, t_parser *parser)
{
	char	*str;

	str = ft_read_and_join(map);
	if (str == NULL)
		exit(1);
	parser->tab = ft_split(str, '\n');
	if (parser->tab == NULL)
		return ;
	free(str);
}
