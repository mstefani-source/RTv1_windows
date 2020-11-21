#include "../include/RTv1.h"

double		clamp(double val, double l, double r)
{
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

int			ft_check_shadow(t_vec p, t_light *l, t_object *objects)
{
	t_solution	sol;
    t_vec       vec_to_light;
	double      point = INT_MAX;
    double      len_vec_to_light;
    
    vec_to_light = ft_vectorsub(&(l->position), &p);
    len_vec_to_light = ft_vectorlen(&vec_to_light);
    ft_vectornorm(&vec_to_light);
    while (objects)
	{
	    sol = ft_intersectraysphere(&p, &vec_to_light, objects);	    
 		if ((sol.t1 > 0.001) && (sol.t1 < INT_MAX) && (sol.t1 < point)) 
			point = sol.t1;
		if ((sol.t2 > 0.001) && (sol.t2 < INT_MAX) && (sol.t2 < point))
			point = sol.t2;
        if (point > 0 && point < len_vec_to_light)
            return (1);
    	objects = objects->next;
	}
	return (0);
}

double		ft_calc_light(t_vec n, t_vec p, t_light *light, double *shine)
{
	t_vec	l;
	double	intensity;
	double	n_dot_l;
	double	shine_int;

	intensity = 0.0;
	shine_int = 0.0;

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

			if (n_dot_l > 0)
			{
				shine_int +=  0.4 * pow(ft_calc_shine(l, p, n), *shine);
				intensity += light->intensity * n_dot_l;	
			}
		}
    return (intensity + shine_int);
}