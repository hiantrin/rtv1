/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghrous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 17:44:42 by saghrous          #+#    #+#             */
/*   Updated: 2020/02/28 15:05:26 by saghrous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	init_cam(t_rt *r)
{
	t_vect up;

	up = (t_vect){0., 1., 0.};
	r->c->fov = r->c->fov * M_PI / 180;
	r->c->z = ft_vector_sub(r->c->tar, r->c->ori);
	r->c->z.z -= 0.001;
	ft_vector_nor(&r->c->z);
	r->c->x = ft_vector_cross(r->c->z, up);
	ft_vector_nor(&r->c->x);
	r->c->y = ft_vector_cross(r->c->x, r->c->z);
	r->c->h = tan(r->c->fov / 2) * 2;
	r->c->w = (IMG_W / IMG_H) * r->c->h;
}

static void	ray_dir(t_rt *r, double x, double y)
{
	t_vect	v1;
	t_vect	v2;

	v1 = ft_multiple(r->c->x, x * r->c->w);
	v2 = ft_multiple(r->c->y, y * r->c->h);
	r->r.ori = r->c->ori;
	r->r.dir = ft_vector_add(r->c->z, ft_vector_add(v1, v2));
	ft_vector_nor(&r->r.dir);
}

static void	ft_trace(t_rt *rt, int i, int j)
{
	double	x;
	double	y;

	x = j * 2.0 / (double)IMG_W - 1.0;
	y = (1.0 - i * 2.0 / (double)IMG_H);
	ray_dir(rt, x, y);
	check_inter(rt, rt->o);
	if (rt->inr.t)
	{
		rt->m.i_d[(j + i * IMG_W) * 4 + 0] = fmax(fmin(rt->inr.col.z, 255), 0);
		rt->m.i_d[(j + i * IMG_W) * 4 + 1] = fmax(fmin(rt->inr.col.y, 255), 0);
		rt->m.i_d[(j + i * IMG_W) * 4 + 2] = fmax(fmin(rt->inr.col.x, 255), 0);
	}
}

void		ft_trace_rt(t_rt *rt)
{
	int		i;
	int		j;

	i = 0;
	init_cam(rt);
	while (i < IMG_H)
	{
		j = 0;
		while (j < IMG_W)
		{
			ft_trace(rt, i, j);
			j++;
		}
		i++;
	}
}
