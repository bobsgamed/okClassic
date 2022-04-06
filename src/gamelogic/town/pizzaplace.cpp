//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================


#include "../../main.h"

#define RANGE_TOWNPizzaPlaceToOutside 24*8,32*8,28*8,33*8
//========================================================
//TOWNPizzaPlace
//========================================================
void bobsgame_TOWNPizzaPlace_Map_Load_Function()
{
//RANGE_TOWNPizzaPlaceToOutside 24*8,32*8,28*8,33*8
}

void bobsgame_TOWNPizzaPlace_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	static NPC* counterguy_npc = NULL;
	if(counterguy_npc==NULL)
	{
		NPC_create_npc_xy_feet(&counterguy_npc,GFX_ADULT_GENERICwomanbun,16,40,25*8,12*8-4);
		counterguy_npc->non_walkable=1;
		counterguy_npc->layer=3;
	}
	else if(counterguy_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&counterguy_npc,60))NPC_stare_at_npc(&counterguy_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&counterguy_npc, DOWN);
		if(ACTION_range_xy_xy(21*8,14*8,28*8,15*8,"Buy Pizza"))
		{
			TEXT_set_sprite_window(0,counterguy_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);//TODO: buy pizza.
		}
	}
	static NPC* pizzaplace_npcs[12] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<12;c++)
	{
		if(pizzaplace_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			if(c== 0){x= 5*8;y=17*8;dir=DOWN;}
			if(c== 1){x= 5*8;y=22*8-2;dir=UP;bgp=3;}
			if(c== 2){x=11*8;y=17*8;dir=DOWN;}
			if(c== 3){x=11*8;y=22*8-2;dir=UP;bgp=3;}
			if(c== 4){x=17*8;y=17*8;dir=DOWN;}
			if(c== 5){x=17*8;y=22*8-2;dir=UP;bgp=3;}
			if(c== 6){x= 5*8;y=25*8;dir=DOWN;}
			if(c== 7){x= 5*8;y=30*8-2;dir=UP;bgp=3;}
			if(c== 8){x=11*8;y=25*8;dir=DOWN;}
			if(c== 9){x=11*8;y=30*8-2;dir=UP;bgp=3;}
			if(c==10){x=17*8;y=25*8;dir=DOWN;}
			if(c==11){x=17*8;y=30*8-2;dir=UP;bgp=3;}

			NPC_create_random_ADULT_OR_CHILD_xy_feet(&pizzaplace_npcs[c],x,(y)+3);
			NPC_animate_stand_dir(&pizzaplace_npcs[c], dir);
			pizzaplace_npcs[c]->non_walkable=1;
			pizzaplace_npcs[c]->walk_dir=dir;
			pizzaplace_npcs[c]->layer=bgp;
		}
		if(pizzaplace_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&pizzaplace_npcs[c],12))NPC_stare_at_npc(&pizzaplace_npcs[c],&PLAYER_npc);
			else NPC_animate_stand_dir(&pizzaplace_npcs[c], pizzaplace_npcs[c]->walk_dir);
		}
	}
	if(walking_into_door(RANGE_TOWNPizzaPlaceToOutside))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,850,264);return;
	}
}
void bobsgame_TOWNPizzaPlace_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNPizzaPlace_Map_VBL_Function()
{

}

void bobsgame_TOWNPizzaPlace_Map_HBL_Function()
{

}


