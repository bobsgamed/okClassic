//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================




#include "../../main.h"





#define RANGE_CITYStadiumLobbyToOUTSIDECity1 10*8,31*8,16*8,32*8
#define RANGE_CITYStadiumLobbyToOUTSIDECity2 21*8,31*8,27*8,32*8
#define RANGE_CITYStadiumLobbyToOUTSIDECity3 32*8,31*8,38*8,32*8
#define RANGE_CITYStadiumLobbyToOUTSIDECity4 43*8,31*8,49*8,32*8
#define RANGE_CITYStadiumLobbyToOUTSIDECity5 81*8,31*8,87*8,32*8
#define RANGE_CITYStadiumLobbyToOUTSIDECity6 92*8,31*8,98*8,32*8
#define RANGE_CITYStadiumLobbyToOUTSIDECity7 103*8,31*8,109*8,32*8
#define RANGE_CITYStadiumLobbyToOUTSIDECity8 114*8,31*8,120*8,32*8
#define RANGE_CITYStadiumLobbyToOUTSIDECity9 153*8,31*8,159*8,32*8
#define RANGE_CITYStadiumLobbyToOUTSIDECity10 164*8,31*8,170*8,32*8
#define RANGE_CITYStadiumLobbyToOUTSIDECity11 175*8,31*8,181*8,32*8
#define RANGE_CITYStadiumLobbyToOUTSIDECity12 186*8,31*8,192*8,32*8
#define RANGE_CITYStadiumLobbyToMain1 2*8,4*8,8*8,5*8
#define RANGE_CITYStadiumLobbyToMain2 9*8,4*8,15*8,5*8
#define RANGE_CITYStadiumLobbyToMain3 94*8,4*8,101*8,5*8
#define RANGE_CITYStadiumLobbyToMain4 102*8,4*8,109*8,5*8
#define RANGE_CITYStadiumLobbyToMain5 188*8,4*8,194*8,5*8
#define RANGE_CITYStadiumLobbyToMain6 195*8,4*8,201*8,5*8
#define RANGE_CITYStadiumLobbyToMensBathroomLeft 17*8,15*8,21*8,16*8
#define RANGE_CITYStadiumLobbyToMensBathroomRight 88*8,15*8,92*8,16*8
#define RANGE_CITYStadiumLobbyToWomensBathroomLeft 111*8,15*8,115*8,16*8
#define RANGE_CITYStadiumLobbyToWomensBathroomRight 182*8,15*8,186*8,16*8
#define RANGE_CITYStadiumBathroomLeftMensToLobbyLeft 3*8,23*8,7*8,24*8
#define RANGE_CITYStadiumBathroomLeftMensToLobbyRight 74*8,23*8,78*8,24*8
#define RANGE_CITYStadiumBathroomRightWomensToLobbyLeft 3*8,23*8,7*8,24*8
#define RANGE_CITYStadiumBathroomRightWomensToLobbyRight 74*8,23*8,78*8,24*8
#define RANGE_CITYStadiumLeftHallwayToMain 6*8,187*8,10*8,188*8
#define RANGE_CITYStadiumLeftHallwayToBackstage 6*8,9*8,10*8,10*8
#define RANGE_CITYStadiumRightHallwayToMain 6*8,187*8,10*8,188*8
#define RANGE_CITYStadiumRightHallwayToBackstage 6*8,9*8,10*8,10*8
#define RANGE_CITYStadiumBackstageToLeftHallway 6*8,24*8,10*8,25*8
#define RANGE_CITYStadiumBackstageToRightHallway 193*8,24*8,197*8,25*8
#define RANGE_CITYStadiumBackstageToDressingRoom 11*8,9*8,15*8,10*8
#define RANGE_CITYStadiumBackstageToDressingRoom2 46*8,9*8,50*8,10*8
#define RANGE_CITYStadiumBackstageToDressingRoom3 152*8,9*8,156*8,10*8
#define RANGE_CITYStadiumBackstageToProducerRoom 186*8,9*8,190*8,10*8
#define RANGE_CITYStadiumBackstageToStageLeft 19*8,24*8,23*8,25*8
#define RANGE_CITYStadiumBackstageToStageRight 180*8,24*8,184*8,25*8
#define RANGE_CITYStadiumDressingRoomToBackstage 3*8,17*8,7*8,18*8
#define RANGE_CITYStadiumDressingRoomToBathroom 3*8,9*8,7*8,10*8
#define RANGE_CITYStadiumBathroomToDressingRoom 3*8,17*8,7*8,18*8
#define RANGE_CITYStadiumMainToBackstageRight 179*8,19*8,185*8,20*8
#define RANGE_CITYStadiumMainToBackstageLeft 18*8,19*8,24*8,20*8
#define RANGE_CITYStadiumMainToLeftHallway 6*8,201*8,10*8,202*8
#define RANGE_CITYStadiumMainToRightHallway 192*8,201*8,196*8,202*8
#define RANGE_CITYStadiumMainToLobby1 2*8,223*8,8*8,224*8
#define RANGE_CITYStadiumMainToLobby2 9*8,223*8,15*8,224*8
#define RANGE_CITYStadiumMainToLobby3 94*8,223*8,101*8,224*8
#define RANGE_CITYStadiumMainToLobby4 102*8,223*8,109*8,224*8
#define RANGE_CITYStadiumMainToLobby5 188*8,223*8,194*8,224*8
#define RANGE_CITYStadiumMainToLobby6 195*8,223*8,201*8,224*8
#define RANGE_CITYStadiumProducerRoomToBackstage 12*8,27*8,16*8,28*8
#define RANGE_CITYStadiumDressingRoom2ToBackstage 3*8,17*8,7*8,18*8
#define RANGE_CITYStadiumDressingRoom2ToBathroom 3*8,9*8,7*8,10*8
#define RANGE_CITYStadiumDressingRoom2BathroomToDressingRoom2 3*8,17*8,7*8,18*8
#define RANGE_CITYStadiumDressingRoom3ToBackstage 3*8,17*8,7*8,18*8
#define RANGE_CITYStadiumDressingRoom3ToBathroom 3*8,9*8,7*8,10*8
#define RANGE_CITYStadiumDressingRoom3BathroomToDressingRoom3 3*8,17*8,7*8,18*8

//========================================================
//CITYStadiumLobby
//========================================================
void bobsgame_CITYStadiumLobby_Map_Load_Function()
{

//RANGE_CITYStadiumLobbyToOUTSIDECity1 10*8,31*8,16*8,32*8
//RANGE_CITYStadiumLobbyToOUTSIDECity2 21*8,31*8,27*8,32*8
//RANGE_CITYStadiumLobbyToOUTSIDECity3 32*8,31*8,38*8,32*8
//RANGE_CITYStadiumLobbyToOUTSIDECity4 43*8,31*8,49*8,32*8
//RANGE_CITYStadiumLobbyToOUTSIDECity5 81*8,31*8,87*8,32*8
//RANGE_CITYStadiumLobbyToOUTSIDECity6 92*8,31*8,98*8,32*8
//RANGE_CITYStadiumLobbyToOUTSIDECity7 103*8,31*8,109*8,32*8
//RANGE_CITYStadiumLobbyToOUTSIDECity8 114*8,31*8,120*8,32*8
//RANGE_CITYStadiumLobbyToOUTSIDECity9 153*8,31*8,159*8,32*8
//RANGE_CITYStadiumLobbyToOUTSIDECity10 164*8,31*8,170*8,32*8
//RANGE_CITYStadiumLobbyToOUTSIDECity11 175*8,31*8,181*8,32*8
//RANGE_CITYStadiumLobbyToOUTSIDECity12 186*8,31*8,192*8,32*8

//RANGE_CITYStadiumLobbyToMain1 2*8,4*8,8*8,5*8
//RANGE_CITYStadiumLobbyToMain2 9*8,4*8,15*8,5*8
//RANGE_CITYStadiumLobbyToMain3 94*8,4*8,101*8,5*8
//RANGE_CITYStadiumLobbyToMain4 102*8,4*8,109*8,5*8
//RANGE_CITYStadiumLobbyToMain5 188*8,4*8,194*8,5*8
//RANGE_CITYStadiumLobbyToMain6 195*8,4*8,201*8,5*8

//RANGE_CITYStadiumLobbyToMensBathroomLeft 17*8,15*8,21*8,16*8
//RANGE_CITYStadiumLobbyToMensBathroomRight 88*8,15*8,92*8,16*8
//RANGE_CITYStadiumLobbyToMensBathroomRight 88*8,15*8,92*8,16*8

//RANGE_CITYStadiumLobbyToWomensBathroomLeft 111*8,15*8,115*8,16*8
//RANGE_CITYStadiumLobbyToWomensBathroomRight 182*8,15*8,186*8,16*8

}

void bobsgame_CITYStadiumLobby_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//TODO: need cashier sprite. maybe striped or something similar to tacoburger sprites

//cashiers
//37,17
//50
//69
//82
//129
//144
//163
//176

	static NPC* stadiumcashier_npcs[8] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<8;c++)
	{
		if(stadiumcashier_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			GFX* gfx=NULL;

			if(c== 0){x= 37*8+2;y=17*8+4;dir=DOWN;bgp=3;}
			if(c== 1){x= 50*8+2;y=17*8+4;dir=DOWN;bgp=3;}
			if(c== 2){x= 69*8+2;y=17*8+4;dir=DOWN;bgp=3;}
			if(c== 3){x= 82*8+2;y=17*8+4;dir=DOWN;bgp=3;}
			if(c== 4){x=131*8+2;y=17*8+4;dir=DOWN;bgp=3;}
			if(c== 5){x=144*8+2;y=17*8+4;dir=DOWN;bgp=3;}
			if(c== 6){x=163*8+2;y=17*8+4;dir=DOWN;bgp=3;}
			if(c== 7){x=176*8+2;y=17*8+4;dir=DOWN;bgp=3;}

			if(gfx==NULL)NPC_create_random_ADULT_xy_feet(&stadiumcashier_npcs[c],x,y);
			else NPC_create_npc_xy_feet(&stadiumcashier_npcs[c],gfx,16,40,x,y);

			NPC_animate_stand_dir(&stadiumcashier_npcs[c],dir);
			stadiumcashier_npcs[c]->non_walkable=1;
			stadiumcashier_npcs[c]->walk_dir=dir;
			stadiumcashier_npcs[c]->layer=bgp;
			//NPC_animate_increment_direction_frame_now(&stadiumcashier_npcs[c],dir);
		}

		if(stadiumcashier_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stadiumcashier_npcs[c],15))NPC_stare_at_npc_not_opposite_walking_direction(&stadiumcashier_npcs[c],&PLAYER_npc);
			else if(stadiumcashier_npcs[c]->AI==0){if(stadiumcashier_npcs[c]->vbls>200){if(r(4)==0){stadiumcashier_npcs[c]->AI=1+r(3);}else{stadiumcashier_npcs[c]->vbls=0;NPC_animate_stand_dir(&stadiumcashier_npcs[c], stadiumcashier_npcs[c]->walk_dir);if(stadiumcashier_npcs[c]->anim_frame_count!=0){stadiumcashier_npcs[c]->anim_frame_count=3;NPC_animate(&stadiumcashier_npcs[c]);}}}}
			else if(stadiumcashier_npcs[c]->AI==1){if(stadiumcashier_npcs[c]->walk_dir==UP||stadiumcashier_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&stadiumcashier_npcs[c],LEFT);else NPC_animate_stand_dir(&stadiumcashier_npcs[c],UP);stadiumcashier_npcs[c]->vbls=r(120);stadiumcashier_npcs[c]->AI=0;}
			else if(stadiumcashier_npcs[c]->AI==2){if(stadiumcashier_npcs[c]->walk_dir==UP||stadiumcashier_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&stadiumcashier_npcs[c],RIGHT);else NPC_animate_stand_dir(&stadiumcashier_npcs[c],DOWN);stadiumcashier_npcs[c]->vbls=r(120);stadiumcashier_npcs[c]->AI=0;}
			else if(stadiumcashier_npcs[c]->AI==3){NPC_animate(&stadiumcashier_npcs[c]);stadiumcashier_npcs[c]->vbls=r(120);stadiumcashier_npcs[c]->AI=0;}

			//if(NPC_in_range_of_npc_amt(&PLAYER_npc,stadiumcashier_npcs[c],15))NPC_stare_at_npc(&stadiumcashier_npcs[c],PLAYER_npc);
			//else NPC_animate_set_direction_now(&stadiumcashier_npcs[c], stadiumcashier_npcs[c]->walking_direction);
		}
	}

//people coming from doors and going up the stairs
//doors
//13,30
//24
//35
//46

//84
//95
//106
//117

//156
//167
//178
//189

//stairs
//  5,2
// 12
// 98
//105
//191
//198

	//c=0;
	//static NPC* stadiumlobby_npcs[6] = {NULL,NULL,NULL,NULL,NULL,NULL};
	//static int last_clock=0;
	//for(c=0;c<6;c++)
	//{
	//	if(stadiumlobby_npcs[c]==NULL&&CLOCK_minute%2==0&&CLOCK_minute!=last_clock)
	//	{
	//
	//		last_clock=CLOCK_minute;
	//		int r=r(12);
	//
	//			 if(r== 0){NPC_create_random_ADULT_xy_feet(&stadiumlobby_npcs[c], 13*8,30*8);}
	//		else if(r== 1){NPC_create_random_ADULT_xy_feet(&stadiumlobby_npcs[c], 24*8,30*8);}
	//		else if(r== 2){NPC_create_random_ADULT_xy_feet(&stadiumlobby_npcs[c], 35*8,30*8);}
	//
	//		else if(r== 3){NPC_create_random_ADULT_xy_feet(&stadiumlobby_npcs[c], 46*8,30*8);}
	//		else if(r== 4){NPC_create_random_ADULT_xy_feet(&stadiumlobby_npcs[c], 84*8,30*8);}
	//		else if(r== 5){NPC_create_random_ADULT_xy_feet(&stadiumlobby_npcs[c], 95*8,30*8);}
	//
	//		else if(r== 6){NPC_create_random_ADULT_xy_feet(&stadiumlobby_npcs[c],106*8,30*8);}
	//		else if(r== 7){NPC_create_random_ADULT_xy_feet(&stadiumlobby_npcs[c],117*8,30*8);}
	//		else if(r== 8){NPC_create_random_ADULT_xy_feet(&stadiumlobby_npcs[c],156*8,30*8);}
	//
	//		else if(r== 9){NPC_create_random_ADULT_xy_feet(&stadiumlobby_npcs[c],167*8,30*8);}
	//		else if(r==10){NPC_create_random_ADULT_xy_feet(&stadiumlobby_npcs[c],178*8,30*8);}
	//		else if(r==11){NPC_create_random_ADULT_xy_feet(&stadiumlobby_npcs[c],189*8,30*8);}
	//
	//		stadiumlobby_npcs[c]->non_walkable=1;
	//		stadiumlobby_npcs[c]->cycle=0;
	//		stadiumlobby_npcs[c]->walking_speed=SPEED_NORMAL+r(SPEED_SLOW-SPEED_FASTEST);
	//		//stadiumlobby_npcs[c]->ignore_fx_layer=1;
	//		NPC_animate_set_direction_now(&stadiumlobby_npcs[c],UP);
	//	}
	//
	//	if(stadiumlobby_npcs[c]!=NULL)
	//	{
	//		if(stadiumlobby_npcs[c]->cycle== 0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&stadiumlobby_npcs[c],stadiumlobby_npcs[c]->walking_speed, -1,24*8)==(1))stadiumlobby_npcs[c]->cycle=4+r(6);
	//		if(stadiumlobby_npcs[c]->cycle== 1)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&stadiumlobby_npcs[c],stadiumlobby_npcs[c]->walking_speed, -1,25*8)==(1))stadiumlobby_npcs[c]->cycle=4+r(6);
	//		if(stadiumlobby_npcs[c]->cycle== 2)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&stadiumlobby_npcs[c],stadiumlobby_npcs[c]->walking_speed, -1,26*8)==(1))stadiumlobby_npcs[c]->cycle=4+r(6);
	//		if(stadiumlobby_npcs[c]->cycle== 3)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&stadiumlobby_npcs[c],stadiumlobby_npcs[c]->walking_speed, -1,27*8)==(1))stadiumlobby_npcs[c]->cycle=4+r(6);
	//
	//		if(stadiumlobby_npcs[c]->cycle== 4)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&stadiumlobby_npcs[c],stadiumlobby_npcs[c]->walking_speed,  5*8,-1)==1)stadiumlobby_npcs[c]->cycle=10;
	//		if(stadiumlobby_npcs[c]->cycle== 5)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&stadiumlobby_npcs[c],stadiumlobby_npcs[c]->walking_speed, 12*8,-1)==1)stadiumlobby_npcs[c]->cycle=10;
	//		if(stadiumlobby_npcs[c]->cycle== 6)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&stadiumlobby_npcs[c],stadiumlobby_npcs[c]->walking_speed, 98*8,-1)==1)stadiumlobby_npcs[c]->cycle=10;
	//		if(stadiumlobby_npcs[c]->cycle== 7)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&stadiumlobby_npcs[c],stadiumlobby_npcs[c]->walking_speed,105*8,-1)==1)stadiumlobby_npcs[c]->cycle=10;
	//		if(stadiumlobby_npcs[c]->cycle== 8)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&stadiumlobby_npcs[c],stadiumlobby_npcs[c]->walking_speed,191*8,-1)==1)stadiumlobby_npcs[c]->cycle=10;
	//		if(stadiumlobby_npcs[c]->cycle== 9)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&stadiumlobby_npcs[c],stadiumlobby_npcs[c]->walking_speed,198*8,-1)==1)stadiumlobby_npcs[c]->cycle=10;
			//if(stadiumlobby_npcs[c]->cycle==10)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&stadiumlobby_npcs[c],stadiumlobby_npcs[c]->walking_speed, -1,2*8)==1){NPC_delete_npc(&stadiumlobby_npcs[c]);}
		//}
	//}

//people coming from left and right, traveling to other side, deleting.

//people waiting in line, people created from left/right of touchmap, if place is taken or you're in place, dont advance.
//cashiers
//37,21
//50
//69
//82
//129
//144
//163
//176

	c=0;
	static NPC* lobbyline_npcs[35] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

	for(c=0;c<35;c++)
	{
		if(lobbyline_npcs[c]==NULL)
		{

			int randnum=r(2);
			int x=MAP_cam_x-16;
			if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
			int y=(25+randnum)*8;
			if(!NPC_cant_create_at_xy(x,y))NPC_create_random_ADULT_xy_feet(&lobbyline_npcs[c],x,y);

			if(lobbyline_npcs[c]!=NULL)lobbyline_npcs[c]->non_walkable=1;
			if(lobbyline_npcs[c]!=NULL)lobbyline_npcs[c]->AI=r(14);
			if(lobbyline_npcs[c]!=NULL)lobbyline_npcs[c]->walking_speed=SPEED_FAST+r(SPEED_SLOW-SPEED_FASTEST);
			//if(lobbyline_npcs[c]!=NULL)lobbyline_npcs[c]->ignore_fx_layer=1;
			if(lobbyline_npcs[c]!=NULL)NPC_animate_stand_dir(&lobbyline_npcs[c],UP);
		}

		if(lobbyline_npcs[c]!=NULL)
		{
			if(lobbyline_npcs[c]->AI== 0){if(MAP_is_xy_within_screen_by_64px( 37*8,21*8))lobbyline_npcs[c]->AI+=14; else lobbyline_npcs[c]->AI=r(8);}
			if(lobbyline_npcs[c]->AI== 1){if(MAP_is_xy_within_screen_by_64px( 50*8,21*8))lobbyline_npcs[c]->AI+=14; else lobbyline_npcs[c]->AI=r(8);}
			if(lobbyline_npcs[c]->AI== 2){if(MAP_is_xy_within_screen_by_64px( 69*8,21*8))lobbyline_npcs[c]->AI+=14; else lobbyline_npcs[c]->AI=r(8);}
			if(lobbyline_npcs[c]->AI== 3){if(MAP_is_xy_within_screen_by_64px( 82*8,21*8))lobbyline_npcs[c]->AI+=14; else lobbyline_npcs[c]->AI=r(8);}
			if(lobbyline_npcs[c]->AI== 4){if(MAP_is_xy_within_screen_by_64px(129*8,21*8))lobbyline_npcs[c]->AI+=14; else lobbyline_npcs[c]->AI=r(8);}
			if(lobbyline_npcs[c]->AI== 5){if(MAP_is_xy_within_screen_by_64px(144*8,21*8))lobbyline_npcs[c]->AI+=14; else lobbyline_npcs[c]->AI=r(8);}
			if(lobbyline_npcs[c]->AI== 6){if(MAP_is_xy_within_screen_by_64px(163*8,21*8))lobbyline_npcs[c]->AI+=14; else lobbyline_npcs[c]->AI=r(8);}
			if(lobbyline_npcs[c]->AI== 7){if(MAP_is_xy_within_screen_by_64px(176*8,21*8))lobbyline_npcs[c]->AI+=14; else lobbyline_npcs[c]->AI=r(8);}

			if(lobbyline_npcs[c]->AI== 8){if(MAP_is_xy_within_screen_by_64px(  5*8,21*8))lobbyline_npcs[c]->AI+=14; else lobbyline_npcs[c]->AI=8+r(6);}
			if(lobbyline_npcs[c]->AI== 9){if(MAP_is_xy_within_screen_by_64px( 12*8,21*8))lobbyline_npcs[c]->AI+=14; else lobbyline_npcs[c]->AI=8+r(6);}
			if(lobbyline_npcs[c]->AI==10){if(MAP_is_xy_within_screen_by_64px( 98*8,21*8))lobbyline_npcs[c]->AI+=14; else lobbyline_npcs[c]->AI=8+r(6);}
			if(lobbyline_npcs[c]->AI==11){if(MAP_is_xy_within_screen_by_64px(105*8,21*8))lobbyline_npcs[c]->AI+=14; else lobbyline_npcs[c]->AI=8+r(6);}
			if(lobbyline_npcs[c]->AI==12){if(MAP_is_xy_within_screen_by_64px(191*8,21*8))lobbyline_npcs[c]->AI+=14; else lobbyline_npcs[c]->AI=8+r(6);}
			if(lobbyline_npcs[c]->AI==13){if(MAP_is_xy_within_screen_by_64px(198*8,21*8))lobbyline_npcs[c]->AI+=14; else lobbyline_npcs[c]->AI=8+r(6);}

			if(lobbyline_npcs[c]->AI==14)if(NPC_walk_to_xy_intelligenthit_pushothers(&lobbyline_npcs[c],lobbyline_npcs[c]->walking_speed, 37*8,-1)==1)lobbyline_npcs[c]->AI=28;
			if(lobbyline_npcs[c]->AI==15)if(NPC_walk_to_xy_intelligenthit_pushothers(&lobbyline_npcs[c],lobbyline_npcs[c]->walking_speed, 50*8,-1)==1)lobbyline_npcs[c]->AI=28;
			if(lobbyline_npcs[c]->AI==16)if(NPC_walk_to_xy_intelligenthit_pushothers(&lobbyline_npcs[c],lobbyline_npcs[c]->walking_speed, 69*8,-1)==1)lobbyline_npcs[c]->AI=28;
			if(lobbyline_npcs[c]->AI==17)if(NPC_walk_to_xy_intelligenthit_pushothers(&lobbyline_npcs[c],lobbyline_npcs[c]->walking_speed, 82*8,-1)==1)lobbyline_npcs[c]->AI=28;
			if(lobbyline_npcs[c]->AI==18)if(NPC_walk_to_xy_intelligenthit_pushothers(&lobbyline_npcs[c],lobbyline_npcs[c]->walking_speed,129*8,-1)==1)lobbyline_npcs[c]->AI=28;
			if(lobbyline_npcs[c]->AI==19)if(NPC_walk_to_xy_intelligenthit_pushothers(&lobbyline_npcs[c],lobbyline_npcs[c]->walking_speed,144*8,-1)==1)lobbyline_npcs[c]->AI=28;
			if(lobbyline_npcs[c]->AI==20)if(NPC_walk_to_xy_intelligenthit_pushothers(&lobbyline_npcs[c],lobbyline_npcs[c]->walking_speed,163*8,-1)==1)lobbyline_npcs[c]->AI=28;
			if(lobbyline_npcs[c]->AI==21)if(NPC_walk_to_xy_intelligenthit_pushothers(&lobbyline_npcs[c],lobbyline_npcs[c]->walking_speed,176*8,-1)==1)lobbyline_npcs[c]->AI=28;

			if(lobbyline_npcs[c]->AI==22){if(MAP_is_xy_within_screen_by_64px(lobbyline_npcs[c]->MAP_x,lobbyline_npcs[c]->MAP_y)==0){NPC_delete_npc(&lobbyline_npcs[c]);}else if(NPC_walk_to_xy_intelligenthit_pushothers(&lobbyline_npcs[c],lobbyline_npcs[c]->walking_speed,  5*8,-1)==1)lobbyline_npcs[c]->AI=30;}
			if(lobbyline_npcs[c]->AI==23){if(MAP_is_xy_within_screen_by_64px(lobbyline_npcs[c]->MAP_x,lobbyline_npcs[c]->MAP_y)==0){NPC_delete_npc(&lobbyline_npcs[c]);}else if(NPC_walk_to_xy_intelligenthit_pushothers(&lobbyline_npcs[c],lobbyline_npcs[c]->walking_speed, 12*8,-1)==1)lobbyline_npcs[c]->AI=30;}
			if(lobbyline_npcs[c]->AI==24){if(MAP_is_xy_within_screen_by_64px(lobbyline_npcs[c]->MAP_x,lobbyline_npcs[c]->MAP_y)==0){NPC_delete_npc(&lobbyline_npcs[c]);}else if(NPC_walk_to_xy_intelligenthit_pushothers(&lobbyline_npcs[c],lobbyline_npcs[c]->walking_speed, 98*8,-1)==1)lobbyline_npcs[c]->AI=30;}
			if(lobbyline_npcs[c]->AI==25){if(MAP_is_xy_within_screen_by_64px(lobbyline_npcs[c]->MAP_x,lobbyline_npcs[c]->MAP_y)==0){NPC_delete_npc(&lobbyline_npcs[c]);}else if(NPC_walk_to_xy_intelligenthit_pushothers(&lobbyline_npcs[c],lobbyline_npcs[c]->walking_speed,105*8,-1)==1)lobbyline_npcs[c]->AI=30;}
			if(lobbyline_npcs[c]->AI==26){if(MAP_is_xy_within_screen_by_64px(lobbyline_npcs[c]->MAP_x,lobbyline_npcs[c]->MAP_y)==0){NPC_delete_npc(&lobbyline_npcs[c]);}else if(NPC_walk_to_xy_intelligenthit_pushothers(&lobbyline_npcs[c],lobbyline_npcs[c]->walking_speed,191*8,-1)==1)lobbyline_npcs[c]->AI=30;}
			if(lobbyline_npcs[c]->AI==27){if(MAP_is_xy_within_screen_by_64px(lobbyline_npcs[c]->MAP_x,lobbyline_npcs[c]->MAP_y)==0){NPC_delete_npc(&lobbyline_npcs[c]);}else if(NPC_walk_to_xy_intelligenthit_pushothers(&lobbyline_npcs[c],lobbyline_npcs[c]->walking_speed,198*8,-1)==1)lobbyline_npcs[c]->AI=30;}

			if(lobbyline_npcs[c]->AI==28)if(NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,lobbyline_npcs[c]->MAP_x-16,20*8,lobbyline_npcs[c]->MAP_x+16+16,23*8,UP,0)==0){if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&lobbyline_npcs[c],lobbyline_npcs[c]->walking_speed,  -1, 21*8+4)==1){lobbyline_npcs[c]->AI++;lobbyline_npcs[c]->vbls=r(40);}}
			if(lobbyline_npcs[c]->AI==29)if(lobbyline_npcs[c]->vbls>200)lobbyline_npcs[c]->AI=8+r(6);

			if(lobbyline_npcs[c]->AI==30){if(MAP_is_xy_within_screen_by_64px(lobbyline_npcs[c]->MAP_x,lobbyline_npcs[c]->MAP_y)==0){NPC_delete_npc(&lobbyline_npcs[c]);}else if(NPC_walk_to_xy_intelligenthit_pushothers(&lobbyline_npcs[c],lobbyline_npcs[c]->walking_speed, -1, 2*8)==1){NPC_delete_npc(&lobbyline_npcs[c]);}}

		}
	}

//TODO: crowd noises

	if(walking_into_door(RANGE_CITYStadiumLobbyToOUTSIDECity1))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,757,39);return;
	}
	if(walking_into_door(RANGE_CITYStadiumLobbyToOUTSIDECity2))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,768,39);return;
	}
	if(walking_into_door(RANGE_CITYStadiumLobbyToOUTSIDECity3))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,779,39);return;
	}
	if(walking_into_door(RANGE_CITYStadiumLobbyToOUTSIDECity4))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,790,39);return;
	}
	if(walking_into_door(RANGE_CITYStadiumLobbyToOUTSIDECity5))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,828,39);return;
	}
	if(walking_into_door(RANGE_CITYStadiumLobbyToOUTSIDECity6))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,839,39);return;
	}
	if(walking_into_door(RANGE_CITYStadiumLobbyToOUTSIDECity7))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,850,39);return;
	}
	if(walking_into_door(RANGE_CITYStadiumLobbyToOUTSIDECity8))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,861,39);return;
	}
	if(walking_into_door(RANGE_CITYStadiumLobbyToOUTSIDECity9))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,900,39);return;
	}
	if(walking_into_door(RANGE_CITYStadiumLobbyToOUTSIDECity10))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,911,39);return;
	}
	if(walking_into_door(RANGE_CITYStadiumLobbyToOUTSIDECity11))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,922,39);return;
	}
	if(walking_into_door(RANGE_CITYStadiumLobbyToOUTSIDECity12))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,933,39);return;
	}

	if(walking_into_door(RANGE_CITYStadiumLobbyToMain1))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumMain,4,222);return;
	}
	if(walking_into_door(RANGE_CITYStadiumLobbyToMain2))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumMain,11,222);return;
	}
	if(walking_into_door(RANGE_CITYStadiumLobbyToMain3))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumMain,97,222);return;
	}
	if(walking_into_door(RANGE_CITYStadiumLobbyToMain4))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumMain,104,222);return;
	}
	if(walking_into_door(RANGE_CITYStadiumLobbyToMain5))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumMain,190,222);return;
	}
	if(walking_into_door(RANGE_CITYStadiumLobbyToMain6))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumMain,197,222);return;
	}

	if(walking_into_door(RANGE_CITYStadiumLobbyToMensBathroomLeft))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumBathroomLeftMens,3,22);return;
	}
	if(walking_into_door(RANGE_CITYStadiumLobbyToMensBathroomRight))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumBathroomLeftMens,76,22);return;
	}
	if(walking_into_door(RANGE_CITYStadiumLobbyToWomensBathroomLeft))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumBathroomRightWomens,3,22);return;
		//TODO: can't do that?
	}
	if(walking_into_door(RANGE_CITYStadiumLobbyToWomensBathroomRight))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumBathroomRightWomens,76,22);return;
		//TODO: can't do that?
	}
}
void bobsgame_CITYStadiumLobby_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYStadiumLobby_Map_VBL_Function()
{

}
void bobsgame_CITYStadiumLobby_Map_HBL_Function()
{

}
//========================================================
//CITYStadiumBathroomLeftMens
//========================================================
void bobsgame_CITYStadiumBathroomLeftMens_Map_Load_Function()
{
//RANGE_CITYStadiumBathroomLeftMensToLobbyLeft 3*8,23*8,7*8,24*8
//RANGE_CITYStadiumBathroomLeftMensToLobbyRight 74*8,23*8,78*8,24*8
}
void bobsgame_CITYStadiumBathroomLeftMens_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//should have people come in, use a random urinal, flush sound, goto the sink, leave
//77,23
//3,23

//??,17

//urinals
//63,11
//66
//69
//72
//75
//78

//toilets
//33,11 down
//38,11 down open
//43,11 down
//48,11 down
//53,11 down open
//58,11 down

//sinks
//15,12 up
//18
//21
//24
//27

//5,10 up
//8
//11

	int c=0;
	static NPC* stadiumbathroom_npcs[6] = {NULL,NULL,NULL,NULL,NULL,NULL};
	static int last_clock=0;
	for(c=0;c<6;c++)
	{
		if(stadiumbathroom_npcs[c]==NULL&&CLOCK_minute%2==0&&CLOCK_minute!=last_clock)
		{

			last_clock=CLOCK_minute;
			int randnum=r(2);

				 if(randnum== 0){NPC_create_random_MAN_xy_feet(&stadiumbathroom_npcs[c], 77*8,23*8);}
			else if(randnum== 1){NPC_create_random_MAN_xy_feet(&stadiumbathroom_npcs[c],  3*8,23*8);}

			stadiumbathroom_npcs[c]->non_walkable=1;
			stadiumbathroom_npcs[c]->AI=0;
			stadiumbathroom_npcs[c]->walking_speed=SPEED_NORMAL+r(SPEED_SLOW-SPEED_FASTEST);
			stadiumbathroom_npcs[c]->ignore_fx_layer=1;
			NPC_animate_stand_dir(&stadiumbathroom_npcs[c],UP);
		}

		if(stadiumbathroom_npcs[c]!=NULL)
		{
			if(stadiumbathroom_npcs[c]->AI== 0)if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumbathroom_npcs[c],stadiumbathroom_npcs[c]->walking_speed, -1,17*8)==(1))stadiumbathroom_npcs[c]->AI=1+r(6);

			if(stadiumbathroom_npcs[c]->AI== 1)if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumbathroom_npcs[c],stadiumbathroom_npcs[c]->walking_speed, 63*8,-1)==1)stadiumbathroom_npcs[c]->AI=7;
			if(stadiumbathroom_npcs[c]->AI== 2)if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumbathroom_npcs[c],stadiumbathroom_npcs[c]->walking_speed, 66*8,-1)==1)stadiumbathroom_npcs[c]->AI=7;
			if(stadiumbathroom_npcs[c]->AI== 3)if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumbathroom_npcs[c],stadiumbathroom_npcs[c]->walking_speed, 69*8,-1)==1)stadiumbathroom_npcs[c]->AI=7;
			if(stadiumbathroom_npcs[c]->AI== 4)if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumbathroom_npcs[c],stadiumbathroom_npcs[c]->walking_speed, 72*8,-1)==1)stadiumbathroom_npcs[c]->AI=7;
			if(stadiumbathroom_npcs[c]->AI== 5)if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumbathroom_npcs[c],stadiumbathroom_npcs[c]->walking_speed, 75*8,-1)==1)stadiumbathroom_npcs[c]->AI=7;
			if(stadiumbathroom_npcs[c]->AI== 6)if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumbathroom_npcs[c],stadiumbathroom_npcs[c]->walking_speed, 78*8,-1)==1)stadiumbathroom_npcs[c]->AI=7;

			if(stadiumbathroom_npcs[c]->AI== 7)if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumbathroom_npcs[c],stadiumbathroom_npcs[c]->walking_speed, -1,11*8)==(1)){stadiumbathroom_npcs[c]->AI++;stadiumbathroom_npcs[c]->vbls=r(40);NPC_animate_stand_dir(&stadiumbathroom_npcs[c],UP);}
			if(stadiumbathroom_npcs[c]->AI== 8)if(stadiumbathroom_npcs[c]->vbls>200)stadiumbathroom_npcs[c]->AI++;
			if(stadiumbathroom_npcs[c]->AI== 9)if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumbathroom_npcs[c],stadiumbathroom_npcs[c]->walking_speed, -1,17*8)==(1)){stadiumbathroom_npcs[c]->AI++;}

			if(stadiumbathroom_npcs[c]->AI==10)if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumbathroom_npcs[c],stadiumbathroom_npcs[c]->walking_speed, 15*8,-1)==1)stadiumbathroom_npcs[c]->AI=15;
			if(stadiumbathroom_npcs[c]->AI==11)if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumbathroom_npcs[c],stadiumbathroom_npcs[c]->walking_speed, 18*8,-1)==1)stadiumbathroom_npcs[c]->AI=15;
			if(stadiumbathroom_npcs[c]->AI==12)if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumbathroom_npcs[c],stadiumbathroom_npcs[c]->walking_speed, 21*8,-1)==1)stadiumbathroom_npcs[c]->AI=15;
			if(stadiumbathroom_npcs[c]->AI==13)if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumbathroom_npcs[c],stadiumbathroom_npcs[c]->walking_speed, 24*8,-1)==1)stadiumbathroom_npcs[c]->AI=15;
			if(stadiumbathroom_npcs[c]->AI==14)if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumbathroom_npcs[c],stadiumbathroom_npcs[c]->walking_speed, 27*8,-1)==1)stadiumbathroom_npcs[c]->AI=15;

			if(stadiumbathroom_npcs[c]->AI==15)if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumbathroom_npcs[c],stadiumbathroom_npcs[c]->walking_speed, -1,12*8)==(1)){stadiumbathroom_npcs[c]->AI++;stadiumbathroom_npcs[c]->vbls=r(40);NPC_animate_stand_dir(&stadiumbathroom_npcs[c],UP);}
			if(stadiumbathroom_npcs[c]->AI==16)if(stadiumbathroom_npcs[c]->vbls>200)stadiumbathroom_npcs[c]->AI++;

			if(stadiumbathroom_npcs[c]->AI==17)if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumbathroom_npcs[c],stadiumbathroom_npcs[c]->walking_speed,  5*8,-1)==1)stadiumbathroom_npcs[c]->AI=20;
			if(stadiumbathroom_npcs[c]->AI==18)if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumbathroom_npcs[c],stadiumbathroom_npcs[c]->walking_speed,  8*8,-1)==1)stadiumbathroom_npcs[c]->AI=20;
			if(stadiumbathroom_npcs[c]->AI==19)if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumbathroom_npcs[c],stadiumbathroom_npcs[c]->walking_speed, 11*8,-1)==1)stadiumbathroom_npcs[c]->AI=20;

			if(stadiumbathroom_npcs[c]->AI==20)if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumbathroom_npcs[c],stadiumbathroom_npcs[c]->walking_speed, -1,10*8)==1){stadiumbathroom_npcs[c]->AI++;stadiumbathroom_npcs[c]->vbls=r(40);NPC_animate_stand_dir(&stadiumbathroom_npcs[c],UP);}
			if(stadiumbathroom_npcs[c]->AI==21)if(stadiumbathroom_npcs[c]->vbls>200)stadiumbathroom_npcs[c]->AI++;

			if(stadiumbathroom_npcs[c]->AI==22)if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumbathroom_npcs[c],stadiumbathroom_npcs[c]->walking_speed, 3, 23*8)==1){NPC_delete_npc(&stadiumbathroom_npcs[c]);}
		}
	}

	static NPC* stallman1_npc = NULL;
	if(stallman1_npc==NULL)
	{
		NPC_create_random_MAN_xy_feet(&stallman1_npc,32*8,11*8);
		//NPC_create_npc_xy_feet(&stallman1_npc,SPRITE,16,40,7*8,27*8);
		stallman1_npc->non_walkable=1;
		stallman1_npc->layer=2;
		NPC_animate_stand_dir(&stallman1_npc,DOWN);
		stallman1_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		stallman1_npc->walk_dir=stallman1_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&stallman1_npc, stallman1_npc->anim_direction);
	}
	if(stallman1_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stallman1_npc,45))NPC_stare_at_npc_not_opposite_walking_direction(&stallman1_npc,&PLAYER_npc);
		else if(stallman1_npc->AI==0){if(stallman1_npc->vbls>200){if(r(4)==0){stallman1_npc->AI=1+r(3);}else{stallman1_npc->vbls=0;NPC_animate_stand_dir(&stallman1_npc, stallman1_npc->walk_dir);if(stallman1_npc->anim_frame_count!=0){stallman1_npc->anim_frame_count=3;NPC_animate(&stallman1_npc);}}}}
		else if(stallman1_npc->AI==1){if(stallman1_npc->walk_dir==UP||stallman1_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallman1_npc,LEFT);else NPC_animate_stand_dir(&stallman1_npc,UP);stallman1_npc->vbls=r(120);stallman1_npc->AI=0;}
		else if(stallman1_npc->AI==2){if(stallman1_npc->walk_dir==UP||stallman1_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallman1_npc,RIGHT);else NPC_animate_stand_dir(&stallman1_npc,DOWN);stallman1_npc->vbls=r(120);stallman1_npc->AI=0;}
		else if(stallman1_npc->AI==3){NPC_animate(&stallman1_npc);stallman1_npc->vbls=r(120);stallman1_npc->AI=0;}

		if(ACTION_range_xy_xy(32*8,13*8,34*8,14*8,"Talk To Pooping Man"))
		{
			TEXT_set_sprite_window(0,stallman1_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	static NPC* stallman2_npc = NULL;
	if(stallman2_npc==NULL)
	{
		NPC_create_random_MAN_xy_feet(&stallman2_npc,42*8,11*8);
		//NPC_create_npc_xy_feet(&stallman2_npc,SPRITE,16,40,7*8,27*8);
		stallman2_npc->non_walkable=1;
		stallman2_npc->layer=2;
		NPC_animate_stand_dir(&stallman2_npc,DOWN);
		stallman2_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		stallman2_npc->walk_dir=stallman2_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&stallman2_npc, stallman2_npc->anim_direction);
	}
	if(stallman2_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stallman2_npc,45))NPC_stare_at_npc_not_opposite_walking_direction(&stallman2_npc,&PLAYER_npc);
		else if(stallman2_npc->AI==0){if(stallman2_npc->vbls>200){if(r(4)==0){stallman2_npc->AI=1+r(3);}else{stallman2_npc->vbls=0;NPC_animate_stand_dir(&stallman2_npc, stallman2_npc->walk_dir);if(stallman2_npc->anim_frame_count!=0){stallman2_npc->anim_frame_count=3;NPC_animate(&stallman2_npc);}}}}
		else if(stallman2_npc->AI==1){if(stallman2_npc->walk_dir==UP||stallman2_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallman2_npc,LEFT);else NPC_animate_stand_dir(&stallman2_npc,UP);stallman2_npc->vbls=r(120);stallman2_npc->AI=0;}
		else if(stallman2_npc->AI==2){if(stallman2_npc->walk_dir==UP||stallman2_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallman2_npc,RIGHT);else NPC_animate_stand_dir(&stallman2_npc,DOWN);stallman2_npc->vbls=r(120);stallman2_npc->AI=0;}
		else if(stallman2_npc->AI==3){NPC_animate(&stallman2_npc);stallman2_npc->vbls=r(120);stallman2_npc->AI=0;}

		if(ACTION_range_xy_xy(42*8,13*8,44*8,14*8,"Talk To Pooping Man"))
		{
			TEXT_set_sprite_window(0,stallman2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	static NPC* stallman3_npc = NULL;
	if(stallman3_npc==NULL)
	{
		NPC_create_random_MAN_xy_feet(&stallman3_npc,47*8,11*8);
		//NPC_create_npc_xy_feet(&stallman3_npc,SPRITE,16,40,7*8,27*8);
		stallman3_npc->non_walkable=1;
		stallman3_npc->layer=2;
		NPC_animate_stand_dir(&stallman3_npc,DOWN);
		stallman3_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		stallman3_npc->walk_dir=stallman3_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&stallman3_npc, stallman3_npc->anim_direction);
	}
	if(stallman3_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stallman3_npc,45))NPC_stare_at_npc_not_opposite_walking_direction(&stallman3_npc,&PLAYER_npc);
		else if(stallman3_npc->AI==0){if(stallman3_npc->vbls>200){if(r(4)==0){stallman3_npc->AI=1+r(3);}else{stallman3_npc->vbls=0;NPC_animate_stand_dir(&stallman3_npc, stallman3_npc->walk_dir);if(stallman3_npc->anim_frame_count!=0){stallman3_npc->anim_frame_count=3;NPC_animate(&stallman3_npc);}}}}
		else if(stallman3_npc->AI==1){if(stallman3_npc->walk_dir==UP||stallman3_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallman3_npc,LEFT);else NPC_animate_stand_dir(&stallman3_npc,UP);stallman3_npc->vbls=r(120);stallman3_npc->AI=0;}
		else if(stallman3_npc->AI==2){if(stallman3_npc->walk_dir==UP||stallman3_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallman3_npc,RIGHT);else NPC_animate_stand_dir(&stallman3_npc,DOWN);stallman3_npc->vbls=r(120);stallman3_npc->AI=0;}
		else if(stallman3_npc->AI==3){NPC_animate(&stallman3_npc);stallman3_npc->vbls=r(120);stallman3_npc->AI=0;}

		if(ACTION_range_xy_xy(47*8,13*8,49*8,14*8,"Talk To Pooping Man"))
		{
			TEXT_set_sprite_window(0,stallman3_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	static NPC* stallman4_npc = NULL;
	if(stallman4_npc==NULL)
	{
		NPC_create_random_MAN_xy_feet(&stallman4_npc,57*8,11*8);
		//NPC_create_npc_xy_feet(&stallman4_npc,SPRITE,16,40,7*8,27*8);
		stallman4_npc->non_walkable=1;
		stallman4_npc->layer=2;
		NPC_animate_stand_dir(&stallman4_npc,DOWN);
		stallman4_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		stallman4_npc->walk_dir=stallman4_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&stallman4_npc, stallman4_npc->anim_direction);
	}
	if(stallman4_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stallman4_npc,45))NPC_stare_at_npc_not_opposite_walking_direction(&stallman4_npc,&PLAYER_npc);
		else if(stallman4_npc->AI==0){if(stallman4_npc->vbls>200){if(r(4)==0){stallman4_npc->AI=1+r(3);}else{stallman4_npc->vbls=0;NPC_animate_stand_dir(&stallman4_npc, stallman4_npc->walk_dir);if(stallman4_npc->anim_frame_count!=0){stallman4_npc->anim_frame_count=3;NPC_animate(&stallman4_npc);}}}}
		else if(stallman4_npc->AI==1){if(stallman4_npc->walk_dir==UP||stallman4_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallman4_npc,LEFT);else NPC_animate_stand_dir(&stallman4_npc,UP);stallman4_npc->vbls=r(120);stallman4_npc->AI=0;}
		else if(stallman4_npc->AI==2){if(stallman4_npc->walk_dir==UP||stallman4_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallman4_npc,RIGHT);else NPC_animate_stand_dir(&stallman4_npc,DOWN);stallman4_npc->vbls=r(120);stallman4_npc->AI=0;}
		else if(stallman4_npc->AI==3){NPC_animate(&stallman4_npc);stallman4_npc->vbls=r(120);stallman4_npc->AI=0;}

		if(ACTION_range_xy_xy(57*8,13*8,59*8,14*8,"Talk To Pooping Man"))
		{
			TEXT_set_sprite_window(0,stallman4_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	if(walking_into_door(RANGE_CITYStadiumBathroomLeftMensToLobbyLeft))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumLobby,17,16);return;
	}
	if(walking_into_door(RANGE_CITYStadiumBathroomLeftMensToLobbyRight))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumLobby,90,16);return;
	}
}
void bobsgame_CITYStadiumBathroomLeftMens_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYStadiumBathroomLeftMens_Map_VBL_Function()
{

}
void bobsgame_CITYStadiumBathroomLeftMens_Map_HBL_Function()
{

}
//========================================================
//CITYStadiumBathroomRightWomens
//========================================================
void bobsgame_CITYStadiumBathroomRightWomens_Map_Load_Function()
{
//RANGE_CITYStadiumBathroomRightWomensToLobbyLeft 3*8,23*8,7*8,24*8
//RANGE_CITYStadiumBathroomRightWomensToLobbyRight 74*8,23*8,78*8,24*8
}
void bobsgame_CITYStadiumBathroomRightWomens_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//should have women go into the stalls(disappear), flush sound, reappear, sink, leave.

//4
//9
//19
//29
//39

	static NPC* stallwoman1_npc = NULL;
	if(stallwoman1_npc==NULL)
	{
		NPC_create_random_WOMAN_xy_feet(&stallwoman1_npc,4*8,11*8);
		//NPC_create_npc_xy_feet(&stallwoman1_npc,SPRITE,16,40,7*8,27*8);
		stallwoman1_npc->non_walkable=1;
		stallwoman1_npc->layer=2;
		NPC_animate_stand_dir(&stallwoman1_npc,DOWN);
		stallwoman1_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		stallwoman1_npc->walk_dir=stallwoman1_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&stallwoman1_npc, stallwoman1_npc->anim_direction);
	}
	if(stallwoman1_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stallwoman1_npc,45))NPC_stare_at_npc_not_opposite_walking_direction(&stallwoman1_npc,&PLAYER_npc);
		else if(stallwoman1_npc->AI==0){if(stallwoman1_npc->vbls>200){if(r(4)==0){stallwoman1_npc->AI=1+r(3);}else{stallwoman1_npc->vbls=0;NPC_animate_stand_dir(&stallwoman1_npc, stallwoman1_npc->walk_dir);if(stallwoman1_npc->anim_frame_count!=0){stallwoman1_npc->anim_frame_count=3;NPC_animate(&stallwoman1_npc);}}}}
		else if(stallwoman1_npc->AI==1){if(stallwoman1_npc->walk_dir==UP||stallwoman1_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallwoman1_npc,LEFT);else NPC_animate_stand_dir(&stallwoman1_npc,UP);stallwoman1_npc->vbls=r(120);stallwoman1_npc->AI=0;}
		else if(stallwoman1_npc->AI==2){if(stallwoman1_npc->walk_dir==UP||stallwoman1_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallwoman1_npc,RIGHT);else NPC_animate_stand_dir(&stallwoman1_npc,DOWN);stallwoman1_npc->vbls=r(120);stallwoman1_npc->AI=0;}
		else if(stallwoman1_npc->AI==3){NPC_animate(&stallwoman1_npc);stallwoman1_npc->vbls=r(120);stallwoman1_npc->AI=0;}

		if(ACTION_range_xy_xy(4*8,13*8,6*8,14*8,"Talk To Checking Make-Up Woman"))
		{
			TEXT_set_sprite_window(0,stallwoman1_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	static NPC* stallwoman2_npc = NULL;
	if(stallwoman2_npc==NULL)
	{
		NPC_create_random_WOMAN_xy_feet(&stallwoman2_npc,9*8,11*8);
		//NPC_create_npc_xy_feet(&stallwoman2_npc,SPRITE,16,40,7*8,27*8);
		stallwoman2_npc->non_walkable=1;
		stallwoman2_npc->layer=2;
		NPC_animate_stand_dir(&stallwoman2_npc,DOWN);
		stallwoman2_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		stallwoman2_npc->walk_dir=stallwoman2_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&stallwoman2_npc, stallwoman2_npc->anim_direction);
	}
	if(stallwoman2_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stallwoman2_npc,45))NPC_stare_at_npc_not_opposite_walking_direction(&stallwoman2_npc,&PLAYER_npc);
		else if(stallwoman2_npc->AI==0){if(stallwoman2_npc->vbls>200){if(r(4)==0){stallwoman2_npc->AI=1+r(3);}else{stallwoman2_npc->vbls=0;NPC_animate_stand_dir(&stallwoman2_npc, stallwoman2_npc->walk_dir);if(stallwoman2_npc->anim_frame_count!=0){stallwoman2_npc->anim_frame_count=3;NPC_animate(&stallwoman2_npc);}}}}
		else if(stallwoman2_npc->AI==1){if(stallwoman2_npc->walk_dir==UP||stallwoman2_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallwoman2_npc,LEFT);else NPC_animate_stand_dir(&stallwoman2_npc,UP);stallwoman2_npc->vbls=r(120);stallwoman2_npc->AI=0;}
		else if(stallwoman2_npc->AI==2){if(stallwoman2_npc->walk_dir==UP||stallwoman2_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallwoman2_npc,RIGHT);else NPC_animate_stand_dir(&stallwoman2_npc,DOWN);stallwoman2_npc->vbls=r(120);stallwoman2_npc->AI=0;}
		else if(stallwoman2_npc->AI==3){NPC_animate(&stallwoman2_npc);stallwoman2_npc->vbls=r(120);stallwoman2_npc->AI=0;}

		if(ACTION_range_xy_xy(9*8,13*8,11*8,14*8,"Talk To Be Right Back Woman"))
		{
			TEXT_set_sprite_window(0,stallwoman2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	static NPC* stallwoman3_npc = NULL;
	if(stallwoman3_npc==NULL)
	{
		NPC_create_random_WOMAN_xy_feet(&stallwoman3_npc,19*8,11*8);
		//NPC_create_npc_xy_feet(&stallwoman3_npc,SPRITE,16,40,7*8,27*8);
		stallwoman3_npc->non_walkable=1;
		stallwoman3_npc->layer=2;
		NPC_animate_stand_dir(&stallwoman3_npc,DOWN);
		stallwoman3_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		stallwoman3_npc->walk_dir=stallwoman3_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&stallwoman3_npc, stallwoman3_npc->anim_direction);
	}
	if(stallwoman3_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stallwoman3_npc,45))NPC_stare_at_npc_not_opposite_walking_direction(&stallwoman3_npc,&PLAYER_npc);
		else if(stallwoman3_npc->AI==0){if(stallwoman3_npc->vbls>200){if(r(4)==0){stallwoman3_npc->AI=1+r(3);}else{stallwoman3_npc->vbls=0;NPC_animate_stand_dir(&stallwoman3_npc, stallwoman3_npc->walk_dir);if(stallwoman3_npc->anim_frame_count!=0){stallwoman3_npc->anim_frame_count=3;NPC_animate(&stallwoman3_npc);}}}}
		else if(stallwoman3_npc->AI==1){if(stallwoman3_npc->walk_dir==UP||stallwoman3_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallwoman3_npc,LEFT);else NPC_animate_stand_dir(&stallwoman3_npc,UP);stallwoman3_npc->vbls=r(120);stallwoman3_npc->AI=0;}
		else if(stallwoman3_npc->AI==2){if(stallwoman3_npc->walk_dir==UP||stallwoman3_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallwoman3_npc,RIGHT);else NPC_animate_stand_dir(&stallwoman3_npc,DOWN);stallwoman3_npc->vbls=r(120);stallwoman3_npc->AI=0;}
		else if(stallwoman3_npc->AI==3){NPC_animate(&stallwoman3_npc);stallwoman3_npc->vbls=r(120);stallwoman3_npc->AI=0;}

		if(ACTION_range_xy_xy(19*8,13*8,21*8,14*8,"Talk To Freshening Up Woman"))
		{
			TEXT_set_sprite_window(0,stallwoman3_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	static NPC* stallwoman4_npc = NULL;
	if(stallwoman4_npc==NULL)
	{
		NPC_create_random_WOMAN_xy_feet(&stallwoman4_npc,29*8,11*8);
		//NPC_create_npc_xy_feet(&stallwoman4_npc,SPRITE,16,40,7*8,27*8);
		stallwoman4_npc->non_walkable=1;
		stallwoman4_npc->layer=2;
		NPC_animate_stand_dir(&stallwoman4_npc,DOWN);
		stallwoman4_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		stallwoman4_npc->walk_dir=stallwoman4_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&stallwoman4_npc, stallwoman4_npc->anim_direction);
	}
	if(stallwoman4_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stallwoman4_npc,45))NPC_stare_at_npc_not_opposite_walking_direction(&stallwoman4_npc,&PLAYER_npc);
		else if(stallwoman4_npc->AI==0){if(stallwoman4_npc->vbls>200){if(r(4)==0){stallwoman4_npc->AI=1+r(3);}else{stallwoman4_npc->vbls=0;NPC_animate_stand_dir(&stallwoman4_npc, stallwoman4_npc->walk_dir);if(stallwoman4_npc->anim_frame_count!=0){stallwoman4_npc->anim_frame_count=3;NPC_animate(&stallwoman4_npc);}}}}
		else if(stallwoman4_npc->AI==1){if(stallwoman4_npc->walk_dir==UP||stallwoman4_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallwoman4_npc,LEFT);else NPC_animate_stand_dir(&stallwoman4_npc,UP);stallwoman4_npc->vbls=r(120);stallwoman4_npc->AI=0;}
		else if(stallwoman4_npc->AI==2){if(stallwoman4_npc->walk_dir==UP||stallwoman4_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallwoman4_npc,RIGHT);else NPC_animate_stand_dir(&stallwoman4_npc,DOWN);stallwoman4_npc->vbls=r(120);stallwoman4_npc->AI=0;}
		else if(stallwoman4_npc->AI==3){NPC_animate(&stallwoman4_npc);stallwoman4_npc->vbls=r(120);stallwoman4_npc->AI=0;}

		if(ACTION_range_xy_xy(29*8,13*8,31*8,14*8,"Talk To Stepping Outside Woman"))
		{
			TEXT_set_sprite_window(0,stallwoman4_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	static NPC* stallwoman5_npc = NULL;
	if(stallwoman5_npc==NULL)
	{
		NPC_create_random_WOMAN_xy_feet(&stallwoman5_npc,39*8,11*8);
		//NPC_create_npc_xy_feet(&stallwoman5_npc,SPRITE,16,40,7*8,27*8);
		stallwoman5_npc->non_walkable=1;
		stallwoman5_npc->layer=2;
		NPC_animate_stand_dir(&stallwoman5_npc,DOWN);
		stallwoman5_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		stallwoman5_npc->walk_dir=stallwoman5_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&stallwoman5_npc, stallwoman5_npc->anim_direction);
	}
	if(stallwoman5_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stallwoman5_npc,45))NPC_stare_at_npc_not_opposite_walking_direction(&stallwoman5_npc,&PLAYER_npc);
		else if(stallwoman5_npc->AI==0){if(stallwoman5_npc->vbls>200){if(r(4)==0){stallwoman5_npc->AI=1+r(3);}else{stallwoman5_npc->vbls=0;NPC_animate_stand_dir(&stallwoman5_npc, stallwoman5_npc->walk_dir);if(stallwoman5_npc->anim_frame_count!=0){stallwoman5_npc->anim_frame_count=3;NPC_animate(&stallwoman5_npc);}}}}
		else if(stallwoman5_npc->AI==1){if(stallwoman5_npc->walk_dir==UP||stallwoman5_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallwoman5_npc,LEFT);else NPC_animate_stand_dir(&stallwoman5_npc,UP);stallwoman5_npc->vbls=r(120);stallwoman5_npc->AI=0;}
		else if(stallwoman5_npc->AI==2){if(stallwoman5_npc->walk_dir==UP||stallwoman5_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallwoman5_npc,RIGHT);else NPC_animate_stand_dir(&stallwoman5_npc,DOWN);stallwoman5_npc->vbls=r(120);stallwoman5_npc->AI=0;}
		else if(stallwoman5_npc->AI==3){NPC_animate(&stallwoman5_npc);stallwoman5_npc->vbls=r(120);stallwoman5_npc->AI=0;}

		if(ACTION_range_xy_xy(39*8,13*8,41*8,14*8,"Talk To Powdering Nose Woman"))
		{
			TEXT_set_sprite_window(0,stallwoman5_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	if(walking_into_door(RANGE_CITYStadiumBathroomRightWomensToLobbyLeft))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumLobby,111,16);return;
	}
	if(walking_into_door(RANGE_CITYStadiumBathroomRightWomensToLobbyRight))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumLobby,184,16);return;
	}
}
void bobsgame_CITYStadiumBathroomRightWomens_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYStadiumBathroomRightWomens_Map_VBL_Function()
{

}
void bobsgame_CITYStadiumBathroomRightWomens_Map_HBL_Function()
{

}
//========================================================
//CITYStadiumLeftHallway
//========================================================
void bobsgame_CITYStadiumLeftHallway_Map_Load_Function()
{
//RANGE_CITYStadiumLeftHallwayToMain 6*8,187*8,10*8,188*8
//RANGE_CITYStadiumLeftHallwayToBackstage 6*8,9*8,10*8,10*8
}
void bobsgame_CITYStadiumLeftHallway_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//nobody in here. nothing.

//TODO: muffled stadium sound
//echoed footsteps?

	if(walking_into_door(RANGE_CITYStadiumLeftHallwayToMain))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumMain,8,202);return;
	}
	if(walking_into_door(RANGE_CITYStadiumLeftHallwayToBackstage))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumBackstage,8,23);return;
	}
}
void bobsgame_CITYStadiumLeftHallway_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYStadiumLeftHallway_Map_VBL_Function()
{

}
void bobsgame_CITYStadiumLeftHallway_Map_HBL_Function()
{

}
//========================================================
//CITYStadiumRightHallway
//========================================================
void bobsgame_CITYStadiumRightHallway_Map_Load_Function()
{
//RANGE_CITYStadiumRightHallwayToMain 6*8,187*8,10*8,188*8
//RANGE_CITYStadiumRightHallwayToBackstage 6*8,9*8,10*8,10*8
}
void bobsgame_CITYStadiumRightHallway_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	//nobody in here either.

	//TODO: muffled stadium sound
	//echoed footsteps?

	if(walking_into_door(RANGE_CITYStadiumRightHallwayToMain))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumMain,195,202);return;
	}
	if(walking_into_door(RANGE_CITYStadiumRightHallwayToBackstage))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumBackstage,195,23);return;
	}
}
void bobsgame_CITYStadiumRightHallway_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYStadiumRightHallway_Map_VBL_Function()
{

}
void bobsgame_CITYStadiumRightHallway_Map_HBL_Function()
{

}
//========================================================
//CITYStadiumBackstage
//========================================================
void bobsgame_CITYStadiumBackstage_Map_Load_Function()
{
//RANGE_CITYStadiumBackstageToLeftHallway 6*8,24*8,10*8,25*8
//RANGE_CITYStadiumBackstageToRightHallway 193*8,24*8,197*8,25*8

//RANGE_CITYStadiumBackstageToDressingRoom 11*8,9*8,15*8,10*8
//RANGE_CITYStadiumBackstageToDressingRoom2 46*8,9*8,50*8,10*8
//RANGE_CITYStadiumBackstageToDressingRoom3 152*8,9*8,156*8,10*8
//RANGE_CITYStadiumBackstageToProducerRoom 186*8,9*8,190*8,10*8

//RANGE_CITYStadiumBackstageToStageLeft 19*8,24*8,23*8,25*8
//RANGE_CITYStadiumBackstageToStageRight 180*8,24*8,184*8,25*8

}
void bobsgame_CITYStadiumBackstage_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	//need some people with headsets or something running back and forth
	//TODO: need crew guys with headset sprites

	//20,13
	//20,23 down
	//20,13
	//182,13
	//182,23 down
	//182,13

	static NPC* crewguy1_npc = NULL;
	if(crewguy1_npc==NULL)
	{
		NPC_create_npc_xy_feet(&crewguy1_npc,GFX_ADULT_businessguy,16,40,20*8,13*8);
		//NPC_create_random_ADULT_xy_feet(&crewguy1_npc,11*8,34*8);

		crewguy1_npc->layer=2;
		crewguy1_npc->non_walkable=1;
		NPC_animate_stand_dir(&crewguy1_npc,DOWN);

		crewguy1_npc->walking_speed = SPEED_FASTEST+(r(SPEED_SLOWEST-SPEED_FAST));
		crewguy1_npc->AI=0;
	}
	if(crewguy1_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&crewguy1_npc,15))NPC_stare_at_npc(&crewguy1_npc,&PLAYER_npc);
		//else NPC_animate_set_direction_now(&crewguy1_npc, LEFT);

		else if(crewguy1_npc->AI== 0){if(NPC_walk_to_xy_nohit_pushmain(&crewguy1_npc,crewguy1_npc->walking_speed, 20*8,23*8)==1){NPC_animate_stand_dir(&crewguy1_npc,DOWN);crewguy1_npc->vbls=r(40);crewguy1_npc->AI++;}}
		else if(crewguy1_npc->AI== 1){if(crewguy1_npc->vbls>60)crewguy1_npc->AI++;}
		else if(crewguy1_npc->AI== 2){if(NPC_walk_to_xy_nohit_pushmain(&crewguy1_npc,crewguy1_npc->walking_speed, 20*8,13*8)==1){crewguy1_npc->AI++;}}
		else if(crewguy1_npc->AI== 3){if(NPC_walk_to_xy_nohit_pushmain(&crewguy1_npc,crewguy1_npc->walking_speed,182*8,13*8)==1){crewguy1_npc->AI++;}}
		else if(crewguy1_npc->AI== 4){if(NPC_walk_to_xy_nohit_pushmain(&crewguy1_npc,crewguy1_npc->walking_speed,182*8,23*8)==1){NPC_animate_stand_dir(&crewguy1_npc,DOWN);crewguy1_npc->vbls=r(40);crewguy1_npc->AI++;}}
		else if(crewguy1_npc->AI== 5){if(crewguy1_npc->vbls>60)crewguy1_npc->AI++;}
		else if(crewguy1_npc->AI== 6){if(NPC_walk_to_xy_nohit_pushmain(&crewguy1_npc,crewguy1_npc->walking_speed,182*8,13*8)==1){crewguy1_npc->AI++;}}
		else if(crewguy1_npc->AI== 7){if(NPC_walk_to_xy_nohit_pushmain(&crewguy1_npc,crewguy1_npc->walking_speed, 20*8,13*8)==1){crewguy1_npc->AI=0;}}

		if(ACTION_npc(&crewguy1_npc,"Talk To Crew Guy"))
		{
			TEXT_set_sprite_window(0,crewguy1_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	static NPC* crewguy2_npc = NULL;
	if(crewguy2_npc==NULL)
	{
		NPC_create_npc_xy_feet(&crewguy2_npc,GFX_ADULT_businessguy,16,40,184*8,16*8);
		//NPC_create_random_ADULT_xy_feet(&crewguy2_npc,11*8,34*8);

		crewguy2_npc->layer=2;
		crewguy2_npc->non_walkable=1;
		NPC_animate_stand_dir(&crewguy2_npc,DOWN);

		crewguy2_npc->walking_speed = SPEED_FASTEST+(r(SPEED_SLOWEST-SPEED_FAST));
		crewguy2_npc->AI=4;
	}
	if(crewguy2_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&crewguy2_npc,15))NPC_stare_at_npc(&crewguy2_npc,&PLAYER_npc);
		//else NPC_animate_set_direction_now(&crewguy2_npc, LEFT);

		else if(crewguy2_npc->AI== 0){if(NPC_walk_to_xy_nohit_pushmain(&crewguy2_npc,crewguy2_npc->walking_speed, 22*8,23*8)==1){NPC_animate_stand_dir(&crewguy2_npc,DOWN);crewguy2_npc->vbls=r(40);crewguy2_npc->AI++;}}
		else if(crewguy2_npc->AI== 1){if(crewguy2_npc->vbls>60)crewguy2_npc->AI++;}
		else if(crewguy2_npc->AI== 2){if(NPC_walk_to_xy_nohit_pushmain(&crewguy2_npc,crewguy2_npc->walking_speed, 22*8,16*8)==1){crewguy2_npc->AI++;}}
		else if(crewguy2_npc->AI== 3){if(NPC_walk_to_xy_nohit_pushmain(&crewguy2_npc,crewguy2_npc->walking_speed,184*8,16*8)==1){crewguy2_npc->AI++;}}
		else if(crewguy2_npc->AI== 4){if(NPC_walk_to_xy_nohit_pushmain(&crewguy2_npc,crewguy2_npc->walking_speed,184*8,23*8)==1){NPC_animate_stand_dir(&crewguy2_npc,DOWN);crewguy2_npc->vbls=r(40);crewguy2_npc->AI++;}}
		else if(crewguy2_npc->AI== 5){if(crewguy2_npc->vbls>60)crewguy2_npc->AI++;}
		else if(crewguy2_npc->AI== 6){if(NPC_walk_to_xy_nohit_pushmain(&crewguy2_npc,crewguy2_npc->walking_speed,184*8,16*8)==1){crewguy2_npc->AI++;}}
		else if(crewguy2_npc->AI== 7){if(NPC_walk_to_xy_nohit_pushmain(&crewguy2_npc,crewguy2_npc->walking_speed, 22*8,16*8)==1){crewguy2_npc->AI=0;}}

		if(ACTION_npc(&crewguy2_npc,"Talk To Crew Guy"))
		{
			TEXT_set_sprite_window(0,crewguy2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	if(walking_into_door(RANGE_CITYStadiumBackstageToLeftHallway))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumLeftHallway,8,10);return;
	}
	if(walking_into_door(RANGE_CITYStadiumBackstageToRightHallway))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumRightHallway,8,10);return;
	}
	if(walking_into_door(RANGE_CITYStadiumBackstageToDressingRoom))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumDressingRoom,5,16);return;
	}
	if(walking_into_door(RANGE_CITYStadiumBackstageToDressingRoom2))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumDressingRoom2,5,16);return;
	}
	if(walking_into_door(RANGE_CITYStadiumBackstageToDressingRoom3))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumDressingRoom3,5,16);return;
	}
	if(walking_into_door(RANGE_CITYStadiumBackstageToProducerRoom))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumProducerRoom,14,26);return;
	}

	if(walking_into_door(RANGE_CITYStadiumBackstageToStageLeft))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumMain,20,20);return;
	}
	if(walking_into_door(RANGE_CITYStadiumBackstageToStageRight))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumMain,181,20);return;
	}
}
void bobsgame_CITYStadiumBackstage_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYStadiumBackstage_Map_VBL_Function()
{

}
void bobsgame_CITYStadiumBackstage_Map_HBL_Function()
{

}
//========================================================
//CITYStadiumDressingRoom
//========================================================
void bobsgame_CITYStadiumDressingRoom_Map_Load_Function()
{
//RANGE_CITYStadiumDressingRoomToBackstage 3*8,17*8,7*8,18*8
//RANGE_CITYStadiumDressingRoomToBathroom 3*8,9*8,7*8,10*8
}
void bobsgame_CITYStadiumDressingRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	//this is your room.
	//?? in here.

	if(walking_into_door(RANGE_CITYStadiumDressingRoomToBackstage))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumBackstage,13,10);return;
	}
	if(walking_into_door(RANGE_CITYStadiumDressingRoomToBathroom))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumDressingRoomBathroom,5,16);return;
	}
}
void bobsgame_CITYStadiumDressingRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYStadiumDressingRoom_Map_VBL_Function()
{

}
void bobsgame_CITYStadiumDressingRoom_Map_HBL_Function()
{

}
//========================================================
//CITYStadiumDressingRoomBathroom
//========================================================
void bobsgame_CITYStadiumDressingRoomBathroom_Map_Load_Function()
{
//RANGE_CITYStadiumBathroomToDressingRoom 3*8,17*8,7*8,18*8
}
void bobsgame_CITYStadiumDressingRoomBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	if(walking_into_door(RANGE_CITYStadiumBathroomToDressingRoom))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumDressingRoom,5,10);return;
	}
}
void bobsgame_CITYStadiumDressingRoomBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYStadiumDressingRoomBathroom_Map_VBL_Function()
{

}
void bobsgame_CITYStadiumDressingRoomBathroom_Map_HBL_Function()
{

}
//========================================================
//CITYStadiumMain
//========================================================
void bobsgame_CITYStadiumMain_Map_Load_Function()
{
//RANGE_CITYStadiumMainToLobby1 2*8,223*8,8*8,224*8
//RANGE_CITYStadiumMainToLobby2 9*8,223*8,15*8,224*8
//RANGE_CITYStadiumMainToLobby3 94*8,223*8,101*8,224*8
//RANGE_CITYStadiumMainToLobby4 102*8,223*8,109*8,224*8
//RANGE_CITYStadiumMainToLobby5 188*8,223*8,194*8,224*8
//RANGE_CITYStadiumMainToLobby6 195*8,223*8,201*8,224*8

//RANGE_CITYStadiumMainToBackstageRight 179*8,19*8,185*8,20*8
//RANGE_CITYStadiumMainToBackstageLeft 18*8,19*8,24*8,20*8

//RANGE_CITYStadiumMainToLeftHallway 6*8,201*8,10*8,202*8
//RANGE_CITYStadiumMainToRightHallway 192*8,201*8,196*8,202*8

}
void bobsgame_CITYStadiumMain_Map_Run_Function(int MAP_just_loaded)
{

static int frame[11]={0,0,0,0,0,0,0,0,0,0,0};
static int timer[11]={0,0,0,0,0,0,0,0,0,0,0};
static int lastvbltimer = 0;
static int lastvbltimer2 = 0;

	if(MAP_just_loaded==1)
	{
		int n=0;for(n=0;n<11;n++){frame[n]=0;timer[n]=0;}
		lastvbltimer = 0;
		lastvbltimer2= 0;

	}

	//animate all the people,

//2-9, 16-17
//24
//32
//40
//48
//56
//64
//72
//80
//2-7,88
//2-5,96

	if(lastvbltimer!=vbl_5_var)
	{
		lastvbltimer=vbl_5_var;

		int c=0;
		for(c=0;c<11;c++)
		{

			if(frame[c]!=2&&timer[c]==0)
			{
				int x=0;
				int y=0;

				frame[c]=2;

				int xmax=10;
				int xstart=2;

				if(c== 0){y= 72;}
				if(c== 1){y= 80;}
				if(c== 2){y= 88;}
				if(c== 3){y= 96;}
				if(c== 4){y=104;}
				if(c== 5){y=112;}
				if(c== 6){y=120;}
				if(c== 7){y=128;}
				if(c== 8){y=136;}
				if(c== 9){y=144;xmax=8;}
				if(c==10){y=152;xmax=6;}

				for(x=xstart;x<xmax;x++)
				{
					///TODO: MUST FIX!!!
					///HARDWARE_set_tile_gfx_to_tile(1,1,HARDWARE_map_1[HARDWARE_map_width_tiles*y+x],HARDWARE_map_1[HARDWARE_map_width_tiles*(y+frame[c])+x]);
					///HARDWARE_set_tile_gfx_to_tile(1,1,HARDWARE_map_1[HARDWARE_map_width_tiles*(y+1)+x],HARDWARE_map_1[HARDWARE_map_width_tiles*(y+frame[c]+1)+x]);
				}
			}
			if(timer[c]>0)timer[c]--;
		}
	}

	if(lastvbltimer2!=vbl_5_var)
	{
		lastvbltimer2=vbl_5_var;

		int x=0;
		int y=0;

		int t=0;
		int m=r(2);

		for(t=0;t<m;t++)
		{
			int c=r(11);

			if(frame[c]==2)frame[c]=2+((1+r(2))*2);
			timer[c]=1+r(5);

			int xmax=10;
			int xstart=2;

			if(c== 0){y= 72;}
			if(c== 1){y= 80;}
			if(c== 2){y= 88;}
			if(c== 3){y= 96;}
			if(c== 4){y=104;}
			if(c== 5){y=112;}
			if(c== 6){y=120;}
			if(c== 7){y=128;}
			if(c== 8){y=136;}
			if(c== 9){y=144;xmax=8;}
			if(c==10){y=152;xmax=6;}

			xstart=2*(r(5));
			if(xmax>xstart+2)xmax=xstart+2;

			for(x=xstart;x<xmax;x++)
			{
				///TODO: MUST FIX!!!
				///HARDWARE_set_tile_gfx_to_tile(1,1,HARDWARE_map_1[HARDWARE_map_width_tiles*y+x],HARDWARE_map_1[HARDWARE_map_width_tiles*(y+frame[c])+x]);
				///HARDWARE_set_tile_gfx_to_tile(1,1,HARDWARE_map_1[HARDWARE_map_width_tiles*(y+1)+x],HARDWARE_map_1[HARDWARE_map_width_tiles*(y+frame[c]+1)+x]);
			}
		}
	}

	//need tv camera guys
	//TODO: headsets guys
	static NPC* stadiumcameraguys_npcs[6] = {NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	//for(c=0;c<6;c++)
	{
		if(stadiumcameraguys_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			GFX* gfx=NULL;

			if(c== 0){x= 28*8;y=56*8+4;dir=UP;		bgp=1;}
			if(c== 1){x= 22*8;y=56*8+4;dir=UP;		bgp=1;}
			if(c== 2){x= 28*8;y=66*8  ;dir=RIGHT;	bgp=2;}
			if(c== 3){x=176*8;y=56*8+4;dir=UP;		bgp=1;}
			if(c== 4){x=180*8;y=56*8+4;dir=UP;		bgp=1;}
			if(c== 5){x=175*8;y=67*8  ;dir=LEFT;	bgp=2;}

			if(gfx==NULL)NPC_create_random_ADULT_xy_feet(&stadiumcameraguys_npcs[c],x,y);
			else NPC_create_npc_xy_feet(&stadiumcameraguys_npcs[c],gfx,16,40,x,y);

			NPC_animate_stand_dir(&stadiumcameraguys_npcs[c], dir);
			stadiumcameraguys_npcs[c]->non_walkable=1;
			stadiumcameraguys_npcs[c]->walk_dir=dir;
			stadiumcameraguys_npcs[c]->layer=bgp;
			//NPC_animate_increment_direction_frame_now(&stadiumcameraguys_npcs[c], dir);
		}
		if(stadiumcameraguys_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stadiumcameraguys_npcs[c],15))NPC_stare_at_npc_not_opposite_walking_direction(&stadiumcameraguys_npcs[c],&PLAYER_npc);
			else if(stadiumcameraguys_npcs[c]->AI==0){if(stadiumcameraguys_npcs[c]->vbls>200){if(r(4)==0){stadiumcameraguys_npcs[c]->AI=1+r(3);}else{stadiumcameraguys_npcs[c]->vbls=0;NPC_animate_stand_dir(&stadiumcameraguys_npcs[c], stadiumcameraguys_npcs[c]->walk_dir);if(stadiumcameraguys_npcs[c]->anim_frame_count!=0){stadiumcameraguys_npcs[c]->anim_frame_count=3;NPC_animate(&stadiumcameraguys_npcs[c]);}}}}
			else if(stadiumcameraguys_npcs[c]->AI==1){if(stadiumcameraguys_npcs[c]->walk_dir==UP||stadiumcameraguys_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&stadiumcameraguys_npcs[c],LEFT);else NPC_animate_stand_dir(&stadiumcameraguys_npcs[c],UP);stadiumcameraguys_npcs[c]->vbls=r(120);stadiumcameraguys_npcs[c]->AI=0;}
			else if(stadiumcameraguys_npcs[c]->AI==2){if(stadiumcameraguys_npcs[c]->walk_dir==UP||stadiumcameraguys_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&stadiumcameraguys_npcs[c],RIGHT);else NPC_animate_stand_dir(&stadiumcameraguys_npcs[c],DOWN);stadiumcameraguys_npcs[c]->vbls=r(120);stadiumcameraguys_npcs[c]->AI=0;}
			else if(stadiumcameraguys_npcs[c]->AI==3){NPC_animate(&stadiumcameraguys_npcs[c]);stadiumcameraguys_npcs[c]->vbls=r(120);stadiumcameraguys_npcs[c]->AI=0;}

			//if(NPC_in_range_of_npc_amt(&PLAYER_npc,stadiumcameraguys_npcs[c],15))NPC_stare_at_npc(&stadiumcameraguys_npcs[c],PLAYER_npc);
			//else NPC_animate_set_direction_now(&stadiumcameraguys_npcs[c], stadiumcameraguys_npcs[c]->walking_direction);
		}
	}

	//maybe have people walking up and down the aisles.
	//TODO: headsets guys

	//184,200
	//184, 86
	//146, 86
	//146,200
	//142,200
	//142, 86
	//103, 86
	//103,200

	// 98,200
	// 98, 86
	// 60, 86
	// 60,200
	// 55,200
	// 55, 86
	// 18, 86
	// 18,200

	static NPC* stadiumcrewguys_npcs[16] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	//for(c=0;c<16;c++)
	{
		if(stadiumcrewguys_npcs[c]==NULL)
		{

			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			GFX* gfx=NULL;
			int cycle=0;

			if(c== 0){x=184*8;y= 86*8;  cycle= 0;}
			if(c== 1){x=146*8;y=198*8;  cycle= 2;}
			if(c== 2){x=142*8;y= 86*8;  cycle= 4;}
			if(c== 3){x=102*8;y=198*8;  cycle= 6;}
			if(c== 4){x= 98*8;y= 86*8;  cycle= 8;}
			if(c== 5){x= 60*8;y=198*8;	cycle=10;}
			if(c== 6){x= 56*8;y= 86*8;	cycle=12;}
			if(c== 7){x= 18*8;y=198*8;	cycle=14;}

			if(c== 8){x=184*8;y=198*8;  cycle= 1;}
			if(c== 9){x=146*8;y= 86*8;  cycle=27;}
			if(c==10){x=142*8;y=198*8;  cycle=25;}
			if(c==11){x=102*8;y= 86*8;  cycle=23;}
			if(c==12){x= 98*8;y=198*8;  cycle=21;}
			if(c==13){x= 60*8;y= 86*8;	cycle=19;}
			if(c==14){x= 56*8;y=198*8;	cycle=17;}
			if(c==15){x= 18*8;y= 86*8;	cycle=15;}

			if(gfx==NULL)NPC_create_random_ADULT_xy_feet(&stadiumcrewguys_npcs[c],x,y);
			else NPC_create_npc_xy_feet(&stadiumcrewguys_npcs[c],gfx,16,40,x,y);

			stadiumcrewguys_npcs[c]->layer=bgp;
			stadiumcrewguys_npcs[c]->non_walkable=1;
			stadiumcrewguys_npcs[c]->walking_speed = SPEED_FASTEST+(r(SPEED_SLOWEST-SPEED_FAST));
			stadiumcrewguys_npcs[c]->AI=cycle;
			NPC_animate_stand_dir(&stadiumcrewguys_npcs[c],dir);
			stadiumcrewguys_npcs[c]->walk_dir=dir;
		}
		if(stadiumcrewguys_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stadiumcrewguys_npcs[c],15))NPC_stare_at_npc(&stadiumcrewguys_npcs[c],&PLAYER_npc);
			//else NPC_animate_set_direction_now(&stadiumcrewguys_npcs[c], LEFT);

			else if(stadiumcrewguys_npcs[c]->AI== 0){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed, 184*8,198*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI== 1){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed, 146*8,198*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI== 2){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed, 146*8, 86*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI== 3){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed, 142*8, 86*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI== 4){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed, 142*8,198*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI== 5){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed, 102*8,198*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI== 6){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed, 102*8, 86*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI== 7){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed,  98*8, 86*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI== 8){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed,  98*8,198*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI== 9){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed,  60*8,198*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI==10){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed,  60*8, 86*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI==11){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed,  56*8, 86*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI==12){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed,  56*8,198*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI==13){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed,  18*8,198*8)==1){stadiumcrewguys_npcs[c]->AI++;}}

			else if(stadiumcrewguys_npcs[c]->AI==14){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed,  18*8, 86*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI==15){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed,  56*8, 86*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI==16){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed,  56*8,198*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI==17){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed,  60*8,198*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI==18){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed,  60*8, 86*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI==19){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed,  98*8, 86*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI==20){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed,  98*8,198*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI==21){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed, 102*8,198*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI==22){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed, 102*8, 86*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI==23){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed, 142*8, 86*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI==24){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed, 142*8,198*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI==25){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed, 146*8,198*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI==26){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed, 146*8, 86*8)==1){stadiumcrewguys_npcs[c]->AI++;}}
			else if(stadiumcrewguys_npcs[c]->AI==27){if(NPC_walk_to_xy_intelligenthit_pushothers(&stadiumcrewguys_npcs[c],stadiumcrewguys_npcs[c]->walking_speed, 184*8, 86*8)==1){stadiumcrewguys_npcs[c]->AI=0;}}

			if(ACTION_npc(&stadiumcrewguys_npcs[c],"Talk To Crew Guy"))
			{
				TEXT_set_sprite_window(0,stadiumcrewguys_npcs[c],NULL);
				TEXT_set_sprite_window(1,PLAYER_npc,NULL);
				TEXT_window(""
				);
			}
		}
	}

	//TODO: need magnified tournament screens.

	static int tournament_cycle=1;
	static NPC* famousguy_npc = NULL;
	static NPC* screenhead_npc = NULL;

	if(screenhead_npc!=NULL)
	{
		if(screenhead_npc->vbls>15){screenhead_npc->anim_frame_count=r(5);NPC_animate_cycle_through_frames_now(&screenhead_npc,4);screenhead_npc->vbls=r(10);}
	}

	//TODO: trigger tournament begin

	if(tournament_cycle==1)
	{
		//script richnerd guy coming out, miyamomo? friend?

		//come out from backstage 20, 19 to 20,31
		//walk to podium 93,31 down

		if(famousguy_npc==NULL)
		{

			famousguy_npc=PLAYER_npc;

			//NPC_create_npc_xy_feet(&famousguy_npc,GFX_ADULT_bob,16,40,20*8,19*8);
			//NPC_create_random_ADULT_xy_feet(&famousguy_npc,11*8,34*8);


			famousguy_npc->MAP_x = 93*8+4-16/2;
			famousguy_npc->MAP_y = 30*8-40-3;

			famousguy_npc->layer=3;
			//famousguy_npc->sprite->shadow=0;

			famousguy_npc->non_walkable=1;
			NPC_animate_stand_dir(&famousguy_npc,DOWN);

			famousguy_npc->walking_speed = SPEED_FAST;
			famousguy_npc->AI=2;
			//famousguy_npc->vbl_timer=0;
			tournament_cycle++;

			cameraman_target=famousguy_npc;
			GLOBAL_main_sprite_input_off=1;

			GLOBAL_camera_fx_bounds_off=1;
			//GLOBAL_main_sprite_standing=1;



		}
		if(famousguy_npc!=NULL)
		{
			//famousguy_npc->shadow=0;

			if(famousguy_npc->AI== 0){if(NPC_walk_to_xy_nohit(&famousguy_npc,famousguy_npc->walking_speed,20*8,30*8)==1){famousguy_npc->AI++;}}
			if(famousguy_npc->AI== 1){if(NPC_walk_to_xy_nohit(&famousguy_npc,famousguy_npc->walking_speed,93*8+4,30*8)==1){famousguy_npc->AI++;famousguy_npc->vbls=0;NPC_animate_stand_dir(&famousguy_npc,DOWN);}}
			if(famousguy_npc->AI== 2){if(famousguy_npc->vbls>120){famousguy_npc->vbls=0;famousguy_npc->AI++;tournament_cycle++;}}
		}

		//TODO: mom at 88
		//TODO: friend at 84
		//TODO: you at ?
		//TODO: japanese kid at ??

		//big screen turns on (remove tiles from layer 1?)

	}

	static NPC* screenflicker_npc=NULL;

	if(screenflicker_npc==NULL)
	{
		NPC_create_npc(&screenflicker_npc,GFX_MISC_bigscreen_scanlines,30*8,20*8,86*8,6*8);
		screenflicker_npc->alpha=64;
	}

	if(screenflicker_npc!=NULL)
	{
		if(screenflicker_npc->vbls>3){NPC_animate_cycle_through_frames_now(&screenflicker_npc,3);screenflicker_npc->vbls=0;screenflicker_npc->alpha++;if(screenflicker_npc->alpha>128)screenflicker_npc->alpha=64;}
	}

	if(tournament_cycle==2&&cameraman->MAP_y<famousguy_npc->MAP_y+64)
	{
		//gigantic head of the guy talking

		if(screenhead_npc==NULL)
		{
			NPC_create_npc_xy_feet(&screenhead_npc,GFX_MISC_bighead,64,64,98*8,14*8+2);//16*8+2);




			screenhead_npc->layer=3;
			screenhead_npc->scale=2.0f;
			screenhead_npc->alpha=127;

			///TODO: MUST FIX!
			///HARDWARE_set_fx(0,SFX_ALPHA,SFX_OBJ,SFX_BG3);
			//HARDWARE_set_fx(1,SFX_ALPHA,SFX_OBJ,SFX_BG3);
		}

		//static int focus_on_screen=1;

		//if(focus_on_screen==0)if(ACTION_range_xy_xy(86*8,27*8,116*8,29*8,"Look At Screen"))focus_on_screen=1;

		//if(NPC_in_range_of_xy_xy_direction(&PLAYER_npc,86*8,27*8,116*8,29*8,UP,0)==0)focus_on_screen=0;

		//if(focus_on_screen==1)
		{
			//101,15<-perfectly centered
			dummy_camera_target->MAP_x=101*8;
			///dummy_camera_target->MAP_y=19*8;
			dummy_camera_target->MAP_y=21*8;
			cameraman_target=dummy_camera_target;
		}
		//else{cameraman_target=PLAYER_npc;}
		tournament_cycle++;
	}

	//TODO: not let you past ropes.

//TODO: random people everywhere up and down aisles

	if(tournament_cycle==3)
	{

			int a=255;
			while(a>0)
			{
				fade_alpha=a;
				a-=20;
				if(a<0)a=0;

				whilefix();

			}

		//famousguy_npc->shadow=0;

		TEXT_set_sprite_window(0,famousguy_npc,NULL);
		TEXT_set_sprite_window(1,PLAYER_npc,NULL);
		TEXT_window("And lastly we have \"Yuu\", <DELAY1SEC>the unknown newcomer with incredible beginner's luck <DELAY1SEC>who is clearly here by some kind of mistake.<.>And now we commence <DELAY1SEC><NEXTLINE>The <DELAY>First <DELAY>Interdimensional <DELAY><NEXTLINE><GREEN>\"bob's game\"<WHITE> <DELAY>Championship."
		);
		cameraman_target=dummy_camera_target;
		tournament_cycle++;

		GLOBAL_camera_fx_bounds_off=0;
	}




	HARDWARE_play_sound("applause",64,40000,1);
	//HARDWARE_play_sound("applause",127,30000,1);
	HARDWARE_play_sound("applause",64,50000,1);

	//TODO: crazy audience screaming

	if(tournament_cycle==4&&GLOBAL_text_engine_state==0)
	{
		GLOBAL_main_sprite_input_off=0;
		cameraman_target=PLAYER_npc;
		tournament_cycle++;
	}

	if(walking_into_door(RANGE_CITYStadiumMainToLobby1))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumLobby,4,5);return;
	}
	if(walking_into_door(RANGE_CITYStadiumMainToLobby2))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumLobby,11,5);return;
	}
	if(walking_into_door(RANGE_CITYStadiumMainToLobby3))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumLobby,97,5);return;
	}
	if(walking_into_door(RANGE_CITYStadiumMainToLobby4))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumLobby,104,5);return;
	}
	if(walking_into_door(RANGE_CITYStadiumMainToLobby5))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumLobby,190,5);return;
	}
	if(walking_into_door(RANGE_CITYStadiumMainToLobby6))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumLobby,197,5);return;
	}
	if(walking_into_door(RANGE_CITYStadiumMainToBackstageRight))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumBackstage,181,23);return;
	}
	if(walking_into_door(RANGE_CITYStadiumMainToBackstageLeft))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumBackstage,20,23);return;
	}
	if(walking_into_door(RANGE_CITYStadiumMainToLeftHallway))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumLeftHallway,8,186);return;
	}
	if(walking_into_door(RANGE_CITYStadiumMainToRightHallway))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumRightHallway,8,186);return;
	}
}
void bobsgame_CITYStadiumMain_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYStadiumMain_Map_VBL_Function()
{

}
void bobsgame_CITYStadiumMain_Map_HBL_Function()
{

}

//========================================================
//CITYStadiumProducerRoom
//========================================================
void bobsgame_CITYStadiumProducerRoom_Map_Load_Function()
{
//RANGE_CITYStadiumProducerRoomToBackstage 12*8,27*8,16*8,28*8
}
void bobsgame_CITYStadiumProducerRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//need the producer in here.
//TODO: sprite fat guy with sunglasses and headset? maybe with long hair and a hat?

	static NPC* producer_npc = NULL;
	if(producer_npc==NULL)
	{
		NPC_create_npc_xy_feet(&producer_npc,GFX_ADULT_bigwig,16,40,14*8,17*8);
		producer_npc->non_walkable=1;
		producer_npc->layer=2;
		NPC_animate_stand_dir(&producer_npc,DOWN);
		producer_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		producer_npc->walk_dir=producer_npc->anim_dir;
	}
	if(producer_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&producer_npc,25))NPC_stare_at_npc_not_opposite_walking_direction(&producer_npc,&PLAYER_npc);
		else if(producer_npc->AI==0){if(producer_npc->vbls>200){if(r(4)==0){producer_npc->AI=1+r(3);}else{producer_npc->vbls=0;NPC_animate_stand_dir(&producer_npc, producer_npc->walk_dir);if(producer_npc->anim_frame_count!=0){producer_npc->anim_frame_count=3;NPC_animate(&producer_npc);}}}}
		else if(producer_npc->AI==1){if(producer_npc->walk_dir==UP||producer_npc->walk_dir==DOWN)NPC_animate_stand_dir(&producer_npc,LEFT);else NPC_animate_stand_dir(&producer_npc,UP);producer_npc->vbls=r(120);producer_npc->AI=0;}
		else if(producer_npc->AI==2){if(producer_npc->walk_dir==UP||producer_npc->walk_dir==DOWN)NPC_animate_stand_dir(&producer_npc,RIGHT);else NPC_animate_stand_dir(&producer_npc,DOWN);producer_npc->vbls=r(120);producer_npc->AI=0;}
		else if(producer_npc->AI==3){NPC_animate(&producer_npc);producer_npc->vbls=r(120);producer_npc->AI=0;}

		if(ACTION_npc(&producer_npc,"Talk To Producer"))
		{
			TEXT_set_sprite_window(0,producer_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

//TODO: need a few headset guys at
//8, 16 face left
//21, 16 face right

	static NPC* editingguy1_npc = NULL;
	if(editingguy1_npc==NULL)
	{
		NPC_create_npc_xy_feet(&editingguy1_npc,GFX_ADULT_skinnymeekcoder,16,40,8*8,16*8);
		editingguy1_npc->non_walkable=1;
		editingguy1_npc->layer=2;
		NPC_animate_stand_dir(&editingguy1_npc,LEFT);
		editingguy1_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		editingguy1_npc->walk_dir=editingguy1_npc->anim_dir;
	}
	if(editingguy1_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&editingguy1_npc,25))NPC_stare_at_npc_not_opposite_walking_direction(&editingguy1_npc,&PLAYER_npc);
		else if(editingguy1_npc->AI==0){if(editingguy1_npc->vbls>200){if(r(4)==0){editingguy1_npc->AI=1+r(3);}else{editingguy1_npc->vbls=0;NPC_animate_stand_dir(&editingguy1_npc, editingguy1_npc->walk_dir);if(editingguy1_npc->anim_frame_count!=0){editingguy1_npc->anim_frame_count=3;NPC_animate(&editingguy1_npc);}}}}
		else if(editingguy1_npc->AI==1){if(editingguy1_npc->walk_dir==UP||editingguy1_npc->walk_dir==DOWN)NPC_animate_stand_dir(&editingguy1_npc,LEFT);else NPC_animate_stand_dir(&editingguy1_npc,UP);editingguy1_npc->vbls=r(120);editingguy1_npc->AI=0;}
		else if(editingguy1_npc->AI==2){if(editingguy1_npc->walk_dir==UP||editingguy1_npc->walk_dir==DOWN)NPC_animate_stand_dir(&editingguy1_npc,RIGHT);else NPC_animate_stand_dir(&editingguy1_npc,DOWN);editingguy1_npc->vbls=r(120);editingguy1_npc->AI=0;}
		else if(editingguy1_npc->AI==3){NPC_animate(&editingguy1_npc);editingguy1_npc->vbls=r(120);editingguy1_npc->AI=0;}

		if(ACTION_npc(&editingguy1_npc,"Talk To Editing Guy"))
		{
			TEXT_set_sprite_window(0,editingguy1_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	static NPC* editingguy2_npc = NULL;
	if(editingguy2_npc==NULL)
	{
		NPC_create_npc_xy_feet(&editingguy2_npc,GFX_ADULT_fatmeekcoder,16,40,21*8,16*8);
		editingguy2_npc->non_walkable=1;
		editingguy2_npc->layer=2;
		NPC_animate_stand_dir(&editingguy2_npc,RIGHT);
		editingguy2_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		editingguy2_npc->walk_dir=editingguy2_npc->anim_dir;
	}
	if(editingguy2_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&editingguy2_npc,25))NPC_stare_at_npc_not_opposite_walking_direction(&editingguy2_npc,&PLAYER_npc);
		else if(editingguy2_npc->AI==0){if(editingguy2_npc->vbls>200){if(r(4)==0){editingguy2_npc->AI=1+r(3);}else{editingguy2_npc->vbls=0;NPC_animate_stand_dir(&editingguy2_npc, editingguy2_npc->walk_dir);if(editingguy2_npc->anim_frame_count!=0){editingguy2_npc->anim_frame_count=3;NPC_animate(&editingguy2_npc);}}}}
		else if(editingguy2_npc->AI==1){if(editingguy2_npc->walk_dir==UP||editingguy2_npc->walk_dir==DOWN)NPC_animate_stand_dir(&editingguy2_npc,LEFT);else NPC_animate_stand_dir(&editingguy2_npc,UP);editingguy2_npc->vbls=r(120);editingguy2_npc->AI=0;}
		else if(editingguy2_npc->AI==2){if(editingguy2_npc->walk_dir==UP||editingguy2_npc->walk_dir==DOWN)NPC_animate_stand_dir(&editingguy2_npc,RIGHT);else NPC_animate_stand_dir(&editingguy2_npc,DOWN);editingguy2_npc->vbls=r(120);editingguy2_npc->AI=0;}
		else if(editingguy2_npc->AI==3){NPC_animate(&editingguy2_npc);editingguy2_npc->vbls=r(120);editingguy2_npc->AI=0;}

		if(ACTION_npc(&editingguy2_npc,"Talk To Editing Guy"))
		{
			TEXT_set_sprite_window(0,editingguy2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	if(walking_into_door(RANGE_CITYStadiumProducerRoomToBackstage))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumBackstage,188,10);return;
	}
}
void bobsgame_CITYStadiumProducerRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYStadiumProducerRoom_Map_VBL_Function()
{

}
void bobsgame_CITYStadiumProducerRoom_Map_HBL_Function()
{

}
//========================================================
//CITYStadiumDressingRoom2
//========================================================
void bobsgame_CITYStadiumDressingRoom2_Map_Load_Function()
{
//RANGE_CITYStadiumDressingRoom2ToBackstage 3*8,17*8,7*8,18*8
//RANGE_CITYStadiumDressingRoom2ToBathroom 3*8,9*8,7*8,10*8
}
void bobsgame_CITYStadiumDressingRoom2_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	//this is your friends room

	if(walking_into_door(RANGE_CITYStadiumDressingRoom2ToBackstage))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumBackstage,48,10);return;
	}
	if(walking_into_door(RANGE_CITYStadiumDressingRoom2ToBathroom))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumDressingRoom2Bathroom,5,16);return;
	}
}
void bobsgame_CITYStadiumDressingRoom2_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYStadiumDressingRoom2_Map_VBL_Function()
{

}
void bobsgame_CITYStadiumDressingRoom2_Map_HBL_Function()
{

}
//========================================================
//CITYStadiumDressingRoom2Bathroom
//========================================================
void bobsgame_CITYStadiumDressingRoom2Bathroom_Map_Load_Function()
{
//RANGE_CITYStadiumDressingRoom2BathroomToDressingRoom2 3*8,17*8,7*8,18*8
}
void bobsgame_CITYStadiumDressingRoom2Bathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	if(walking_into_door(RANGE_CITYStadiumDressingRoom2BathroomToDressingRoom2))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumDressingRoom2,5,10);return;
	}
}
void bobsgame_CITYStadiumDressingRoom2Bathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYStadiumDressingRoom2Bathroom_Map_VBL_Function()
{

}
void bobsgame_CITYStadiumDressingRoom2Bathroom_Map_HBL_Function()
{

}
//========================================================
//CITYStadiumDressingRoom3
//========================================================
void bobsgame_CITYStadiumDressingRoom3_Map_Load_Function()
{
//RANGE_CITYStadiumDressingRoom3ToBackstage 3*8,17*8,7*8,18*8
//RANGE_CITYStadiumDressingRoom3ToBathroom 3*8,9*8,7*8,10*8
}
void bobsgame_CITYStadiumDressingRoom3_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	//this is the stars room, i need famous guy in here. rich nerd guy ahaha
	static NPC* famousguy_npc = NULL;
	if(famousguy_npc==NULL)
	{
		//NPC_create_random_WOMAN_xy_feet(&famousguy_npc,39*8,11*8);
		NPC_create_npc_xy_feet(&famousguy_npc,GFX_ADULT_richnerdguy,16,40,21*8,12*8+4);
		famousguy_npc->non_walkable=1;
		famousguy_npc->layer=3;
		NPC_animate_stand_dir(&famousguy_npc,UP);
		famousguy_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		famousguy_npc->walk_dir=famousguy_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&famousguy_npc, famousguy_npc->anim_direction);
	}
	if(famousguy_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&famousguy_npc,15))NPC_stare_at_npc_not_opposite_walking_direction(&famousguy_npc,&PLAYER_npc);
		else if(famousguy_npc->AI==0){if(famousguy_npc->vbls>200){if(r(4)==0){famousguy_npc->AI=1+r(3);}else{famousguy_npc->vbls=0;NPC_animate_stand_dir(&famousguy_npc, famousguy_npc->walk_dir);if(famousguy_npc->anim_frame_count!=0){famousguy_npc->anim_frame_count=3;NPC_animate(&famousguy_npc);}}}}
		else if(famousguy_npc->AI==1){if(famousguy_npc->walk_dir==UP||famousguy_npc->walk_dir==DOWN)NPC_animate_stand_dir(&famousguy_npc,LEFT);else NPC_animate_stand_dir(&famousguy_npc,UP);famousguy_npc->vbls=r(120);famousguy_npc->AI=0;}
		else if(famousguy_npc->AI==2){if(famousguy_npc->walk_dir==UP||famousguy_npc->walk_dir==DOWN)NPC_animate_stand_dir(&famousguy_npc,RIGHT);else NPC_animate_stand_dir(&famousguy_npc,DOWN);famousguy_npc->vbls=r(120);famousguy_npc->AI=0;}
		else if(famousguy_npc->AI==3){NPC_animate(&famousguy_npc);famousguy_npc->vbls=r(120);famousguy_npc->AI=0;}

		if(ACTION_npc(&famousguy_npc,"Talk To Rich Nerd Guy"))
		{
			TEXT_set_sprite_window(0,famousguy_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	//need hairdresser guy
	static NPC* assistant_npc = NULL;
	if(assistant_npc==NULL)
	{
		//NPC_create_random_WOMAN_xy_feet(&assistant_npc,39*8,11*8);
		NPC_create_npc_xy_feet(&assistant_npc,GFX_ADULT_wealthyguy,16,40,18*8,13*8);
		assistant_npc->non_walkable=1;
		assistant_npc->layer=2;
		NPC_animate_stand_dir(&assistant_npc,RIGHT);
		assistant_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		assistant_npc->walk_dir=assistant_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&assistant_npc, assistant_npc->anim_direction);
	}
	if(assistant_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&assistant_npc,15))NPC_stare_at_npc_not_opposite_walking_direction(&assistant_npc,&PLAYER_npc);
		else if(assistant_npc->AI==0){if(assistant_npc->vbls>200){if(r(4)==0){assistant_npc->AI=1+r(3);}else{assistant_npc->vbls=0;NPC_animate_stand_dir(&assistant_npc, assistant_npc->walk_dir);if(assistant_npc->anim_frame_count!=0){assistant_npc->anim_frame_count=3;NPC_animate(&assistant_npc);}}}}
		else if(assistant_npc->AI==1){if(assistant_npc->walk_dir==UP||assistant_npc->walk_dir==DOWN)NPC_animate_stand_dir(&assistant_npc,LEFT);else NPC_animate_stand_dir(&assistant_npc,UP);assistant_npc->vbls=r(120);assistant_npc->AI=0;}
		else if(assistant_npc->AI==2){if(assistant_npc->walk_dir==UP||assistant_npc->walk_dir==DOWN)NPC_animate_stand_dir(&assistant_npc,RIGHT);else NPC_animate_stand_dir(&assistant_npc,DOWN);assistant_npc->vbls=r(120);assistant_npc->AI=0;}
		else if(assistant_npc->AI==3){NPC_animate(&assistant_npc);assistant_npc->vbls=r(120);assistant_npc->AI=0;}

		if(ACTION_npc(&assistant_npc,"Talk To Assistant"))
		{
			TEXT_set_sprite_window(0,assistant_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	if(walking_into_door(RANGE_CITYStadiumDressingRoom3ToBackstage))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumBackstage,154,10);return;
	}
	if(walking_into_door(RANGE_CITYStadiumDressingRoom3ToBathroom))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumDressingRoom3Bathroom,5,16);return;
	}
}
void bobsgame_CITYStadiumDressingRoom3_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYStadiumDressingRoom3_Map_VBL_Function()
{

}
void bobsgame_CITYStadiumDressingRoom3_Map_HBL_Function()
{

}
//========================================================
//CITYStadiumDressingRoom3Bathroom
//========================================================
void bobsgame_CITYStadiumDressingRoom3Bathroom_Map_Load_Function()
{
//RANGE_CITYStadiumDressingRoom3BathroomToDressingRoom3 3*8,17*8,7*8,18*8
}
void bobsgame_CITYStadiumDressingRoom3Bathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	//TODO: famous guys ???? toilet paper or something.
	//sell it to someone??

	if(walking_into_door(RANGE_CITYStadiumDressingRoom3BathroomToDressingRoom3))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumDressingRoom3,5,10);return;
	}
}
void bobsgame_CITYStadiumDressingRoom3Bathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYStadiumDressingRoom3Bathroom_Map_VBL_Function()
{

}
void bobsgame_CITYStadiumDressingRoom3Bathroom_Map_HBL_Function()
{

}




