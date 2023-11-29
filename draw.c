/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:41:41 by mel-amar          #+#    #+#             */
/*   Updated: 2023/11/18 17:42:35 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	dst = f->img.addr + (y * f->img.len + x * (f->img.bitp) / 8);
	*(unsigned int *)dst = color;
}

t_cmpl	get_const(t_fractol fractol, int x, int y)
{
	t_cmpl	tmp;

	tmp.re = (x - WIDTH / 2) * (4.0 / WIDTH * fractol.zoom) + fractol.move_x;
	tmp.im = (y - HEIGHT / 2) * (4.0 / HEIGHT * fractol.zoom) + fractol.move_y;
	return (tmp);
}

int	gen_color(int iteration)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iteration / MAX_IT;
	if (iteration >= MAX_IT)
		return (0);
	r = (int)(sin(2 * M_PI * t) * 127 + 128);
	g = (int)(sin(2 * M_PI * t + 2) * 127 + 128);
	b = (int)(sin(2 * M_PI * t + 4) * 127 + 128);
	return (r << 16 | g << 8 | b);
}

void	draw_fractol(t_fractol *fractol)
{
	int		x;
	int		y;
	int		color;
	t_cmpl	c;

	x = 0;
	while (x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			c = get_const(*fractol, x, y);
			if (!fractol->type)
				color = gen_color(mandelbrot(c, fractol->max_iter));
			else if (fractol->type == 1)
				color = gen_color(julia(*fractol, c, fractol->max_iter));
			else if (fractol->type == 2)
				color = gen_color(cubic_mandelbrot(c, fractol->max_iter));
			put_pixel(fractol, x, y, color);
			y++;
		}
		x++;
	}
}
