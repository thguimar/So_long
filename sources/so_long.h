/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:12:51 by thguimar          #+#    #+#             */
/*   Updated: 2024/04/22 15:12:26 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "../minilibx-linux/mlx.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <X11/keysym.h>
# include "../libft/libft.h"

typedef struct s_imgs
{
	char		*addr;
	int			bites_per_pxl;
	int			endian;
	int			height;
	int			line_len;
	int			width;
	void		*win;
	void		*img;
}				t_imgs;

typedef struct s_assets
{
	t_imgs	*lantern;
	t_imgs	*ground;
	t_imgs	*character;
	t_imgs	*gwc;
	t_imgs	*cwl;
	t_imgs	*door;
	t_imgs	*gwl;
	t_imgs	*par;
	t_imgs	*gwp;
	t_imgs	*wall;
	t_imgs	*gwd;
	t_imgs	*gwdwc;
	t_imgs	*gwcwl;
	t_imgs	*c2;
	t_imgs	*gwc2;
	t_imgs	*cwl2;
	t_imgs	*gwcwl2;
}	t_assets;

typedef struct s_vars
{
	void			*mlx;
	void			*img;
	void			*win;
	int				win_w;
	int				win_h;
	int				x_p;
	int				y_p;
	int				e_x;
	int				e_y;
	int				movement;
	char			**map;
	int				collect;
	int				lantern;
	int				there_was_lantern;
	int				left;
	t_assets		*assets;
}	t_vars;

typedef struct s_map
{
	int	c;
	int	p;
	int	e;
	int	l;
	int	x;
	int	y;
}	t_map;

void			render_map(t_vars *vars, char **argv);
void			move_left(t_vars *v);
void			move_right(t_vars *v);
void			move_up(t_vars *v);
void			move_down(t_vars *v);
char			*ft_join_strings(char *s1, char *s2);
char			*ft_itoa(int n);
void			put_text(t_vars *v);
void			put_image_to_map(char p, int x1, int y1, t_vars *v);
int				get_height(char **map);
void			check_map_valid(t_vars *vars);
void			check_file_is_valid(char *file_line);
void			check_elements(t_vars *vars);
void			ft_error(t_vars *vars, char *message);
int				animation(t_vars *vars);
int				get_position_for_enemy(t_vars **vars);
void			exit_door(t_vars *v);
t_imgs			*new_img(int w, int h, t_vars *mlx, t_vars *window);
t_imgs			*new_file_img(char *path, void *mlx, void *window);
void			put_pixel_img(t_imgs *img, int x, int y, int color);
void			put_img_to_img(t_imgs *dst, t_imgs *src, int x, int y);
void			assets_cleaner(t_vars *v);
int				check_c(t_vars *vars);
int				check_e(t_vars *vars);
void			flood_fill(char **map, int x, int y);
void			get_player(t_vars *vars);
void			init_vars(t_vars *vars);
char			**get_map(char *fmap, t_vars *vars);
void			final_cleaner(t_vars *vars, int assets);
void			ft_message_error(t_vars *vars, int assets);
char			unknown_element(t_vars *v, char c);
void			assets_initiator(t_vars *v);
void			lantern(t_vars *v);
void			move_idk(t_vars *v);
void			exit_verifier(t_vars *v, int xy, int vet);
void			collected(t_vars *v);
void			invisible_door(t_vars *v, int x1, int y1);
char			*nengue(int fd, char *line, char *all_lines);
int				map_xloop(t_vars *vars, int x1, int y1, int map_y);
void			flood_checker(t_vars *vars, char **argv);
t_map			map_idk(t_vars *vars, t_map map);
unsigned int	get_pixel_img(t_imgs *img, int x, int y);

#endif
