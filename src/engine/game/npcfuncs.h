//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================
#ifndef NPCFUNCS_H
#define NPCFUNCS_H
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


void NPC_fade_out_and_delete(NPC** npcpp);

bool NPC_walk_to_xy_stop_for_other_npcs_amt(NPC** npcpp,int speed,int x,int y,int amt);

void NPC_stop_following(NPC** npcpp);
void NPC_stop_pulling_against(NPC** npcpp);
void NPC_stop_chasing(NPC** npcpp);
void NPC_stop_avoiding(NPC** npcpp);
void NPC_pushable_avoid_other_npcs();
void NPC_stand(NPC** npcpp);

bool NPC_chase_npc(NPC** chaser_npcpp, NPC** chase_npcpp);
void NPC_move_pixel(NPC** npcpp, int dir);
bool NPC_check_hit_move_pixel(NPC** npcpp, int dir);
bool NPC_walk_to_xy_basichit(NPC** npcpp, int speed, int x, int y); //RETURNS 1 IF NPC IS AT COORDS, HAS HIT DETECTION WITH MAIN SPRITE, CAN USE NPC_IGNORE_SPRITE
bool NPC_walk_to_xy_nohit(NPC** npcpp, int speed, int x, int y);
bool NPC_walk_to_xy_nohit_avoidothers_pushmain(NPC** npcpp,int speed,int x,int y);
bool NPC_walk_to_xy_intelligenthit_avoidothers(NPC** npcpp,int speed,int x,int y);
bool NPC_walk_to_xy_nohit_pushmain(NPC** npcpp,int speed,int x,int y);
bool NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(NPC** npcpp,int speed,int x,int y);
bool NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(NPC** npcpp,int speed,int x,int y);
bool NPC_walk_to_xy_intelligenthit_pushothers(NPC** npcpp,int speed,int x,int y);
bool NPC_avoid_nearest_npc(NPC** npcpp, int amt);
void NPC_stare_at_npc(NPC** staring_npcpp, NPC** stared_at_npcpp);
void NPC_stare_at_npc_not_opposite_walking_direction(NPC** staring_npcpp,NPC** stared_at_npcpp);
void NPC_dont_look_at_npc(NPC** staring_npcpp,NPC** stared_at_npcpp);
bool NPC_walk_to_xy_LR_to_UD(NPC** npcpp,int speed,int x,int y);
bool NPC_walk_to_xy_UD_to_LR(NPC** npcpp,int speed,int x,int y);
bool NPC_avoid_npc(NPC** in_npcpp,NPC** avoid_npcpp,int avoid_amt);
void NPC_delete_chase_structs();
void NPC_delete_follow_structs();
void NPC_delete_avoid_structs();
void NPC_delete_pull_againster_structs();
void NPC_walk_randomly_around_room_and_stop(NPC** in_npcpp);
void NPC_walk_direction_avoid_other_npcs(NPC** npcpp ,int NPC_direction);
bool NPC_move_to_xy_nohit_noanim(NPC** npcpp,int speed,int x,int y);
bool NPC_walk_randomly_within_xy_xy(NPC** npcpp,int x1,int y1,int x2,int y2);
void NPC_randomly_twitch_around_room(NPC** npcpp);
NPC *NPC_find_nearest_npc_in_front_of_npc(NPC** npcpp);
void NPC_set_alpha(NPC** npcpp, int alpha);

void NPC_animate_if_needed(NPC** npcpp,int dir);



//==============================================================================
#endif
//==============================================================================
