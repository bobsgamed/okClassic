
//==============================================================================
#ifndef MAIN_H
#define MAIN_H
//==============================================================================


#define _USING_V110_SDK71_ 1
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif



///-----------------------------
///C libs
///-----------------------------
#include <stdlib.h>
#include <math.h>
//#include <unistd.h>
#include <time.h>
#include <stdint.h>
#include <stdio.h>
//#include <stdarg.h>
//#include <string.h>
//#include <assert.h>
//#include <setjmp.h>
//#include <sys/time.h>
//#include <sys/stat.h>
//#include <dirent.h>
//#include <errno.h>
//#include <fcntl.h>
//#include <malloc.h>


#include "engine/main/types.h"


///-----------------------------
///C++ libs
///-----------------------------
#include <iostream>
#include <iomanip>


///-----------------------------
///GL libs
///-----------------------------

//glu is outdated and i dont have it anyway
#ifndef GLEW_NO_GLU
#define GLEW_NO_GLU
#endif

//because im including glew.c instead of linking to the lib/dll
#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif

#include "GL/glew.h"
#include "GL/wglew.h"



///-----------------------------
///SDL libs
///-----------------------------
#include "SDL.h"

#define NO_SDL_GLEXT
#include "SDL_opengl.h"

#define BYTE_RED 2
#define BYTE_GREEN 1
#define BYTE_BLUE 0

#include "SDL_mixer.h"
#include "SDL_ttf.h"
//#include "SDL_image.h"
//#include "SDL_net.h"

/*

///-----------------------------
///SDL+ libs
///-----------------------------
#include "SDL_rotozoom.h"
#include "SDL_config_lib.h"


///-----------------------------
///other libs
///-----------------------------
#include "chipmunk.h"
#include "Box2D/Box2D.h"

//windows.h defines DELETE which causes an error in a Guichan header
#if defined (DELETE)
#undef DELETE
#endif
#include <guichan.hpp>
#include <guichan/sdl.hpp>
#include <guichan/opengl.hpp>
// A class used to load images for OpenGL using SDL
#include <guichan/opengl/openglsdlimageloader.hpp>

*/


//extern "C"
//{
//#include "../lib/ini/iniparser.h"
//#include "../lib/ini/textfile.h"
//}




//================
//defines
//================

#define GL_TEXTURE_CROP_RECT_OES 0




//================
//variables
//================


extern void (*glDrawTexiES)(int,int,int,int,int);

extern bool vbl_done;
extern bool timer_done;

extern Uint32 rmask, gmask, bmask, amask;

extern TTF_Font *font_bobsgame_8px;
extern TTF_Font *font_bobsgame_16px;

extern bool seeded;

extern bool vbl_init;

extern bool GAME_is_running;

extern bool append_screen;

extern int MAIN_QUIT;



extern bool GLOBAL_hq2x_is_on;

extern int HARDWARE_brightness;
extern int vsync;
extern int fpsmeter;




//-----------------------------
//ini variables
//-----------------------------

extern int debug;

extern int fullscreen;
extern int skiptext;
extern int easymode;
extern int cheater;

//-----------------------------
//SDL variables
//-----------------------------
extern bool quit;

//-----------------------------
//timer stuff
//-----------------------------
extern int framesrendered;
extern int secondspassed;
extern int lastsecondspassed;
extern int fps;

extern int vbl_ticks;
extern int render_ticks;

extern LARGE_INTEGER hires_ticks_per_second;//=0;
extern LARGE_INTEGER newvbltimer;//=0;
extern LARGE_INTEGER lastvbltimer;//=0;


//typedef void (*actionfunction)();


/*
char TEXT_button_icon_Bitmap[64] //__attribute__ ((aligned (4)))
= //was const but doesnt matter for nds
{
0,0,5,5,5,5,0,0,
0,5,4,3,3,4,5,0,
5,4,3,1,1,3,4,5,
5,3,1,3,3,1,3,5,
5,3,1,1,1,1,3,5,
5,4,1,3,3,1,4,5,
0,5,4,3,3,4,5,0,
0,0,5,5,5,5,0,0
};

char TEXT_button_icon_underneath_Bitmap [64] //__attribute__ ((aligned (4)))
=//was const but doesnt matter for nds
{
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
1,3,0,0,0,0,3,1,
1,3,3,3,3,3,3,1,
0,1,3,3,3,3,1,0,
0,0,1,1,1,1,0,0
};

char answer_cursor_Bitmap[64] //__attribute__ ((aligned (4)))
=//was const but doesnt matter for nds
{
0,0,2,0,0,0,0,0,
0,0,2,2,0,0,0,0,
0,0,2,2,2,0,0,0,
0,0,2,2,2,2,0,0,
0,0,2,2,2,0,0,0,
0,0,2,2,0,0,0,0,
0,0,2,0,0,0,0,0,
0,0,0,0,0,0,0,0
};


int randomtempsprite[64*64]= {0};//  __attribute__ ((aligned (4))) = {0}; //for random npcs
int randomtempcarsprite[64*64]= {0};//  __attribute__ ((aligned (4))) = {0}; //for random cars
*/

//int TEXT_sprite_window_Bitmap[32*64] = {1};
//	__attribute__ ((aligned (4))) = {0};
//int caption_box_sprite_Bitmap [64*32*4]= {1};// 	__attribute__ ((aligned (4))) = {0};
//int TEXT_box_indexed_gfx_data[64*64*4*3]= {1};// 	__attribute__ ((aligned (4))) = {0};


//char caption_box_sprite_GFX[1024];
//char TEXT_box_sprite_GFX[1024];
//char TEXTANSWER_draw_answerbox_text_sprite_GFX[1024];



//================
//prototypes
//================

void main_vbl();
void reset_controls();

void DO_NOTHING_Function();
void DO_NOTHING_Function(BOOL);

///-----------------------------
///game headers
///-----------------------------

#include "engine/game.h"

#include "engine/main/debug.h"
#include "engine/main/render.h"
#include "engine/main/error.h"
#include "engine/main/controls.h"

#include "engine/main/misc.h"
#include "engine/main/sound.h"
#include "engine/main/tilemaps.h"
#include "engine/main/sprites.h"


//game
#include "engine/game/npc.h"
#include "engine/game/npcfuncs.h"
#include "engine/game/npcrand.h"
#include "engine/game/npccar.h"

#include "engine/game/caption.h"

#include "engine/game/player.h"
#include "engine/game/map.h"

#include "engine/game/txt.h"
#include "engine/game/txtkeyboard.h"
#include "engine/game/txtanswer.h"

#include "engine/game/letterbox.h"
#include "engine/game/action.h"
#include "engine/game/clock.h"
#include "engine/game/save.h"
#include "engine/game/music.h"
#include "engine/game/item.h"
#include "engine/game/start.h"



//gamelogic
#include "gamelogic/changemap.h"




//intro
#include "gamelogic/intro/introtown.h"
#include "gamelogic/intro/introyuushouse.h"

//town
#include "gamelogic/town/town.h"

#include "gamelogic/town/yuushouse.h"

#include "gamelogic/town/arcade.h"
#include "gamelogic/town/beautysalon.h"
#include "gamelogic/town/bookstore.h"
#include "gamelogic/town/church.h"
#include "gamelogic/town/clubhouse.h"
#include "gamelogic/town/coffeeshop.h"
#include "gamelogic/town/crazyladyhouse.h"
#include "gamelogic/town/departmentstore.h"
#include "gamelogic/town/doctorsoffice.h"
#include "gamelogic/town/electronicsstore.h"
#include "gamelogic/town/friendshouse.h"
#include "gamelogic/town/gamestore.h"
#include "gamelogic/town/gasstation.h"
#include "gamelogic/town/generichouses.h"
#include "gamelogic/town/grocerystore.h"
#include "gamelogic/town/mansion.h"
#include "gamelogic/town/movietheater.h"
#include "gamelogic/town/petstore.h"
#include "gamelogic/town/pizzaplace.h"
#include "gamelogic/town/playground.h"
#include "gamelogic/town/recordstore.h"
#include "gamelogic/town/school.h"
#include "gamelogic/town/tacoburger.h"
#include "gamelogic/town/town.h"
#include "gamelogic/town/videostore.h"
#include "gamelogic/town/toolshed.h"

//city
#include "gamelogic/city/city.h"

#include "gamelogic/city/apartment.h"

#include "gamelogic/city/bank.h"
#include "gamelogic/city/casino.h"
#include "gamelogic/city/cityhall.h"
#include "gamelogic/city/deli.h"
#include "gamelogic/city/elevatedlifeplace.h"
#include "gamelogic/city/fashionstore.h"
#include "gamelogic/city/firestation.h"
#include "gamelogic/city/groovyclub.h"
#include "gamelogic/city/hospital.h"
#include "gamelogic/city/hotel.h"
#include "gamelogic/city/hourlymotel.h"
#include "gamelogic/city/laundromat.h"
#include "gamelogic/city/museum.h"
#include "gamelogic/city/office.h"
#include "gamelogic/city/partystore.h"
#include "gamelogic/city/pawnshop.h"
#include "gamelogic/city/policestation.h"
#include "gamelogic/city/poolhall.h"
#include "gamelogic/city/restaurant.h"
#include "gamelogic/city/stadium.h"
#include "gamelogic/city/thecafe.h"

#include "gamelogic/other/japanhouse.h"
#include "gamelogic/other/castroom.h"
#include "gamelogic/other/meetingroom.h"



//minigames

#include "gamelogic/title/titlescreen.h"
#include "gamelogic/title/warning.h"
#include "gamelogic/title/license.h"
#include "gamelogic/title/demoend.h"

#include "gamelogic/other/minigame.h"

#include "minigame/tetrid.h"
#include "minigame/ping.h"
#include "minigame/ramio.h"

//#include "minigame/beats.h"
//#include "minigame/blobs.h"

//==============================================================================
#endif
//==============================================================================
