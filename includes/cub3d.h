/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:11:23 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/22 15:46:36 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>
#include <stdbool.h>

# include "../includes/ft_printf.h"
# include "../includes/get_next_line.h"
# include "../includes/libft.h"
# include "../includes/minilibx-linux/mlx.h"

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"

typedef struct s_parser
{
	char	**tab;
	char	**map;
	int		index_start_map;
	int		flag_north;
	int		flag_south;
	int		flag_east;
	int		flag_west;
	int		flag_floor;
	int		flag_ceiling;
	int		map_width;
	int		map_height;
}	t_parser;

/*********************************   MAIN   **********************************/

/***************************   INIT_AND_PARSING   ***************************/

int		convert_tab_in_map(t_parser *parser);
void	parms_map_size(t_parser *parser);

int		begin_at_texture(char *str);
int		begin_digit(char *line);

int		verif_floor_and_ceiling(t_parser *parser);

int		verif_zero_close(t_parser *parser);
int		verif_space_close(t_parser *parser);

int		verif_pos_player(t_parser *parser);

int		validate_line(char *line);
int		verif_textures_wall(t_parser *parser);
int		verif_parameters(t_parser *parser);

int		master_parsing(int ac, char **av, t_parser *parser);

int		check_no_map(char *str);
void	ft_put_in_tab(char *map, t_parser *parser);

/********************************   UTILS   *********************************/

void	free_tab(char **tab);

int		ft_strncmp_cub3d(char *s1, char *s2, int n);
int		ft_strcmp_cub3d(char *s1, char *s2);

char	*ft_read_and_join(char *map);

int		verif_directory(char *str);
int		verif_extensions(char *str, char **av);
char	*trim_start(char *str);
int		verif_char(char **tab);

int		err(char *str);
char	*copy_from(char *str, char c_start);
int		find_start_of_map(t_parser *parser);
int		is_all_space(char *input);

#endif