/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:36:11 by mibernar          #+#    #+#             */
/*   Updated: 2022/10/17 14:03:26 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update(t_game *mlx)
{
	if (mlx->player.frames > 60)
	{
		mlx->player.current_img = mlx->player.player_img_2;
		if (mlx->player.frames == 120)
			mlx->player.frames = 0;
	}
	else
		mlx->player.current_img = mlx->player.player_img;
	mlx->player.frames += 1;
	put_tiles(*mlx);
	return (1);
}

void	game_init(t_game *mlx)
{
	mlx->map = generate_tilemap(mlx->map_tiles, mlx);
	mlx->mlx_ptr = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx_ptr, (mlx->map_info.size.x * 64),
			(mlx->map_info.size.y * 64), "so_long");
	mlx_hook(mlx->window, 17, 0L, close_window, mlx);
	open_imgs(mlx);
	put_tiles(*mlx);
}

void	get_map(t_game *mlx, int fd, char *path)
{
	int		lines;
	int		x;

	lines = number_lines(fd);
	mlx->map_tiles = (char **)malloc(sizeof(char *) * lines);
	if (!mlx->map_tiles)
		return ;
	x = -1;
	fd = open(path, O_RDONLY);
	while (++x != lines)
		mlx->map_tiles[x] = get_next_line(fd);
}

void	so_long(int fd, char *path)
{
	static t_game	mlx;

	get_map(&mlx, fd, path);
	if (check_map(&mlx) == 0 || check_path(&mlx) == 0)
	{	
		free_maps(&mlx);
		ft_putendl_fd("ERROR\nINVALID MAP", 2);
		return ;
	}
	game_init(&mlx);
	free_maps(&mlx);
	mlx_key_hook(mlx.window, keys, (void *)&mlx);
	mlx_loop_hook(mlx.mlx_ptr, update, (void *)&mlx);
	mlx_loop(mlx.mlx_ptr);
}

int	main(int argc, char **argv)
{
	char	*path;
	int		fd;
	int		x;

	if (argc != 2)
	{
		ft_putendl_fd("ERROR\nINVALID INPUT", 2);
		return (0);
	}
	path = argv[1];
	x = ft_strlen(path) - 1;
	if (path[x] != 'r' || path[x - 1] != 'e' || path[x - 2] != 'b'
		|| path[x - 3] != '.')
	{
		ft_putendl_fd("ERROR\nINVALID FILE TYPE", 2);
		return (0);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("ERROR\nCAN'T OPEN FILE", 2);
		return (0);
	}
	so_long(fd, path);
	return (0);
}
