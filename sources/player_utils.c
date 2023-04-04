/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:21:35 by miguel            #+#    #+#             */
/*   Updated: 2022/10/17 13:41:30 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_to(t_game *mlx, t_tile *tile)
{
	if (tile->tile_type == FLOOR)
		move_to_floor(mlx, tile);
	else if (tile->tile_type == COLLECTABLE)
		move_to_collectible(mlx, tile);
	else if (tile->tile_type == EXIT)
		move_to_exit(mlx);
	else if (tile->tile_type == ENEMY)
		close_window(mlx);
	mlx->movements++;
	if (tile->tile_type == WALL || tile->tile_type == EXIT)
		mlx->movements--;
}

int	player_movements(int key_code, t_game *mlx)
{
	if (key_code == 119)
		move_to(mlx, mlx->player.tile->up);
	if (key_code == 115)
		move_to(mlx, mlx->player.tile->down);
	if (key_code == 97)
		move_to(mlx, mlx->player.tile->left);
	if (key_code == 100)
		move_to(mlx, mlx->player.tile->right);
	put_tiles(*mlx);
	return (0);
}
