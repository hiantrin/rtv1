/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 23:02:42 by hiantrin          #+#    #+#             */
/*   Updated: 2021/02/27 15:46:59 by saghrous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>
# include <stdio.h>

# include "libft.h"
# include "vector.h"
# include "struct_rt.h"

# define P_COUNT 6
# define CAMERA_C_C 3
# define SPHERE_C_C 3
# define LIGHT_C_C 3
# define ORI_SET 1
# define BUFF_SIZE 100

enum {ERROR, SUCCESS};
enum {LIGHT, CAMERA, CONE, PLANE, SPHERE, CYLINDER};
enum {ORIGIN, COLOR, POWER, RAY, FOV, AXIS, TRANS, ROTAT};

typedef struct	s_parent
{
	char		*p;
	int			(*f)(t_rt *r);
}				t_parent;

typedef struct	s_child
{
	char		*name;
	int			(*f)(t_rt *r, char *l);
}				t_child;

int				get_int(int *p, char *v, int t);
int				get_double(double *p, char *v, int t);
int				get_vector(t_vect *o, char *v, int t);
int				get_next_line(const int fd, char **line);

int				data_is_valid(t_rt *r);
int				free_tab(char **t, int ret);

int				add_ray(t_rt *r, char *v);
int				add_fov(t_rt *r, char *v);
int				add_power(t_rt *r, char *v);
int				add_origin(t_rt *r, char *v);
int				add_target(t_rt *r, char *v);

int				add_child(t_rt *r, char **tab);
int				parse_parent(char *line, t_rt *r);

int				free_rt(t_rt *r);
int				parse_file(char *file, t_rt *r);
double			ft_vcolor (double x);
int				ft_set(int a, int b);

#endif
