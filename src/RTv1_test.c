#include  "../include/RTv1.h"


int main_test(int argc, char* argv[]) 
{
	t_mlsdl*    sdl;
	t_scene*   	rtv;
	SDL_Window* pointer;

	if (!(sdl = (t_mlsdl*)ft_memalloc(sizeof(t_mlsdl))))
		exit(2);
	SDL_Init(SDL_INIT_VIDEO);

	rtv = ft_set_scene(argv[1]);

/*	if (!(pointer = SDL_CreateWindow("SDL Game", 0, 0, SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_HIDDEN)))
		exit(1);*/
	
	
	pointer = SDL_CreateWindow("SDL Game", 0, 0, 600, 800, SDL_WINDOW_HIDDEN);
	SDL_ShowWindow(pointer);



	SDL_Event event;
	int running = 1;
	while(running) 
	{
		while(SDL_PollEvent(&event)) 
		{
			if(event.type == SDL_QUIT) 
			{
				running = 0;
			}
    	}
	SDL_Delay( 32 );
	}
	SDL_DestroyWindow(pointer);
	SDL_Quit();
	free(rtv);
	return 0;
}