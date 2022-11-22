/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:51:47 by afrigger          #+#    #+#             */
/*   Updated: 2022/11/21 15:10:49 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/mandelbrot.h"
#include "../headers/colors.h"

void	mandelcalc(t_fractal *mlx, int x, int y)
{
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;
	int		i;

	i = -1;
	zr = mlx->cr;
	zi = mlx->ci;
	while (++i < mlx->itmax)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if (zr2 + zi2 > 4)
			break ;
		zi = 2 * zr * zi + mlx->ci;
		zr = zr2 - zi2 + mlx->cr;
	}
	put_color(mlx, x, y, i);
}

void	mandelbrot(t_fractal *mlx)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < HEIGHT)
	{
		mlx->ci = (y + mlx->yoff) / mlx->zoom + mlx->rmin ;
		//mlx->imax - y * mlx->ifactor ;
		while (++x < WIDTH)
		{
			mlx->cr = (x + mlx->xoff) / mlx->zoom + mlx->imin;
			//mlx->rmin + x * mlx->rfactor ;
			mandelcalc(mlx, x, y);
		}
		x = -1;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
}

