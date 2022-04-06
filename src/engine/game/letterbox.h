//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================
#ifndef LETTERBOX_H
#define LETTERBOX_H
//==============================================================================


//================
//defines
//================



//================
//variables
//================

extern SPRITE* LETTERBOX_sprite[4];

extern int LETTERBOX_size;
extern int LETTERBOX_top_y;
extern int LETTERBOX_bottom_y;

extern bool LETTERBOX_on;
extern bool LETTERBOX_sprites_exist;

//================
//prototypes
//================


void LETTERBOX_deinit();
void LETTERBOX_init(int size, bool transparent);

void LETTERBOX_vbl();





//==============================================================================
#endif
//==============================================================================
