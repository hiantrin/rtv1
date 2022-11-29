/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_inter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghrous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 22:12:42 by saghrous          #+#    #+#             */
/*   Updated: 2020/02/17 14:15:26 by saghrous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	check_inter_objs(t_rt *r, t_obj *obj)
{
	double	t_min;
	double	inter;

	inter = 0;
	t_min = TR_MAX;
	while (obj)
	{
		if ((inter = check_inter_objects(r, obj)))
			if (inter < t_min)
				t_min = inter;
		obj = obj->next;
	}
	if (t_min != TR_MAX)
		return (t_min);
	return (0);
}

static int	check_shadow(t_rt *r, t_light l)
{
	t_vect	v;
	double	inter;
	double	dist_light;
	double	dist_object;

	r->r.ori = ft_vector_add(r->inr.poi, ft_multiple(r->inr.nor, 0.05));
	r->r.dir = ft_vector_sub(l.ori, r->r.ori);
	ft_vector_nor(&r->r.dir);
	if (!(inter = check_inter_objs(r, r->o)))
		return (0);
	dist_light = ft_vector_dist(r->inr.poi, l.ori);
	v = ft_vector_add(r->r.ori, ft_multiple(r->r.dir, inter));
	dist_object = ft_vector_dist(r->inr.poi, v);
	if (dist_object < dist_light)
		return (1);
	return (0);
}

static void	calcul_lights(t_rt *r, t_light l)
{
	t_vect	vec;
	t_vect	view_dir;

	r->inr.amb += 0.2;
	if (check_shadow(r, l))
		return ;
	vec = ft_vector_sub(l.ori, r->inr.poi);
	ft_vector_nor(&vec);
	r->inr.def += l.pow * fmax(0, ft_vector_dot(vec, r->inr.nor));
	vec = ft_multiple(vec, -1);
	view_dir = ft_vector_sub(r->c->ori, r->inr.poi);
	ft_vector_nor(&view_dir);
}

static void	add_lights(t_rt *rt, t_light *lights)
{
	int	itr;

	itr = 0;
	rt->inr.amb = 0.0;
	rt->inr.def = 0.0;
	while (lights)
	{
		if (lights->pow)
		{
			itr++;
			calcul_lights(rt, *lights);
		}
		lights = lights->next;
	}
	if (!itr)
		rt->inr.amb = 0.2;
	rt->inr.col = ft_multiple(rt->inr.col, (rt->inr.amb + rt->inr.def));
}

void		check_inter(t_rt *r, t_obj *objs)
{
	t_obj	*tp;
	double	t_min;

	r->inr.t = 0;
	t_min = TR_MAX;
	while (objs)
	{
		r->inr.t = check_inter_objects(r, objs);
		if (r->inr.t && r->inr.t < t_min)
		{
			tp = objs;
			t_min = r->inr.t;
		}
		objs = objs->next;
	}
	r->inr.t = (t_min < TR_MAX) ? t_min : 0;
	if (!r->inr.t)
		return ;
	normal_objects(r, *tp);
	add_lights(r, r->l);
}
