//
//  game.h
//  SDL2_Pong
//
//  Created by Jake on 12/01/14.
//  Copyright (c) 2014 Draderus. All rights reserved.
//

#ifndef __SDL2_Pong__game__
#define __SDL2_Pong__game__

#include <iostream>

#include <SDL2/SDL.h>

#include <SDL2_mixer/SDL_mixer.h>

#include "sprite.h"


class Game
{
public:
    
    Game();
    
    int Init(const char* title, int width, int height,
             int bpp, bool fullscreen);
    
    void HandleEvents(Game* game);
    
    void Update();
    
    void Draw();
    
    void Clean();
    
    bool Running();
    
    void BeginRound();
    
    void ResetBall();
    
    void Winner();
    
    void ResetMatch();
    
    void Quit();

    SDL_Renderer *renderer;
    
    bool start;
    
    bool matchover;
    
    Mix_Chunk *sound;
    int channel;
    
    bool p1moveup;
    bool p1movedown;
    
    int servedir;
   
    int p1score;
    int p2score;
       bool p2moveup;
    bool p2movedown;
    
    float ballx, bally;
    
    
    
    
private:
    
    SDL_Window *window;
    
    bool  m_bRunning;
    
    SDL_Texture *backgroundSprite;
    
    Sprite *background;
    
    
    SDL_Texture *paddleSprite;
    
    Sprite *paddle;
    
    
    SDL_Texture *paddleSprite2;
    
    Sprite *paddle2;
    
    
    SDL_Texture *ballSprite;
    
    Sprite *ball;
    
    Sprite *p1points;
    Sprite *p2points;
    
    SDL_Texture *zero;
    SDL_Texture *one;
    SDL_Texture *two;
    SDL_Texture *three;
    SDL_Texture *four;
    SDL_Texture *five;
    SDL_Texture *six;
    SDL_Texture *seven;
    SDL_Texture *eight;
    SDL_Texture *nine;
    SDL_Texture *ten;
    SDL_Texture *eleven;
    SDL_Texture *twelve;
    SDL_Texture *thirteen;
    SDL_Texture *fourteen;
    SDL_Texture *fifteen;
    SDL_Texture *sixteen;
    SDL_Texture *seventeen;
    SDL_Texture *eighteen;
    SDL_Texture *nineteen;
    SDL_Texture *twenty;
   
    
};


#endif /* defined(__SDL2_Pong__game__) */
