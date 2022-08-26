/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:07:23 by jpaterno          #+#    #+#             */
/*   Updated: 2022/07/27 20:07:25 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "./libft/libft.h"
#include "solong.h"

int	main(int argc, char **argv)
{
	t_bag	as;

	if (ft_check_input (argv[1], argc) == 0)
		return (0);
	as.pp = malloc(sizeof(int) * 2);
	as.sr = mlx_init();
	as.wall = get_wall(&as);
	as.g = get_g(&as);
	as.item = get_item(&as);
	as.p = get_player(&as);
	as.exit = get_exit(&as);
	as.fd = open(argv[1], O_RDONLY);
	as.size = ft_grabtab(&as);
	as.x = (as.size / 1000) * 50;
	as.y = (as.size % 1000) * 50;
	as.wi = mlx_new_window(as.sr, as.x, as.y, "SL");
	ft_createmap(&as);
	ft_canireach(&as);
	as.fd = open(argv[1], O_RDONLY);
	as.size = ft_grabtab(&as);
	mlx_key_hook(as.wi, ft_key_hook, &as);
	mlx_hook(as.wi, 17, 1L << 0, ft_close, &as);
	mlx_loop(as.sr);
	return (0);
}

int	ft_key_hook(int key, void *param)
{
	t_bag	*as;
	int		old_nbr;

	as = param;
	old_nbr = as->nbr_moves;
	if (key == 13)
		(as->nbr_moves += ft_goup(as));
	if (key == 0)
		(as->nbr_moves += ft_goleft(as));
	if (key == 1)
		(as->nbr_moves += ft_godown(as));
	if (key == 2)
		(as->nbr_moves += ft_goright(as));
	if (old_nbr != as->nbr_moves)
		ft_printf("\nNbr moves == %d", as->nbr_moves);
	if (key == 53)
		ft_close(as, "Exit by ESC");
	return (0);
}

void	co_ft_ceatemap(t_bag *as, int x, int y, char choice)
{
	if (as->tab[y / 50][x / 50] == '1')
		mlx_put_image_to_window(as->sr, as->wi, as->wall->g, x, y);
	else if (as->tab[y / 50][x / 50] == '0')
		mlx_put_image_to_window(as->sr, as->wi, as->g->g, x, y);
	else if (as->tab[y / 50][x / 50] == 'C')
		mlx_put_image_to_window(as->sr, as->wi, as->item->g, x, y);
	else if (as->tab[y / 50][x / 50] == 'E')
		mlx_put_image_to_window(as->sr, as->wi, as->exit->g, x, y);
	else if (choice == 'P')
	{
		as->r_i += 10000;
		if (as->r_i > 19000)
			ft_close(as, "Error \nIl ne doit y'avoir que 1 joueurs (P)");
		mlx_put_image_to_window(as->sr, as->wi, as->p->g, x, y);
		as->pp[0] = x;
		as->pp[1] = y;
	}
	else if (as->tab[y / 50][x / 50] != 10)
		ft_close(as, "Error \nLa map contient une case inconnue\n");
}

void	ft_createmap(t_bag *as)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	as->r_i = 0;
	while (as->tab[y / 50])
	{
		co_ft_ceatemap(as, x, y, as->tab[y / 50][x / 50]);
		if (as->tab[y / 50][x / 50] == 'C')
			as->r_i++;
		if (as->tab[y / 50][x / 50] == 'E')
			as->r_i += 100;
		x += 50;
		if (!(as->tab[y / 50][x / 50]))
		{
			y += 50;
			x = 0;
		}
	}
	as->nb_c = (as->r_i - 10000) % 100;
	if (as->r_i < 10101)
		ft_close(as, "Error \nLe map m'a pas assez de item OU player OU exit\n");
}

int	ft_grabtab(t_bag *as)
{
	int	i;
	int	size;

	if (as->fd == -1)
		ft_close(as, "--Error \nLe fichier n'exsite pas");
	i = 0;
	as->tab[i] = get_next_line(as->fd);
	while (as->tab[i] != NULL)
		as->tab[++i] = get_next_line(as->fd);
	size = i;
	if (size < 3)
		ft_close(as, "-Error \nLa map est trop petite");
	i = ft_check_ifsquare(as->tab);
	if (i == 0)
		ft_close(as, "-Error \nLa map n'est pas un rectangle");
	i = ft_check_ifclosed(as->tab, i);
	if (i == 0)
		ft_close(as, "-Error \nLa map n'est pas close");
	i = 0;
	while (as->tab[0][i])
		i++;
	return (size + ((i - 1) * 1000));
}
