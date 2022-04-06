//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================




#include "../../main.h"


#define RANGE_CITYFancyRestaurantEntranceToOUTSIDECity 27*8,25*8,35*8,26*8
#define RANGE_CITYFancyRestaurantEntranceToFancyRestaurant 12*8,8*8,18*8,9*8
#define RANGE_CITYFancyRestaurantToEntrance 12*8,67*8,18*8,68*8
#define RANGE_CITYFancyRestaurantToKitchen 43*8,16*8,51*8,17*8
#define RANGE_CITYFancyRestaurantKitchenToFancyRestaurant 19*8,32*8,27*8,33*8
#define RANGE_CITYFancyRestaurantKitchenToFreezer 4*8,9*8,8*8,10*8
#define RANGE_CITYFancyRestaurantKitchenFreezerToKitchen 3*8,16*8,7*8,17*8


//========================================================
//CITYFancyRestaurantEntrance
//========================================================
void bobsgame_CITYFancyRestaurantEntrance_Map_Load_Function()
{
//RANGE_CITYFancyRestaurantEntranceToOUTSIDECity 27*8,25*8,35*8,26*8
//RANGE_CITYFancyRestaurantEntranceToFancyRestaurant 12*8,8*8,18*8,9*8
}
void bobsgame_CITYFancyRestaurantEntrance_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//22,17 face right

	static NPC* host_npc = NULL;
	if(host_npc==NULL)
	{
		NPC_create_npc_xy_feet(&host_npc,GFX_ADULT_GENERICbaldsuitguy,16,40,22*8,17*8);
		host_npc->layer=2;
		host_npc->non_walkable=1;
		NPC_animate_stand_dir(&host_npc,RIGHT);
	}
	else if(host_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&host_npc,30))NPC_stare_at_npc(&host_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&host_npc, RIGHT);
		if(ACTION_range_xy_xy(22*8,17*8,24*8,19*8,"Talk To Host"))
		{
			TEXT_set_sprite_window(0,host_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	//TODO: not allowed in unless you have a table. maybe have him bring you to your table?
	//12,10-17,10
//4,17 face right
	static NPC* checkout_npc = NULL;
	if(checkout_npc==NULL)
	{
		NPC_create_npc_xy_feet(&checkout_npc,GFX_ADULT_GENERICmangrayhairsuit,16,40,6*8-4,17*8);
		checkout_npc->layer=3;
		NPC_animate_stand_dir(&checkout_npc,RIGHT);
	}
	else if(checkout_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&checkout_npc,30))NPC_stare_at_npc(&checkout_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&checkout_npc, RIGHT);
		if(ACTION_range_xy_xy(7*8,14*8,8*8,18*8,"Pay Bill"))
		{
			TEXT_set_sprite_window(0,checkout_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
//TODO: buy breath mints?

//TODO: need waiter sprite male and female with tray and without tray?

	if(walking_into_door(RANGE_CITYFancyRestaurantEntranceToOUTSIDECity))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,1503,38);return;
	}
	if(walking_into_door(RANGE_CITYFancyRestaurantEntranceToFancyRestaurant))
	{
		MAP_change_map(MAP_bobsgame_CITYFancyRestaurant,14,65);return;
	}
}
void bobsgame_CITYFancyRestaurantEntrance_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYFancyRestaurantEntrance_Map_VBL_Function()
{

}
void bobsgame_CITYFancyRestaurantEntrance_Map_HBL_Function()
{

}
//========================================================
//CITYFancyRestaurant
//========================================================
void bobsgame_CITYFancyRestaurant_Map_Load_Function()
{
//RANGE_CITYFancyRestaurantToEntrance 12*8,67*8,18*8,68*8
//RANGE_CITYFancyRestaurantToKitchen 43*8,16*8,51*8,17*8
}
void bobsgame_CITYFancyRestaurant_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
	static NPC* restaurant_npcs[23] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<23;c++)
	{
		if(restaurant_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			//int* gfx=NULL;
			if(c== 0){x= 6*8-2;y=30*8;dir=RIGHT;}
			if(c== 1){x=12*8+2;y=30*8;dir=LEFT;}
			if(c== 2){x=18*8-2;y=30*8;dir=RIGHT;}
			if(c== 3){x=24*8+2;y=30*8;dir=LEFT;}
			if(c== 4){x=46*8-2;y=30*8;dir=RIGHT;}
			if(c== 5){x=52*8+2;y=30*8;dir=LEFT;}
			if(c== 6){x= 6*8-2;y=41*8;dir=RIGHT;}
			if(c== 7){x=12*8+2;y=41*8;dir=LEFT;}
			if(c== 8){x=18*8-2;y=41*8;dir=RIGHT;}
			if(c== 9){x=24*8+2;y=41*8;dir=LEFT;}
			if(c==10){x=46*8-2;y=41*8;dir=RIGHT;}
			if(c==11){x=52*8+2;y=41*8;dir=LEFT;}

			if(c==12){x= 6*8-2;y=52*8;dir=RIGHT;}
			if(c==13){x=12*8+2;y=52*8;dir=LEFT;}
			if(c==14){x=18*8-2;y=52*8;dir=RIGHT;}
			if(c==15){x=24*8+2;y=52*8;dir=LEFT;}
			if(c==16){x=46*8-2;y=52*8;dir=RIGHT;}
			if(c==17){x=52*8+2;y=52*8;dir=LEFT;}

			if(c==18){x= 4*8;y=19*8+2;dir=UP;}
			if(c==19){x= 8*8;y=19*8+2;dir=UP;}
			if(c==20){x=12*8;y=19*8+2;dir=UP;}
			if(c==21){x=16*8;y=19*8+2;dir=UP;}
			if(c==22){x=20*8;y=19*8+2;dir=UP;}
			NPC_create_random_ADULT_xy_feet(&restaurant_npcs[c],x,(y)+3);

			//NPC_create_npc_xy_feet(&restaurant_npcs[c],gfx,16,40,x,(y));
			NPC_animate_stand_dir(&restaurant_npcs[c], dir);
			restaurant_npcs[c]->non_walkable=1;
			restaurant_npcs[c]->walk_dir=dir;
			restaurant_npcs[c]->layer=bgp;
		}
		if(restaurant_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&restaurant_npcs[c],15))NPC_stare_at_npc(&restaurant_npcs[c],&PLAYER_npc);
			else NPC_animate_stand_dir(&restaurant_npcs[c], restaurant_npcs[c]->walk_dir);
		}
	}
//waitresses?
//47,18 down from kitchen
//48,28 down wait
//37 19 coffee wait
//55,26
//55,36
//49,39 down wait
//49 37
//55.37
//55,48
//49,50 down wait
//42,46
//42,61
//36 61
//36 25
//40,19 up wait
//47 18 kitchen disappear
	static NPC* waiter1_npc = NULL;
	if(waiter1_npc==NULL&&CLOCK_minute%3==1)
	{
		NPC_create_npc_xy_feet(&waiter1_npc,GFX_ADULT_GENERICmanlongsleeves,16,40,47*8,18*8);
		waiter1_npc->layer=2;
		waiter1_npc->non_walkable=1;
		NPC_animate_stand_dir(&waiter1_npc,DOWN);
		waiter1_npc->walking_speed = SPEED_NORMAL+r(SPEED_SLOWEST-SPEED_FASTEST);
	}
	if(waiter1_npc!=NULL)
	{
		if(waiter1_npc->AI== 0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter1_npc,waiter1_npc->walking_speed,50*8,26*8)==(1))waiter1_npc->AI++;
		if(waiter1_npc->AI== 1)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter1_npc,waiter1_npc->walking_speed,37*8,19*8)==(1)){waiter1_npc->AI++;waiter1_npc->vbls=0;NPC_animate_stand_dir(&waiter1_npc,DOWN);}
		if(waiter1_npc->AI== 2)if(waiter1_npc->vbls>120)waiter1_npc->AI++;
		if(waiter1_npc->AI== 3)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter1_npc,waiter1_npc->walking_speed,55*8,26*8)==(1))waiter1_npc->AI++;
		if(waiter1_npc->AI== 4)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter1_npc,waiter1_npc->walking_speed,55*8,36*8)==(1))waiter1_npc->AI++;
		if(waiter1_npc->AI== 5)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter1_npc,waiter1_npc->walking_speed,49*8,36*8)==(1)){waiter1_npc->AI++;waiter1_npc->vbls=0;NPC_animate_stand_dir(&waiter1_npc,DOWN);}
		if(waiter1_npc->AI== 6)if(waiter1_npc->vbls>120)waiter1_npc->AI++;
		if(waiter1_npc->AI== 7)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter1_npc,waiter1_npc->walking_speed,49*8,37*8)==(1))waiter1_npc->AI++;
		if(waiter1_npc->AI== 8)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter1_npc,waiter1_npc->walking_speed,55*8,37*8)==(1))waiter1_npc->AI++;
		if(waiter1_npc->AI== 9)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter1_npc,waiter1_npc->walking_speed,55*8,47*8)==(1))waiter1_npc->AI++;
		if(waiter1_npc->AI==10)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter1_npc,waiter1_npc->walking_speed,49*8,47*8)==(1))waiter1_npc->AI++;
		if(waiter1_npc->AI==11)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter1_npc,waiter1_npc->walking_speed,49*8,49*8)==(1)){waiter1_npc->AI++;waiter1_npc->vbls=0;NPC_animate_stand_dir(&waiter1_npc,DOWN);}
		if(waiter1_npc->AI==12)if(waiter1_npc->vbls>120)waiter1_npc->AI++;
		if(waiter1_npc->AI==13)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter1_npc,waiter1_npc->walking_speed,43*8,47*8)==(1))waiter1_npc->AI++;
		if(waiter1_npc->AI==14)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter1_npc,waiter1_npc->walking_speed,43*8,61*8)==(1))waiter1_npc->AI++;
		if(waiter1_npc->AI==15)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter1_npc,waiter1_npc->walking_speed,36*8,61*8)==(1))waiter1_npc->AI++;
		if(waiter1_npc->AI==16)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter1_npc,waiter1_npc->walking_speed,36*8,25*8)==(1))waiter1_npc->AI++;
		if(waiter1_npc->AI==17)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter1_npc,waiter1_npc->walking_speed,40*8,19*8)==(1)){waiter1_npc->AI++;waiter1_npc->vbls=0;NPC_animate_stand_dir(&waiter1_npc,UP);}
		if(waiter1_npc->AI==18)if(waiter1_npc->vbls>120)waiter1_npc->AI++;
		if(waiter1_npc->AI==19)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter1_npc,waiter1_npc->walking_speed,47*8,18*8)==(1))NPC_delete_npc(&waiter1_npc);
	}
//47,18 down from kitchen
//44 25
//21,25
//20,28 down wait
//20,25
//27,25
//27 36
//21 36
//21 39 down wait
//21 36
//27 36
//27 48
//20 48
//20 50 down wait
//20 47
//27 48
//27 60
//35 60
//35 24
//47 25
//47 18 kitchen disappear
	static NPC* waiter2_npc = NULL;
	if(waiter2_npc==NULL&&CLOCK_minute%3==0)
	{
		NPC_create_npc_xy_feet(&waiter2_npc,GFX_ADULT_GENERICmanlongsleeves,16,40,47*8,18*8);
		waiter2_npc->AI=0;
		waiter2_npc->walking_speed = SPEED_NORMAL+r(SPEED_SLOWEST-SPEED_FASTEST);
		waiter2_npc->layer=2;
		waiter2_npc->non_walkable=1;
		NPC_animate_stand_dir(&waiter2_npc,DOWN);
	}
	if(waiter2_npc!=NULL)
	{
		if(waiter2_npc->AI== 0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter2_npc,waiter2_npc->walking_speed,44*8,25*8)==(1))waiter2_npc->AI++;
		if(waiter2_npc->AI== 1)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter2_npc,waiter2_npc->walking_speed,20*8,25*8)==(1))waiter2_npc->AI++;
		if(waiter2_npc->AI== 2)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter2_npc,waiter2_npc->walking_speed,20*8,27*8)==(1)){waiter2_npc->AI++;waiter2_npc->vbls=0;NPC_animate_stand_dir(&waiter2_npc,DOWN);}
		if(waiter2_npc->AI== 3)if(waiter2_npc->vbls>120)waiter2_npc->AI++;
		if(waiter2_npc->AI== 4)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter2_npc,waiter2_npc->walking_speed,20*8,25*8)==(1))waiter2_npc->AI++;
		if(waiter2_npc->AI== 5)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter2_npc,waiter2_npc->walking_speed,27*8,25*8)==(1))waiter2_npc->AI++;
		if(waiter2_npc->AI== 6)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter2_npc,waiter2_npc->walking_speed,27*8,36*8)==(1))waiter2_npc->AI++;
		if(waiter2_npc->AI== 7)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter2_npc,waiter2_npc->walking_speed,21*8,36*8)==(1))waiter2_npc->AI++;
		if(waiter2_npc->AI== 8)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter2_npc,waiter2_npc->walking_speed,21*8,38*8)==(1)){waiter2_npc->AI++;waiter2_npc->vbls=0;NPC_animate_stand_dir(&waiter2_npc,DOWN);}
		if(waiter2_npc->AI== 9)if(waiter2_npc->vbls>120)waiter2_npc->AI++;
		if(waiter2_npc->AI==10)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter2_npc,waiter2_npc->walking_speed,21*8,36*8)==(1))waiter2_npc->AI++;
		if(waiter2_npc->AI==11)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter2_npc,waiter2_npc->walking_speed,27*8,36*8)==(1))waiter2_npc->AI++;
		if(waiter2_npc->AI==12)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter2_npc,waiter2_npc->walking_speed,27*8,47*8)==(1))waiter2_npc->AI++;
		if(waiter2_npc->AI==13)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter2_npc,waiter2_npc->walking_speed,20*8,47*8)==(1))waiter2_npc->AI++;
		if(waiter2_npc->AI==14)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter2_npc,waiter2_npc->walking_speed,20*8,49*8)==(1)){waiter2_npc->AI++;waiter2_npc->vbls=0;NPC_animate_stand_dir(&waiter2_npc,DOWN);}
		if(waiter2_npc->AI==15)if(waiter2_npc->vbls>120)waiter2_npc->AI++;
		if(waiter2_npc->AI==16)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter2_npc,waiter2_npc->walking_speed,20*8,47*8)==(1))waiter2_npc->AI++;
		if(waiter2_npc->AI==17)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter2_npc,waiter2_npc->walking_speed,27*8,47*8)==(1))waiter2_npc->AI++;
		if(waiter2_npc->AI==18)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter2_npc,waiter2_npc->walking_speed,27*8,60*8)==(1))waiter2_npc->AI++;
		if(waiter2_npc->AI==19)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter2_npc,waiter2_npc->walking_speed,35*8,60*8)==(1))waiter2_npc->AI++;
		if(waiter2_npc->AI==20)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter2_npc,waiter2_npc->walking_speed,35*8,24*8)==(1))waiter2_npc->AI++;
		if(waiter2_npc->AI==21)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter2_npc,waiter2_npc->walking_speed,47*8,24*8)==(1))waiter2_npc->AI++;
		if(waiter2_npc->AI==22)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter2_npc,waiter2_npc->walking_speed,47*8,18*8)==(1))NPC_delete_npc(&waiter2_npc);
	}

//47,18 down from kitchen
//44 25
//31,25
//30,19 up coffee
//29,24
//8 25
//8 28 down wait
//8 25
//2 27
//2 37
//9 37
//9 39 down wait
//9 37
//2 37
//2 48
//8 48
//8 50 down wait
//8 48
//2 48
//2 58
//35 60
//35 24
//47 25
//47 18 kitchen disappear
	static NPC* waiter3_npc = NULL;
	if(waiter3_npc==NULL&&CLOCK_minute%3==2)
	{
		NPC_create_npc_xy_feet(&waiter3_npc,GFX_ADULT_GENERICmanlongsleeves,16,40,47*8,18*8);
		waiter3_npc->layer=2;
		waiter3_npc->non_walkable=1;
		NPC_animate_stand_dir(&waiter3_npc,DOWN);
		waiter3_npc->walking_speed = SPEED_NORMAL+r(SPEED_SLOWEST-SPEED_FASTEST);
		waiter3_npc->AI=0;
	}
	if(waiter3_npc!=NULL)
	{
		if(waiter3_npc->AI== 0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter3_npc,waiter3_npc->walking_speed,44*8,25*8)==(1))waiter3_npc->AI++;
		if(waiter3_npc->AI== 1)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter3_npc,waiter3_npc->walking_speed,30*8,25*8)==(1))waiter3_npc->AI++;
		if(waiter3_npc->AI== 2)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter3_npc,waiter3_npc->walking_speed,30*8,19*8)==(1)){waiter3_npc->AI++;waiter3_npc->vbls=0;NPC_animate_stand_dir(&waiter3_npc,UP);}
		if(waiter3_npc->AI== 3)if(waiter3_npc->vbls>120)waiter3_npc->AI++;
		if(waiter3_npc->AI== 4)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter3_npc,waiter3_npc->walking_speed,30*8,25*8)==(1))waiter3_npc->AI++;
		if(waiter3_npc->AI== 5)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter3_npc,waiter3_npc->walking_speed, 8*8,25*8)==(1))waiter3_npc->AI++;
		if(waiter3_npc->AI== 6)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter3_npc,waiter3_npc->walking_speed, 8*8,27*8)==(1)){waiter3_npc->AI++;waiter3_npc->vbls=0;NPC_animate_stand_dir(&waiter3_npc,DOWN);}
		if(waiter3_npc->AI== 7)if(waiter3_npc->vbls>120)waiter3_npc->AI++;
		if(waiter3_npc->AI== 8)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter3_npc,waiter3_npc->walking_speed, 8*8,25*8)==(1))waiter3_npc->AI++;
		if(waiter3_npc->AI== 9)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter3_npc,waiter3_npc->walking_speed, 3*8,25*8)==(1))waiter3_npc->AI++;
		if(waiter3_npc->AI==10)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter3_npc,waiter3_npc->walking_speed, 3*8,36*8)==(1))waiter3_npc->AI++;
		if(waiter3_npc->AI==11)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter3_npc,waiter3_npc->walking_speed, 9*8,36*8)==(1))waiter3_npc->AI++;
		if(waiter3_npc->AI==12)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter3_npc,waiter3_npc->walking_speed, 9*8,38*8)==(1)){waiter3_npc->AI++;waiter3_npc->vbls=0;NPC_animate_stand_dir(&waiter3_npc,DOWN);}
		if(waiter3_npc->AI==13)if(waiter3_npc->vbls>120)waiter3_npc->AI++;
		if(waiter3_npc->AI==14)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter3_npc,waiter3_npc->walking_speed, 9*8,36*8)==(1))waiter3_npc->AI++;
		if(waiter3_npc->AI==15)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter3_npc,waiter3_npc->walking_speed, 3*8,36*8)==(1))waiter3_npc->AI++;
		if(waiter3_npc->AI==16)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter3_npc,waiter3_npc->walking_speed, 3*8,47*8)==(1))waiter3_npc->AI++;
		if(waiter3_npc->AI==17)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter3_npc,waiter3_npc->walking_speed, 8*8,47*8)==(1))waiter3_npc->AI++;
		if(waiter3_npc->AI==18)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter3_npc,waiter3_npc->walking_speed, 8*8,49*8)==(1)){waiter3_npc->AI++;waiter3_npc->vbls=0;NPC_animate_stand_dir(&waiter3_npc,DOWN);}
		if(waiter3_npc->AI==19)if(waiter3_npc->vbls>120)waiter3_npc->AI++;
		if(waiter3_npc->AI==20)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter3_npc,waiter3_npc->walking_speed, 8*8,48*8)==(1))waiter3_npc->AI++;
		if(waiter3_npc->AI==21)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter3_npc,waiter3_npc->walking_speed, 3*8,48*8)==(1))waiter3_npc->AI++;
		if(waiter3_npc->AI==22)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter3_npc,waiter3_npc->walking_speed, 3*8,58*8)==(1))waiter3_npc->AI++;
		if(waiter3_npc->AI==23)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter3_npc,waiter3_npc->walking_speed,35*8,58*8)==(1))waiter3_npc->AI++;
		if(waiter3_npc->AI==24)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter3_npc,waiter3_npc->walking_speed,35*8,25*8)==(1))waiter3_npc->AI++;
		if(waiter3_npc->AI==25)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter3_npc,waiter3_npc->walking_speed,47*8,25*8)==(1))waiter3_npc->AI++;
		if(waiter3_npc->AI==26)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&waiter3_npc,waiter3_npc->walking_speed,47*8,18*8)==(1))NPC_delete_npc(&waiter3_npc);
	}
//bartender
//2-20,14

	static NPC* bartender_npc = NULL;
	if(bartender_npc==NULL)
	{
		NPC_create_npc_xy_feet(&bartender_npc,GFX_ADULT_GENERICmanlongsleeves,16,40,2*8,14*8);
		bartender_npc->layer=3;
		//bartender_npc->non_walkable=1;
		NPC_animate_stand_dir(&bartender_npc,DOWN);
		bartender_npc->walking_speed = SPEED_NORMAL+r(SPEED_SLOWEST-SPEED_FASTEST);
		bartender_npc->AI=0;
	}
	if(bartender_npc!=NULL)
	{
		if(bartender_npc->AI== 0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bartender_npc,bartender_npc->walking_speed, 2*8,14*8)==(1))bartender_npc->AI=6;
		if(bartender_npc->AI== 1)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bartender_npc,bartender_npc->walking_speed, 5*8,14*8)==(1))bartender_npc->AI=6;
		if(bartender_npc->AI== 2)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bartender_npc,bartender_npc->walking_speed, 8*8,14*8)==(1))bartender_npc->AI=6;
		if(bartender_npc->AI== 3)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bartender_npc,bartender_npc->walking_speed,13*8,14*8)==(1))bartender_npc->AI=6;
		if(bartender_npc->AI== 4)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bartender_npc,bartender_npc->walking_speed,16*8,14*8)==(1))bartender_npc->AI=6;
		if(bartender_npc->AI== 5)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bartender_npc,bartender_npc->walking_speed,19*8,14*8)==(1))bartender_npc->AI=6;
		if(bartender_npc->AI== 6){bartender_npc->AI++;bartender_npc->vbls=0;NPC_animate_stand_dir(&bartender_npc,DOWN);}
		if(bartender_npc->AI== 7)if(bartender_npc->vbls>120)bartender_npc->AI=r(6);
	}

//TODO: waiter sprites
//TODO: violinist?
//TODO: need mafia guys?
	if(walking_into_door(RANGE_CITYFancyRestaurantToEntrance))
	{
		MAP_change_map(MAP_bobsgame_CITYFancyRestaurantEntrance,14,11);return;
	}
	if(walking_into_door(RANGE_CITYFancyRestaurantToKitchen))
	{
		MAP_change_map(MAP_bobsgame_CITYFancyRestaurantKitchen,22,31);return;
	}
}
void bobsgame_CITYFancyRestaurant_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYFancyRestaurant_Map_VBL_Function()
{

}
void bobsgame_CITYFancyRestaurant_Map_HBL_Function()
{

}
//========================================================
//CITYFancyRestaurantKitchen
//========================================================
void bobsgame_CITYFancyRestaurantKitchen_Map_Load_Function()
{
//RANGE_CITYFancyRestaurantKitchenToFancyRestaurant 19*8,32*8,27*8,33*8
//RANGE_CITYFancyRestaurantKitchenToFreezer 4*8,9*8,8*8,10*8
}
void bobsgame_CITYFancyRestaurantKitchen_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//TODO: need chef sprites make/female
//TODO: clanking plates, chopping noises.

//5,28 down cutting
//4,22 up stove
	static NPC* cook1_npc = NULL;
	if(cook1_npc==NULL)
	{
		NPC_create_npc_xy_feet(&cook1_npc,GFX_ADULT_GENERICmanlongsleeves,16,40,5*8,27*8);
		cook1_npc->layer=2;
		cook1_npc->non_walkable=1;
		NPC_animate_stand_dir(&cook1_npc,DOWN);
		cook1_npc->walking_speed = SPEED_NORMAL+r(SPEED_SLOWEST-SPEED_FASTEST);
		cook1_npc->AI=0;
	}
	if(cook1_npc!=NULL)
	{
		//TODO: for all walking npcs that you can talk to:  if in range of npcs, stop walking, face you, can talk to.
		//TODO: for standing/sitting npcs, need to have slight animations at random intervals. maybe look around too.
		if(cook1_npc->AI== 0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&cook1_npc,cook1_npc->walking_speed, 5*8,27*8)==(1)){cook1_npc->AI=2;cook1_npc->vbls=0;NPC_animate_stand_dir(&cook1_npc,DOWN);}
		if(cook1_npc->AI== 1)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&cook1_npc,cook1_npc->walking_speed, 4*8,22*8)==(1)){cook1_npc->AI=2;cook1_npc->vbls=0;NPC_animate_stand_dir(&cook1_npc,UP);}
		if(cook1_npc->AI== 2)if(cook1_npc->vbls>60)cook1_npc->AI=r(2);
	}
	//8 22 up oven
	//10,28 down cutting
	static NPC* cook2_npc = NULL;
	if(cook2_npc==NULL)
	{
		NPC_create_npc_xy_feet(&cook2_npc,GFX_ADULT_GENERICmanlongsleeves,16,40,10*8,27*8);
		cook2_npc->layer=2;
		cook2_npc->non_walkable=1;
		NPC_animate_stand_dir(&cook2_npc,DOWN);
		cook2_npc->walking_speed = SPEED_NORMAL+r(SPEED_SLOWEST-SPEED_FASTEST);
		cook2_npc->AI=0;
	}
	if(cook2_npc!=NULL)
	{
		if(cook2_npc->AI== 0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&cook2_npc,cook2_npc->walking_speed, 8*8,22*8)==(1)){cook2_npc->AI=2;cook2_npc->vbls=0;NPC_animate_stand_dir(&cook2_npc,UP);}
		if(cook2_npc->AI== 1)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&cook2_npc,cook2_npc->walking_speed, 10*8,27*8)==(1)){cook2_npc->AI=2;cook2_npc->vbls=0;NPC_animate_stand_dir(&cook2_npc,DOWN);}
		if(cook2_npc->AI== 2)if(cook2_npc->vbls>60)cook2_npc->AI=r(2);
	}
//12,12 up fridge
//14,25 right cutting

	static NPC* cook3_npc = NULL;
	if(cook3_npc==NULL)
	{
		NPC_create_npc_xy_feet(&cook3_npc,GFX_ADULT_GENERICmanlongsleeves,16,40,14*8,25*8);
		cook3_npc->layer=2;
		cook3_npc->non_walkable=1;
		NPC_animate_stand_dir(&cook3_npc,RIGHT);
		cook3_npc->walking_speed = SPEED_NORMAL+r(SPEED_SLOWEST-SPEED_FASTEST);
		cook3_npc->AI=0;
	}
	if(cook3_npc!=NULL)
	{
		if(cook3_npc->AI== 0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&cook3_npc,cook3_npc->walking_speed, 12*8,12*8)==(1)){cook3_npc->AI=2;cook3_npc->vbls=0;NPC_animate_stand_dir(&cook3_npc,UP);}
		if(cook3_npc->AI== 1)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&cook3_npc,cook3_npc->walking_speed, 14*8,25*8)==(1)){cook3_npc->AI=2;cook3_npc->vbls=0;NPC_animate_stand_dir(&cook3_npc,RIGHT);}
		if(cook3_npc->AI== 2)if(cook3_npc->vbls>60)cook3_npc->AI=r(2);
	}
//17,12 up microwave
//18 24 left cutting
//23,12 up sink
//26,21 right fridge

	static NPC* cook4_npc = NULL;
	if(cook4_npc==NULL)
	{
		NPC_create_npc_xy_feet(&cook4_npc,GFX_ADULT_GENERICmanlongsleeves,16,40,19*8,24*8);
		cook4_npc->layer=2;
		cook4_npc->non_walkable=1;
		NPC_animate_stand_dir(&cook4_npc,DOWN);
		cook4_npc->walking_speed = SPEED_NORMAL+r(SPEED_SLOWEST-SPEED_FASTEST);
		cook4_npc->AI=0;
	}
	if(cook4_npc!=NULL)
	{
		if(cook4_npc->AI== 0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&cook4_npc,cook4_npc->walking_speed, 23*8,12*8)==(1)){cook4_npc->AI=3;cook4_npc->vbls=0;NPC_animate_stand_dir(&cook4_npc,UP);}
		if(cook4_npc->AI== 1)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&cook4_npc,cook4_npc->walking_speed, 26*8,21*8)==(1)){cook4_npc->AI=3;cook4_npc->vbls=0;NPC_animate_stand_dir(&cook4_npc,RIGHT);}
		if(cook4_npc->AI== 2)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&cook4_npc,cook4_npc->walking_speed, 19*8,24*8)==(1)){cook4_npc->AI=3;cook4_npc->vbls=0;NPC_animate_stand_dir(&cook4_npc,LEFT);}
		if(cook4_npc->AI== 3)if(cook4_npc->vbls>60)cook4_npc->AI=r(3);
	}
	if(walking_into_door(RANGE_CITYFancyRestaurantKitchenToFancyRestaurant))
	{
		MAP_change_map(MAP_bobsgame_CITYFancyRestaurant,46,17);return;
	}
	if(walking_into_door(RANGE_CITYFancyRestaurantKitchenToFreezer))
	{
		MAP_change_map(MAP_bobsgame_CITYFancyRestaurantKitchenFreezer,5,15);return;
	}
}
void bobsgame_CITYFancyRestaurantKitchen_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYFancyRestaurantKitchen_Map_VBL_Function()
{

}
void bobsgame_CITYFancyRestaurantKitchen_Map_HBL_Function()
{

}
//========================================================
//CITYFancyRestaurantKitchenFreezer
//========================================================
void bobsgame_CITYFancyRestaurantKitchenFreezer_Map_Load_Function()
{
//RANGE_CITYFancyRestaurantKitchenFreezerToKitchen 3*8,16*8,7*8,17*8
}
void bobsgame_CITYFancyRestaurantKitchenFreezer_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//TODO: need frozen man

	static NPC* frozenman_npc = NULL;
	if(frozenman_npc==NULL)
	{
		NPC_create_npc_xy_feet(&frozenman_npc,GFX_ADULT_ghost,16,40,29*8,11*8);
		frozenman_npc->layer=2;
		frozenman_npc->non_walkable=1;
		NPC_animate_stand_dir(&frozenman_npc,DOWN);
	}
	if(frozenman_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&frozenman_npc,30))NPC_stare_at_npc(&frozenman_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&frozenman_npc, DOWN);
		if(ACTION_range_xy_xy(20*8,18*8,24*8,19*8,"Talk To Barbara"))
		{
			TEXT_set_sprite_window(0,frozenman_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	if(walking_into_door(RANGE_CITYFancyRestaurantKitchenFreezerToKitchen))
	{
		MAP_change_map(MAP_bobsgame_CITYFancyRestaurantKitchen,6,10);return;
	}
}
void bobsgame_CITYFancyRestaurantKitchenFreezer_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYFancyRestaurantKitchenFreezer_Map_VBL_Function()
{

}
void bobsgame_CITYFancyRestaurantKitchenFreezer_Map_HBL_Function()
{

}



