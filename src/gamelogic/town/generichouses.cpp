//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"


#define RANGE_GENERIC1DownstairsToOUTSIDEFrontyard 26*8,42*8,30*8,43*8
#define RANGE_GENERIC2DownstairsToOUTSIDEFrontyard 26*8,42*8,30*8,43*8
#define RANGE_GENERIC3DownstairsToOUTSIDEFrontyard 31*8,42*8,35*8,43*8


//========================================================
//GENERIC1Downstairs
//========================================================
void bobsgame_TOWNGENERIC1Downstairs_Map_Load_Function()
{
//RANGE_GENERIC1DownstairsToOUTSIDEFrontyard 26*8,42*8,30*8,43*8
}

void bobsgame_TOWNGENERIC1Downstairs_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_GENERIC1DownstairsToOUTSIDEFrontyard))
	{
		//MAP_change_map(,);return;
	}
}
void bobsgame_TOWNGENERIC1Downstairs_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNGENERIC1Downstairs_Map_VBL_Function()
{

}

void bobsgame_TOWNGENERIC1Downstairs_Map_HBL_Function()
{

}

//========================================================
//GENERIC2Downstairs
//========================================================
void bobsgame_TOWNGENERIC2Downstairs_Map_Load_Function()
{
//RANGE_GENERIC2DownstairsToOUTSIDEFrontyard 26*8,42*8,30*8,43*8
}

void bobsgame_TOWNGENERIC2Downstairs_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_GENERIC2DownstairsToOUTSIDEFrontyard))
	{
		//MAP_change_map(,);return;
	}
}
void bobsgame_TOWNGENERIC2Downstairs_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNGENERIC2Downstairs_Map_VBL_Function()
{

}

void bobsgame_TOWNGENERIC2Downstairs_Map_HBL_Function()
{

}

//========================================================
//GENERIC3Downstairs
//========================================================
void bobsgame_TOWNGENERIC3Downstairs_Map_Load_Function()
{
//RANGE_GENERIC3DownstairsToOUTSIDEFrontyard 31*8,42*8,35*8,43*8
}

void bobsgame_TOWNGENERIC3Downstairs_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_GENERIC3DownstairsToOUTSIDEFrontyard))
	{
		//MAP_change_map(,);return;
	}
}
void bobsgame_TOWNGENERIC3Downstairs_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}

void bobsgame_TOWNGENERIC3Downstairs_Map_VBL_Function()
{

}

void bobsgame_TOWNGENERIC3Downstairs_Map_HBL_Function()
{

}



