//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================




#include "../../main.h"


#define RANGE_CITYPoolHallToOUTSIDECity 29*8,62*8,37*8,63*8



//========================================================
//CITYPoolHall
//========================================================
void bobsgame_CITYPoolHall_Map_Load_Function()
{
//RANGE_CITYPoolHallToOUTSIDECity 29*8,62*8,37*8,63*8
}
void bobsgame_CITYPoolHall_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//guy
//7,18 face left
	static NPC* poolattendant_npc = NULL;
	if(poolattendant_npc==NULL)
	{
		NPC_create_npc_xy_feet(&poolattendant_npc,GFX_ADULT_GENERICbeardbaldingtshirt,16,40,8*8,17*8);
		poolattendant_npc->layer=2;
		poolattendant_npc->non_walkable=1;
		NPC_animate_stand_dir(&poolattendant_npc,LEFT);
	}
	if(poolattendant_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&poolattendant_npc,50))NPC_stare_at_npc(&poolattendant_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&poolattendant_npc, LEFT);
		//TODO: ANIMATE
		if(ACTION_range_xy_xy(10*8,15*8,11*8,20*8,"Talk To Attendant"))
		{
			TEXT_set_sprite_window(0,poolattendant_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
//TODO: 23-28 10 jukebox

//TODO: have pool player
//TODO: have ball animated?
//10,34 down
//7,39 right
//10,42 up
//13,38 left
//guy at 9.31 down
//guy at 15,39 left
	static NPC* poolplayer1_npc = NULL;
	static NPC* poolplayer2_npc = NULL;
	if(poolplayer1_npc==NULL)
	{
		//NPC_create_random_ADULT_xy_feet(&poolplayer1_npc,51*8,26*8);
		NPC_create_npc_xy_feet(&poolplayer1_npc,GFX_ADULT_biker,16,40,9*8,31*8);
		poolplayer1_npc->layer=2;
		poolplayer1_npc->non_walkable=1;
		NPC_animate_stand_dir(&poolplayer1_npc,DOWN);
		poolplayer1_npc->walking_speed = SPEED_SLOWEST+r(SPEED_SLOWEST-SPEED_FASTEST);
		poolplayer1_npc->AI=0;
	}
	if(poolplayer1_npc!=NULL)
	{
		if(poolplayer1_npc->AI== 0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer1_npc,poolplayer1_npc->walking_speed, 10*8,34*8)==1){poolplayer1_npc->AI=4;poolplayer1_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer1_npc,DOWN);}
		if(poolplayer1_npc->AI== 1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer1_npc,poolplayer1_npc->walking_speed,  7*8,39*8)==1){poolplayer1_npc->AI=4;poolplayer1_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer1_npc,RIGHT);}
		if(poolplayer1_npc->AI== 2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer1_npc,poolplayer1_npc->walking_speed, 10*8,42*8)==1){poolplayer1_npc->AI=4;poolplayer1_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer1_npc,UP);}
		if(poolplayer1_npc->AI== 3)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer1_npc,poolplayer1_npc->walking_speed, 14*8,38*8)==1){poolplayer1_npc->AI=4;poolplayer1_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer1_npc,LEFT);}
		if(poolplayer1_npc->AI== 4)if(poolplayer1_npc->vbls>150){poolplayer1_npc->vbls=0;poolplayer1_npc->AI=5;}//TODO: ball animation and crack sound
		if(poolplayer1_npc->AI== 5)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer1_npc,poolplayer1_npc->walking_speed,  9*8,31*8)==1){poolplayer1_npc->AI=6;poolplayer1_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer1_npc,DOWN);}
		if(poolplayer1_npc->AI== 6){poolplayer1_npc->vbls=0;poolplayer2_npc->AI=r(4);poolplayer1_npc->AI=7;}
	}

	if(poolplayer2_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&poolplayer2_npc,biker,16,40,9*8,31*8);
		NPC_create_random_ADULT_xy_feet(&poolplayer2_npc,17*8,39*8);
		poolplayer2_npc->layer=2;
		poolplayer2_npc->non_walkable=1;
		NPC_animate_stand_dir(&poolplayer2_npc,LEFT);
		poolplayer2_npc->walking_speed = SPEED_SLOWEST+r(SPEED_SLOWEST-SPEED_FASTEST);
		poolplayer2_npc->AI=0;
	}
	if(poolplayer2_npc!=NULL)
	{
		if(poolplayer2_npc->AI== 0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer2_npc,poolplayer2_npc->walking_speed, 10*8,34*8)==1){poolplayer2_npc->AI=4;poolplayer2_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer2_npc,DOWN);}
		if(poolplayer2_npc->AI== 1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer2_npc,poolplayer2_npc->walking_speed,  7*8,39*8)==1){poolplayer2_npc->AI=4;poolplayer2_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer2_npc,RIGHT);}
		if(poolplayer2_npc->AI== 2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer2_npc,poolplayer2_npc->walking_speed, 10*8,42*8)==1){poolplayer2_npc->AI=4;poolplayer2_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer2_npc,UP);}
		if(poolplayer2_npc->AI== 3)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer2_npc,poolplayer2_npc->walking_speed, 14*8,38*8)==1){poolplayer2_npc->AI=4;poolplayer2_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer2_npc,LEFT);}
		if(poolplayer2_npc->AI== 4)if(poolplayer2_npc->vbls>150){poolplayer2_npc->vbls=0;poolplayer2_npc->AI=5;}//TODO: ball animation and crack sound
		if(poolplayer2_npc->AI== 5)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer2_npc,poolplayer2_npc->walking_speed, 17*8,39*8)==1){poolplayer2_npc->AI=6;poolplayer2_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer2_npc,LEFT);}
		if(poolplayer2_npc->AI== 6){poolplayer2_npc->vbls=0;poolplayer1_npc->AI=r(4);poolplayer2_npc->AI=7;}
	}
//20,48 down
//17,54 right
//21,56 up
//23,52 left
//guy at 14,52 right
//guy at 20,44 down
	static NPC* poolplayer3_npc = NULL;
	static NPC* poolplayer4_npc = NULL;
	if(poolplayer3_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&poolplayer3_npc,biker,16,40,14*8,52*8);
		NPC_create_random_ADULT_xy_feet(&poolplayer3_npc,14*8,52*8);
		poolplayer3_npc->layer=2;
		poolplayer3_npc->non_walkable=1;
		NPC_animate_stand_dir(&poolplayer3_npc,RIGHT);
		poolplayer3_npc->walking_speed = SPEED_SLOWEST+r(SPEED_SLOWEST-SPEED_FASTEST);
		poolplayer3_npc->AI=0;
	}
	if(poolplayer3_npc!=NULL)
	{
		if(poolplayer3_npc->AI== 0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer3_npc,poolplayer3_npc->walking_speed, 20*8,48*8)==1){poolplayer3_npc->AI=4;poolplayer3_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer3_npc,DOWN);}
		if(poolplayer3_npc->AI== 1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer3_npc,poolplayer3_npc->walking_speed, 17*8,54*8)==1){poolplayer3_npc->AI=4;poolplayer3_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer3_npc,RIGHT);}
		if(poolplayer3_npc->AI== 2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer3_npc,poolplayer3_npc->walking_speed, 21*8,56*8)==1){poolplayer3_npc->AI=4;poolplayer3_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer3_npc,UP);}
		if(poolplayer3_npc->AI== 3)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer3_npc,poolplayer3_npc->walking_speed, 24*8,52*8)==1){poolplayer3_npc->AI=4;poolplayer3_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer3_npc,LEFT);}
		if(poolplayer3_npc->AI== 4)if(poolplayer3_npc->vbls>150){poolplayer3_npc->vbls=0;poolplayer3_npc->AI=5;}//TODO: ball animation and crack sound
		if(poolplayer3_npc->AI== 5)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer3_npc,poolplayer3_npc->walking_speed,  14*8,52*8)==1){poolplayer3_npc->AI=6;poolplayer3_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer3_npc,RIGHT);}
		if(poolplayer3_npc->AI== 6){poolplayer3_npc->vbls=0;poolplayer4_npc->AI=r(4);poolplayer3_npc->AI=7;}
	}

	if(poolplayer4_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&poolplayer4_npc,biker,16,40,9*8,31*8);
		NPC_create_random_ADULT_xy_feet(&poolplayer4_npc,20*8,44*8);
		poolplayer4_npc->layer=2;
		poolplayer4_npc->non_walkable=1;
		NPC_animate_stand_dir(&poolplayer4_npc,DOWN);
		poolplayer4_npc->walking_speed = SPEED_SLOWEST+r(SPEED_SLOWEST-SPEED_FASTEST);
		poolplayer4_npc->AI=0;
	}
	if(poolplayer4_npc!=NULL)
	{
		if(poolplayer4_npc->AI== 0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer4_npc,poolplayer4_npc->walking_speed, 20*8,48*8)==1){poolplayer4_npc->AI=4;poolplayer4_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer4_npc,DOWN);}
		if(poolplayer4_npc->AI== 1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer4_npc,poolplayer4_npc->walking_speed, 17*8,54*8)==1){poolplayer4_npc->AI=4;poolplayer4_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer4_npc,RIGHT);}
		if(poolplayer4_npc->AI== 2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer4_npc,poolplayer4_npc->walking_speed, 21*8,56*8)==1){poolplayer4_npc->AI=4;poolplayer4_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer4_npc,UP);}
		if(poolplayer4_npc->AI== 3)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer4_npc,poolplayer4_npc->walking_speed, 24*8,52*8)==1){poolplayer4_npc->AI=4;poolplayer4_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer4_npc,LEFT);}

		if(poolplayer4_npc->AI== 4)if(poolplayer4_npc->vbls>150){poolplayer4_npc->vbls=0;poolplayer4_npc->AI=5;}//TODO: ball animation and crack sound
		if(poolplayer4_npc->AI== 5)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer4_npc,poolplayer4_npc->walking_speed, 20*8,44*8)==1){poolplayer4_npc->AI=6;poolplayer4_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer4_npc,DOWN);}
		if(poolplayer4_npc->AI== 6){poolplayer4_npc->vbls=0;poolplayer3_npc->AI=r(4);poolplayer4_npc->AI=7;}
	}
//30,34 down
//27,40 right
//30,42 up
//33,39 left
//guy stands at 25,39 right
//other guy 30,31 down
	static NPC* poolplayer5_npc = NULL;
	static NPC* poolplayer6_npc = NULL;
	if(poolplayer5_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&poolplayer5_npc,biker,16,40,14*8,52*8);
		NPC_create_random_ADULT_xy_feet(&poolplayer5_npc,24*8,39*8);
		poolplayer5_npc->layer=2;
		poolplayer5_npc->non_walkable=1;
		NPC_animate_stand_dir(&poolplayer5_npc,RIGHT);
		poolplayer5_npc->walking_speed = SPEED_SLOWEST+r(SPEED_SLOWEST-SPEED_FASTEST);
		poolplayer5_npc->AI=0;
	}
	if(poolplayer5_npc!=NULL)
	{
		if(poolplayer5_npc->AI== 0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer5_npc,poolplayer5_npc->walking_speed, 30*8,34*8)==1){poolplayer5_npc->AI=4;poolplayer5_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer5_npc,DOWN);}
		if(poolplayer5_npc->AI== 1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer5_npc,poolplayer5_npc->walking_speed, 27*8,40*8)==1){poolplayer5_npc->AI=4;poolplayer5_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer5_npc,RIGHT);}
		if(poolplayer5_npc->AI== 2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer5_npc,poolplayer5_npc->walking_speed, 30*8,42*8)==1){poolplayer5_npc->AI=4;poolplayer5_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer5_npc,UP);}
		if(poolplayer5_npc->AI== 3)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer5_npc,poolplayer5_npc->walking_speed, 34*8,39*8)==1){poolplayer5_npc->AI=4;poolplayer5_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer5_npc,LEFT);}
		if(poolplayer5_npc->AI== 4)if(poolplayer5_npc->vbls>150){poolplayer5_npc->vbls=0;poolplayer5_npc->AI=5;}//TODO: ball animation and crack sound
		if(poolplayer5_npc->AI== 5)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer5_npc,poolplayer5_npc->walking_speed,  24*8,39*8)==1){poolplayer5_npc->AI=6;poolplayer5_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer5_npc,RIGHT);}
		if(poolplayer5_npc->AI== 6){poolplayer5_npc->vbls=0;poolplayer6_npc->AI=r(4);poolplayer5_npc->AI=7;}
	}

	if(poolplayer6_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&poolplayer6_npc,biker,16,40,9*8,31*8);
		NPC_create_random_ADULT_xy_feet(&poolplayer6_npc,30*8,31*8);
		poolplayer6_npc->layer=2;
		poolplayer6_npc->non_walkable=1;
		NPC_animate_stand_dir(&poolplayer6_npc,DOWN);
		poolplayer6_npc->walking_speed = SPEED_SLOWEST+r(SPEED_SLOWEST-SPEED_FASTEST);
		poolplayer6_npc->AI=0;
	}
	if(poolplayer6_npc!=NULL)
	{
		if(poolplayer6_npc->AI== 0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer6_npc,poolplayer6_npc->walking_speed, 30*8,34*8)==1){poolplayer6_npc->AI=4;poolplayer6_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer6_npc,DOWN);}
		if(poolplayer6_npc->AI== 1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer6_npc,poolplayer6_npc->walking_speed, 27*8,40*8)==1){poolplayer6_npc->AI=4;poolplayer6_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer6_npc,RIGHT);}
		if(poolplayer6_npc->AI== 2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer6_npc,poolplayer6_npc->walking_speed, 30*8,42*8)==1){poolplayer6_npc->AI=4;poolplayer6_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer6_npc,UP);}
		if(poolplayer6_npc->AI== 3)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer6_npc,poolplayer6_npc->walking_speed, 34*8,39*8)==1){poolplayer6_npc->AI=4;poolplayer6_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer6_npc,LEFT);}

		if(poolplayer6_npc->AI== 4)if(poolplayer6_npc->vbls>150){poolplayer6_npc->vbls=0;poolplayer6_npc->AI=5;}//TODO: ball animation and crack sound
		if(poolplayer6_npc->AI== 5)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&poolplayer6_npc,poolplayer6_npc->walking_speed, 30*8,31*8)==1){poolplayer6_npc->AI=6;poolplayer6_npc->vbls=r(60);NPC_animate_stand_dir(&poolplayer6_npc,DOWN);}
		if(poolplayer6_npc->AI== 6){poolplayer6_npc->vbls=0;poolplayer5_npc->AI=r(4);poolplayer6_npc->AI=7;}
	}

	if(walking_into_door(RANGE_CITYPoolHallToOUTSIDECity))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,393,39);return;
	}
}
void bobsgame_CITYPoolHall_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYPoolHall_Map_VBL_Function()
{

}
void bobsgame_CITYPoolHall_Map_HBL_Function()
{

}


