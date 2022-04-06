
//==============================================================================
#ifndef MINIGAME_H
#define MINIGAME_H
//==============================================================================



//================
//defines
//================



//================
//variables
//================
extern float 	TV_aspectratio;// = 1.0f;//((float)(((float)(GAME_VIEWPORT_HEIGHT_PIXELS)/1.6f))/192.0f);
extern int 	TV_fromx;// = 0; //((GAME_VIEWPORT_WIDTH_PIXELS-(TETRID_aspectratio*256.0f))/2);
extern int 	TV_fromy;// = 0;//(GAME_VIEWPORT_HEIGHT_PIXELS/3.5f)+7-4;

//================
//prototypes
//================



void load_gametoy();
void unload_gametoy();

void load_gametoy_broken();
void unload_gametoy_broken();

void load_gametoy_fullscreen();
void unload_gametoy_fullscreen();

void load_tv_fullscreen();
void load_ping_tv_fullscreen();
void unload_tv_fullscreen();










//==============================================================================
#endif
//==============================================================================
