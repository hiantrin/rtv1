/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 23:02:42 by hiantrin          #+#    #+#             */
/*   Updated: 2020/02/17 15:05:26 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	add_color(t_rt *r, char *v)
{
	if (r->t == LIGHT && !ft_set(r->l->opt, 1 << 3)
			&& get_vector(&r->l->col, v, COLOR))
	{
		r->l->opt |= 1 << 3;
		return (SUCCESS);
	}
	if (r->t >= 2 && r->t <= 5 && !ft_set(r->o->opt, 1 << 3)
			&& get_vector(&r->o->col, v, COLOR))
	{
		r->o->opt |= 1 << 3;
		return (SUCCESS);
	}
	return (ERROR);
}

int	add_axis(t_rt *r, char *v)
{
	if (r->t >= 2 && r->t <= 5 && !ft_set(r->o->opt, 1 << 6)
			&& get_vector(&r->o->axi, v, AXIS))
	{
		r->o->opt |= 1 << 6;
		return (SUCCESS);
	}
	return (ERROR);
}

int	add_rotation(t_rt *r, char *v)
{
	if (r->t >= 2 && r->t <= 5 && !ft_set(r->o->opt, 1 << 8)
			&& get_vector(&r->o->rot, v, ROTAT))
	{
		r->o->opt |= 1 << 8;
		return (SUCCESS);
	}
	return (ERROR);
}

int	add_translation(t_rt *r, char *v)
{
	if (r->t >= 2 && r->t <= 5 && !ft_set(r->o->opt, 1 << 7)
			&& get_vector(&r->o->tra, v, TRANS))
	{
		r->o->opt |= 1 << 7;
		return (SUCCESS);
	}
	return (ERROR);
}

int	add_child(t_rt *r, char **tab)
{
	int				i;
	int				ret;
	static t_child	c_child[9] = {
		{"ray:", &add_ray},
		{"fov:", &add_fov},
		{"color:", &add_color},
		{"power:", &add_power},
		{"origin:", &add_origin},
		{"target:", &add_target},
		{"axis:", &add_axis},
		{"rotation:", &add_rotation},
		{"translation:", &add_translation},
	};

	if (!tab[1])
		return (free_tab(tab, ERROR));
	i = -1;
	while (++i < 9)
		if (ft_strequ(tab[0], c_child[i].name))
			break ;
	ret = ERROR;
	if (i < 9 && ft_strequ(tab[0], c_child[i].name))
		ret = c_child[i].f(r, tab[1]);
	return (free_tab(tab, ret));
}
