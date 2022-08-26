/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:20:40 by jpaterno          #+#    #+#             */
/*   Updated: 2022/08/01 15:20:42 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

typedef struct s_data {
	void	*g;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct bag {
	void	*sr;
	void	*wi;
	t_data	*wall;
	t_data	*g;
	t_data	*item;
	t_data	*exit;
	t_data	*p;
	t_data	*blocs[10];
	void	*bag[20];
	char	*tab[99];
	int		*pp;
	int		nbr_moves;
	int		nb_c;
	int		fd;
	int		x;
	int		y;
	int		size;
	int		r_i;
	int		*xy;
}				t_bag;

int		ft_key_hook(int key, void *param);
int		ft_grabtab(t_bag *as);
void	ft_createmap(t_bag *as);
int		ft_goup(t_bag *as);
int		ft_godown(t_bag *as);
int		ft_goleft(t_bag *as);
int		ft_goright(t_bag *as);
t_data	*get_exit(t_bag *as);
t_data	*get_player(t_bag *as);
t_data	*get_item(t_bag *as);
t_data	*get_g(t_bag *as);
int		deal_key(int key, void *param);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_data	*get_wall(t_bag *as);
int		ft_check_ifsquare(char **tab);
int		ft_check_ifclosed(char **tab, int size);
int		ft_check_input(char *input, int n);
int		ft_close(t_bag *as, char *text);
int		ft_canireach(t_bag *as);

#endif