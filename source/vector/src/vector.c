/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghrous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 23:02:42 by saghrous          #+#    #+#             */
/*   Updated: 2020/02/17 15:05:26 by saghrous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vect	ft_vector_add(t_vect v1, t_vect v2)
{
	t_vect	v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;
	return (v);
}

t_vect	ft_vector_sub(t_vect v1, t_vect v2)
{
	t_vect	v;

	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;
	return (v);
}

t_vect	ft_vector_div(t_vect v1, t_vect v2)
{
	t_vect	v;

	v = (t_vect){0, 0, 0};
	if (v2.x)
		v.x = v1.x / v2.x;
	if (v2.y)
		v.y = v1.y / v2.y;
	if (v2.z)
		v.z = v1.z / v2.z;
	return (v);
}

t_vect	ft_vector_mul(t_vect v1, t_vect v2)
{
	t_vect	v;

	v.x = v1.x * v2.x;
	v.y = v1.y * v2.y;
	v.z = v1.z * v2.z;
	return (v);
}

double	ft_vector_dot(t_vect v1, t_vect v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
