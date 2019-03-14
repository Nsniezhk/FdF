/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsniezhk <nsnizhk@student.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:55:00 by nsniezhk          #+#    #+#             */
/*   Updated: 2018/10/04 12:55:02 by nsniezhk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include "ft_printf.h"
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

/*
** CREATES 2D ARRAY OF INTS AND SAVE (Z) VALUE OF MAP
*/

static	int		**file_proceed(char *file, t_point *size, int fd)
{
	int			**xyz;
	char		**nums;
	char		*line;
	t_point		i;

	i.y = -1;
	fd = open(file, O_RDONLY);
	if (!(xyz = ft_memalloc(sizeof(int*) * size->y)))
		return (0);
	while (++i.y < size->y)
		if (!(xyz[i.y] = ft_memalloc(sizeof(int) * size->x)))
			return (0);
	i.y = 0;
	while (get_next_line(fd, &line))
	{
		i.x = -1;
		nums = ft_strsplit(line, ' ');
		while (++i.x < size->x)
			xyz[i.y][i.x] = ft_atoi(nums[i.x]);
		i.y++;
		ft_splitdel(&nums);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (xyz);
}

/*
** INITIALIZE WINDOW AND MLX
*/

static	t_mlx	*window_init(char *title, int **xyz, t_point *size)
{
	t_mlx	*mlx;

	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
	{
		ft_strdel(&title);
		return (NULL);
	}
	if ((mlx->mlx = mlx_init()) == NULL ||
		(mlx->window = mlx_new_window(mlx->mlx, 1280, 720, title)) == NULL)
	{
		ft_strdel(&title);
		return (NULL);
	}
	ft_strdel(&title);
	mlx->scale = 1;
	mlx->color = 0x0CFF00;
	mlx->xyz = &(*xyz);
	mlx->m_size = &(*size);
	return (mlx);
}

/*
** PROCEEDS KEYBORD EVENT
*/

static	int		key_hook(int key, t_mlx *mlx)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	else if (key == 18)
		mlx->color = 0x0CFF00;
	else if (key == 19)
		mlx->color = 0xFFCF00;
	else if (key == 20)
		mlx->color = 0xFF0000;
	else if (key == 21)
		mlx->color = 0x00FFF2;
	render(mlx);
	return (1);
}

/*
** ERROR MENEGMENT
*/

static	int		return_error(int error, int er)
{
	if (error == EISDIR)
	{
		ft_printf("\x1b[31m""[FdF] ERROR: ");
		ft_printf("\x1b[33m""directory as argument!\n");
		return (0);
	}
	if (error == ENOENT)
	{
		ft_printf("\x1b[31m""[FdF] ERROR: ");
		ft_printf("\x1b[33m""File is not valid or doesn't exist!\n");
		return (0);
	}
	if (er == 1)
	{
		ft_printf("\x1b[31m""[FdF] ERROR: ");
		ft_printf("\x1b[33m""Wrong number of arguments!\n");
		return (0);
	}
	if (er == 2)
	{
		ft_printf("\x1b[31m""[FdF] ERROR: ");
		ft_printf("\x1b[33m""MLX Initialization failed!");
		return (0);
	}
	return (ft_printf("\x1b[31m""[FdF] UNDEFINED ERROR!\n"));
}

int				main(int argc, char **argv)
{
	t_point		p;
	t_mlx		*mlx;
	int			**xyz;

	p.x = 0;
	p.y = 0;
	if (argc != 2)
		return (return_error(0, 1));
	if (!(file_check(argv[1], &p)))
		return (return_error(errno, 0));
	if (!(xyz = file_proceed(argv[1], &p, 0)))
		return (0);
	if ((mlx = window_init(ft_strjoin("FdF - ", argv[1]), xyz, &p)) == NULL)
		return (0);
	while (mlx->scale * p.x < (1280 / 2) && mlx->scale * p.y < (720 / 2))
		mlx->scale++;
	mlx_key_hook(mlx->window, &key_hook, &(*mlx));
	render(mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
