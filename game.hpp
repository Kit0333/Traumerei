#ifndef GAME_HPP
#define GAME_HPP
#include <gameState.hpp>
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
class Game{
public:
    Game(const char* title,Uint32 flags,int &width,int &height);
    ~Game();
    
    SDL_Texture* loadTexture(const char* filePath);
    
    void render(SDL_Texture* tex,int x=0,int y=0,int w=1024,int h=600);
    
    GameState getGameState();
    
    int& mousePress(SDL_MouseButtonEvent& b);
    
    void gameStateChange(GameState x);
    
    void run();
    void clear();
    void display();
    void cleanup();
    //Methods to manilupate the screen

private:





    void UserScreenSize(int&width, int &height);

    GameState m_gameState;
    
    SDL_Window* m_window;

    SDL_Renderer* m_renderer;
};
 
  

  


#endif