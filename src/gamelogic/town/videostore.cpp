//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================

#include "../../main.h"


#define RANGE_TOWNVideoRentToOutside 9*8,37*8,13*8,38*8
#define RANGE_TOWNVideoRentToVideoRentAdultRoom 32*8,17*8,36*8,18*8
#define RANGE_TOWNVideoRentAdultRoomToVideoRent 5*8,18*8,9*8,19*8



//========================================================
//TOWNVideoRent
//========================================================
void bobsgame_TOWNVideoRent_Map_Load_Function()
{
//NPC_create_sprite(&adultsonlysign,32,16,264,112);
//RANGE_TOWNVideoRentToOutside 9*8,37*8,13*8,38*8
//RANGE_TOWNVideoRentToVideoRentAdultRoom 32*8,17*8,36*8,18*8
//NPC_create_npc(&NULL,adultsonlysign,32,16,264,112);
}
void bobsgame_TOWNVideoRent_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//3x2tv at 3,4
//24,4
//29,12
//clerk at 18,33 face up
//guy at 10,10 face up
//15,10 face up
//26,12 face right
//37,24 right
//37,33 right
//29,30 left
//26,23 right
//21,21 right
//14,18 left
//9,23 left
//6,16 right
//3,30 left
//TODO: maybe have people stand for awhile, look around, move a tile
//TODO: need to have tvs playing previews
	static NPC* counterguy_npc = NULL;
	if(counterguy_npc==NULL)
	{
		NPC_create_npc_xy_feet(&counterguy_npc,GFX_ADULT_GENERICwomanbun,16,40,19*8,33*8);
		counterguy_npc->non_walkable=1;
		//counterguy_npc->layer=3;
		//TODO: need video rental guy
	}
	else if(counterguy_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&counterguy_npc,60))NPC_stare_at_npc(&counterguy_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&counterguy_npc, UP);
		if(ACTION_range_xy_xy(16*8,29*8,20*8,37*8,"Rent Video"))
		{
			TEXT_set_sprite_window(0,counterguy_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);//TODO: rent video
		}
	}
	static NPC* videorent_npcs[12] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<12;c++)
	{
		if(videorent_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			if(c== 0){x=10*8;y=10*8;dir=UP;}
			if(c== 1){x=15*8;y=10*8;dir=UP;}
			if(c== 2){x=26*8+2;y=11*8;dir=RIGHT;}
			if(c== 3){x=37*8+2;y=24*8;dir=RIGHT;}
			if(c== 4){x=37*8+2;y=33*8;dir=RIGHT;}
			if(c== 5){x=30*8-2;y=30*8;dir=LEFT;}
			if(c== 6){x=26*8+2;y=23*8;dir=RIGHT;}
			if(c== 7){x=21*8+2;y=21*8;dir=RIGHT;}
			if(c== 8){x=15*8-2;y=18*8;dir=LEFT;}
			if(c== 9){x=10*8-2;y=23*8;dir=LEFT;}
			if(c==10){x= 6*8+2;y=16*8;dir=RIGHT;}
			if(c==11){x= 4*8-2;y=30*8;dir=LEFT;}
			NPC_create_random_ADULT_xy_feet(&videorent_npcs[c],x,(y)+3);
			NPC_animate_stand_dir(&videorent_npcs[c], dir);
			videorent_npcs[c]->non_walkable=1;
			videorent_npcs[c]->walk_dir=dir;
			videorent_npcs[c]->layer=bgp;
		}
		if(videorent_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&videorent_npcs[c],12))NPC_stare_at_npc(&videorent_npcs[c],&PLAYER_npc);
			else NPC_animate_stand_dir(&videorent_npcs[c], videorent_npcs[c]->walk_dir);
		}
	}
	if(walking_into_door(RANGE_TOWNVideoRentToOutside))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,1197,264);return;
	}
	if(walking_into_door(RANGE_TOWNVideoRentToVideoRentAdultRoom))
	{
		MAP_change_map(MAP_bobsgame_TOWNVideoRentAdultRoom,7,17);return;
	}
}
void bobsgame_TOWNVideoRent_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNVideoRent_Map_VBL_Function()
{

}

void bobsgame_TOWNVideoRent_Map_HBL_Function()
{

}

//========================================================
//TOWNVideoRentAdultRoom
//========================================================
void bobsgame_TOWNVideoRentAdultRoom_Map_Load_Function()
{
//RANGE_TOWNVideoRentAdultRoomToVideoRent 5*8,18*8,9*8,19*8
}
void bobsgame_TOWNVideoRentAdultRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	static NPC* adultroom_npcs[2] = {NULL,NULL};
	int c=0;
	for(c=0;c<2;c++)
	{
		if(adultroom_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			if(c== 0){x= 5*8;y=10*8+4;dir=UP;}
			if(c== 1){x= 9*8;y=10*8+4;dir=UP;}
			NPC_create_random_ADULT_xy_feet(&adultroom_npcs[c],x,(y)+3);
			NPC_animate_stand_dir(&adultroom_npcs[c], dir);
			adultroom_npcs[c]->non_walkable=1;
			adultroom_npcs[c]->walk_dir=dir;
			adultroom_npcs[c]->layer=bgp;
		}
		if(adultroom_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&adultroom_npcs[c],12))NPC_stare_at_npc(&adultroom_npcs[c],&PLAYER_npc);
			else NPC_animate_stand_dir(&adultroom_npcs[c], adultroom_npcs[c]->walk_dir);
		}
	}
	if(walking_into_door(RANGE_TOWNVideoRentAdultRoomToVideoRent))
	{
		MAP_change_map(MAP_bobsgame_TOWNVideoRent,34,18);return;
	}
		//TODO: talk to guy buying adult videos :)
}
void bobsgame_TOWNVideoRentAdultRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNVideoRentAdultRoom_Map_VBL_Function()
{

}

void bobsgame_TOWNVideoRentAdultRoom_Map_HBL_Function()
{

}


