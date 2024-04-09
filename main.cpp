#include "file.h/Header.h"

int main( int argc, char* argv[]){
    init();
    loadMedia();    
    Game game;
    game.Play();
    game.FreeBird();
    close();
    return 0;
}
bool loadMedia(){
	bool success = true;   
                                                                    //BACKGROUND LOADING  
	gBackgroundTexture.loadFromFile( gBackGroundTexture_path );
        for(int i = 0; i < BACKGROUND_FRAME;i++){
            gSpriteBackground[i].x = 0;
            gSpriteBackground[i].y = 0;
            gSpriteBackground[i].w = BACKGROUND_WIDTH;
            gSpriteBackground[i].h = BACKGROUND_HEIGHT;
        }
                                                                    //BASE LOADING
    gBaseSurface.loadFromFile( gBaseSurface_path );
                                                                    //BIRD LOADING
    for(int i = 0; i <FLYING_ANIMATION_FRAMES_OF_BIRD;i++){     //=> continuous bird
        string imagePath = "Sprites/bluebird" + to_string(i + 1) + ".png"; 
        gBird[i].loadFromFile(imagePath);
    }
                                                                    //MUSIC LOADING
    gFly = Mix_LoadWAV(gFly_path);
    gMusic = Mix_LoadMUS(gMusic_path);
    gSwoosh = Mix_LoadWAV(gSwoosh_path);
    gMoneyCol = Mix_LoadWAV(gMoneyCol_path);
    gSwapBullet = Mix_LoadWAV(gSwapBullet_path);
    gExplosion = Mix_LoadWAV(gExplosion_path);
    gDie = Mix_LoadWAV(gDie_path);
    gBubbleAdd = Mix_LoadWAV(gBubbleAdd_path);
    gBubblePow = Mix_LoadWAV(gBubllePow_path);
    gScoreIncrement = Mix_LoadWAV(gScoreIncrement_path);
                                                                    //BUTTON CONTORL LOADING
    gButtonControlGame[PAUSE].loadFromFile(gButtonControlGame_PAUSE_path);
    gButtonControlGame[PLAY].loadFromFile(gButtonControlGame_PLAY_path);
    gButtonControlGame[REPLAY].loadFromFile(gButtonControlGame_REPLAY_path);
    gButtonControlGame[EXIT].loadFromFile(gButtonControlGame_EXIT_path);
	return success;
}
void close() {
                                                                    //FREE LTEXTURE
    for (int i = 0; i < FLYING_ANIMATION_FRAMES_OF_BIRD; ++i) gBird[i].free();// => free loaded image
    gBaseSurface.free();
    gBackgroundTexture.free();
    gButtonControlGame[0].free();
    gButtonControlGame[1].free();
    gButtonControlGame[2].free();
    gButtonControlGame[3].free();
                                                                    //FREE MUSICE
    Mix_FreeChunk( gFly );  gFly = NULL;
    Mix_FreeMusic( gMusic ); gMusic = NULL;
    Mix_FreeChunk( gSwoosh ); gSwoosh = NULL;
    Mix_FreeChunk( gMoneyCol ); gMoneyCol = NULL;
    Mix_FreeChunk( gDie ); gDie = NULL;
    Mix_FreeChunk( gExplosion ); gExplosion = NULL;
    Mix_FreeChunk( gSwapBullet ); gSwapBullet = NULL;
    Mix_FreeChunk( gBubbleAdd ); gBubbleAdd = NULL;
    Mix_FreeChunk( gBubblePow ); gBubblePow = NULL;
    Mix_FreeChunk( gScoreIncrement ); gScoreIncrement = NULL;
	                                                                //DESTROY TEXTURE
    SDL_DestroyTexture(pipeTexture); pipeTexture = NULL;   
    pipeSurface = NULL;

                                                                    //DESTROY RENDER,WINDOW
    SDL_DestroyRenderer(gRenderer);  gRenderer = NULL;
    SDL_DestroyWindow(gWindow);      gWindow= NULL;
                                                                    //DESTROY FONT
    TTF_CloseFont(gFontText);gFontText = NULL;
    TTF_CloseFont(gFontMENU);gFontMENU = NULL;
    TTF_CloseFont(gFont);gFont = NULL;
                                                                    //DESTROY SURFACE
    IMG_Quit();
    Mix_Quit();
    SDL_Quit();
}
