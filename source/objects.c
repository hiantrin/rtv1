/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghrous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 23:02:42 by saghrous          #+#    #+#             */
/*   Updated: 2020/02/17 15:05:26 by saghrous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	check_inter_cone(t_rt *r, t_obj *o)
{
	t_delt	d;
	t_vect	v;
	double	a;
	double	b;
	double	c;

	v = ft_vector_sub(r->r.ori, o->ori);
	a = ft_vector_dot(r->r.dir, r->r.dir);
	b = ft_vector_dot(r->r.dir, o->axi);
	d.a = a - (1 + pow(tan(o->ray * M_PI / 180), 2)) * pow(b, 2);
	a = ft_vector_dot(r->r.dir, v);
	c = ft_vector_dot(v, o->axi);
	d.b = 2 * (a - (1 + pow(tan(o->ray * M_PI / 180), 2)) * b * c);
	d.c = ft_vector_dot(v, v);
	d.c = d.c - (1 + pow(tan(o->ray * M_PI / 180), 2)) * pow(c, 2);
	return (solve_equation(d));
}

static double	check_inter_plane(t_rt *r, t_obj *o)
{
	t_vect		v;
	double		inter;
	double		nor_dir;

	v = ft_vector_sub(o->ori, r->r.ori);
	if ((nor_dir = ft_vector_dot(r->r.dir, o->axi)))
		inter = ft_vector_dot(v, o->axi) / nor_dir;
	else
		return (0);
	if (inter < TR_MIN)
		return (0);
	return (inter);
}

static double	check_inter_sphere(t_rt *r, t_obj *o)
{
	t_delt	d;
	t_vect	v;

	v = ft_vector_sub(r->r.ori, o->ori);
	d.a = ft_vector_dot(r->r.dir, r->r.dir);
	d.b = 2 * ft_vector_dot(r->r.dir, v);
	d.c = ft_vector_dot(v, v) - o->ray * o->ray;
	return (solve_equation(d));
}

static double	check_inter_cylinder(t_rt *r, t_obj *o)
{
	t_delt	d;
	t_vect	v;
	double	a;
	double	b;

	v = ft_vector_sub(r->r.ori, o->ori);
	b = ft_vector_dot(v, o->axi);
	a = ft_vector_dot(r->r.dir, o->axi);
	d.a = ft_vector_dot(r->r.dir, r->r.dir) - a * a;
	d.b = 2 * (ft_vector_dot(r->r.dir, v) - (a * b));
	d.c = ft_vector_dot(v, v) - b * b - o->ray * o->ray;
	return (solve_equation(d));
}

double			check_inter_objects(t_rt *r, t_obj *obj)
{
	if (obj->id == CONE)
		return (check_inter_cone(r, obj));
	if (obj->id == PLANE)
		return (check_inter_plane(r, obj));
	if (obj->id == SPHERE)
		return (check_inter_sphere(r, obj));
	if (obj->id == CYLINDER)
		return (check_inter_cylinder(r, obj));
	return (0);
}
