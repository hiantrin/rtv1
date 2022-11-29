/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 23:02:42 by hiantrin          #+#    #+#             */
/*   Updated: 2020/02/17 15:05:26 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		get_int(int *p, char *v, int t)
{
	int i;
	int res;

	res = sscanf(v, "%d%n", p, &i);
	if (res != 1 || v[i] != '\0')
		return (ERROR);
	if (t == CAMERA && (*p < 0 || *p > 120))
		return (ERROR);
	return (SUCCESS);
}

int		get_double(double *p, char *v, int t)
{
	int i;
	int res;

	res = sscanf(v, "%lf%n", p, &i);
	if (res != 1 || v[i] != '\0' || *p < 0)
		return (ERROR);
	if (t == FOV && *p > 120)
		return (ERROR);
	return (SUCCESS);
}

double	ft_vcolor(double x)
{
	return (x >= 0 && x <= 255);
}

int		get_vector(t_vect *o, char *v, int t)
{
	int i;
	int res;

	i = 0;
	res = sscanf(v, "%lf,%lf,%lf%n", &(o->x), &(o->y), &(o->z), &i);
	if (res != 3 || v[i] != '\0')
		return (ERROR);
	if (t == COLOR && !(ft_vcolor(o->x) && ft_vcolor(o->y) && ft_vcolor(o->x)))
		return (ERROR);
	if (t != ROTAT)
		return (SUCCESS);
	o->x = o->x * M_PI / 180;
	o->y = o->y * M_PI / 180;
	o->z = o->z * M_PI / 180;
	return (SUCCESS);
}

int		free_tab(char **t, int ret)
{
	int	i;

	if (!t)
		return (ret);
	i = -1;
	while (t[++i])
		ft_memdel((void **)&t[i]);
	free(t);
	t = 0;
	return (ret);
}
