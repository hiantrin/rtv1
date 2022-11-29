/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghrous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 23:02:42 by saghrous          #+#    #+#             */
/*   Updated: 2020/02/17 15:05:26 by saghrous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	normal_objects(t_rt *r, t_obj obj)
{
	double	a;

	r->inr.poi = ft_vector_add(r->r.ori, ft_multiple(r->r.dir, r->inr.t));
	if (obj.id == PLANE)
		r->inr.nor = obj.axi;
	if (obj.id == SPHERE)
		r->inr.nor = ft_vector_sub(r->inr.poi, obj.ori);
	if (obj.id == CONE || obj.id == CYLINDER)
	{
		a = ft_vector_dot(ft_vector_sub(r->r.ori, obj.ori), obj.axi);
		a = ft_vector_dot(r->r.dir, obj.axi) * r->inr.t + a;
		r->inr.nor = ft_vector_sub(r->inr.poi, obj.ori);
		r->inr.nor = ft_vector_sub(r->inr.nor, ft_multiple(obj.axi, a));
	}
	ft_vector_nor(&r->inr.nor);
	r->inr.col = obj.col;
}

double	solve_equation(t_delt d)
{
	double	t1;
	double	t2;
	double	delta;

	delta = d.b * d.b - 4 * d.a * d.c;
	if (delta < 0 || d.a == 0)
		return (0);
	t1 = (-d.b - sqrt(delta)) / (2 * d.a);
	t2 = (-d.b + sqrt(delta)) / (2 * d.a);
	if (t1 < TR_MIN && t2 < TR_MIN)
		return (0);
	if (t1 < TR_MIN)
		return (t2);
	if (t2 < TR_MIN)
		return (t1);
	return (fmin(t1, t2));
}
