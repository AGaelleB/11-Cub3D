c est mieux mais par contre la map suivante est considere comme valide alors que ca ne l est pas car il y a 2 fois float

NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA                 textures/east.xpm
F 151,155,166
C 141,229,249
F
1111111111111
100000N000001
1000000000001
1000011100001
10001   10001
1000011100001
1000000000001
1000000000001
1111111111111


int check_dup_args(char *str)
{
	int i;
	int count_args;

	i = -1;
	count_args = 0;
	while (str[++i])
	{
		if (ft_strncmp_cub3d(&str[i], "NO ", 3) == 0
			|| ft_strncmp_cub3d(&str[i], "SO ", 3) == 0
			|| ft_strncmp_cub3d(&str[i], "WE ", 3) == 0
			|| ft_strncmp_cub3d(&str[i], "EA ", 3) == 0
			|| ft_strncmp_cub3d(&str[i], "F  ", 2) == 0
			|| ft_strncmp_cub3d(&str[i], "C  ", 2) == 0)
				count_args++;
		if (count_args > 6)
		{
			err("Error\nDuplicate argument found\n");
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
	check_dup_args(str);
	check_empty_line_in_map(str);
	parser->tab = ft_split(str, '\n');
	if (parser->tab == NULL)
		return ;
	free(str);
}
