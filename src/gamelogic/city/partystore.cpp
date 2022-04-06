//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================




#include "../../main.h"


#define RANGE_CITYPartyStoreToOUTSIDECity 30*8,42*8,38*8,43*8
#define RANGE_CITYPartyStoreToBathroom 14*8,9*8,18*8,10*8
#define RANGE_CITYPartyStoreBathroomToPartyStore 9*8,15*8,13*8,16*8


//========================================================
//CITYPartyStore
//========================================================
void bobsgame_CITYPartyStore_Map_Load_Function()
{
//RANGE_CITYPartyStoreToOUTSIDECity 30*8,42*8,38*8,43*8
//RANGE_CITYPartyStoreToBathroom 14*8,9*8,18*8,10*8
}
void bobsgame_CITYPartyStore_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	static NPC* partystoreclerk_npc = NULL;
	if(partystoreclerk_npc==NULL)
	{
		NPC_create_npc_xy_feet(&partystoreclerk_npc,GFX_ADULT_GENERICbeardbaldingtshirt,16,40,49*8,28*8);
		partystoreclerk_npc->non_walkable=1;
		partystoreclerk_npc->pushable=1;
		partystoreclerk_npc->layer=3;
	}
	else if(partystoreclerk_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&partystoreclerk_npc,60))NPC_stare_at_npc(&partystoreclerk_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&partystoreclerk_npc, DOWN);
		if(ACTION_range_xy_xy(45*8,27*8,54*8,31*8,"Purchase Vice"))
		{
			TEXT_set_sprite_window(0,partystoreclerk_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);//TODO: choose between hot dogs, cigarettes, beer, liquor, lottery tickets...
		}
	}//TODO: need party store clerk
	static NPC* pharmacist_npc = NULL;
	if(pharmacist_npc==NULL)
	{
		NPC_create_npc_xy_feet(&pharmacist_npc,GFX_ADULT_quack,16,40,28*8,13*8);
		pharmacist_npc->non_walkable=1;
		pharmacist_npc->pushable=1;
		pharmacist_npc->layer=3;
	}
	else if(pharmacist_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&pharmacist_npc,60))NPC_stare_at_npc(&pharmacist_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&pharmacist_npc, DOWN);
		if(ACTION_range_xy_xy(25*8,14*8,30*8,15*8,"Talk To Pharmacist"))
		{
			TEXT_set_sprite_window(0,pharmacist_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);//TODO: buy ???
		}
	}

		if(ACTION_range_xy_xy(5*8,11*8,12*8,12*8,"Look In Cooler"))
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
		if(ACTION_range_xy_xy(50*8,38*8,53*8,39*8,"Use ATM"))
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	if(walking_into_door(RANGE_CITYPartyStoreToOUTSIDECity))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,604,39);return;
	}
	if(walking_into_door(RANGE_CITYPartyStoreToBathroom))
	{
		MAP_change_map(MAP_bobsgame_CITYPartyStoreBathroom,11,14);return;
	}
}
void bobsgame_CITYPartyStore_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYPartyStore_Map_VBL_Function()
{

}
void bobsgame_CITYPartyStore_Map_HBL_Function()
{

}
//========================================================
//CITYPartyStoreBathroom
//========================================================
void bobsgame_CITYPartyStoreBathroom_Map_Load_Function()
{
//RANGE_CITYPartyStoreBathroomToPartyStore 9*8,15*8,13*8,16*8
}
void bobsgame_CITYPartyStoreBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
		if(ACTION_range_xy_xy(3*8,10*8,4*8,11*8,"Look In Toilet"))
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	if(walking_into_door(RANGE_CITYPartyStoreBathroomToPartyStore))
	{
		MAP_change_map(MAP_bobsgame_CITYPartyStore,16,10);return;
	}
}
void bobsgame_CITYPartyStoreBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYPartyStoreBathroom_Map_VBL_Function()
{

}
void bobsgame_CITYPartyStoreBathroom_Map_HBL_Function()
{

}



