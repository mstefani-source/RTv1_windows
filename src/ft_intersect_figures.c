
#include "../include/RTv1.h"


t_solution 	ft_intersectraysphere(t_vec *cam_pos, t_vec *d, t_object *obj) 
{
	t_solution	sol;
    t_vec		oc;
	double		k1;
	double 		k2;
	double 		k3;
	double 		discriminant;

    sol.t1 = INT_MAX;
	sol.t2 = INT_MAX;
	sol.color = (t_color){0, 0, 0};
    sol.flag = 0;
	discriminant = -1;
	
	oc = ft_vectorsub(cam_pos, &obj->center);
   	k1 = ft_vectordot(d, d);
    k2 = 2 * ft_vectordot(&oc, d);
    k3 = ft_vectordot(&oc, &oc) - pow(obj->radius, 2);

	discriminant = pow(k2 , 2) - 4 * k1 * k3;
	if (discriminant < 0)
        return sol;

    sol.t1 = (-k2 + sqrt(discriminant)) / (2 * k1);
   	sol.t2 = (-k2 - sqrt(discriminant)) / (2 * k1);
    sol.color = obj->color;
    sol.flag = 1;
    return (sol);
}

