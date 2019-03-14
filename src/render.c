/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsnizhk@student.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:55:45 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/10/04 12:55:47 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <math.h>

/*
** BRESENHAM ALGORYTHM (for integer arythmetics)
*/

static	void		line_goes_up(t_mlx *mlx, t_point p0, t_point p1)
{
	t_spec	s;

	s.dx = p1.x - p0.x;
	s.dy = p1.y - p0.y;
	s.xi = 1;
	if (s.dx < 0)
	{
		s.xi = -1;
		s.dx *= -1;
	}
	s.error = 2 * (s.dx - s.dy);
	s.y = p0.x;
	while (p0.y < p1.y)
	{
		if (s.y > 0 && s.y < 1280 && p0.y > 0 && p0.y < 720)
			mlx_pixel_put(mlx->mlx, mlx->window, s.y, p0.y, mlx->color);
		if (s.error > 0)
		{
			s.y = s.y + s.xi;
			s.error = s.error - (2 * s.dy);
		}
		s.error = s.error + (2 * s.dx);
		p0.y++;
	}
}

static	void		line_goes_down(t_mlx *mlx, t_point p0, t_point p1)
{
	t_spec	s;

	s.dx = (p1.x - p0.x);
	s.dy = (p1.y - p0.y);
	s.yi = 1;
	if (s.dy < 0)
	{
		s.yi = -1;
		s.dy *= -1;
	}
	s.error = 2 * (s.dy - s.dx);
	s.x = p0.y;
	while (p0.x < p1.x)
	{
		if (p0.x > 0 && p0.x < 1280 && s.x > 0 && s.x < 720)
			mlx_pixel_put(mlx->mlx, mlx->window, p0.x, s.x, mlx->color);
		if (s.error > 0)
		{
			s.x = s.x + s.yi;
			s.error = s.error - (2 * s.dx);
		}
		s.error = s.error + (2 * s.dy);
		p0.x++;
	}
}

static	void		line(t_mlx *mlx, t_point p0, t_point p1)
{
	t_point	spec;

	spec.x = 0;
	if (ft_abs(p1.y - p0.y) < ft_abs(p1.x - p0.x))
	{
		if (p0.x > p1.x)
			line_goes_down(mlx, p1, p0);
		else
			line_goes_down(mlx, p0, p1);
	}
	else
	{
		if (p0.y > p1.y)
			line_goes_up(mlx, p1, p0);
		else
			line_goes_up(mlx, p0, p1);
	}
}

static	t_point		place_line(t_point p, int zp, t_mlx *mlx)
{
	t_point		v;
	double		x;
	double		y;
	double		z;

	x = p.x - (mlx->m_size->x - 1) / 2;
	v.x = ((cos(0.5) * x - sin(0.5) * zp) * mlx->scale) + (1280 / 2);
	z = sin(0.5) * x + cos(0.5) * zp;
	y = p.y - (mlx->m_size->y - 1) / 2;
	v.y = ((cos(0.5) * y + sin(0.5) * z) * mlx->scale) + (720 / 2);
	return (v);
}

void				render(t_mlx *mlx)
{
	t_point	p0;
	t_point	p1;

	p0.y = -1;
	while (++p0.y < mlx->m_size->y)
	{
		p0.x = -1;
		while (++p0.x < mlx->m_size->x)
		{
			if (p0.x + 1 < mlx->m_size->x)
			{
				p1.x = p0.x + 1;
				p1.y = p0.y;
				line(mlx, place_line(p0, mlx->xyz[p0.y][p0.x], mlx),
					place_line(p1, mlx->xyz[p0.y][p1.x], mlx));
			}
			if (p0.y + 1 < mlx->m_size->y)
			{
				p1.x = p0.x;
				p1.y = p0.y + 1;
				line(mlx, place_line(p0, mlx->xyz[p0.y][p0.x], mlx),
					place_line(p1, mlx->xyz[p1.y][p0.x], mlx));
			}
		}
	}
}
