//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"



#define RANGE_TOWNGroceryStoreToOUTSIDETownLeftExit 11*8,89*8,19*8,90*8
#define RANGE_TOWNGroceryStoreToOUTSIDETownRightEntrance 73*8,89*8,81*8,90*8




//========================================================
//TOWNGroceryStore
//========================================================
void bobsgame_TOWNGroceryStore_Map_Load_Function()
{
//RANGE_TOWNGroceryStoreToOUTSIDETownLeftExit 11*8,89*8,19*8,90*8
//RANGE_TOWNGroceryStoreToOUTSIDETownRightEntrance 73*8,89*8,81*8,90*8
}

void bobsgame_TOWNGroceryStore_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	//shoppers come in at 77,88
	//path 1
	//76,81 105,81 104,55 97,42 95,25 74,23 69,18 7,17 7,38 19,38 19,53 50,56 52,72 right, stand, 51,82 15,82 15,89 delete
	//71,56 71,19 60,19 60,53 40,53 39,19 18,19 19,55 21,69 face right pause, 15,89 delete
	//72,70 61,70, 60,52 40,52 39,18 30,18 30,53 7,57 7,18 40,18 42,73 pause face right, 39,82 14,83 15,89 delete
	//clerk at 25,69 face up
	//35,69
	//46,69 face up
	//55,69
		//104,27 face left meat counter
	//100,22 101,37 meat range
		static NPC* deliguy_npc = NULL;
	if(deliguy_npc==NULL)
	{
		NPC_create_npc_xy_feet(&deliguy_npc,GFX_ADULT_deliicecreamman,16,40,104*8,27*8);
		deliguy_npc->non_walkable=1;
		deliguy_npc->pushable=1;
		deliguy_npc->layer=1;
	}
	else if(deliguy_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&deliguy_npc,60))NPC_stare_at_npc(&deliguy_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&deliguy_npc, LEFT);
		if(ACTION_range_xy_xy(100*8,22*8,101*8,37*8,"Buy Meat"))
		{
			TEXT_set_sprite_window(0,deliguy_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);//TODO: buy meat
		}
	}
	static NPC* groceryclerks_npcs[4] = {NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<4;c++)
	{
		if(groceryclerks_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			if(c== 0){x=26*8;y=69*8;dir=UP;}
			if(c== 1){x=36*8;y=69*8;dir=UP;}
			if(c== 2){x=46*8;y=69*8;dir=UP;}
			if(c== 3){x=56*8;y=69*8;dir=UP;}
			NPC_create_random_ADULT_xy_feet(&groceryclerks_npcs[c],x,(y)+3);
			NPC_animate_stand_dir(&groceryclerks_npcs[c], dir);
			groceryclerks_npcs[c]->non_walkable=1;
			groceryclerks_npcs[c]->walk_dir=dir;
			groceryclerks_npcs[c]->layer=bgp;
		}
		else if(groceryclerks_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&groceryclerks_npcs[c],60)&&PLAYER_npc->MAP_x<groceryclerks_npcs[c]->MAP_x)NPC_stare_at_npc(&groceryclerks_npcs[c],&PLAYER_npc);
			else NPC_animate_stand_dir(&groceryclerks_npcs[c], groceryclerks_npcs[c]->walk_dir);
		}
		//TODO: buy groceries.
		//TODO: animate stuff going down the checkout.
	}
	static NPC* grocery_npcs[35] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	for(c=0;c<35;c++)
	{
		if(grocery_npcs[c]==NULL&&CLOCK_second/10==c%6)
		{
			NPC_create_random_ADULT_xy_feet(&grocery_npcs[c],77*8,88*8);
			grocery_npcs[c]->non_walkable=1;
			grocery_npcs[c]->AI=1;
			grocery_npcs[c]->walking_speed=SPEED_NORMAL+r(SPEED_SLOW-SPEED_FASTEST);
			grocery_npcs[c]->ignore_fx_layer=1;
		}
		if(grocery_npcs[c]!=NULL)
		{
			if(c%3==0)
			{
				if(grocery_npcs[c]->AI== 1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 76*8,81*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI== 2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed,105*8,81*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI== 3)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed,104*8,55*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI== 4)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 97*8,42*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI== 5)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 95*8,25*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI== 6)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 74*8,23*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI== 7)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 69*8,18*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI== 8)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed,  7*8,17*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI== 9)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed,  7*8,38*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI==10)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 19*8,38*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI==11)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 19*8,53*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI==12)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 50*8,56*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI==13)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 52*8,72*8)==(1)){grocery_npcs[c]->AI++;NPC_animate_stand_dir(&grocery_npcs[c], RIGHT);grocery_npcs[c]->vbls=0;}
				if(grocery_npcs[c]->AI==14)if(grocery_npcs[c]->vbls>120)grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI==15)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 51*8,82*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI==16)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 15*8,82*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI==17)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 15*8,88*8)==(1)){NPC_delete_npc(&grocery_npcs[c]);}
			}
			if(c%3==1)
			{
				if(grocery_npcs[c]->AI== 1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 71*8,56*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI== 2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 71*8,19*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI== 3)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 60*8,19*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI== 4)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 60*8,53*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI== 5)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 40*8,53*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI== 6)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 39*8,19*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI== 7)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 18*8,19*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI== 8)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 19*8,55*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI== 9)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 22*8,69*8)==(1)){grocery_npcs[c]->AI++;NPC_animate_stand_dir(&grocery_npcs[c], RIGHT);grocery_npcs[c]->vbls=0;}
				if(grocery_npcs[c]->AI==10)if(grocery_npcs[c]->vbls>120)grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI==11)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 15*8,88*8)==(1)){NPC_delete_npc(&grocery_npcs[c]);}
			}
			if(c%3==2)
			{
				if(grocery_npcs[c]->AI== 1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 72*8,70*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI== 2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 61*8,70*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI== 3)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 60*8,52*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI== 4)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 40*8,52*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI== 5)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 39*8,18*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI== 6)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 30*8,18*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI== 7)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 30*8,53*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI== 8)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed,  7*8,57*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI== 9)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed,  7*8,18*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI==10)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 40*8,18*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI==11)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 42*8,73*8)==(1)){grocery_npcs[c]->AI++;NPC_animate_stand_dir(&grocery_npcs[c], RIGHT);grocery_npcs[c]->vbls=0;}
				if(grocery_npcs[c]->AI==12)if(grocery_npcs[c]->vbls>120)grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI==13)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 39*8,82*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI==14)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 14*8,83*8)==(1))grocery_npcs[c]->AI++;
				if(grocery_npcs[c]->AI==15)if(grocery_npcs[c]->MAP_y>83*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&grocery_npcs[c],grocery_npcs[c]->walking_speed, 15*8,88*8)==(1)){NPC_delete_npc(&grocery_npcs[c]);}
			}
		}
	}
		if(walking_into_door(RANGE_TOWNGroceryStoreToOUTSIDETownLeftExit))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,1058,230);return;
	}
	if(walking_into_door(RANGE_TOWNGroceryStoreToOUTSIDETownRightEntrance))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,1120,230);return;
	}
}
void bobsgame_TOWNGroceryStore_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNGroceryStore_Map_VBL_Function()
{

}

void bobsgame_TOWNGroceryStore_Map_HBL_Function()
{

}


