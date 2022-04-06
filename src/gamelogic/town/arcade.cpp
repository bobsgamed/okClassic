//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"




#define RANGE_TOWNArcadeToOutside 5*8,32*8,13*8,33*8





//========================================================
//TOWNArcade
//========================================================
void bobsgame_TOWNArcade_Map_Load_Function()
{
//RANGE_TOWNArcadeToOutside 5*8,32*8,13*8,33*8
//dude..youre bleeding..
//YEAH BUT IT WAS COOL RIGHT?!
}
void bobsgame_TOWNArcade_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	//clerk at 27,29 face up
	//85,18 face up basketball game
	//54,26 up coin pusher
	//65,26 down claw game
	//63,13 up arcade game
	//47,12 classic arcade game
	//33,12 up driving game below 2?
	//10,12 coins
	//19ish middle
	//ddr from 68, 14 to 73 14
		//TODO: kid goes from coin pusher to coin machine?
	//TODO: animate basketball game, arcade games, ddr buttons, ddr lights
		static NPC* arcadeguy_npc = NULL;
	if(arcadeguy_npc==NULL)
	{
		NPC_create_npc_xy_feet(&arcadeguy_npc,GFX_ADULT_GENERICwomanbun,16,40,27*8,28*8);
		arcadeguy_npc->non_walkable=1;
		arcadeguy_npc->pushable=1;
		arcadeguy_npc->layer=1;
		//TODO: need arcade clerk sprite
	}
	else if(arcadeguy_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&arcadeguy_npc,60))NPC_stare_at_npc(&arcadeguy_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&arcadeguy_npc, UP);
		if(ACTION_range_xy_xy(25*8,24*8,30*8,25*8,"Redeem Tickets"))
		{
			TEXT_set_sprite_window(0,arcadeguy_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);//TODO: ticket thing
		}
	}
	static NPC* ddrkid_npc = NULL;
	if(ddrkid_npc==NULL)
	{
		NPC_create_npc_xy_feet(&ddrkid_npc,GFX_ADULT_bob,16,40,70*8,14*8);
		ddrkid_npc->non_walkable=1;
		ddrkid_npc->pushable=1;
		NPC_animate_stand_dir(&ddrkid_npc, UP);
		ddrkid_npc->animation_off=1;
		//ddrkid_npc->layer=3;
	}
	else if(ddrkid_npc!=NULL)
	{
		static int dir=0;
		if(dir==0){if(NPC_walk_to_xy_nohit(&ddrkid_npc,SPEED_SLOW+(r(SPEED_SLOW-SPEED_FAST)),68*8,14*8)==(1))dir=r(4);}
		if(dir==1){if(NPC_walk_to_xy_nohit(&ddrkid_npc,SPEED_SLOW+(r(SPEED_SLOW-SPEED_FAST)),74*8,14*8)==(1))dir=r(4);}
		if(dir==2){if(NPC_walk_to_xy_nohit(&ddrkid_npc,SPEED_SLOW+(r(SPEED_SLOW-SPEED_FAST)),68*8,12*8)==(1))dir=r(4);}
		if(dir==3){if(NPC_walk_to_xy_nohit(&ddrkid_npc,SPEED_SLOW+(r(SPEED_SLOW-SPEED_FAST)),74*8,12*8)==(1))dir=r(4);}
		if(ddrkid_npc->vbls>ddrkid_npc->walking_speed/64)
		{
			ddrkid_npc->vbls=0;
			NPC_animate_dir(&ddrkid_npc,UP);
		}
	}
	static NPC* arcade_npcs[6] = {NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<6;c++)
	{
		if(arcade_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			if(c== 0){x=85*8+4;y=18*8;dir=UP;bgp=1;}//basketball game
			if(c== 1){x=54*8;y=24*8;dir=UP;}//coin pusher
			if(c== 2){x=65*8;y=25*8;dir=DOWN;}//claw game
			if(c== 3){x=63*8;y=13*8;dir=UP;}//big arcade game
			if(c== 4){x=47*8+4;y=12*8;dir=UP;}//classic arcade game
			if(c== 5){x=33*8;y=13*8-3;dir=UP;bgp=3;}//driving game
			NPC_create_random_ADULT_OR_CHILD_xy_feet(&arcade_npcs[c],x,(y)+3);
			NPC_animate_stand_dir(&arcade_npcs[c], dir);
			arcade_npcs[c]->non_walkable=1;
			//arcade_npcs[c]->pushable=1;
			arcade_npcs[c]->walk_dir=dir;
			arcade_npcs[c]->layer=bgp;
		}
		if(arcade_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&arcade_npcs[c],12))NPC_stare_at_npc(&arcade_npcs[c],&PLAYER_npc);
			else NPC_animate_stand_dir(&arcade_npcs[c], arcade_npcs[c]->walk_dir);
		}
	}
		if(walking_into_door(RANGE_TOWNArcadeToOutside))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,1279,263);return;
	}
}
void bobsgame_TOWNArcade_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNArcade_Map_VBL_Function()
{

}

void bobsgame_TOWNArcade_Map_HBL_Function()
{

}



