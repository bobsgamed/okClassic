//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================




#include "../../main.h"


#define RANGE_OUTSIDEPlaygroundToINSIDESchoolEntranceHallwayLeft 85*8,226*8,93*8,227*8
#define RANGE_OUTSIDEPlaygroundToINSIDESchoolEntranceHallwayRight 184*8,226*8,192*8,227*8
#define RANGE_OUTSIDEPlaygroundToINSIDESchoolBackHallwayLeft 181*8,72*8,189*8,73*8
#define RANGE_OUTSIDEPlaygroundToINSIDESchoolBackHallwayRight 193*8,72*8,201*8,73*8


//========================================================
//Playground
//========================================================
void bobsgame_SCHOOLPlayground_Map_Load_Function()
{
//RANGE_OUTSIDEPlaygroundToINSIDESchoolEntranceHallwayLeft 85*8,226*8,93*8,227*8
//RANGE_OUTSIDEPlaygroundToINSIDESchoolEntranceHallwayRight 184*8,226*8,192*8,227*8
//RANGE_OUTSIDEPlaygroundToINSIDESchoolBackHallwayLeft 181*8,72*8,189*8,73*8
//RANGE_OUTSIDEPlaygroundToINSIDESchoolBackHallwayRight 193*8,72*8,201*8,73*8
}

void bobsgame_SCHOOLPlayground_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//basketball court
//250 45 ref face down throw ball?
//246,48 face right
//244,45
//244,52
//254,48 face left
//256,45
//256,52
//234,48 face left free throw
//267,48 face right free throw
//ref guy throws ball up, comes down
//guys jump in, guy grabs ball
//runs right to free throw, other guys chase, face him, his guys get in front of those guys
//jumps, ball to hoop, bounces back, guy grabs it
//repeat for other side
//TODO: free throw game
	static NPC* bball_npcs[10] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<10;c++)
	{
		if(bball_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			if(c==0){x=246*8;y=47*8;dir=RIGHT;}
			if(c==1){x=244*8;y=41*8;dir=RIGHT;}
			if(c==2){x=244*8;y=44*8;dir=RIGHT;}
			if(c==3){x=244*8;y=51*8;dir=RIGHT;}
			if(c==4){x=244*8;y=54*8;dir=RIGHT;}
			if(c==5){x=254*8;y=47*8;dir=LEFT;}
			if(c==6){x=256*8;y=41*8;dir=LEFT;}
			if(c==7){x=256*8;y=44*8;dir=LEFT;}
			if(c==8){x=256*8;y=51*8;dir=LEFT;}
			if(c==9){x=256*8;y=54*8;dir=LEFT;}
			NPC_create_random_LITTLE_CHILD_xy_feet(&bball_npcs[c],x,(y)+3);
			NPC_animate_stand_dir(&bball_npcs[c], dir);
			bball_npcs[c]->non_walkable=1;
			//bball_npcs[c]->pushable=1;
			bball_npcs[c]->walk_dir=dir;
			bball_npcs[c]->layer=bgp;
			bball_npcs[c]->walking_speed=SPEED_FAST;//+(r(SPEED_SLOW-SPEED_FAST));
		}
		if(bball_npcs[c]!=NULL)
		{
			if(c==0&&bball_npcs[c]->AI==0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bball_npcs[c],SPEED_FAST,267*8,47*8)==(1)){bball_npcs[c]->AI++;bball_npcs[c]->vbls=0;NPC_animate_stand_dir(&bball_npcs[c],RIGHT);{bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}}//throw ball at right hoop, bounces off, other team grabs it
			if(c==0&&bball_npcs[c]->AI==1){if(bball_npcs[5]->AI==2)bball_npcs[c]->AI++;}//if(bball_npcs[c]->walking_direction==UP)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,46*8+6)){bball_npcs[c]->walking_direction=DOWN;bball_npcs[c]->vbl_timer=0;}if(bball_npcs[c]->walking_direction==DOWN)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,48*8-6)){bball_npcs[c]->walking_direction=UP;bball_npcs[c]->vbl_timer=0;}if(NPC_should_animate(&bball_npcs[c]))NPC_animate_increment_direction_frame_now(&bball_npcs[c],RIGHT);}
			if(c==0&&bball_npcs[c]->AI==2)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bball_npcs[c],SPEED_FAST,232*8,47*8)==(1)){bball_npcs[c]->AI++;bball_npcs[c]->vbls=0;NPC_animate_stand_dir(&bball_npcs[c],RIGHT);{bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}}
			if(c==0&&bball_npcs[c]->AI==3){if(bball_npcs[c]->vbls>200)bball_npcs[c]->AI=0;if(bball_npcs[c]->walk_dir==UP)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,46*8+6)){bball_npcs[c]->walk_dir=DOWN;}if(bball_npcs[c]->walk_dir==DOWN)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,48*8-6)){bball_npcs[c]->walk_dir=UP;}if(NPC_should_animate(&bball_npcs[c]))NPC_animate_dir(&bball_npcs[c],RIGHT);}
			if(c==1&&bball_npcs[c]->AI==0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bball_npcs[c],SPEED_FAST,263*8,39*8)==(1)){bball_npcs[c]->AI++;bball_npcs[c]->vbls=0;NPC_animate_stand_dir(&bball_npcs[c],RIGHT);{bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}}//throw ball at right hoop, bounces off, other team grabs it
			if(c==1&&bball_npcs[c]->AI==1){if(bball_npcs[0]->AI==2)bball_npcs[c]->AI++;if(bball_npcs[c]->walk_dir==UP)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,38*8+6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}if(bball_npcs[c]->walk_dir==DOWN)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,40*8-6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}if(NPC_should_animate(&bball_npcs[c]))NPC_animate_dir(&bball_npcs[c],RIGHT);}
			if(c==1&&bball_npcs[c]->AI==2)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bball_npcs[c],SPEED_FAST,236*8,39*8)==(1)){bball_npcs[c]->AI++;bball_npcs[c]->vbls=0;NPC_animate_stand_dir(&bball_npcs[c],RIGHT);{bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}}
			if(c==1&&bball_npcs[c]->AI==3){if(bball_npcs[0]->AI==0)bball_npcs[c]->AI=0;if(bball_npcs[c]->walk_dir==UP)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,38*8+6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}if(bball_npcs[c]->walk_dir==DOWN)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,40*8-6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}if(NPC_should_animate(&bball_npcs[c]))NPC_animate_dir(&bball_npcs[c],RIGHT);}
			if(c==2&&bball_npcs[c]->AI==0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bball_npcs[c],SPEED_FAST,259*8,44*8)==(1)){bball_npcs[c]->AI++;bball_npcs[c]->vbls=0;NPC_animate_stand_dir(&bball_npcs[c],RIGHT);{bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}}//throw ball at right hoop, bounces off, other team grabs it
			if(c==2&&bball_npcs[c]->AI==1){if(bball_npcs[0]->AI==2)bball_npcs[c]->AI++;if(bball_npcs[c]->walk_dir==UP)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,43*8+6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}if(bball_npcs[c]->walk_dir==DOWN)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,45*8-6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}if(NPC_should_animate(&bball_npcs[c]))NPC_animate_dir(&bball_npcs[c],RIGHT);}
			if(c==2&&bball_npcs[c]->AI==2)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bball_npcs[c],SPEED_FAST,240*8,44*8)==(1)){bball_npcs[c]->AI++;bball_npcs[c]->vbls=0;NPC_animate_stand_dir(&bball_npcs[c],RIGHT);{bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}}
			if(c==2&&bball_npcs[c]->AI==3){if(bball_npcs[0]->AI==0)bball_npcs[c]->AI=0;if(bball_npcs[c]->walk_dir==UP)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,43*8+6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}if(bball_npcs[c]->walk_dir==DOWN)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,45*8-6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}if(NPC_should_animate(&bball_npcs[c]))NPC_animate_dir(&bball_npcs[c],RIGHT);}
			if(c==3&&bball_npcs[c]->AI==0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bball_npcs[c],SPEED_FAST,259*8,51*8)==(1)){bball_npcs[c]->AI++;bball_npcs[c]->vbls=0;NPC_animate_stand_dir(&bball_npcs[c],RIGHT);{bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}}//throw ball at right hoop, bounces off, other team grabs it
			if(c==3&&bball_npcs[c]->AI==1){if(bball_npcs[0]->AI==2)bball_npcs[c]->AI++;if(bball_npcs[c]->walk_dir==UP)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,50*8+6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}if(bball_npcs[c]->walk_dir==DOWN)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,52*8-6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}if(NPC_should_animate(&bball_npcs[c]))NPC_animate_dir(&bball_npcs[c],RIGHT);}
			if(c==3&&bball_npcs[c]->AI==2)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bball_npcs[c],SPEED_FAST,240*8,51*8)==(1)){bball_npcs[c]->AI++;bball_npcs[c]->vbls=0;NPC_animate_stand_dir(&bball_npcs[c],RIGHT);{bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}}
			if(c==3&&bball_npcs[c]->AI==3){if(bball_npcs[0]->AI==0)bball_npcs[c]->AI=0;if(bball_npcs[c]->walk_dir==UP)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,50*8+6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}if(bball_npcs[c]->walk_dir==DOWN)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,52*8-6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}if(NPC_should_animate(&bball_npcs[c]))NPC_animate_dir(&bball_npcs[c],RIGHT);}
			if(c==4&&bball_npcs[c]->AI==0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bball_npcs[c],SPEED_FAST,263*8,56*8)==(1)){bball_npcs[c]->AI++;bball_npcs[c]->vbls=0;NPC_animate_stand_dir(&bball_npcs[c],RIGHT);{bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}}//throw ball at right hoop, bounces off, other team grabs it
			if(c==4&&bball_npcs[c]->AI==1){if(bball_npcs[0]->AI==2)bball_npcs[c]->AI++;if(bball_npcs[c]->walk_dir==UP)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,55*8+6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}if(bball_npcs[c]->walk_dir==DOWN)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,57*8-6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}if(NPC_should_animate(&bball_npcs[c]))NPC_animate_dir(&bball_npcs[c],RIGHT);}
			if(c==4&&bball_npcs[c]->AI==2)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bball_npcs[c],SPEED_FAST,236*8,56*8)==(1)){bball_npcs[c]->AI++;bball_npcs[c]->vbls=0;NPC_animate_stand_dir(&bball_npcs[c],RIGHT);{bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}}
			if(c==4&&bball_npcs[c]->AI==3){if(bball_npcs[0]->AI==0)bball_npcs[c]->AI=0;if(bball_npcs[c]->walk_dir==UP)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,55*8+6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}if(bball_npcs[c]->walk_dir==DOWN)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,57*8-6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}if(NPC_should_animate(&bball_npcs[c]))NPC_animate_dir(&bball_npcs[c],RIGHT);}
			if(c==5&&bball_npcs[c]->AI==0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bball_npcs[c],SPEED_FAST,269*8,47*8)==(1)){bball_npcs[c]->AI++;bball_npcs[c]->vbls=0;NPC_animate_stand_dir(&bball_npcs[c],LEFT);{bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}}
			if(c==5&&bball_npcs[c]->AI==1){if(bball_npcs[c]->vbls>200)bball_npcs[c]->AI++;if(bball_npcs[c]->walk_dir==UP)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,46*8+6)){bball_npcs[c]->walk_dir=DOWN;}if(bball_npcs[c]->walk_dir==DOWN)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,48*8-6)){bball_npcs[c]->walk_dir=UP;}if(NPC_should_animate(&bball_npcs[c]))NPC_animate_dir(&bball_npcs[c],LEFT);}
			if(c==5&&bball_npcs[c]->AI==2)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bball_npcs[c],SPEED_FAST,234*8,47*8)==(1)){bball_npcs[c]->AI++;bball_npcs[c]->vbls=0;NPC_animate_stand_dir(&bball_npcs[c],LEFT);{bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}}//throw ball at left hoop, bounces off, other team grabs it
			if(c==5&&bball_npcs[c]->AI==3){if(bball_npcs[0]->AI==0)bball_npcs[c]->AI=0;}//if(bball_npcs[c]->walking_direction==UP)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,46*8+6)){bball_npcs[c]->walking_direction=DOWN;bball_npcs[c]->vbl_timer=0;}if(bball_npcs[c]->walking_direction==DOWN)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,48*8-6)){bball_npcs[c]->walking_direction=UP;bball_npcs[c]->vbl_timer=0;}if(NPC_should_animate(&bball_npcs[c]))NPC_animate_increment_direction_frame_now(&bball_npcs[c],LEFT);}
			if(c==6&&bball_npcs[c]->AI==0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bball_npcs[c],SPEED_FAST,265*8,39*8)==(1)){bball_npcs[c]->AI++;bball_npcs[c]->vbls=0;NPC_animate_stand_dir(&bball_npcs[c],LEFT);{bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}}
			if(c==6&&bball_npcs[c]->AI==1){if(bball_npcs[5]->AI==2)bball_npcs[c]->AI++;if(bball_npcs[c]->walk_dir==UP)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,38*8+6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}if(bball_npcs[c]->walk_dir==DOWN)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,40*8-6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}if(NPC_should_animate(&bball_npcs[c]))NPC_animate_dir(&bball_npcs[c],LEFT);}
			if(c==6&&bball_npcs[c]->AI==2)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bball_npcs[c],SPEED_FAST,238*8,39*8)==(1)){bball_npcs[c]->AI++;bball_npcs[c]->vbls=0;NPC_animate_stand_dir(&bball_npcs[c],LEFT);{bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}}//throw ball at left hoop, bounces off, other team grabs it
			if(c==6&&bball_npcs[c]->AI==3){if(bball_npcs[5]->AI==0)bball_npcs[c]->AI=0;if(bball_npcs[c]->walk_dir==UP)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,38*8+6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}if(bball_npcs[c]->walk_dir==DOWN)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,40*8-6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}if(NPC_should_animate(&bball_npcs[c]))NPC_animate_dir(&bball_npcs[c],LEFT);}
			if(c==7&&bball_npcs[c]->AI==0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bball_npcs[c],SPEED_FAST,261*8,44*8)==(1)){bball_npcs[c]->AI++;bball_npcs[c]->vbls=0;NPC_animate_stand_dir(&bball_npcs[c],LEFT);{bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}}
			if(c==7&&bball_npcs[c]->AI==1){if(bball_npcs[5]->AI==2)bball_npcs[c]->AI++;if(bball_npcs[c]->walk_dir==UP)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,43*8+6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}if(bball_npcs[c]->walk_dir==DOWN)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,45*8-6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}if(NPC_should_animate(&bball_npcs[c]))NPC_animate_dir(&bball_npcs[c],LEFT);}
			if(c==7&&bball_npcs[c]->AI==2)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bball_npcs[c],SPEED_FAST,242*8,44*8)==(1)){bball_npcs[c]->AI++;bball_npcs[c]->vbls=0;NPC_animate_stand_dir(&bball_npcs[c],LEFT);{bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}}//throw ball at left hoop, bounces off, other team grabs it
			if(c==7&&bball_npcs[c]->AI==3){if(bball_npcs[5]->AI==0)bball_npcs[c]->AI=0;if(bball_npcs[c]->walk_dir==UP)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,43*8+6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}if(bball_npcs[c]->walk_dir==DOWN)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,45*8-6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}if(NPC_should_animate(&bball_npcs[c]))NPC_animate_dir(&bball_npcs[c],LEFT);}
			if(c==8&&bball_npcs[c]->AI==0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bball_npcs[c],SPEED_FAST,261*8,51*8)==(1)){bball_npcs[c]->AI++;bball_npcs[c]->vbls=0;NPC_animate_stand_dir(&bball_npcs[c],LEFT);{bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}}
			if(c==8&&bball_npcs[c]->AI==1){if(bball_npcs[5]->AI==2)bball_npcs[c]->AI++;if(bball_npcs[c]->walk_dir==UP)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,50*8+6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}if(bball_npcs[c]->walk_dir==DOWN)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,52*8-6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}if(NPC_should_animate(&bball_npcs[c]))NPC_animate_dir(&bball_npcs[c],LEFT);}
			if(c==8&&bball_npcs[c]->AI==2)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bball_npcs[c],SPEED_FAST,242*8,51*8)==(1)){bball_npcs[c]->AI++;bball_npcs[c]->vbls=0;NPC_animate_stand_dir(&bball_npcs[c],LEFT);{bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}}//throw ball at left hoop, bounces off, other team grabs it
			if(c==8&&bball_npcs[c]->AI==3){if(bball_npcs[5]->AI==0)bball_npcs[c]->AI=0;if(bball_npcs[c]->walk_dir==UP)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,50*8+6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}if(bball_npcs[c]->walk_dir==DOWN)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,52*8-6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}if(NPC_should_animate(&bball_npcs[c]))NPC_animate_dir(&bball_npcs[c],LEFT);}
			if(c==9&&bball_npcs[c]->AI==0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bball_npcs[c],SPEED_FAST,265*8,56*8)==(1)){bball_npcs[c]->AI++;bball_npcs[c]->vbls=0;NPC_animate_stand_dir(&bball_npcs[c],LEFT);{bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}}
			if(c==9&&bball_npcs[c]->AI==1){if(bball_npcs[5]->AI==2)bball_npcs[c]->AI++;if(bball_npcs[c]->walk_dir==UP)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,55*8+6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}if(bball_npcs[c]->walk_dir==DOWN)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,57*8-6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}if(NPC_should_animate(&bball_npcs[c]))NPC_animate_dir(&bball_npcs[c],LEFT);}
			if(c==9&&bball_npcs[c]->AI==2)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&bball_npcs[c],SPEED_FAST,238*8,56*8)==(1)){bball_npcs[c]->AI++;bball_npcs[c]->vbls=0;NPC_animate_stand_dir(&bball_npcs[c],LEFT);{bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}}//throw ball at left hoop, bounces off, other team grabs it
			if(c==9&&bball_npcs[c]->AI==3){if(bball_npcs[5]->AI==0)bball_npcs[c]->AI=0;if(bball_npcs[c]->walk_dir==UP)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,55*8+6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=DOWN;bball_npcs[c]->vbls=0;}if(bball_npcs[c]->walk_dir==DOWN)if(NPC_move_to_xy_nohit_noanim(&bball_npcs[c],SPEED_SLOWEST*2,bball_npcs[c]->MAP_x+8,57*8-6)&&bball_npcs[c]->vbls>20){bball_npcs[c]->walk_dir=UP;bball_npcs[c]->vbls=0;}if(NPC_should_animate(&bball_npcs[c]))NPC_animate_dir(&bball_npcs[c],LEFT);}
			//TODO: need basketball
			//TODO: maybe opposite team jersey sprites
		}
	}

//kid in pipe 177,42
	static NPC* pipe_npc = NULL;
	if(pipe_npc==NULL)
	{
		NPC_create_npc_xy_feet(&pipe_npc,GFX_KID_GENERICboy3,16,32,178*8,42*8);
		pipe_npc->non_walkable=1;
		//pipe_npc->pushable=1;
		pipe_npc->layer=2;
		NPC_animate_stand_dir(&pipe_npc,DOWN);
	}
	else if(pipe_npc!=NULL)
	{
		if(NPC_in_range_of_npc(&PLAYER_npc,&pipe_npc))NPC_stare_at_npc(&pipe_npc,&PLAYER_npc);
		//else NPC_animate_set_direction_now(&pipe_npc,DOWN);
		if(ACTION_npc(&pipe_npc,"Talk To Tube Kid"))
		{
			TEXT_set_sprite_window(0,pipe_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
//hill 191,38
	static NPC* hill_npc = NULL;
	if(hill_npc==NULL)
	{
		NPC_create_npc_xy_feet(&hill_npc,GFX_KID_GENERICboy2,16,32,191*8,38*8);
		hill_npc->non_walkable=1;
		hill_npc->pushable=1;
		hill_npc->layer=2;
		NPC_animate_stand_dir(&hill_npc,DOWN);
	}
	else if(hill_npc!=NULL)
	{
		if(NPC_in_range_of_npc(&PLAYER_npc,&hill_npc))NPC_stare_at_npc(&hill_npc,&PLAYER_npc);
		//else NPC_animate_set_direction_now(&hill_npc,DOWN);
		if(ACTION_npc(&hill_npc,"Talk To King Of The Hill"))
		{
			TEXT_set_sprite_window(0,hill_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	//TODO: try to push him off the hill, walks back up slowly.
//pullup bar 157,53 over 1 face down
//maybe have kid doing pullups
//"how did you get up there?"
//TODO:maybe if walk underneath.. gum in hair?
	static NPC* pullup_npc = NULL;
	if(pullup_npc==NULL)
	{
		NPC_create_npc_xy_feet(&pullup_npc,GFX_KID_GENERICboy2,16,32,157*8,53*8);
		//pullup_npc->non_walkable=1;
		//pullup_npc->pushable=1;
		pullup_npc->layer=1;
		NPC_animate_stand_dir(&pullup_npc,DOWN);
	}
	else if(pullup_npc!=NULL)
	{
	//TODO: animate swinging legs
		//if(NPC_in_range_of_npc(&PLAYER_npc,pullup_npc))NPC_stare_at_npc(&pullup_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&pullup_npc,DOWN);
		if(ACTION_npc(&pullup_npc,"Talk To Pull-Up Bar Kid"))
		{
			TEXT_set_sprite_window(0,pullup_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
//swings 123,44 down
//128,44 down
//136,44 down
//141,44 down
//149.44 down
//154,44 down
//TODO: animate kids up and down, remove/add chain tiles, maybe animate feet out/in
//TODO: have swing game
//TODO: get hit by kids swinging?
	static NPC* swingkid1_npc = NULL;
	if(swingkid1_npc==NULL)
	{
		NPC_create_npc_xy_feet(&swingkid1_npc,GFX_KID_GENERICboy2,16,32,123*8+4,44*8);
		swingkid1_npc->non_walkable=1;
		//swingkid1_npc->pushable=1;
		swingkid1_npc->layer=1;
		NPC_animate_stand_dir(&swingkid1_npc,DOWN);
	}
	else if(swingkid1_npc!=NULL)
	{
		//if(NPC_in_range_of_npc(&PLAYER_npc,swingkid1_npc))NPC_stare_at_npc(&swingkid1_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&swingkid1_npc,DOWN);
		if(ACTION_npc(&swingkid1_npc,"Talk To Swing Kid"))
		{
			TEXT_set_sprite_window(0,swingkid1_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
//seesaw 84,46 up
//84,37 face down over 1
//seesaw 86,47 down
//76,55 over 1 face up
//seesaw 118,59 face left over 1
//107,54 face right over 1
//TODO: seesaw animation?
//TODO: seesaw minigame? get fat kid to make you fly in the air?
	static NPC* seesawkid1_npc = NULL;
	if(seesawkid1_npc==NULL)
	{
		NPC_create_npc_xy_feet(&seesawkid1_npc,GFX_KID_GENERICboy2,16,32,84*8+4,46*8);
		seesawkid1_npc->non_walkable=1;
		//seesawkid1_npc->pushable=1;
		seesawkid1_npc->layer=2;
		NPC_animate_stand_dir(&seesawkid1_npc,UP);
	}
	else if(seesawkid1_npc!=NULL)
	{
		//if(NPC_in_range_of_npc(&PLAYER_npc,seesawkid1_npc))NPC_stare_at_npc(&seesawkid1_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&seesawkid1_npc,DOWN);
		if(ACTION_npc(&seesawkid1_npc,"Talk To See-Saw Kid"))
		{
			TEXT_set_sprite_window(0,seesawkid1_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	static NPC* seesawkid2_npc = NULL;
	if(seesawkid2_npc==NULL)
	{
		NPC_create_npc_xy_feet(&seesawkid2_npc,GFX_KID_GENERICboy2,16,32,84*8+4,37*8);
		seesawkid2_npc->non_walkable=1;
		//seesawkid2_npc->pushable=1;
		seesawkid2_npc->layer=1;
		NPC_animate_stand_dir(&seesawkid2_npc,DOWN);
	}
	else if(seesawkid2_npc!=NULL)
	{
		//if(NPC_in_range_of_npc(&PLAYER_npc,seesawkid2_npc))NPC_stare_at_npc(&seesawkid2_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&seesawkid2_npc,DOWN);
		if(ACTION_npc(&seesawkid2_npc,"Talk To See-Saw Kid"))
		{
			TEXT_set_sprite_window(0,seesawkid2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
//tire swing kid 37,44 face down
	static NPC* tireswing_npc = NULL;
	if(tireswing_npc==NULL)
	{
		NPC_create_npc_xy_feet(&tireswing_npc,GFX_KID_GENERIClittleboy2,16,32,37*8+4,42*8);
		tireswing_npc->non_walkable=1;
		//tireswing_npc->pushable=1;
		tireswing_npc->layer=1;
		NPC_animate_stand_dir(&tireswing_npc,DOWN);
	}
	else if(tireswing_npc!=NULL)
	{
		//if(NPC_in_range_of_npc(&PLAYER_npc,tireswing_npc))NPC_stare_at_npc(&tireswing_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&tireswing_npc,DOWN);
		if(ACTION_npc(&tireswing_npc,"Talk To Tire Swing Kid"))
		{
			TEXT_set_sprite_window(0,tireswing_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
//bouncy turtle kid 46,50 over 1 face left
	static NPC* bouncyturtle_npc = NULL;
	if(bouncyturtle_npc==NULL)
	{
		NPC_create_npc_xy_feet(&bouncyturtle_npc,GFX_KID_GENERIClittleboy2,16,32,47*8,49*8);
		bouncyturtle_npc->non_walkable=1;
		//bouncyturtle_npc->pushable=1;
		bouncyturtle_npc->layer=1;
		NPC_animate_stand_dir(&bouncyturtle_npc,LEFT);
	}
	else if(bouncyturtle_npc!=NULL)
	{
		//if(NPC_in_range_of_npc(&PLAYER_npc,bouncyturtle_npc))NPC_stare_at_npc(&bouncyturtle_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&bouncyturtle_npc,DOWN);
		if(ACTION_npc(&bouncyturtle_npc,"Talk To Bouncy Turtle Kid"))
		{
			TEXT_set_sprite_window(0,bouncyturtle_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	//TODO: sprite rotation? animation?
	//maybe make this into a back and forth minigame?
	//go flying into something? break it off? something underneath it?
//sandbox 25,61 to 61,80
	static NPC* sandbox_npcs[15] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	c=0;
	for(c=0;c<12;c++)
	{
		if(sandbox_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			if(c== 0){x=27*8;y=64*8;dir=RIGHT;}
			if(c== 1){x=35*8;y=70*8;dir=RIGHT;}
			if(c== 2){x=46*8;y=75*8;dir=RIGHT;}
			if(c== 3){x=54*8;y=78*8;dir=RIGHT;}
			if(c== 4){x=28*8;y=66*8;dir=LEFT;}
			if(c== 5){x=37*8;y=68*8;dir=DOWN;}
			if(c== 6){x=43*8;y=73*8;dir=UP;}
			if(c== 7){x=52*8;y=77*8;dir=UP;}
			if(c== 8){x=30*8;y=68*8;dir=UP;}
			if(c== 9){x=40*8;y=72*8;dir=UP;}
			if(c==10){x=50*8;y=74*8;dir=UP;}
			if(c==11){x=59*8;y=76*8;dir=UP;}
			NPC_create_random_LITTLE_CHILD_xy_feet(&sandbox_npcs[c],x,(y)+3);
			NPC_animate_stand_dir(&sandbox_npcs[c], dir);
			sandbox_npcs[c]->non_walkable=1;
			//sandbox_npcs[c]->pushable=1;
			sandbox_npcs[c]->walk_dir=dir;
			sandbox_npcs[c]->layer=bgp;
		}
		if(sandbox_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&sandbox_npcs[c],10))NPC_stare_at_npc(&sandbox_npcs[c],&PLAYER_npc);
			else //NPC_animate_set_direction_now(&sandbox_npcs[c], sandbox_npcs[c]->walking_direction);
			NPC_walk_randomly_within_xy_xy(&sandbox_npcs[c], 25*8,61*8,61*8,80*8);
		}
	}
//monkeybar kids 49,95 to 25,95 left, to 25,115 down
//TODO: need monkeybar kids animation
	static NPC* monkeybar_npc = NULL;
	if(monkeybar_npc==NULL)
	{
		NPC_create_npc_xy_feet(&monkeybar_npc,GFX_KID_GENERICboy2,16,32,49*8,95*8);
		//monkeybar_npc->non_walkable=1;
		//monkeybar_npc->pushable=1;
		monkeybar_npc->layer=2;
		NPC_animate_stand_dir(&monkeybar_npc,LEFT);
		monkeybar_npc->always_on_top=1;
	}
	else if(monkeybar_npc!=NULL)
	{
		if(monkeybar_npc->AI== 0)if(NPC_move_to_xy_nohit_noanim(&monkeybar_npc,SPEED_FAST,48*8,93*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;monkeybar_npc->always_on_top=1;NPC_animate_stand_dir(&monkeybar_npc,LEFT);}
		if(monkeybar_npc->AI== 1)if(monkeybar_npc->vbls>10)monkeybar_npc->AI++;
		if(monkeybar_npc->AI== 2)if(NPC_move_to_xy_nohit_noanim(&monkeybar_npc,SPEED_SLOWEST,46*8+4,93*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;}
		if(monkeybar_npc->AI== 3)if(monkeybar_npc->vbls>10)monkeybar_npc->AI++;
		if(monkeybar_npc->AI== 4)if(NPC_move_to_xy_nohit_noanim(&monkeybar_npc,SPEED_SLOWEST,44*8+4,93*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;}
		if(monkeybar_npc->AI== 5)if(monkeybar_npc->vbls>10)monkeybar_npc->AI++;
		if(monkeybar_npc->AI== 6)if(NPC_move_to_xy_nohit_noanim(&monkeybar_npc,SPEED_SLOWEST,42*8+4,93*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;}
		if(monkeybar_npc->AI== 7)if(monkeybar_npc->vbls>10)monkeybar_npc->AI++;
		if(monkeybar_npc->AI== 8)if(NPC_move_to_xy_nohit_noanim(&monkeybar_npc,SPEED_SLOWEST,40*8+4,93*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;}
		if(monkeybar_npc->AI== 9)if(monkeybar_npc->vbls>10)monkeybar_npc->AI++;
		if(monkeybar_npc->AI==10)if(NPC_move_to_xy_nohit_noanim(&monkeybar_npc,SPEED_SLOWEST,38*8+4,93*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;}
		if(monkeybar_npc->AI==11)if(monkeybar_npc->vbls>10)monkeybar_npc->AI++;
		if(monkeybar_npc->AI==12)if(NPC_move_to_xy_nohit_noanim(&monkeybar_npc,SPEED_SLOWEST,36*8+4,93*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;}
		if(monkeybar_npc->AI==13)if(monkeybar_npc->vbls>10)monkeybar_npc->AI++;
		if(monkeybar_npc->AI==14)if(NPC_move_to_xy_nohit_noanim(&monkeybar_npc,SPEED_SLOWEST,34*8+4,93*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;}
		if(monkeybar_npc->AI==15)if(monkeybar_npc->vbls>10)monkeybar_npc->AI++;
		if(monkeybar_npc->AI==16)if(NPC_move_to_xy_nohit_noanim(&monkeybar_npc,SPEED_SLOWEST,32*8+4,93*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;}
		if(monkeybar_npc->AI==17)if(monkeybar_npc->vbls>10)monkeybar_npc->AI++;
		if(monkeybar_npc->AI==18)if(NPC_move_to_xy_nohit_noanim(&monkeybar_npc,SPEED_SLOWEST,30*8+4,93*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;}
		if(monkeybar_npc->AI==19)if(monkeybar_npc->vbls>10)monkeybar_npc->AI++;
		if(monkeybar_npc->AI==20)if(NPC_move_to_xy_nohit_noanim(&monkeybar_npc,SPEED_SLOWEST,28*8+4,93*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;}
		if(monkeybar_npc->AI==21)if(NPC_move_to_xy_nohit_noanim(&monkeybar_npc,SPEED_FAST	,28*8+4,96*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;}
		if(monkeybar_npc->AI==22)if(NPC_move_to_xy_nohit_noanim(&monkeybar_npc,SPEED_SLOWEST,25*8+4,96*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;NPC_animate_stand_dir(&monkeybar_npc,DOWN);}
		if(monkeybar_npc->AI==23)if(NPC_move_to_xy_nohit_noanim(&monkeybar_npc,SPEED_FAST	,25*8+4,94*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;}
		if(monkeybar_npc->AI==24)if(monkeybar_npc->vbls>10)monkeybar_npc->AI++;
		if(monkeybar_npc->AI==25)if(NPC_move_to_xy_nohit_noanim(&monkeybar_npc,SPEED_SLOWEST,25*8+4,96*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;}
		if(monkeybar_npc->AI==26)if(monkeybar_npc->vbls>10)monkeybar_npc->AI++;
		if(monkeybar_npc->AI==27)if(NPC_move_to_xy_nohit_noanim(&monkeybar_npc,SPEED_SLOWEST,25*8+4,98*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;}
		if(monkeybar_npc->AI==28)if(monkeybar_npc->vbls>10)monkeybar_npc->AI++;
		if(monkeybar_npc->AI==29)if(NPC_move_to_xy_nohit_noanim(&monkeybar_npc,SPEED_SLOWEST,25*8+4,100*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;}
		if(monkeybar_npc->AI==30)if(monkeybar_npc->vbls>10)monkeybar_npc->AI++;
		if(monkeybar_npc->AI==31)if(NPC_move_to_xy_nohit_noanim(&monkeybar_npc,SPEED_SLOWEST,25*8+4,102*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;}
		if(monkeybar_npc->AI==32)if(monkeybar_npc->vbls>10)monkeybar_npc->AI++;
		if(monkeybar_npc->AI==33)if(NPC_move_to_xy_nohit_noanim(&monkeybar_npc,SPEED_SLOWEST,25*8+4,104*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;}
		if(monkeybar_npc->AI==34)if(monkeybar_npc->vbls>10)monkeybar_npc->AI++;
		if(monkeybar_npc->AI==35)if(NPC_move_to_xy_nohit_noanim(&monkeybar_npc,SPEED_SLOWEST,25*8+4,106*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;}
		if(monkeybar_npc->AI==36)if(monkeybar_npc->vbls>10)monkeybar_npc->AI++;
		if(monkeybar_npc->AI==37)if(NPC_move_to_xy_nohit_noanim(&monkeybar_npc,SPEED_SLOWEST,25*8+4,108*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;}
		if(monkeybar_npc->AI==38)if(monkeybar_npc->vbls>10)monkeybar_npc->AI++;
		if(monkeybar_npc->AI==39)if(NPC_move_to_xy_nohit_noanim(&monkeybar_npc,SPEED_SLOWEST,25*8+4,110*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;}
		if(monkeybar_npc->AI==40)if(monkeybar_npc->vbls>10)monkeybar_npc->AI++;
		if(monkeybar_npc->AI==41)if(NPC_move_to_xy_nohit_noanim(&monkeybar_npc,SPEED_FAST	,25*8+4,114*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;monkeybar_npc->always_on_top=0;}
		if(monkeybar_npc->AI==42)if(monkeybar_npc->vbls>10)monkeybar_npc->AI++;
		if(monkeybar_npc->AI==43)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&monkeybar_npc,SPEED_SLOWEST,25*8+4,119*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;}
		if(monkeybar_npc->AI==44)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&monkeybar_npc,SPEED_SLOWEST,34*8,119*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;}
		if(monkeybar_npc->AI==45)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&monkeybar_npc,SPEED_SLOWEST,34*8,101*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;}
		if(monkeybar_npc->AI==46)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&monkeybar_npc,SPEED_SLOWEST,49*8,101*8)==(1)){monkeybar_npc->AI++;monkeybar_npc->vbls=0;}
		if(monkeybar_npc->AI==47)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&monkeybar_npc,SPEED_SLOWEST,49*8, 95*8)==(1)){monkeybar_npc->AI=0;}
		}
	//junglegym kid over 1 at 44,108 to 52,108, to  48,108 to 48,111 to 44,111, to 52,111
	static NPC* junglegym_npc = NULL;
	if(junglegym_npc==NULL)
	{
		NPC_create_npc_xy_feet(&junglegym_npc,GFX_KID_GENERICboy2,16,32,44*8,108*8);
		//junglegym_npc->non_walkable=1;
		//junglegym_npc->pushable=1;
		junglegym_npc->layer=1;
		NPC_animate_stand_dir(&junglegym_npc,LEFT);
	}
	else if(junglegym_npc!=NULL)
	{
		//if(NPC_in_range_of_npc(&PLAYER_npc,junglegym_npc))NPC_stare_at_npc(&junglegym_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&junglegym_npc,DOWN);
		if(junglegym_npc->AI==0)if(NPC_walk_to_xy_nohit(&junglegym_npc,SPEED_SLOWEST*2,52*8,106*8)==(1))junglegym_npc->AI++;
		if(junglegym_npc->AI==1)if(NPC_walk_to_xy_nohit(&junglegym_npc,SPEED_SLOWEST*2,49*8,106*8)==(1))junglegym_npc->AI++;
		if(junglegym_npc->AI==2)if(NPC_walk_to_xy_nohit(&junglegym_npc,SPEED_SLOWEST*2,49*8,110*8)==(1))junglegym_npc->AI++;
		if(junglegym_npc->AI==3)if(NPC_walk_to_xy_nohit(&junglegym_npc,SPEED_SLOWEST*2,45*8,110*8)==(1))junglegym_npc->AI++;
		if(junglegym_npc->AI==4)if(NPC_walk_to_xy_nohit(&junglegym_npc,SPEED_SLOWEST*2,52*8,110*8)==(1))junglegym_npc->AI++;
		if(junglegym_npc->AI==5)if(NPC_walk_to_xy_nohit(&junglegym_npc,SPEED_SLOWEST*2,49*8,110*8)==(1))junglegym_npc->AI++;
		if(junglegym_npc->AI==6)if(NPC_walk_to_xy_nohit(&junglegym_npc,SPEED_SLOWEST*2,49*8,106*8)==(1))junglegym_npc->AI=0;
		if(ACTION_npc(&junglegym_npc,"Talk To Jungle Gym Kid"))
		{
			TEXT_set_sprite_window(0,junglegym_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
//slide kids 25,136 , over 1, to 28,127 to 30,127, diagonal to 40,136, over 2, 41,138, 25,138
	static NPC* slide_npc = NULL;
	if(slide_npc==NULL)
	{
		NPC_create_npc_xy_feet(&slide_npc,GFX_KID_GENERICboy2,16,32,25*8,136*8);
		slide_npc->non_walkable=1;
		//slide_npc->pushable=1;
		slide_npc->layer=1;
		NPC_animate_stand_dir(&slide_npc,RIGHT);
	}
	else if(slide_npc!=NULL)
	{
		//if(NPC_in_range_of_npc(&PLAYER_npc,slide_npc))NPC_stare_at_npc(&slide_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&slide_npc,DOWN);
		if(slide_npc->AI==0)if(NPC_walk_to_xy_nohit(&slide_npc,SPEED_SLOWEST,28*8,127*8)==(1)){slide_npc->AI++;slide_npc->layer=1;}
		if(slide_npc->AI==1)if(NPC_walk_to_xy_nohit(&slide_npc,SPEED_SLOWEST,30*8,127*8)==(1)){slide_npc->AI++;slide_npc->animation_off=1;}
		if(slide_npc->AI==2)if(NPC_walk_to_xy_nohit(&slide_npc,SPEED_NORMAL ,40*8,136*8)==(1)){slide_npc->AI++;slide_npc->animation_off=0;}
		if(slide_npc->AI==3)if(NPC_walk_to_xy_nohit(&slide_npc,SPEED_SLOWEST,41*8,138*8)==(1)){slide_npc->AI++;slide_npc->layer=2;}
		if(slide_npc->AI==4)if(NPC_walk_to_xy_nohit(&slide_npc,SPEED_SLOWEST,25*8,138*8)==(1)){slide_npc->AI++;}
		if(slide_npc->AI==5)if(NPC_walk_to_xy_nohit(&slide_npc,SPEED_SLOWEST,25*8,136*8)==(1)){slide_npc->AI=0;}
		if(ACTION_npc(&slide_npc,"Talk To Slide Kid"))
		{
			TEXT_set_sprite_window(0,slide_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
//slide 2 25,158. over 1, to 28 149, diagonal to 40,158, over 2, 41,160,  25,160
	static NPC* slide2_npc = NULL;
	if(slide2_npc==NULL)
	{
		NPC_create_npc_xy_feet(&slide2_npc,GFX_KID_GENERICboy2,16,32,25*8,158*8);
		slide2_npc->non_walkable=1;
		//slide2_npc->pushable=1;
		slide2_npc->layer=1;
		NPC_animate_stand_dir(&slide2_npc,RIGHT);
	}
	else if(slide2_npc!=NULL)
	{
		//if(NPC_in_range_of_npc(&PLAYER_npc,slide2_npc))NPC_stare_at_npc(&slide2_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&slide2_npc,DOWN);
		if(slide2_npc->AI==0)if(NPC_walk_to_xy_nohit(&slide2_npc,SPEED_SLOWEST,28*8,149*8)==(1)){slide2_npc->AI++;slide2_npc->layer=1;}
		if(slide2_npc->AI==1)if(NPC_walk_to_xy_nohit(&slide2_npc,SPEED_SLOWEST,30*8,149*8)==(1)){slide2_npc->AI++;slide2_npc->animation_off=1;}
		if(slide2_npc->AI==2)if(NPC_walk_to_xy_nohit(&slide2_npc,SPEED_NORMAL ,40*8,158*8)==(1)){slide2_npc->AI++;slide2_npc->animation_off=0;}
		if(slide2_npc->AI==3)if(NPC_walk_to_xy_nohit(&slide2_npc,SPEED_SLOWEST,41*8,160*8)==(1)){slide2_npc->AI++;slide2_npc->layer=2;}
		if(slide2_npc->AI==4)if(NPC_walk_to_xy_nohit(&slide2_npc,SPEED_SLOWEST,25*8,160*8)==(1)){slide2_npc->AI++;}
		if(slide2_npc->AI==5)if(NPC_walk_to_xy_nohit(&slide2_npc,SPEED_SLOWEST,25*8,158*8)==(1)){slide2_npc->AI=0;}
		if(ACTION_npc(&slide2_npc,"Talk To Slide Kid"))
		{
			TEXT_set_sprite_window(0,slide2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
//swings face left 55,160
//TODO: get rid of this :(
	static NPC* sideswing_npc = NULL;
	if(sideswing_npc==NULL)
	{
		NPC_create_npc_xy_feet(&sideswing_npc,GFX_KID_GENERICboy2,16,32,55*8,160*8);
		sideswing_npc->non_walkable=1;
		//sideswing_npc->pushable=1;
		sideswing_npc->layer=2;
		NPC_animate_stand_dir(&sideswing_npc,LEFT);
	}
	else if(sideswing_npc!=NULL)
	{
		//if(NPC_in_range_of_npc(&PLAYER_npc,sideswing_npc))NPC_stare_at_npc(&sideswing_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&sideswing_npc,DOWN);
		if(ACTION_npc(&sideswing_npc,"Talk To Swing Kid"))
		{
			TEXT_set_sprite_window(0,sideswing_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
//kickball
//kicker 43,182
//waiting kids 52,183 55,183 58,183
//1st base 27,198 face right
//2nd 43,214 face up
//3rd 59,198 face left
//home 43,184
//pitcher
//43,198 face up
//left field 33,229
//right field 54,232
	static NPC* kickball_npcs[11] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	c=0;
	for(c=0;c<12;c++)
	{
		if(kickball_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			if(c== 0){x=43*8;y=182*8;dir=DOWN;}//kicker
			if(c== 1){x=52*8;y=183*8;dir=DOWN;}//line
			if(c== 2){x=55*8;y=183*8;dir=DOWN;}//line
			if(c== 3){x=58*8;y=183*8;dir=DOWN;}//line
			if(c== 4){x=43*8;y=197*8;dir=UP;}//pitcher
			if(c== 5){x=43*8;y=178*8;dir=DOWN;}//catcher
			if(c== 6){x=25*8;y=199*8;dir=RIGHT;}//1st baseman
			if(c== 7){x=41*8;y=215*8;dir=UP;}//2nd basement
			if(c== 8){x=61*8;y=199*8;dir=LEFT;}//3rd baseman
			if(c== 9){x=33*8;y=229*8;dir=UP;}//left field
			if(c==10){x=54*8;y=232*8;dir=UP;}//right field
			NPC_create_random_LITTLE_CHILD_xy_feet(&kickball_npcs[c],x,(y)+3);
			NPC_animate_stand_dir(&kickball_npcs[c], dir);
			kickball_npcs[c]->non_walkable=1;
			//kickball_npcs[c]->pushable=1;
			kickball_npcs[c]->walk_dir=dir;
			kickball_npcs[c]->layer=bgp;
		}
		if(kickball_npcs[c]!=NULL)
		{
			//pitcher runs forward
			if(kickball_npcs[0]->AI==0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[4],SPEED_FASTER,43*8,196*8)==(1))kickball_npcs[0]->AI++;
			//kicker kicks
			if(kickball_npcs[0]->AI==1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[0],SPEED_FASTEST,43*8,184*8)==(1))kickball_npcs[0]->AI++;
			//kicker runs to 1st
			if(kickball_npcs[0]->AI==2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[0],SPEED_FASTER,27*8,198*8)==(1))kickball_npcs[0]->AI++;
			//2nd kicker walks to home, pitcher backs up
			if(kickball_npcs[0]->AI==3)
			{
				if(
					 NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[1],SPEED_NORMAL,43*8,182*8)
					&&NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[4],SPEED_NORMAL,43*8,197*8)
				)
				{
					kickball_npcs[0]->AI++;
					NPC_animate_stand_dir(&kickball_npcs[1],DOWN);
					NPC_animate_stand_dir(&kickball_npcs[4],UP);
					NPC_animate_stand_dir(&kickball_npcs[0],RIGHT);
				}
			}
			//pitcher runs forward
			if(kickball_npcs[0]->AI==4)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[4],SPEED_FASTER,43*8,196*8)==(1))kickball_npcs[0]->AI++;
			//2nd kicker kicks
			if(kickball_npcs[0]->AI==5)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[1],SPEED_FASTEST,43*8,184*8)==(1))kickball_npcs[0]->AI++;
			//1st kicker runs to 2nd, 2nd kicker runs to 1st
			if(kickball_npcs[0]->AI==6)
			{
				if(
					 NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[0],SPEED_FASTER,43*8,214*8)
					+NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[1],SPEED_FASTER,27*8,198*8)==2
				)
				{
					kickball_npcs[0]->AI++;
					NPC_animate_stand_dir(&kickball_npcs[4],UP);
					NPC_animate_stand_dir(&kickball_npcs[0],UP);
					NPC_animate_stand_dir(&kickball_npcs[1],RIGHT);
				}
			}
			//3rd kicker moves to home, pitcher backs up
			if(kickball_npcs[0]->AI==7)
			{
				if(
					 NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[2],SPEED_NORMAL,43*8,182*8)
					+NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[4],SPEED_NORMAL,43*8,197*8)==2
				)
				{
					kickball_npcs[0]->AI++;
					NPC_animate_stand_dir(&kickball_npcs[2],DOWN);
					NPC_animate_stand_dir(&kickball_npcs[4],UP);
				}
			}
			//pitcher runs forward
			if(kickball_npcs[0]->AI==8)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[4],SPEED_FASTER,43*8,196*8)==(1))kickball_npcs[0]->AI++;
			//3rd kicker kicks
			if(kickball_npcs[0]->AI==9)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[2],SPEED_FASTEST,43*8,184*8)==(1))kickball_npcs[0]->AI++;
			//1st kicker goes to 3rd, 2nd kicker goes to 2nd, 3rd kicker goes to 1st
			if(kickball_npcs[0]->AI==10)
			{
				if(
					  NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[0],SPEED_FASTER,59*8,198*8)
					+NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[1],SPEED_FASTER,43*8,214*8)
					+NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[2],SPEED_FASTER,27*8,198*8)==3
				)
				{
					kickball_npcs[0]->AI++;
					NPC_animate_stand_dir(&kickball_npcs[0],LEFT);
					NPC_animate_stand_dir(&kickball_npcs[1],UP);
					NPC_animate_stand_dir(&kickball_npcs[2],RIGHT);
				}
			}
			//4th kicker goes to home, pitcher backs up
			if(kickball_npcs[0]->AI==11)
			{
				if(
					  NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[3],SPEED_NORMAL,43*8,182*8)
					&&NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[4],SPEED_NORMAL,43*8,197*8)
				)
				{
					kickball_npcs[0]->AI++;
					NPC_animate_stand_dir(&kickball_npcs[3],DOWN);
					NPC_animate_stand_dir(&kickball_npcs[4],UP);
				}
			}
			//pitcher runs forward
			if(kickball_npcs[0]->AI==12)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[4],SPEED_FASTER,43*8,196*8)==(1))kickball_npcs[0]->AI++;
			//4th kicker kicks, good kick
			if(kickball_npcs[0]->AI==13)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[3],SPEED_FASTEST,43*8,184*8)==(1))kickball_npcs[0]->AI++;
			//1st kicker runs home, 2nd kicker runs to 3rd, 3rd kicker runs to 2nd, 4th kicker runs to first
			if(kickball_npcs[0]->AI==14)
			{
				if(
					 NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[0],SPEED_FASTER,43*8,184*8)
					+NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[1],SPEED_FASTER,59*8,198*8)
					+NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[2],SPEED_FASTER,43*8,214*8)
					+NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[3],SPEED_FASTER,27*8,198*8)==4
				)
				{
					kickball_npcs[0]->AI++;
					NPC_animate_stand_dir(&kickball_npcs[1],LEFT);
					NPC_animate_stand_dir(&kickball_npcs[2],UP);
					NPC_animate_stand_dir(&kickball_npcs[3],RIGHT);
				}
			}
			//1st kicker gets back in line
			if(kickball_npcs[0]->AI==15)
			{
				if(
					 NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[0],SPEED_NORMAL,52*8,183*8)
					+NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[1],SPEED_FASTER,43*8,184*8)
					+NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[2],SPEED_FASTER,59*8,198*8)
					+NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[3],SPEED_FASTER,43*8,214*8)==4
				)
				{
					kickball_npcs[0]->AI++;
					NPC_animate_stand_dir(&kickball_npcs[0],DOWN);
				}
			}
			if(kickball_npcs[0]->AI==16)
			{
				if(
					 NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[1],SPEED_NORMAL,55*8,183*8)
					+NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[2],SPEED_FASTER,43*8,184*8)
					+NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[3],SPEED_FASTER,59*8,198*8)==3
				)
				{
					kickball_npcs[0]->AI++;
					NPC_animate_stand_dir(&kickball_npcs[1],DOWN);
				}
			}
			if(kickball_npcs[0]->AI==17)
			{
				if(
					 NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[2],SPEED_NORMAL,58*8,183*8)
					+NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[3],SPEED_FASTER,43*8,184*8)==2
				)
				{
					kickball_npcs[0]->AI++;
					NPC_animate_stand_dir(&kickball_npcs[2],DOWN);
				}
			}
			if(kickball_npcs[0]->AI==18)
			{
				if(
					 NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[3],SPEED_NORMAL,61*8,183*8)
				)
				{
					kickball_npcs[0]->AI++;
					NPC_animate_stand_dir(&kickball_npcs[3],DOWN);
				}
			}
			if(kickball_npcs[0]->AI==19)
			{
				if(
					 NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[0],SPEED_NORMAL,43*8,182*8)
					 +NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&kickball_npcs[4],SPEED_NORMAL,43*8,197*8)==2
				)
				{
					kickball_npcs[0]->AI=0;
				}
			}
		}
	}
	//pitcher runs up a tile
//ball travels
//kicker runs foward two tiles
//ball goes flying, either left or Right
//kicker runs to first baseman
//ball kicked to first
//kicker gets in line
//next line kid kicks
//TODO: need kickball ball
//TODO: talk to anyone standing around "yuu cant play"
	//TODO: if bell rings, everybody floods into school
	if(walking_into_door(RANGE_OUTSIDEPlaygroundToINSIDESchoolEntranceHallwayLeft))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLEntranceHallway,10,40);return;
	}
	if(walking_into_door(RANGE_OUTSIDEPlaygroundToINSIDESchoolEntranceHallwayRight))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLEntranceHallway,109,40);return;
	}
	if(walking_into_door(RANGE_OUTSIDEPlaygroundToINSIDESchoolBackHallwayLeft))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLBackHallway,106,12);return;
	}
	if(walking_into_door(RANGE_OUTSIDEPlaygroundToINSIDESchoolBackHallwayRight))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLBackHallway,118,12);return;
	}
}
void bobsgame_SCHOOLPlayground_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLPlayground_Map_VBL_Function()
{

}

void bobsgame_SCHOOLPlayground_Map_HBL_Function()
{

}



