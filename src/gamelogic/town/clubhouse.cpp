//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================




#include "../../main.h"




#define RANGE_OUTSIDEClubHouseToOUTSIDETown 10*8,22*8,14*8,23*8



//========================================================
//ClubHouse
//========================================================
void bobsgame_TOWNClubHouse_Map_Load_Function()
{
//RANGE_OUTSIDEClubHouseToOUTSIDETown 10*8,22*8,14*8,23*8
}

void bobsgame_TOWNClubHouse_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
	if(walking_into_door(RANGE_OUTSIDEClubHouseToOUTSIDETown))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,413,615);return;
	}
}
void bobsgame_TOWNClubHouse_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNClubHouse_Map_VBL_Function()
{

}

void bobsgame_TOWNClubHouse_Map_HBL_Function()
{

}



