//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================


#include "../../main.h"



#define RANGE_CITYFashionStoreToOUTSIDECity 14*8,54*8,22*8,55*8
#define RANGE_CITYFashionStoreToDressingRoom 5*8,9*8,10*8,10*8
#define RANGE_CITYFashionStoreToDressingRoom2 17*8,9*8,22*8,10*8
#define RANGE_CITYFashionStoreDressingRoomToFashionStore 4*8,19*8,9*8,20*8
#define RANGE_CITYFashionStoreDressingRoom2ToFashionStore 4*8,19*8,9*8,20*8




//========================================================
//CITYFashionStore
//========================================================
void bobsgame_CITYFashionStore_Map_Load_Function()
{
//RANGE_CITYFashionStoreToOUTSIDECity 14*8,54*8,22*8,55*8
//RANGE_CITYFashionStoreToDressingRoom 5*8,9*8,10*8,10*8
//RANGE_CITYFashionStoreToDressingRoom2 17*8,9*8,22*8,10*8
}
void bobsgame_CITYFashionStore_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//clerk 9,24 under 3
//talk to 6,27 13,33

	static NPC* clerk_npc = NULL;
	if(clerk_npc==NULL)
	{
		NPC_create_npc_xy_feet(&clerk_npc,GFX_ADULT_GENERICwomanlonghair,16,40,9*8,29*8);
		clerk_npc->layer=3;
		clerk_npc->non_walkable=1;
		NPC_animate_stand_dir(&clerk_npc,DOWN);
	}
	if(clerk_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&clerk_npc,60))NPC_stare_at_npc(&clerk_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&clerk_npc, DOWN);
		if(ACTION_range_xy_xy(6*8,27*8,13*8,31*8,"Talk To Fashion Clerk"))
		{
			TEXT_set_sprite_window(0,clerk_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
//25,20 up
//28, 27 down
//34,24 right
	static NPC* fashion1_npc = NULL;
	if(fashion1_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&fashion1_npc,GENERICmanlongsleeves,16,40,28*8,27*8);
		NPC_create_random_ADULT_xy_feet(&fashion1_npc,28*8,27*8);
		fashion1_npc->layer=2;
		fashion1_npc->non_walkable=1;
		NPC_animate_stand_dir(&fashion1_npc,DOWN);
		fashion1_npc->walking_speed = SPEED_SLOWEST+r(SPEED_SLOWEST-SPEED_FASTEST);
		fashion1_npc->AI=0;
	}
	if(fashion1_npc!=NULL)
	{
		if(fashion1_npc->AI== 0){if(fashion1_npc->MAP_y<18*8)fashion1_npc->layer=1;if(NPC_walk_to_xy_nohit_pushmain(&fashion1_npc,fashion1_npc->walking_speed, 25*8,20*8)==(1)){fashion1_npc->AI=3;fashion1_npc->vbls=0;NPC_animate_stand_dir(&fashion1_npc,UP);}}
		if(fashion1_npc->AI== 1){if(fashion1_npc->MAP_y>20*8)fashion1_npc->layer=3;if(NPC_walk_to_xy_nohit_pushmain(&fashion1_npc,fashion1_npc->walking_speed, 28*8,26*8)==(1)){fashion1_npc->AI=3;fashion1_npc->vbls=0;NPC_animate_stand_dir(&fashion1_npc,DOWN);}}
		if(fashion1_npc->AI== 2){if(fashion1_npc->MAP_x>32*8)fashion1_npc->layer=3;if(NPC_walk_to_xy_nohit_pushmain(&fashion1_npc,fashion1_npc->walking_speed, 34*8,24*8)==(1)){fashion1_npc->AI=3;fashion1_npc->vbls=0;NPC_animate_stand_dir(&fashion1_npc,RIGHT);}}
		if(fashion1_npc->AI== 3)if(fashion1_npc->vbls>120){fashion1_npc->vbls=0;fashion1_npc->AI=r(3);}
	}
//14,21 left
//14,27 left
//12,16 down
//9,16 down

	static NPC* fashion2_npc = NULL;
	if(fashion2_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&fashion2_npc,GENERICmanlongsleeves,16,40,14*8,27*8);
		NPC_create_random_ADULT_xy_feet(&fashion2_npc,15*8,27*8);
		fashion2_npc->layer=2;
		fashion2_npc->non_walkable=1;
		NPC_animate_stand_dir(&fashion2_npc,DOWN);
		fashion2_npc->walking_speed = SPEED_SLOWEST+r(SPEED_SLOWEST-SPEED_FASTEST);
		fashion2_npc->AI=0;
	}
	if(fashion2_npc!=NULL)
	{
		if(fashion2_npc->AI== 0)if(NPC_walk_to_xy_nohit_pushmain(&fashion2_npc,fashion2_npc->walking_speed, 15*8,22*8)==(1)){fashion2_npc->AI=4;fashion2_npc->vbls=0;NPC_animate_stand_dir(&fashion2_npc,LEFT);}
		if(fashion2_npc->AI== 1)if(NPC_walk_to_xy_nohit_pushmain(&fashion2_npc,fashion2_npc->walking_speed, 15*8,26*8)==(1)){fashion2_npc->AI=4;fashion2_npc->vbls=0;NPC_animate_stand_dir(&fashion2_npc,LEFT);}
		if(fashion2_npc->AI== 2)if(NPC_walk_to_xy_nohit_pushmain(&fashion2_npc,fashion2_npc->walking_speed, 15*8,30*8)==(1)){fashion2_npc->AI=4;fashion2_npc->vbls=0;NPC_animate_stand_dir(&fashion2_npc,LEFT);}
		if(fashion2_npc->AI== 3)if(NPC_walk_to_xy_nohit_pushmain(&fashion2_npc,fashion2_npc->walking_speed, 15*8,19*8)==(1)){fashion2_npc->AI=4;fashion2_npc->vbls=0;NPC_animate_stand_dir(&fashion2_npc,LEFT);}
		if(fashion2_npc->AI== 4)if(fashion2_npc->vbls>120){fashion2_npc->vbls=0;fashion2_npc->AI=r(4);}
	}

//6,47 left
//9,44 up

	static NPC* fashion3_npc = NULL;
	if(fashion3_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&fashion3_npc,GENERICmanlongsleeves,16,40,9*8,44*8);
		NPC_create_random_ADULT_xy_feet(&fashion3_npc,9*8,44*8);
		fashion3_npc->layer=2;
		fashion3_npc->non_walkable=1;
		NPC_animate_stand_dir(&fashion3_npc,DOWN);
		fashion3_npc->walking_speed = SPEED_SLOWEST+r(SPEED_SLOWEST-SPEED_FASTEST);
		fashion3_npc->AI=0;
	}
	if(fashion3_npc!=NULL)
	{
		if(fashion3_npc->AI== 0)if(NPC_walk_to_xy_nohit_pushmain(&fashion3_npc,fashion3_npc->walking_speed, 7*8,47*8)==(1)){fashion3_npc->AI=2;fashion3_npc->vbls=0;NPC_animate_stand_dir(&fashion3_npc,LEFT);}
		if(fashion3_npc->AI== 1)if(NPC_walk_to_xy_nohit_pushmain(&fashion3_npc,fashion3_npc->walking_speed, 9*8,44*8)==(1)){fashion3_npc->AI=2;fashion3_npc->vbls=0;NPC_animate_stand_dir(&fashion3_npc,UP);}
		if(fashion3_npc->AI== 2)if(fashion3_npc->vbls>120){fashion3_npc->vbls=0;fashion3_npc->AI=r(2);}
	}
//24,42 down
//33,39 up
//23,37 down
//33,35 down
	static NPC* fashion4_npc = NULL;
	if(fashion4_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&fashion4_npc,GENERICmanlongsleeves,16,40,33*8,39*8);
		NPC_create_random_ADULT_xy_feet(&fashion4_npc,33*8,39*8);
		fashion4_npc->layer=2;
		fashion4_npc->non_walkable=1;
		NPC_animate_stand_dir(&fashion4_npc,DOWN);
		fashion4_npc->walking_speed = SPEED_SLOWEST+r(SPEED_SLOWEST-SPEED_FASTEST);
		fashion4_npc->AI=0;
	}
	if(fashion4_npc!=NULL)
	{
		if(fashion4_npc->AI== 0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&fashion4_npc,fashion4_npc->walking_speed, 24*8,41*8)==1){fashion4_npc->AI=4;fashion4_npc->vbls=0;NPC_animate_stand_dir(&fashion4_npc,DOWN);}
		if(fashion4_npc->AI== 1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&fashion4_npc,fashion4_npc->walking_speed, 33*8,39*8)==1){fashion4_npc->AI=4;fashion4_npc->vbls=0;NPC_animate_stand_dir(&fashion4_npc,UP);}
		if(fashion4_npc->AI== 2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&fashion4_npc,fashion4_npc->walking_speed, 20*8,34*8)==1){fashion4_npc->AI=4;fashion4_npc->vbls=0;NPC_animate_stand_dir(&fashion4_npc,DOWN);}
		if(fashion4_npc->AI== 3)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&fashion4_npc,fashion4_npc->walking_speed, 33*8,34*8)==1){fashion4_npc->AI=4;fashion4_npc->vbls=0;NPC_animate_stand_dir(&fashion4_npc,DOWN);}
		if(fashion4_npc->AI== 4)if(fashion4_npc->vbls>120){fashion4_npc->vbls=0;fashion4_npc->AI=r(4);}
	}
//13,11 up
//24,11 up
//21,11 up
//28,17 down

	static NPC* fashion5_npc = NULL;
	if(fashion5_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&fashion5_npc,GENERICmanlongsleeves,16,40,19*8,24*8);
		NPC_create_random_ADULT_xy_feet(&fashion5_npc,24*8,12*8+4);
		fashion5_npc->layer=2;
		fashion5_npc->non_walkable=1;
		NPC_animate_stand_dir(&fashion5_npc,DOWN);
		fashion5_npc->walking_speed = SPEED_SLOW;
		fashion5_npc->AI=0;
	}
	if(fashion5_npc!=NULL)
	{
		if(fashion5_npc->AI== 0){if(fashion5_npc->MAP_y<11*8)fashion5_npc->layer=2;if(NPC_walk_to_xy_nohit_pushmain(&fashion5_npc,fashion5_npc->walking_speed, 13*8,12*8+4)){fashion5_npc->AI=5;fashion5_npc->vbls=0;NPC_animate_stand_dir(&fashion5_npc,UP);}}
		if(fashion5_npc->AI== 1){if(fashion5_npc->MAP_y<11*8)fashion5_npc->layer=2;if(NPC_walk_to_xy_nohit_pushmain(&fashion5_npc,fashion5_npc->walking_speed, 24*8,12*8+4)){fashion5_npc->AI=5;fashion5_npc->vbls=0;NPC_animate_stand_dir(&fashion5_npc,UP);}}
		if(fashion5_npc->AI== 2){if(fashion5_npc->MAP_y<11*8)fashion5_npc->layer=2;if(NPC_walk_to_xy_nohit_pushmain(&fashion5_npc,fashion5_npc->walking_speed, 32*8,12*8+4)){fashion5_npc->AI=5;fashion5_npc->vbls=0;NPC_animate_stand_dir(&fashion5_npc,UP);}}
		if(fashion5_npc->AI== 3){if(fashion5_npc->MAP_y>11*8)fashion5_npc->layer=3;if(NPC_walk_to_xy_nohit_pushmain(&fashion5_npc,fashion5_npc->walking_speed, 22*8,17*8)==(1)){fashion5_npc->AI=5;fashion5_npc->vbls=0;NPC_animate_stand_dir(&fashion5_npc,DOWN);}}
		if(fashion5_npc->AI== 4){if(fashion5_npc->MAP_y>11*8)fashion5_npc->layer=3;if(NPC_walk_to_xy_nohit_pushmain(&fashion5_npc,fashion5_npc->walking_speed, 28*8,17*8)==(1)){fashion5_npc->AI=5;fashion5_npc->vbls=0;NPC_animate_stand_dir(&fashion5_npc,DOWN);}}
		if(fashion5_npc->AI== 5)if(fashion5_npc->vbls>60){fashion5_npc->vbls=0;fashion5_npc->AI=r(5);}
	}

	if(walking_into_door(RANGE_CITYFashionStoreToOUTSIDECity))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,1562,38);return;
	}
	if(walking_into_door(RANGE_CITYFashionStoreToDressingRoom))
	{
		MAP_change_map(MAP_bobsgame_CITYFashionStoreDressingRoom,5,18);return;
	}
	if(walking_into_door(RANGE_CITYFashionStoreToDressingRoom2))
	{
		MAP_change_map(MAP_bobsgame_CITYFashionStoreDressingRoom2,5,18);return;
	}
}
void bobsgame_CITYFashionStore_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYFashionStore_Map_VBL_Function()
{

}
void bobsgame_CITYFashionStore_Map_HBL_Function()
{

}
//========================================================
//CITYFashionStoreDressingRoom
//========================================================
void bobsgame_CITYFashionStoreDressingRoom_Map_Load_Function()
{
//RANGE_CITYFashionStoreDressingRoomToFashionStore 4*8,19*8,9*8,20*8
}
void bobsgame_CITYFashionStoreDressingRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
	if(walking_into_door(RANGE_CITYFashionStoreDressingRoomToFashionStore))
	{
		MAP_change_map(MAP_bobsgame_CITYFashionStore,6,10);return;
	}
}
void bobsgame_CITYFashionStoreDressingRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYFashionStoreDressingRoom_Map_VBL_Function()
{

}
void bobsgame_CITYFashionStoreDressingRoom_Map_HBL_Function()
{

}
//========================================================
//CITYFashionStoreDressingRoom2
//========================================================
void bobsgame_CITYFashionStoreDressingRoom2_Map_Load_Function()
{
//RANGE_CITYFashionStoreDressingRoom2ToFashionStore 4*8,19*8,9*8,20*8
}
void bobsgame_CITYFashionStoreDressingRoom2_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//someone in their underwear?
//someone stole my clothes when i wasnt paying attention.
//ive been in here for 3 days. can you bring me a sandwich or something?
//dont you want clothes?
//nah, i'm alright. i never had a full length mirror like this.
//jumping up and down in front of this thing is mesmerizing.

	static NPC* naked_npc = NULL;
	if(naked_npc==NULL)
	{
		NPC_create_npc_xy_feet(&naked_npc,GFX_ADULT_GENERICwomanlonghair,16,40,6*8,11*8);
		naked_npc->layer=2;
		naked_npc->non_walkable=1;
		NPC_animate_stand_dir(&naked_npc,UP);
	}
	if(naked_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&naked_npc,30))NPC_stare_at_npc(&naked_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&naked_npc, UP);
		if(ACTION_npc(&naked_npc,"Talk To Nude Person"))
		{
			TEXT_set_sprite_window(0,naked_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
//TODO: need naked sprite
	if(walking_into_door(RANGE_CITYFashionStoreDressingRoom2ToFashionStore))
	{
		MAP_change_map(MAP_bobsgame_CITYFashionStore,18,10);return;
	}
}
void bobsgame_CITYFashionStoreDressingRoom2_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYFashionStoreDressingRoom2_Map_VBL_Function()
{

}
void bobsgame_CITYFashionStoreDressingRoom2_Map_HBL_Function()
{

}


