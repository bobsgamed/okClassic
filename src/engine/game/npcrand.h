//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================
#ifndef NPCRAND_H
#define NPCRAND_H
//==============================================================================


//================
//defines
//================



//================
//variables
//================


//extern int CROWDSIZE=30;


//================
//prototypes
//================


void NPC_create_random_npc_xy_feet(NPC**NPC_pp,GFX*gfx_struct,int size_x,int size_y,int x,int y);
void NPC_create_random_CHILD_xy_feet(NPC**NPC_pp,int x,int y);
void NPC_create_random_ADULT_xy_feet(NPC**NPC_pp,int x,int y);
void NPC_random_crowd_left_right_xyxy(int x,int y, int x2, int y2, int amount);
void NPC_create_random_LITTLE_CHILD_xy_feet(NPC**NPC_pp,int x,int y);
void NPC_create_random_MAN_xy_feet(NPC**NPC_pp,int x,int y);
void NPC_create_random_WOMAN_xy_feet(NPC**NPC_pp,int x,int y);
void NPC_create_random_ADULT_OR_CHILD_xy_feet(NPC**NPC_pp,int x,int y);
void NPC_fade_out_random_crowd();

//==============================================================================
#endif
//==============================================================================
