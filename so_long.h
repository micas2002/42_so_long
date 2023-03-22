/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:28:49 by mibernar          #+#    #+#             */
/*   Updated: 2022/10/17 14:03:49 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

// PROTOTYPES

typedef struct s_enemy
{
	void	*enemy_img;
}	t_enemy;

typedef struct s_wall
{
	void	*wall_img;
}	t_wall;

typedef struct s_exit
{
	void	*exit_img;
	void	*exit_img_2;
}	t_exit;

typedef struct s_floor
{
	void	*floor_img;
}	t_floor;

typedef struct s_col
{
	void	*col_img;
}	t_col;

typedef struct s_vector
{
	int	x;
	int	y;
}t_vector;

typedef struct s_map_info
{
	int			player;
	int			p_pos_x;
	int			p_pos_y;
	int			exit;
	int			e_pos_x;
	int			e_pos_y;
	int			collectible;
	int			true_false;
	t_vector	size;
}t_map_info;

typedef enum s_type
{
	FLOOR = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = '2',
}t_type;

typedef struct s_tile
{
	t_vector		pos;
	t_type			tile_type;
	t_type			og_type;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}t_tile;

typedef struct s_player
{
	void	*player_img;
	void	*player_img_2;
	void	*current_img;
	int		frames;
	t_tile	*tile;
}	t_player;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*window;
	int			movements;
	int			gen_use;
	t_map_info	map_info;
	t_vector	window_size;
	t_vector	img_size;
	t_player	player;
	t_wall		wall_img;
	t_exit		exit_img;
	t_floor		floor_img;
	t_col		col_img;
	t_enemy		enemy_img;
	char		**map_tiles;
	char		**path;
	t_tile		**map;
}t_game;

// MAP_UTILS
int		check_map(t_game *mlx);
int		number_lines(int fd);
void	get_map_data(char **map, t_game *mlx);
void	check_tile(char **map, int x, int y, t_game *mlx);
int		check_borders(char **map, int y, t_game *mlx);

//MOVE_TO
void	move_to_floor(t_game *mlx, t_tile *tile);
void	move_to_collectible(t_game *mlx, t_tile *tile);
void	move_to_exit(t_game *mlx);

// OPEN_IMGS
void	open_imgs(t_game *mlx);
void	open_players(t_game *mlx);
void	open_walls(t_game *mlx);
void	open_colectibles(t_game *mlx);
void	open_doors(t_game *mlx);

//PLAYER_UTILS
int		player_movements(int key_code, t_game *mlx);
void	move_to(t_game *mlx, t_tile *tile);

//RENDER
void	put_tiles(t_game mlx);
void	put_image(t_tile tile, t_game mlx, int y, int x);

//SO_LONG.C
int		main(int argc, char **argv);
void	so_long(int fd, char *path);
void	get_map(t_game *mlx, int fd, char *path);
void	game_init(t_game *mlx);
int		update(t_game *mlx);
void	player_sprites(t_player *player);

//TILEMAP.C
t_tile	**generate_tilemap(char **map, t_game *game);
void	set_gamevars(t_tile *tile, t_game *mlx);
void	setup_tile(t_tile **tilemap, int x, int y, t_game *mlx);
t_type	define_tiletype(char definer);
t_tile	**alloc_tilemap(char **map);

//VARS_UTILS.C
int		keys(int key_code, t_game *mlx);
int		close_window(t_game *vars);

//CHECK_PATH.C
int		check_path(t_game *mlx);
int		valid(t_game *mlx, int y, int x);
void	mark_possible(t_game *mlx, int y, int x);
void	copy_map(t_game *mlx);
void 	free_maps(t_game *vars);

#endif