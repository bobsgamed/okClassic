//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"

#define RANGE_TOWNDepartmentStoreToOUTSIDETown1 37*8,79*8,45*8,80*8
#define RANGE_TOWNDepartmentStoreToOUTSIDETown2 48*8,79*8,56*8,80*8
#define RANGE_TOWNDepartmentStoreToOUTSIDETown3 59*8,79*8,67*8,80*8
#define RANGE_TOWNDepartmentStoreToOUTSIDETown4 70*8,79*8,78*8,80*8

//========================================================
//TOWNDepartmentStore
//========================================================
void bobsgame_TOWNDepartmentStore_Map_Load_Function()
{
//RANGE_TOWNDepartmentStoreToOUTSIDETown1 37*8,79*8,45*8,80*8
//RANGE_TOWNDepartmentStoreToOUTSIDETown2 48*8,79*8,56*8,80*8
//RANGE_TOWNDepartmentStoreToOUTSIDETown3 59*8,79*8,67*8,80*8
//RANGE_TOWNDepartmentStoreToOUTSIDETown4 70*8,79*8,78*8,80*8
}

void bobsgame_TOWNDepartmentStore_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//door 1 42 79
//door 2 52 79
//door 3 64 79
//door 4 75 79
//path 1
//door, 37,69 35,53 23,52 8,52 9,34 38,34 41,14 50,12 upwait, 81,15 81,37 83,37 rightwait 77,44 69,44 70,59 rightwait, 68,70, exit
//path 2
//door, 80,70 77,70 92,61 92,56 rightwait 92,44 upwait 99,44 upwait 102,31 upwait 78.31 leftwait 79.15 50,11 upwait 48,36 leftwait 50,60 rightwait 48,70 exit
//path 3
//door, 35,70 36,61 35,57 23,56 21,69 leftwait 21,77 7,77 5,60 faceleft 7,39 6,19 5,17 faceleft 7,12 up 31,14 33,12 up 34,44 31,44 leftwait 60,44 60,61 rightwait 58,70 exit
//TODO: need store clerk. run up to you once every few minutes? "can i help you, sir?" "no thanks" "dont be afraid to ask."
//cashiers
//92,41 jewelry counter 88-95,44 talk to
//checkout clerks 74,58 64,58 54,58 44,58 face up
//20,42 face down electronics counter 16-24,46 talk to
	static NPC* departmentclerks_npcs[4] = {NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<4;c++)
	{
		if(departmentclerks_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			if(c== 0){x=74*8;y=58*8;dir=UP;}
			if(c== 1){x=64*8;y=58*8;dir=UP;}
			if(c== 2){x=54*8;y=58*8;dir=UP;}
			if(c== 3){x=44*8;y=58*8;dir=UP;}
			NPC_create_random_ADULT_xy_feet(&departmentclerks_npcs[c],x,(y)+3);
			NPC_animate_stand_dir(&departmentclerks_npcs[c], dir);
			departmentclerks_npcs[c]->non_walkable=1;
			departmentclerks_npcs[c]->walk_dir=dir;
			departmentclerks_npcs[c]->layer=bgp;
		}
		else if(departmentclerks_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&departmentclerks_npcs[c],60)&&PLAYER_npc->MAP_x<departmentclerks_npcs[c]->MAP_x)NPC_stare_at_npc(&departmentclerks_npcs[c],&PLAYER_npc);
			else NPC_animate_stand_dir(&departmentclerks_npcs[c], departmentclerks_npcs[c]->walk_dir);
		}
	}
		static NPC* deptelecguy_npc = NULL;
	if(deptelecguy_npc==NULL)
	{
		NPC_create_npc_xy_feet(&deptelecguy_npc,GFX_ADULT_GENERICwomanbun,16,40,20*8,42*8);
		deptelecguy_npc->non_walkable=1;
		deptelecguy_npc->pushable=1;
		deptelecguy_npc->layer=3;
	}
	else if(deptelecguy_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&deptelecguy_npc,60))NPC_stare_at_npc(&deptelecguy_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&deptelecguy_npc, DOWN);
		if(ACTION_range_xy_xy(16*8,44*8,24*8,45*8,"Talk To Electronics Salesman"))
		{
			TEXT_set_sprite_window(0,deptelecguy_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);//TODO: buy ???
		}
	}
		static NPC* deptjewelryguy_npc = NULL;
	if(deptjewelryguy_npc==NULL)
	{
		NPC_create_npc_xy_feet(&deptjewelryguy_npc,GFX_ADULT_GENERICwomanbun,16,40,92*8,41*8);
		deptjewelryguy_npc->non_walkable=1;
		deptjewelryguy_npc->pushable=1;
		deptjewelryguy_npc->layer=3;
	}
	else if(deptjewelryguy_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&deptjewelryguy_npc,60))NPC_stare_at_npc(&deptjewelryguy_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&deptjewelryguy_npc, DOWN);
		if(ACTION_range_xy_xy(88*8,42*8,95*8,43*8,"Talk To Jewelry Salesman"))
		{
			TEXT_set_sprite_window(0,deptjewelryguy_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);//TODO: buy jewelry
		}
	}
	static NPC* department_npcs[10] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	for(c=0;c<10;c++)
	{
		if(department_npcs[c]==NULL&&CLOCK_second/10==c%6)
		{
			int d=r(4);
			if(d==0)NPC_create_random_ADULT_xy_feet(&department_npcs[c],42*8,78*8);
			if(d==1)NPC_create_random_ADULT_xy_feet(&department_npcs[c],52*8,78*8);
			if(d==2)NPC_create_random_ADULT_xy_feet(&department_npcs[c],64*8,78*8);
			if(d==3)NPC_create_random_ADULT_xy_feet(&department_npcs[c],75*8,78*8);
			department_npcs[c]->non_walkable=1;
			department_npcs[c]->AI=1;
			department_npcs[c]->walking_speed=SPEED_NORMAL+r(SPEED_SLOW-SPEED_FASTEST);
			department_npcs[c]->ignore_fx_layer=1;
			NPC_animate_stand_dir(&department_npcs[c], UP);
		}
		if(department_npcs[c]!=NULL)
		{
			if(c%3==0)
			{
				if(department_npcs[c]->AI== 1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 37*8,69*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI== 2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 35*8,51*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI== 3)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 23*8,51*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI== 4)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed,  8*8,51*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI== 5)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed,  9*8,34*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI== 6)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 41*8,34*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI== 7)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 41*8,14*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI== 8)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 50*8,12*8)==1){department_npcs[c]->AI++;NPC_animate_stand_dir(&department_npcs[c], UP);department_npcs[c]->vbls=0;}
				if(department_npcs[c]->AI== 9)if(department_npcs[c]->vbls>120)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==10)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 81*8,15*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==11)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 81*8,37*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==12)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 83*8,37*8)==1){department_npcs[c]->AI++;NPC_animate_stand_dir(&department_npcs[c], RIGHT);department_npcs[c]->vbls=0;}
				if(department_npcs[c]->AI==13)if(department_npcs[c]->vbls>120)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==14)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 77*8,44*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==15)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 69*8,44*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==16)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 70*8,59*8)==1){department_npcs[c]->AI++;NPC_animate_stand_dir(&department_npcs[c], RIGHT);department_npcs[c]->vbls=0;}
				if(department_npcs[c]->AI==17)if(department_npcs[c]->vbls>120)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==18)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed,  70*8,70*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==19)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 50*8,78*8)==1){NPC_delete_npc(&department_npcs[c]);}
			}
			if(c%3==1)
			{
				if(department_npcs[c]->AI== 1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 80*8,70*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI== 2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 77*8,70*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI== 3)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 92*8,61*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI== 4)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 92*8,56*8)==1){department_npcs[c]->AI++;NPC_animate_stand_dir(&department_npcs[c], RIGHT);department_npcs[c]->vbls=0;}
				if(department_npcs[c]->AI== 5)if(department_npcs[c]->vbls>120)department_npcs[c]->AI++;
				if(department_npcs[c]->AI== 6)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 92*8,45*8)==1){department_npcs[c]->AI++;NPC_animate_stand_dir(&department_npcs[c], UP);department_npcs[c]->vbls=0;}
				if(department_npcs[c]->AI== 7)if(department_npcs[c]->vbls>120)department_npcs[c]->AI++;
				if(department_npcs[c]->AI== 8)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 106*8,45*8)==1){department_npcs[c]->AI++;NPC_animate_stand_dir(&department_npcs[c], RIGHT);department_npcs[c]->vbls=0;}
				if(department_npcs[c]->AI== 9)if(department_npcs[c]->vbls>120)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==10)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed,102*8,31*8)==1){department_npcs[c]->AI++;NPC_animate_stand_dir(&department_npcs[c], UP);department_npcs[c]->vbls=0;}
				if(department_npcs[c]->AI==11)if(department_npcs[c]->vbls>120)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==12)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 79*8,31*8)==1){department_npcs[c]->AI++;NPC_animate_stand_dir(&department_npcs[c], LEFT);department_npcs[c]->vbls=0;}
				if(department_npcs[c]->AI==13)if(department_npcs[c]->vbls>120)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==14)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 79*8,15*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==15)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 50*8,11*8)==1){department_npcs[c]->AI++;NPC_animate_stand_dir(&department_npcs[c], UP);department_npcs[c]->vbls=0;}
				if(department_npcs[c]->AI==16)if(department_npcs[c]->vbls>120)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==17)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 49*8,36*8)==1){department_npcs[c]->AI++;NPC_animate_stand_dir(&department_npcs[c], LEFT);department_npcs[c]->vbls=0;}
				if(department_npcs[c]->AI==18)if(department_npcs[c]->vbls>120)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==19)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 49*8,44*8)==1){department_npcs[c]->AI++;NPC_animate_stand_dir(&department_npcs[c], LEFT);department_npcs[c]->vbls=0;}
				if(department_npcs[c]->AI==20)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 50*8,60*8)==1){department_npcs[c]->AI++;NPC_animate_stand_dir(&department_npcs[c], RIGHT);department_npcs[c]->vbls=0;}
				if(department_npcs[c]->AI==21)if(department_npcs[c]->vbls>120)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==22)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 48*8,70*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==23)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 62*8,78*8)==1){NPC_delete_npc(&department_npcs[c]);}
			}
			if(c%3==2)
			{
				if(department_npcs[c]->AI== 1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 35*8,70*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI== 2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 36*8,61*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI== 3)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 35*8,57*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI== 4)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 23*8,56*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI== 5)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 22*8,69*8)==1){department_npcs[c]->AI++;NPC_animate_stand_dir(&department_npcs[c], LEFT);department_npcs[c]->vbls=0;}
				if(department_npcs[c]->AI== 6)if(department_npcs[c]->vbls>120)department_npcs[c]->AI++;
				if(department_npcs[c]->AI== 7)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 22*8,77*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI== 8)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed,  7*8,77*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI== 9)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed,  6*8,60*8)==1){department_npcs[c]->AI++;NPC_animate_stand_dir(&department_npcs[c], LEFT);department_npcs[c]->vbls=0;}
				if(department_npcs[c]->AI==10)if(department_npcs[c]->vbls>120)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==11)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed,  7*8,39*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==12)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed,  6*8,19*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==13)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed,  6*8,17*8)==1){department_npcs[c]->AI++;NPC_animate_stand_dir(&department_npcs[c], LEFT);department_npcs[c]->vbls=0;}
				if(department_npcs[c]->AI==14)if(department_npcs[c]->vbls>120)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==15)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed,  7*8,13*8)==1){department_npcs[c]->AI++;NPC_animate_stand_dir(&department_npcs[c], UP);department_npcs[c]->vbls=0;}
				if(department_npcs[c]->AI==16)if(department_npcs[c]->vbls>120)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==17)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 31*8,14*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==18)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 33*8,14*8)==1){department_npcs[c]->AI++;NPC_animate_stand_dir(&department_npcs[c], UP);department_npcs[c]->vbls=0;}
				if(department_npcs[c]->AI==19)if(department_npcs[c]->vbls>120)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==20)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 34*8,44*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==21)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 32*8,44*8)==1){department_npcs[c]->AI++;NPC_animate_stand_dir(&department_npcs[c], LEFT);department_npcs[c]->vbls=0;}
				if(department_npcs[c]->AI==22)if(department_npcs[c]->vbls>120)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==23)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 59*8,44*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==24)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 60*8,61*8)==1){department_npcs[c]->AI++;NPC_animate_stand_dir(&department_npcs[c], RIGHT);department_npcs[c]->vbls=0;}
				if(department_npcs[c]->AI==25)if(department_npcs[c]->vbls>120)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==26)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 58*8,70*8)==1)department_npcs[c]->AI++;
				if(department_npcs[c]->AI==27)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&department_npcs[c],department_npcs[c]->walking_speed, 62*8,78*8)==1){NPC_delete_npc(&department_npcs[c]);}
			}
		}
	}
	if(walking_into_door(RANGE_TOWNDepartmentStoreToOUTSIDETown1))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,973,229);return;
	}
	if(walking_into_door(RANGE_TOWNDepartmentStoreToOUTSIDETown2))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,984,229);return;
	}
	if(walking_into_door(RANGE_TOWNDepartmentStoreToOUTSIDETown3))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,995,229);return;
	}
	if(walking_into_door(RANGE_TOWNDepartmentStoreToOUTSIDETown4))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,1006,229);return;
	}
}
void bobsgame_TOWNDepartmentStore_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNDepartmentStore_Map_VBL_Function()
{

}

void bobsgame_TOWNDepartmentStore_Map_HBL_Function()
{

}


