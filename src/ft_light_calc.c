#include "../include/RTv1.h"

double		clamp(double val, double l, double r) {
	if (val >= l && val <= r)
		return val;
	else if (val < l)
		return l;
	return r;
}

double		ft_calc_shine(t_vec l, t_vec p, t_vec n)
{
	t_vec	local_norm;
	t_vec	reflect_vec;
	t_vec	to_me;

	to_me = ft_vectorscale(&p, -1);
	ft_vectornorm(&to_me);

	local_norm = ft_vectorscale(&n ,ft_vectordot(&n, &l));
	reflect_vec = ft_vectorsub(&local_norm, &l);
	reflect_vec = ft_vectoradd(&local_norm, &reflect_vec);
	ft_vectornorm(&reflect_vec);

	return (ft_vectordot(&reflect_vec, &to_me));
}

int			ft_check_shadow(t_vec p, t_vec l, t_object *objects)
{
	t_object	closest_object;
	t_solution	sol;
	double		point;

	closest_object.type = 0;
	point = INT_MAX;

	while (objects)
	{
		objects->center = ft_vectorsub(&objects->center, &p);
	    sol = ft_intersectraysphere(&p, &l, objects);	    
		if ((sol.t1 > 0.001) && (sol.t1 < INT_MAX) && (sol.t1 < point)) 
		{
			point = sol.t1;
			closest_object = *objects;
		}
		if ((sol.t2 > 1) && (sol.t2 < INT_MAX) && (sol.t2 < point))
		{
			point = sol.t2;
			closest_object = *objects;
		}
		objects = objects->next;
	}
	if (closest_object.type == 0)
		return 0x00000000;
	return (1);
}

double		ft_calc_light(t_vec n, t_vec p, t_light *light, double *shine, t_object *obj)
{
	t_vec	l;
	double	intensity;
	double	n_dot_l;
	double	shine_int;

	intensity = 0.0;
	shine_int = 0.0;

while (light)
	{
	if (light->type == 1)
		intensity += light->intensity;
		else
		{
			if (light->type == 2)
				l = ft_vectorsub(&light->position, &p);
			else 
				l = light->direction;
			ft_vectornorm(&l);
			n_dot_l = ft_vectordot(&n, &l);

	/*		if (ft_check_shadow(p, l, obj) == 1)
				return(0); */
			if (n_dot_l > 0)
			{
				// зеркальность
				shine_int +=  0.4 * pow(ft_calc_shine(l, p, n), *shine);
				// диффузность
				intensity += light->intensity * n_dot_l;	
			}
		}
		light = light->next;
	}
	return (clamp(intensity + shine_int, 0., 1.));
}