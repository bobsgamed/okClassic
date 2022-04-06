//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================




#include "../../main.h"





#define RANGE_TOWNGasStationToOutside 12*8,42*8,20*8,43*8


//========================================================
//TOWNGasStation
//========================================================
void bobsgame_TOWNGasStation_Map_Load_Function()
{
//RANGE_TOWNGasStationToOutside 12*8,42*8,20*8,43*8
}

void bobsgame_TOWNGasStation_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//9,28 clerk face down
//5,13 up grinders guy looking at meat?
//49 13 up cooler guy
	static NPC* gasstationclerk_npc = NULL;
	if(gasstationclerk_npc==NULL)
	{
		NPC_create_npc_xy_feet(&gasstationclerk_npc,GFX_ADULT_GENERICwomanbun,16,40,10*8,27*8);
		gasstationclerk_npc->non_walkable=1;
		gasstationclerk_npc->pushable=1;
		gasstationclerk_npc->layer=3;
	}
	else if(gasstationclerk_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&gasstationclerk_npc,60))NPC_stare_at_npc(&gasstationclerk_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&gasstationclerk_npc, DOWN);
		if(ACTION_range_xy_xy(5*8,23*8,13*8,32*8,"Buy Expired Balogna"))
		{
			TEXT_set_sprite_window(0,gasstationclerk_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);//TODO: buy balogna
		}
	}
	static NPC* grinderguy_npc = NULL;
	if(grinderguy_npc==NULL)
	{
		NPC_create_npc_xy_feet(&grinderguy_npc,GFX_ADULT_GENERICwomanbun,16,40,5*8,13*8);
		grinderguy_npc->non_walkable=1;
		//grinderguy_npc->pushable=1;
		grinderguy_npc->layer=2;
	}
	else if(grinderguy_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&grinderguy_npc,16))NPC_stare_at_npc(&grinderguy_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&grinderguy_npc, UP);
		if(ACTION_npc(&grinderguy_npc,"Talk To Hungry Customer"))
		{
			TEXT_set_sprite_window(0,grinderguy_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);//TODO: get balogna, cant leave unless buy it or put it back
		}
	}
		static NPC* coolerguy_npc = NULL;
	if(coolerguy_npc==NULL)
	{
		NPC_create_npc_xy_feet(&coolerguy_npc,GFX_ADULT_GENERICwomanbun,16,40,49*8,13*8+4);
		coolerguy_npc->non_walkable=1;
		//coolerguy_npc->pushable=1;
		coolerguy_npc->layer=2;
	}
	else if(coolerguy_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&coolerguy_npc,16))NPC_stare_at_npc(&coolerguy_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&coolerguy_npc, UP);
		if(ACTION_npc(&coolerguy_npc,"Talk To Thirsty Customer"))
		{
			TEXT_set_sprite_window(0,coolerguy_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	//path 1
//door 16,41
//18,28 19,12up wait 14,26 face left wait
//19,35 27 38 down wait 37,38 38,25 right wait 36,13 up wait 17,17 14,26 face left wait
//17,35 23,16 41,13 50,16 49,34 face left wait 49,40 30,40 28,36 18,36 14,26 face left wait
//14,41 leave
	static NPC* gasstation_npcs[10] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<10;c++)
	{
		if(gasstation_npcs[c]==NULL&&CLOCK_second/10==c%6)
		{
			NPC_create_random_ADULT_xy_feet(&gasstation_npcs[c],16*8,41*8);
			gasstation_npcs[c]->non_walkable=1;
			gasstation_npcs[c]->AI=1;
			gasstation_npcs[c]->walking_speed=SPEED_NORMAL+r(SPEED_SLOW-SPEED_FASTEST);
			gasstation_npcs[c]->ignore_fx_layer=1;
		}
		if(gasstation_npcs[c]!=NULL)
		{
			if(c%3==0)
			{
				if(gasstation_npcs[c]->AI== 1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&gasstation_npcs[c],gasstation_npcs[c]->walking_speed, 18*8,28*8)==(1))gasstation_npcs[c]->AI++;
				if(gasstation_npcs[c]->AI== 2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&gasstation_npcs[c],gasstation_npcs[c]->walking_speed, 19*8,12*8)==(1)){gasstation_npcs[c]->AI++;NPC_animate_stand_dir(&gasstation_npcs[c], UP);gasstation_npcs[c]->vbls=0;}
				if(gasstation_npcs[c]->AI== 3)if(gasstation_npcs[c]->vbls>120)gasstation_npcs[c]->AI++;
				if(gasstation_npcs[c]->AI== 4)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&gasstation_npcs[c],gasstation_npcs[c]->walking_speed, 15*8,26*8)==(1)){gasstation_npcs[c]->AI++;NPC_animate_stand_dir(&gasstation_npcs[c], LEFT);gasstation_npcs[c]->vbls=0;}
				if(gasstation_npcs[c]->AI== 5)if(gasstation_npcs[c]->vbls>120)gasstation_npcs[c]->AI++;
				if(gasstation_npcs[c]->AI== 6)if(NPC_walk_to_xy_basichit(&gasstation_npcs[c],gasstation_npcs[c]->walking_speed, 14*8,41*8)==(1)){NPC_delete_npc(&gasstation_npcs[c]);}
			}
			if(c%3==1)
			{
				if(gasstation_npcs[c]->AI== 1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&gasstation_npcs[c],gasstation_npcs[c]->walking_speed, 19*8,35*8)==1)gasstation_npcs[c]->AI++;
				if(gasstation_npcs[c]->AI== 2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&gasstation_npcs[c],gasstation_npcs[c]->walking_speed, 27*8,37*8)==1){gasstation_npcs[c]->AI++;NPC_animate_stand_dir(&gasstation_npcs[c], DOWN);gasstation_npcs[c]->vbls=0;}
				if(gasstation_npcs[c]->AI== 3)if(gasstation_npcs[c]->vbls>120)gasstation_npcs[c]->AI++;
				if(gasstation_npcs[c]->AI== 4)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&gasstation_npcs[c],gasstation_npcs[c]->walking_speed, 37*8,38*8)==1)gasstation_npcs[c]->AI++;
				if(gasstation_npcs[c]->AI== 5)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&gasstation_npcs[c],gasstation_npcs[c]->walking_speed, 38*8,25*8)==1){gasstation_npcs[c]->AI++;NPC_animate_stand_dir(&gasstation_npcs[c], RIGHT);gasstation_npcs[c]->vbls=0;}
				if(gasstation_npcs[c]->AI== 6)if(gasstation_npcs[c]->vbls>120)gasstation_npcs[c]->AI++;
				if(gasstation_npcs[c]->AI== 7)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&gasstation_npcs[c],gasstation_npcs[c]->walking_speed, 36*8,13*8)==1){gasstation_npcs[c]->AI++;NPC_animate_stand_dir(&gasstation_npcs[c], UP);gasstation_npcs[c]->vbls=0;}
				if(gasstation_npcs[c]->AI== 8)if(gasstation_npcs[c]->vbls>120)gasstation_npcs[c]->AI++;
				if(gasstation_npcs[c]->AI== 9)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&gasstation_npcs[c],gasstation_npcs[c]->walking_speed, 17*8,17*8)==1)gasstation_npcs[c]->AI++;
				if(gasstation_npcs[c]->AI==10)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&gasstation_npcs[c],gasstation_npcs[c]->walking_speed, 15*8,26*8)==1){gasstation_npcs[c]->AI++;NPC_animate_stand_dir(&gasstation_npcs[c], LEFT);gasstation_npcs[c]->vbls=0;}
				if(gasstation_npcs[c]->AI==11)if(gasstation_npcs[c]->vbls>120)gasstation_npcs[c]->AI++;
				if(gasstation_npcs[c]->AI==12)if(NPC_walk_to_xy_basichit(&gasstation_npcs[c],gasstation_npcs[c]->walking_speed, 14*8,41*8)==(1)){NPC_delete_npc(&gasstation_npcs[c]);}
			}
			if(c%3==2)
			{
				if(gasstation_npcs[c]->AI== 1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&gasstation_npcs[c],gasstation_npcs[c]->walking_speed, 17*8,35*8)==1)gasstation_npcs[c]->AI++;
				if(gasstation_npcs[c]->AI== 2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&gasstation_npcs[c],gasstation_npcs[c]->walking_speed, 23*8,16*8)==1)gasstation_npcs[c]->AI++;
				if(gasstation_npcs[c]->AI== 3)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&gasstation_npcs[c],gasstation_npcs[c]->walking_speed, 41*8,13*8)==1)gasstation_npcs[c]->AI++;
				if(gasstation_npcs[c]->AI== 4)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&gasstation_npcs[c],gasstation_npcs[c]->walking_speed, 50*8,16*8)==1)gasstation_npcs[c]->AI++;
				if(gasstation_npcs[c]->AI== 5)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&gasstation_npcs[c],gasstation_npcs[c]->walking_speed, 50*8,34*8)==1){gasstation_npcs[c]->AI++;NPC_animate_stand_dir(&gasstation_npcs[c], LEFT);gasstation_npcs[c]->vbls=0;}
				if(gasstation_npcs[c]->AI== 6)if(gasstation_npcs[c]->vbls>120)gasstation_npcs[c]->AI++;
				if(gasstation_npcs[c]->AI== 7)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&gasstation_npcs[c],gasstation_npcs[c]->walking_speed, 50*8,40*8)==1)gasstation_npcs[c]->AI++;
				if(gasstation_npcs[c]->AI== 8)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&gasstation_npcs[c],gasstation_npcs[c]->walking_speed, 30*8,40*8)==1)gasstation_npcs[c]->AI++;
				if(gasstation_npcs[c]->AI== 9)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&gasstation_npcs[c],gasstation_npcs[c]->walking_speed, 28*8,36*8)==1)gasstation_npcs[c]->AI++;
				if(gasstation_npcs[c]->AI==10)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&gasstation_npcs[c],gasstation_npcs[c]->walking_speed, 18*8,36*8)==1)gasstation_npcs[c]->AI++;
				if(gasstation_npcs[c]->AI==11)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&gasstation_npcs[c],gasstation_npcs[c]->walking_speed, 15*8,26*8)==(1)){gasstation_npcs[c]->AI++;NPC_animate_stand_dir(&gasstation_npcs[c], LEFT);gasstation_npcs[c]->vbls=0;}
				if(gasstation_npcs[c]->AI==12)if(gasstation_npcs[c]->vbls>120)gasstation_npcs[c]->AI++;
				if(gasstation_npcs[c]->AI==13)if(NPC_walk_to_xy_basichit(&gasstation_npcs[c],gasstation_npcs[c]->walking_speed, 14*8,41*8)==(1)){NPC_delete_npc(&gasstation_npcs[c]);}
			}
		}
	}
	if(walking_into_door(RANGE_TOWNGasStationToOutside))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,713,227);return;return;
	}
	}

void bobsgame_TOWNGasStation_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNGasStation_Map_VBL_Function()
{

}

void bobsgame_TOWNGasStation_Map_HBL_Function()
{

}


