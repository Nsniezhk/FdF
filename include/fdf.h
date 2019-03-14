/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsniezhk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:55:09 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/10/04 12:55:12 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef	struct	s_mlx
{
	void		*mlx;
	void		*window;
	int			**xyz;
	int			scale;
	int			color;
	t_point		*m_size;
}				t_mlx;

typedef struct	s_spec
{
	int			dx;
	int			dy;
	int			xi;
	int			yi;
	int			x;
	int			y;
	int			error;
}				t_spec;

int				file_check(char *file, t_point *p);
void			render(t_mlx *mlx);

#endif
