//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"


#define RANGE_TOWNCoffeeShopToOutside 24*8,66*8,28*8,67*8
//========================================================
//TOWNCoffeeShop
//========================================================
void bobsgame_TOWNCoffeeShop_Map_Load_Function()
{
//NPC_create_sprite(&drums_GFX,64,64,56,112);
//RANGE_TOWNCoffeeShopToOutside 24*8,66*8,28*8,67*8

}
void bobsgame_TOWNCoffeeShop_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//guy at counter 8,48
//guy on couch face right 5,62
//guy on couch face left 14,62
//guy at table 22,53 face down
//guy at table 22,55 face up, under 2
//29,53, 29,55
//22,47, 22,49
//29,47  29,49
//22,38  22,40
//29,38  29,40
//couch face left 28,27
//couch face left 28,14
//guy at mic 15,16 face down (guitar guy?)
//guy at piano 6,14 face up
//guy at drums 9,16 face down
//TODO: if you buy coffee, the band plays, then you can talk to them
//cant talk to the band guys "dont interrupt me, im mentally preparing my poetic justice."
//guys on the couch are intellectuals contemporaries? talk politics?
//one of the guys at the tables is stuffed. hey, he isnt real

static NPC* drumsnpc = NULL;
if(drumsnpc==NULL)NPC_create_npc(&drumsnpc,GFX_MISC_drums,64,64,56,112);



	static NPC* coffeeshop_npcs[14] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<14;c++)
	{
		if(coffeeshop_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			if(c== 0){x=22*8;y=51*8+1;dir=DOWN;}
			if(c== 1){x=22*8;y=55*8+5;dir=UP;bgp=3;}
			if(c== 2){x=29*8;y=51*8+1;dir=DOWN;}
			if(c== 3){x=29*8;y=55*8+5;dir=UP;bgp=3;}
			if(c== 4){x=22*8;y=43*8+1;dir=DOWN;}
			if(c== 5){x=22*8;y=47*8+5;dir=UP;bgp=3;}
			if(c== 6){x=29*8;y=43*8+1;dir=DOWN;}
			if(c== 7){x=29*8;y=47*8+5;dir=UP;bgp=3;}
			if(c== 8){x=22*8;y=35*8+1;dir=DOWN;}
			if(c== 9){x=22*8;y=39*8+5;dir=UP;bgp=3;}
			if(c==10){x=29*8;y=35*8+1;dir=DOWN;}
			if(c==11){x=29*8;y=39*8+5;dir=UP;bgp=3;}
			if(c==12){x=28*8-3;y=26*8;dir=LEFT;}
			if(c==13){x=28*8-3;y=14*8;dir=LEFT;}

			NPC_create_random_ADULT_OR_CHILD_xy_feet(&coffeeshop_npcs[c],x,(y)+3);
			NPC_animate_stand_dir(&coffeeshop_npcs[c], dir);
			coffeeshop_npcs[c]->non_walkable=1;
			coffeeshop_npcs[c]->walk_dir=dir;
			coffeeshop_npcs[c]->layer=bgp;
		}
		if(coffeeshop_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&coffeeshop_npcs[c],12))NPC_stare_at_npc(&coffeeshop_npcs[c],&PLAYER_npc);
			else NPC_animate_stand_dir(&coffeeshop_npcs[c], coffeeshop_npcs[c]->walk_dir);
		}
	}
//TODO: drummer, pianist, counterguy, hipster, intellectual sprites
	static NPC* counterguy_npc = NULL;
	if(counterguy_npc==NULL)
	{
		NPC_create_npc_xy_feet(&counterguy_npc,GFX_ADULT_GENERICwomanbun,16,40,8*8,47*8-4);
		counterguy_npc->non_walkable=1;
		counterguy_npc->layer=3;
	}
	else if(counterguy_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&counterguy_npc,60))NPC_stare_at_npc(&counterguy_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&counterguy_npc, DOWN);
		if(ACTION_range_xy_xy(4*8,50*8,10*8,51*8,"Buy Coffee"))
		{
			TEXT_set_sprite_window(0,counterguy_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	static NPC* guitarguy_npc = NULL;
	if(guitarguy_npc==NULL)
	{
		NPC_create_npc_xy_feet(&guitarguy_npc,GFX_ADULT_guitarguy,16,40,15*8+4,15*8);
		guitarguy_npc->non_walkable=1;
	}
	else if(guitarguy_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&guitarguy_npc,12))NPC_stare_at_npc(&guitarguy_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&guitarguy_npc, DOWN);
		if(ACTION_npc(&guitarguy_npc,"Talk To Musician"))
		{
			TEXT_set_sprite_window(0,guitarguy_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Don't bother me right now. I'm mentally preparing my poetic armageddon.<.>"
			"Yuu had better sit down for this one, trust me."
			);
		}
	}
		static NPC* pianoguy_npc = NULL;
	if(pianoguy_npc==NULL)
	{
		NPC_create_npc_xy_feet(&pianoguy_npc,GFX_ADULT_GENERICbaldsuitguy,16,40,6*8,13*8);
		pianoguy_npc->non_walkable=1;
		//pianoguy_npc->layer=1;
	}
	else if(pianoguy_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&pianoguy_npc,12))NPC_stare_at_npc(&pianoguy_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&pianoguy_npc, UP);
		if(ACTION_npc(&pianoguy_npc,"Talk To Pianist"))
		{
			TEXT_set_sprite_window(0,pianoguy_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Move it, kid. This piano isn't going to play itself.<.>"
			"<1>Isn't that one of those pianos that plays itself?<.>"
			"<0>*snort*<.>"
			"And who exactly does Yuu think is going to hit the play button, huh?"
			);
		}
	}
		static NPC* drumsguy_npc = NULL;
	if(drumsguy_npc==NULL)
	{
		NPC_create_npc_xy_feet(&drumsguy_npc,GFX_ADULT_GENERICbaldingmanashirt,16,40,10*8,16*8);
		drumsguy_npc->non_walkable=1;
	}
	else if(drumsguy_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&drumsguy_npc,12))NPC_stare_at_npc(&drumsguy_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&drumsguy_npc,DOWN);
		if(ACTION_npc(&drumsguy_npc,"Talk To Drummer"))
		{
			TEXT_set_sprite_window(0,drumsguy_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Drums are the ultimate musical instrument.<.>"
			"Yuu can play half of it with your foot, leaving a hand free for a delicious sandwich."
			);
		}
	}
		static NPC* couchguy1_npc = NULL;
	if(couchguy1_npc==NULL)
	{
		NPC_create_npc_xy_feet(&couchguy1_npc,GFX_ADULT_GENERICmanlongsleeves,16,40,6*8+4,62*8);
		couchguy1_npc->non_walkable=1;
	}
	else if(couchguy1_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&couchguy1_npc,12))NPC_stare_at_npc(&couchguy1_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&couchguy1_npc,RIGHT);
		if(ACTION_npc(&couchguy1_npc,"Talk To Hipster"))
		{
			TEXT_set_sprite_window(0,couchguy1_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Why can't we all just get along?<.>"
			"If the whole world would join together in harmony, and all of mankind would just sit down and play some bongos together, we would finally have peace.<.>"
			"<1>Are you sure that would work? Things seem a little more complicated than that.<.>"
			"<0>See what I mean? Yuu should be playing bongos. Yuu is being part of the problem, man."
			);
		}
	}
	static NPC* couchguy2_npc = NULL;
	if(couchguy2_npc==NULL)
	{
		NPC_create_npc_xy_feet(&couchguy2_npc,GFX_ADULT_GENERICsuitguy,16,40,14*8-4,62*8);
		couchguy2_npc->non_walkable=1;
	}
	else if(couchguy2_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&couchguy2_npc,12))NPC_stare_at_npc(&couchguy2_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&couchguy2_npc,LEFT);
		if(ACTION_npc(&couchguy2_npc,"Talk To Intellectualismist"))
		{
			TEXT_set_sprite_window(0,couchguy2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Has Yuu seen the papers recently?<.>"
			"The government just has no idea what they're doing.<.>"
			"We need to relax and throw away all these dangerous weapons.<.>"
			"The other countries will see that we're actually nice guys and do the same, I'm sure of it.<.>"
			);
		}
	}
//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_TOWNCoffeeShopToOutside))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,785,263);return;
	}
}
void bobsgame_TOWNCoffeeShop_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNCoffeeShop_Map_VBL_Function()
{

}

void bobsgame_TOWNCoffeeShop_Map_HBL_Function()
{

}


