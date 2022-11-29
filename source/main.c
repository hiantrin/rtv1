/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghrous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 22:02:42 by saghrous          #+#    #+#             */
/*   Updated: 2020/02/25 16:15:26 by saghrous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	keys_hook(int k, t_rt *r)
{
	(void)r;
	if (k == 53)
	{
		free_rt(r);
		exit(0);
	}
	return (0);
}

static int	init_mlx(t_rt *rt)
{
	int	b;
	int	s;
	int	e;

	rt->m.m_p = mlx_init();
	rt->m.w_p = mlx_new_window(rt->m.m_p, IMG_W, IMG_H, "Rtr1");
	rt->m.i_p = mlx_new_image(rt->m.m_p, IMG_W, IMG_H);
	rt->m.i_d = (unsigned char *)mlx_get_data_addr(rt->m.i_p, &b, &s, &e);
	return (0);
}

int			main(int ac, char **av)
{
	t_rt	r;

	(void)ac;
	if (!av[1])
		return (1);
	if (!parse_file(av[1], &r))
		return (1);
	init_mlx(&r);
	ft_trace_rt(&r);
	mlx_hook(r.m.w_p, 2, 0, keys_hook, &r);
	mlx_put_image_to_window(r.m.m_p, r.m.w_p, r.m.i_p, 0, 0);
	mlx_loop(r.m.m_p);
}
