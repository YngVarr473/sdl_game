#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>

static SDL_Window *window;
static SDL_Renderer *render;
SDL_FRect rect = {12, 12, 72, 72};
float speed = 3.2;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer("sdl_game", 1280, 720, 0, &window, &render);
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
    SDL_SetRenderDrawColor(render, 30, 30, 30, 185);
    SDL_RenderClear(render);

    const bool* keys = SDL_GetKeyboardState(NULL);

    if(keys[SDL_SCANCODE_W]){
        rect.y -= speed;
    }
    if(keys[SDL_SCANCODE_S]){
        rect.y += speed;
    }
    if(keys[SDL_SCANCODE_A]){
        rect.x -= speed;
    }
    if(keys[SDL_SCANCODE_D]){
        rect.x += speed;
    }
    
    SDL_SetRenderDrawColor(render, 120, 82, 148, 255);
    SDL_RenderFillRect(render, &rect);
    SDL_RenderPresent(render);
    SDL_Delay(16);

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
    switch(event->type) {
        case SDL_EVENT_QUIT:
            return SDL_APP_SUCCESS;
            break;
        default:
            break;
    }
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result){
}
