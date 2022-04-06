//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"


#define RANGE_OUTSIDEToolShedToOUTSIDETown 4*8,18*8,10*8,19*8

//========================================================
//YUUBackyardToolShed
//========================================================
void bobsgame_TOWNYUUBackyardToolShed_Map_Load_Function()
{
//RANGE_OUTSIDEToolShedToOUTSIDETown 4*8,18*8,10*8,19*8
}

void bobsgame_TOWNYUUBackyardToolShed_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//TODO: lawnmower sprite, lawnmower minigame?
	if(walking_into_door(RANGE_OUTSIDEToolShedToOUTSIDETown))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,548,437);return;
	}
}
void bobsgame_TOWNYUUBackyardToolShed_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNYUUBackyardToolShed_Map_VBL_Function()
{

}

void bobsgame_TOWNYUUBackyardToolShed_Map_HBL_Function()
{

}


