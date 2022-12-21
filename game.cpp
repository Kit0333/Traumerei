#include <headers/game.hpp>
#include <headers/gameState.hpp>
#include <iostream>

GameState Game::getGameState(){
    return m_gameState;
};

void Game::gameStateChange(GameState x){
    m_gameState=x;
};




Game::Game(const char* title,Uint32 flags,int &width,int &height) {
    SDL_Init(SDL_INIT_EVERYTHING);
    
    UserScreenSize(width,height);
    _window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, width,height, flags);
    _renderer = SDL_CreateRenderer(m_window, -1, 0);
    _gameState = GameState::PLAY;


};

Game::~Game() {
    delete _map;
};

void Game::UserScreenSize(int &width,int &height){
    //the method modify the width and height depending on the size of the user's screen

    SDL_DisplayMode displaymode;
    if(SDL_GetCurrentDisplayMode(0,&displaymode)!=0){
        SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
        width=1024;
        height=600;
      //default value of the screen
      // 1024 x 600
    }
    else{
        width=displaymode.w;
        height=displaymode.h;
      //It switches the value of the width and the height
    }

};

void Game::run(){
    clear();
    display();
}

void Game::render(SDL_Texture* tex,int x,int y,int w,int h){
    /*SDL_Rect src;
    src.x=x;
    src.y=y;
    src.w=w;
    src.h=h;
*/
    SDL_Rect dist;
    dist.x=x;
    dist.y=y;
    dist.w=w;
    dist.h=h;

    SDL_RenderCopy(m_renderer,tex,NULL,&dist);
};


SDL_Texture* Game::loadTexture(const char* filePath){
    
    SDL_Texture* tex=NULL;
    tex=IMG_LoadTexture(m_renderer,filePath);

    if(tex==NULL){
        std::cout<<"img couldn't load from file path "<<filePath<<" ERROR : "<<SDL_GetError()<<std::endl;
    }
    return tex;

};

void Game::display(){
    SDL_RenderPresent(m_renderer);

}

void Game::clear(){
    SDL_RenderClear(m_renderer);
}

void Game::cleanup(){
    SDL_DestroyWindow(m_window);
}


int& Game::mousePress(SDL_MouseButtonEvent& b){
    static int state;
    if(b.button==SDL_BUTTON_LEFT){
        state=0;//0= left click
    }
    else{
        state=1;//1=right click
    }
    return state;
};