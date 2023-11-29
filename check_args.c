/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:38:03 by mel-amar          #+#    #+#             */
/*   Updated: 2023/11/18 18:34:29 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_not_nb(char *str)
{
	int	p;
	int	i;

	i = 0;
	p = 0;
	if (str[0] == '-' && (str[1] < '0' || str[1] > '9'))
		return (1);
	else if (str[0] == '-')
		i++;
	if (str[i] == '.')
		return (1);
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	{
		if (str[i] == '.')
			p++;
		i++;
	}
	if (p > 1 || (str[i - 1] && str[i - 1] == '.'))
		return (1);
	return ((int )str[i]);
}

double	get_double(int nb, int positive)
{
	int		i;
	int		tmp;
	double	res;

	if (!nb)
		return (0);
	tmp = nb;
	i = 0;
	while (tmp > 0)
	{
		i++;
		tmp /= 10;
	}
	res = 0.1;
	while (i > 1)
	{
		res = res * 0.1;
		i--;
	}
	if (positive)
		return (res * nb);
	return (-1 * res * nb);
}

int	parse_julia(char **av, t_fractol *fractol)
{
	char	*tmp;
	int		nb;

	if (is_not_nb(av[2]) || is_not_nb(av[3]))
		return (0);
	tmp = av[2];
	while ((*tmp && *tmp != '.' ) || *tmp == '-')
		tmp++;
	nb = ft_atoi(av[2]);
	fractol->julia.re = nb + get_double(ft_atoi(++tmp), av[2][0] != '-');
	tmp = av[3];
	while ((*tmp && *tmp != '.') || *tmp == '-')
		tmp++;
	nb = ft_atoi(av[3]);
	fractol->julia.im = nb + get_double(ft_atoi(++tmp), av[3][0] != '-');
	fractol->type = 1;
	fractol->active_mouse = 0;
	return (1);
}

int	check_args(t_fractol *fractol, int ac, char **av)
{
	if (ac >= 2)
	{
		if (!ft_strcmp(av[1], "mandelbrot") && ac == 2)
			fractol->type = 0;
		else if (!ft_strcmp(av[1], "julia") && ac == 4)
			return (parse_julia(av, fractol));
		else if (!ft_strcmp(av[1], "julia") && ac == 2)
		{
			fractol->julia.re = 0;
			fractol->julia.im = 0.8;
			fractol->type = 1;
			return (1);
		}
		else if (!ft_strcmp(av[1], "cubic_mandelbrot") && ac == 2)
			fractol->type = 2;
		else
			return (0);
		return (1);
	}
	return (0);
}
