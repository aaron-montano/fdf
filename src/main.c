/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 04:21:01 by amontano          #+#    #+#             */
/*   Updated: 2018/07/10 06:31:53 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		error(char *error_message)
{
	ft_putendl(error_message);
	exit(1);
}

t_mlx	*mlx_dispose(t_mlx *mlx)
{
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->view)
		ft_memdel((void	**)&mlx->view);
	if (mlx->mouse)
		ft_memdel((void **)&mlx->mouse);
	if (mlx->img)
		del_img(mlx, mlx->img);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_mlx	*init(char *clickbait)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->mlx = mlx_init()) \
		|| (!(mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, clickbait))) \
		|| (!(mlx->view = ft_memalloc(sizeof(t_view))))	\
		|| (!(mlx->mouse = ft_memalloc(sizeof(t_mouse))))	\
		|| (!(mlx->img = new_img(mlx))))
		return (mlx_dispose(mlx));
	mlx->view->x = 0.0;
	mlx->view->y = 0.0;
	mlx->view->z = 0.0;
	mlx->view->context = 36;
	mlx->view->rot_speed = 1;
	mlx->view->x_off = WIN_W / 2;
	mlx->view->y_off = WIN_H / 2;
	return (mlx);
}

int		main(int argc, char **argv)
{
	t_map	*map;
	t_mlx	*mlx;
	int		fd;
	char	*clickbait;

	clickbait = ft_strjoin("FdF - ", argv[1]);
	if (argc < 2)
		error("No arguments!");
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		error("No file!");
	if (read_file(fd, &map) == 0)
		error("Invalid file!");
	if ((mlx = init(clickbait)) == NULL)
		error("mlx failed to init!");
	free(clickbait);
	mlx->map = map;
	close(fd);
	mlx_key_hook(mlx->win, hook_keydown, mlx);
	mlx_hook(mlx->win, 2, 0, hook_key_pressed, mlx);
	mlx_hook(mlx->win, 4, 0, hook_mousedown, mlx);
	mlx_hook(mlx->win, 5, 0, hook_mouseup, mlx);
	mlx_hook(mlx->win, 6, 0, hook_mousemove, mlx);
	mlx_loop_hook(mlx->mlx, &rend, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
