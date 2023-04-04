/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:12:32 by mibernar          #+#    #+#             */
/*   Updated: 2022/10/17 14:07:51 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_maps(t_game *vars)
{
	if (vars->map_tiles)
	{
		vars->gen_use = -1;
		while (vars->map_tiles[++vars->gen_use])
			free(vars->map_tiles[vars->gen_use]);
		free(vars->map_tiles);
	}	
	if (vars->path)
	{
		vars->gen_use = -1;
		while (vars->path[++vars->gen_use])
			free(vars->path[vars->gen_use]);
		free(vars->path);
	}
}

void	free_game(t_game *vars)
{
	mlx_destroy_image(vars->mlx_ptr, vars->wall_img.wall_img);
	mlx_destroy_image(vars->mlx_ptr, vars->col_img.col_img);
	mlx_destroy_image(vars->mlx_ptr, vars->enemy_img.enemy_img);
	mlx_destroy_image(vars->mlx_ptr, vars->exit_img.exit_img_2);
	mlx_destroy_image(vars->mlx_ptr, vars->exit_img.exit_img);
	mlx_destroy_image(vars->mlx_ptr, vars->floor_img.floor_img);
	mlx_destroy_image(vars->mlx_ptr, vars->player.player_img);
	mlx_destroy_image(vars->mlx_ptr, vars->player.player_img_2);
	mlx_destroy_window(vars->mlx_ptr, vars->window);
	mlx_destroy_display(vars->mlx_ptr);
	if (vars->map)
	{
		vars->gen_use = -1;
		while (vars->map[++vars->gen_use])
			free(vars->map[vars->gen_use]);
		free(vars->map);
	}
	free(vars->mlx_ptr);
}

int	close_window(t_game *vars)
{
	free_game(vars);
	exit (0);
	return (0);
}

int	keys(int key_code, t_game *mlx)
{
	if (key_code == 65307)
		close_window(mlx);
	else if (key_code == 119 || key_code == 97 || key_code == 115
		|| key_code == 100)
		player_movements(key_code, mlx);
	return (0);
}
