
#include "../include/RTv1.h"

void	ft_initsol(t_solution *sol)
{
    sol->t1 = INT_MAX;
	sol->t2 = INT_MAX;
	sol->color = (t_color){0, 0, 0};
}


t_solution		*ft_intersectraysphere(t_vec *cam_pos, t_vec *d, t_object *obj) 
{
	t_solution	*sol;
    t_vec		oc;
	double 		k2;
	double 		k3;
	double 		discriminant;

    sol = (t_solution*)malloc(sizeof(t_solution));
	ft_initsol(sol);
	discriminant = -1;
	oc = ft_vectorsub(cam_pos, &obj->center);
    k2 = 2 * ft_vectordot(&oc, d);
    k3 = ft_vectordot(&oc, &oc) - pow(obj->radius, 2);
	discriminant = pow(k2 , 2) - 4 * ft_vectordot(d, d) * k3;
	if ((discriminant) < 0)
        return sol;
    sol->t1 = (-k2 + sqrt(discriminant)) / (2 * ft_vectordot(d, d));
   	sol->t2 = (-k2 - sqrt(discriminant)) / (2 * ft_vectordot(d, d));
    sol->color = obj->color;
    return (sol);
}

t_solution		*ft_intersectrayplan(t_vec *cam_pos,t_vec *d_vec, t_object *obj)
{
	t_solution	*sol;
	t_vec		a;
	
	sol = (t_solution*)malloc(sizeof(t_solution));
	ft_initsol(sol);
	a = ft_vectorsub(&obj->center, cam_pos);
	sol->t1 = (ft_vectordot(&a,&(obj->norm))/ft_vectordot(d_vec, &(obj->norm)));
	return (sol);
}

t_solution		*ft_intersectcyl(t_vec *cam_pos, t_vec *d, t_object *obj)
{
	t_solution	*sol;
    t_vec		oc;
	double 		k1;
	double 		k2;
	double 		k3;
	double 		discriminant;

    sol = (t_solution*)malloc(sizeof(t_solution));
	ft_initsol(sol);
	discriminant = -1;
	oc = ft_vectorsub(cam_pos, &obj->center);
	k1 = ft_vectordot(d, d) - ft_vectordot(d, &(obj->norm)) * ft_vectordot(d, &(obj->norm));
    k2 = 2 * ft_vectordot(&oc, d) - ft_vectordot(d, &(obj->norm)) * ft_vectordot(&oc, &(obj->norm));
    k3 = ft_vectordot(&oc, &oc) - pow(obj->radius, 2) - ft_vectordot(&oc, &(obj->norm)) * ft_vectordot(&oc, &(obj->norm));
	discriminant = pow(k2 , 2) - 4 * k1 * k3;
	if ((discriminant) < 0)
        return sol;
    sol->t1 = (-k2 + sqrt(discriminant)) / (2 * k1);
   	sol->t2 = (-k2 - sqrt(discriminant)) / (2 * k1);
    sol->color = obj->color;
    return (sol);

}