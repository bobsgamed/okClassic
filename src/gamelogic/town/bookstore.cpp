//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================




#include "../../main.h"


#define RANGE_TOWNBookstoreToOutside 4*8,51*8,12*8,52*8
#define RANGE_TOWNBookstoreToBookstoreBathroom 13*8,10*8,14*8,14*8
#define RANGE_TOWNBookstoreBathroomToBookstore 1*8,10*8,2*8,14*8


//========================================================
//TOWNBookstore
//========================================================
void bobsgame_TOWNBookstore_Map_Load_Function()
{
//RANGE_TOWNBookstoreToOutside 4*8,51*8,12*8,52*8
//RANGE_TOWNBookstoreToBookstoreBathroom 13*8,10*8,14*8,14*8
}

void bobsgame_TOWNBookstore_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//bookstore thief comes in steals goes into bathroom?
//clerk at 25,42
	static NPC* counterguy_npc = NULL;
	if(counterguy_npc==NULL)
	{
		NPC_create_npc_xy_feet(&counterguy_npc,GFX_ADULT_GENERICwomanbun,16,40,25*8,42*8);
		counterguy_npc->non_walkable=1;
		counterguy_npc->layer=3;
		//TODO: need bookstore clerk sprite
	}
	else if(counterguy_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&counterguy_npc,60))NPC_stare_at_npc(&counterguy_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&counterguy_npc, LEFT);
		if(ACTION_range_xy_xy(21*8,40*8,29*8,48*8,"Buy Books"))
		{
			TEXT_set_sprite_window(0,counterguy_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);//TODO: buy books
		}
	}
		static NPC* bookstore_npcs[11] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<11;c++)
	{
		if(bookstore_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			if(c== 0){x= 3*8;y=43*8;dir=UP;}//bookshelves
			if(c== 1){x= 9*8;y=43*8;dir=UP;}
			if(c== 2){x= 5*8;y=36*8;dir=UP;}
			if(c== 3){x= 4*8;y=29*8;dir=UP;}
			if(c== 4){x= 7*8;y=29*8;dir=UP;}
			if(c== 5){x= 6*8;y=22*8;dir=UP;}
			if(c== 6){x=23*8;y=25*8;dir=DOWN;bgp=1;}//bench
			if(c== 7){x=24*8;y=17*8;dir=UP;}//magazine rack
			if(c== 8){x= 6*8;y=11*8;dir=UP;}//pay phone
			if(c== 9){x=19*8+3;y=23*8+2;dir=RIGHT;}//left bench face right
			if(c==10){x=17*8;y=47*8;dir=DOWN;}//newspapers down

			NPC_create_random_ADULT_OR_CHILD_xy_feet(&bookstore_npcs[c],x,(y)+3);
			NPC_animate_stand_dir(&bookstore_npcs[c], dir);
			bookstore_npcs[c]->non_walkable=1;
			bookstore_npcs[c]->walk_dir=dir;
			bookstore_npcs[c]->layer=bgp;
		}
		if(bookstore_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&bookstore_npcs[c],12))NPC_stare_at_npc(&bookstore_npcs[c],&PLAYER_npc);
			else NPC_animate_stand_dir(&bookstore_npcs[c], bookstore_npcs[c]->walk_dir);
		}
	}
		if(walking_into_door(RANGE_TOWNBookstoreToOutside))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,800,264);return;
	}
	if(walking_into_door(RANGE_TOWNBookstoreToBookstoreBathroom))
	{
		MAP_change_map(MAP_bobsgame_TOWNBookstoreBathroom,2,12);return;
	}
}
void bobsgame_TOWNBookstore_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNBookstore_Map_VBL_Function()
{

}

void bobsgame_TOWNBookstore_Map_HBL_Function()
{

}

//========================================================
//TOWNBookstoreBathroom
//========================================================
void bobsgame_TOWNBookstoreBathroom_Map_Load_Function()
{
//RANGE_TOWNBookstoreBathroomToBookstore 1*8,10*8,2*8,14*8
}

void bobsgame_TOWNBookstoreBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	static NPC* bookstorebathroomguy_npc = NULL;
	if(bookstorebathroomguy_npc==NULL)
	{

		NPC_create_npc_xy_feet(&bookstorebathroomguy_npc,GFX_ADULT_GENERICbaldingmantshirt,16,40,16*8,12*8);
		NPC_animate_stand_dir(&bookstorebathroomguy_npc, UP);
		bookstorebathroomguy_npc->non_walkable=1;
	}
	else if(bookstorebathroomguy_npc!=NULL)
	{
		//TODO: talk to guy at toilet
	}
	if(walking_into_door(RANGE_TOWNBookstoreBathroomToBookstore))
	{
		MAP_change_map(MAP_bobsgame_TOWNBookstore,12,12);return;
	}
}
void bobsgame_TOWNBookstoreBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNBookstoreBathroom_Map_VBL_Function()
{

}

void bobsgame_TOWNBookstoreBathroom_Map_HBL_Function()
{

}



