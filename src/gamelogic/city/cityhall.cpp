//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================


#include "../../main.h"



#define RANGE_CITYCityHallEntranceToOUTSIDECityLeft 23*8,46*8,29*8,47*8
#define RANGE_CITYCityHallEntranceToOUTSIDECityRight 31*8,46*8,37*8,47*8
#define RANGE_CITYCityHallEntranceToElevator 82*8,21*8,88*8,22*8
#define RANGE_CITYCityHallElevatorToSelectedFloor 5*8,19*8,11*8,20*8
#define RANGE_CITYCityHallOfficesToElevator 82*8,21*8,88*8,22*8
#define RANGE_CITYCityHallMeetingRoomToElevator 82*8,21*8,88*8,22*8
#define RANGE_CITYCityHallMayorOfficeToElevator 82*8,21*8,88*8,22*8

//========================================================
//CITYCityHallEntrance
//========================================================
void bobsgame_CITYCityHallEntrance_Map_Load_Function()
{
//RANGE_CITYCityHallEntranceToOUTSIDECityLeft 23*8,46*8,29*8,47*8
//RANGE_CITYCityHallEntranceToOUTSIDECityRight 31*8,46*8,37*8,47*8
//RANGE_CITYCityHallEntranceToElevator 82*8,21*8,88*8,22*8
}
void bobsgame_CITYCityHallEntrance_Map_Run_Function(int MAP_just_loaded)
{
static int metalalarm=0;
	if(MAP_just_loaded==1)
	{
		metalalarm=0;
	}

//guard
//77,38 down

	static NPC* cityhallguard_npc = NULL;
	if(cityhallguard_npc==NULL)
	{
		//NPC_create_random_ADULT_xy_feet(&cityhallguard_npc,2*8,2*8);
		NPC_create_npc_xy_feet(&cityhallguard_npc,GFX_ADULT_securityguard,16,40,77*8,38*8);
		cityhallguard_npc->non_walkable=1;
		cityhallguard_npc->layer=2;
		NPC_animate_stand_dir(&cityhallguard_npc,DOWN);
		cityhallguard_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		cityhallguard_npc->walk_dir=cityhallguard_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&cityhallguard_npc, cityhallguard_npc->anim_direction);
	}
	if(cityhallguard_npc!=NULL)
	{
		//if(NPC_in_range_of_npc_amt(&PLAYER_npc,cityhallguard_npc,15))NPC_stare_at_npc(&cityhallguard_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&cityhallguard_npc, cityhallguard_npc->walking_direction);
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&cityhallguard_npc,15))NPC_stare_at_npc(&cityhallguard_npc,&PLAYER_npc);
		else
		{
			if(cityhallguard_npc->AI==0){if(cityhallguard_npc->vbls>200){if(r(4)==0){cityhallguard_npc->AI=1+r(3);}else{cityhallguard_npc->vbls=0;NPC_animate_stand_dir(&cityhallguard_npc, cityhallguard_npc->walk_dir);if(cityhallguard_npc->anim_frame_count!=0){cityhallguard_npc->anim_frame_count=3;NPC_animate(&cityhallguard_npc);}}}}
			if(cityhallguard_npc->AI==1){if(cityhallguard_npc->walk_dir==UP||cityhallguard_npc->walk_dir==DOWN)NPC_animate_stand_dir(&cityhallguard_npc,LEFT);else NPC_animate_stand_dir(&cityhallguard_npc,UP);cityhallguard_npc->vbls=r(120);cityhallguard_npc->AI=0;}
			if(cityhallguard_npc->AI==2){if(cityhallguard_npc->walk_dir==UP||cityhallguard_npc->walk_dir==DOWN)NPC_animate_stand_dir(&cityhallguard_npc,RIGHT);else NPC_animate_stand_dir(&cityhallguard_npc,DOWN);cityhallguard_npc->vbls=r(120);cityhallguard_npc->AI=0;}
			if(cityhallguard_npc->AI==3){NPC_animate(&cityhallguard_npc);cityhallguard_npc->vbls=r(120);cityhallguard_npc->AI=0;}
		}
		if(ACTION_range_xy_xy(16*8,28*8,17*8,31*8,"Talk To Guard"))
		{
			TEXT_set_sprite_window(0,cityhallguard_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("" //?
			);
		}
	}
//someone 7,27 left
	static NPC* sittingperson_npc = NULL;
	if(sittingperson_npc==NULL)
	{
		NPC_create_random_ADULT_xy_feet(&sittingperson_npc,10*8-4,27*8);
		//NPC_create_npc_xy_feet(&sittingperson_npc,securityguard,16,40,7*8,27*8);
		sittingperson_npc->non_walkable=1;
		sittingperson_npc->layer=2;
		NPC_animate_stand_dir(&sittingperson_npc,LEFT);
		sittingperson_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		sittingperson_npc->walk_dir=sittingperson_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&sittingperson_npc, sittingperson_npc->anim_direction);
	}
	if(sittingperson_npc!=NULL)
	{
		//if(NPC_in_range_of_npc_amt(&PLAYER_npc,sittingperson_npc,15))NPC_stare_at_npc(&sittingperson_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&sittingperson_npc, sittingperson_npc->walking_direction);
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&sittingperson_npc,15))NPC_stare_at_npc(&sittingperson_npc,&PLAYER_npc);
		else
		{
			if(sittingperson_npc->AI==0){if(sittingperson_npc->vbls>200){if(r(4)==0){sittingperson_npc->AI=1+r(3);}else{sittingperson_npc->vbls=0;NPC_animate_stand_dir(&sittingperson_npc, sittingperson_npc->walk_dir);if(sittingperson_npc->anim_frame_count!=0){sittingperson_npc->anim_frame_count=3;NPC_animate(&sittingperson_npc);}}}}
			if(sittingperson_npc->AI==1){if(sittingperson_npc->walk_dir==UP||sittingperson_npc->walk_dir==DOWN)NPC_animate_stand_dir(&sittingperson_npc,LEFT);else NPC_animate_stand_dir(&sittingperson_npc,UP);sittingperson_npc->vbls=r(120);sittingperson_npc->AI=0;}
			if(sittingperson_npc->AI==2){if(sittingperson_npc->walk_dir==UP||sittingperson_npc->walk_dir==DOWN)NPC_animate_stand_dir(&sittingperson_npc,RIGHT);else NPC_animate_stand_dir(&sittingperson_npc,DOWN);sittingperson_npc->vbls=r(120);sittingperson_npc->AI=0;}
			if(sittingperson_npc->AI==3){NPC_animate(&sittingperson_npc);sittingperson_npc->vbls=r(120);sittingperson_npc->AI=0;}
		}
		if(ACTION_npc(&sittingperson_npc,"Talk To Sitting Person"))
		{
			TEXT_set_sprite_window(0,sittingperson_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("" //?
			);
		}
	}
//have people come in, go through metal detector. stop for you.
	int c=0;
	static NPC* line_npcs[6] = {NULL,NULL,NULL,NULL,NULL,NULL};
	static int last_clock=0;
	for(c=0;c<6;c++)
	{
		if(line_npcs[c]==NULL&&CLOCK_minute%2==0&&CLOCK_minute!=last_clock)
		{
			last_clock=CLOCK_minute;
			if(r(2)==0)NPC_create_random_ADULT_xy_feet(&line_npcs[c],26*8,46*8);
			else NPC_create_random_ADULT_xy_feet(&line_npcs[c],34*8,46*8);
			line_npcs[c]->non_walkable=1;
			line_npcs[c]->AI=0;
			line_npcs[c]->walking_speed=SPEED_NORMAL+r(SPEED_SLOW-SPEED_FASTEST);
			line_npcs[c]->ignore_fx_layer=1;
			NPC_animate_stand_dir(&line_npcs[c], UP);
		}
		if(line_npcs[c]!=NULL)
		{
			if(line_npcs[c]->AI== 0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, -1,42*8)==(1))line_npcs[c]->AI++;
			if(line_npcs[c]->AI== 1)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 85*8,-1)==1)line_npcs[c]->AI++;
//if elevator opens
			if(line_npcs[c]->AI== 2)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 85*8,23*8)==1){NPC_delete_npc(&line_npcs[c]);}
		}
	}

//cant go through metal detector, always goes off because of gps collar
//switch tile with tile at layer 3, 1-2 off, 3-4 on. tile at layer 1 85-86,30
	//TODO: if(have gps)
	if(PLAYER_npc->MAP_x+PLAYER_npc->size_x/2>=83*8&&PLAYER_npc->MAP_x+PLAYER_npc->size_x/2<=88*8)
	{
		if(PLAYER_npc->MAP_y+PLAYER_npc->size_y-PLAYER_npc->hitsize_y<=36*8)
		{
			GLOBAL_main_sprite_input_off=1;
			metalalarm=1;
			//TODO: play alarm sample
			//TODO: guard comes over, have conversation.
		}
		if(GLOBAL_main_sprite_input_off==1)
		{
			if(PLAYER_npc->ms>SPEED_NORMAL){PLAYER_npc->ms=0;PLAYER_npc->MAP_y++;if(NPC_should_animate(&PLAYER_npc))NPC_animate_dir(&PLAYER_npc,DOWN);}//facing_direction=DOWN;
			if(PLAYER_npc->MAP_y+PLAYER_npc->size_y-PLAYER_npc->hitsize_y>=40*8)GLOBAL_main_sprite_input_off=0;
		}
	}

	static int last_vblvar=0;
	if(metalalarm==1&&last_vblvar!=vbl_10_var)
	{
		last_vblvar=vbl_10_var;
		static int onoff=0;

		if(onoff==0)
		{
			onoff=1;
			//off
			//HARDWARE_set_map_tile(1,1,84,30,HARDWARE_map_1[1]);
			//HARDWARE_set_map_tile(1,1,85,30,HARDWARE_map_1[2]);
			///TODO: MUST FIX THIS!!!
			///HARDWARE_set_tile_gfx_to_tile(1,1,HARDWARE_map_3[1],HARDWARE_map_3[3]);
			///HARDWARE_set_tile_gfx_to_tile(1,1,HARDWARE_map_3[2],HARDWARE_map_3[4]);
		}
		else
		{
			onoff=0;
			//on
			//HARDWARE_set_map_tile(1,1,84,30,HARDWARE_map_1[3]);
			//HARDWARE_set_map_tile(1,1,85,30,HARDWARE_map_1[4]);
			///HARDWARE_set_tile_gfx_to_tile(1,1,HARDWARE_map_3[1],HARDWARE_map_3[5]);
			///HARDWARE_set_tile_gfx_to_tile(1,1,HARDWARE_map_3[2],HARDWARE_map_3[6]);
		}
	}

	//animate water
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

//59-61,12-13 bust one
	if(ACTION_range_xy_xy(59*8,12*8,61*8,13*8,"Look At Bust"))
	{
		TEXT_set_sprite_window(0,PLAYER_npc,NULL);
		TEXT_set_sprite_window(1,PLAYER_npc,NULL);
		TEXT_window("" //?
		);
	}
//72-73,18-21 bust 2
	if(ACTION_range_xy_xy(72*8,18*8,73*8,21*8,"Look At Bust"))
	{
		TEXT_set_sprite_window(0,PLAYER_npc,NULL);
		TEXT_set_sprite_window(1,PLAYER_npc,NULL);
		TEXT_window("" //?
		);
	}
// 9-12 portrait 1
	if(ACTION_range_xy_xy( 9*8,10*8,12*8,11*8,"Look At 1910 Portrait"))
	{
		TEXT_set_sprite_window(0,PLAYER_npc,NULL);
		TEXT_set_sprite_window(1,PLAYER_npc,NULL);
		TEXT_window("" //?
		);
	}
//29-32 portrait 2
	if(ACTION_range_xy_xy(29*8,10*8,32*8,11*8,"Look At 1940 Portrait"))
	{
		TEXT_set_sprite_window(0,PLAYER_npc,NULL);
		TEXT_set_sprite_window(1,PLAYER_npc,NULL);
		TEXT_window("" //?
		);
	}
//50-53 portrait 3
	if(ACTION_range_xy_xy(50*8,10*8,53*8,11*8,"Look At 1970 Portrait"))
	{
		TEXT_set_sprite_window(0,PLAYER_npc,NULL);
		TEXT_set_sprite_window(1,PLAYER_npc,NULL);
		TEXT_window("" //?
		);
	}
//66-69 portrait 4
	if(ACTION_range_xy_xy(66*8,10*8,69*8,11*8,"Look At 2000 Portrait"))
	{
		TEXT_set_sprite_window(0,PLAYER_npc,NULL);
		TEXT_set_sprite_window(1,PLAYER_npc,NULL);
		TEXT_window("" //?
		);
	}
//TODO: fountain sound

//fountain sprite 1
	static NPC* fountainwater1_npc = NULL;
	if(fountainwater1_npc==NULL)
	{
		NPC_create_npc_xy_feet(&fountainwater1_npc,GFX_MISC_fountainwater,64,64,29*8-4,29*8);
		fountainwater1_npc->layer=1;
		fountainwater1_npc->alpha=127;
	}
	if(fountainwater1_npc!=NULL)
	{
		if(fountainwater1_npc->vbls>3){NPC_animate_cycle_through_frames_now(&fountainwater1_npc,6);fountainwater1_npc->vbls=0;}
	}
	static NPC* fountainwater2_npc = NULL;
	if(fountainwater2_npc==NULL)
	{
		NPC_create_npc_xy_feet(&fountainwater2_npc,GFX_MISC_fountainwater,64,64,33*8-4,25*8);
		fountainwater2_npc->layer=1;
		fountainwater2_npc->anim_frame_count=1;
		fountainwater2_npc->alpha=127;
	}
	if(fountainwater2_npc!=NULL)
	{
		if(fountainwater2_npc->vbls>3){NPC_animate_cycle_through_frames_now(&fountainwater2_npc,6);fountainwater2_npc->vbls=0;}
	}
	static NPC* fountainwater3_npc = NULL;
	if(fountainwater3_npc==NULL)
	{
		NPC_create_npc_xy_feet(&fountainwater3_npc,GFX_MISC_fountainwater,64,64,26*8-4,23*8);
		fountainwater3_npc->layer=1;
		fountainwater3_npc->anim_frame_count=2;
		fountainwater3_npc->alpha=127;
	}
	if(fountainwater3_npc!=NULL)
	{
		if(fountainwater3_npc->vbls>3){NPC_animate_cycle_through_frames_now(&fountainwater3_npc,6);fountainwater3_npc->vbls=0;}
	}
	static NPC* fountainwater4_npc = NULL;
	if(fountainwater4_npc==NULL)
	{
		NPC_create_npc_xy_feet(&fountainwater4_npc,GFX_MISC_fountainwater,64,64,24*8-4,22*8);
		fountainwater4_npc->layer=1;
		fountainwater4_npc->anim_frame_count=3;
		fountainwater4_npc->alpha=127;
	}
	if(fountainwater4_npc!=NULL)
	{
		if(fountainwater4_npc->vbls>3){NPC_animate_cycle_through_frames_now(&fountainwater4_npc,6);fountainwater4_npc->vbls=0;}
	}
	static NPC* fountainwater5_npc = NULL;
	if(fountainwater5_npc==NULL)
	{
		NPC_create_npc_xy_feet(&fountainwater5_npc,GFX_MISC_fountainwater,64,64,21*8-4,29*8);
		fountainwater5_npc->layer=1;
		fountainwater5_npc->anim_frame_count=4;
		fountainwater5_npc->alpha=127;
	}
	if(fountainwater5_npc!=NULL)
	{
		if(fountainwater5_npc->vbls>3){NPC_animate_cycle_through_frames_now(&fountainwater5_npc,6);fountainwater5_npc->vbls=0;}
	}
	static NPC* fountainwater6_npc = NULL;
	if(fountainwater6_npc==NULL)
	{
		NPC_create_npc_xy_feet(&fountainwater6_npc,GFX_MISC_fountainwater,64,64,17*8-4,25*8);
		fountainwater6_npc->layer=1;
		fountainwater6_npc->anim_frame_count=5;
		fountainwater6_npc->alpha=127;
	}
	if(fountainwater6_npc!=NULL)
	{
		if(fountainwater6_npc->vbls>3){NPC_animate_cycle_through_frames_now(&fountainwater6_npc,6);fountainwater6_npc->vbls=0;}
	}
	if(walking_into_door(RANGE_CITYCityHallEntranceToOUTSIDECityLeft))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,1074,39);return;
	}
	if(walking_into_door(RANGE_CITYCityHallEntranceToOUTSIDECityRight))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,1082,39);return;
	}
	if(walking_into_door(RANGE_CITYCityHallEntranceToElevator))
	{
		MAP_change_map(MAP_bobsgame_CITYCityHallElevator,7,18);return;
	}
}
void bobsgame_CITYCityHallEntrance_Map_Stop_Function()
{

	NPC_delete_all_npcs();
}
void bobsgame_CITYCityHallEntrance_Map_VBL_Function()
{

}
void bobsgame_CITYCityHallEntrance_Map_HBL_Function()
{

}
//========================================================
//CITYCityHallElevator
//========================================================
void bobsgame_CITYCityHallElevator_Map_Load_Function()
{
//RANGE_CITYCityHallElevatorToSelectedFloor 5*8,19*8,11*8,20*8
}
void bobsgame_CITYCityHallElevator_Map_Run_Function(int MAP_just_loaded)
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
		TEXT_window("Which floor?<Q:Entrance 1F:City Offices 2F:Meeting Hall 3F:Mayor 4F>"
		);
	}
	//if select same floor no ding
	//if no floor selected leave to same floor
	//if selected floor cant leave while animating
	if(strcmp(TEXTANSWER_selected_answer_string,"Entrance 1F")==0&&floor!=0){floor=0;door_locked=1;animate=1;}
	if(strcmp(TEXTANSWER_selected_answer_string,"City Offices 2F")==0&&floor!=1){floor=1;door_locked=1;animate=1;}
	if(strcmp(TEXTANSWER_selected_answer_string,"Meeting Hall 3F")==0&&floor!=2){floor=2;door_locked=1;animate=1;}
	if(strcmp(TEXTANSWER_selected_answer_string,"Mayor 4F")==0&&floor!=3){floor=3;door_locked=1;animate=1;}
	//if animation done, ding sound
	if(animate==1)
	{
		//TODO: screen shake
		//ding
		HARDWARE_play_sound("elevatording",127,44100,0);
		door_locked=0;
		animate=0;
	}

	if(walking_into_door(RANGE_CITYCityHallElevatorToSelectedFloor)
	&&door_locked==0)
	{
		//change to selected floor
		if(floor==0){MAP_change_map(MAP_bobsgame_CITYCityHallEntrance,84,22);return;}
		if(floor==1){MAP_change_map(MAP_bobsgame_CITYCityHallOffices,84,22);return;}
		if(floor==2){MAP_change_map(MAP_bobsgame_CITYCityHallMeetingRoom,84,22);return;}
		if(floor==3){MAP_change_map(MAP_bobsgame_CITYCityHallMayorOffice,84,22);return;}
	}
}
void bobsgame_CITYCityHallElevator_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYCityHallElevator_Map_VBL_Function()
{

}
void bobsgame_CITYCityHallElevator_Map_HBL_Function()
{

}
//========================================================
//CITYCityHallOffices
//========================================================
void bobsgame_CITYCityHallOffices_Map_Load_Function()
{
//RANGE_CITYCityHallOfficesToElevator 82*8,21*8,88*8,22*8
}
void bobsgame_CITYCityHallOffices_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//12,14 down
//32,14 down
//52,14 down
//42,43 up
//62,43 up
//82,43 up
//13,42 right

//17,41 down
//21,
//25
//17.44 UP
//21
//25

//29.42

	static NPC* officeworkers_npcs[16] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<16;c++)
	{
		if(officeworkers_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			GFX* gfx=NULL;
			if(c== 0){x=12*8;y=14*8;dir=DOWN;	bgp=2;  gfx=GFX_ADULT_businessguy;}
			if(c== 1){x=32*8;y=14*8;dir=DOWN;	bgp=2;  gfx=GFX_ADULT_officeworkermale;}
			if(c== 2){x=52*8;y=14*8;dir=DOWN;	bgp=2;  gfx=GFX_ADULT_officeworkerfemale;}
			if(c== 3){x=42*8;y=43*8;dir=UP;		bgp=3;  gfx=GFX_ADULT_businesswoman;}
			if(c== 4){x=62*8;y=43*8;dir=UP;		bgp=3;	gfx=GFX_ADULT_officeworkerfemale;}
			if(c== 5){x=82*8;y=43*8;dir=UP;		bgp=3;	gfx=GFX_ADULT_officeworkermale;}
			if(c== 6){x=13*8+2;y=42*8-2;dir=RIGHT;bgp=2;	gfx=GFX_ADULT_skinnymeekcoder;}
			if(c== 7){x=17*8;y=39*8;dir=DOWN;	bgp=2;	gfx=GFX_ADULT_officeworkermale;}
			if(c== 8){x=21*8;y=39*8;dir=DOWN;	bgp=2;	gfx=GFX_ADULT_fatmeekcoder;}
			if(c== 9){x=25*8;y=39*8;dir=DOWN;	bgp=2;	gfx=GFX_ADULT_officeworkerfemale;}
			if(c==10){x=17*8;y=44*8;dir=UP;		bgp=3;	gfx=GFX_ADULT_officeworkermale;}
			if(c==11){x=21*8;y=44*8;dir=UP;		bgp=3;	gfx=GFX_ADULT_businessguy;}
			if(c==12){x=25*8;y=44*8;dir=UP;		bgp=3;	gfx=GFX_ADULT_officeworkermale;}
			if(c==13){x=29*8-2;y=42*8-2;dir=LEFT;bgp=2;	gfx=GFX_ADULT_businesswoman;}
			if(c==14){x=67*8;y=15*8;dir=RIGHT;	bgp=2;	gfx=GFX_ADULT_businesswoman;}//watercooler
			if(c==15){x=71*8;y=15*8;dir=LEFT;	bgp=2;	gfx=GFX_ADULT_businessguy;}

			if(gfx==NULL)NPC_create_random_ADULT_xy_feet(&officeworkers_npcs[c],x,y);
			else NPC_create_npc_xy_feet(&officeworkers_npcs[c],gfx,16,40,x,y);
			NPC_animate_stand_dir(&officeworkers_npcs[c], dir);
			officeworkers_npcs[c]->non_walkable=1;
			officeworkers_npcs[c]->walk_dir=dir;
			officeworkers_npcs[c]->layer=bgp;
			//NPC_animate_increment_direction_frame_now(&officeworkers_npcs[c], dir);
		}
		if(officeworkers_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&officeworkers_npcs[c],15))NPC_stare_at_npc(&officeworkers_npcs[c],&PLAYER_npc);
			else if(officeworkers_npcs[c]->AI==0){if(officeworkers_npcs[c]->vbls>200){if(r(4)==0){officeworkers_npcs[c]->AI=1+r(3);}else{officeworkers_npcs[c]->vbls=0;NPC_animate_stand_dir(&officeworkers_npcs[c], officeworkers_npcs[c]->walk_dir);if(officeworkers_npcs[c]->anim_frame_count!=0){officeworkers_npcs[c]->anim_frame_count=3;NPC_animate(&officeworkers_npcs[c]);}}}}
			else if(officeworkers_npcs[c]->AI==1){if(officeworkers_npcs[c]->walk_dir==UP||officeworkers_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&officeworkers_npcs[c],LEFT);else NPC_animate_stand_dir(&officeworkers_npcs[c],UP);officeworkers_npcs[c]->vbls=r(120);officeworkers_npcs[c]->AI=0;}
			else if(officeworkers_npcs[c]->AI==2){if(officeworkers_npcs[c]->walk_dir==UP||officeworkers_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&officeworkers_npcs[c],RIGHT);else NPC_animate_stand_dir(&officeworkers_npcs[c],DOWN);officeworkers_npcs[c]->vbls=r(120);officeworkers_npcs[c]->AI=0;}
			else if(officeworkers_npcs[c]->AI==3){NPC_animate(&officeworkers_npcs[c]);officeworkers_npcs[c]->vbls=r(120);officeworkers_npcs[c]->AI=0;}
			//if(NPC_in_range_of_npc_amt(&PLAYER_npc,officeworkers_npcs[c],15))NPC_stare_at_npc(&officeworkers_npcs[c],PLAYER_npc);
			//else NPC_animate_set_direction_now(&officeworkers_npcs[c], officeworkers_npcs[c]->walking_direction);
		}
	}
//TODO: meeting event. maybe have open chair.
	if(walking_into_door(RANGE_CITYCityHallOfficesToElevator))
	{
		MAP_change_map(MAP_bobsgame_CITYCityHallElevator,7,18);return;
	}
}
void bobsgame_CITYCityHallOffices_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYCityHallOffices_Map_VBL_Function()
{

}
void bobsgame_CITYCityHallOffices_Map_HBL_Function()
{

}
//========================================================
//CITYCityHallMeetingRoom
//========================================================
void bobsgame_CITYCityHallMeetingRoom_Map_Load_Function()
{
//RANGE_CITYCityHallMeetingRoomToElevator 82*8,21*8,88*8,22*8
}
void bobsgame_CITYCityHallMeetingRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//84,22 come from elevator to 84,26 to 20,26
//20,33 over 1, face right mayor
//25,29 down
//31
//37
//43
//49
//55
//25,36 up
//31
//37
//43
//49
//55
	static NPC* citymeeting_npcs[13] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<13;c++)
	{
		if(citymeeting_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			GFX* gfx=NULL;
			if(c== 0){x=20*8;y=32*8;dir=RIGHT;	bgp=2;  gfx=GFX_ADULT_mayor;}
			if(c== 1){x=25*8;y=28*8-4;dir=DOWN;	bgp=2;  gfx=GFX_ADULT_bigwig;}
			if(c== 2){x=31*8;y=28*8-4;dir=DOWN;	bgp=2;  gfx=GFX_ADULT_richnerdguy;}
			if(c== 3){x=37*8;y=28*8-4;dir=DOWN;	bgp=2;  gfx=GFX_ADULT_businesswoman;}
			if(c== 4){x=43*8;y=28*8-4;dir=DOWN;	bgp=2;	gfx=GFX_ADULT_businessguy;}
			if(c== 5){x=49*8;y=28*8-4;dir=DOWN;	bgp=2;	gfx=GFX_ADULT_wealthygirl;}
			if(c== 6){x=55*8;y=28*8-4;dir=DOWN;	bgp=2;	gfx=GFX_ADULT_wealthylady;}
			if(c== 7){x=25*8;y=36*8;dir=UP;		bgp=2;	gfx=GFX_ADULT_wealthyguy;}
			if(c== 8){x=31*8;y=36*8;dir=UP;		bgp=2;	gfx=GFX_ADULT_alien;}
			if(c== 9){x=37*8;y=36*8;dir=UP;		bgp=2;	gfx=GFX_ADULT_crimeboss;}
			if(c==10){x=43*8;y=36*8;dir=UP;		bgp=2;	gfx=GFX_ADULT_mafiaguy;}
			if(c==11){x=49*8;y=36*8;dir=UP;		bgp=2;	gfx=GFX_ADULT_president;}
			if(c==12){x=55*8;y=36*8;dir=UP;		bgp=2;	gfx=GFX_ADULT_cia;}

			if(gfx==NULL)NPC_create_random_ADULT_xy_feet(&citymeeting_npcs[c],x,y);
			else NPC_create_npc_xy_feet(&citymeeting_npcs[c],gfx,16,40,x,y);
			NPC_animate_stand_dir(&citymeeting_npcs[c], dir);
			citymeeting_npcs[c]->non_walkable=1;
			citymeeting_npcs[c]->walk_dir=dir;
			citymeeting_npcs[c]->layer=bgp;
			//NPC_animate_increment_direction_frame_now(&citymeeting_npcs[c], dir);
		}
		if(citymeeting_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&citymeeting_npcs[c],15))NPC_stare_at_npc(&citymeeting_npcs[c],&PLAYER_npc);
			else if(citymeeting_npcs[c]->AI==0){if(citymeeting_npcs[c]->vbls>200){if(r(4)==0){citymeeting_npcs[c]->AI=1+r(3);}else{citymeeting_npcs[c]->vbls=0;NPC_animate_stand_dir(&citymeeting_npcs[c], citymeeting_npcs[c]->walk_dir);if(citymeeting_npcs[c]->anim_frame_count!=0){citymeeting_npcs[c]->anim_frame_count=3;NPC_animate(&citymeeting_npcs[c]);}}}}
			else if(citymeeting_npcs[c]->AI==1){if(citymeeting_npcs[c]->walk_dir==UP||citymeeting_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&citymeeting_npcs[c],LEFT);else NPC_animate_stand_dir(&citymeeting_npcs[c],UP);citymeeting_npcs[c]->vbls=r(120);citymeeting_npcs[c]->AI=0;}
			else if(citymeeting_npcs[c]->AI==2){if(citymeeting_npcs[c]->walk_dir==UP||citymeeting_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&citymeeting_npcs[c],RIGHT);else NPC_animate_stand_dir(&citymeeting_npcs[c],DOWN);citymeeting_npcs[c]->vbls=r(120);citymeeting_npcs[c]->AI=0;}
			else if(citymeeting_npcs[c]->AI==3){NPC_animate(&citymeeting_npcs[c]);citymeeting_npcs[c]->vbls=r(120);citymeeting_npcs[c]->AI=0;}
			//if(NPC_in_range_of_npc_amt(&PLAYER_npc,citymeeting_npcs[c],15))NPC_stare_at_npc(&citymeeting_npcs[c],PLAYER_npc);
			//else NPC_animate_set_direction_now(&citymeeting_npcs[c], citymeeting_npcs[c]->walking_direction);
		}
	}

//foreign servers refill water? person looks at server if server is close.
//someone interrupt, stand at 60,32 face left. you?

//TODO: fountain sound

	//animate water
	static int lastvbltimer = 0;
	if(lastvbltimer!=vbl_10_var)
	{
		lastvbltimer=vbl_10_var;
		static int tile=0;
		tile++;
		if(tile>7)tile=0;
		///TODO: MUST FIX!
		///HARDWARE_set_tile_gfx_to_tile(1,0,HARDWARE_map_0[1],HARDWARE_map_0[2+tile]);
		///HARDWARE_set_tile_gfx_to_tile(1,0,HARDWARE_map_0[10],HARDWARE_map_0[11+tile]);

		///HARDWARE_set_tile_gfx_to_tile(1,1,HARDWARE_map_2[1],HARDWARE_map_2[2+tile]);
		///HARDWARE_set_tile_gfx_to_tile(1,1,HARDWARE_map_2[10],HARDWARE_map_2[11+tile]);

		///HARDWARE_set_tile_gfx_to_tile(1,2,HARDWARE_map_2[1],HARDWARE_map_2[2+tile]);
		///HARDWARE_set_tile_gfx_to_tile(1,2,HARDWARE_map_2[10],HARDWARE_map_2[11+tile]);
	}

//fountain sprite 1
	static NPC* fountainwater1_npc = NULL;
	if(fountainwater1_npc==NULL)
	{
		NPC_create_npc_xy_feet(&fountainwater1_npc,GFX_MISC_fountainwater,64,64,31*8-4,18*8);
		fountainwater1_npc->layer=1;
		fountainwater1_npc->alpha=127;
	}
	if(fountainwater1_npc!=NULL)
	{
		if(fountainwater1_npc->vbls>3){NPC_animate_cycle_through_frames_now(&fountainwater1_npc,6);fountainwater1_npc->vbls=0;}
	}
	static NPC* fountainwater2_npc = NULL;
	if(fountainwater2_npc==NULL)
	{
		NPC_create_npc_xy_feet(&fountainwater2_npc,GFX_MISC_fountainwater,64,64,51*8-4,18*8);
		fountainwater2_npc->layer=1;
		fountainwater2_npc->anim_frame_count=1;
		fountainwater2_npc->alpha=127;
	}
	if(fountainwater2_npc!=NULL)
	{
		if(fountainwater2_npc->vbls>3){NPC_animate_cycle_through_frames_now(&fountainwater2_npc,6);fountainwater2_npc->vbls=0;}
	}

	if(walking_into_door(RANGE_CITYCityHallMeetingRoomToElevator))
	{
		MAP_change_map(MAP_bobsgame_CITYCityHallElevator,7,18);return;
	}
}
void bobsgame_CITYCityHallMeetingRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYCityHallMeetingRoom_Map_VBL_Function()
{

}
void bobsgame_CITYCityHallMeetingRoom_Map_HBL_Function()
{

}
//========================================================
//CITYCityHallMayorOffice
//========================================================
void bobsgame_CITYCityHallMayorOffice_Map_Load_Function()
{
//RANGE_CITYCityHallMayorOfficeToElevator 82*8,21*8,88*8,22*8
}
void bobsgame_CITYCityHallMayorOffice_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//20,26 down
	static NPC* mayor_npc = NULL;
	static NPC* golfclub_npc=NULL;
	static NPC* golfball_npc=NULL;
	if(mayor_npc==NULL)
	{
		//NPC_create_random_ADULT_xy_feet(&mayor_npc,10*8-4,27*8);
		NPC_create_npc_xy_feet(&mayor_npc,GFX_ADULT_mayor,16,40,20*8+4,26*8);
		mayor_npc->non_walkable=1;
		mayor_npc->layer=2;
		NPC_animate_stand_dir(&mayor_npc,DOWN);
		mayor_npc->walking_speed=SPEED_SLOWEST;//SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		mayor_npc->walk_dir=mayor_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&mayor_npc, mayor_npc->anim_direction);
		if(golfclub_npc==NULL)NPC_create_npc_xy_feet(&golfclub_npc,GFX_MISC_golfclub,16,32,56*8,31*8-4);
	}
	if(mayor_npc!=NULL)
	{
		//walk to 20,28 24,28 24,21 32,22, 35,30
		//trophies at 28,40
		//29,13 up window
		//47,26 up tv
		//56,28 up water
		//55,32 up golf club
		//56,33 down
		//golf ball at 56,35
		//to 42,35 disappear
		//walk to 41,34
		//walk back to 56,33
		//golf ball back
		if(mayor_npc->AI== 0)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&mayor_npc,65))NPC_stare_at_npc(&mayor_npc,&PLAYER_npc);
			else NPC_animate_stand_dir(&mayor_npc, mayor_npc->walk_dir);
			if(ACTION_range_xy_xy(12*8,24*8,29*8,33*8,"Talk To Mayor"))
			{
				TEXT_set_sprite_window(0,mayor_npc,NULL);
				TEXT_set_sprite_window(1,PLAYER_npc,NULL);
				TEXT_window("We meet at last." // oh its the famous yuu
				);
				mayor_npc->AI++;
				//GLOBAL_main_sprite_input_off=1;
			}
		}
		if(mayor_npc->AI== 1){if(GLOBAL_text_engine_state==0)mayor_npc->AI++;}
		if(mayor_npc->AI== 2)if(NPC_walk_to_xy_nohit_pushmain(&mayor_npc,SPEED_SLOWER,20*8+4,28*8))mayor_npc->AI++;
		if(mayor_npc->AI== 3)if(NPC_walk_to_xy_nohit_pushmain(&mayor_npc,SPEED_SLOWER,24*8,28*8))mayor_npc->AI++;
		if(mayor_npc->AI== 4)if(NPC_walk_to_xy_nohit_pushmain(&mayor_npc,SPEED_SLOWER,24*8,21*8))mayor_npc->AI++;
		if(mayor_npc->AI== 5)if(NPC_walk_to_xy_nohit_pushmain(&mayor_npc,SPEED_SLOWER,32*8,21*8))mayor_npc->AI++;
		if(mayor_npc->AI== 6)if(NPC_walk_to_xy_nohit_pushmain(&mayor_npc,SPEED_SLOWER,35*8,30*8))mayor_npc->AI++;
		if(mayor_npc->AI== 7)
		{
			NPC_stare_at_npc(&mayor_npc,&PLAYER_npc);
			TEXT_set_sprite_window(0,mayor_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Let me tell Yuu something, boy." // let me tell yuu something
			);
			mayor_npc->AI++;
		}
		if(mayor_npc->AI== 8){if(GLOBAL_text_engine_state==0)mayor_npc->AI++;}
		if(mayor_npc->AI== 9)if(NPC_walk_to_xy_nohit_pushmain(&mayor_npc,SPEED_SLOWER,30*8,12*8)){mayor_npc->AI++;NPC_animate_stand_dir(&mayor_npc,DOWN);}
		if(mayor_npc->AI==10)
		{
			NPC_stare_at_npc(&mayor_npc,&PLAYER_npc);
			TEXT_set_sprite_window(0,mayor_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Come over here." // come over here
			);
			mayor_npc->AI++;
		}
		if(mayor_npc->AI==11){if(GLOBAL_text_engine_state==0)mayor_npc->AI++;}
		if(mayor_npc->AI==12)
		{
			NPC_stare_at_npc(&mayor_npc,&PLAYER_npc);
			//PLAYER_npc walk to window
			//cant leave
			if(NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,30*8,12*8,36*8,13*8,PLAYER_npc->anim_dir,0))mayor_npc->AI++;
		}
		if(mayor_npc->AI==13)
		{
			NPC_animate_stand_dir(&mayor_npc,UP);
			NPC_animate_stand_dir(&PLAYER_npc,UP);
			TEXT_set_sprite_window(0,mayor_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("See this city? It's mine. All mine. Bahaha." // see this city, boy?
			);
			mayor_npc->AI++;
		}
		if(mayor_npc->AI==14){if(GLOBAL_text_engine_state==0)mayor_npc->AI++;}
		if(mayor_npc->AI==15)if(NPC_walk_to_xy_nohit_pushmain(&mayor_npc,SPEED_SLOWER,32*8,21*8)){mayor_npc->AI++;}
		if(mayor_npc->AI==16)if(NPC_walk_to_xy_nohit_pushmain(&mayor_npc,SPEED_SLOWER,28*8,40*8)){mayor_npc->AI++;}
		if(mayor_npc->AI==17)if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&mayor_npc,64))mayor_npc->AI++;
		if(mayor_npc->AI==18)
		{
			NPC_stare_at_npc(&mayor_npc,&PLAYER_npc);
			TEXT_set_sprite_window(0,mayor_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("See these trophies? I'm the best." // see these trophies?
			);
			mayor_npc->AI++;
		}
		if(mayor_npc->AI==19){if(GLOBAL_text_engine_state==0)mayor_npc->AI++;}
		if(mayor_npc->AI==20)if(NPC_walk_to_xy_nohit_pushmain(&mayor_npc,SPEED_SLOWER,47*8,26*8)){mayor_npc->AI++;NPC_animate_stand_dir(&mayor_npc,UP);}
		if(mayor_npc->AI==21)if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&mayor_npc,64))mayor_npc->AI++;
		if(mayor_npc->AI==22)
		{
			//TODO: animate tv
			mayor_npc->AI++;
		}
		if(mayor_npc->AI==23)
		{
			NPC_stare_at_npc(&mayor_npc,&PLAYER_npc);
			TEXT_set_sprite_window(0,mayor_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Let's watch TV. War, death, famine. Wonderful. I am clearly very evil." // watch tv
			);
			mayor_npc->AI++;
		}
		if(mayor_npc->AI==24){if(GLOBAL_text_engine_state==0)mayor_npc->AI++;}
		if(mayor_npc->AI==25)if(NPC_walk_to_xy_nohit_pushmain(&mayor_npc,SPEED_SLOWER,47*8,26*8)){mayor_npc->AI++;NPC_animate_stand_dir(&mayor_npc,UP);}
		if(mayor_npc->AI==26)if(NPC_walk_to_xy_nohit_pushmain(&mayor_npc,SPEED_SLOWER,47*8,32*8)){mayor_npc->AI++;}
		if(mayor_npc->AI==27)if(NPC_walk_to_xy_nohit_pushmain(&mayor_npc,SPEED_SLOWER,55*8,32*8)){mayor_npc->AI++;NPC_animate_stand_dir(&mayor_npc,UP);mayor_npc->vbls=0;}
		if(mayor_npc->AI==28)
		{
			if(mayor_npc->vbls>60)
			{
				//remove golf club
				if(golfclub_npc!=NULL)NPC_delete_npc(&golfclub_npc);
				mayor_npc->AI++;
			}
		}
		if(mayor_npc->AI==29)if(NPC_walk_to_xy_nohit_pushmain(&mayor_npc,SPEED_SLOWER,56*8,33*8)){mayor_npc->AI++;NPC_animate_stand_dir(&mayor_npc,DOWN);mayor_npc->vbls=0;}
		if(mayor_npc->AI==30)if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&mayor_npc,64))mayor_npc->AI++;
		if(mayor_npc->AI==31)
		{
			//place golf ball
			if(golfball_npc==NULL)NPC_create_npc_xy_feet(&golfball_npc,GFX_MISC_golfball,8,8,56*8,34*8);
			mayor_npc->AI++;
		}
		if(mayor_npc->AI==32)
		{
			NPC_stare_at_npc(&mayor_npc,&PLAYER_npc);
			TEXT_set_sprite_window(0,mayor_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Take a game like golf. A massive field of land for one tiny white ball. Delicious grass that cows could be eating. But instead we let the cows starve to death."
			);
			mayor_npc->AI++;
		}
		if(mayor_npc->AI==33){if(GLOBAL_text_engine_state==0)mayor_npc->AI++;}
		if(mayor_npc->AI==34)
		{
			//TODO: animate swing a few times, end on left swing
			mayor_npc->AI++;
		}
		if(mayor_npc->AI==35)
		{
			//golf ball flies to 42,35 disappears
			if(golfball_npc!=NULL){if(NPC_move_to_xy_nohit_noanim(&golfball_npc,SPEED_CAR*2,42*8,34*8))NPC_delete_npc(&golfball_npc);}
			else
			mayor_npc->AI++;
		}
		if(mayor_npc->AI==36)if(NPC_walk_to_xy_nohit_pushmain(&mayor_npc,SPEED_SLOWER,43*8,34*8)){mayor_npc->AI++;mayor_npc->vbls=0;}
		if(mayor_npc->AI==37)if(mayor_npc->vbls>60)mayor_npc->AI++;
		if(mayor_npc->AI==38)if(NPC_walk_to_xy_nohit_pushmain(&mayor_npc,SPEED_SLOWER,56*8,33*8)){mayor_npc->AI++;NPC_animate_stand_dir(&mayor_npc,DOWN);mayor_npc->vbls=0;}
		if(mayor_npc->AI==39)
		{
			//place golf ball
			if(golfball_npc==NULL)NPC_create_npc_xy_feet(&golfball_npc,GFX_MISC_golfball,8,8,56*8,34*8);
			mayor_npc->AI++;
		}
		if(mayor_npc->AI==40)
		{
			NPC_stare_at_npc(&mayor_npc,&PLAYER_npc);
			TEXT_set_sprite_window(0,mayor_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("One little swing can clear hundreds of yards. This society is like a line of dominoes. You just have to know which one to push."
			);
			mayor_npc->AI++;
		}
		if(mayor_npc->AI==41)
		{
			//mayor animating swing
			if(GLOBAL_text_engine_state==0)mayor_npc->AI++;
		}
		if(mayor_npc->AI==42)
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("But isn't that wrong?"
			);
			mayor_npc->AI++;
		}
		if(mayor_npc->AI==43)
		{
			//mayor animating swing
			if(GLOBAL_text_engine_state==0)mayor_npc->AI++;
		}
		if(mayor_npc->AI==44)
		{
			//TODO: ball flies all crazy, breaks ??? window?
			//camera follows ball
			if(golfball_npc!=NULL)
			{
				if(golfball_npc->AI==0)if(NPC_move_to_xy_nohit_noanim(&golfball_npc,SPEED_CAR*2,27*8,34*8))golfball_npc->AI++;
				if(golfball_npc->AI==1)if(NPC_move_to_xy_nohit_noanim(&golfball_npc,SPEED_CAR*2,27*8,12*8))golfball_npc->AI++;
				if(golfball_npc->AI==2)
				{
					//TODO: glass shatter sound
					NPC_delete_npc(&golfball_npc);
				}
			}
			else
			mayor_npc->AI++;
		}
		if(mayor_npc->AI==45)
		{
			//mayor checks it out, trips on cord
			//cord goes tight, tv goes off, lights on tv go out
			//help! help!
			//hes just too fat.
			//get water from water cooler pour it out window?
			//some kind of mayhem, mayor falls out
			//cia man rushes in "whats going on here?"
			//sitting in limo with the president
			//yuu has made a big mistake, buddy. things are not what they seem
		}

	}
//TODO: need mayor putting animation
	if(walking_into_door(RANGE_CITYCityHallMayorOfficeToElevator))
	{
		MAP_change_map(MAP_bobsgame_CITYCityHallElevator,7,18);return;
	}
}
void bobsgame_CITYCityHallMayorOffice_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYCityHallMayorOffice_Map_VBL_Function()
{

}
void bobsgame_CITYCityHallMayorOffice_Map_HBL_Function()
{

}

