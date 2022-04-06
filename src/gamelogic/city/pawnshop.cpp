//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================




#include "../../main.h"



#define RANGE_CITYPawnShopToOUTSIDECity 11*8,44*8,19*8,45*8

//========================================================
//CITYPawnShop
//========================================================
void bobsgame_CITYPawnShop_Map_Load_Function()
{
//RANGE_CITYPawnShopToOUTSIDECity 11*8,44*8,19*8,45*8
}
void bobsgame_CITYPawnShop_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//18.16 layer 2

	static NPC* pawnshopguy_npc = NULL;
	if(pawnshopguy_npc==NULL)
	{
		//NPC_create_random_ADULT_xy_feet(&pawnshopguy_npc,10*8-4,27*8);
		NPC_create_npc_xy_feet(&pawnshopguy_npc,GFX_ADULT_pawnshopguy,16,40,18*8,15*8);

		pawnshopguy_npc->non_walkable=1;
		pawnshopguy_npc->layer=2;
		NPC_animate_stand_dir(&pawnshopguy_npc,LEFT);

		pawnshopguy_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		pawnshopguy_npc->walk_dir=pawnshopguy_npc->anim_dir;

		//NPC_animate_increment_direction_frame_now(&pawnshopguy_npc, pawnshopguy_npc->anim_direction);

	}
	if(pawnshopguy_npc!=NULL)
	{
		//if(NPC_in_range_of_npc_amt(&PLAYER_npc,pawnshopguy_npc,15))NPC_stare_at_npc(&pawnshopguy_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&pawnshopguy_npc, pawnshopguy_npc->walking_direction);

		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&pawnshopguy_npc,45))NPC_stare_at_npc_not_opposite_walking_direction(&pawnshopguy_npc,&PLAYER_npc);
		else
		{
			if(pawnshopguy_npc->AI==0){if(pawnshopguy_npc->vbls>200){if(r(4)==0){pawnshopguy_npc->AI=1+r(3);}else{pawnshopguy_npc->vbls=0;NPC_animate_stand_dir(&pawnshopguy_npc, pawnshopguy_npc->walk_dir);if(pawnshopguy_npc->anim_frame_count!=0){pawnshopguy_npc->anim_frame_count=3;NPC_animate(&pawnshopguy_npc);}}}}
			if(pawnshopguy_npc->AI==1){if(pawnshopguy_npc->walk_dir==UP||pawnshopguy_npc->walk_dir==DOWN)NPC_animate_stand_dir(&pawnshopguy_npc,LEFT);else NPC_animate_stand_dir(&pawnshopguy_npc,UP);pawnshopguy_npc->vbls=r(120);pawnshopguy_npc->AI=0;}
			if(pawnshopguy_npc->AI==2){if(pawnshopguy_npc->walk_dir==UP||pawnshopguy_npc->walk_dir==DOWN)NPC_animate_stand_dir(&pawnshopguy_npc,RIGHT);else NPC_animate_stand_dir(&pawnshopguy_npc,DOWN);pawnshopguy_npc->vbls=r(120);pawnshopguy_npc->AI=0;}
			if(pawnshopguy_npc->AI==3){NPC_animate(&pawnshopguy_npc);pawnshopguy_npc->vbls=r(120);pawnshopguy_npc->AI=0;}
		}

		if(ACTION_range_xy_xy(16*8,18*8,21*8,19*8,"Talk To Pawn Shop Guy"))
		{
			TEXT_set_sprite_window(0,pawnshopguy_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("" //?
			);
		}
	}

//TODO: need drug addict who keeps coming in

	if(walking_into_door(RANGE_CITYPawnShopToOUTSIDECity))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,135,39);return;
	}
}
void bobsgame_CITYPawnShop_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYPawnShop_Map_VBL_Function()
{

}
void bobsgame_CITYPawnShop_Map_HBL_Function()
{

}




