/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hastid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:28:15 by hastid            #+#    #+#             */
/*   Updated: 2020/03/04 20:29:43 by hastid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

typedef struct	s_vect
{
	double	x;
	double	y;
	double	z;
}				t_vect;

void			ft_add(t_vect *v, double nbr);
double			ft_vector_len(t_vect v);
void			ft_vector_nor(t_vect *v);
t_vect			ft_multiple(t_vect v, double a);
t_vect			ft_vector_add(t_vect v1, t_vect v2);
t_vect			ft_vector_sub(t_vect v1, t_vect v2);
t_vect			ft_vector_mul(t_vect v1, t_vect v2);
double			ft_vector_dot(t_vect v1, t_vect v2);
t_vect			ft_vector_cross(t_vect v1, t_vect v2);
t_vect			ft_vector_rot(t_vect v1, t_vect v2);
double			ft_vector_dist(t_vect v1, t_vect v2);

#endif
