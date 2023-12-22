
int verif_inside_zero_close(t_parser *parser, int i, int j)
{
	int prev_row_len;
	int	next_row_len;

	prev_row_len = 0;
	next_row_len = 0;
	if (parser->map[i][0] == '0')
		return (1);
	if (i > 0)
		prev_row_len = ft_strlen(parser->map[i - 1]);
	if (i < parser->map_height - 1)
		next_row_len = ft_strlen(parser->map[i + 1]);
	if ((i > 0 && j < prev_row_len && (parser->map[i - 1][j] == ' ' || !parser->map[i - 1][j]))
		|| (i < parser->map_height - 1 && j < next_row_len && (parser->map[i + 1][j] == ' ' || !parser->map[i + 1][j]))
		|| (j > 0 && parser->map[i][j - 1] == ' ')
		|| (j < parser->map_width - 1 && parser->map[i][j + 1] == ' '))
		return (1);
	if ((i == 0 || i == parser->map_height - 1) && parser->map[i][j] == '0')
		return (1);
	if ((i > 0 && j >= prev_row_len) || (i < parser->map_height - 1 && j >= next_row_len))
		return (1);
	return (0);
}
