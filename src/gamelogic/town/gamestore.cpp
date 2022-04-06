//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"




#define RANGE_TOWNGameStoreToOutside 20*8,43*8,28*8,44*8


//========================================================
//TOWNGameStore
//========================================================
void bobsgame_TOWNGameStore_Map_Load_Function()
{
//RANGE_TOWNGameStoreToOutside 20*8,43*8,28*8,44*8
}

void bobsgame_TOWNGameStore_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//clerks
//27,17
//35,17
//23-30,20 talk to 1
//33-40,40 talk to 2
	static NPC* gamestoreclerk_npc = NULL;
	if(gamestoreclerk_npc==NULL)
	{
		NPC_create_npc_xy_feet(&gamestoreclerk_npc,GFX_ADULT_GENERICwomanlonghair,16,40,27*8,16*8);
		gamestoreclerk_npc->non_walkable=1;
		gamestoreclerk_npc->layer=2;
		NPC_animate_stand_dir(&gamestoreclerk_npc, DOWN);
	}
	else if(gamestoreclerk_npc!=NULL)
	{
		if(ACTION_range_xy_xy(23*8,19*8,30*8,20*8,"Talk To N Fan"))
		{
			TEXT_set_sprite_window(0,gamestoreclerk_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("It's all about fun and gameplay, innovation, Yuu knows? If Yuu wants photorealistic violence, go watch an action movie."
			);
		}
	}
	static NPC* gamestoreclerk2_npc = NULL;
	if(gamestoreclerk2_npc==NULL)
	{
		NPC_create_npc_xy_feet(&gamestoreclerk2_npc,GFX_ADULT_GENERICmanlongsleeves,16,40,35*8,16*8);
		gamestoreclerk2_npc->non_walkable=1;
		gamestoreclerk2_npc->layer=2;
		NPC_animate_stand_dir(&gamestoreclerk2_npc, DOWN);
	}
	else if(gamestoreclerk2_npc!=NULL)
	{
		if(ACTION_range_xy_xy(33*8,19*8,40*8,20*8,"Talk To S Fan"))
		{
			TEXT_set_sprite_window(0,gamestoreclerk2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("I wouldn't be caught dead playing those little kid games. Who wants to play a cartoon? I've gotta have something with style and plot."
			);
		}
	}
//kid playing demo 12,12 up
//bin guy 7,33 left
//11,34 face down
//17,32 face up
//35,38 face up wii
	static NPC* demokids_npcs[5] = {NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<5;c++)
	{
		if(demokids_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			if(c== 0){x=12*8;y=12*8;dir=UP;bgp=1;}
			if(c== 1){x= 8*8;y=31*8;dir=LEFT;}
			if(c== 2){x=11*8;y=33*8;dir=DOWN;}
			if(c== 3){x=17*8;y=32*8;dir=UP;bgp=1;}
			if(c== 4){x=36*8;y=36*8;dir=UP;bgp=1;}
			NPC_create_random_CHILD_xy_feet(&demokids_npcs[c],x,(y)+3);
			NPC_animate_stand_dir(&demokids_npcs[c], dir);
			demokids_npcs[c]->non_walkable=1;
			demokids_npcs[c]->layer=bgp;
			demokids_npcs[c]->walk_dir=dir;
		}
		else if(demokids_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&demokids_npcs[c],16))NPC_stare_at_npc(&demokids_npcs[c],&PLAYER_npc);
			else NPC_animate_stand_dir(&demokids_npcs[c], demokids_npcs[c]->walk_dir);
			//if(ACTION_npc(&demokids_npcs[c],"Talk To Patient"))
			//{
			//	TEXT_set_sprite_window(0,demokids_npcs[c],NULL);
			//	TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			//	if(c==0)TEXT_window("");
			//}
		}
	}
//5,8-8,9 door to backroom, cant go in
	if(ACTION_range_xy_xy(5*8,8*8,8*8,9*8,"Go In Back Room"))
	{
		TEXT_set_sprite_window(0,PLAYER_npc,NULL);
		TEXT_set_sprite_window(1,PLAYER_npc,NULL);
		TEXT_window("Locked. They're playing Super Mushroom 128 back there, I'm sure of it."
		);
	}
	if(walking_into_door(RANGE_TOWNGameStoreToOutside))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,1247,264);return;
	}
}
void bobsgame_TOWNGameStore_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNGameStore_Map_VBL_Function()
{

}

void bobsgame_TOWNGameStore_Map_HBL_Function()
{

}


