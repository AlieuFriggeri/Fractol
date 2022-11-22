/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:11:42 by afrigger          #+#    #+#             */
/*   Updated: 2022/11/21 15:05:12 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/colors.h"

void	put_color(t_fractal *mlx, int x, int y, int i)
{
	if (i == mlx->itmax)
		my_mlx_pixel_put(mlx, x, y, PURPLE);
	else if (i >= mlx->itmax * 0.9)
		my_mlx_pixel_put(mlx, x, y, PURPLE + 85000);
	else if (i >= mlx->itmax * 0.8)
		my_mlx_pixel_put(mlx, x, y, PURPLE + 71000);
	else if (i >= mlx->itmax * 0.7)
		my_mlx_pixel_put(mlx, x, y, PURPLE + 61500);
	else if (i >= mlx->itmax * 0.6)
		my_mlx_pixel_put(mlx, x, y, PURPLE + 52000);
	else if (i >= mlx->itmax * 0.5)
		my_mlx_pixel_put(mlx, x, y, PURPLE + 42500);
	else if (i >= mlx->itmax * 0.4)
		my_mlx_pixel_put(mlx, x, y, PURPLE + 33000);
	else if (i >= mlx->itmax * 0.3)
		my_mlx_pixel_put(mlx, x, y, PURPLE + 23500);
	else if (i >= mlx->itmax * 0.2)
		my_mlx_pixel_put(mlx, x, y, PURPLE + 14000);
	else
		my_mlx_pixel_put(mlx, x, y, BLACK);
}
