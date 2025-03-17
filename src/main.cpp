#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

static SDL_Window *window;
static SDL_Renderer *render;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer("sdl_game", 1280, 720, 0, &window, &render);
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
    SDL_SetRenderDrawColor(render, 30, 30, 30, 185);
    SDL_RenderClear(render);

	SDL_SetRenderDrawColor(render, 100, 30, 200, 185);
    SDL_FRect rect;
    rect.x = 100;
    rect.y = 100;
    rect.w = 100;
    rect.h = 100;
	   
    SDL_RenderFillRect(render, &rect);

    SDL_FRect rectBorder;
    rectBorder.x = 300;
    rectBorder.y = 300;
    rectBorder.w = 100;
    rectBorder.h = 100;
    SDL_RenderRect(render, &rectBorder);

    SDL_RenderLine(render, 450, 100, 500, 200);

    SDL_FPoint lines[] = {
        {100, 320}, {200, 250}, {600, 720}, {400, 520}
    };

    SDL_RenderLines(render, lines, SDL_arraysize(lines));

    SDL_RenderPoint(render, 50, 50);

    SDL_RenderPresent(render);
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
    if (event->type == SDL_EVENT_QUIT)
    {
        return SDL_APP_SUCCESS;
    }
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result){
}
