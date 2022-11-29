/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghrous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 23:02:42 by saghrous          #+#    #+#             */
/*   Updated: 2020/02/17 15:05:26 by saghrous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# include "libft.h"
# include "parser.h"
# include "struct_rt.h"

# include "../miniLibX/mlx.h"

# define IMG_W 700
# define IMG_H 700
# define TR_MIN 0.0001
# define TR_MAX 1.0e30f

double		solve_equation(t_delt d);
void		check_inter(t_rt *r, t_obj *objs);
void		normal_objects(t_rt *r, t_obj obj);
double		check_inter_objects(t_rt *r, t_obj *obj);

void		ft_trace_rt(t_rt *rt);

#endif
