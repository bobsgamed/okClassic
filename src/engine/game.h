//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================
#ifndef GAME_H
#define GAME_H
//==============================================================================

//================
//defines
//================

#define INTRO 0
#define TOWN 1
#define CITY 2


#define FIRST_SPRITE_ID 0

#define CLEAR 			0
#define BLACK 			1
#define WHITE 			2
#define LIGHTGRAY 	3
#define GRAY 			4
#define DARKGRAY		5
#define LIGHTRED 		6
#define RED				7
#define DARKRED		8
#define LIGHTORANGE	9
#define ORANGE			10
#define DARKORANGE	11
#define LIGHTYELLOW	12
#define YELLOW			13
#define DARKYELLOW	14
#define LIGHTGREEN	15
#define GREEN			16
#define DARKGREEN		17
#define LIGHTBLUE		18
#define BLUE			19
#define DARKBLUE		20
#define LIGHTPURPLE	21
#define PURPLE			22
#define DARKPURPLE	23
#define LIGHTPINK		24
#define PINK 			25
#define DARKPINK		26



//================
//variables
//================

extern int GAMESTATE;

extern int GLOBAL_debug_level_select;

extern bool GAME_paused;
extern bool music_playing;

extern int timer_var;
extern int vbl_var;
extern int vbl_10_var;
extern int vbl_20_var;
extern int vbl_30_var;
extern int vbl_60_var;
extern int vbl_5_var;



extern int DOWN;
extern int UP;
extern int LEFT;
extern int RIGHT;

extern int UPLEFT;
extern int UPRIGHT;

extern int DOWNRIGHT;
extern int DOWNLEFT;



//================
//prototypes
//================



void GAME_main(int gamespeed);
void GAME_init();
void GAME_vbl();






//==============================================================================
#endif
//==============================================================================
