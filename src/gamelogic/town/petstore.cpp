//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"



#define RANGE_TOWNPets4LessToOutside 23*8,52*8,27*8,53*8


//========================================================
//TOWNPets4Less
//========================================================
void bobsgame_TOWNPets4Less_Map_Load_Function()
{
//RANGE_TOWNPets4LessToOutside 23*8,52*8,27*8,53*8
}

void bobsgame_TOWNPets4Less_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//counter at 26,40 face left
//22,34-29,45 talk to
//5,12 up aquarium
//5,39 left hamster cage
//3,43 down hamster cage
//14,48 down hamster cage
//9,45 up bird cage
//9,21 right
//9,31 right
//13,25 left
//16,29 right
//20,22 left
//20,27 left
//23,28 right
//27,24 left
//27,18 left
//20,13 up dog cage
	static NPC* counterguy_npc = NULL;
	if(counterguy_npc==NULL)
	{
		NPC_create_npc_xy_feet(&counterguy_npc,GFX_ADULT_GENERICwomanbun,16,40,26*8,40*8);
		counterguy_npc->non_walkable=1;
		counterguy_npc->pushable=1;
		//counterguy_npc->layer=3;
		//TODO: need pet store clerk
	}
	if(counterguy_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&counterguy_npc,60))NPC_stare_at_npc(&counterguy_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&counterguy_npc, LEFT);
		if(ACTION_range_xy_xy(22*8,35*8,29*8,45*8,"Buy Pet"))
		{
			TEXT_set_sprite_window(0,counterguy_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);//TODO: buy pet
		}
	}
	//TODO: fish in aquariums, dogs in cages, birds in bird cage. cats?
	static NPC* petstore_npcs[15] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<15;c++)
	{
		if(petstore_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			if(c== 0){x= 5*8;  y=12*8;dir=UP;}//aquarium
			if(c== 1){x= 6*8;  y=37*8;dir=LEFT;}//hamster cage
			if(c== 2){x= 3*8;  y=42*8;dir=DOWN;}//hamster cage
			if(c== 3){x=14*8;  y=47*8;dir=DOWN;}//hamster
			if(c== 4){x= 9*8;  y=45*8-4;dir=UP;}//bird
			if(c== 5){x= 9*8+2;y=21*8;dir=RIGHT;}
			if(c== 6){x= 9*8+2;y=31*8;dir=RIGHT;}
			if(c== 7){x=14*8-2;y=25*8;dir=LEFT;}
			if(c== 8){x=16*8+2;y=29*8;dir=RIGHT;}
			if(c== 9){x=21*8-2;y=22*8;dir=LEFT;}
			if(c==10){x=21*8-2;y=27*8;dir=LEFT;}
			if(c==11){x=23*8+2;y=30*8;dir=RIGHT;}
			if(c==12){x=28*8-2;y=24*8;dir=LEFT;}
			if(c==13){x=28*8-2;y=18*8;dir=LEFT;}
			if(c==14){x=20*8;  y=11*8;dir=UP;}//dog
			NPC_create_random_ADULT_OR_CHILD_xy_feet(&petstore_npcs[c],x,(y)+3);
			NPC_animate_stand_dir(&petstore_npcs[c], dir);
			petstore_npcs[c]->non_walkable=1;
			//petstore_npcs[c]->pushable=1;
			petstore_npcs[c]->walk_dir=dir;
			petstore_npcs[c]->layer=bgp;
		}
		if(petstore_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&petstore_npcs[c],12))NPC_stare_at_npc(&petstore_npcs[c],&PLAYER_npc);
			else NPC_animate_stand_dir(&petstore_npcs[c], petstore_npcs[c]->walk_dir);
		}
	}
	if(walking_into_door(RANGE_TOWNPets4LessToOutside))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,927,264);return;
	}
}
void bobsgame_TOWNPets4Less_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNPets4Less_Map_VBL_Function()
{

}

void bobsgame_TOWNPets4Less_Map_HBL_Function()
{

}


