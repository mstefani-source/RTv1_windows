#ifndef MLSDL_MLSDL_H
# define MLSDL_MLSDL_H

#include "../SDL/include/SDL2/SDL.h"
#include "../SDL/include/SDL2/SDL_image.h"

typedef struct      s_mlsdl_data
{
    int             *pix;
    int             *bits_per_pixel;
    int             *size_line; 
    int             *endian;
}                   t_mlsdl_data;

typedef struct      s_mlsdl
{
    SDL_Window      *pointer;
    SDL_Renderer    *render;
    SDL_Surface     *surface;
    SDL_Texture     *txt;
    t_mlsdl_data    *data;
}                   t_mlsdl;

int                 mlsdl_init();
SDL_Window         *mlsdl_new_window(int width, int height, char* title);
SDL_Renderer       *mlsdl_new_rend(SDL_Window *sdl_window_pointer);
SDL_Surface        *mlsdl_new_surface(SDL_Window *sdl_window_pointer, int width, int height);
SDL_Texture        *mlsdl_new_texture(SDL_Renderer *sdl_window_render, int width, int height);
void               *mlsdl_put_texture_to_render(SDL_Renderer *sdl_window_render, SDL_Texture *sdl_window_texture);
char               *mlsdl_get_data_addr(SDL_Texture *sdl_window_texture, int *bits_per_pixel, int *size_line, int *endian);
void               *mlsdl_close_window(t_mlsdl *sdl);
void	            mlsdl_loop(t_mlsdl *sdl);
void                mlsdl_key_press(int key, void (*ptr)(void));
void                mlsdl_event_listening();

#endif    