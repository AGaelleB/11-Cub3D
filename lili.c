// Cette fonction cherche la première ligne qui n'est pas de configuration.
// On suppose que les lignes de configuration se terminent par une ligne vide.
int find_start_of_map(t_parser *parser)
{
    int i = 0;
    while (parser->tab[i] && strcmp(parser->tab[i], "") != 0)
    {
        i++;
    }
    return i + 1; // Retourne l'index de la première ligne après la ligne vide
}

int find_line_with_only_ones(t_parser *parser)
{
    int start_of_map = find_start_of_map(parser);
    int i = start_of_map;

    while (parser->tab[i])
    {
        int j = 0;
        while (parser->tab[i][j])
        {
            if (parser->tab[i][j] != '1' && parser->tab[i][j] != ' ')
                break;
            j++;
        }
        if (parser->tab[i][j] == '\0')
            return i - start_of_map; // Retourne l'index relatif à la carte elle-même
        i++;
    }

    return -1;
}

int master_verif_textures(char *map, t_parser *parser)
{
    ft_put_in_tab(map, parser);

    parser->index_start_map = find_line_with_only_ones(parser);
    if (parser->index_start_map != -1)
    {
        printf("Index de la ligne avec que des '1': %d\n", parser->index_start_map);
    }

    // Reste du code...
}
