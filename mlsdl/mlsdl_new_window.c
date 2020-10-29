#include "mlsdl.h"

SDL_Window   *mlsdl_new_window(int width, int height, char* title)
{
    SDL_Window* sdl_window_pointer;

    sdl_window_pointer = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (!sdl_window_pointer)
         return ((void *)0);
    return (sdl_window_pointer);
}