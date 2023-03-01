/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:45:17 by afrigger          #+#    #+#             */
/*   Updated: 2023/03/01 13:56:13 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/mandelbrot.h"
#include "../headers/hook.h"

void	my_mlx_pixel_put(t_fractal *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->sizeline + x * (data->bitsperpixel / 8));
	*(unsigned int *)dst = color;
}

double	atod(char *str)
{
	double	res;
	double	res2;
	int		i;
	int		sign;

	res = 0.0;
	res2 = 0.0;
	i = -1;
	sign = 1;
	if (str[++i] == '-')
		sign = -1;
	while (str[++i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i] - '0');
	if (str[i] == '.')
		i = ft_strlen(str) - 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res2 += (str[i] - '0');
		res2 /= 10;
		i--;
	}
	return ((res + res2) * sign);
}

void	fractaltype(int argc, char **argv, t_fractal *mlx)
{		
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		mandelinit(mlx);
		mlx->type = 0;
		mandelbrot(mlx);
	}
	else if (ft_strncmp(argv[1], "julia", 5) == 0 && (argc == 4 || argc == 2))
	{
		set_base(argv, argc, mlx);
		juliainit(mlx);
		mlx->type = 1;
		julia(mlx);
	}
	else if (ft_strncmp(argv[1], "burningship", 11) == 0)
	{
		mandelinit(mlx);
		mlx->type = 2;
		burningship(mlx);
	}
	else
		error();
}

void	error(void)
{
	ft_putstr_fd("Please select a valid fractal(mandelbrot/julia/burningship)\n", 1);
	ft_putstr_fd("For julia, please insert constant\n", 1);
	ft_putstr_fd("Ex : ./fractol julia (0.420 0.69)", 1);
}

int	main(int argc, char **argv)
{
	t_fractal	mlx;

	if (argc > 1)
	{
		mlx.mlx = mlx_init();
		mlx.window = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "fract'ol");
		mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
		mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bitsperpixel,
				&mlx.sizeline, &mlx.endian);
		mlx.type = -1;
		fractaltype(argc, argv, &mlx);
		if (mlx.type < 0)
		{
			error();
			return (0);
		}
		mlx_hook(mlx.window, 02, 0, &hook, &mlx);
		mlx_hook(mlx.window, 17, 0, &fractol_exit, &mlx);
		mlx_mouse_hook(mlx.window, mouse_hook, &mlx);
		mlx_loop(mlx.mlx);
	}
	else
		error();
	return (0);
}
