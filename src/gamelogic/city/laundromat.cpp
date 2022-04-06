//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"




#define RANGE_CITYLaundromatToOUTSIDECity 33*8,47*8,41*8,48*8




//========================================================
//CITYLaundromat
//========================================================
void bobsgame_CITYLaundromat_Map_Load_Function()
{
//RANGE_CITYLaundromatToOUTSIDECity 33*8,47*8,41*8,48*8
}
void bobsgame_CITYLaundromat_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//8,12 face right
	static NPC* laundromatowner_npc = NULL;
	if(laundromatowner_npc==NULL)
	{
		NPC_create_npc_xy_feet(&laundromatowner_npc,GFX_ADULT_GENERICbeardbaldingtshirt,16,40,8*8,12*8);
		laundromatowner_npc->layer=2;
		laundromatowner_npc->non_walkable=1;
		NPC_animate_stand_dir(&laundromatowner_npc,DOWN);
	}
	if(laundromatowner_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&laundromatowner_npc,50))NPC_stare_at_npc(&laundromatowner_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&laundromatowner_npc, DOWN);
		//TODO: ANIMATE
		if(ACTION_range_xy_xy(10*8,12*8,11*8,16*8,"Talk To Attendant"))
		{
			TEXT_set_sprite_window(0,laundromatowner_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	//8+4,39 left
	//30 left
	//26 left
	//11+4,37 right
	//11+4,27 right
	//13,44 up
	//41,27 up staring
	//34,31 down
	//30,13 up
	static NPC* laundromat_npcs[9] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<9;c++)
	{
		if(laundromat_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			//int* gfx=NULL;
			if(c== 0){x=8*8+6;y=39*8;dir=LEFT;}
			if(c== 1){x=8*8+6;y=29*8;dir=LEFT;}
			if(c== 2){x=8*8+6;y=26*8;dir=LEFT;}
			if(c== 3){x=12*8-6;y=37*8;dir=RIGHT;}
			if(c== 4){x=12*8-6;y=27*8;dir=RIGHT;}
			if(c== 5){x=13*8;y=43*8+3;dir=UP;}
			if(c== 6){x=41*8;y=27*8;dir=UP;}
			if(c== 7){x=34*8;y=30*8+3;dir=DOWN;}
			if(c== 8){x=30*8;y=12*8;dir=UP;}

			NPC_create_random_ADULT_xy_feet(&laundromat_npcs[c],x,y);

			//NPC_create_npc_xy_feet(&laundromat_npcs[c],gfx,16,40,x,(y));
			NPC_animate_stand_dir(&laundromat_npcs[c], dir);
			laundromat_npcs[c]->non_walkable=1;
			laundromat_npcs[c]->walk_dir=dir;
			laundromat_npcs[c]->layer=bgp;
		}
		//TODO: need humming noise,
		//TODO: need some open washers/driers
		//TODO: need to animate tile?
		//TODO: need something for laundry lady to do
		//TODO: need someone moving.
		if(laundromat_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&laundromat_npcs[c],15))NPC_stare_at_npc(&laundromat_npcs[c],&PLAYER_npc);
			else NPC_animate_stand_dir(&laundromat_npcs[c], laundromat_npcs[c]->walk_dir);
			//TODO: ANIMATE
		}
	}

	if(walking_into_door(RANGE_CITYLaundromatToOUTSIDECity))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,441,39);return;
	}
}
void bobsgame_CITYLaundromat_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYLaundromat_Map_VBL_Function()
{

}
void bobsgame_CITYLaundromat_Map_HBL_Function()
{

}



