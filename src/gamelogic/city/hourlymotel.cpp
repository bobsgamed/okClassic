//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"

#define RANGE_CITYHourlyMotelToOUTSIDECity 20*8,66*8,24*8,67*8
#define RANGE_CITYHourlyMotelToRoom 23*8,23*8,24*8,27*8
#define RANGE_CITYHourlyMotelRoomToLobby 23*8,23*8,24*8,27*8
#define RANGE_CITYHourlyMotelToBathroom 15*8,27*8,16*8,31*8
#define RANGE_CITYHourlyMotelBathroomToRoom 15*8,10*8,16*8,14*8

//========================================================
//CITYHourlyMotel
//========================================================
void bobsgame_CITYHourlyMotel_Map_Load_Function()
{
//RANGE_CITYHourlyMotelToOUTSIDECity 20*8,66*8,24*8,67*8
//RANGE_CITYHourlyMotelToRoom 23*8,23*8,24*8,27*8
}
void bobsgame_CITYHourlyMotel_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}


	//TODO: need fat guy sprite

	static NPC* motelclerk_npc = NULL;
	if(motelclerk_npc==NULL)
	{
		//NPC_create_random_ADULT_xy_feet(&motelclerk_npc,10*8-4,27*8);
		NPC_create_npc_xy_feet(&motelclerk_npc,GFX_ADULT_pawnshopguy,16,40,9*8-2,59*8-2);

		motelclerk_npc->non_walkable=1;
		motelclerk_npc->layer=2;
		NPC_animate_stand_dir(&motelclerk_npc,RIGHT);

		motelclerk_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		motelclerk_npc->walk_dir=motelclerk_npc->anim_dir;
	}
	if(motelclerk_npc!=NULL)
	{

		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&motelclerk_npc,55))NPC_stare_at_npc_not_opposite_walking_direction(&motelclerk_npc,&PLAYER_npc);
		else
		{
			if(motelclerk_npc->AI==0){if(motelclerk_npc->vbls>200){if(r(4)==0){motelclerk_npc->AI=1+r(3);}else{motelclerk_npc->vbls=0;NPC_animate_stand_dir(&motelclerk_npc, motelclerk_npc->walk_dir);if(motelclerk_npc->anim_frame_count!=0){motelclerk_npc->anim_frame_count=3;NPC_animate(&motelclerk_npc);}}}}
			if(motelclerk_npc->AI==1){if(motelclerk_npc->walk_dir==UP||motelclerk_npc->walk_dir==DOWN)NPC_animate_stand_dir(&motelclerk_npc,LEFT);else NPC_animate_stand_dir(&motelclerk_npc,UP);motelclerk_npc->vbls=r(120);motelclerk_npc->AI=0;}
			if(motelclerk_npc->AI==2){if(motelclerk_npc->walk_dir==UP||motelclerk_npc->walk_dir==DOWN)NPC_animate_stand_dir(&motelclerk_npc,RIGHT);else NPC_animate_stand_dir(&motelclerk_npc,DOWN);motelclerk_npc->vbls=r(120);motelclerk_npc->AI=0;}
			if(motelclerk_npc->AI==3){NPC_animate(&motelclerk_npc);motelclerk_npc->vbls=r(120);motelclerk_npc->AI=0;}
		}

		if(ACTION_range_xy_xy(12*8,58*8,13*8,63*8,"Talk To Motel Guy"))
		{
			TEXT_set_sprite_window(0,motelclerk_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("" //?
			);
		}
	}

	if(walking_into_door(RANGE_CITYHourlyMotelToOUTSIDECity))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,109,39);return;
	}
	if(walking_into_door(RANGE_CITYHourlyMotelToRoom))
	{
		MAP_change_map(MAP_bobsgame_CITYHourlyMotelRoom,21,24);return;
	}
}
void bobsgame_CITYHourlyMotel_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHourlyMotel_Map_VBL_Function()
{

}
void bobsgame_CITYHourlyMotel_Map_HBL_Function()
{

}

//========================================================
//CITYHourlyMotelRoom
//========================================================
void bobsgame_CITYHourlyMotelRoom_Map_Load_Function()
{
//RANGE_CITYHourlyMotelRoomToLobby 23*8,23*8,24*8,27*8
//RANGE_CITYHourlyMotelToBathroom 15*8,27*8,16*8,31*8
}
void bobsgame_CITYHourlyMotelRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	if(walking_into_door(RANGE_CITYHourlyMotelRoomToLobby))
	{
		MAP_change_map(MAP_bobsgame_CITYHourlyMotel,24,24);return;
	}
	if(walking_into_door(RANGE_CITYHourlyMotelToBathroom))
	{
		MAP_change_map(MAP_bobsgame_CITYHourlyMotelRoomBathroom,13,12);return;
	}
}
void bobsgame_CITYHourlyMotelRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHourlyMotelRoom_Map_VBL_Function()
{

}
void bobsgame_CITYHourlyMotelRoom_Map_HBL_Function()
{

}
//========================================================
//CITYHourlyMotelRoomBathroom
//========================================================
void bobsgame_CITYHourlyMotelRoomBathroom_Map_Load_Function()
{
//RANGE_CITYHourlyMotelBathroomToRoom 15*8,10*8,16*8,14*8
}
void bobsgame_CITYHourlyMotelRoomBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	if(walking_into_door(RANGE_CITYHourlyMotelBathroomToRoom))
	{
		MAP_change_map(MAP_bobsgame_CITYHourlyMotelRoom,16,28);return;
	}
}
void bobsgame_CITYHourlyMotelRoomBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHourlyMotelRoomBathroom_Map_VBL_Function()
{

}
void bobsgame_CITYHourlyMotelRoomBathroom_Map_HBL_Function()
{

}


