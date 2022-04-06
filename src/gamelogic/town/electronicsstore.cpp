//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"


#define RANGE_TOWNElectronicsStoreToOutside 4*8,52*8,12*8,53*8
#define RANGE_TOWNElectronicsStoreToElectronicsStoreBackRoom 18*8,9*8,22*8,10*8
#define RANGE_TOWNElectronicsStoreBackRoomToElectronicsStore 14*8,28*8,18*8,29*8


//========================================================
//TOWNElectronicsStore
//========================================================
void bobsgame_TOWNElectronicsStore_Map_Load_Function()
{
//RANGE_TOWNElectronicsStoreToOutside 4*8,52*8,12*8,53*8
//RANGE_TOWNElectronicsStoreToElectronicsStoreBackRoom 18*8,9*8,22*8,10*8
}

void bobsgame_TOWNElectronicsStore_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	//clerks 26,37   34,37
	//3,43 up computer
	//5,31 left computer
	//10,35 right
	//18,40 left
	//16,43 up
	//11,21 left
	//21,23 right
	//25,18 left
	//28,24 right
	//26,12 up
	//6,12 up
		static NPC* counterguy_npc = NULL;
	if(counterguy_npc==NULL)
	{
		NPC_create_npc_xy_feet(&counterguy_npc,GFX_ADULT_GENERICwomanbun,16,40,26*8,37*8);
		counterguy_npc->non_walkable=1;
		counterguy_npc->pushable=1;
		//counterguy_npc->layer=3;
		//TODO: need electronics clerk guy old nerd guy?
	}
	if(counterguy_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&counterguy_npc,60))NPC_stare_at_npc(&counterguy_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&counterguy_npc, LEFT);
		if(ACTION_range_xy_xy(22*8,33*8,29*8,41*8,"Buy Electronics"))
		{
			TEXT_set_sprite_window(0,counterguy_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);//TODO: buy electronics
		}
	}
	static NPC* electronicsstore_npcs[11] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<11;c++)
	{
		if(electronicsstore_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			if(c== 0){x= 3*8;y=43*8;dir=UP;}
			if(c== 1){x= 6*8;y=31*8;dir=LEFT;}
			if(c== 2){x=10*8;y=35*8;dir=RIGHT;}
			if(c== 3){x=19*8;y=33*8;dir=LEFT;}
			if(c== 4){x=16*8;y=43*8;dir=UP;}
			if(c== 5){x=12*8;y=21*8;dir=LEFT;}
			if(c== 6){x=21*8;y=23*8;dir=RIGHT;}
			if(c== 7){x=26*8;y=18*8;dir=LEFT;}
			if(c== 8){x=28*8;y=24*8;dir=RIGHT;}
			if(c== 9){x=26*8;y=12*8;dir=UP;}
			if(c==10){x= 6*8;y=12*8;dir=UP;}
			NPC_create_random_ADULT_OR_CHILD_xy_feet(&electronicsstore_npcs[c],x,(y)+3);
			NPC_animate_stand_dir(&electronicsstore_npcs[c], dir);
			electronicsstore_npcs[c]->non_walkable=1;
			//electronicsstore_npcs[c]->pushable=1;
			electronicsstore_npcs[c]->walk_dir=dir;
			electronicsstore_npcs[c]->layer=bgp;
		}
		if(electronicsstore_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&electronicsstore_npcs[c],12))NPC_stare_at_npc(&electronicsstore_npcs[c],&PLAYER_npc);
			else NPC_animate_stand_dir(&electronicsstore_npcs[c], electronicsstore_npcs[c]->walk_dir);
		}
	}
	if(walking_into_door(RANGE_TOWNElectronicsStoreToOutside))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,1162,263);return;
	}
	if(walking_into_door(RANGE_TOWNElectronicsStoreToElectronicsStoreBackRoom))
	{
		MAP_change_map(MAP_bobsgame_TOWNElectronicsStoreBackRoom,16,27);return;
	}
}
void bobsgame_TOWNElectronicsStore_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNElectronicsStore_Map_VBL_Function()
{

}

void bobsgame_TOWNElectronicsStore_Map_HBL_Function()
{

}

//========================================================
//TOWNElectronicsStoreBackRoom
//========================================================
void bobsgame_TOWNElectronicsStoreBackRoom_Map_Load_Function()
{
//RANGE_TOWNElectronicsStoreBackRoomToElectronicsStore 14*8,28*8,18*8,29*8
}

void bobsgame_TOWNElectronicsStoreBackRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{
	}

	static NPC* shadyguy_npc = NULL;
	if(shadyguy_npc==NULL)
	{
		NPC_create_npc_xy_feet(&shadyguy_npc,GFX_ADULT_shadywatchdealer,16,40,13*8,15*8);
		shadyguy_npc->non_walkable=1;
		//shadyguy_npc->pushable=1;
	}
	else if(shadyguy_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&shadyguy_npc,60))NPC_stare_at_npc(&shadyguy_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&shadyguy_npc, LEFT);
		if(ACTION_npc(&shadyguy_npc,"Talk To Shady Guy"))
		{
			TEXT_set_sprite_window(0,shadyguy_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);//TODO: buy electronics
		}
	}
	if(walking_into_door(RANGE_TOWNElectronicsStoreBackRoomToElectronicsStore))
	{
		MAP_change_map(MAP_bobsgame_TOWNElectronicsStore,20,10);return;
	}
}
void bobsgame_TOWNElectronicsStoreBackRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNElectronicsStoreBackRoom_Map_VBL_Function()
{

}

void bobsgame_TOWNElectronicsStoreBackRoom_Map_HBL_Function()
{

}


