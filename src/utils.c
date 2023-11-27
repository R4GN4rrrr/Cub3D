/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 06:12:19 by aelbouaa          #+#    #+#             */
/*   Updated: 2023/11/27 22:20:46 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse/Cub3D.h"

void	draw_floor(t_rayc *rayc, t_txtr *txtr)
{
	while (txtr->inc + txtr->i < WINDOW_HIEGHT)
	{
		my_mlx_pixel_put(rayc->data[0],
			txtr->inc + txtr->i, txtr->y, 0x808080);
		txtr->inc++;
	}
}

void	get_wich_textures(t_rayc *rayc, int x)
{
	if (rayc->dir[x] == 'S')
		rayc->dir_tex = 1;
	else if (rayc->dir[x] == 'N')
		rayc->dir_tex = 2;
	else if (rayc->dir[x] == 'E')
		rayc->dir_tex = 3;
	else if (rayc->dir[x] == 'W')
		rayc->dir_tex = 4;
}

int	ft_close(int event, t_rayc *rayc)
{
	(void)event;
	(void)rayc;
	// ft_free(rayc->map);
	exit (1);
	return (0);
}

double	dist(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
