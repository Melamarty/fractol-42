/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:47:03 by mel-amar          #+#    #+#             */
/*   Updated: 2023/11/18 17:41:18 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_complex
{
	double	re;
	double	im;
}	t_cmpl;

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bitp;
	int		endian;
	int		len;
}	t_img;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_cmpl	cmpl;
	t_cmpl	julia;
	int		exist_pm;
	int		type;
	int		width;
	int		height;
	double	zoom;
	double	move_x;
	double	move_y;
	int		max_iter;
	int		active_mouse;
}	t_fractol;

# define WIDTH 650
# define HEIGHT 650
# define MAX_IT 100
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_TOP 126

void	init_fractol(t_fractol *fractol);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *str);
int		check_args(t_fractol	*fractol, int ac, char **av);
int		mouse_hook(int key, int x, int y, t_fractol *fractol);
int		key_hook(int key, t_fractol *fractol);
int		mouse_move(int x, int y, t_fractol *fractol);
int		close_win(t_fractol *fractol);
void	draw_fractol(t_fractol *fractol);
int		mandelbrot(t_cmpl c, int max_it);
int		julia(t_fractol fractol, t_cmpl z, int max_it);
int		cubic_mandelbrot(t_cmpl c, int max_it);
t_cmpl	get_const(t_fractol fractol, int x, int y);
void	render_image(t_fractol *fractol);

#endif
