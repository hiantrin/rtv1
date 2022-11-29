/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 23:02:42 by hiantrin          #+#    #+#             */
/*   Updated: 2020/02/17 15:05:26 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	object_is_valid(int opt, int t)
{
	if (t == CONE || t == PLANE || t == SPHERE || t == CYLINDER)
	{
		if (!ft_set(opt, ORI_SET))
			return (ERROR);
		if (!ft_set(opt, 1 << 3))
			return (ERROR);
		if (!ft_set(opt, 1 << 6))
			return (ERROR);
		if (!ft_set(opt, 1 << 8))
			return (ERROR);
		if (!ft_set(opt, 1 << 7))
			return (ERROR);
		if (t != PLANE && !ft_set(opt, 1 << 5))
			return (ERROR);
		return (SUCCESS);
	}
	return (ERROR);
}

int	objects_is_valid(t_obj *o)
{
	t_obj *tmp;

	if (!o)
		return (ERROR);
	tmp = o;
	while (tmp)
	{
		if (!object_is_valid(tmp->opt, o->id))
			return (ERROR);
		tmp->ori = ft_vector_add(tmp->ori, tmp->tra);
		tmp->axi = ft_vector_rot(tmp->axi, tmp->rot);
		ft_vector_nor(&tmp->axi);
		tmp = tmp->next;
	}
	return (SUCCESS);
}

int	lights_is_valid(t_light *l)
{
	t_light *tmp;

	if (!l)
		return (ERROR);
	tmp = l;
	while (tmp)
	{
		if (!ft_set(tmp->opt, ORI_SET))
			return (ERROR);
		if (!ft_set(tmp->opt, 1 << 3))
			return (ERROR);
		if (!ft_set(tmp->opt, 1 << 4))
			return (ERROR);
		tmp = tmp->next;
	}
	return (SUCCESS);
}

int	camera_is_valid(t_cam *c)
{
	if (!c)
		return (ERROR);
	if (!ft_set(c->opt, ORI_SET))
		return (ERROR);
	if (!ft_set(c->opt, 1 << 1))
		return (ERROR);
	if (!ft_set(c->opt, 1 << 2))
		return (ERROR);
	return (SUCCESS);
}

int	data_is_valid(t_rt *r)
{
	if (!camera_is_valid(r->c))
		return (ERROR);
	if (!lights_is_valid(r->l))
		return (ERROR);
	if (!objects_is_valid(r->o))
		return (ERROR);
	return (SUCCESS);
}
