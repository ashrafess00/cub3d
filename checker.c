/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:07:36 by kslik             #+#    #+#             */
/*   Updated: 2023/08/11 19:34:37 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3dHeader.h"

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
    int fl = 0;
    int tmp = 0;
    char q;
    while(map->my_map[i][j] == ' ')
        j++;
    if(map->my_map[i][j] == c && map->my_map[i][j+1] == ' ')
        j++;
    else
        werror(1);
    while(map->my_map[i][j] == ' ')
        j++;
    while(map->my_map[i][j + 1] != '\0')
    {
        tmp = j;
        while(map->my_map[i][tmp] != ',' && map->my_map[i][tmp] != '\0')
            tmp++;
        if(!(map->my_map[i][j] >= 48 && map->my_map[i][j] <= 50) && tmp - j == 3 && map->my_map[i][j] != ',' && ft_isdigit(map->my_map[i][j])==1  && map->my_map[i][j] != '\0')
            werror(1);
        if(tmp - j == 3)
        {
            while(map->my_map[i][j] != ',' && map->my_map[i][j + 1] != '\0')
            {
                if(!(map->my_map[i][j] >= 48 && map->my_map[i][j] <= 53))
                    werror(1);
                j++;
            }
        }
        else 
            while(map->my_map[i][j] != ',' && map->my_map[i][j] != '\0')
                j++;
        j++;
    }
    return 0;
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
    while(map->my_map[k][0] != '1')
        k++;
    i = 0;
    while(i < k)
    {
        j = 0;
        while(map->my_map[i][j] == ' ')
            j++;
        if(map->my_map[i][j] == 'N' && map->my_map[i][j+1] == 'O' && map->my_map[i][j+2] == ' ')
            n++;
        else if(map->my_map[i][j] == 'S' && map->my_map[i][j+1] == 'O' && map->my_map[i][j+2] == ' ')
            s++;
        else if(map->my_map[i][j] == 'W' && map->my_map[i][j+1] == 'E' && map->my_map[i][j+2] == ' ')
            we++;
        else if(map->my_map[i][j] == 'E' && map->my_map[i][j+1] == 'A' && map->my_map[i][j+2] == ' ')
            ea++;
        else if(map->my_map[i][j] == 'C' )
            check_color(map, i, 'C');
        else if(map->my_map[i][j] == 'F')
            check_color(map, i, 'F');
        i++;
    }
    if(n != 1 || s != 1 ||we != 1 ||ea != 1)
        werror(1);
    return 1;
}