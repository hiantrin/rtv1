/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_rt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghrous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 23:02:42 by saghrous          #+#    #+#             */
/*   Updated: 2020/02/17 15:05:26 by saghrous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_RT_H
# define STRUCT_RT_H

# include <math.h>

# include "vector.h"

typedef struct	s_delt
{
	double	a;
	double	b;
	double	c;
}				t_delt;

typedef struct	s_mlx
{
	void			*m_p;
	void			*w_p;
	void			*i_p;
	unsigned char	*i_d;
}				t_mlx;

typedef struct	s_ray
{
	t_vect	ori;
	t_vect	dir;
}				t_ray;

typedef struct	s_cam
{
	int		opt;
	t_vect	x;
	t_vect	y;
	t_vect	z;
	double	h;
	double	w;
	double	fov;
	t_vect	ori;
	t_vect	tar;
}				t_cam;

typedef struct	s_obj
{
	int				id;
	int				opt;
	double			ray;
	t_vect			ori;
	t_vect			col;
	t_vect			axi;
	t_vect			tra;
	t_vect			rot;
	struct s_obj	*next;
}				t_obj;

typedef struct	s_light
{
	int				opt;
	double			pow;
	t_vect			ori;
	t_vect			col;
	struct s_light	*next;
}				t_light;

typedef struct	s_inter
{
	double	t;
	double	amb;
	double	def;
	t_vect	poi;
	t_vect	nor;
	t_vect	col;
	t_vect	spc;
}				t_inter;

typedef struct	s_rt
{
	int		t;
	t_mlx	m;
	t_ray	r;
	t_cam	*c;
	t_obj	*o;
	t_light	*l;
	t_inter	inr;
}				t_rt;

#endif
