/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaa <aelbouaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 06:13:56 by aelbouaa          #+#    #+#             */
/*   Updated: 2023/11/27 06:34:14 by aelbouaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse/Cub3D.h"

void	backwards(t_rayc *rayc)
{
	rayc->x_cos[RAYS / 2] = cos(rayc->radian[RAYS / 2]) * 8;
	rayc->y_sin[RAYS / 2] = sin(rayc->radian[RAYS / 2]) * 8;
	rayc->pp_x -= (int)rayc->x_cos[RAYS / 2];
	rayc->pp_y -= (int)rayc->y_sin[RAYS / 2];
	if (rayc->map[(rayc->pp_y - (int)rayc->y_sin[RAYS / 2]) / 50]
		[(rayc->pp_x - (int)rayc->x_cos[RAYS / 2]) / 50] != '1')
		draw_rays(rayc);
	else
	{
		rayc->pp_x += (int)rayc->x_cos[RAYS / 2];
		rayc->pp_y += (int)rayc->y_sin[RAYS / 2];
	}
}

void	move_right(t_rayc *rayc)
{
	rayc->radian[RAYS / 2] = (rayc->angel[RAYS / 2] + 90) * (3.141593 / 180);
	rayc->x_cos[RAYS / 2] = cos(rayc->radian[RAYS / 2]) * 8;
	rayc->y_sin[RAYS / 2] = sin(rayc->radian[RAYS / 2]) * 8;
	rayc->pp_x += (int)rayc->x_cos[RAYS / 2];
	rayc->pp_y += (int)rayc->y_sin[RAYS / 2];
	if (rayc->map[(rayc->pp_y + (int)rayc->y_sin[RAYS / 2]) / 50]
		[(rayc->pp_x + (int)rayc->x_cos[RAYS / 2]) / 50] != '1')
		draw_rays(rayc);
	else
	{
		rayc->pp_x -= (int)rayc->x_cos[RAYS / 2];
		rayc->pp_y -= (int)rayc->y_sin[RAYS / 2];
	}
}

void	move_left(t_rayc *rayc)
{
	rayc->radian[RAYS / 2] = (rayc->angel[RAYS / 2] - 90) * (3.141593 / 180);
	rayc->x_cos[RAYS / 2] = cos(rayc->radian[RAYS / 2]) * 8;
	rayc->y_sin[RAYS / 2] = sin(rayc->radian[RAYS / 2]) * 8;
	rayc->pp_x += (int)rayc->x_cos[RAYS / 2];
	rayc->pp_y += (int)rayc->y_sin[RAYS / 2];
	if (rayc->map[(rayc->pp_y + (int)rayc->y_sin[RAYS / 2]) / 50]
		[(rayc->pp_x + (int)rayc->x_cos[RAYS / 2]) / 50] != '1')
		draw_rays(rayc);
	else
	{
		rayc->pp_x -= (int)rayc->x_cos[RAYS / 2];
		rayc->pp_y -= (int)rayc->y_sin[RAYS / 2];
	}
}

void	rotete_right(t_rayc *rayc)
{
	int	x;

	x = 0;
	while (x < RAYS)
	{
		rayc->angel[x] = rayc->angel[x] + 5;
		x++;
	}
	draw_rays(rayc);
}

void	rotete_left(t_rayc *rayc)
{
	int	x;

	x = 0;
	while (x < RAYS)
	{
		rayc->angel[x] = rayc->angel[x] - 5;
		x++;
	}
	draw_rays(rayc);
}
