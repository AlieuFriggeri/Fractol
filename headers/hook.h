/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:50:15 by afrigger          #+#    #+#             */
/*   Updated: 2022/11/21 10:48:20 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
#define HOOK_H
#include "mandelbrot.h"

int fractol_exit(t_fractal *mlx);
int	hook(int keycode, t_fractal *mlx);
int mouse_hook(int keycode, int x, int y, t_fractal *mlx);
int ratio(int keycode, t_fractal *mlx);

#endif
