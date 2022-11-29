/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghrous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 23:02:42 by saghrous          #+#    #+#             */
/*   Updated: 2020/02/17 15:05:26 by saghrous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	ft_add(t_vect *v, double nbr)
{
	v->x += nbr;
	v->y += nbr;
	v->z += nbr;
}

t_vect	ft_multiple(t_vect v, double a)
{
	t_vect	tp;

	tp.x = v.x * a;
	tp.y = v.y * a;
	tp.z = v.z * a;
	return (tp);
}

t_vect	ft_division(t_vect v, double a)
{
	t_vect	tp;

	tp = (t_vect){0, 0, 0};
	if (!a)
		return (tp);
	tp.x = v.x / a;
	tp.x = v.y / a;
	tp.x = v.z / a;
	return (tp);
}

double	ft_vector_len(t_vect v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

void	ft_vector_nor(t_vect *v)
{
	double	len;

	if ((len = sqrt(ft_vector_len(*v))))
	{
		v->x /= len;
		v->y /= len;
		v->z /= len;
	}
	else
		*v = (t_vect){0, 0, 0};
}
