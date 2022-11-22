/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:13:03 by afrigger          #+#    #+#             */
/*   Updated: 2022/11/22 12:29:21 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include "mandelbrot.h"

# define RED				0x610000
# define BLUE				0x000033
# define GREEN				0x377D14
# define WHITE				0xFFFFFF
# define BROWN				0x180002
# define BLACK				0x000000
# define ORANGE				0xE6C832
# define YELLOW				0xFFFF00
# define TRUE_RED			0xFF0000
# define PURPLE 			0x8000FF

void	put_color(t_fractal *mlx, int x, int y, int i);

#endif
