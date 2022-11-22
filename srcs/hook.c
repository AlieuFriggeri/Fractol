/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:50:35 by afrigger          #+#    #+#             */
/*   Updated: 2022/11/22 12:26:26 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot.h"

int	fractol_exit(t_fractal *mlx)
{
	if (mlx->mlx && mlx->window)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->mlx && mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	exit(0);
}

void	zoom(int keycode, t_fractal *mlx)
{
	if (keycode == 4)
	{
		mlx->ratio *= 1.5;
		mlx->xoff += 370 * mlx->ratio;
		mlx->yoff += 207 * mlx->ratio;
		mlx->zoom += 100 * mlx->ratio;
		mlx->itmax += 4;
	}
	else if (keycode == 5)
	{
		mlx->xoff -= 370 * mlx->ratio;
		mlx->yoff -= 207 * mlx->ratio;
		mlx->zoom -= 100 * mlx->ratio;
		mlx->itmax -= 4;
		mlx->ratio -= (mlx->ratio / 3);
		if (mlx->ratio < 1)
			mlx->ratio = 1;
	}
}

int	mouse_hook(int keycode, int x, int y, t_fractal *mlx)
{
	(void) x;
	(void) y;
	if (keycode == 4)
		zoom(keycode, mlx);
	else if (keycode == 5)
		zoom(keycode, mlx);
	if (mlx->type == 0)
		mandelbrot(mlx);
	else if (mlx->type == 1)
		julia(mlx);
	else if (mlx->type == 2)
		burningship(mlx);
	return (0);
}

void	render(t_fractal *mlx)
{
	if (mlx->type == 0)
		mandelbrot(mlx);
	else if (mlx->type == 1)
		julia(mlx);
	else if (mlx->type == 2)
		burningship(mlx);
}

int	hook(int keycode, t_fractal *mlx)
{
	if (keycode == 53)
		fractol_exit(mlx);
	else if (keycode == 126)
		mlx->rmin += 0.15 / mlx->ratio;
	else if (keycode == 125)
		mlx->rmin -= 0.15 / mlx->ratio;
	else if (keycode == 123)
		mlx->imin -= 0.12 / mlx->ratio;
	else if (keycode == 124)
		mlx->imin += 0.12 / mlx->ratio;
	else if (keycode == 27 && mlx->type == 1)
	{
		mlx->kr -= 0.01;
		mlx->ki -= 0.01;
	}
	else if (keycode == 24 && mlx->type == 1)
	{
		mlx->kr += 0.01;
		mlx->ki += 0.01;
	}
	render(mlx);
	return (0);
}

//*********************************************************

// int	julia_hook(int keycode, t_fractal *mlx)
// {
// 	if (keycode == 53)
// 		fractol_exit(mlx);
// 		//fleche du haut
// 	else if (keycode == 126)
// 	{
// 		// // (pour se deplacer en haut)
// 		// //mlx->yoff += 0.1;
// 		// mlx->ratio *= 1.5;
// 		// mlx->imin += 20 * mlx->ratio;
// 		// mlx->rmin += 20 * mlx->ratio;
// 		// // if (mlx->count != 0)
// 		// // {
// 		// // 	mlx->xoff += 300;
// 		// // 	mlx->yoff += 300;
// 		// // }
// 		// mlx->itmax += 2;
// 		// //mlx->itmax += 10;
// 		// //mandelbrot(mlx);
// 		mlx->ratio *= 1.5;
// 		//mlx->xoff += 370 * mlx->ratio;
// 		//mlx->yoff += 207 * mlx->ratio;
// 		mlx->zoom += 100 * mlx->ratio;
// 		mlx->itmax += 4;
// 	}
// 	//fleche du bas
// 	else if (keycode == 125)
// 	{
// 		// // (pour se deplacer en bas)
// 		// //mlx->yoff += 0.1;
// 		// mlx->imin -= 20 * mlx->ratio;
// 		// mlx->rmin -= 20 * mlx->ratio;
// 		// mlx->itmax -= 2;
// 		// mlx->ratio -= (mlx->ratio / 3);
// 		// if (mlx->ratio < 1)
// 		// 	mlx->ratio = 1;
// 		// //mlx->itmax -= 10;
// 		// //mandelbrot(mlx);
// 		//mlx->xoff -= 370 * mlx->ratio;
// 		//mlx->yoff -= 207 * mlx->ratio;
// 		mlx->zoom -= 100 * mlx->ratio;
// 		mlx->itmax -= 4;
// 		mlx->ratio -= (mlx->ratio / 3);
// 		if (mlx->ratio < 1)
// 			mlx->ratio = 1;
// 	}
// 	//fleche de gauche
// 	else if (keycode == 123)
// 	{
// 		// (pour se deplacer a gauche)
// 		mlx->rmin += 10.2;
// 		//mlx->rmin += mlx->xoff / mlx->zoom;
// 		//mandelbrot(mlx);
// 	}
// 	//fleche de droite
// 	else if (keycode == 124)
// 	{
// 		// (pour se deplacer a droite)
// 		mlx->rmin -= 10.2;
// 		//mlx->rmin -= mlx->xoff / mlx->zoom;
// 		//mandelbrot(mlx);
// 	}
// 	//touche 1
// 	else if (keycode == 18)
// 	{
// 		// mlx->rfactor /= 0.9 ;
// 		// mlx->ifactor /= 0.9 ;
// 		// mlx->rmax /= 0.9;
// 		// mlx->imax /= 0.9;
// 		//mlx->rmax += 0.5;
// 		//mlx->ratio += 0.5;
// 		mlx->ci -= 1;
// 	}
// 	//touche 2
// 	else if (keycode == 19)
// 	{
// 		// mlx->rfactor *= 0.9;
// 		// mlx->ifactor *= 0.9;
// 		// mlx->rmax *= 0.9;
// 		// mlx->imax *= 0.9;
// 		//mlx->rmax -= 0.5;
// 		mlx->ci += 1;
// 	}
// 	//touche 3
// 	else if (keycode == 20)
// 	{
// 		//mlx->zoom -= 0.01;
// 		mlx->ifactor /= 0.9 * mlx->zoom;
// 		//mlx->ifactor += mlx->yoff / mlx->zoom;
// 		mlx->rfactor /= 0.9 * mlx->zoom;
// 		//mlx->rfactor += mlx->xoff / mlx->zoom;
// 		mlx->rmin /= 0.9 * mlx->zoom;
//     	mlx->rmax /= (0.9 * mlx->zoom) ;
// 		mlx->imin /= (0.9 * mlx->zoom) ;
// 		mlx->imax = (mlx->rmax - mlx->rmin) * HEIGHT / WIDTH;
// 		//mlx->itmax -= 1;
// 		//mlx->rmin += 0.1 * mlx->zoom;
// 		//mlx->imax -= 0.1 * mlx->zoom;
// 		//mlx->imin += 0.5;
// 	}
// 	//touche 4
// 	else if (keycode == 21)
// 	{
// 		//mlx->zoom += 0.01;
// 		mlx->ifactor *= 0.9 * mlx->zoom;
// 		//mlx->ifactor += mlx->yoff / mlx->zoom;
// 		mlx->rfactor *= 0.9 * mlx->zoom;
// 		//mlx->rfactor += mlx->xoff / mlx->zoom;
// 		mlx->rmin *= 0.9 * mlx->zoom;
// 		mlx->rmax *= 0.9 * mlx->zoom;
// 		mlx->imin *= 0.9 * mlx->zoom;
// 		mlx->imax = (mlx->rmax - mlx->rmin) * HEIGHT / WIDTH;
// 		//mlx->itmax += 1;
// 		//mlx->rmin -= 0.1 * mlx->zoom;
// 		//mlx->imax += 0.1 * mlx->zoom;
// 		//mlx->imin -= 0.5;
// 	}
// 	//touche 5
// 	else if(keycode == 23)
// 	{
// 		//mlx->xoff -= 5 * mlx->ratio;
// 		//mlx->yoff -= 5 * mlx->ratio;
// 		//mlx->zoom -= 100 * mlx->ratio;
// 		mlx->itmax -= 3;
// 		mlx->rmin -= 100 * mlx->ratio;
// 		mlx->imin -= 100 * mlx->ratio;
// 		mlx->ratio -= (mlx->ratio / 3);
// 		if (mlx->ratio < 1)
// 			mlx->ratio = 1;
// 	}
// 	//touche 6
// 	else if (keycode == 22)
// 	{
// 		mlx->ratio *= 1.5;
// 		mlx->xoff += 100 * mlx->ratio;
// 		mlx->yoff += 100 * mlx->ratio;
// 		//mlx->zoom += 100 * mlx->ratio;
// 		mlx->rmin += 100 * mlx->ratio;
// 		mlx->imin += 100 * mlx->ratio;
// 		mlx->itmax += 3;
// 	}
// 	//touche 7
// 	else if (keycode == 26)
// 	{
// 		 mlx->xoff += 50;
// 		 mlx->count++;
// 	}
// 	//touche 8
// 	else if(keycode == 28)
// 	{
// 		 mlx->xoff -= 50;
// 		 mlx->count--;
// 	}
// 	// touche 9
// 	else if(keycode == 25)
// 	{
// 		mlx->yoff += 50;
// 		mlx->count++;
// 	}
// 	//touche 0
// 	else if(keycode == 29)
// 	{
// 		mlx->yoff -= 50;
// 		mlx->count--;
// 	}
// 	// touche k
// 	else if(keycode == 40)
// 	{
// 		mlx->kr -= 0.01;
// 		mlx->ki -= 0.01;
// 	}
// 	//touche L
// 	else if(keycode == 37)
// 	{
// 		mlx->kr += 0.01;
// 		mlx->ki += 0.01;
// 	}
// 		julia(mlx);
// 	return (0);
// }