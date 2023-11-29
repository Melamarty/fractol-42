/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:31:52 by mel-amar          #+#    #+#             */
/*   Updated: 2023/11/18 17:43:17 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_cmpl c, int max_it)
{
	t_cmpl	z;
	t_cmpl	t;
	int		i;

	z.im = 0;
	z.re = 0;
	i = 0;
	while (i < max_it)
	{
		t.re = z.re * z.re - z.im * z.im + c.re;
		t.im = 2 * z.re * z.im + c.im;
		z = t;
		if (((z.re * z.re) + (z.im * z.im)) >= __DBL_MAX__)
		{
			return (i);
		}
		i++;
	}
	return (max_it);
}

int	julia(t_fractol fractol, t_cmpl z, int max_it)
{
	int		i;
	t_cmpl	t;

	i = 0;
	while (i < max_it)
	{
		t.re = z.re * z.re - z.im * z.im + fractol.julia.re;
		t.im = 2 * z.re * z.im + fractol.julia.im;
		z = t;
		if (t.re * t.re + t.im * t.im >= __DBL_MAX__)
			return (i);
		i++;
	}
	return (max_it);
}
