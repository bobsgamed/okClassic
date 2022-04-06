//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"


//========================================================
//JAPANUpstairsMainBedroom
//========================================================
void bobsgame_JAPANUpstairsMainBedroom_Map_Load_Function()
{

}

void bobsgame_JAPANUpstairsMainBedroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//TODO: japanese boy
//TODO: need cutscene, japanese text, yellow subtitles
//1000 thumb pushups
	static NPC* japanesekid_npc = NULL;
	if(japanesekid_npc==NULL)
	{
		NPC_create_npc_xy_feet(&japanesekid_npc,GFX_KID_japaneseboy,16,32,12*8,15*8);
		japanesekid_npc->non_walkable=1;
		//japanesekid_npc->pushable=1;
		japanesekid_npc->layer=1;
	}
	if(japanesekid_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&japanesekid_npc,32))NPC_stare_at_npc(&japanesekid_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&japanesekid_npc,UP);
		if(ACTION_npc(&japanesekid_npc,"Talk To Japanese Boy"))
		{
			TEXT_set_sprite_window(0,japanesekid_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
}

void bobsgame_JAPANUpstairsMainBedroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_JAPANUpstairsMainBedroom_Map_VBL_Function()
{

}

void bobsgame_JAPANUpstairsMainBedroom_Map_HBL_Function()
{

}

