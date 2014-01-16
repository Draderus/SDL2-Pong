//
//  sprite.cpp
//  SDL2_Pong
//
//  Created by Jake on 12/01/14.
//  Copyright (c) 2014 Draderus. All rights reserved.
//

#include "sprite.h"

// constructor
Sprite::Sprite(float x, float y, float w, float h, float speed, SDL_Texture *tex)
{
    this->x = x;
	this->y = y;
	this->speed = speed;
	directionX = NONE;
	directionY = NONE;
    
    this->texture = tex;
}



SDL_Texture* Sprite::Load(std::string file, SDL_Renderer *ren)
{
    SDL_Surface *loadedImage = nullptr;
    SDL_Texture *texture = nullptr;
    loadedImage = SDL_LoadBMP(file.c_str());
    if (loadedImage != nullptr){
        texture = SDL_CreateTextureFromSurface(ren, loadedImage);
        SDL_FreeSurface(loadedImage);
    }
    else
        std::cout << SDL_GetError() << std::endl;
    return texture;
}



bool Sprite::ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend){
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
    SDL_RenderCopy(rend, tex, NULL, &pos);
}


void Sprite::move(float dx, float dy)
{
    this->x += dx;
    this->y += dy;
    
}

bool Sprite::intersects(Sprite* r) {
    
	if ((x+w/2 < r->x-r->w/2) || (x-w/2 > r->x+r->w/2)
        || (y-h/2 < r->y+r->h/2) || (y+h/2 > r->y-r->h/2))
        return false;
    else{
            return true;
    }
    
}



