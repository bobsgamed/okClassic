//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"


#define RANGE_TOWNTacoBurgerToOutside 25*8,54*8,33*8,55*8


//========================================================
//TOWNTacoBurger
//========================================================
void bobsgame_TOWNTacoBurger_Map_Load_Function()
{
//RANGE_TOWNTacoBurgerToOutside 25*8,54*8,33*8,55*8
}

void bobsgame_TOWNTacoBurger_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//clerks
//16,12
//24,12
//32,12
//static NPC* fuck=NULL;
//NPC_create_npc(&fuck,GENERICwomanbun,16,40,12*8,12*8);
//HARDWARE_wait_for_vbl();
//NPC_delete_npc(&fuck);
//NPC_create_npc(&fuck,GENERICwomanbun,16,40,12*8,12*8);
//NPC_delete_npc(&fuck);
//HARDWARE_wait_for_vbl();
	static NPC* fastfood1_npc = NULL;
	if(fastfood1_npc==NULL)
	{
		NPC_create_npc_xy_feet(&fastfood1_npc,GFX_ADULT_GENERICwomanbun,16,40,14*8,12*8);
		fastfood1_npc->non_walkable=1;
		fastfood1_npc->pushable=1;
		fastfood1_npc->layer=3;
		//TODO: need tacoburger sprite
	}
	else if(fastfood1_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&fastfood1_npc,30))NPC_stare_at_npc(&fastfood1_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&fastfood1_npc, DOWN);
		if(ACTION_range_xy_xy(12*8,13*8,16*8,14*8,"Order TacoBurgers"))
		{
			TEXT_set_sprite_window(0,fastfood1_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);//TODO: buy ???
		}
	}
	static NPC* fastfood2_npc = NULL;
	if(fastfood2_npc==NULL)
	{
		NPC_create_npc_xy_feet(&fastfood2_npc,GFX_ADULT_GENERICwomanbun,16,40,22*8,12*8);
		fastfood2_npc->non_walkable=1;
		fastfood2_npc->pushable=1;
		fastfood2_npc->layer=3;
	}
	else if(fastfood2_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&fastfood2_npc,30))NPC_stare_at_npc(&fastfood2_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&fastfood2_npc, DOWN);
		if(ACTION_range_xy_xy(20*8,13*8,24*8,14*8,"Place Order"))
		{
			TEXT_set_sprite_window(0,fastfood2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);//TODO: buy ???
		}
	}
	static NPC* fastfood3_npc = NULL;
	if(fastfood3_npc==NULL)
	{
		NPC_create_npc_xy_feet(&fastfood3_npc,GFX_ADULT_GENERICwomanbun,16,40,29*8,12*8);
		fastfood3_npc->non_walkable=1;
		fastfood3_npc->pushable=1;
		fastfood3_npc->layer=3;
	}
	else if(fastfood3_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&fastfood3_npc,30))NPC_stare_at_npc(&fastfood3_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&fastfood3_npc, DOWN);
		if(ACTION_range_xy_xy(27*8,13*8,31*8,14*8,"Purchase Delicious TacoBurgers"))
		{
			TEXT_set_sprite_window(0,fastfood3_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);//TODO: buy ???
		}
	}
//TODO: brighter signs
//TODO: need fat people
//people in chairs
//16,39 down
//23,39 down
//16,41 up-2
//23,41 up-2
//17,49 down
//21,49 down
//17,53 up-2
//21,53 up-2
//10,40 left
//10,43 left
//10,49 left
//10,52 left
//4,40 right
//4,43 right
//4,49 right
//4 52 right
	static NPC* tacoburgersitting_npcs[16] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<16;c++)
	{
		if(tacoburgersitting_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			if(c== 0){x=16*8;y=38*8-2;dir=DOWN;}
			if(c== 1){x=23*8;y=38*8-2;dir=DOWN;}
			if(c== 2){x=16*8;y=42*8-2;dir=UP;bgp=3;}
			if(c== 3){x=23*8;y=42*8-2;dir=UP;bgp=3;}
			if(c== 4){x=17*8;y=48*8-2;dir=DOWN;}
			if(c== 5){x=21*8;y=48*8-2;dir=DOWN;}
			if(c== 6){x=17*8;y=52*8-2;dir=UP;bgp=3;}
			if(c== 7){x=21*8;y=52*8-2;dir=UP;bgp=3;}
			if(c== 8){x=10*8-3;y=38*8-2;dir=LEFT;}
			if(c== 9){x=10*8-3;y=42*8-2;dir=LEFT;}
			if(c==10){x=10*8-3;y=47*8-2;dir=LEFT;}
			if(c==11){x=10*8-3;y=51*8-2;dir=LEFT;}
			if(c==12){x= 5*8+3;y=38*8-2;dir=RIGHT;}
			if(c==13){x= 5*8+3;y=42*8-2;dir=RIGHT;}
			if(c==14){x= 5*8+3;y=47*8-2;dir=RIGHT;}
			if(c==15){x= 5*8+3;y=51*8-2;dir=RIGHT;}
			NPC_create_random_ADULT_OR_CHILD_xy_feet(&tacoburgersitting_npcs[c],x,(y)+3);
			NPC_animate_stand_dir(&tacoburgersitting_npcs[c], dir);
			tacoburgersitting_npcs[c]->non_walkable=1;
			tacoburgersitting_npcs[c]->walk_dir=dir;
			tacoburgersitting_npcs[c]->layer=bgp;
		}
		else if(tacoburgersitting_npcs[c]!=NULL)
		{
			//if(NPC_in_range_of_npc_amt(&PLAYER_npc,tacoburgersitting_npcs[c],60)&&PLAYER_npc->MAP_x<tacoburgersitting_npcs[c]->MAP_x)NPC_stare_at_npc(&tacoburgersitting_npcs[c],PLAYER_npc);
			//else NPC_animate_set_direction_now(&tacoburgersitting_npcs[c], tacoburgersitting_npcs[c]->walking_direction);
		}
	}
//TODO:need crowd murmur
//need order up sounds
//people in line. line moves.
//TODO: have to wait in line
//maybe get position in line, maybe take control of sprite and put it through the cycles.
//TODO: people are initialized at certain stages already
//TODO: get kicked out on close.
//door at 29,54 walk to 29,30 12,30 12,23 31,23 31,17
//talk to clerks at 30,15 22,15 14,15
//tray at 6,15, place tray at 6,13? guy comes from above?
//5,24 left soda fountain
//5,33 left trash
	static int spotused[3]={0,0,0};
	static int randnum=0;
		static NPC* line_npcs[20] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	for(c=0;c<20;c++)
	{
		if(line_npcs[c]==NULL&&CLOCK_second/10==c%6)
		{
			NPC_create_random_ADULT_OR_CHILD_xy_feet(&line_npcs[c],29*8,54*8);
			line_npcs[c]->non_walkable=1;
			line_npcs[c]->AI=1;
			line_npcs[c]->walking_speed=SPEED_NORMAL+r(SPEED_SLOW-SPEED_FASTEST);
			line_npcs[c]->ignore_fx_layer=1;
			NPC_animate_stand_dir(&line_npcs[c], UP);
		}
		if(line_npcs[c]!=NULL)
		{
			if(line_npcs[c]->AI== 1)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 29*8,29*8)==(1))line_npcs[c]->AI++;
			if(line_npcs[c]->AI== 2)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 12*8,29*8)==(1))line_npcs[c]->AI++;
			if(line_npcs[c]->AI== 3)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 12*8,23*8)==(1))line_npcs[c]->AI++;
			if(line_npcs[c]->AI== 4)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 31*8,23*8)==(1))line_npcs[c]->AI++;
			if(line_npcs[c]->AI== 5)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 31*8,18*8)==(1))line_npcs[c]->AI++;
			if(line_npcs[c]->AI== 6){randnum=(r(3));line_npcs[c]->vbls=0;if(spotused[randnum]==0){line_npcs[c]->AI+=randnum+1;spotused[randnum]=1;}}
			if(line_npcs[c]->AI== 7)if(line_npcs[c]->vbls>60){line_npcs[c]->AI+=3;}
			if(line_npcs[c]->AI== 8)if(line_npcs[c]->vbls>60){line_npcs[c]->AI+=3;}
			if(line_npcs[c]->AI== 9)if(line_npcs[c]->vbls>60){line_npcs[c]->AI+=3;}
			//walk to open spot
			if(line_npcs[c]->AI==10)if(NPC_walk_to_xy_nohit_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 30*8,15*8)==(1)){line_npcs[c]->AI+=3;line_npcs[c]->vbls=0;NPC_animate_stand_dir(&line_npcs[c], UP);}
			if(line_npcs[c]->AI==11)if(NPC_walk_to_xy_nohit_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 22*8,15*8)==(1)){line_npcs[c]->AI+=3;line_npcs[c]->vbls=0;NPC_animate_stand_dir(&line_npcs[c], UP);}
			if(line_npcs[c]->AI==12)if(NPC_walk_to_xy_nohit_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 14*8,15*8)==(1)){line_npcs[c]->AI+=3;line_npcs[c]->vbls=0;NPC_animate_stand_dir(&line_npcs[c], UP);}
			//stand for awhile, then open up spot
			if(line_npcs[c]->AI==13)if(line_npcs[c]->vbls>200){line_npcs[c]->AI+=3;spotused[0]=0;}
			if(line_npcs[c]->AI==14)if(line_npcs[c]->vbls>200){line_npcs[c]->AI+=3;spotused[1]=0;}
			if(line_npcs[c]->AI==15)if(line_npcs[c]->vbls>200){line_npcs[c]->AI+=3;spotused[2]=0;}
			//walk to tray
			if(line_npcs[c]->AI==16)if(NPC_walk_to_xy_nohit_pushmain(&line_npcs[c],line_npcs[c]->walking_speed,30*8,17*8)==(1)){line_npcs[c]->AI+=3;NPC_animate_stand_dir(&line_npcs[c], UP);line_npcs[c]->vbls=0;}
			if(line_npcs[c]->AI==17)if(NPC_walk_to_xy_nohit_pushmain(&line_npcs[c],line_npcs[c]->walking_speed,22*8,17*8)==(1)){line_npcs[c]->AI+=2;NPC_animate_stand_dir(&line_npcs[c], UP);line_npcs[c]->vbls=0;}
			if(line_npcs[c]->AI==18)if(NPC_walk_to_xy_nohit_pushmain(&line_npcs[c],line_npcs[c]->walking_speed,14*8,17*8)==(1)){line_npcs[c]->AI+=1;NPC_animate_stand_dir(&line_npcs[c], UP);line_npcs[c]->vbls=0;}
			if(line_npcs[c]->AI==19)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 10*8,15*8)==(1)){line_npcs[c]->AI++;NPC_animate_stand_dir(&line_npcs[c], UP);line_npcs[c]->vbls=0;}
			if(line_npcs[c]->AI==20)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 6*8,15*8)==(1)){line_npcs[c]->AI++;NPC_animate_stand_dir(&line_npcs[c], UP);line_npcs[c]->vbls=0;}
			if(line_npcs[c]->AI==21)if(line_npcs[c]->vbls>120)line_npcs[c]->AI++;
			//walk to soda fountain
			if(line_npcs[c]->AI==22)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 6*8,24*8)==(1)){line_npcs[c]->AI++;NPC_animate_stand_dir(&line_npcs[c], LEFT);line_npcs[c]->vbls=0;}
			if(line_npcs[c]->AI==23)if(line_npcs[c]->vbls>120)line_npcs[c]->AI++;
			if(line_npcs[c]->AI==24)if(NPC_walk_to_xy_nohit_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 7*8,34*8)==(1)){line_npcs[c]->AI++;line_npcs[c]->vbls=0;}
			if(line_npcs[c]->AI==25)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 27*8,34*8)==(1)){line_npcs[c]->AI++;line_npcs[c]->vbls=0;}
			if(line_npcs[c]->AI==26)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 27*8,54*8)==(1)){NPC_delete_npc(&line_npcs[c]);}
		}
	}
	if(walking_into_door(RANGE_TOWNTacoBurgerToOutside))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,577,292);return;
	}
}
void bobsgame_TOWNTacoBurger_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNTacoBurger_Map_VBL_Function()
{

}

void bobsgame_TOWNTacoBurger_Map_HBL_Function()
{

}


