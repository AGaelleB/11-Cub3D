/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:40:03 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/15 15:42:55 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	main(int ac, char **av)
{

	// ft_printf("debut parsing cub3d\n");
	if (master_parsing(ac, av) != 0)
		return (1);
	
	return (0);
}