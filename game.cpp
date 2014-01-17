//
//  game.cpp
//  SDL2_Pong
//
//  Created by Jake on 12/01/14.
//  Copyright (c) 2014 Draderus. All rights reserved.
//

#include "game.h"

using namespace std;


// constructor
Game::Game()
{
    
}



int Game::Init(const char* title, int width, int height,
               int bpp, bool fullscreen)
{
	
	// initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
        std::cout << SDL_GetError() << std::endl;
        return 1;
    }
	
    window = nullptr;
    
    
    
    window = SDL_CreateWindow(title, 100, 100, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr){
        std::cout << SDL_GetError() << std::endl;
        return 1;
    }
    
    renderer = nullptr;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr){
        std::cout << SDL_GetError() << std::endl;
        return 1;
    }
    
    backgroundSprite = NULL;
    backgroundSprite = Sprite::Load("Data/bg.bmp", renderer);
    
    background = new Sprite(400, 300, 800, 600, 0, backgroundSprite);
    
    
    paddleSprite = NULL;
    paddleSprite = Sprite::Load("Data/paddle.bmp", renderer);
    
    paddle = new Sprite(125, 300, 30, 8, 0, paddleSprite);
	
	
    paddleSprite2 = NULL;
    paddleSprite2 = Sprite::Load("Data/paddle.bmp", renderer);
    
    paddle2 = new Sprite(675, 300, 30, 8, 0, paddleSprite2);
    
    
    ballSprite = NULL;
    ballSprite = Sprite::Load("Data/ball.bmp", renderer);
    
    ball = new Sprite(400, 300, 8, 8, 0, ballSprite);
    
    
    zero = NULL;
    zero = Sprite::Load("Data/0.bmp", renderer);
    
    one = NULL;
    one = Sprite::Load("Data/1.bmp", renderer);
    
    two = NULL;
    two = Sprite::Load("Data/2.bmp", renderer);
    
    three = NULL;
    three = Sprite::Load("Data/3.bmp", renderer);
    
    four = NULL;
    four = Sprite::Load("Data/4.bmp", renderer);
    
    five = NULL;
    five = Sprite::Load("Data/5.bmp", renderer);
    
    six = NULL;
    six = Sprite::Load("Data/6.bmp", renderer);
    
    seven = NULL;
    seven = Sprite::Load("Data/7.bmp", renderer);
    
    eight = NULL;
    eight = Sprite::Load("Data/8.bmp", renderer);
    
    nine = NULL;
    nine = Sprite::Load("Data/9.bmp", renderer);
    
    ten = NULL;
    ten = Sprite::Load("Data/10.bmp", renderer);
    
    eleven = NULL;
    eleven = Sprite::Load("Data/11.bmp", renderer);
    
    twelve = NULL;
    twelve = Sprite::Load("Data/12.bmp", renderer);
    
    thirteen = NULL;
    thirteen = Sprite::Load("Data/13.bmp", renderer);
    
    fourteen = NULL;
    fourteen = Sprite::Load("Data/14.bmp", renderer);
    
    fifteen = NULL;
    fifteen = Sprite::Load("Data/15.bmp", renderer);
    
    sixteen = NULL;
    sixteen = Sprite::Load("Data/16.bmp", renderer);
    
    seventeen = NULL;
    seventeen = Sprite::Load("Data/17.bmp", renderer);
    
    eighteen = NULL;
    eighteen = Sprite::Load("Data/18.bmp", renderer);
    
    nineteen = NULL;
    nineteen = Sprite::Load("Data/19.bmp", renderer);
    
    twenty = NULL;
    twenty = Sprite::Load("Data/20.bmp", renderer);
    
    
    p1points = new Sprite(230, 140, 64, 32, 0, zero);
    
    p2points = new Sprite(570, 140, 64, 32, 0, zero);
	
	
    
	m_bRunning = true;
    
    p1score = 0;
    p2score = 0;
    
    servedir = -1;
    
    srand (static_cast <unsigned> (time(0)));
    
    
    
    
    
    
    sound = NULL;
    int audio_rate = 22050;
    Uint16 audio_format = AUDIO_S16SYS;
    int audio_channels = 2;
    int audio_buffers = 4096;
    if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
        printf("Unable to initialize audio: %s\n", Mix_GetError());
        exit(1);
    }
    sound = Mix_LoadWAV("Data/bounce.wav");
    if(sound == NULL) {
        printf("Unable to load WAV file: %s\n", Mix_GetError());
    }
    
   
    
    
    
    
    
    // print our success
	printf("Game Initialised Succesfully\n");
}



void Game::HandleEvents(Game* game)
{
	SDL_Event event;
	
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
            
			case SDL_QUIT:
				game->Quit();
				break;
				
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_ESCAPE:
						game->Quit();
				}
                
                
                switch (event.key.keysym.sym) {
					case SDLK_w:
						p1moveup = true;
				}
                switch (event.key.keysym.sym) {
					case SDLK_s:
						p1movedown = true;
				}
                                
                switch (event.key.keysym.sym) {
					case SDLK_UP:
						p2moveup = true;
				}
                switch (event.key.keysym.sym) {
					case SDLK_DOWN:
						p2movedown = true;
				}
                
                switch (event.key.keysym.sym) {
					case SDLK_SPACE:
                        if(matchover == false)
                        {
                            game->BeginRound();
                        }
                        if(matchover == true)
                        {
                            game->ResetMatch();
                        }
				}
                
                
				break;
                
                
            case SDL_KEYUP:
				
                
                switch (event.key.keysym.sym) {
					case SDLK_w:
						p1moveup = false;
				}
                switch (event.key.keysym.sym) {
					case SDLK_s:
						p1movedown = false;
				}
                
                switch (event.key.keysym.sym) {
					case SDLK_UP:
						p2moveup = false;
				}
                switch (event.key.keysym.sym) {
					case SDLK_DOWN:
						p2movedown = false;
				}
                
                
				break;
               
                
		}
	}
	
}



void Game::Update()
{
    if(paddle->y < 80)
    {
        paddle->move(0, 4);
        
    }
    if(paddle->y > 520)
    {
        paddle->move(0, -4);
        
    }
    
    if(paddle2->y < 80)
    {
        paddle2->move(0, 4);
        
    }
    if(paddle2->y > 520)
    {
        paddle2->move(0, -4);
        
    }
    
    if(start == true)
    {
        ball->move(ballx, bally);
        
    }
    
    if(p1moveup == true)
    {
        paddle->move(0, -4);
        
    }
    if(p1movedown == true)
    {
        paddle->move(0, 4);
        
    }
    
    if(p2moveup == true)
    {
        paddle2->move(0, -4);
        
    }
    if(p2movedown == true)
    {
        paddle2->move(0, 4);
        
    }
    
    
    
    if(((ball->x-4 < paddle->x+4) && (ball->y+4 > paddle->y-15) && (ball->y-4 < paddle->y+15))&&ballx<0 && ball->x+4>paddle->x+4)
    {
        ballx = -ballx;
        
        int random = rand()%2;
        
        if(random == 0)
        {
            bally = 0.6 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2-0.6)));
            
        }
        if(random == 1)
        {
            bally = -0.6 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(-0.6+2)));
            
        }
        
        channel = Mix_PlayChannel(-1, sound, 0);
        if(channel == -1) {
            printf("Unable to play WAV file: %s\n", Mix_GetError());
        }
        while(Mix_Playing(channel) != 0);
    }
    
    
    
    if(ball->x-4 < 0)
    {
        p2score++;
       
        cout << "1 point to p2" << endl;
        cout << "p1: " << p1score << endl;
        cout << "p2: " << p2score << endl;
        
        if((p2score == 11 && p2score - p1score >= 2) || (p2score > 11 && p2score - p1score >= 2))
        {
            Winner();
        }
        
        if(p1score == 20 && p2score == 20)
        {
            Winner();
        }
        
        
        ResetBall();
        
    }
    
   
    if(((ball->x+4 > paddle2->x-4) && (ball->y+4 > paddle2->y-15) && (ball->y-4 < paddle2->y+15))&&ballx>0 && ball->x-4<paddle2->x-4)
    {
        ballx = -ballx;
        
        int random = rand()%2;
        
        if(random == 0)
        {
            bally = 1.2 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(4-1.2)));
            
        }
        if(random == 1)
        {
            bally = -1.2 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(-1.2+4)));
            
        }
        
        channel = Mix_PlayChannel(-1, sound, 0);
        if(channel == -1) {
            printf("Unable to play WAV file: %s\n", Mix_GetError());
        }
        while(Mix_Playing(channel) != 0);
    }
    
        
    if(ball->x+4 > 800)
    {
        p1score++;
        
        cout << "1 point to p1" << endl;
        cout << "p1: " << p1score << endl;
        cout << "p2: " << p2score << endl;
        
        if((p1score == 11 && p1score - p2score >= 2) || (p1score > 11 && p1score - p2score >= 2))
        {
            Winner();
        }
        
        if(p1score == 20 && p2score == 20)
        {
            Winner();
        }
        
        
        ResetBall();
        
    }
    
    
    if((ball->y-4 < 65) || ball->y+4 > 535)
    {
        bally = -bally;
        
        channel = Mix_PlayChannel(-1, sound, 0);
        if(channel == -1) {
            printf("Unable to play WAV file: %s\n", Mix_GetError());
        }
        while(Mix_Playing(channel) != 0);
        
    }
  
  
            
    
}

void Game::Draw()
{
    SDL_RenderClear(renderer);
    
    int iW, iH;
    SDL_QueryTexture(background->texture, NULL, NULL, &iW, &iH);
    int x = background->x - iW / 2;
    int y = background->y - iH / 2;
    Sprite::ApplySurface(x, y, background->texture, renderer);
    
    
    int jW, jH;
    SDL_QueryTexture(paddle->texture, NULL, NULL, &jW, &jH);
    int x2 = paddle->x - jW / 2;
    int y2 = paddle->y - jH / 2;
    Sprite::ApplySurface(x2, y2, paddle->texture, renderer);
    
    
    int kW, kH;
    SDL_QueryTexture(paddle2->texture, NULL, NULL, &kW, &kH);
    int x3 = paddle2->x - kW / 2;
    int y3 = paddle2->y - kH / 2;
    Sprite::ApplySurface(x3, y3, paddle2->texture, renderer);
    
    
    int lW, lH;
    SDL_QueryTexture(ball->texture, NULL, NULL, &lW, &lH);
    int x4 = ball->x - lW / 2;
    int y4 = ball->y - lH / 2;
    Sprite::ApplySurface(x4, y4, ball->texture, renderer);
    
    
    int mW, mH;
    SDL_QueryTexture(p1points->texture, NULL, NULL, &mW, &mH);
    int x5 = p1points->x - mW / 2;
    int y5 = p1points->y - mH / 2;
    Sprite::ApplySurface(x5, y5, p1points->texture, renderer);
    
    int nW, nH;
    SDL_QueryTexture(p2points->texture, NULL, NULL, &nW, &nH);
    int x6 = p2points->x - nW / 2;
    int y6 = p2points->y - nH / 2;
    Sprite::ApplySurface(x6, y6, p2points->texture, renderer);
    
    SDL_RenderPresent(renderer);
}

bool Game::Running() {return m_bRunning;}

void Game::BeginRound()
{
    if(ballx == 0)
    {
    
    start = true;
    
    ballx = 6*servedir;
    bally = -1.2;
    
    }
}


void Game::ResetBall()
{
    
    
    ball->x = 400;
    ball->y = 300;
    
    ballx = 0;
    bally = 0;
    
    servedir = -servedir;
    
    start = false;
    
    if(p1score == 1)
    {
        p1points = new Sprite(230, 140, 64, 32, 0, one);
    }
    
    if(p1score == 2)
    {
        p1points = new Sprite(230, 140, 64, 32, 0, two);
    }
    
    if(p1score == 3)
    {
        p1points = new Sprite(230, 140, 64, 32, 0, three);
    }
    
    if(p1score == 4)
    {
        p1points = new Sprite(230, 140, 64, 32, 0, four);
    }
    
    if(p1score == 5)
    {
        p1points = new Sprite(230, 140, 64, 32, 0, five);
    }
    
    if(p1score == 6)
    {
        p1points = new Sprite(230, 140, 64, 32, 0, six);
    }
    
    if(p1score == 7)
    {
        p1points = new Sprite(230, 140, 64, 32, 0, seven);
    }
    
    if(p1score == 8)
    {
        p1points = new Sprite(230, 140, 64, 32, 0, eight);
    }
    
    if(p1score == 9)
    {
        p1points = new Sprite(230, 140, 64, 32, 0, nine);
    }
    
    if(p1score == 10)
    {
        p1points = new Sprite(178, 140, 64, 32, 0, ten);
    }
    
    if(p1score == 11)
    {
        p1points = new Sprite(178, 140, 64, 32, 0, eleven);
    }
    
    if(p1score == 12)
    {
        p1points = new Sprite(178, 140, 64, 32, 0, twelve);
    }
    
    if(p1score == 13)
    {
        p1points = new Sprite(178, 140, 64, 32, 0, thirteen);
    }
    
    if(p1score == 14)
    {
        p1points = new Sprite(178, 140, 64, 32, 0, fourteen);
    }
    
    if(p1score == 15)
    {
        p1points = new Sprite(178, 140, 64, 32, 0, fifteen);
    }
    
    if(p1score == 16)
    {
        p1points = new Sprite(178, 140, 64, 32, 0, sixteen);
    }
    
    if(p1score == 17)
    {
        p1points = new Sprite(178, 140, 64, 32, 0, seventeen);
    }
    
    if(p1score == 18)
    {
        p1points = new Sprite(178, 140, 64, 32, 0, eighteen);
    }
    
    if(p1score == 19)
    {
        p1points = new Sprite(178, 140, 64, 32, 0, nineteen);
    }
    
    if(p1score == 20)
    {
        p1points = new Sprite(178, 140, 64, 32, 0, twenty);
    }
    
    
    
    
    if(p2score == 1)
    {
        p2points = new Sprite(570, 140, 64, 32, 0, one);
    }
    
    if(p2score == 2)
    {
        p2points = new Sprite(570, 140, 64, 32, 0, two);
    }
    
    if(p2score == 3)
    {
        p2points = new Sprite(570, 140, 64, 32, 0, three);
    }
    
    if(p2score == 4)
    {
        p2points = new Sprite(570, 140, 64, 32, 0, four);
    }
    
    if(p2score == 5)
    {
        p2points = new Sprite(570, 140, 64, 32, 0, five);
    }
    
    if(p2score == 6)
    {
        p2points = new Sprite(570, 140, 64, 32, 0, six);
    }
    
    if(p2score == 7)
    {
        p2points = new Sprite(570, 140, 64, 32, 0, seven);
    }
    
    if(p2score == 8)
    {
        p2points = new Sprite(570, 140, 64, 32, 0, eight);
    }
    
    if(p2score == 9)
    {
        p2points = new Sprite(570, 140, 64, 32, 0, nine);
    }
    
    if(p2score == 10)
    {
        p2points = new Sprite(622, 140, 64, 32, 0, ten);
    }
    
    if(p2score == 11)
    {
        p2points = new Sprite(622, 140, 64, 32, 0, eleven);
    }
    
    if(p2score == 12)
    {
        p2points = new Sprite(622, 140, 64, 32, 0, twelve);
    }
    
    if(p2score == 13)
    {
        p2points = new Sprite(622, 140, 64, 32, 0, thirteen);
    }
    
    if(p2score == 14)
    {
        p2points = new Sprite(622, 140, 64, 32, 0, fourteen);
    }
    
    if(p2score == 15)
    {
        p2points = new Sprite(622, 140, 64, 32, 0, fifteen);
    }
    
    if(p2score == 16)
    {
        p2points = new Sprite(622, 140, 64, 32, 0, sixteen);
    }
    
    if(p2score == 17)
    {
        p2points = new Sprite(622, 140, 64, 32, 0, seventeen);
    }
    
    if(p2score == 18)
    {
        p2points = new Sprite(622, 140, 64, 32, 0, eighteen);
    }
    
    if(p2score == 19)
    {
        p2points = new Sprite(622, 140, 64, 32, 0, nineteen);
    }
    
    if(p2score == 20)
    {
        p2points = new Sprite(622, 140, 64, 32, 0, twenty);
    }
    
    
    
    
}

void Game::Winner()
{
    
    matchover = true;
    
    if(p1score > p2score)
    {
        cout << "Player One Wins!!!" << endl;
    }
    if(p2score > p1score)
    {
        cout << "Player Two Wins!!!" << endl;
    }
    
    if(p1score == 20 && p2score == 20)
    {
        cout << "Its a Draw!!!" << endl;
    }
    
    
    cout << "Play Again: Press Space" << endl;
    cout << "Quit: Press Escape" << endl;
    
}


void Game::ResetMatch()
{
    matchover = false;
    
    p1score = 0;
    p2score = 0;
    
    paddle->y = 300;
    paddle2->y = 300;
    
    servedir = -1;
    
    p1points = new Sprite(230, 140, 64, 32, 0, zero);
    
    p2points = new Sprite(570, 140, 64, 32, 0, zero);
}



void Game::Quit() { m_bRunning = false;}

void Game::Clean()
{
    SDL_DestroyTexture(backgroundSprite);
    SDL_DestroyTexture(paddleSprite);
    SDL_DestroyTexture(paddleSprite2);
    SDL_DestroyTexture(ballSprite);
    SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
    Mix_FreeChunk(sound);
    Mix_CloseAudio();
    SDL_Quit();
}



