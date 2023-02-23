#include "so_long.h"

static int add_comp(t_map *tmap, char c, t_map_comp *comp)
{
    if (ft_is_player_char(c))
        comp->nb_starting_points++;
    else if (c == 'E')
        comp->nb_exits++;
    else if (c == 'C')
        comp->nb_collec++;
}

static int ft_inspect_map(t_map *tmap, t_map_comp *comp)
{
    int i;
    int j;

    if (tmap->map != 0)
    {
        i = -1;
        while (++i < tmap->rows)
        {
            j = -1;
            while (++j < tmap->cols)
            {
                add_comp(tmap, tmap->map[i][j], comp);
                comp->player_x = j;
                comp->player_y = i;
            }
        }
    }
    if (comp->nb_starting_points != 1 ||comp->nb_exits != 1
        || comp->nb_collec < 1)
        return (0);
    return (1);
}

static void init_comp(t_map_comp *c)
{
    c->nb_starting_points = 0;
    c->nb_collec = 0;
    c->nb_exits = 0;
    c->player_x = -1;
    ;
    c->player_y = -1;
    ;
}
int ft_map_has_necessary_components(t_map *tmap)
{
    t_map_comp comp;

    init_comp(&comp);
    // TODO: check map has 1 exit, 1 or more collectibles, 1 starting position
    if (ft_inspect_map(tmap, &comp) != 1)
        return (0);
    tmap->px = comp.player_x;
    tmap->py = comp.player_y;
    return (1);
}