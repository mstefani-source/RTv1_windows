/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:40:49 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/28 17:02:58 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv.h"

void 	free_obj(t_scene *rt)
{
	t_object *tmp;
	t_object *next;
	tmp = rt->objects->next;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(rt->objects);
}

void 	free_rt(t_scene *rt)
{
	free_obj(rt);
	free(rt->cam_pos);

	t_light *tmp;
	t_light *next;
	tmp = rt->light->next;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(rt->light);
}

int		main(int argc, char **argv)
{
	t_mlsdl		*sdl;
	t_scene		*rtv;

	if (argc == 1)
	{
		write(1, "Error data\n", 11);
		exit (0);
	}
	rtv = ft_parce_scene(argv[1]);
	sdl = ft_init_window((int)rtv->wd, (int)rtv->ht);
	ft_draw_scene(sdl, rtv);
	SDL_UpdateTexture(sdl->txt, NULL, sdl->data->pix, sizeof(Uint32) * rtv->wd);
	free_rt(rtv);
	mlsdl_put_texture_to_render(sdl->render, sdl->txt);
	mlsdl_loop(sdl);
	mlsdl_close_window(sdl);
	return (0);
}
