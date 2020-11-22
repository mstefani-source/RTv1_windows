#include "../include/RTv1.h"

t_vec		*ft_setcam_position(int x, int y, int z)
{
	t_vec	*cam_pos;

	cam_pos = (t_vec*)malloc(sizeof(t_vec));
	cam_pos->x = 0;
	cam_pos->y = 0;
	cam_pos->z = 0;
	return (cam_pos);
}

t_viewport   *ft_set_portale(int d, int vw, int vh)
{
	t_viewport *portale;
	
	portale = (t_viewport*)malloc(sizeof(t_viewport));
	portale->d = 1.0;
	portale->vw = 1.0;
	portale->vh = 1.0;
	return (portale);
}

t_object	*ft_set_objects(char *line)
{
	t_object	*object1, *object2, *object3, *object4, *object5;

	object1 = (t_object*)malloc(sizeof(t_object));
	object2 = (t_object*)malloc(sizeof(t_object));
	object3 = (t_object*)malloc(sizeof(t_object));
	object4 = (t_object*)malloc(sizeof(t_object));
	object5 = (t_object*)malloc(sizeof(t_object));

	object1->type = 3;
	object1->norm = (t_vec){0, 1, 0};
	object1->center = (t_vec){0, 0, 16};
	object1->radius = 3;
	object1->shine = 500;
	object1->color = (t_color){255, 0, 0};
	object1->next = NULL;

	object2->type = 1;
	object2->center = (t_vec){1, 2, 4};
	object2->radius = 1;
	object2->shine = 50;
	object2->color = (t_color){0, 0, 255};
	object2->next = object3;

	object3->type = 1;
	object3->center = (t_vec){-1, 2, 7};
	object3->radius = 1;
	object3->shine = 1000;
	object3->color = (t_color){0, 255, 0};
	object3->next = object5;

	object4->type = 1;
	object4->center = (t_vec){0, -5001, 0};
	object4->shine = 500;
	object4->radius = 5000;
	object4->color = (t_color){255, 255, 0};
	object4->next = object5;

	object5->type = 3;
	object5->norm = (t_vec){0, 1, 0};
	object5->center = (t_vec){0, 0, 16};
	object5->shine = 500;
	object5->radius = 3;
	object5->color = (t_color){127, 0, 255};
	object5->next = NULL;

	return (object1);
}

t_light		*ft_set_light(int type, float intent, t_vec pos, t_vec dir) 
{
	t_light 	*light1,*light2, *light3;
	
	light1 = (t_light*)malloc(sizeof(t_light));
	light2 = (t_light*)malloc(sizeof(t_light));
	light3 = (t_light*)malloc(sizeof(t_light));
	
 	light1->type = type;
	light1->intensity = intent;
	light1->position = pos;
	light1->direction = dir;
	light1->color = (t_color){255, 255, 255};
	light1->next = NULL; 

	light2->type = 2;
	light2->intensity = 0.5;
	light2->position = (t_vec){4, 4, 0};
	light2->color = (t_color){255, 255, 255};
	light2->next = NULL;
	
	light3->type = 3;
	light3->intensity = 0.2;
	light3->position = (t_vec){1, 6, 4};
	light3->direction = (t_vec){1, 4, 4};
	light3->color = (t_color){255, 255, 255};
	light3->next = NULL;
	return (light1);
}

t_scene		*ft_set_scene(char *file)
{
	t_scene 	*rtv;

	if ((rtv = ft_memalloc(sizeof(t_scene))) == NULL)
		return (NULL);
	rtv->ht = 800;
	rtv->wd = 800;
	rtv->cam_pos = ft_setcam_position(0, 0, 0);
	rtv->portale = ft_set_portale(1.0, 1.0, 1.0);
	rtv->objects = ft_set_objects("sp 0.0,0.0,20.6 12.6 10,0,255");
	rtv->light = ft_set_light(2, 0.6, (t_vec){0, 5, 14}, (t_vec){0, 0, 0});
	return (rtv);
}