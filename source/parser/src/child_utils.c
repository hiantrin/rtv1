/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 23:02:42 by hiantrin          #+#    #+#             */
/*   Updated: 2020/02/17 15:05:26 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	add_ray(t_rt *r, char *v)
{
	if (r->t >= 2 && r->t <= 5 && !ft_set(r->o->opt, 1 << 5)
			&& get_double(&(r->o->ray), v, RAY))
	{
		r->o->opt |= 1 << 5;
		return (SUCCESS);
	}
	return (ERROR);
}

int	add_fov(t_rt *r, char *v)
{
	if (r->t == CAMERA && !ft_set(r->c->opt, 1 << 2)
			&& get_double(&(r->c->fov), v, FOV))
	{
		r->c->opt |= 1 << 2;
		return (SUCCESS);
	}
	return (ERROR);
}

int	add_power(t_rt *r, char *v)
{
	if (r->t == LIGHT && !ft_set(r->l->opt, 1 << 4)
			&& get_double(&(r->l->pow), v, POWER))
	{
		r->l->opt |= 1 << 4;
		return (SUCCESS);
	}
	return (ERROR);
}

int	add_origin(t_rt *r, char *v)
{
	if (r->t == LIGHT && !ft_set(r->l->opt, ORI_SET)
			&& get_vector(&r->l->ori, v, ORIGIN))
	{
		r->l->opt |= ORI_SET;
		return (SUCCESS);
	}
	if (r->t == CAMERA && !ft_set(r->c->opt, ORI_SET)
			&& get_vector(&r->c->ori, v, ORIGIN))
	{
		r->c->opt |= ORI_SET;
		return (SUCCESS);
	}
	if (r->t >= 2 && r->t <= 5 && !ft_set(r->o->opt, ORI_SET)
			&& get_vector(&r->o->ori, v, ORIGIN))
	{
		r->o->opt |= ORI_SET;
		return (SUCCESS);
	}
	return (ERROR);
}

int	add_target(t_rt *r, char *v)
{
	if (r->t == CAMERA && !ft_set(r->c->opt, 1 << 1)
			&& get_vector(&r->c->tar, v, ORIGIN))
	{
		r->c->opt |= 1 << 1;
		return (SUCCESS);
	}
	return (ERROR);
}
