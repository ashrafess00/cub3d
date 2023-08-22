/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:07:36 by kslik             #+#    #+#             */
/*   Updated: 2023/08/22 15:53:35 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

int	error_ber(char *av)
{
	int	i;
    int fl;

	i = 0;
    fl = 0;
    while(av[i] != '\0')
    {
        if(av[i] == '.')
            fl++;
        i++;
    }
    if(fl > 1)
        return 0;
    i = 0;
	while (av[i + 4] != '\0')
		i++;
	if (av[i] != '.' || av[i + 1] != 'c' || av[i + 2] != 'u' || av[i + 3] != 'b'
		|| av[i + 4] != '\0')
		return 0;
    return 1;
}

int checker_1(char **args)
{
    if(args[1] == '\0')
        return -1;
    if(error_ber(args[1]) == 0)
        return -1;
    return 1;
}
int check_color(struct s_map *map, int i, char c)
{
    int j = 0;
    int nmb = 0;
    int tmp = 0;
    int comma = 0;
    int vld  =0;
    char *q;
    while(map->my_map[i][j] == ' ' && map->my_map[i][j] != '\0')
        j++;
    if(map->my_map[i][j] == c && map->my_map[i][j+1] == ' '  && map->my_map[i][j+1] != '\0')
        j++;
    while(map->my_map[i][j] == ' '&& map->my_map[i][j] != '\0')
        j++;
    while(map->my_map[i][j] != '\0')
    {
        tmp = j;
        while(map->my_map[i][j] != ',' && map->my_map[i][j] != '\0')
        {
            if(map->my_map[i][j] > 33 && map->my_map[i][j] < 126 && map->my_map[i][j+1] != '\0')
            {
                if(map->my_map[i][j] < 48 || map->my_map[i][j] > 57)
                    werror(1);
            }
            j++;
        }
        if(map->my_map[i][j] == ',')
            comma++;
        if(tmp - j == 0)
            werror(1);
        q = ft_substr(map->my_map[i], tmp , j-tmp);
        nmb = ft_atoi(q);
        if(nmb > 255 || nmb < 0)
            werror(1);
        else
        {
            if(c == 'F')
                map->rgb.f[vld] = nmb;
            else if(c == 'C')
                map->rgb.c[vld] = nmb;
            vld++;
        }
        if(map->my_map[i][j] == ',')
            j++;
    }
    if(comma != 2 || vld != 3)
        werror(1);
    return 1;
}
int checker_2(struct s_map *map)
{
    int i= 0;
    int k = 0;
    int n = 0;
    int s = 0;
    int we = 0;
    int ea = 0;
    int  j = 0;
    int c = 0;
    int f = 0;
    while(map->my_map[k] != '\0')
        k++;
    ea = 0;
    i = 0;
    while(i < k)
    {
        j = 0;
        while(map->my_map[i][j] == ' ' && map->my_map[i][j] != '\0')
            j++;
        if(map->my_map[i][j] == 'N' && map->my_map[i][j+1] == 'O' && map->my_map[i][j+2] == ' ')
            n += load_text_n(map, i, j+2);
        else if(map->my_map[i][j] == 'S' && map->my_map[i][j+1] == 'O' && map->my_map[i][j+2] == ' ')
            s += load_text_s(map, i, j+2);
        else if(map->my_map[i][j] == 'W' && map->my_map[i][j+1] == 'E' && map->my_map[i][j+2] == ' ')
            we += load_text_w(map, i, j+2);
        else if(map->my_map[i][j] == 'E' && map->my_map[i][j+1] == 'A' && map->my_map[i][j+2] == ' ')
            ea += load_text_e(map, i, j+2);
        else if(map->my_map[i][j] == 'C' && map->my_map[i][j+1] == ' ')
            c += check_color(map, i, 'C');
        else if(map->my_map[i][j] == 'F' && map->my_map[i][j+1] == ' ')
            f += check_color(map, i, 'F');
        i++;
    }
    
    if(n != 1 || s != 1 ||we != 1 ||ea != 1 || c != 1|| f != 1)
        werror(1);
    return 1;
}