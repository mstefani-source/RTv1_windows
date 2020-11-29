#include <unistd.h>
#include "get_next_line.h"
#include "rtv.h"

t_light *ft_add_light(t_light *light, char *line)
{
	t_light *new_light;
	int i;

	i = 0;
	new_light = (t_light*)malloc(sizeof(t_light));
	while (!(ft_isdigit(line[i]) || (line[i] == '-')))
		i++;
	new_light->position.x = ft_atof(&line[i]);
	while (ft_isdigit(line[i]) || line[i] == '.' || line[i] == '-')
		i++;
	i++;
	new_light->position.y = ft_atof(&line[i]);
	while (ft_isdigit(line[i]) || line[i] == '.' || line[i] == '-')
		i++;
	i++;
	new_light->position.z = ft_atof(&line[i]);
	while (ft_isdigit(line[i]) || line[i] == '.' || line[i] == '-')
		i++;
	while (!(ft_isdigit(line[i])))
		i++;
	new_light->intensity = ft_atof(&line[i]);
	while (ft_isdigit(line[i]) || line[i] == '.')
		i++;
	while (!(ft_isdigit(line[i])))
		i++;
	new_light->type = ft_atoi(&line[i]);
	new_light->next = light;
	return(new_light);
}

t_object *ft_add_plane(t_object *object, char *line)
{
	t_object *new_object;
	int i;

	i = 0;
	new_object = (t_object *)malloc(sizeof(t_object));
	new_object->type = 2;
	while (!(ft_isdigit(line[i]) || (line[i] == '-')))
		i++;
	new_object->center.x = ft_atof(&line[i]);
	while (ft_isdigit(line[i]) || line[i] == '.' || line[i] == '-')
		i++;
	i++;
	new_object->center.y = ft_atof(&line[i]);
	while (ft_isdigit(line[i]) || line[i] == '.' || line[i] == '-')
		i++;
	i++;
	new_object->center.z = ft_atof(&line[i]);
	while (ft_isdigit(line[i]) || line[i] == '.' || line[i] == '-')
		i++;
	while (!(ft_isdigit(line[i]) || (line[i] == '-')))
		i++;
	new_object->n.x = ft_atof(&line[i]);
	while (ft_isdigit(line[i]) || line[i] == '.' || line[i] == '-')
		i++;
	i++;
	new_object->n.y = ft_atof(&line[i]);
	while (ft_isdigit(line[i]) || line[i] == '.' || line[i] == '-')
		i++;
	i++;
	new_object->n.z = ft_atof(&line[i]);
	while (ft_isdigit(line[i]) || line[i] == '.' || line[i] == '-')
		i++;
	while (!(ft_isdigit(line[i])))
		i++;
	new_object->col.r = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	new_object->col.g = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	new_object->col.b = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (!(ft_isdigit(line[i])))
		i++;
	new_object->shine = ft_atof(&line[i]);
	new_object->next = object;
	return(new_object);
}

t_object *ft_add_sphere(t_object *object, char *line)
{
	t_object *new_object;
	int i;

	i = 0;
	new_object = (t_object *)malloc(sizeof(t_object));
	new_object->type = 1;
	while (!(ft_isdigit(line[i]) || (line[i] == '-')))
		i++;
	new_object->center.x = ft_atof(&line[i]);
	while (ft_isdigit(line[i]) || line[i] == '.' || line[i] == '-')
		i++;
	i++;
	new_object->center.y = ft_atof(&line[i]);
	while (ft_isdigit(line[i]) || line[i] == '.' || line[i] == '-')
		i++;
	i++;
	new_object->center.z = ft_atof(&line[i]);
	while (ft_isdigit(line[i]) || line[i] == '.' || line[i] == '-')
		i++;
	while (!(ft_isdigit(line[i])))
		i++;
	new_object->col.r = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	new_object->col.g = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	new_object->col.b = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (!(ft_isdigit(line[i])))
		i++;
	new_object->radius = ft_atof(&line[i]);
	while (ft_isdigit(line[i]) || (line[i] == '.'))
		i++;
	while (!(ft_isdigit(line[i])))
		i++;
	new_object->shine = ft_atof(&line[i]);
	new_object->next = object;
	return(new_object);
}

t_object *ft_add_cyl(t_object *object, char *line)
{
	t_object *new_object;
	int i;

	i = 0;
	new_object = (t_object *)malloc(sizeof(t_object));
	if (line[0] == 'c' && line[1] == 'y')
		new_object->type = 3;
	if (line[0] == 'c' && line[1] == 'o')
		new_object->type = 4;
	while (!(ft_isdigit(line[i]) || (line[i] == '-')))
		i++;
	new_object->center.x = ft_atof(&line[i]);
	while (ft_isdigit(line[i]) || line[i] == '.' || line[i] == '-')
		i++;
	i++;
	new_object->center.y = ft_atof(&line[i]);
	while (ft_isdigit(line[i]) || line[i] == '.' || line[i] == '-')
		i++;
	i++;
	new_object->center.z = ft_atof(&line[i]);
	while (ft_isdigit(line[i]) || line[i] == '.' || line[i] == '-')
		i++;
	while (!(ft_isdigit(line[i]) || (line[i] == '-')))
		i++;
	new_object->n.x = ft_atof(&line[i]);
	while (ft_isdigit(line[i]) || line[i] == '.' || line[i] == '-')
		i++;
	i++;
	new_object->n.y = ft_atof(&line[i]);
	while (ft_isdigit(line[i]) || line[i] == '.' || line[i] == '-')
		i++;
	i++;
	new_object->n.z = ft_atof(&line[i]);
	while (ft_isdigit(line[i]) || line[i] == '.' || line[i] == '-')
		i++;
	while (!(ft_isdigit(line[i])))
		i++;
	new_object->col.r = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	new_object->col.g = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	new_object->col.b = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (!(ft_isdigit(line[i])))
		i++;
	new_object->radius = ft_atof(&line[i]);
	while (ft_isdigit(line[i]) || (line[i] == '.'))
		i++;
	while (!(ft_isdigit(line[i])))
		i++;
	new_object->shine = ft_atof(&line[i]);
	new_object->next = object;
	return(new_object);
}

t_scene *ft_init_rtv(void)
{
	t_scene  *res;

	res = (t_scene*)malloc(sizeof(t_scene));
	res->objects = (t_object*)malloc(sizeof(t_object));
	res->portale = (t_viewport*)malloc(sizeof(t_viewport));
	res->cam_pos = (t_vec *)malloc(sizeof(t_vec));
	res->light = (t_light*)malloc(sizeof(t_light));
	res->ht = 0;
	res->wd = 0;
	return (res);
}

t_scene *ft_build(t_scene *res, char *line)
{
	int i = 0;

	if (line[i] == 'R')
	{
		while (!(ft_isdigit(line[i])))
			i++;
		res->wd = ft_atoi(&line[i]);
		while (ft_isdigit(line[i]))
			i++;
		while (!(ft_isdigit(line[i])))
			i++;
		res->ht = ft_atoi(&line[i]);

	}
	if (line[0] == 'L')
		res->light = ft_add_light(res->light, line);
	if (line[0] == 'p' && line[1] == 'l')
		res->objects = ft_add_plane(res->objects, line);
	if (line[0] == 's' && line[1] == 'p')
		res->objects = ft_add_sphere(res->objects, line);
	if (line[0] == 'c' && (line[1] == 'y' || line[1] == 'o'))
		res->objects = ft_add_cyl(res->objects, line);
	if (line[0] == 'C')
	{
		while (!(ft_isdigit(line[i]) || (line[i] == '-')))
			i++;
		res->cam_pos->x = ft_atof(&line[i]);
		while (ft_isdigit(line[i]) || line[i] == '.' || line[i] == '-')
			i++;
		while (!(ft_isdigit(line[i]) || (line[i] == '-')))
			i++;
		res->cam_pos->y = ft_atof(&line[i]);
		while (ft_isdigit(line[i]) || line[i] == '.' || line[i] == '-')
			i++;
		while (!(ft_isdigit(line[i]) || (line[i] == '-')))
			i++;
		res->cam_pos->z = ft_atof(&line[i]);
		}
	return (res);
}

int main ()
{
	int		fd;
	char	*line;
	int		i;
	t_scene *res;

	if ((fd = open("../test", O_RDONLY)) < 0)
		return (0);
	res = ft_init_rtv();

	while ( get_next_line(fd, &line) > 0 )
	{
		i = 0;
		while (line[i])
		{
			if (ft_isdigit(line[i]) || (line[i] == '-') || (line[i] == ' ') || (line[i] == '.') || (line[i] == ',') || (line[i] == '\n'))
				i++;
			else if ((line[i] == 'p' && line[i+1] == 'l') || (line[i] == 's' && (line[i+1] == 'p' ||  line[i+1] == 'q'))  || (line[i] == 'c' && line[i+1] == 'y')  || (line[i] == 'c' && line[i+1] == 'o'))
				i=i+2;
			else if ((line[i] == 'R') || (line[i] == 'A') || (line[i] == 'C') || (line[i] == 'L'))
				i++;
			else
			{
				write(1, "Error data\n", 11);
				return (0);
			}
		}
		ft_build(res, line);
	}
}
