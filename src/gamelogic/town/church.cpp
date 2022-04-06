//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"





#define RANGE_TOWNChurchToOutside 18*8,63*8,26*8,64*8



//========================================================
//TOWNChurch
//========================================================
void bobsgame_TOWNChurch_Map_Load_Function()
{
//RANGE_TOWNChurchToOutside 18*8,63*8,26*8,64*8
}

void bobsgame_TOWNChurch_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//priest at 21,17
//organist at 5,14 up
//TODO: need priest sprite
//TODO: need organist sprite
	static NPC* priest_npc = NULL;
	if(priest_npc==NULL)
	{
		NPC_create_npc_xy_feet(&priest_npc,GFX_ADULT_GENERICmangrayhairsuit,16,40,22*8,17*8);
		priest_npc->non_walkable=1;
		priest_npc->pushable=1;
		priest_npc->layer=2;
		NPC_animate_stand_dir(&priest_npc, DOWN);
	}
	else if(priest_npc!=NULL)
	{
		if(ACTION_range_xy_xy(19*8,21*8,24*8,22*8,"Repent"))
		{
			TEXT_set_sprite_window(0,priest_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("<1>I'm really sorry.<.>"
			"<0>That's alright.<.>"
			"Drink this blood and Yuu will have eternal life in paradise.<.>"
			"<1>Yay!<.>"
			"Wait a second, isn't this alcohol?<.>"
			"Can you give that to kids?<.>"
			"<0>*cough*No, Yuu sees. It's blood. Bob forgives you.<.>"
			"Now sit down, I've got to analyze this paragraph for a few hours.<.>"
			"I'm not sure whether this mention of \"Panda\" is a metaphor for the sin of Gluttony, or if it's simply referring to the paragon of scholarly omniscience.<.>"
			"<1>The animal?<.>"
			"<0>Sacrilege! Get a grip on reality, kid, or burn in the flames of eternal torture.<.>"
			"<1>Ok."
			);
		}
	}
	static NPC* organist_npc = NULL;
	if(organist_npc==NULL)
	{
		NPC_create_npc_xy_feet(&organist_npc,GFX_ADULT_GENERICwomanwhitehair,16,40,5*8,14*8);
		organist_npc->non_walkable=1;
		organist_npc->pushable=1;
		organist_npc->layer=2;
		NPC_animate_stand_dir(&organist_npc, UP);
	}
	else if(organist_npc!=NULL)
	{

	}
//congregation
//8,12,16,31,34       28
//7,13,15,26,30,35    34
//8,13,16,25,30,36    40
//7,12,16,26,31,36    46
//7,13,17,24,29,34    52
//TODO: need yuu in a suit
//need service script
//need organ music
//need generics in suits
//need to script everybody flooding out
//need church bell sound
	static NPC* congregation_npcs[35] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<35;c++)
	{
		if(congregation_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=3;
			if(c== 0){x= 8*8;y=28*8;dir=UP;}
			if(c== 1){x=12*8;y=28*8;dir=UP;}
			if(c== 2){x=16*8;y=28*8;dir=UP;}
			if(c== 3){x=31*8;y=28*8;dir=UP;}
			if(c== 4){x=34*8;y=28*8;dir=UP;}
			if(c== 5){x= 8*8;y=34*8;dir=UP;}
			if(c== 6){x=10*8;y=34*8;dir=UP;}
			if(c== 7){x=13*8;y=34*8;dir=UP;}
			if(c== 8){x=15*8;y=34*8;dir=UP;}
			if(c== 9){x=26*8;y=34*8;dir=UP;}
			if(c==10){x=30*8;y=34*8;dir=UP;}
			if(c==11){x=35*8;y=34*8;dir=UP;}
			if(c==12){x= 8*8;y=40*8;dir=UP;}
			if(c==13){x=13*8;y=40*8;dir=UP;}
			if(c==14){x=16*8;y=40*8;dir=UP;}
			if(c==15){x=26*8;y=40*8;dir=UP;}
			if(c==16){x=30*8;y=40*8;dir=UP;}
			if(c==17){x=32*8;y=40*8;dir=UP;}
			if(c==18){x=36*8;y=40*8;dir=UP;}
			if(c==19){x= 8*8;y=46*8;dir=UP;}
			if(c==20){x=10*8;y=46*8;dir=UP;}
			if(c==21){x=12*8;y=46*8;dir=UP;}
			if(c==22){x=16*8;y=46*8;dir=UP;}
			if(c==23){x=27*8;y=46*8;dir=UP;}
			if(c==24){x=31*8;y=46*8;dir=UP;}
			if(c==25){x=33*8;y=46*8;dir=UP;}
			if(c==26){x=36*8;y=46*8;dir=UP;}
			if(c==27){x= 8*8;y=52*8;dir=UP;}
			if(c==28){x=11*8;y=52*8;dir=UP;}
			if(c==29){x=13*8;y=52*8;dir=UP;}
			if(c==30){x=17*8;y=52*8;dir=UP;}
			if(c==31){x=28*8;y=52*8;dir=UP;}
			if(c==32){x=30*8;y=52*8;dir=UP;}
			if(c==33){x=34*8;y=52*8;dir=UP;}
			if(c==34){x=36*8;y=52*8;dir=UP;}
			if(x!=0)
			{
				NPC_create_random_ADULT_OR_CHILD_xy_feet(&congregation_npcs[c],x,(y)+3);
				NPC_animate_stand_dir(&congregation_npcs[c], dir);
				congregation_npcs[c]->non_walkable=1;
				congregation_npcs[c]->layer=bgp;
			}
		}
		else if(congregation_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&congregation_npcs[c],16))NPC_stare_at_npc(&congregation_npcs[c],&PLAYER_npc);
			else NPC_animate_stand_dir(&congregation_npcs[c], UP);
		}
	}
	if(walking_into_door(RANGE_TOWNChurchToOutside))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,497,292);return;
	}
}
void bobsgame_TOWNChurch_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNChurch_Map_VBL_Function()
{

}

void bobsgame_TOWNChurch_Map_HBL_Function()
{

}



