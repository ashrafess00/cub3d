/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ray_facing_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:39:56 by aessaoud          #+#    #+#             */
/*   Updated: 2023/08/16 12:53:20 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3dHeader.h"


bool is_ray_facing_down(float ray_angle)
{
    return (ray_angle > 0 && ray_angle < M_PI);
}

bool is_ray_facing_up(float ray_angle)
{
	return (!is_ray_facing_down(ray_angle));
}

bool is_ray_facing_right(float ray_angle)
{
    return (ray_angle < (M_PI / 2) || ray_angle > 1.5 * M_PI);
}

bool is_ray_facing_left(float ray_angle)
{
	return (!is_ray_facing_right(ray_angle));
}

