/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 09:28:15 by kslik             #+#    #+#             */
/*   Updated: 2023/08/13 12:21:49 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3dHeader.h"
int extract_2(struct s_map *map, int start)
{
    int i;
    int j;
    map->pure_map = malloc(map->char_in_map * sizeof(char*) + 1);
    i = 0;
    while(map->my_map[start])
    {
        j = 0;
        
        map->pure_map[i] = malloc(ft_strlen(map->my_map[start]) * sizeof(char) + 1);
        while(map->my_map[start][j] != '\0')
        {
            map->pure_map[i][j] = map->my_map[start][j];
            j++;
        }
        map->pure_map[i][j] = '\0';
        start++;
        i++;
    }
    map->pure_map[i] =  NULL;
    return 1;
}
int checker_map(struct s_map *map)
{
    int i = 0;
    int j = 0;
    int ply = 0;
    while(map->pure_map[i] != '\0')
    {
        j =0;
        while(map->pure_map[i][j])
        {
            if(map->pure_map[i][j] == 'N' || map->pure_map[i][j] == 'S')
                ply++;
            else if(map->pure_map[i][j] == 'E' || map->pure_map[i][j] == 'W')
                ply++;
            else if(map->pure_map[i][j] == '0' || map->pure_map[i][j] == '1' || map->pure_map[i][j] == ' ')
                        ;
            else
                werror(1);
            j++;
        }
        i++;
    }
    if(ply > 1)
        werror(1);
    return 0;
}
int check_valid(struct s_map *map)
{
    
}
int exctract(struct s_map *map)
{
    int i = 6;
    int j = 0;
    int ma = 0;
    int start;
    while(map->my_map[i][j] != '\0')
    {
        while(map->my_map[i][j] == ' ' && map->my_map[i][j] != '\0')     
           j++;
        if(map->my_map[i][j] == '1' || map->my_map[i][j] == '0')
            break;
        i++;
    }
    while(map->my_map[i][j] == '1' && map->my_map[i][j] != '\0')
    {
        j++;
        ma++;
    }
    if(ma >= 3)
        start = i;
    else
        werror(1);
    extract_2(map, start);
    checker_map(map);
    return 0;
}