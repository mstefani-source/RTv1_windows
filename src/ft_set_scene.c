#include "../include/rtv.h"

t_vec		*ft_setcam_position(int x, int y, int z)
{
	t_vec	*cam_pos;

	cam_pos = (t_vec*)malloc(sizeof(t_vec));
	cam_pos->x = 0;
	cam_pos->y = 0;
	cam_pos->z = 0;
	return (cam_pos);
}

t_object	*ft_set_objects(char *line)
{
	t_object	*object1, *object2, *object3, *object4, *object5, *object6;

	object1 = (t_object*)malloc(sizeof(t_object));
	object2 = (t_object*)malloc(sizeof(t_object));
	object3 = (t_object*)malloc(sizeof(t_object));
	object4 = (t_object*)malloc(sizeof(t_object));
	object5 = (t_object*)malloc(sizeof(t_object));
	object6 = (t_object*)malloc(sizeof(t_object));

	object1->type = 1;      // красный шар
	object1->n = (t_vec){0, 0, 0};
	object1->center = (t_vec){1, 0, 4};
	object1->radius = 1;
	object1->shine = 500;
	object1->col = (t_color){255, 0, 0};
	object1->next = object2;

	object2->type = 1;       // синий шар
	object2->center = (t_vec){-1, 1, 3};
	object2->radius = 1;
	object2->shine = 50;
	object2->col = (t_color){0, 0, 255};
	object2->next = object3;

	object3->type = 1;		// зеленый шар
	object3->center = (t_vec){-1, -1, 6};
	object3->radius = 1;
	object3->shine = 1000;
	object3->col = (t_color){0, 255, 0};
	object3->next = object4;

	object4->type = 3;     // цилиндр
	object4->n = (t_vec){0, 1, 0};
	object4->center = (t_vec){1, 0, 6};
	object4->shine = 500;
	object4->radius = 1;
	object4->col = (t_color){127, 0, 255};
	object4->next = object5;

	object5->type = 2;     // поверхность
	object5->n = (t_vec){0, 1, 0};
	object5->center = (t_vec){0, -2, 0};
	object5->shine = 300;
	object5->radius = 3;
	object5->col = (t_color){243, 123, 148};
	object5->next = object6;

	object6->type = 4;     // конус
	object6->n = (t_vec){0, 1, 0};
	object6->center = (t_vec){-2, 0, 5.5};
	object6->shine = 300;
	object6->radius = 0.01;
	object6->col = (t_color){255, 0, 255};
	object6->next = NULL;

	return (object1);
}

t_light		*ft_set_light(int type, double intent, t_vec pos, t_vec dir)
{
	t_light 	*light1,*light2, *light3;
	
	light1 = (t_light*)malloc(sizeof(t_light));
	light2 = (t_light*)malloc(sizeof(t_light));
	light3 = (t_light*)malloc(sizeof(t_light));
	
 	light1->type = type;
	light1->intensity = intent;
	light1->position = pos;
	light1->direction = dir;
	light1->col = (t_color){255, 255, 255};
	light1->next = light2;

	light2->type = 2;
	light2->intensity = 0.2;
	light2->position = (t_vec){30, 20, -50};
	light2->direction = (t_vec){-1, -1, -4};
	light2->col = (t_color){255, 255, 255};
	light2->next = light3;
	
	light3->type = 2;
	light3->intensity = 0.2;
	light3->position = (t_vec){-30, 0, -50};
	light3->direction = (t_vec){-1, -1, -4};
	light3->col = (t_color){255, 255, 255};
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
	rtv->port = ft_set_portale(1.0, 1.0, 1.0);
	rtv->objects = ft_set_objects("sp 0.0,0.0,20.6 12.6 10,0,255");
	rtv->light = ft_set_light(1, 0.2, (t_vec){0, 5, 14}, (t_vec){0, 0, 1});
	return (rtv);
}