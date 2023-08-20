/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslik <kslik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:14:25 by kslik             #+#    #+#             */
/*   Updated: 2023/08/18 13:14:46 by kslik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_header.h"

int load_text_n(struct s_map *map, int i, int j)
{
    int k = 0;
    while(map->my_map[i][j] == ' ')
        j++;
    k = j;
    while(map->my_map[i][j] != ' ')
        j++;
    map->txt.no_txt = malloc((j) * sizeof(char));
    j = 0;
    while(map->my_map[i][k] != '\0' && map->my_map[i][k] != ' ')
    {
        map->txt.no_txt[j] = map->my_map[i][k];
        k++;
        j++;
    }
    if(map->my_map[i][k] != '\0')
        werror(1);
    map->txt.no_txt[j] = '\0';
    return 1;
}
int load_text_s(struct s_map *map, int i, int j)
{
    int k = 0;
    while(map->my_map[i][j] == ' ')
        j++;
    k = j;
    while(map->my_map[i][j] != ' ')
        j++;
    map->txt.so_txt = malloc((j) * sizeof(char));
    j = 0;
    while(map->my_map[i][k] != '\0' && map->my_map[i][k] != ' ')
    {
        map->txt.so_txt[j] = map->my_map[i][k];
        k++;
        j++;
    }
    if(map->my_map[i][k] != '\0')
        werror(1);
    map->txt.so_txt[j] = '\0';
    return 1;
}
int load_text_w(struct s_map *map, int i, int j)
{
    int k = 0;
    while(map->my_map[i][j] == ' ')
        j++;
    k = j;
    while(map->my_map[i][j] != ' ')
        j++;
    map->txt.we_txt = malloc((j) * sizeof(char));
    j = 0;
    while(map->my_map[i][k] != '\0' && map->my_map[i][k] != ' ')
    {
        map->txt.we_txt[j] = map->my_map[i][k];
        k++;
        j++;
    }
    if(map->my_map[i][k] != '\0')
        werror(1);
    map->txt.we_txt[j] = '\0';
    return 1;
}
int load_text_e(struct s_map *map, int i, int j)
{
    int k = 0;
    while(map->my_map[i][j] == ' ')
        j++;
    k = j;
    while(map->my_map[i][j] != ' ')
        j++;
    map->txt.ea_txt = malloc((j) * sizeof(char));
    j = 0;
    while(map->my_map[i][k] != '\0' && map->my_map[i][k] != ' ')
    {
        map->txt.ea_txt[j] = map->my_map[i][k];
        k++;
        j++;
    }
    if(map->my_map[i][k] != '\0')
        werror(1);
    map->txt.ea_txt[j] = '\0';
    return 1;
}