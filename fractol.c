/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:10:00 by mel-amar          #+#    #+#             */
/*   Updated: 2023/11/18 18:26:10 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_window(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&(fractol->img.bitp), &(fractol->img.len),
			&(fractol->img.endian));
}

void	render_image(t_fractol *fractol)
{
	draw_fractol(fractol);
	mlx_clear_window(fractol->mlx, fractol->win);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}

void	init_fractol(t_fractol *fractol)
{
	fractol->zoom = 1;
	fractol->move_x = 0;
	fractol->move_y = 0;
	fractol->max_iter = MAX_IT;
}

void	display_guide(void)
{
	write(1, "\033[1;32m========== guide ============\n", 37);
	write(1, "\033[1;32mzoom        : mouse wheel\n", 33);
	write(1, "\033[1;32mimage move  : arrow keys\n", 32);
	write(1, "\033[1;32mquit        : ESC\n\n", 26);
	write(1, "\033[1;32mif you work with julia press enter ", 42);
	write(1, "\033[1;32mthen move the mouse to change constante\n", 47);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	fractol.mlx = NULL;
	if (!check_args(&fractol, ac, av))
	{
		write(2, "\033[1;31margument error.\n", 23);
		write(2, "\033[1;33mtype\t./fractol julia [re] [im]\n", 38);
		write(2, "\033[1;33m\t./fractol mandelbrot\n", 29);
		write(2, "\033[1;33m\t./fractol cubic_mandelbrot\033[0m\n", 39);
		return (1);
	}
	display_guide();
	fractol.img.len = -1;
	init_window(&fractol);
	fractol.win = mlx_new_window(fractol.mlx, WIDTH, HEIGHT, "fractol");
	init_fractol(&fractol);
	render_image(&fractol);
	mlx_mouse_hook(fractol.win, mouse_hook, &fractol);
	mlx_hook(fractol.win, 6, (1L << 6), mouse_move, &fractol);
	mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.img.img, 0, 0);
	mlx_hook(fractol.win, 17, 0, close_win, &fractol);
	mlx_hook(fractol.win, 2, 0, key_hook, &fractol);
	mlx_loop(fractol.mlx);
}
