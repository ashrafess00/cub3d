/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 09:28:15 by kslik             #+#    #+#             */
/*   Updated: 2023/08/22 17:29:37 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"
int lines(struct s_map *map)
{
    return map->lines;
}
int extract_2(struct s_map *map, int start)
{
    int i;
    int j;
    map->pure_map = malloc(lines(map) * sizeof(char*) + 1);
    i = 0;
    
    while(map->my_map[start] != '\0')
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
    if(map->pure_map[i][j + 1] != '1' && map->pure_map[i][j + 1] != '0' && !is_player(map->pure_map[i], j+1))
        werror(1);
    if(map->pure_map[i][j - 1] != '1' && map->pure_map[i][j - 1] != '0' && !is_player(map->pure_map[i], j-1))
        werror(1);
    if(map->pure_map[i + 1][j] != '1' && map->pure_map[i + 1][j] != '0' && !is_player(map->pure_map[i+1], j))
        werror(1);
    if(map->pure_map[i - 1][j] != '1' && map->pure_map[i - 1][j] != '0' && !is_player(map->pure_map[i-1], j))
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
    while(map->whole_map[start] != '\0')
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
int is_player(char *s, int i)
{
    if(s[i] == 'N' || s[i] == 'S' || s[i] == 'E' || s[i] == 'W')
        return 1;
    return 0;
}
int get_ply_cor(struct s_map *map, t_player *player)
{
    int i = 0;
    int j = 0;
    while(map->pure_map[i])
    {
        j = 0;
        while(map->pure_map[i][j])
        {
            if(is_player(map->pure_map[i], j))
            {
                player->x = j * TILE_SIZE;
                player->y = i * TILE_SIZE;
                player->c = malloc(3 * sizeof(char));
                player->c[0] = map->pure_map[i][j];
                player->c[1] = '\0';
                return 0;
            }
            j++;
        }
        i++;
    }
    return 0;
}
int get_wi_he(struct s_map *map)
{
    int i = 0;
    int j=0;
    map->window_wid = 0;
    while(map->pure_map[i])
    {
        j=0;
        while(map->pure_map[i][j])
            j++;
        if(j > map->window_wid)
            map->window_wid = j * TILE_SIZE;
        i++;
    }
    map->window_heig = i * TILE_SIZE;
    return 0;
}
int exctract(struct s_map *map, t_player *player)
{
    int i = 5;
    int j = 0;
    int ma = 0;
    int start;
    while(map->my_map[i] != '\0')
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
    get_wi_he(map);
    get_ply_cor(map, player);
    return 0;
}