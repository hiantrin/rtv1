/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghrous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 23:02:42 by saghrous          #+#    #+#             */
/*   Updated: 2020/02/17 15:05:26 by saghrous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vect	ft_vector_cross(t_vect v1, t_vect v2)
{
	t_vect	v;

	v.x = v1.y * v2.z - v1.z * v2.y;
	v.y = v1.z * v2.x - v1.x * v2.z;
	v.z = v1.x * v2.y - v1.y * v2.x;
	return (v);
}

double	ft_vector_dist(t_vect u, t_vect v)
{
	double x;
	double y;
	double z;

	x = (u.x - v.x) * (u.x - v.x);
	y = (u.y - v.y) * (u.y - v.y);
	z = (u.z - v.z) * (u.z - v.z);
	return (x + y + z);
}

t_vect	ft_vector_rot(t_vect v1, t_vect v2)
{
	t_vect res;

	res.x = v1.x;
	res.y = v1.y * cos(v2.x) + v1.z * sin(v2.x);
	res.z = -v1.y * sin(v2.x) + v1.z * cos(v2.x);
	v1 = (t_vect) {res.x, res.y, res.z};
	res.x = v1.x * cos(v2.y) + v1.z * sin(v2.y);
	res.y = v1.y;
	res.z = -v1.x * sin(v2.y) + v1.z * cos(v2.y);
	v1 = (t_vect) {res.x, res.y, res.z};
	res.x = v1.x * cos(v2.z) - v1.y * sin(v2.z);
	res.y = v1.x * sin(v2.z) + v1.y * cos(v2.z);
	res.z = v1.z;
	return (res);
}
