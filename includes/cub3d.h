/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:11:23 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/27 16:18:08 by abonnefo         ###   ########.fr       */
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

// # define WIDTH 1280 // x
// # define HEIGHT 960 // y

# define WIDTH 640 // x
# define HEIGHT 480 // y

# define KEY_ESCAPE 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define SPEED_MOVE 0.015
# define SPEED_ROT 0.01

# define INFINITY_VALUE 1e30 //"1e30" est une façon d'écrire 10^30
# define MAX_COLOR_VALUE 0xFF  // Equivalent to 255 in decimal

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	rot_left;
	int	rot_right;
}	t_keys;

typedef struct s_colors
{
	int			red;
	int			green;
	int			blue;
}	t_colors;

typedef struct s_game
{
	double		pos_x;			// Position de départ x et y
	double		pos_y;			// Position de départ x et y
	double		dir_x;			// vecteur de direction initial
	double		dir_y;			// vecteur de direction initial
	double		plan_x;			//la version Raycaster 2D du plan de la caméra
	double		plan_y;			//la version Raycaster 2D du plan de la caméra
	double		camera_x;		//coordonnée x dans l'espace de la caméra
	double		ray_dir_x;
	double		ray_dir_y;
	double		delta_dist_x;	//the distance the ray has to travel to go from 1 x-side to the next x-side
	double		delta_dist_y;	//the distance the ray has to travel to go from 1 x-side to the next x-side
	double		side_dist_x;	//the distance the ray has to travel from its start position to the first x-side and the first y-side
	double		side_dist_y;	//the distance the ray has to travel from its start position to the first x-side and the first y-side
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;			//was there a wall hit?
	int			side;			//was a NS or a EW wall hit?
	double		dist_to_wall;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	int			texture_x;
	int			texture_y;
	double		texture_pos;
	double		walk;
}	t_game;

typedef struct s_img
{
	void		*mlx;
	void		*window;
	char		*filename;
	char		*data_addr;
	void		*img_ptr; // stocker le pointeur vers une image chargée
	int			bits_per_pixels;
	int			size_line;
	int			endian;
}	t_img;

typedef struct s_parser
{
	char		**tab;
	char		**map;
	int			index_start_map;
	int			flag_north;
	int			flag_south;
	int			flag_east;
	int			flag_west;
	int			flag_floor;
	int			flag_ceiling;
	int			map_width;
	int			map_height;
}	t_parser;

typedef struct s_data
{
	char		**valid_map;
	char		**valid_param;
	int			pos_player_x;
	int			pos_player_y;
	int			line_height;
	t_parser	*parser;
	t_img		*img_blank; // créer une nouvelle image vierge avec mlx_new_image
	t_img		*texture_NO;
	t_img		*texture_SO;
	t_img		*texture_WE;
	t_img		*texture_EA;
	t_colors	colors_ceiling;
	t_colors	colors_floor;
	t_game		*game;
	t_keys		keys;
}	t_data;


/* POUBELLE TEMP */
void	print_stuff_before_init(t_data	*data);
void	print_stuff_after_init(t_data	*data);

/*********************************   MAIN   **********************************/


/*******************************   EXEC_CUB3D   ******************************/

void	exec_game(t_parser *parser);
int		display_game(t_data *data);
void	throw_rays(t_data *data);
void	calcul_wall_drawing_params(t_data *data);
void	draw_vertical_column(t_data *data, int x, int y, int line_height);
void	put_pixel(t_data *data, int x, int y, int C_or_F);
int		get_rgb(t_data *data, int C_or_F);
int		get_color(t_data *data, t_img *texture);
int		key_press(int key, t_data *data);
int		key_release(int key, t_data *data);
void	movement_player(t_data *data);


/*********************************   INIT   *********************************/

int		init_colors(t_data *data);
int		init_textures_filename(t_data *data);
int		init_windows(t_data *data);
int		init_pos_player(t_data *data);
void	init_textures_adress(t_data *data);
void	init_data_game(t_data *data, t_parser *parser);
void	init_ray(t_data	*data, int x);
void	init_pos_directions(t_data *data);
void	init_key_press(t_data *data);


/********************************   PARSING   ********************************/

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
float	ft_fabs(float i);

#endif