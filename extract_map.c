/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 09:28:15 by kslik             #+#    #+#             */
/*   Updated: 2023/08/13 10:35:35 by kslik            ###   ########.fr       */
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
    return 0;
}