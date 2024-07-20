#include <SDL2/SDL.h>
#include <stdio.h>

int WIDHT = 800;
int HEIGHT = 600;

int main (int argc, char *argv[]){
    SDL_Init( SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("GameBoy Emulator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDHT, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

    if(NULL == window){
        printf("Não foi possível criar a janela: ", SDL_GetError());
        return 1;
    }

    SDL_Event windowEvent;

    while(1){
        if(SDL_PollEvent(&windowEvent)){
            if(SDL_Quit == windowEvent.type){break;}
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}