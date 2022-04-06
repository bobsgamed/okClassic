//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================


#include "../../main.h"



#define RANGE_CITYDeliToOUTSIDECity 19*8,42*8,27*8,43*8


//========================================================
//CITYDeli
//========================================================
void bobsgame_CITYDeli_Map_Load_Function()
{
//RANGE_CITYDeliToOUTSIDECity 19*8,42*8,27*8,43*8
}
void bobsgame_CITYDeli_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//patrons
//12 13 up bread
	static NPC* delipatron1_npc = NULL;
	if(delipatron1_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&delipatron1_npc,GENERICmanlongsleeves,16,40,33*8,39*8);
		NPC_create_random_ADULT_xy_feet(&delipatron1_npc,12*8,13*8);
		delipatron1_npc->layer=2;
		delipatron1_npc->non_walkable=1;
		NPC_animate_stand_dir(&delipatron1_npc,UP);
		delipatron1_npc->walking_speed = SPEED_SLOWEST+r(SPEED_SLOWEST-SPEED_FASTEST);
		delipatron1_npc->AI=0;
	}
	if(delipatron1_npc!=NULL)
	{
		if(delipatron1_npc->AI== 0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&delipatron1_npc,delipatron1_npc->walking_speed,  9*8,13*8)==1){delipatron1_npc->AI=4;delipatron1_npc->vbls=r(60);NPC_animate_stand_dir(&delipatron1_npc,UP);}
		if(delipatron1_npc->AI== 1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&delipatron1_npc,delipatron1_npc->walking_speed, 12*8,13*8)==1){delipatron1_npc->AI=4;delipatron1_npc->vbls=r(60);NPC_animate_stand_dir(&delipatron1_npc,UP);}
		if(delipatron1_npc->AI== 2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&delipatron1_npc,delipatron1_npc->walking_speed,  5*8,13*8)==1){delipatron1_npc->AI=4;delipatron1_npc->vbls=r(60);NPC_animate_stand_dir(&delipatron1_npc,UP);}
		if(delipatron1_npc->AI== 3)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&delipatron1_npc,delipatron1_npc->walking_speed, 16*8,13*8)==1){delipatron1_npc->AI=4;delipatron1_npc->vbls=r(60);NPC_animate_stand_dir(&delipatron1_npc,LEFT);}
		if(delipatron1_npc->AI== 4)if(delipatron1_npc->vbls>120){delipatron1_npc->vbls=0;delipatron1_npc->AI=r(4);}
	}
//21 13 up cooler
//25
//26 20 right
	static NPC* delipatron2_npc = NULL;
	if(delipatron2_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&delipatron2_npc,GENERICmanlongsleeves,16,40,33*8,39*8);
		NPC_create_random_ADULT_xy_feet(&delipatron2_npc,21*8,13*8);
		delipatron2_npc->layer=2;
		delipatron2_npc->non_walkable=1;
		NPC_animate_stand_dir(&delipatron2_npc,UP);
		delipatron2_npc->walking_speed = SPEED_SLOWEST+r(SPEED_SLOWEST-SPEED_FASTEST);
		delipatron2_npc->AI=0;
	}
	if(delipatron2_npc!=NULL)
	{
		if(delipatron2_npc->AI== 0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&delipatron2_npc,delipatron2_npc->walking_speed, 25*8,13*8)==1){delipatron2_npc->AI=4;delipatron2_npc->vbls=r(60);NPC_animate_stand_dir(&delipatron2_npc,UP);}
		if(delipatron2_npc->AI== 1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&delipatron2_npc,delipatron2_npc->walking_speed, 21*8,13*8)==1){delipatron2_npc->AI=4;delipatron2_npc->vbls=r(60);NPC_animate_stand_dir(&delipatron2_npc,UP);}
		if(delipatron2_npc->AI== 2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&delipatron2_npc,delipatron2_npc->walking_speed, 26*8,20*8)==1){delipatron2_npc->AI=4;delipatron2_npc->vbls=r(60);NPC_animate_stand_dir(&delipatron2_npc,RIGHT);}
		if(delipatron2_npc->AI== 3)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&delipatron2_npc,delipatron2_npc->walking_speed, 26*8,16*8)==1){delipatron2_npc->AI=4;delipatron2_npc->vbls=r(60);NPC_animate_stand_dir(&delipatron2_npc,RIGHT);}
		if(delipatron2_npc->AI== 4)if(delipatron2_npc->vbls>120){delipatron2_npc->vbls=0;delipatron2_npc->AI=r(4);}
	}
//23,22 left candy
//23,26
//23,30
//26,27 right
	static NPC* delipatron3_npc = NULL;
	if(delipatron3_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&delipatron3_npc,GENERICmanlongsleeves,16,40,33*8,39*8);
		NPC_create_random_ADULT_xy_feet(&delipatron3_npc,23*8,26*8);
		delipatron3_npc->layer=2;
		delipatron3_npc->non_walkable=1;
		NPC_animate_stand_dir(&delipatron3_npc,LEFT);
		delipatron3_npc->walking_speed = SPEED_SLOWEST+r(SPEED_SLOWEST-SPEED_FASTEST);
		delipatron3_npc->AI=0;
	}
	if(delipatron3_npc!=NULL)
	{
		if(delipatron3_npc->AI== 0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&delipatron3_npc,delipatron3_npc->walking_speed, 24*8,22*8)==1){delipatron3_npc->AI=4;delipatron3_npc->vbls=r(60);NPC_animate_stand_dir(&delipatron3_npc,LEFT);}
		if(delipatron3_npc->AI== 1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&delipatron3_npc,delipatron3_npc->walking_speed, 24*8,26*8)==1){delipatron3_npc->AI=4;delipatron3_npc->vbls=r(60);NPC_animate_stand_dir(&delipatron3_npc,LEFT);}
		if(delipatron3_npc->AI== 2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&delipatron3_npc,delipatron3_npc->walking_speed, 24*8,30*8)==1){delipatron3_npc->AI=4;delipatron3_npc->vbls=r(60);NPC_animate_stand_dir(&delipatron3_npc,LEFT);}
		if(delipatron3_npc->AI== 3)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&delipatron3_npc,delipatron3_npc->walking_speed, 26*8,27*8)==1){delipatron3_npc->AI=4;delipatron3_npc->vbls=r(60);NPC_animate_stand_dir(&delipatron3_npc,RIGHT);}
		if(delipatron3_npc->AI== 4)if(delipatron3_npc->vbls>120){delipatron3_npc->vbls=0;delipatron3_npc->AI=r(4);}
	}

//clerks
//12 34 right  clerk
//16,30-36
//12,23 right  clerk
//16,20-26
//go between these unless you walk to the counter, then he walks to the counter
//4 34 left sink
//7,40 down
//6 29 left fridge
//7,26 up chopping
	static NPC* deliclerk_npc = NULL;
	if(deliclerk_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&deliclerk_npc,GENERICmanlongsleeves,16,40,33*8,39*8);
		NPC_create_random_ADULT_xy_feet(&deliclerk_npc,11*8,34*8);
		deliclerk_npc->layer=2;
		deliclerk_npc->non_walkable=1;
		NPC_animate_stand_dir(&deliclerk_npc,RIGHT);
		deliclerk_npc->walking_speed = SPEED_NORMAL;
		deliclerk_npc->AI=0;
	}
	if(deliclerk_npc!=NULL)
	{
		if(NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,14*8,30*8,16*8,36*8,PLAYER_npc->anim_dir,0))
		{
			if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&deliclerk_npc,deliclerk_npc->walking_speed, 12*8,33*8)==1)NPC_animate_stand_dir(&deliclerk_npc,RIGHT);
		}
		else
		if(NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,14*8,20*8,16*8,26*8,PLAYER_npc->anim_dir,0))
		{
			if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&deliclerk_npc,deliclerk_npc->walking_speed, 12*8,24*8)==1)NPC_animate_stand_dir(&deliclerk_npc,RIGHT);
		}
		else if(deliclerk_npc->AI== 0){if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&deliclerk_npc,deliclerk_npc->walking_speed, 5*8,34*8)==1){deliclerk_npc->AI=4;deliclerk_npc->vbls=r(60);NPC_animate_stand_dir(&deliclerk_npc,LEFT);}}
		else if(deliclerk_npc->AI== 1){if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&deliclerk_npc,deliclerk_npc->walking_speed, 7*8,40*8)==1){deliclerk_npc->AI=4;deliclerk_npc->vbls=r(60);NPC_animate_stand_dir(&deliclerk_npc,DOWN);}}
		else if(deliclerk_npc->AI== 2){if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&deliclerk_npc,deliclerk_npc->walking_speed, 6*8,29*8)==1){deliclerk_npc->AI=4;deliclerk_npc->vbls=r(60);NPC_animate_stand_dir(&deliclerk_npc,LEFT);}}
		else if(deliclerk_npc->AI== 3){if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&deliclerk_npc,deliclerk_npc->walking_speed, 7*8,26*8)==1){deliclerk_npc->AI=4;deliclerk_npc->vbls=r(60);NPC_animate_stand_dir(&deliclerk_npc,UP);}}
		else if(deliclerk_npc->AI== 4){if(deliclerk_npc->vbls>120){deliclerk_npc->vbls=0;deliclerk_npc->AI=r(4);}}
		if(ACTION_range_xy_xy(14*8,20*8,15*8,36*8,"Talk To Sandwich Technician"))
		{
			TEXT_set_sprite_window(0,deliclerk_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	if(walking_into_door(RANGE_CITYDeliToOUTSIDECity))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,559,39);return;
	}
}
void bobsgame_CITYDeli_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYDeli_Map_VBL_Function()
{

}
void bobsgame_CITYDeli_Map_HBL_Function()
{

}

