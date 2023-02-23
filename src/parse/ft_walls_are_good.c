#include "so_long.h"

static int ft_walls_are_closed(t_map *tmap, char **map)
{
    int i;

    i = 0;
    while (i < tmap->rows)
    {
        if (map[i][0] == '0' || map[i][tmap->cols - 1] == '0') // 1st and last cols
        {
        //    printf("map[%d][0 or cols - 1] = %c %c\n", i, map[i][0], map[i][tmap->cols - 1]);
            return (0);
        }
        i++;
    }
    i = 0;
    while (i < tmap->cols)
    {
        if (map[0][i] == '0' || map[tmap->rows - 1][i] == '0')
            return (0);
        i++;
    }
    return (1);
}

static int  ft_is_map_rect(t_map *tmap, char **map)
{
    int i;
    int len;

    i = 1;
    len = ft_strlen(map[0]);
    while (i < tmap->rows)
    {
        if (len != ft_strlen(map[i]))
        {
         //   printf("i = %d, len %d, %d\n", i, len, ft_strlen(map[i]));
            return (0);
        }
        i++;        
    }
    return (1);
}

int ft_walls_are_good(t_map *tmap)
{
   ft_display_tmap_map(*tmap);
    if (!ft_is_map_rect(tmap, tmap->map))
    {
        
		ft_putstr_fd("Error\nIn ft_walls_are_good.c: Map walls are not rectangular.\n", 2);
        return (0);
    }
	if (!ft_walls_are_closed(tmap, tmap->map))
    {
		ft_putstr_fd("Error\nIn ft_walls_are_good.c: Map walls are not closed.\n", 2);
        return (0);
    }
    return (1);
}