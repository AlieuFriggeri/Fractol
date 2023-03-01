/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:11:42 by afrigger          #+#    #+#             */
/*   Updated: 2023/03/01 11:22:12 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/colors.h"

void	put_color(t_fractal *mlx, int x, int y, int i)
{
	if (i == mlx->itmax)
	{
		if (mlx->palette == 1)
			my_mlx_pixel_put(mlx, x, y, RED);
		else if (mlx->palette == 2)
			my_mlx_pixel_put(mlx, x, y, BLUE);
		else if (mlx->palette == 3)
			my_mlx_pixel_put(mlx, x, y, GREEN);
		else if (mlx->palette == 4)
			my_mlx_pixel_put(mlx, x, y, ORANGE);
		else if (mlx->palette == 5)
			my_mlx_pixel_put(mlx, x, y, 0xFF00F0);
	}		
	else
		my_mlx_pixel_put(mlx, x, y, mlx->color);
}

int	choose_color(int iter, double zr2, double zi2, t_fractal *data)
{
	double	ratio;

	ratio = ((double)iter + 3 - log(log(zr2 + zi2)) / M_LN2) / 20;
	ratio /= 3.33;
	return (encode_rgb(data, ratio));
}

int	encode_rgb(t_fractal *data, double ratio)
{
	int	color;

	color = 0;
	if (data->color_r != 0)
		color += (int)(ratio * 255) << 16;
	if (data->color_g != 0)
		color += (int)(ratio * 255) << 8;
	if (data->color_b != 0)
		color += (int)(ratio * 255);
	return (color);
}

void	palette_change(int keycode, t_fractal *mlx)
{
	if (keycode == 18)
		mlx->palette = 1;
	else if (keycode == 19)
		mlx->palette = 2;
	else if (keycode == 20)
		mlx->palette = 3;
	else if (keycode == 21)
		mlx->palette = 4;
	else if (keycode == 23)
		mlx->palette = 5;
	set_rgb(mlx);
}

void	set_rgb(t_fractal *mlx)
{
	mlx->color_r = 0;
	mlx->color_g = 0;
	mlx->color_b = 0;
	if (mlx->palette == 1)
		mlx->color_r = 1;
	else if (mlx->palette == 2)
		mlx->color_b = 1;
	else if (mlx->palette == 3)
		mlx->color_g = 1;
	else if (mlx->palette == 4)
	{
		mlx->color_g = 1;
		mlx->color_r = 1;
	}
	else if (mlx->palette == 5)
	{
		mlx->color_r = 1;
		mlx->color_b = 1;
	}
}
