



void	go_cub(t_main *data)
{
	t_cub	cub;

	init_value(&cub, data);
	if (mlx_stuff(&cub))
		return ;
	get_texture(&cub);
	mlx_hook(cub.img->win, KeyPress, KeyPressMask, &key_press, &cub);
	mlx_hook(cub.img->win, MotionNotify, PointerMotionMask, &motion_mouse, &cub);
	mlx_hook(cub.img->win, KeyRelease, KeyReleaseMask, &key_release, &cub);
	mlx_hook(cub.img->win, DestroyNotify, 0, &close_window, &cub);
	if (cub.mouse_on == 0)
		mlx_mouse_hide(cub.img->mlx, cub.img->win);
	mlx_loop_hook(cub.img->mlx, &display_game_frame, &cub);
	mlx_loop(cub.img->mlx);
}

void	init_value(t_cub *cub, t_main *data)
{
	cub->map = good_map(cub, data, data->map); //
	cub->colors_ceiling = data->colors_ceiling; //
	cub->colors_floor = data->colors_floor; //
	cub->posx = start_pos(cub->map, 0) + 0.5; //
	cub->posy = start_pos(cub->map, 1) + 0.5; //
	cub->sno = ft_strdup(data->no); // filename
	cub->sso = ft_strdup(data->so); //
	cub->swe = ft_strdup(data->we); //
	cub->sea = ft_strdup(data->ea); //
	free_textures(data);
	cub->texture1 = NULL;
	cub->texture2 = NULL;
	cub->texture3 = NULL;
	cub->texture4 = NULL;
	cub->side = 0; //
	cub->mouse_on = 0;
	init_pos(cub);
	init_malloc_event(cub);
}

void	init_pos(t_cub *cub)
{
	if (cub->map[(int)cub->posx][(int)cub->posy] == 'N')
	{
		cub->dirx = -1;
		cub->diry = 0;
		cub->planex = 0;
		cub->planey = 0.66;
	}
	else if (cub->map[(int)cub->posx][(int)cub->posy] == 'S')
	{
		cub->dirx = 1;
		cub->diry = 0;
		cub->planex = 0;
		cub->planey = -0.66;
	}
	else
		init_pos_dig(cub);
}

void	init_malloc_event_dig(t_cub *cub)
{
	cub->cam_left = malloc(sizeof(t_bool));
	if (!cub->cam_left)
		error_alloc(cub, "Error alloc cam_left");
	cub->cam_left->key = 65363;
	cub->cam_left->ok = FALSE;
	cub->cam_right = malloc(sizeof(t_bool));
	if (!cub->cam_right)
		error_alloc(cub, "Error alloc cam_right");
	cub->cam_right->key = 65361;
	cub->cam_right->ok = FALSE;
	cub->cam_mouse_right = 0;
	cub->cam_mouse_left = 0;
}

void	init_malloc_event(t_cub *cub)
{
	cub->go_w = malloc(sizeof(t_bool));
	if (!cub->go_w)
		error_alloc(cub, "Error alloc go_w");
	cub->go_w->key = 119;
	cub->go_w->ok = FALSE;
	cub->go_s = malloc(sizeof(t_bool));
	if (!cub->go_s)
		error_alloc(cub, "Error alloc go_s");
	cub->go_s->key = 115;
	cub->go_s->ok = FALSE;
	cub->go_a = malloc(sizeof(t_bool));
	if (!cub->go_a)
		error_alloc(cub, "Error alloc go_a");
	cub->go_a->key = 97;
	cub->go_a->ok = FALSE;
	cub->go_d = malloc(sizeof(t_bool));
	if (!cub->go_d)
		error_alloc(cub, "Error alloc go_d");
	cub->go_d->key = 100;
	cub->go_d->ok = FALSE;
	init_malloc_event_dig(cub);
}

int	mlx_stuff(t_cub *cub)
{
	cub->img = ft_calloc(1, sizeof(t_img));
	if (!cub->img)
		error_alloc(cub, "Error alloc cub->img");
	cub->img->mlx = mlx_init();
	if (!cub->img->mlx)
		return (error_ok("Error mlx_init", 1));
	cub->img->win = mlx_new_window(cub->img->mlx, WIDTH, HEIGHT, "CUB3D");
	if (!cub->img->win)
		return (error_ok("Error mlx_win", 1));
	cub->img->img = mlx_new_image(cub->img->mlx, WIDTH, HEIGHT);
	cub->img->data_addr = mlx_get_data_addr(cub->img->img, &(cub->img->bpp),
			&(cub->img->line_size), &(cub->img->endian));
	return (0);
}


void	get_texture(t_cub *cub)
{
	int	h;
	int	w;

	cub->texture1 = ft_calloc(1, sizeof(t_img));
	if (!cub->texture1)
		error_alloc(cub, "Error alloc texture1");
	cub->texture1->img = mlx_xpm_file_to_image(cub->img->mlx, cub->sno, &w, &h);
	if (!cub->texture1->img)
		return (error_void("Error texture1->img"));
	cub->texture1->data_addr = mlx_get_data_addr(cub->texture1->img,
			&(cub->texture1->bpp), &(cub->texture1->line_size),
			&(cub->texture1->endian));

	cub->texture2 = ft_calloc(1, sizeof(t_img));
	if (!cub->texture2)
		error_alloc(cub, "Error alloc texture2");
	cub->texture2->img = mlx_xpm_file_to_image(cub->img->mlx, cub->sso, &w, &h);
	if (!cub->texture2->img)
		return (error_void("Error texture2->img"));
	cub->texture2->data_addr = mlx_get_data_addr(cub->texture2->img,
			&(cub->texture2->bpp), &(cub->texture2->line_size),
			&(cub->texture2->endian));
	get_texture_dig(cub, h, w);
}