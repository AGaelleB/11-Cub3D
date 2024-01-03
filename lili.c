


void	movement_player_rotation_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	if (data->keys.rot_right == 1 || data->keys.mouse_rot_right == 1)
	{
		old_dir_x = data->game->dir_x;
		data->game->dir_x = data->game->dir_x * cos(-SPEED_ROT) - data->game->dir_y * sin(-SPEED_ROT);
		data->game->dir_y = old_dir_x * sin(-SPEED_ROT) + data->game->dir_y * cos(-SPEED_ROT);
		old_plane_x = data->game->plan_x;
		data->game->plan_x = data->game->plan_x * cos(-SPEED_ROT)
			- data->game->plan_y * sin(-SPEED_ROT);
		data->game->plan_y = old_plane_x * sin(-SPEED_ROT) + data->game->plan_y
			* cos(-SPEED_ROT);
	}
}

void	movement_player_rotation_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	if (data->keys.rot_left == 1 || data->keys.mouse_rot_left == 1)
	{
		old_dir_x = data->game->dir_x;
		data->game->dir_x = data->game->dir_x * cos(SPEED_ROT)
			- data->game->dir_y * sin(SPEED_ROT);
		data->game->dir_y = old_dir_x * sin(SPEED_ROT) + data->game->dir_y
			* cos(SPEED_ROT);
		old_plane_x = data->game->plan_x;
		data->game->plan_x = data->game->plan_x * cos(SPEED_ROT)
			- data->game->plan_y * sin(SPEED_ROT);
		data->game->plan_y = old_plane_x * sin(SPEED_ROT) + data->game->plan_y
			* cos(SPEED_ROT);
	}
}

void	movement_player(t_data *data)
{
	movement_player_up_down(data);
	movement_player_right_left(data);
	movement_player_rotation_left(data);
	movement_player_rotation_right(data);
	data->keys.mouse_rot_right = 0;
	data->keys.mouse_rot_left = 0;
}

// int capture_mouse(int x, int y, t_data *data)
// {
// 	static int last_x = -1;
// 	(void)y;
// 	if (last_x >= 0)
// 	{
// 		int diff_x = x - last_x;

// 		if (diff_x > 0)
// 		{
// 			data->keys.mouse_rot_right = 1;
// 			data->keys.mouse_rot_left = 0;
// 		}
// 		else if (diff_x < 0)
// 		{
// 			data->keys.mouse_rot_left = 1;
// 			data->keys.mouse_rot_right = 0;
// 		}
// 	}
// 	last_x = x;
// 	return (0);
// }


int capture_mouse(int x, int y, t_data *data)
{
	// Assurez-vous de définir SCREEN_WIDTH quelque part dans votre code
	const int EDGE_THRESHOLD = 50; // Seuil pour déterminer l'"extrême" de l'écran
	(void)y;
	// Vérifiez si la souris est sur le côté droit extrême de l'écran
	if (x > WIDTH - EDGE_THRESHOLD)
	{
		data->keys.mouse_rot_right = 1;
		data->keys.mouse_rot_left = 0;
	}
	// Vérifiez si la souris est sur le côté gauche extrême de l'écran
	else if (x < EDGE_THRESHOLD)
	{
		data->keys.mouse_rot_left = 1;
		data->keys.mouse_rot_right = 0;
	}
	else
	{
		// La souris n'est pas sur les bords extrêmes, réinitialiser les rotations
		data->keys.mouse_rot_right = 0;
		data->keys.mouse_rot_left = 0;
	}
	return (0);
}


void	exec_game(t_parser *parser)
{
	t_data	data;

	init_data_game(&data, parser);
	if (init_windows(&data))
		return ;
	init_textures_adress(&data);
	mlx_hook(data.img_blank->window, KeyPress, KeyPressMask, key_press, &data);
	mlx_hook(data.img_blank->window, MotionNotify, PointerMotionMask, capture_mouse, &data);
	mlx_hook(data.img_blank->window, KeyRelease, KeyReleaseMask, key_release, &data);
	mlx_hook(data.img_blank->window, 17, 0, close_window, &data);
	mlx_loop_hook(data.img_blank->mlx, &display_game, &data);
	mlx_loop(data.img_blank->mlx);
}
