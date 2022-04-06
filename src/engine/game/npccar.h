//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================
#ifndef NPCCAR_H
#define NPCCAR_H
//==============================================================================


//================
//defines
//================



//================
//variables
//================



//================
//prototypes
//================

bool NPC_car_xyxy(NPC** npcpp,int x,int y,int x2,int y2,int speed,int direction,int* hit_direction_x,int* hit_direction_y);
bool NPC_car_clockwise(NPC** npcpp,int speed,int* hit_direction_x,int* hit_direction_y);
bool NPC_car_counterclockwise(NPC** npcpp,int speed,int* hit_direction_x,int* hit_direction_y);
void NPC_create_car_if_within_range_else_delete(NPC** npcpp,int x,int y,int direction);
void NPC_create_bicycle_if_within_range_else_delete(NPC** npcpp,int x,int y,int direction);
void NPC_create_car(NPC** npcpp,int x,int y,int direction);
void NPC_set_car_anim_frame_now(NPC** npcpp,int frame);




//==============================================================================
#endif
//==============================================================================
