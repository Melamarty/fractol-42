/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:31:31 by mel-amar          #+#    #+#             */
/*   Updated: 2023/11/18 17:41:35 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_win(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img.img);
	mlx_destroy_window(fractol->mlx, fractol->win);
	exit (0);
	return (0);
}

int	key_hook(int key, t_fractol *fractol)
{
	if (key == KEY_ESC)
		close_win(fractol);
	if (key == KEY_LEFT)
		fractol->move_x -= 0.2 * fractol->zoom;
	if (key == KEY_RIGHT)
		fractol->move_x += 0.2 * fractol->zoom;
	if (key == KEY_DOWN)
		fractol->move_y += 0.2 * fractol->zoom;
	if (key == KEY_TOP)
		fractol->move_y -= 0.2 * fractol->zoom;
	if (key == 49)
		fractol->active_mouse = !fractol->active_mouse;
	if (key == 0)
		init_fractol(fractol);
	render_image(fractol);
	return (0);
}

int	mouse_move(int x, int y, t_fractol *fractol)
{
	if (fractol->type == 1 && fractol->active_mouse)
	{
		fractol->julia = get_const(*fractol, x, y);
		render_image(fractol);
	}
	return (0);
}

int	mouse_hook(int key, int x, int y, t_fractol *fractol)
{
	t_cmpl	old_const;
	t_cmpl	new_cmpl;

	old_const = get_const(*fractol, x, y);
	if (key == 4)
	{
		fractol->zoom *= 1.2;
		new_cmpl = get_const(*fractol, x, y);
		fractol->move_x += old_const.re - new_cmpl.re;
		fractol->move_y += old_const.im - new_cmpl.im;
	}
	else if (key == 5)
	{
		fractol->zoom *= 0.8;
		new_cmpl = get_const(*fractol, x, y);
		fractol->move_x += old_const.re - new_cmpl.re;
		fractol->move_y += old_const.im - new_cmpl.im;
	}
	render_image(fractol);
	return (0);
}
