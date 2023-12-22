/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_begin_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:21:16 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/22 15:22:46 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	begin_at_texture(char *str)
{
	int	i;

	i = 2;
	while (str[i] == ' ')
		i++;
	if (str[i] != 't')
		return (1);
	return (0);
}

int	begin_digit(char *line)
{
	int	i;

	i = 1;
	while (line[i] == ' ')
		i++;
	if (ft_isdigit(line[i]) == 0)
		return (1);
	return (0);
}
