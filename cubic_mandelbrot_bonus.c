/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubic_mandelbrot_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:10:45 by mel-amar          #+#    #+#             */
/*   Updated: 2023/11/18 17:40:38 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	cubic_mandelbrot(t_cmpl c, int max_iter)
{
	int			i;
	t_cmpl		z;
	t_cmpl		tmp;

	i = 0;
	z.im = 0;
	z.re = 0;
	while (i < max_iter)
	{
		tmp.re = z.re * z.re * z.re - 3 * z.re * z.im * z.im + c.re;
		tmp.im = 3 * z.re * z.re * z.im - z.im * z.im * z.im + c.im;
		z = tmp;
		i++;
		if ((z.re * z.re + z.im * z.im) > 4)
			return (i);
	}
	return (i);
}
