/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:06:43 by mstefani          #+#    #+#             */
/*   Updated: 2019/09/22 17:51:13 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlsdl/mlsdl.h"
#include "../libft/libft.h"
#include "../include/RTv1.h"

t_mlsdl		*ft_init_window(int w, int h)
{
	t_mlsdl	*sdl_wind;
	int		size;

	if (!(sdl_wind = (t_mlsdl*)ft_memalloc(sizeof(t_mlsdl))))
		exit(2);
	if (mlsdl_init() != 1)
		mlsdl_close_window(sdl_wind);
	if (!(sdl_wind->pointer = mlsdl_new_window(w, h, "RTv1")))
		mlsdl_close_window(sdl_wind);
	if (!(sdl_wind->render = mlsdl_new_rend(sdl_wind->pointer)))
	{
		write(1, "NO_Render\n", 10);
		mlsdl_close_window(sdl_wind);
	}
	if (!(sdl_wind->txt = mlsdl_new_texture(sdl_wind->render, w, h)))
	{
		write(1, "NO_Texture\n", 11);
		mlsdl_close_window(sdl_wind);
	}
	size = w * h;
	sdl_wind->data = (t_mlsdl_data*)malloc(size * sizeof(sdl_wind->data));
	sdl_wind->data->pix = (int*)malloc(size * sizeof(int));
	return (sdl_wind);
}
