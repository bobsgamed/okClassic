//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================


#include "../../main.h"


#define RANGE_CITYFireDepartmentGarageToOUTSIDECity 34*8,54*8,42*8,55*8
#define RANGE_CITYFireDepartmentGarageToUpstairs 41*8,5*8,46*8,6*8
#define RANGE_CITYFireDepartmentUpstairsToGarage 41*8,21*8,46*8,22*8
#define RANGE_CITYFireDepartmentUpstairsToQuarters 24*8,22*8,32*8,23*8
#define RANGE_CITYFireDepartmentUpstairsToGaragePole1 4*8,16*8,7*8,17*8
#define RANGE_CITYFireDepartmentUpstairsToGaragePole2 10*8,16*8,13*8,17*8
#define RANGE_CITYFireDepartmentUpstairsToGaragePole3 16*8,16*8,19*8,17*8
#define RANGE_CITYFireDepartmentQuartersToUpstairs 24*8,9*8,32*8,10*8
#define RANGE_CITYFireDepartmentQuartersToBedroom 23*8,31*8,27*8,32*8
#define RANGE_CITYFireDepartmentQuartersToBathroom 30*8,31*8,34*8,32*8
#define RANGE_CITYFireDepartmentBedroomToQuarters 23*8,9*8,27*8,10*8
#define RANGE_CITYFireDepartmentBedroomToBathroom 28*8,28*8,29*8,32*8
#define RANGE_CITYFireDepartmentBathroomToQuarters 3*8,9*8,7*8,10*8
#define RANGE_CITYFireDepartmentBathroomToBedroom 1*8,28*8,2*8,32*8

//========================================================
//CITYFireDepartmentGarage
//========================================================
void bobsgame_CITYFireDepartmentGarage_Map_Load_Function()
{
//RANGE_CITYFireDepartmentGarageToOUTSIDECity 34*8,54*8,42*8,55*8
//RANGE_CITYFireDepartmentGarageToUpstairs 41*8,5*8,46*8,6*8
}
void bobsgame_CITYFireDepartmentGarage_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//38,41 down
//TODO: need firefighter chief security guy head?
	static NPC* firedeptclerk_npc = NULL;
	if(firedeptclerk_npc==NULL)
	{
		//NPC_create_random_ADULT_xy_feet(&firedeptclerk_npc,2*8,2*8);
		NPC_create_npc_xy_feet(&firedeptclerk_npc,GFX_ADULT_paramedic,16,40,38*8,41*8-4);
		firedeptclerk_npc->non_walkable=1;
		firedeptclerk_npc->layer=2;
		NPC_animate_stand_dir(&firedeptclerk_npc, DOWN);
		firedeptclerk_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		firedeptclerk_npc->walk_dir=firedeptclerk_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&firedeptclerk_npc, firedeptclerk_npc->anim_direction);
	}
	if(firedeptclerk_npc!=NULL)
	{
		//if(NPC_in_range_of_npc_amt(&PLAYER_npc,firedeptclerk_npc,15))NPC_stare_at_npc(&firedeptclerk_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&firedeptclerk_npc, firedeptclerk_npc->walking_direction);
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&firedeptclerk_npc,35))NPC_stare_at_npc(&firedeptclerk_npc,&PLAYER_npc);
		else
		{
			if(firedeptclerk_npc->AI==0){if(firedeptclerk_npc->vbls>200){if(r(4)==0){firedeptclerk_npc->AI=1+r(3);}else{firedeptclerk_npc->vbls=0;NPC_animate_stand_dir(&firedeptclerk_npc, firedeptclerk_npc->walk_dir);if(firedeptclerk_npc->anim_frame_count!=0){firedeptclerk_npc->anim_frame_count=3;NPC_animate(&firedeptclerk_npc);}}}}
			if(firedeptclerk_npc->AI==1){if(firedeptclerk_npc->walk_dir==UP||firedeptclerk_npc->walk_dir==DOWN)NPC_animate_stand_dir(&firedeptclerk_npc,LEFT);else NPC_animate_stand_dir(&firedeptclerk_npc,UP);firedeptclerk_npc->vbls=r(120);firedeptclerk_npc->AI=0;}
			if(firedeptclerk_npc->AI==2){if(firedeptclerk_npc->walk_dir==UP||firedeptclerk_npc->walk_dir==DOWN)NPC_animate_stand_dir(&firedeptclerk_npc,RIGHT);else NPC_animate_stand_dir(&firedeptclerk_npc,DOWN);firedeptclerk_npc->vbls=r(120);firedeptclerk_npc->AI=0;}
			if(firedeptclerk_npc->AI==3){NPC_animate(&firedeptclerk_npc);firedeptclerk_npc->vbls=r(120);firedeptclerk_npc->AI=0;}
		}
		if(ACTION_range_xy_xy(35*8,43*8,40*8,44*8,"Talk To Fire Chief"))
		{
			TEXT_set_sprite_window(0,firedeptclerk_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	//TODO: not let past rope unless?? 36-41,30
	//TODO: need firefighter in overalls without hat, blue shirt?

	static NPC* radioguy_npc = NULL;
	if(radioguy_npc==NULL)
	{
		//NPC_create_random_ADULT_xy_feet(&radioguy_npc,2*8,2*8);
		NPC_create_npc_xy_feet(&radioguy_npc,GFX_ADULT_firefighter,16,40,34*8+4,17*8);
		radioguy_npc->non_walkable=1;
		radioguy_npc->layer=2;
		NPC_animate_stand_dir(&radioguy_npc, RIGHT);
		radioguy_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		radioguy_npc->walk_dir=radioguy_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&radioguy_npc, radioguy_npc->anim_direction);
	}
	if(radioguy_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&radioguy_npc,20))NPC_stare_at_npc(&radioguy_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&radioguy_npc, radioguy_npc->walk_dir);
		if(ACTION_npc(&radioguy_npc,"Talk To Radio Guy"))
		{
			TEXT_set_sprite_window(0,radioguy_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	//slide down pole
	if(PLAYER_npc->MAP_x<22*8&&PLAYER_npc->MAP_y<(12-3)*8)
	{
		if(PLAYER_npc->ms>SPEED_FASTEST){PLAYER_npc->ms=0;PLAYER_npc->MAP_y++;}
	}
	if(walking_into_door(RANGE_CITYFireDepartmentGarageToOUTSIDECity))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,1394,39);return;
	}
	if(walking_into_door(RANGE_CITYFireDepartmentGarageToUpstairs))
	{
		MAP_change_map(MAP_bobsgame_CITYFireDepartmentUpstairs,43,21);return;
	}
}
void bobsgame_CITYFireDepartmentGarage_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYFireDepartmentGarage_Map_VBL_Function()
{

}
void bobsgame_CITYFireDepartmentGarage_Map_HBL_Function()
{

}
//========================================================
//CITYFireDepartmentUpstairs
//========================================================
void bobsgame_CITYFireDepartmentUpstairs_Map_Load_Function()
{
//RANGE_CITYFireDepartmentUpstairsToGarage 41*8,21*8,46*8,22*8
//RANGE_CITYFireDepartmentUpstairsToQuarters 24*8,22*8,32*8,23*8
//RANGE_CITYFireDepartmentUpstairsToGaragePole1 4*8,16*8,7*8,17*8
//RANGE_CITYFireDepartmentUpstairsToGaragePole2 10*8,16*8,13*8,17*8
//RANGE_CITYFireDepartmentUpstairsToGaragePole3 16*8,16*8,19*8,17*8
}
void bobsgame_CITYFireDepartmentUpstairs_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	if(walking_into_door(RANGE_CITYFireDepartmentUpstairsToGarage))
	{
		MAP_change_map(MAP_bobsgame_CITYFireDepartmentGarage,43,6);return;
	}
	if(walking_into_door(RANGE_CITYFireDepartmentUpstairsToQuarters))
	{
		MAP_change_map(MAP_bobsgame_CITYFireDepartmentQuarters,27,10);return;
	}
	if(walking_into_door(RANGE_CITYFireDepartmentUpstairsToGaragePole1))
	{
		MAP_change_map(MAP_bobsgame_CITYFireDepartmentGarage,5,4);return;
		//slide down to 14
	}
	if(walking_into_door(RANGE_CITYFireDepartmentUpstairsToGaragePole2))
	{
		MAP_change_map(MAP_bobsgame_CITYFireDepartmentGarage,11,4);return;
		//slide down to 14
	}
	if(walking_into_door(RANGE_CITYFireDepartmentUpstairsToGaragePole3))
	{
		MAP_change_map(MAP_bobsgame_CITYFireDepartmentGarage,17,4);return;
		//slide down to 14
	}
}
void bobsgame_CITYFireDepartmentUpstairs_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYFireDepartmentUpstairs_Map_VBL_Function()
{

}
void bobsgame_CITYFireDepartmentUpstairs_Map_HBL_Function()
{

}
//========================================================
//CITYFireDepartmentQuarters
//========================================================
void bobsgame_CITYFireDepartmentQuarters_Map_Load_Function()
{
//RANGE_CITYFireDepartmentQuartersToUpstairs 24*8,9*8,32*8,10*8
//RANGE_CITYFireDepartmentQuartersToBedroom 23*8,31*8,27*8,32*8
//RANGE_CITYFireDepartmentQuartersToBathroom 30*8,31*8,34*8,32*8
}
void bobsgame_CITYFireDepartmentQuarters_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//12,23
//16,23
//20,23 up
	static NPC* fireupstairs_npcs[10] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<10;c++)
	{
		if(fireupstairs_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			GFX* gfx=NULL;
			if(c== 0){x=12*8;y=23*8-4;	dir=UP;		bgp=2;gfx=GFX_ADULT_firefighter;}
			if(c== 1){x=16*8;y=23*8-4;	dir=UP;		bgp=2;gfx=GFX_ADULT_firefighter;}
			if(c== 2){x=20*8;y=23*8-4;	dir=UP;		bgp=2;gfx=GFX_ADULT_firefighter;}
			if(c== 3){x=12*8;y=17*8;	dir=DOWN;	bgp=2;gfx=GFX_ADULT_firefighter;}
			if(c== 4){x=16*8;y=17*8;	dir=DOWN;	bgp=2;gfx=GFX_ADULT_firefighter;}
			if(c== 5){x=20*8;y=17*8;	dir=DOWN;	bgp=2;gfx=GFX_ADULT_firefighter;}
			if(c== 6){x=32*8;y=18*8;	dir=RIGHT;	bgp=2;gfx=GFX_ADULT_firefighter;}
			if(c== 7){x=32*8;y=21*8+4;	dir=RIGHT;	bgp=2;gfx=GFX_ADULT_firefighter;}
			if(c== 8){x=36*8;y=12*8+2;	dir=DOWN;	bgp=2;gfx=GFX_ADULT_firefighter;}
			if(c== 9){x=39*8+4;y=12*8+2;dir=DOWN;	bgp=2;gfx=GFX_ADULT_firefighter;}

			if(gfx==NULL)NPC_create_random_ADULT_xy_feet(&fireupstairs_npcs[c],x,y);
			else NPC_create_npc_xy_feet(&fireupstairs_npcs[c],gfx,16,40,x,y);
			NPC_animate_stand_dir(&fireupstairs_npcs[c], dir);
			fireupstairs_npcs[c]->non_walkable=1;
			fireupstairs_npcs[c]->walk_dir=dir;
			fireupstairs_npcs[c]->layer=bgp;
			//NPC_animate_increment_direction_frame_now(&fireupstairs_npcs[c], dir);
		}
		if(fireupstairs_npcs[c]!=NULL)
		{
			if(fireupstairs_npcs[c]->AI==0){if(fireupstairs_npcs[c]->vbls>200){if(r(4)==0){fireupstairs_npcs[c]->AI=1+r(3);}else{fireupstairs_npcs[c]->vbls=0;NPC_animate_stand_dir(&fireupstairs_npcs[c], fireupstairs_npcs[c]->walk_dir);if(fireupstairs_npcs[c]->anim_frame_count!=0){fireupstairs_npcs[c]->anim_frame_count=3;NPC_animate(&fireupstairs_npcs[c]);}}}}
			if(fireupstairs_npcs[c]->AI==1){if(fireupstairs_npcs[c]->walk_dir==UP||fireupstairs_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&fireupstairs_npcs[c],LEFT);else NPC_animate_stand_dir(&fireupstairs_npcs[c],UP);fireupstairs_npcs[c]->vbls=r(120);fireupstairs_npcs[c]->AI=0;}
			if(fireupstairs_npcs[c]->AI==2){if(fireupstairs_npcs[c]->walk_dir==UP||fireupstairs_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&fireupstairs_npcs[c],RIGHT);else NPC_animate_stand_dir(&fireupstairs_npcs[c],DOWN);fireupstairs_npcs[c]->vbls=r(120);fireupstairs_npcs[c]->AI=0;}
			if(fireupstairs_npcs[c]->AI==3){NPC_animate(&fireupstairs_npcs[c]);fireupstairs_npcs[c]->vbls=r(120);fireupstairs_npcs[c]->AI=0;}
			//if(NPC_in_range_of_npc_amt(&PLAYER_npc,fireupstairs_npcs[c],15))NPC_stare_at_npc(&fireupstairs_npcs[c],PLAYER_npc);
			//else NPC_animate_set_direction_now(&fireupstairs_npcs[c], fireupstairs_npcs[c]->walking_direction);
		}
	}
	if(walking_into_door(RANGE_CITYFireDepartmentQuartersToUpstairs))
	{
		MAP_change_map(MAP_bobsgame_CITYFireDepartmentUpstairs,27,21);return;
	}
	if(walking_into_door(RANGE_CITYFireDepartmentQuartersToBedroom))
	{
		MAP_change_map(MAP_bobsgame_CITYFireDepartmentBedroom,25,10);return;
	}
	if(walking_into_door(RANGE_CITYFireDepartmentQuartersToBathroom))
	{
		MAP_change_map(MAP_bobsgame_CITYFireDepartmentBathroom,5,10);return;
	}
}
void bobsgame_CITYFireDepartmentQuarters_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYFireDepartmentQuarters_Map_VBL_Function()
{

}
void bobsgame_CITYFireDepartmentQuarters_Map_HBL_Function()
{

}
//========================================================
//CITYFireDepartmentBedroom
//========================================================
void bobsgame_CITYFireDepartmentBedroom_Map_Load_Function()
{
//RANGE_CITYFireDepartmentBedroomToQuarters 23*8,9*8,27*8,10*8
//RANGE_CITYFireDepartmentBedroomToBathroom 28*8,28*8,29*8,32*8
}
void bobsgame_CITYFireDepartmentBedroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//should have one guy asleep
//4,14 down
	static NPC* sleepingff_npc = NULL;
	if(sleepingff_npc==NULL)
	{
		//NPC_create_random_ADULT_xy_feet(&sleepingff_npc,2*8,2*8);
		NPC_create_npc_xy_feet(&sleepingff_npc,GFX_ADULT_firefighter,16,40,4*8,14*8);
		sleepingff_npc->non_walkable=1;
		sleepingff_npc->layer=1;
		NPC_animate_stand_dir(&sleepingff_npc,UP);
		sleepingff_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		sleepingff_npc->walk_dir=sleepingff_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&sleepingff_npc, sleepingff_npc->anim_direction);
	}
	if(sleepingff_npc!=NULL)
	{
		//if(NPC_in_range_of_npc_amt(&PLAYER_npc,sleepingff_npc,15))NPC_stare_at_npc(&sleepingff_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&sleepingff_npc, sleepingff_npc->walking_direction);
		//if(NPC_in_range_of_npc_amt(&PLAYER_npc,sleepingff_npc,35))NPC_stare_at_npc(&sleepingff_npc,PLAYER_npc);
		//else
		//{
		//	if(sleepingff_npc->cycle==0){if(sleepingff_npc->vbl_timer>200){if(r(4)==0){sleepingff_npc->cycle=1+r(3);}else{sleepingff_npc->vbl_timer=0;NPC_animate_set_direction_now(&sleepingff_npc, sleepingff_npc->walking_direction);if(sleepingff_npc->anim_frame_count!=0){sleepingff_npc->anim_frame_count=3;NPC_animate_increment_direction_frame_now(&sleepingff_npc, sleepingff_npc->walking_direction);}}}}
		//	if(sleepingff_npc->cycle==1){if(sleepingff_npc->walking_direction==UP||sleepingff_npc->walking_direction==DOWN)NPC_animate_set_direction_now(&sleepingff_npc,LEFT);else NPC_animate_set_direction_now(&sleepingff_npc,UP);sleepingff_npc->vbl_timer=r(120);sleepingff_npc->cycle=0;}
		//	if(sleepingff_npc->cycle==2){if(sleepingff_npc->walking_direction==UP||sleepingff_npc->walking_direction==DOWN)NPC_animate_set_direction_now(&sleepingff_npc,RIGHT);else NPC_animate_set_direction_now(&sleepingff_npc,DOWN);sleepingff_npc->vbl_timer=r(120);sleepingff_npc->cycle=0;}
		//	if(sleepingff_npc->cycle==3){NPC_animate_increment_direction_frame_now(&sleepingff_npc,sleepingff_npc->walking_direction);sleepingff_npc->vbl_timer=r(120);sleepingff_npc->cycle=0;}
		//}
		if(ACTION_range_xy_xy(2*8,12*8,5*8,16*8,"Wake Up Firefighter"))
		{
			TEXT_set_sprite_window(0,sleepingff_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
			//TODO: snoring sound
			//TODO: have him jump up, run off
			//fire truck is gone?
			//maybe sabotage fire truck or something, then set a fire somewhere else
		}
	}

	if(walking_into_door(RANGE_CITYFireDepartmentBedroomToQuarters))
	{
		MAP_change_map(MAP_bobsgame_CITYFireDepartmentQuarters,25,30);return;
	}
	if(walking_into_door(RANGE_CITYFireDepartmentBedroomToBathroom))
	{
		MAP_change_map(MAP_bobsgame_CITYFireDepartmentBathroom,2,29);return;
	}
}
void bobsgame_CITYFireDepartmentBedroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYFireDepartmentBedroom_Map_VBL_Function()
{

}
void bobsgame_CITYFireDepartmentBedroom_Map_HBL_Function()
{

}
//========================================================
//CITYFireDepartmentBathroom
//========================================================
void bobsgame_CITYFireDepartmentBathroom_Map_Load_Function()
{
//RANGE_CITYFireDepartmentBathroomToQuarters 3*8,9*8,7*8,10*8
//RANGE_CITYFireDepartmentBathroomToBedroom 1*8,28*8,2*8,32*8
}
void bobsgame_CITYFireDepartmentBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//TODO: shower running sfx
//TODO: hmm need water running tile
//17,28 face right under 2

	static NPC* showeringff_npc = NULL;
	if(showeringff_npc==NULL)
	{
		//NPC_create_random_ADULT_xy_feet(&showeringff_npc,2*8,2*8);
		NPC_create_npc_xy_feet(&showeringff_npc,GFX_ADULT_firefighter,16,40,17*8+4,28*8);
		showeringff_npc->non_walkable=1;
		showeringff_npc->layer=3;
		NPC_animate_stand_dir(&showeringff_npc,RIGHT);
		showeringff_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		showeringff_npc->walk_dir=showeringff_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&showeringff_npc, showeringff_npc->anim_direction);
	}
	if(showeringff_npc!=NULL)
	{
		//if(NPC_in_range_of_npc_amt(&PLAYER_npc,showeringff_npc,15))NPC_stare_at_npc(&showeringff_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&showeringff_npc, showeringff_npc->walking_direction);
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&showeringff_npc,15))NPC_stare_at_npc(&showeringff_npc,&PLAYER_npc);
		else
		{
			if(showeringff_npc->AI==0){if(showeringff_npc->vbls>200){if(r(4)==0){showeringff_npc->AI=1+r(3);}else{showeringff_npc->vbls=0;NPC_animate_stand_dir(&showeringff_npc, showeringff_npc->walk_dir);if(showeringff_npc->anim_frame_count!=0){showeringff_npc->anim_frame_count=3;NPC_animate(&showeringff_npc);}}}}
			if(showeringff_npc->AI==1){if(showeringff_npc->walk_dir==UP||showeringff_npc->walk_dir==DOWN)NPC_animate_stand_dir(&showeringff_npc,LEFT);else NPC_animate_stand_dir(&showeringff_npc,UP);showeringff_npc->vbls=r(120);showeringff_npc->AI=0;}
			if(showeringff_npc->AI==2){if(showeringff_npc->walk_dir==UP||showeringff_npc->walk_dir==DOWN)NPC_animate_stand_dir(&showeringff_npc,RIGHT);else NPC_animate_stand_dir(&showeringff_npc,DOWN);showeringff_npc->vbls=r(120);showeringff_npc->AI=0;}
			if(showeringff_npc->AI==3){NPC_animate(&showeringff_npc);showeringff_npc->vbls=r(120);showeringff_npc->AI=0;}
		}
		if(ACTION_range_xy_xy(16*8,28*8,17*8,31*8,"Talk To Showering Firefighter"))
		{
			TEXT_set_sprite_window(0,showeringff_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("" //?
			);
		}
	}

	static NPC* poopingfireman_npc = NULL;
	if(poopingfireman_npc==NULL)
	{
		//NPC_create_random_MAN_xy_feet(&poopingfireman_npc,11*8,11*8);
		NPC_create_npc_xy_feet(&poopingfireman_npc,GFX_ADULT_firefighter,16,40,11*8,11*8);
		poopingfireman_npc->non_walkable=1;
		poopingfireman_npc->layer=2;
		NPC_animate_stand_dir(&poopingfireman_npc,DOWN);
		poopingfireman_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		poopingfireman_npc->walk_dir=poopingfireman_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&poopingfireman_npc, poopingfireman_npc->anim_direction);
	}
	if(poopingfireman_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&poopingfireman_npc,45))NPC_stare_at_npc_not_opposite_walking_direction(&poopingfireman_npc,&PLAYER_npc);
		else if(poopingfireman_npc->AI==0){if(poopingfireman_npc->vbls>200){if(r(4)==0){poopingfireman_npc->AI=1+r(3);}else{poopingfireman_npc->vbls=0;NPC_animate_stand_dir(&poopingfireman_npc, poopingfireman_npc->walk_dir);if(poopingfireman_npc->anim_frame_count!=0){poopingfireman_npc->anim_frame_count=3;NPC_animate(&poopingfireman_npc);}}}}
		else if(poopingfireman_npc->AI==1){if(poopingfireman_npc->walk_dir==UP||poopingfireman_npc->walk_dir==DOWN)NPC_animate_stand_dir(&poopingfireman_npc,LEFT);else NPC_animate_stand_dir(&poopingfireman_npc,UP);poopingfireman_npc->vbls=r(120);poopingfireman_npc->AI=0;}
		else if(poopingfireman_npc->AI==2){if(poopingfireman_npc->walk_dir==UP||poopingfireman_npc->walk_dir==DOWN)NPC_animate_stand_dir(&poopingfireman_npc,RIGHT);else NPC_animate_stand_dir(&poopingfireman_npc,DOWN);poopingfireman_npc->vbls=r(120);poopingfireman_npc->AI=0;}
		else if(poopingfireman_npc->AI==3){NPC_animate(&poopingfireman_npc);poopingfireman_npc->vbls=r(120);poopingfireman_npc->AI=0;}

		if(ACTION_range_xy_xy(11*8,13*8,13*8,14*8,"Talk To Pooping Firefighter"))
		{
			TEXT_set_sprite_window(0,poopingfireman_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	if(walking_into_door(RANGE_CITYFireDepartmentBathroomToQuarters))
	{
		MAP_change_map(MAP_bobsgame_CITYFireDepartmentQuarters,32,30);return;
	}
	if(walking_into_door(RANGE_CITYFireDepartmentBathroomToBedroom))
	{
		MAP_change_map(MAP_bobsgame_CITYFireDepartmentBedroom,26,28);return;
	}
}
void bobsgame_CITYFireDepartmentBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYFireDepartmentBathroom_Map_VBL_Function()
{

}
void bobsgame_CITYFireDepartmentBathroom_Map_HBL_Function()
{

}


