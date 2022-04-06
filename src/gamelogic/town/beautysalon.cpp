//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================




#include "../../main.h"



#define RANGE_TOWNBeautySalonToOutside 28*8,41*8,36*8,42*8
#define RANGE_TOWNBeautySalonToBeautySalonTanningRoom 7*8,9*8,11*8,10*8
#define RANGE_TOWNBeautySalonTanningRoomToBeautySalon 7*8,20*8,11*8,21*8



//========================================================
//TOWNBeautySalon
//========================================================
void bobsgame_TOWNBeautySalon_Map_Load_Function()
{
//RANGE_TOWNBeautySalonToOutside 28*8,41*8,36*8,42*8
//RANGE_TOWNBeautySalonToBeautySalonTanningRoom 7*8,9*8,11*8,10*8
}

void bobsgame_TOWNBeautySalon_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//19,28 face right, in hair drying thing
//19,24
//19,20
//19 16
//35,15 face left getting hair washed
//31,14 face down haircut
//24,14 face up haircut
//haircutter at 23,17 face up
//clerk at 27,28 face down
//
//waiting 9,39 face up
//13,39
//15,39
//7,30 face up getting nails done
//8,25 face down nail stylist
//5,15 tanning clerk face down
	static NPC* counterguy_npc = NULL;
	if(counterguy_npc==NULL)
	{
		NPC_create_npc_xy_feet(&counterguy_npc,GFX_ADULT_GENERICwomanbun,16,40,27*8,28*8);
		counterguy_npc->non_walkable=1;
		counterguy_npc->pushable=0;
		//counterguy_npc->layer=3;
		//TODO: need hairstylist
	}
	else if(counterguy_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&counterguy_npc,60))NPC_stare_at_npc(&counterguy_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&counterguy_npc, DOWN);
		if(ACTION_range_xy_xy(25*8,30*8,30*8,31*8,"Get A Haircut"))
		{
			TEXT_set_sprite_window(0,counterguy_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);//TODO: get haircut
		}
	}
	static NPC* tanningcounterguy_npc = NULL;
	if(tanningcounterguy_npc==NULL)
	{
		NPC_create_npc_xy_feet(&tanningcounterguy_npc,GFX_ADULT_GENERICwomanbun,16,40,5*8,15*8);
		tanningcounterguy_npc->non_walkable=1;
		tanningcounterguy_npc->pushable=0;
		//tanningcounterguy_npc->layer=3;
		//TODO: need tanning clerk
	}
	else if(tanningcounterguy_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&tanningcounterguy_npc,60))NPC_stare_at_npc(&tanningcounterguy_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&tanningcounterguy_npc, DOWN);
		if(ACTION_range_xy_xy(25*8,30*8,30*8,31*8,"Get A Tan"))
		{
			TEXT_set_sprite_window(0,tanningcounterguy_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);//TODO: get a tan
		}
	}
	//TODO: limit going past the rope. use code from nurses office
	static NPC* beautysalon_npcs[15] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<13;c++)
	{
		if(beautysalon_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			if(c== 0){x=20*8-4;y=27*8;dir=RIGHT;}//hair drying
			if(c== 1){x=20*8-4;y=23*8;dir=RIGHT;}
			if(c== 2){x=20*8-4;y=19*8;dir=RIGHT;}
			if(c== 3){x=20*8-4;y=15*8;dir=RIGHT;}
			if(c== 4){x=36*8;y=15*8;dir=LEFT;bgp=1;}//hair washed
			if(c== 5){x=31*8;y=14*8+4;dir=DOWN;bgp=1;}//haircut
			if(c== 6){x=24*8;y=14*8+4;dir=DOWN;bgp=1;}//haircut
			if(c== 7){x=24*8;y=13*8;dir=DOWN;}//hair stylist
			if(c== 8){x= 9*8;y=38*8;dir=UP;}//waiting
			if(c== 9){x=13*8;y=38*8;dir=UP;}
			if(c==10){x=15*8;y=38*8;dir=UP;}
			if(c==11){x= 7*8;y=28*8+2;dir=UP;}//getting nails done
			if(c==12){x= 8*8;y=23*8;dir=DOWN;}//nail stylist

			NPC_create_random_ADULT_xy_feet(&beautysalon_npcs[c],x,(y)+3);
			NPC_animate_stand_dir(&beautysalon_npcs[c], dir);
			beautysalon_npcs[c]->non_walkable=1;
			//beautysalon_npcs[c]->pushable=1;
			beautysalon_npcs[c]->walk_dir=dir;
			beautysalon_npcs[c]->layer=bgp;
		}
		if(beautysalon_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&beautysalon_npcs[c],12))NPC_stare_at_npc(&beautysalon_npcs[c],&PLAYER_npc);
			else NPC_animate_stand_dir(&beautysalon_npcs[c], beautysalon_npcs[c]->walk_dir);
		}
	}
		if(walking_into_door(RANGE_TOWNBeautySalonToOutside))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,894,264);return;
	}
	if(walking_into_door(RANGE_TOWNBeautySalonToBeautySalonTanningRoom))
	{
		MAP_change_map(MAP_bobsgame_TOWNBeautySalonTanningRoom,9,19);return;
	}
}
void bobsgame_TOWNBeautySalon_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNBeautySalon_Map_VBL_Function()
{

}

void bobsgame_TOWNBeautySalon_Map_HBL_Function()
{

}

//========================================================
//TOWNBeautySalonTanningRoom
//========================================================
void bobsgame_TOWNBeautySalonTanningRoom_Map_Load_Function()
{
//RANGE_TOWNBeautySalonTanningRoomToBeautySalon 7*8,20*8,11*8,21*8
}

void bobsgame_TOWNBeautySalonTanningRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//TODO: use tanning salon.
//TODO: need laying down sprite.
//TODO: need closed tanning bed lid
	if(walking_into_door(RANGE_TOWNBeautySalonTanningRoomToBeautySalon))
	{
		MAP_change_map(MAP_bobsgame_TOWNBeautySalon,9,10);return;
	}
}
void bobsgame_TOWNBeautySalonTanningRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNBeautySalonTanningRoom_Map_VBL_Function()
{

}

void bobsgame_TOWNBeautySalonTanningRoom_Map_HBL_Function()
{

}



