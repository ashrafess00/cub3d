/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 09:28:15 by kslik             #+#    #+#             */
/*   Updated: 2023/08/14 20:10:41 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3dHeader.h"
int extract_2(struct s_map *map, int start)
{
    int i;
    int j;
    map->pure_map = malloc((map->char_in_map / 4) * sizeof(char*) + 1);
    i = 0;
    
    while(map->my_map[start] != NULL)
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
    i = -1;
    map->last_line = i - 1;
    map->pure_map[i] =  NULL;
    return 1;
}
int checker_map(struct s_map *map)
{
    int i = 0;
    int j = 0;
    int ply = 0;
    while(map->pure_map[i] != NULL)
    {
        j =0;
        while(map->pure_map[i][j+1] != '\0')
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
    if(ply != 1)
        werror(1);
    return 0;
}
int check_around(struct s_map *map, int i, int j)
{
    if(i == 0 || i == map->last_line)
        werror(1);
    if(map->pure_map[i][j + 1] != '1' && map->pure_map[i][j + 1] != '0' && map->pure_map[i][j + 1] != 'N')
        werror(1);
    if(map->pure_map[i][j - 1] != '1' && map->pure_map[i][j - 1] != '0' && map->pure_map[i][j - 1] != 'N')
        werror(1);
    if(map->pure_map[i + 1][j] != '1' && map->pure_map[i + 1][j] != '0' && map->pure_map[i + 1][j] != 'N')
        werror(1);
    if(map->pure_map[i - 1][j] != '1' && map->pure_map[i - 1][j] != '0' && map->pure_map[i - 1][j] != 'N')
        werror(1);  
    return 0;
}
int check_valid(struct s_map *map)
{
    int i = 0;
    int j = 0;
    while(map->pure_map[i])
    {
        j = 0;
        while(map->pure_map[i][j] != '\0')
        {
            if(map->pure_map[i][j] == '0' || map->pure_map[i][j] == 'N')
                check_around(map, i, j);
            if(map->pure_map[i][j] == 'W' || map->pure_map[i][j] == 'S')
                check_around(map, i, j);
            if(map->pure_map[i][j] == 'E')
                check_around(map, i, j);
            j++;
        }
        i++;
    }
    return 0;
}
int check_mty_line(struct s_map *map, int start)
{
    int k = 0;
    start = 0;
    int fl = 0;
    while(map->whole_map[start])
    {
        if(map->whole_map[start] == '1')
            k++;
        else if(map->whole_map[start] != '1' || map->whole_map[start] != ' ')
            k = 0;
        if(k > 2)
        {
            while(map->whole_map[start] != '\0')
            {
                if(map->whole_map[start] == '\n' && (map->whole_map[start + 1] == '\n' || map->whole_map[start + 1] == '\0'))
                            werror(1);
                start++;                    
            }
            return 0;
        }
        start++;
    }
    return 0;
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
    check_valid(map);
    check_mty_line(map, start);
    return 0;
}