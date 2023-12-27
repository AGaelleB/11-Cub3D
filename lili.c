int	handle_key_esc(int key, t_data *data)
{
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(data->img_blank->mlx, data->img_blank->window);
		exit (0);
	}
	return (0);
}

int	key_press(int key, t_data *data)
{
	if (key == KEY_W) // 119
		data->keys.w = 1;
	if (key == KEY_A) // 97
		data->keys.a = 1;
	if (key == KEY_S) // 115
		data->keys.s = 1;
	if (key == KEY_D) // 100
		data->keys.d = 1;
	return (0);
}

int	key_release(int key, t_data *data)
{
	printf("%skey_release before KEY_W = %d%s\n", GREEN, data->keys.w, RESET);
	if (key == KEY_W)
		data->keys.w = 0;
	if (key == KEY_A)
		data->keys.a = 0;
	if (key == KEY_S)
		data->keys.s = 0;
	if (key == KEY_D)
		data->keys.d = 0;
	printf("%skey_release after KEY_W = %d%s\n", GREEN, data->keys.w, RESET);
	return (0);
}


void	movement_player_up_down(t_data *data, int key)
{
	// double	moove_speed;

	// moove_speed = 0.025;
	if (key == data->keys.w)
	{
		if (data->valid_map[(int)(data->game->pos_x + data->game->dir_x * SPEED)][(int)(data->game->pos_y)] != '1')
			data->game->pos_x += data->game->dir_x * SPEED;
		if (data->valid_map[(int)(data->game->pos_x)][(int)(data->game->pos_y + data->game->dir_y * SPEED)] != '1')
			data->game->pos_y += data->game->dir_y * SPEED;
	}
	else if (key == data->keys.s)
	{
		if (data->valid_map[(int)(data->game->pos_x - data->game->dir_x * SPEED)][(int)(data->game->pos_y)] != '1')
			data->game->pos_x -= data->game->dir_x * SPEED;
		if (data->valid_map[(int)(data->game->pos_x)][(int)(data->game->pos_y - data->game->dir_y * SPEED)] != '1')
			data->game->pos_y -= data->game->dir_y * SPEED;
	}
}
void	movement_player_right_left(t_data *data, int key)
{
	// double	moove_speed;

	// moove_speed = 0.025;
	if (key == data->keys.d)
	{
		if (data->valid_map[(int)(data->game->pos_x + data->game->plan_x * SPEED)]
			[(int)(data->game->pos_y)] != '1')
			data->game->pos_x += data->game->plan_x * SPEED;
		if (data->valid_map[(int)(data->game->pos_x)]
			[(int)(data->game->pos_y + data->game->plan_y * SPEED)] != '1')
			data->game->pos_y += data->game->plan_y * SPEED;
	}
	else if (key == data->keys.a)
	{
		if (data->valid_map[(int)(data->game->pos_x - data->game->plan_x * SPEED)]
			[(int)(data->game->pos_y)] != '1')
			data->game->pos_x -= data->game->plan_x * SPEED;
		if (data->valid_map[(int)(data->game->pos_x)]
			[(int)(data->game->pos_y - data->game->plan_y * SPEED)] != '1')
			data->game->pos_y -= data->game->plan_y * SPEED;
	}
}

void	movement_player(t_data *data, int key)
{
	if (key == data->keys.w || key == data->keys.w)
		movement_player_up_down(data, key);
	else if (key == data->keys.d || key == data->keys.a)
		movement_player_right_left(data, key);
}

void	update_movement(t_data *data)
{
	if (data->keys.w == 1) // avancer
		movement_player(data, KEY_W);
	if (data->keys.s  == 1) // reculer
		movement_player(data, KEY_D);
	if (data->keys.d == 1) // droite
		movement_player(data, KEY_A);
	if (data->keys.a  == 1) // gauche
		movement_player(data, KEY_S);
}
int	display_game(t_data *data)
{
	int	x;

	x = 0;
	// ajouter les mouvements clavier et souris
	update_movement(data);
	while (x < WIDTH)
	{
		init_ray(data, x);
		throw_rays(data);
		calcul_wall_drawing_params(data);
		draw_vertical_column(data, x, 0, data->game->line_height);
		x++;
	}
	mlx_put_image_to_window(data->img_blank->mlx, data->img_blank->window,
		data->img_blank->img_ptr, 0, 0);
	return (0);
}

void	init_data_game(t_data *data, t_parser *parser)
{
	data->game = malloc(sizeof(t_game));
	if (!data->game)
		return ;
	ft_memset(data->game, 0, sizeof(t_game)); // a resolu tous mes problems d init !!!
	data->valid_map = parser->map;
	data->valid_param = parser->tab;
	init_colors(data);
	init_pos_player(data);
	data->game->pos_x = data->pos_player_x + 0.5; // ?? pq +0,5 ?
	data->game->pos_y = data->pos_player_y + 0.5; // ??
	init_textures_filename(data);
	data->game->side = 0;
	init_pos_directions(data);
	init_key_press(data);
	// init_malloc_event(data);
}

void	exec_game(t_parser *parser)
{
	t_data	data;

	init_data_game(&data, parser);
	// print_stuff_before_init(&data); // PRINT
	if (init_windows(&data))
		return ;
	init_textures_adress(&data); // deplace ici sinon bug car init_mlx dans init_windows
	// print_stuff_after_init(&data); // PRINT
	
	mlx_hook(data.img_blank->window, KeyPress, KeyPressMask, key_press, &data);
	mlx_hook(data.img_blank->window, KeyRelease, KeyReleaseMask, key_release, &data);

	mlx_key_hook(data.img_blank->window, handle_key_esc, &data);
	mlx_hook(data.img_blank->window, 17, 0, close_window, &data);

	mlx_loop_hook(data.img_blank->mlx, &display_game, &data);
	mlx_loop(data.img_blank->mlx);
}