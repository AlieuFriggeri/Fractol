/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:37:48 by afrigger          #+#    #+#             */
/*   Updated: 2023/03/01 12:42:15 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/mandelbrot.h"

// base value are:
// rmin = -2.0 | rmax = 2.0 | imin = -1.5 | imax = 
//(mlx->rmax - mlx->rmin) * HEIGHT / WIDTH;

void	mandelinit(t_fractal *mlx)
{
	mlx->rmin = -2.0;
	mlx->rmax = 2.0;
	mlx->imin = -3.35;
	mlx->imax = (mlx->rmax - mlx->rmin) * HEIGHT / WIDTH;
	mlx->rfactor = (mlx->rmax - mlx->rmin) / (WIDTH);
	mlx->ifactor = (mlx->imax - mlx->imin) / (HEIGHT);
	mlx->itmax = 50;
	mlx->zoom = 260;
	mlx->yoff = 0;
	mlx->xoff = 0;
	mlx->ratio = 1.4;
	mlx->palette = 1;
	mlx->color_r = 1;
	mlx->color = 1;
}

void	juliainit(t_fractal *mlx)
{
	mlx->rmin = -2.0;
	mlx->rmax = 2.0;
	mlx->imin = -3.35;
	mlx->imax = (mlx->rmax - mlx->rmin) * HEIGHT / WIDTH;
	mlx->rfactor = (mlx->rmax - mlx->rmin) / (WIDTH);
	mlx->ifactor = (mlx->imax - mlx->imin) / (HEIGHT);
	mlx->itmax = 50;
	mlx->zoom = 260;
	mlx->yoff = 0;
	mlx->xoff = 0;
	mlx->ratio = 1.4;
	mlx->count = 0;
	mlx->palette = 1;
	mlx->color_r = 1;
	mlx->color = 1;
}

// void    juliainit(t_fractal *mlx)
// {
//     mlx->rmin = 2.0;
//     mlx->rmax = 2.0;
//     mlx->imin = -2.0;
//     mlx->imax = (mlx->rmax - mlx->rmin) * HEIGHT / WIDTH;
//     mlx->rfactor = (mlx->rmax - mlx->rmin) / (WIDTH);
//     mlx->ifactor = (mlx->imax - mlx->imin) / (HEIGHT);
//     mlx->itmax = 60;
//     mlx->zoom = 500;
//     mlx->yoff = -975;
//     mlx->xoff = -550;
//     mlx->yoff2 = 0;
//     mlx->xoff2 = 0;
//     mlx->ki = 0.210;
//     mlx->kr = 0.390;
//     mlx->ratio = 1.4;
//     mlx->count = 0;
// }
