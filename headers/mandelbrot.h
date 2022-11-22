/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:16:44 by afrigger          #+#    #+#             */
/*   Updated: 2022/11/22 12:20:09 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_H
# define MANDELBROT_H

# include "../mlx_macos/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define HEIGHT 1080
# define WIDTH 1920
# define IMAX 70

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	int		endian;
	int		sizeline;
	int		bitsperpixel;
	int		itmax;
	double	rmin;
	double	imin;
	double	rmax;
	double	imax;
	double	rfactor;
	double	ifactor;
	double	cr;
	double	ci;
	double	zoom;
	double	xoff;
	double	yoff;
	double	kr;
	double	ki;
	double	ratio;
	int		type;
	int		count;
}	t_fractal;

void	my_mlx_pixel_put(t_fractal *data, int x, int y, int color);
void	mandelcalc(t_fractal *mlx, int x, int y);
void	mandelbrot(t_fractal *mlx);
void	julia(t_fractal *mlx);
void	juliacalc(t_fractal *mlx, int x, int y);
int		hook(int keycode, t_fractal *mlx);
void	mandelinit(t_fractal *mlx);
void	juliainit(t_fractal *mlx);
void	burningship(t_fractal *mlx);	
void	burningcalc(t_fractal *mlx, int x, int y);
void	error(void);
void	fractaltype(int argc, char **argv, t_fractal *mlx);
void	render(t_fractal *mlx);

#endif