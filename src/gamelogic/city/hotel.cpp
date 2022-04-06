//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"



#define RANGE_CITYHotelEntranceToOUTSIDECityLeft 70*8,60*8,76*8,61*8
#define RANGE_CITYHotelEntranceToOUTSIDECityRight 78*8,60*8,84*8,61*8
#define RANGE_CITYHotelEntranceToPool 43*8,20*8,51*8,21*8
#define RANGE_CITYHotelEntranceToElevator 6*8,19*8,12*8,20*8
#define RANGE_CITYHotelEntranceToElevator2 22*8,19*8,28*8,20*8
#define RANGE_CITYHotelPoolToEntrance 11*8,56*8,19*8,57*8
#define RANGE_CITYHotelPoolToSauna 46*8,20*8,50*8,21*8
#define RANGE_CITYHotelSaunaToPool 4*8,22*8,8*8,23*8
#define RANGE_CITYHotelElevatorToSelectedFloor 5*8,19*8,11*8,20*8
#define RANGE_CITYHotelHallwayToElevator 6*8,37*8,12*8,38*8
#define RANGE_CITYHotelHallwayToElevator2 22*8,37*8,28*8,38*8
#define RANGE_CITYHotelHallwayToHotelRoom 23*8,9*8,27*8,10*8
#define RANGE_CITYHotelHallwayToLinenCloset 83*8,37*8,87*8,38*8
#define RANGE_CITYHotelRoomToHallway 22*8,40*8,26*8,41*8
#define RANGE_CITYHotelRoomToBathroom 15*8,35*8,16*8,39*8
#define RANGE_CITYHotelRoomBathroomToHotelRoom 15*8,11*8,16*8,16*8
#define RANGE_CITYHotelElevator2ToSelectedFloor 5*8,19*8,11*8,20*8
#define RANGE_CITYHotelLinenClosetToHallway 3*8,20*8,7*8,21*8




//========================================================
//CITYHotelEntrance
//========================================================
void bobsgame_CITYHotelEntrance_Map_Load_Function()
{
//RANGE_CITYHotelEntranceToOUTSIDECityLeft 70*8,60*8,76*8,61*8
//RANGE_CITYHotelEntranceToOUTSIDECityRight 78*8,60*8,84*8,61*8
//RANGE_CITYHotelEntranceToPool 43*8,20*8,51*8,21*8
//RANGE_CITYHotelEntranceToElevator 6*8,19*8,12*8,20*8
//RANGE_CITYHotelEntranceToElevator2 22*8,19*8,28*8,20*8
}
void bobsgame_CITYHotelEntrance_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//68 36 down under 2
//75,26
//83,36
//91,43 left

	static NPC* hotelclerk1_npc = NULL;
	if(hotelclerk1_npc==NULL)
	{
		NPC_create_random_ADULT_xy_feet(&hotelclerk1_npc,68*8,36*8);
		//NPC_create_npc_xy_feet(&hotelclerk1_npc,SPRITE,16,40,7*8,27*8);
		hotelclerk1_npc->non_walkable=1;
		hotelclerk1_npc->layer=3;
		NPC_animate_stand_dir(&hotelclerk1_npc,DOWN);
		hotelclerk1_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		hotelclerk1_npc->walk_dir=hotelclerk1_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&hotelclerk1_npc, hotelclerk1_npc->anim_direction);
	}
	if(hotelclerk1_npc!=NULL)
	{
		//if(NPC_in_range_of_npc_amt(&PLAYER_npc,hotelclerk1_npc,15))NPC_stare_at_npc(&hotelclerk1_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&hotelclerk1_npc, hotelclerk1_npc->walking_direction);
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&hotelclerk1_npc,35))NPC_stare_at_npc(&hotelclerk1_npc,&PLAYER_npc);
		else
		{
			if(hotelclerk1_npc->AI==0){if(hotelclerk1_npc->vbls>200){if(r(4)==0){hotelclerk1_npc->AI=1+r(3);}else{hotelclerk1_npc->vbls=0;NPC_animate_stand_dir(&hotelclerk1_npc, hotelclerk1_npc->walk_dir);if(hotelclerk1_npc->anim_frame_count!=0){hotelclerk1_npc->anim_frame_count=3;NPC_animate(&hotelclerk1_npc);}}}}
			if(hotelclerk1_npc->AI==1){if(hotelclerk1_npc->walk_dir==UP||hotelclerk1_npc->walk_dir==DOWN)NPC_animate_stand_dir(&hotelclerk1_npc,LEFT);else NPC_animate_stand_dir(&hotelclerk1_npc,UP);hotelclerk1_npc->vbls=r(120);hotelclerk1_npc->AI=0;}
			if(hotelclerk1_npc->AI==2){if(hotelclerk1_npc->walk_dir==UP||hotelclerk1_npc->walk_dir==DOWN)NPC_animate_stand_dir(&hotelclerk1_npc,RIGHT);else NPC_animate_stand_dir(&hotelclerk1_npc,DOWN);hotelclerk1_npc->vbls=r(120);hotelclerk1_npc->AI=0;}
			if(hotelclerk1_npc->AI==3){NPC_animate(&hotelclerk1_npc);hotelclerk1_npc->vbls=r(120);hotelclerk1_npc->AI=0;}
		}
		if(ACTION_range_xy_xy(67*8,39*8,71*8,40*8,"Talk To Hotel Clerk"))
		{
			TEXT_set_sprite_window(0,hotelclerk1_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("" //?
			);
		}
	}
	static NPC* hotelclerk2_npc = NULL;
	if(hotelclerk2_npc==NULL)
	{
		NPC_create_random_ADULT_xy_feet(&hotelclerk2_npc,75*8,36*8);
		//NPC_create_npc_xy_feet(&hotelclerk2_npc,SPRITE,16,40,7*8,27*8);
		hotelclerk2_npc->non_walkable=1;
		hotelclerk2_npc->layer=3;
		NPC_animate_stand_dir(&hotelclerk2_npc,DOWN);
		hotelclerk2_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		hotelclerk2_npc->walk_dir=hotelclerk2_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&hotelclerk2_npc, hotelclerk2_npc->anim_direction);
	}
	if(hotelclerk2_npc!=NULL)
	{
		//if(NPC_in_range_of_npc_amt(&PLAYER_npc,hotelclerk2_npc,15))NPC_stare_at_npc(&hotelclerk2_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&hotelclerk2_npc, hotelclerk2_npc->walking_direction);
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&hotelclerk2_npc,35))NPC_stare_at_npc(&hotelclerk2_npc,&PLAYER_npc);
		else
		{
			if(hotelclerk2_npc->AI==0){if(hotelclerk2_npc->vbls>200){if(r(4)==0){hotelclerk2_npc->AI=1+r(3);}else{hotelclerk2_npc->vbls=0;NPC_animate_stand_dir(&hotelclerk2_npc, hotelclerk2_npc->walk_dir);if(hotelclerk2_npc->anim_frame_count!=0){hotelclerk2_npc->anim_frame_count=3;NPC_animate(&hotelclerk2_npc);}}}}
			if(hotelclerk2_npc->AI==1){if(hotelclerk2_npc->walk_dir==UP||hotelclerk2_npc->walk_dir==DOWN)NPC_animate_stand_dir(&hotelclerk2_npc,LEFT);else NPC_animate_stand_dir(&hotelclerk2_npc,UP);hotelclerk2_npc->vbls=r(120);hotelclerk2_npc->AI=0;}
			if(hotelclerk2_npc->AI==2){if(hotelclerk2_npc->walk_dir==UP||hotelclerk2_npc->walk_dir==DOWN)NPC_animate_stand_dir(&hotelclerk2_npc,RIGHT);else NPC_animate_stand_dir(&hotelclerk2_npc,DOWN);hotelclerk2_npc->vbls=r(120);hotelclerk2_npc->AI=0;}
			if(hotelclerk2_npc->AI==3){NPC_animate(&hotelclerk2_npc);hotelclerk2_npc->vbls=r(120);hotelclerk2_npc->AI=0;}
		}
		if(ACTION_range_xy_xy(74*8,39*8,77*8,40*8,"Talk To Hotel Clerk"))
		{
			TEXT_set_sprite_window(0,hotelclerk2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("" //?
			);
		}
	}
	static NPC* hotelclerk3_npc = NULL;
	if(hotelclerk3_npc==NULL)
	{
		NPC_create_random_ADULT_xy_feet(&hotelclerk3_npc,83*8,36*8);
		//NPC_create_npc_xy_feet(&hotelclerk3_npc,SPRITE,16,40,7*8,27*8);
		hotelclerk3_npc->non_walkable=1;
		hotelclerk3_npc->layer=3;
		NPC_animate_stand_dir(&hotelclerk3_npc,DOWN);
		hotelclerk3_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		hotelclerk3_npc->walk_dir=hotelclerk3_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&hotelclerk3_npc, hotelclerk3_npc->anim_direction);
	}
	if(hotelclerk3_npc!=NULL)
	{
		//if(NPC_in_range_of_npc_amt(&PLAYER_npc,hotelclerk3_npc,15))NPC_stare_at_npc(&hotelclerk3_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&hotelclerk3_npc, hotelclerk3_npc->walking_direction);
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&hotelclerk3_npc,35))NPC_stare_at_npc(&hotelclerk3_npc,&PLAYER_npc);
		else
		{
			if(hotelclerk3_npc->AI==0){if(hotelclerk3_npc->vbls>200){if(r(4)==0){hotelclerk3_npc->AI=1+r(3);}else{hotelclerk3_npc->vbls=0;NPC_animate_stand_dir(&hotelclerk3_npc, hotelclerk3_npc->walk_dir);if(hotelclerk3_npc->anim_frame_count!=0){hotelclerk3_npc->anim_frame_count=3;NPC_animate(&hotelclerk3_npc);}}}}
			if(hotelclerk3_npc->AI==1){if(hotelclerk3_npc->walk_dir==UP||hotelclerk3_npc->walk_dir==DOWN)NPC_animate_stand_dir(&hotelclerk3_npc,LEFT);else NPC_animate_stand_dir(&hotelclerk3_npc,UP);hotelclerk3_npc->vbls=r(120);hotelclerk3_npc->AI=0;}
			if(hotelclerk3_npc->AI==2){if(hotelclerk3_npc->walk_dir==UP||hotelclerk3_npc->walk_dir==DOWN)NPC_animate_stand_dir(&hotelclerk3_npc,RIGHT);else NPC_animate_stand_dir(&hotelclerk3_npc,DOWN);hotelclerk3_npc->vbls=r(120);hotelclerk3_npc->AI=0;}
			if(hotelclerk3_npc->AI==3){NPC_animate(&hotelclerk3_npc);hotelclerk3_npc->vbls=r(120);hotelclerk3_npc->AI=0;}
		}
		if(ACTION_range_xy_xy(82*8,39*8,86*8,40*8,"Talk To Hotel Clerk"))
		{
			TEXT_set_sprite_window(0,hotelclerk3_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("" //?
			);
		}
	}
	static NPC* hotelclerk4_npc = NULL;
	if(hotelclerk4_npc==NULL)
	{
		NPC_create_random_ADULT_xy_feet(&hotelclerk4_npc,92*8,43*8);
		//NPC_create_npc_xy_feet(&hotelclerk4_npc,SPRITE,16,40,7*8,27*8);
		hotelclerk4_npc->non_walkable=1;
		hotelclerk4_npc->layer=3;
		NPC_animate_stand_dir(&hotelclerk4_npc,LEFT);
		hotelclerk4_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		hotelclerk4_npc->walk_dir=hotelclerk4_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&hotelclerk4_npc, hotelclerk4_npc->anim_direction);
	}
	if(hotelclerk4_npc!=NULL)
	{
		//if(NPC_in_range_of_npc_amt(&PLAYER_npc,hotelclerk4_npc,15))NPC_stare_at_npc(&hotelclerk4_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&hotelclerk4_npc, hotelclerk4_npc->walking_direction);
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&hotelclerk4_npc,35))NPC_stare_at_npc(&hotelclerk4_npc,&PLAYER_npc);
		else
		{
			if(hotelclerk4_npc->AI==0){if(hotelclerk4_npc->vbls>200){if(r(4)==0){hotelclerk4_npc->AI=1+r(3);}else{hotelclerk4_npc->vbls=0;NPC_animate_stand_dir(&hotelclerk4_npc, hotelclerk4_npc->walk_dir);if(hotelclerk4_npc->anim_frame_count!=0){hotelclerk4_npc->anim_frame_count=3;NPC_animate(&hotelclerk4_npc);}}}}
			if(hotelclerk4_npc->AI==1){if(hotelclerk4_npc->walk_dir==UP||hotelclerk4_npc->walk_dir==DOWN)NPC_animate_stand_dir(&hotelclerk4_npc,LEFT);else NPC_animate_stand_dir(&hotelclerk4_npc,UP);hotelclerk4_npc->vbls=r(120);hotelclerk4_npc->AI=0;}
			if(hotelclerk4_npc->AI==2){if(hotelclerk4_npc->walk_dir==UP||hotelclerk4_npc->walk_dir==DOWN)NPC_animate_stand_dir(&hotelclerk4_npc,RIGHT);else NPC_animate_stand_dir(&hotelclerk4_npc,DOWN);hotelclerk4_npc->vbls=r(120);hotelclerk4_npc->AI=0;}
			if(hotelclerk4_npc->AI==3){NPC_animate(&hotelclerk4_npc);hotelclerk4_npc->vbls=r(120);hotelclerk4_npc->AI=0;}
		}
		if(ACTION_range_xy_xy(88*8,39*8,89*8,47*8,"Talk To Hotel Clerk"))
		{
			TEXT_set_sprite_window(0,hotelclerk4_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("" //?
			);
		}
	}

//29,52
//58,52 bellhop
//TODO: need bellhop sprite

	static NPC* bellhop_npc = NULL;
	if(bellhop_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&bellhop_npc,,16,40,58*8,52*8);
		NPC_create_random_ADULT_xy_feet(&bellhop_npc,58*8,52*8);
		bellhop_npc->layer=2;
		bellhop_npc->non_walkable=1;
		NPC_animate_stand_dir(&bellhop_npc,DOWN);
		bellhop_npc->walking_speed = SPEED_SLOW;//+(r(SPEED_SLOWEST-SPEED_FAST));
		bellhop_npc->AI=0;
	}
	if(bellhop_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&bellhop_npc,20))NPC_stare_at_npc(&bellhop_npc,&PLAYER_npc);
		//else NPC_animate_set_direction_now(&bellhop_npc, LEFT);
		else if(bellhop_npc->AI== 0){if(NPC_walk_to_xy_nohit_pushmain(&bellhop_npc,bellhop_npc->walking_speed, 60*8,52*8)==1){NPC_animate_stand_dir(&bellhop_npc,DOWN);bellhop_npc->vbls=r(40);bellhop_npc->AI++;}}
		else if(bellhop_npc->AI== 1){if(bellhop_npc->vbls>60)bellhop_npc->AI++;}
		else if(bellhop_npc->AI== 2){NPC_animate_stand_dir(&bellhop_npc,LEFT);bellhop_npc->vbls=r(40);bellhop_npc->AI++;}
		else if(bellhop_npc->AI== 3){if(bellhop_npc->vbls>60)bellhop_npc->AI++;}
		else if(bellhop_npc->AI== 4){if(NPC_walk_to_xy_nohit_pushmain(&bellhop_npc,bellhop_npc->walking_speed,66*8,52*8)==1){bellhop_npc->vbls=r(40);bellhop_npc->AI++;}}
		else if(bellhop_npc->AI== 5){if(NPC_walk_to_xy_nohit_pushmain(&bellhop_npc,bellhop_npc->walking_speed,66*8,56*8)==1){NPC_animate_stand_dir(&bellhop_npc,LEFT);bellhop_npc->vbls=r(40);bellhop_npc->AI++;}}
		else if(bellhop_npc->AI== 6){if(bellhop_npc->vbls>60)bellhop_npc->AI++;}
		else if(bellhop_npc->AI== 7){if(NPC_walk_to_xy_nohit_pushmain(&bellhop_npc,bellhop_npc->walking_speed,66*8,52*8)==1){bellhop_npc->vbls=r(40);bellhop_npc->AI++;}}
		else if(bellhop_npc->AI== 8){if(NPC_walk_to_xy_nohit_pushmain(&bellhop_npc,bellhop_npc->walking_speed,59*8+4,52*8)==1){bellhop_npc->vbls=r(40);bellhop_npc->AI++;}}
		else if(bellhop_npc->AI== 9){if(NPC_walk_to_xy_nohit_pushmain(&bellhop_npc,bellhop_npc->walking_speed,59*8+4,57*8)==1){NPC_animate_stand_dir(&bellhop_npc,LEFT);bellhop_npc->vbls=r(40);bellhop_npc->AI++;}}
		else if(bellhop_npc->AI==10){if(bellhop_npc->vbls>60)bellhop_npc->AI++;}
		else if(bellhop_npc->AI==11){NPC_animate_stand_dir(&bellhop_npc,RIGHT);bellhop_npc->vbls=r(40);bellhop_npc->AI++;}
		else if(bellhop_npc->AI==12){if(bellhop_npc->vbls>60)bellhop_npc->AI=0;}

		if(ACTION_npc(&bellhop_npc,"Talk To Bellhop"))
		{
			TEXT_set_sprite_window(0,bellhop_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

//11,41 down couch
// 4,50 right couch
	static NPC* couchperson1_npc = NULL;
	if(couchperson1_npc==NULL)
	{
		NPC_create_random_ADULT_xy_feet(&couchperson1_npc,11*8,41*8);
		//NPC_create_npc_xy_feet(&couchperson1_npc,SPRITE,16,40,7*8,27*8);
		couchperson1_npc->non_walkable=1;
		couchperson1_npc->layer=2;
		NPC_animate_stand_dir(&couchperson1_npc,DOWN);
		couchperson1_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		couchperson1_npc->walk_dir=couchperson1_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&couchperson1_npc, couchperson1_npc->anim_direction);
	}
	if(couchperson1_npc!=NULL)
	{
		//if(NPC_in_range_of_npc_amt(&PLAYER_npc,couchperson1_npc,15))NPC_stare_at_npc(&couchperson1_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&couchperson1_npc, couchperson1_npc->walking_direction);
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&couchperson1_npc,35))NPC_stare_at_npc(&couchperson1_npc,&PLAYER_npc);
		else
		{
			if(couchperson1_npc->AI==0){if(couchperson1_npc->vbls>200){if(r(4)==0){couchperson1_npc->AI=1+r(3);}else{couchperson1_npc->vbls=0;NPC_animate_stand_dir(&couchperson1_npc, couchperson1_npc->walk_dir);if(couchperson1_npc->anim_frame_count!=0){couchperson1_npc->anim_frame_count=3;NPC_animate(&couchperson1_npc);}}}}
			if(couchperson1_npc->AI==1){if(couchperson1_npc->walk_dir==UP||couchperson1_npc->walk_dir==DOWN)NPC_animate_stand_dir(&couchperson1_npc,LEFT);else NPC_animate_stand_dir(&couchperson1_npc,UP);couchperson1_npc->vbls=r(120);couchperson1_npc->AI=0;}
			if(couchperson1_npc->AI==2){if(couchperson1_npc->walk_dir==UP||couchperson1_npc->walk_dir==DOWN)NPC_animate_stand_dir(&couchperson1_npc,RIGHT);else NPC_animate_stand_dir(&couchperson1_npc,DOWN);couchperson1_npc->vbls=r(120);couchperson1_npc->AI=0;}
			if(couchperson1_npc->AI==3){NPC_animate(&couchperson1_npc);couchperson1_npc->vbls=r(120);couchperson1_npc->AI=0;}
		}
		if(ACTION_npc(&couchperson1_npc,"Talk To Esteemed Patron"))
		{
			TEXT_set_sprite_window(0,couchperson1_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("" //?
			);
		}
	}
	static NPC* couchperson2_npc = NULL;
	if(couchperson2_npc==NULL)
	{
		NPC_create_random_ADULT_xy_feet(&couchperson2_npc,5*8,50*8);
		//NPC_create_npc_xy_feet(&couchperson2_npc,SPRITE,16,40,7*8,27*8);
		couchperson2_npc->non_walkable=1;
		couchperson2_npc->layer=2;
		NPC_animate_stand_dir(&couchperson2_npc,RIGHT);
		couchperson2_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		couchperson2_npc->walk_dir=couchperson2_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&couchperson2_npc, couchperson2_npc->anim_direction);
	}
	if(couchperson2_npc!=NULL)
	{
		//if(NPC_in_range_of_npc_amt(&PLAYER_npc,couchperson2_npc,15))NPC_stare_at_npc(&couchperson2_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&couchperson2_npc, couchperson2_npc->walking_direction);
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&couchperson2_npc,35))NPC_stare_at_npc_not_opposite_walking_direction(&couchperson2_npc,&PLAYER_npc);
		else
		{
			if(couchperson2_npc->AI==0){if(couchperson2_npc->vbls>200){if(r(4)==0){couchperson2_npc->AI=1+r(3);}else{couchperson2_npc->vbls=0;NPC_animate_stand_dir(&couchperson2_npc, couchperson2_npc->walk_dir);if(couchperson2_npc->anim_frame_count!=0){couchperson2_npc->anim_frame_count=3;NPC_animate(&couchperson2_npc);}}}}
			if(couchperson2_npc->AI==1){if(couchperson2_npc->walk_dir==UP||couchperson2_npc->walk_dir==DOWN)NPC_animate_stand_dir(&couchperson2_npc,LEFT);else NPC_animate_stand_dir(&couchperson2_npc,UP);couchperson2_npc->vbls=r(120);couchperson2_npc->AI=0;}
			if(couchperson2_npc->AI==2){if(couchperson2_npc->walk_dir==UP||couchperson2_npc->walk_dir==DOWN)NPC_animate_stand_dir(&couchperson2_npc,RIGHT);else NPC_animate_stand_dir(&couchperson2_npc,DOWN);couchperson2_npc->vbls=r(120);couchperson2_npc->AI=0;}
			if(couchperson2_npc->AI==3){NPC_animate(&couchperson2_npc);couchperson2_npc->vbls=r(120);couchperson2_npc->AI=0;}
		}
		if(ACTION_npc(&couchperson2_npc,"Talk To Honored Guest"))
		{
			TEXT_set_sprite_window(0,couchperson2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("" //?
			);
		}
	}
	if(walking_into_door(RANGE_CITYHotelEntranceToOUTSIDECityLeft))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,1021,39);return;
	}
	if(walking_into_door(RANGE_CITYHotelEntranceToOUTSIDECityRight))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,1029,39);return;
	}
	if(walking_into_door(RANGE_CITYHotelEntranceToPool))
	{
		MAP_change_map(MAP_bobsgame_CITYHotelPool,14,55);return;
	}
	if(walking_into_door(RANGE_CITYHotelEntranceToElevator))
	{
		MAP_change_map(MAP_bobsgame_CITYHotelElevator,7,18);return;
	}
	if(walking_into_door(RANGE_CITYHotelEntranceToElevator2))
	{
		MAP_change_map(MAP_bobsgame_CITYHotelElevator2,7,18);return;
	}
}
void bobsgame_CITYHotelEntrance_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHotelEntrance_Map_VBL_Function()
{

}
void bobsgame_CITYHotelEntrance_Map_HBL_Function()
{

}
//========================================================
//CITYHotelPool
//========================================================
void bobsgame_CITYHotelPool_Map_Load_Function()
{
//RANGE_CITYHotelPoolToEntrance 11*8,56*8,19*8,57*8
//RANGE_CITYHotelPoolToSauna 46*8,20*8,50*8,21*8
}
void bobsgame_CITYHotelPool_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//lifeguard at 33,48 face right, up?
//TODO: need lifeguard sprite

	static NPC* lifeguard_npc = NULL;
	if(lifeguard_npc==NULL)
	{
		NPC_create_random_ADULT_xy_feet(&lifeguard_npc,33*8,48*8);
		//NPC_create_npc_xy_feet(&lifeguard_npc,SPRITE,16,40,7*8,27*8);
		lifeguard_npc->non_walkable=1;
		lifeguard_npc->layer=1;
		NPC_animate_stand_dir(&lifeguard_npc,RIGHT);
		lifeguard_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		lifeguard_npc->walk_dir=lifeguard_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&lifeguard_npc, lifeguard_npc->anim_direction);
	}
	if(lifeguard_npc!=NULL)
	{
		//if(NPC_in_range_of_npc_amt(&PLAYER_npc,lifeguard_npc,15))NPC_stare_at_npc(&lifeguard_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&lifeguard_npc, lifeguard_npc->walking_direction);
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&lifeguard_npc,35))NPC_stare_at_npc_not_opposite_walking_direction(&lifeguard_npc,&PLAYER_npc);
		else
		{
			if(lifeguard_npc->AI==0){if(lifeguard_npc->vbls>200){if(r(4)==0){lifeguard_npc->AI=1+r(3);}else{lifeguard_npc->vbls=0;NPC_animate_stand_dir(&lifeguard_npc, lifeguard_npc->walk_dir);if(lifeguard_npc->anim_frame_count!=0){lifeguard_npc->anim_frame_count=3;NPC_animate(&lifeguard_npc);}}}}
			if(lifeguard_npc->AI==1){if(lifeguard_npc->walk_dir==UP||lifeguard_npc->walk_dir==DOWN)NPC_animate_stand_dir(&lifeguard_npc,LEFT);else NPC_animate_stand_dir(&lifeguard_npc,UP);lifeguard_npc->vbls=r(120);lifeguard_npc->AI=0;}
			if(lifeguard_npc->AI==2){if(lifeguard_npc->walk_dir==UP||lifeguard_npc->walk_dir==DOWN)NPC_animate_stand_dir(&lifeguard_npc,RIGHT);else NPC_animate_stand_dir(&lifeguard_npc,DOWN);lifeguard_npc->vbls=r(120);lifeguard_npc->AI=0;}
			if(lifeguard_npc->AI==3){NPC_animate(&lifeguard_npc);lifeguard_npc->vbls=r(120);lifeguard_npc->AI=0;}
		}
		if(ACTION_range_xy_xy(30*8,48*8,33*8,51*8,"Talk To Lifeguard"))
		{
			TEXT_set_sprite_window(0,lifeguard_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("" //?
			);
		}
	}

//TODO: need person lying horizontal sprite
//TODO: need swimsuit sprites
//60,51 face down
//58,32 face left over 1
//58,60 left over 1
//57,50 over 1 face left

//10,17 jacuzzi face right under 0
//14,15 face down
//15,17 face left

	static NPC* outsidepool_npcs[7] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<7;c++)
	{
		if(outsidepool_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			GFX* gfx=NULL;

			if(c== 0){x=60*8;y=35*8;dir=DOWN;	bgp=1;  }
			if(c== 1){x=58*8;y=31*8;dir=LEFT;	bgp=1;  }
			if(c== 2){x=58*8;y=59*8;dir=LEFT;	bgp=1;  }
			if(c== 3){x=58*8;y=49*8;dir=LEFT;	bgp=1;  }
			if(c== 4){x=10*8;y=17*8;dir=RIGHT;	bgp=2;	}
			if(c== 5){x=14*8;y=15*8;dir=DOWN;	bgp=2;	}
			if(c== 6){x=16*8;y=17*8;dir=LEFT;	bgp=2;	}

			if(gfx==NULL)NPC_create_random_ADULT_xy_feet(&outsidepool_npcs[c],x,y);
			else NPC_create_npc_xy_feet(&outsidepool_npcs[c],gfx,16,40,x,y);

			NPC_animate_stand_dir(&outsidepool_npcs[c], dir);
			outsidepool_npcs[c]->non_walkable=1;
			outsidepool_npcs[c]->walk_dir=dir;
			outsidepool_npcs[c]->layer=bgp;
			//NPC_animate_increment_direction_frame_now(&outsidepool_npcs[c], dir);

		}

		if(outsidepool_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&outsidepool_npcs[c],15))NPC_stare_at_npc_not_opposite_walking_direction(&outsidepool_npcs[c],&PLAYER_npc);
			else if(outsidepool_npcs[c]->AI==0){if(outsidepool_npcs[c]->vbls>200){if(r(4)==0){outsidepool_npcs[c]->AI=1+r(3);}else{outsidepool_npcs[c]->vbls=0;NPC_animate_stand_dir(&outsidepool_npcs[c], outsidepool_npcs[c]->walk_dir);if(outsidepool_npcs[c]->anim_frame_count!=0){outsidepool_npcs[c]->anim_frame_count=3;NPC_animate(&outsidepool_npcs[c]);}}}}
			else if(outsidepool_npcs[c]->AI==1){if(outsidepool_npcs[c]->walk_dir==UP||outsidepool_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&outsidepool_npcs[c],LEFT);else NPC_animate_stand_dir(&outsidepool_npcs[c],UP);outsidepool_npcs[c]->vbls=r(120);outsidepool_npcs[c]->AI=0;}
			else if(outsidepool_npcs[c]->AI==2){if(outsidepool_npcs[c]->walk_dir==UP||outsidepool_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&outsidepool_npcs[c],RIGHT);else NPC_animate_stand_dir(&outsidepool_npcs[c],DOWN);outsidepool_npcs[c]->vbls=r(120);outsidepool_npcs[c]->AI=0;}
			else if(outsidepool_npcs[c]->AI==3){NPC_animate(&outsidepool_npcs[c]);outsidepool_npcs[c]->vbls=r(120);outsidepool_npcs[c]->AI=0;}

			//if(NPC_in_range_of_npc_amt(&PLAYER_npc,outsidepool_npcs[c],15))NPC_stare_at_npc(&outsidepool_npcs[c],PLAYER_npc);
			//else NPC_animate_set_direction_now(&outsidepool_npcs[c], outsidepool_npcs[c]->walking_direction);
		}
	}

//TODO: need sprites half underwater
//snorkel kid?

//swimming from 35,34 to 51,59 deep end

	static NPC* swimming_npcs[15] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	c=0;
	for(c=0;c<15;c++)
	{
		if(swimming_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			GFX* gfx=NULL;

			x=(35*8)+r((51*8)-(35*8));
			y=(34*8)+r((59*8)-(34*8));

			if(gfx==NULL)NPC_create_random_ADULT_xy_feet(&swimming_npcs[c],x,y);
			else NPC_create_npc_xy_feet(&swimming_npcs[c],gfx,16,40,x,y);

			NPC_animate_stand_dir(&swimming_npcs[c], dir);
			swimming_npcs[c]->non_walkable=1;
			swimming_npcs[c]->walk_dir=dir;
			swimming_npcs[c]->layer=bgp;
			//NPC_animate_increment_direction_frame_now(&swimming_npcs[c], dir);
			swimming_npcs[c]->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));

		}

		if(swimming_npcs[c]!=NULL)
		{

			if(swimming_npcs[c]->AI==0)if(NPC_walk_randomly_within_xy_xy(&swimming_npcs[c],35*8,34*8,51*8,59*8)==1){swimming_npcs[c]->AI=1;swimming_npcs[c]->vbls=r(20);swimming_npcs[c]->pixels_to_walk=r(50);swimming_npcs[c]->walk_dir=r(4);}
			if(swimming_npcs[c]->AI==1)if(swimming_npcs[c]->vbls>30)swimming_npcs[c]->AI=0;

		}
	}

//shallow end 18,42  30,46
//TODO: kid with floaties, kid with innertube

//TODO: echo splashing
//maybe fuzzy bubble sound near jacuzzi

//TODO: cant go in pool unless in swimsuit
//TODO: need swimming action, move a few tiles, stop, move a few tiles, stop, etc.
//no footsteps, swimming noise

//special water in jacuzzi
//for layer 1,2, and 0
//switch tile 1 with 2-9 and 10 with 11-18
//might want to actually swap tile data or have many tiles in the pool, so the waves arent so patterny
//animate water.
	static int lastvbltimer = 0;
	if(lastvbltimer!=vbl_10_var)
	{
		lastvbltimer=vbl_10_var;
		static int tile=0;
		tile++;
		if(tile>7)tile=0;
		///HARDWARE_set_tile_gfx_to_tile(1,0,HARDWARE_map_0[1],HARDWARE_map_0[2+tile]);
		///HARDWARE_set_tile_gfx_to_tile(1,0,HARDWARE_map_0[10],HARDWARE_map_0[11+tile]);

		///HARDWARE_set_tile_gfx_to_tile(1,1,HARDWARE_map_2[1],HARDWARE_map_2[2+tile]);
		///HARDWARE_set_tile_gfx_to_tile(1,1,HARDWARE_map_2[10],HARDWARE_map_2[11+tile]);

		///HARDWARE_set_tile_gfx_to_tile(1,2,HARDWARE_map_2[1],HARDWARE_map_2[2+tile]);
		///HARDWARE_set_tile_gfx_to_tile(1,2,HARDWARE_map_2[10],HARDWARE_map_2[11+tile]);
	}

	if(walking_into_door(RANGE_CITYHotelPoolToEntrance))
	{
		MAP_change_map(MAP_bobsgame_CITYHotelEntrance,46,21);return;
	}
	if(walking_into_door(RANGE_CITYHotelPoolToSauna))
	{
		MAP_change_map(MAP_bobsgame_CITYHotelSauna,6,21);return;
	}
}
void bobsgame_CITYHotelPool_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHotelPool_Map_VBL_Function()
{

}
void bobsgame_CITYHotelPool_Map_HBL_Function()
{

}
//========================================================
//CITYHotelSauna
//========================================================
void bobsgame_CITYHotelSauna_Map_Load_Function()
{
//RANGE_CITYHotelSaunaToPool 4*8,22*8,8*8,23*8
}
void bobsgame_CITYHotelSauna_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{
		///TODO: MUST FIX THIS!
		///HARDWARE_set_bg_over(1,0,2);
		//HARDWARE_set_fx(1,SFX_ALPHA,SFX_BG0,SFX_OBJ);
		//HARDWARE_set_fx(1,SFX_ALPHA,SFX_BG0,SFX_BG2|SFX_OBJ|SFX_BG3);
		///HARDWARE_set_fx(1,SFX_ALPHA,SFX_BG0,SFX_BG2|SFX_OBJ|SFX_BG3);
		///HARDWARE_set_fx_alpha_ratio(1,10,10);
	}

	//should the steam be sprites or tiles? hmmm...
	static int lastvbltimer = 0;
	if(lastvbltimer!=vbl_var/3)
	{
		lastvbltimer=vbl_var/3;

		///int t=1+r(4);

		///HARDWARE_set_tile_gfx_to_tile(1,0,HARDWARE_map_3[t],HARDWARE_map_3[5+r(12)]);
		//HARDWARE_set_tile_gfx_to_tile(1,0,HARDWARE_map_3[2],HARDWARE_map_3[5+r(12)]);
		//HARDWARE_set_tile_gfx_to_tile(1,0,HARDWARE_map_3[3],HARDWARE_map_3[5+r(12)]);
		//HARDWARE_set_tile_gfx_to_tile(1,0,HARDWARE_map_3[4],HARDWARE_map_3[5+r(12)]);
	}

//TODO: need nude old men in towels sprites
//6,11 down under 2
//9
//14

//19,17 left

	static NPC* sauna_npcs[4] = {NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<4;c++)
	{
		if(sauna_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			GFX* gfx=NULL;

			if(c== 0){x= 6*8;y=11*8+4;dir=DOWN;bgp=3;}
			if(c== 1){x= 9*8;y=11*8+4;dir=DOWN;bgp=3;}
			if(c== 2){x=14*8;y=11*8+4;dir=DOWN;bgp=3;}
			if(c== 3){x=19*8-2;y=17*8;dir=LEFT;bgp=3;}

			if(gfx==NULL)NPC_create_random_ADULT_xy_feet(&sauna_npcs[c],x,y);
			else NPC_create_npc_xy_feet(&sauna_npcs[c],gfx,16,40,x,y);

			NPC_animate_stand_dir(&sauna_npcs[c],dir);
			sauna_npcs[c]->non_walkable=1;
			sauna_npcs[c]->walk_dir=dir;
			sauna_npcs[c]->layer=bgp;
			//NPC_animate_increment_direction_frame_now(&sauna_npcs[c],dir);
		}

		if(sauna_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&sauna_npcs[c],15))NPC_stare_at_npc_not_opposite_walking_direction(&sauna_npcs[c],&PLAYER_npc);
			else if(sauna_npcs[c]->AI==0){if(sauna_npcs[c]->vbls>200){if(r(4)==0){sauna_npcs[c]->AI=1+r(3);}else{sauna_npcs[c]->vbls=0;NPC_animate_stand_dir(&sauna_npcs[c], sauna_npcs[c]->walk_dir);if(sauna_npcs[c]->anim_frame_count!=0){sauna_npcs[c]->anim_frame_count=3;NPC_animate(&sauna_npcs[c]);}}}}
			else if(sauna_npcs[c]->AI==1){if(sauna_npcs[c]->walk_dir==UP||sauna_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&sauna_npcs[c],LEFT);else NPC_animate_stand_dir(&sauna_npcs[c],UP);sauna_npcs[c]->vbls=r(120);sauna_npcs[c]->AI=0;}
			else if(sauna_npcs[c]->AI==2){if(sauna_npcs[c]->walk_dir==UP||sauna_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&sauna_npcs[c],RIGHT);else NPC_animate_stand_dir(&sauna_npcs[c],DOWN);sauna_npcs[c]->vbls=r(120);sauna_npcs[c]->AI=0;}
			else if(sauna_npcs[c]->AI==3){NPC_animate(&sauna_npcs[c]);sauna_npcs[c]->vbls=r(120);sauna_npcs[c]->AI=0;}

			//if(NPC_in_range_of_npc_amt(&PLAYER_npc,sauna_npcs[c],15))NPC_stare_at_npc(&sauna_npcs[c],PLAYER_npc);
			//else NPC_animate_set_direction_now(&sauna_npcs[c], sauna_npcs[c]->walking_direction);
		}
	}

	if(walking_into_door(RANGE_CITYHotelSaunaToPool))
	{
		MAP_change_map(MAP_bobsgame_CITYHotelPool,48,21);return;
	}
}
void bobsgame_CITYHotelSauna_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHotelSauna_Map_VBL_Function()
{

}
void bobsgame_CITYHotelSauna_Map_HBL_Function()
{

}
//========================================================
//CITYHotelElevator
//========================================================
void bobsgame_CITYHotelElevator_Map_Load_Function()
{
//RANGE_CITYHotelElevatorToSelectedFloor 5*8,19*8,11*8,20*8
}
void bobsgame_CITYHotelElevator_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
	static int floor=0;
	static int door_locked=0;
	int animate=0;
	if(ACTION_range_xy_xy(2*8,18*8,5*8,19*8,"Select Floor"))
	{
		TEXT_set_sprite_window(0,PLAYER_npc,NULL);
		TEXT_set_sprite_window(1,PLAYER_npc,NULL);
		TEXT_window("Which floor?<Q:Entrance 1F:Rooms 2F>"//TODO:Presidential Suite 10F>"
		);
	}
	//if select same floor no ding
	//if no floor selected leave to same floor
	//if selected floor cant leave while animating
	if(strcmp(TEXTANSWER_selected_answer_string,"Entrance 1F")==0&&floor!=0){floor=0;door_locked=1;animate=1;}
	if(strcmp(TEXTANSWER_selected_answer_string,"Rooms 2F")==0&&floor!=1){floor=1;door_locked=1;animate=1;}
	//if(strcmp(TEXTANSWER_selected_answer_string,"Presidential Suite 10F")==0&&floor!=2){floor=1;door_locked=1;animate=1;}
	//if animation done, ding sound
	if(animate==1)
	{
		//TODO: screen shake
		//ding
		HARDWARE_play_sound("elevatording",127,44100,0);
		door_locked=0;
		animate=0;
	}

	if(walking_into_door(RANGE_CITYHotelElevatorToSelectedFloor)
	&&door_locked==0)
	{
		//change to selected floor
		if(floor==0){MAP_change_map(MAP_bobsgame_CITYHotelEntrance,8,20);return;}
		if(floor==1){MAP_change_map(MAP_bobsgame_CITYHotelHallway,8,38);return;}
		if(floor==2){MAP_change_map(MAP_bobsgame_CITYHotelHallway,8,38);return;}
	}
}
void bobsgame_CITYHotelElevator_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHotelElevator_Map_VBL_Function()
{

}
void bobsgame_CITYHotelElevator_Map_HBL_Function()
{

}
//========================================================
//CITYHotelElevator2
//========================================================
void bobsgame_CITYHotelElevator2_Map_Load_Function()
{
//RANGE_CITYHotelElevator2ToSelectedFloor 5*8,19*8,11*8,20*8
}
void bobsgame_CITYHotelElevator2_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{
	}
	static int floor=0;
	static int door_locked=0;
	int animate=0;
	if(ACTION_range_xy_xy(2*8,18*8,5*8,19*8,"Select Floor"))
	{
		TEXT_set_sprite_window(0,PLAYER_npc,NULL);
		TEXT_set_sprite_window(1,PLAYER_npc,NULL);
		TEXT_window("Which floor?<Q:Entrance 1F:Rooms 2F>"//TODO:Presidential Suite 10F>"
		);
	}
	//if select same floor no ding
	//if no floor selected leave to same floor
	//if selected floor cant leave while animating
	if(strcmp(TEXTANSWER_selected_answer_string,"Entrance 1F")==0&&floor!=0){floor=0;door_locked=1;animate=1;}
	if(strcmp(TEXTANSWER_selected_answer_string,"Rooms 2F")==0&&floor!=1){floor=1;door_locked=1;animate=1;}
	//if(strcmp(TEXTANSWER_selected_answer_string,"Presidential Suite 10F")==0&&floor!=2){floor=1;door_locked=1;animate=1;}
	//if animation done, ding sound
	if(animate==1)
	{
		//TODO: screen shake
		//ding
		HARDWARE_play_sound("elevatording",127,44100,0);
		door_locked=0;
		animate=0;
	}

	if(walking_into_door(RANGE_CITYHotelElevator2ToSelectedFloor)
	&&door_locked==0)
	{
		//change to selected floor
		if(floor==0){MAP_change_map(MAP_bobsgame_CITYHotelEntrance,24,20);return;}
		if(floor==1){MAP_change_map(MAP_bobsgame_CITYHotelHallway,24,38);return;}
		if(floor==2){MAP_change_map(MAP_bobsgame_CITYHotelHallway,24,38);return;}
	}
}
void bobsgame_CITYHotelElevator2_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHotelElevator2_Map_VBL_Function()
{

}
void bobsgame_CITYHotelElevator2_Map_HBL_Function()
{

}
//========================================================
//CITYHotelHallway
//========================================================
void bobsgame_CITYHotelHallway_Map_Load_Function()
{
//RANGE_CITYHotelHallwayToElevator 6*8,37*8,12*8,38*8
//RANGE_CITYHotelHallwayToElevator2 22*8,37*8,28*8,38*8
//RANGE_CITYHotelHallwayToHotelRoom 23*8,9*8,27*8,10*8
//RANGE_CITYHotelHallwayToLinenCloset 83*8,37*8,87*8,38*8
}
void bobsgame_CITYHotelHallway_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//maid going from room to room.

//theres a sign that says "do not disturb"
//it says "please clean room" on the back
//flip it?
//maid comes out every once in awhile, leaves key in door?

//86,39 to 75.39 75.19 26 19 look up, stop, to 57, up stop to 88 up stop to 75 to 75 47 down stop to 42 down stop to 11 down stop to 86, to 86 39 disappear
//TODO: if you flip the do not disturb, she comes out with a cart and leaves it in front of the door? get key to linen closet, go in there, get ???
//hmm or maybe just put it on your own door, she knocks and comes in?? i dont know

//TODO: need maid sprite, maid cart?

	static NPC* maid_npc = NULL;
	if(maid_npc==NULL)
	{
		NPC_create_random_ADULT_xy_feet(&maid_npc,88*8,38*8);
		//NPC_create_npc_xy_feet(&maid_npc,SPRITE,16,40,7*8,27*8);
		maid_npc->non_walkable=1;
		maid_npc->layer=2;
		NPC_animate_stand_dir(&maid_npc,DOWN);
		maid_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		maid_npc->walk_dir=maid_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&maid_npc, maid_npc->anim_direction);
	}
	if(maid_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&maid_npc,35))NPC_stare_at_npc(&maid_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&maid_npc, maid_npc->walk_dir);
		//if(NPC_in_range_of_npc_amt(&PLAYER_npc,maid_npc,35))NPC_stare_at_npc_not_opposite_walking_direction(&maid_npc,PLAYER_npc);
		//else
		//{

		//}

		if(ACTION_npc(&maid_npc,"Talk To Maid"))
		{
			TEXT_set_sprite_window(0,maid_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("" //? No hablar Ingles. No comprendo, no comprendo. lo siento. listen you stupid kid, i dont speak english, alright? here, go steal some shampoo.
			);
		}
	}

	if(walking_into_door(RANGE_CITYHotelHallwayToElevator))
	{
		MAP_change_map(MAP_bobsgame_CITYHotelElevator,7,18);return;
	}
	if(walking_into_door(RANGE_CITYHotelHallwayToElevator2))
	{
		MAP_change_map(MAP_bobsgame_CITYHotelElevator2,7,18);return;
	}
	if(walking_into_door(RANGE_CITYHotelHallwayToHotelRoom))
	{
		MAP_change_map(MAP_bobsgame_CITYHotelRoom,24,39);return;
	}
	if(walking_into_door(RANGE_CITYHotelHallwayToLinenCloset))
	{
		MAP_change_map(MAP_bobsgame_CITYHotelLinenCloset,5,19);return;
	}
}
void bobsgame_CITYHotelHallway_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHotelHallway_Map_VBL_Function()
{

}
void bobsgame_CITYHotelHallway_Map_HBL_Function()
{

}
//========================================================
//CITYHotelRoom
//========================================================
void bobsgame_CITYHotelRoom_Map_Load_Function()
{
//RANGE_CITYHotelRoomToHallway 22*8,40*8,26*8,41*8
//RANGE_CITYHotelRoomToBathroom 15*8,35*8,16*8,39*8
}
void bobsgame_CITYHotelRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	if(walking_into_door(RANGE_CITYHotelRoomToHallway))
	{
		MAP_change_map(MAP_bobsgame_CITYHotelHallway,25,10);return;
	}
	if(walking_into_door(RANGE_CITYHotelRoomToBathroom))
	{
		MAP_change_map(MAP_bobsgame_CITYHotelRoomBathroom,13,13);return;
	}
}
void bobsgame_CITYHotelRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHotelRoom_Map_VBL_Function()
{

}
void bobsgame_CITYHotelRoom_Map_HBL_Function()
{

}
//========================================================
//CITYHotelRoomBathroom
//========================================================
void bobsgame_CITYHotelRoomBathroom_Map_Load_Function()
{
//RANGE_CITYHotelRoomBathroomToHotelRoom 15*8,11*8,16*8,16*8
}
void bobsgame_CITYHotelRoomBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	//TODO: use toilet etc

	//steal little shampoos

	if(walking_into_door(RANGE_CITYHotelRoomBathroomToHotelRoom))
	{
		MAP_change_map(MAP_bobsgame_CITYHotelRoom,16,37);return;
	}
}
void bobsgame_CITYHotelRoomBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHotelRoomBathroom_Map_VBL_Function()
{

}
void bobsgame_CITYHotelRoomBathroom_Map_HBL_Function()
{

}
//========================================================
//CITYHotelLinenCloset
//========================================================
void bobsgame_CITYHotelLinenCloset_Map_Load_Function()
{
//RANGE_CITYHotelLinenClosetToHallway 3*8,20*8,7*8,21*8
}
void bobsgame_CITYHotelLinenCloset_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//something important in here. have to sneak in somehow

	if(walking_into_door(RANGE_CITYHotelLinenClosetToHallway))
	{
		MAP_change_map(MAP_bobsgame_CITYHotelHallway,85,38);return;
	}
}
void bobsgame_CITYHotelLinenCloset_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHotelLinenCloset_Map_VBL_Function()
{

}
void bobsgame_CITYHotelLinenCloset_Map_HBL_Function()
{

}



