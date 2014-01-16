//
//  sprite.h
//  SDL2_Pong
//
//  Created by Jake on 12/01/14.
//  Copyright (c) 2014 Draderus. All rights reserved.
//

#ifndef __SDL2_Pong__sprite__
#define __SDL2_Pong__sprite__

#include <iostream>

#include <SDL2/SDL.h>

#include <SDL2/SDL_image.h>

#include <stdexcept>

class Sprite
{
public:
    
    Sprite(float, float, float, float, float, SDL_Texture*);
    
    static SDL_Texture* Load(std::string file, SDL_Renderer *ren);
    
    static bool ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);
    
    void move(float dx, float dy);
    
    enum DIRECTION { UP = -1, DOWN = 1, NONE = 0};
    
    SDL_Texture *texture;

    float x, y;
    float w, h;
    float speed;
    DIRECTION directionX, directionY;
    
    bool intersects(Sprite* r);
    
   
};

#endif /* defined(__SDL2_Pong__sprite__) */
