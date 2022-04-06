//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================




#include "../../main.h"


#define RANGE_TOWNRecordStoreToOutside 9*8,47*8,13*8,48*8



//========================================================
//TOWNRecordStore
//========================================================
void bobsgame_TOWNRecordStore_Map_Load_Function()
{
//RANGE_TOWNRecordStoreToOutside 9*8,47*8,13*8,48*8
}

void bobsgame_TOWNRecordStore_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//clerk 3,42 face right
//2,38 7,47 talk to
//8,12 up
//17,12 up
//34, 12 up
//36,23 right
//36,40 right
//31, 28 left
//27,20 right
//27,38 right
//22,22 left
//22,31 left
//18,27 right
//13,29 left
//13,21 left
//9,24 right
//4,18 left
//4,32 left
	static NPC* counterguy_npc = NULL;
	if(counterguy_npc==NULL)
	{
		NPC_create_npc_xy_feet(&counterguy_npc,GFX_ADULT_GENERICwomanbun,16,40,4*8,41*8);
		counterguy_npc->non_walkable=1;
		//counterguy_npc->layer=3;
		//TODO: need music store guy
	}
	else if(counterguy_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&counterguy_npc,60))NPC_stare_at_npc(&counterguy_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&counterguy_npc, RIGHT);
		if(ACTION_range_xy_xy(2*8,38*8,7*8,47*8,"Buy Music"))
		{
			TEXT_set_sprite_window(0,counterguy_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);//TODO: buy music
		}
	}
	static NPC* recordstore_npcs[16] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<16;c++)
	{
		if(recordstore_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			if(c== 0){x= 9*8;y=12*8;dir=UP;}
			if(c== 1){x=17*8;y=12*8;dir=UP;}
			if(c== 2){x=35*8;y=12*8;dir=UP;}
			if(c== 3){x=36*8;y=23*8;dir=RIGHT;}
			if(c== 4){x=36*8;y=40*8;dir=RIGHT;}
			if(c== 5){x=32*8;y=28*8;dir=LEFT;}
			if(c== 6){x=27*8;y=20*8;dir=RIGHT;}
			if(c== 7){x=27*8;y=38*8;dir=RIGHT;}
			if(c== 8){x=23*8;y=22*8;dir=LEFT;}
			if(c== 9){x=23*8;y=31*8;dir=LEFT;}
			if(c==10){x=18*8;y=27*8;dir=RIGHT;}
			if(c==11){x=14*8;y=29*8;dir=LEFT;}
			if(c==12){x=14*8;y=21*8;dir=LEFT;}
			if(c==13){x= 9*8;y=24*8;dir=RIGHT;}
			if(c==14){x= 5*8;y=19*8;dir=LEFT;}
			if(c==15){x= 5*8;y=32*8;dir=LEFT;}
			NPC_create_random_ADULT_OR_CHILD_xy_feet(&recordstore_npcs[c],x,(y)+3);
			NPC_animate_stand_dir(&recordstore_npcs[c], dir);
			recordstore_npcs[c]->non_walkable=1;
			recordstore_npcs[c]->walk_dir=dir;
			recordstore_npcs[c]->layer=bgp;
		}
		if(recordstore_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&recordstore_npcs[c],12))NPC_stare_at_npc(&recordstore_npcs[c],&PLAYER_npc);
			else NPC_animate_stand_dir(&recordstore_npcs[c], recordstore_npcs[c]->walk_dir);
		}
	}
		if(walking_into_door(RANGE_TOWNRecordStoreToOutside))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,1371,264);return;
	}
}
void bobsgame_TOWNRecordStore_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNRecordStore_Map_VBL_Function()
{

}

void bobsgame_TOWNRecordStore_Map_HBL_Function()
{

}


