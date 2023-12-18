// Fonction pour valider le format de la ligne de texture
int validate_texture_line(char *line)
{
    char **split_line;
    int count;

    split_line = ft_split(line, ' ');
    for (count = 0; split_line[count]; count++);
    if (count != 2)
    {
        ft_free_split(split_line);
        return (0);  // Retourne 0 si le format n'est pas valide
    }
    ft_free_split(split_line);
    return (1);  // Retourne 1 si le format est valide
}

// Fonction pour vérifier et définir les drapeaux de texture
int verify_and_set_texture_flag(t_parser *parser, char *line, char *texture_prefix, int *flag)
{
    if (ft_strncmp_cub3d(line, texture_prefix, 3) == 0)
    {
        if (!validate_texture_line(line))
            return (err("Error\nBad texture\n"));
        if (check_error_textures(parser, line) == 0)
            (*flag)++;
    }
    return (1);
}

// Fonction principale de vérification des textures
int master_verif_textures(char *map, t_parser *parser)
{
    int i;

    i = 0;
    ft_put_in_tab(map, parser);
    while (parser->tab[i])
    {
        if (!verify_and_set_texture_flag(parser, parser->tab[i], "NO ", &parser->flag_north) ||
            !verify_and_set_texture_flag(parser, parser->tab[i], "SO ", &parser->flag_south) ||
            !verify_and_set_texture_flag(parser, parser->tab[i], "WE ", &parser->flag_west) ||
            !verify_and_set_texture_flag(parser, parser->tab[i], "EA ", &parser->flag_east))
            return (0);  // En cas d'erreur
        i++;
    }
    return ((parser->flag_north == 1) && (parser->flag_south == 1) &&
            (parser->flag_west == 1) && (parser->flag_east == 1)) ? 0 : err("Error\nBad texture\n");
}
