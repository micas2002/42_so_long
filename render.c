/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:08:27 by miguel            #+#    #+#             */
/*   Updated: 2022/08/10 16:23:15 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_tile tile, t_game mlx, int y, int x)
{
	if (tile.tile_type == PLAYER)
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.window,
			mlx.player.current_img, (x * 64), (y * 64));
	else if (tile.tile_type == COLLECTABLE)
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.window,
			mlx.col_img.col_img, (x * 64), (y * 64));
	else if (tile.tile_type == EXIT)
	{
		if (mlx.map_info.collectible == 0)
			mlx_put_image_to_window(mlx.mlx_ptr, mlx.window,
				mlx.exit_img.exit_img_2, (x * 64), (y * 64));
		else
			mlx_put_image_to_window(mlx.mlx_ptr, mlx.window,
				mlx.exit_img.exit_img, (x * 64), (y * 64));
	}
	else if (tile.tile_type == WALL)
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.window,
			mlx.wall_img.wall_img, (x * 64), (y * 64));
	else if (tile.tile_type == FLOOR)
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.window,
			mlx.floor_img.floor_img, (x * 64), (y * 64));
	else if (tile.tile_type == ENEMY)
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.window,
			mlx.enemy_img.enemy_img, (x * 64), (y * 64));
}

void	put_tiles(t_game mlx)
{
	int		x;
	int		y;
	t_tile	tile;
	char	*str;

	mlx_clear_window(mlx.mlx_ptr, mlx.window);
	x = 0;
	while (x < mlx.map_info.size.y)
	{
		y = 0;
		while (y < mlx.map_info.size.x)
		{
			tile = mlx.map[x][y];
			put_image(tile, mlx, x, y);
			y++;
		}
		x++;
	}
	str = ft_itoa(mlx.movements);
	mlx_string_put(mlx.mlx_ptr, mlx.window, 64, 32, 1000, str);
	free(str);
}
