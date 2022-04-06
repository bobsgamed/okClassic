//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================


/*

	if(ACTION_range_xy_xy(59*8,12*8,61*8,13*8,"Look At THING"))
	{
		TEXT_set_sprite_window(0,PLAYER_npc);
		TEXT_set_sprite_window(1,PLAYER_npc);
		TEXT_window("" //?
		);
	}

//=========================================================================================
//            STATIC SPRITE THAT GETS ANIMATED
//=========================================================================================

	static NPC* fountainwater1_npc = NULL;
	if(fountainwater1_npc==NULL)
	{
		NPC_create_npc_xy_feet(&fountainwater1_npc,fountainwater,64,64,31*8-4,18*8);
		fountainwater1_npc->layer=1;

	}
	if(fountainwater1_npc!=NULL)
	{
		if(fountainwater1_npc->vbl_timer>3){NPC_animate_cycle_through_frames_now(fountainwater1_npc,6);fountainwater1_npc->vbl_timer=0;}
	}

//=========================================================================================
//            LOTS OF PEOPLE SITTING THERE, ANIMATING A LITTLE, LOOK AT YOU IF YOU GET CLOSE
//=========================================================================================

	static NPC* NAME_npcs[13] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<13;c++)
	{
		if(NAME_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			int* gfx=NULL;

			if(c== 0){x=20*8;y=32*8;dir=RIGHT;	bgp=2;  gfx=SPRITE;}
			if(c== 1){x=25*8;y=28*8-4;dir=DOWN;	bgp=2;  }
			if(c== 2){x=31*8;y=28*8-4;dir=DOWN;	bgp=2;  }
			if(c== 3){x=37*8;y=28*8-4;dir=DOWN;	bgp=2;  }
			if(c== 4){x=43*8;y=28*8-4;dir=DOWN;	bgp=2;	}
			if(c== 5){x=49*8;y=28*8-4;dir=DOWN;	bgp=2;	}
			if(c== 6){x=55*8;y=28*8-4;dir=DOWN;	bgp=2;	}
			if(c== 7){x=25*8;y=36*8;dir=UP;		bgp=2;	}
			if(c== 8){x=31*8;y=36*8;dir=UP;		bgp=2;	}
			if(c== 9){x=37*8;y=36*8;dir=UP;		bgp=2;	}
			if(c==10){x=43*8;y=36*8;dir=UP;		bgp=2;	}
			if(c==11){x=49*8;y=36*8;dir=UP;		bgp=2;	}
			if(c==12){x=55*8;y=36*8;dir=UP;		bgp=2;	}


			if(gfx==NULL)NPC_create_random_ADULT_xy_feet(&NAME_npcs[c],x,y);
			else NPC_create_npc_xy_feet(&NAME_npcs[c],gfx,16,40,x,y);

			NPC_animate_set_direction_now(NAME_npcs[c], dir);
			NAME_npcs[c]->non_walkable=1;
			NAME_npcs[c]->walking_direction=dir;
			NAME_npcs[c]->layer=bgp;
			//NPC_animate_increment_direction_frame_now(NAME_npcs[c], dir);

		}

		if(NAME_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_amt(PLAYER_npc,NAME_npcs[c],15))NPC_stare_at_npc_not_opposite_walking_direction(NAME_npcs[c],PLAYER_npc);
			else if(NAME_npcs[c]->cycle==0){if(NAME_npcs[c]->vbl_timer>200){if(rand()%4==0){NAME_npcs[c]->cycle=1+rand()%3;}else{NAME_npcs[c]->vbl_timer=0;NPC_animate_set_direction_now(NAME_npcs[c], NAME_npcs[c]->walking_direction);if(NAME_npcs[c]->anim_frame_count!=0){NAME_npcs[c]->anim_frame_count=3;NPC_animate_increment_direction_frame_now(NAME_npcs[c], NAME_npcs[c]->walking_direction);}}}}
			else if(NAME_npcs[c]->cycle==1){if(NAME_npcs[c]->walking_direction==UP||NAME_npcs[c]->walking_direction==DOWN)NPC_animate_set_direction_now(NAME_npcs[c],LEFT);else NPC_animate_set_direction_now(NAME_npcs[c],UP);NAME_npcs[c]->vbl_timer=rand()%120;NAME_npcs[c]->cycle=0;}
			else if(NAME_npcs[c]->cycle==2){if(NAME_npcs[c]->walking_direction==UP||NAME_npcs[c]->walking_direction==DOWN)NPC_animate_set_direction_now(NAME_npcs[c],RIGHT);else NPC_animate_set_direction_now(NAME_npcs[c],DOWN);NAME_npcs[c]->vbl_timer=rand()%120;NAME_npcs[c]->cycle=0;}
			else if(NAME_npcs[c]->cycle==3){NPC_animate_increment_direction_frame_now(NAME_npcs[c],NAME_npcs[c]->walking_direction);NAME_npcs[c]->vbl_timer=rand()%120;NAME_npcs[c]->cycle=0;}

			//if(NPC_in_range_of_npc_amt(PLAYER_npc,NAME_npcs[c],15))NPC_stare_at_npc(NAME_npcs[c],PLAYER_npc);
			//else NPC_animate_set_direction_now(NAME_npcs[c], NAME_npcs[c]->walking_direction);
		}
	}

//=========================================================================================
//            PEOPLE COMING IN FROM ONE OF TWO DOORS, ONCE EVERY TWO MINUTES, WALK SOMEWHERE, GET DELETED
//=========================================================================================

	int c=0;
	static NPC* NAME_npcs[6] = {NULL,NULL,NULL,NULL,NULL,NULL};
	static int last_clock=0;
	for(c=0;c<6;c++)
	{
		if(NAME_npcs[c]==NULL&&CLOCK_minute%2==0&&CLOCK_minute!=last_clock)
		{
			last_clock=CLOCK_minute;
			if(rand()%2==0)NPC_create_random_ADULT_xy_feet(&NAME_npcs[c],26*8,46*8);
			else NPC_create_random_ADULT_xy_feet(&NAME_npcs[c],34*8,46*8);

			NAME_npcs[c]->non_walkable=1;
			NAME_npcs[c]->cycle=0;
			NAME_npcs[c]->walking_speed=SPEED_NORMAL+rand()%(SPEED_SLOW-SPEED_FASTEST);
			NAME_npcs[c]->ignore_fx_layer=1;
			NPC_animate_set_direction_now(NAME_npcs[c], UP);
		}

		if(NAME_npcs[c]!=NULL)
		{
			if(NAME_npcs[c]->cycle== 0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(NAME_npcs[c],NAME_npcs[c]->walking_speed, NAME_npcs[c]->MAP_x+NAME_npcs[c]->size_x/2,42*8)==(1))NAME_npcs[c]->cycle++;
			if(NAME_npcs[c]->cycle== 1)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(NAME_npcs[c],NAME_npcs[c]->walking_speed, 85*8,NAME_npcs[c]->MAP_y+NAME_npcs[c]->size_y-NAME_npcs[c]->hitsize_y)==1)NAME_npcs[c]->cycle++;
			if(NAME_npcs[c]->cycle== 2)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(NAME_npcs[c],NAME_npcs[c]->walking_speed, 85*8,23*8)==1){NPC_delete_npc(NAME_npcs[c]);}
		}
	}

//=========================================================================================
//            ONE PERSON, LOOK AROUND, ANIMATE A LITTLE
//=========================================================================================

	static NPC* NAME_npc = NULL;
	if(NAME_npc==NULL)
	{
		NPC_create_random_ADULT_xy_feet(&NAME_npc,10*8-4,27*8);
		//NPC_create_npc_xy_feet(&NAME_npc,SPRITE,16,40,7*8,27*8);

		NAME_npc->non_walkable=1;
		NAME_npc->layer=2;
		NPC_animate_set_direction_now(NAME_npc,LEFT);

		NAME_npc->walking_speed=SPEED_NORMAL+(rand()%(SPEED_SLOWEST-SPEED_FAST));
		NAME_npc->walking_direction=NAME_npc->anim_direction;

		//NPC_animate_increment_direction_frame_now(NAME_npc, NAME_npc->anim_direction);

	}
	if(NAME_npc!=NULL)
	{
		//if(NPC_in_range_of_npc_amt(PLAYER_npc,NAME_npc,15))NPC_stare_at_npc(NAME_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(NAME_npc, NAME_npc->walking_direction);

		if(NPC_in_range_of_npc_amt(PLAYER_npc,NAME_npc,15))NPC_stare_at_npc_not_opposite_walking_direction(NAME_npc,PLAYER_npc);
		else
		{
			if(NAME_npc->cycle==0){if(NAME_npc->vbl_timer>200){if(rand()%4==0){NAME_npc->cycle=1+rand()%3;}else{NAME_npc->vbl_timer=0;NPC_animate_set_direction_now(NAME_npc, NAME_npc->walking_direction);if(NAME_npc->anim_frame_count!=0){NAME_npc->anim_frame_count=3;NPC_animate_increment_direction_frame_now(NAME_npc, NAME_npc->walking_direction);}}}}
			if(NAME_npc->cycle==1){if(NAME_npc->walking_direction==UP||NAME_npc->walking_direction==DOWN)NPC_animate_set_direction_now(NAME_npc,LEFT);else NPC_animate_set_direction_now(NAME_npc,UP);NAME_npc->vbl_timer=rand()%120;NAME_npc->cycle=0;}
			if(NAME_npc->cycle==2){if(NAME_npc->walking_direction==UP||NAME_npc->walking_direction==DOWN)NPC_animate_set_direction_now(NAME_npc,RIGHT);else NPC_animate_set_direction_now(NAME_npc,DOWN);NAME_npc->vbl_timer=rand()%120;NAME_npc->cycle=0;}
			if(NAME_npc->cycle==3){NPC_animate_increment_direction_frame_now(NAME_npc,NAME_npc->walking_direction);NAME_npc->vbl_timer=rand()%120;NAME_npc->cycle=0;}
		}

		if(ACTION_npc(NAME_npc,"Talk To NAME"))
		{
			TEXT_set_sprite_window(0,NAME_npc);
			TEXT_set_sprite_window(1,PLAYER_npc);
			TEXT_window("" //?
			);
		}
	}

//=========================================================================================
//            ONE PERSON, WALK ON A SET PATH, STOP AND LOOK AT YOU IF YOU GET CLOSE
//=========================================================================================

	static NPC* NAME_npc = NULL;
	if(NAME_npc==NULL)
	{
		NPC_create_npc_xy_feet(&NAME_npc,SPRITE,16,40,6*8,21*8);
		//NPC_create_random_ADULT_xy_feet(&NAME_npc,11*8,34*8);

		NAME_npc->layer=2;
		NAME_npc->non_walkable=1;
		NPC_animate_set_direction_now(NAME_npc,DOWN);

		NAME_npc->walking_speed = SPEED_NORMAL+(rand()%(SPEED_SLOWEST-SPEED_FAST));
		NAME_npc->cycle=0;
	}
	if(NAME_npc!=NULL)
	{
		if(NPC_in_range_of_npc_amt(PLAYER_npc,NAME_npc,15))NPC_stare_at_npc(NAME_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(NAME_npc, LEFT);

		else if(NAME_npc->cycle== 0){if(NPC_walk_to_xy_nohit_pushmain(NAME_npc,NAME_npc->walking_speed, 6*8,21*8)==1){NPC_animate_set_direction_now(NAME_npc,DOWN);NAME_npc->vbl_timer=rand()%40;NAME_npc->cycle++;}}
		else if(NAME_npc->cycle== 1){if(NAME_npc->vbl_timer>60)NAME_npc->cycle++;}
		else if(NAME_npc->cycle== 2){NPC_animate_set_direction_now(NAME_npc,UP);NAME_npc->vbl_timer=rand()%40;NAME_npc->cycle++;}
		else if(NAME_npc->cycle== 3){if(NAME_npc->vbl_timer>60)NAME_npc->cycle++;}
		else if(NAME_npc->cycle== 4){if(NPC_walk_to_xy_nohit_pushmain(NAME_npc,NAME_npc->walking_speed,28*8,81*8)==1){NAME_npc->vbl_timer=rand()%40;NAME_npc->cycle++;}}
		else if(NAME_npc->cycle== 5){if(NPC_walk_to_xy_nohit_pushmain(NAME_npc,NAME_npc->walking_speed,28*8,21*8)==1){NPC_animate_set_direction_now(NAME_npc,DOWN);NAME_npc->vbl_timer=rand()%40;NAME_npc->cycle++;}}
		else if(NAME_npc->cycle== 6){if(NAME_npc->vbl_timer>120)NAME_npc->cycle=0;}

		if(ACTION_npc(NAME_npc,"Talk To NAME"))
		{
			TEXT_set_sprite_window(0,NAME_npc);
			TEXT_set_sprite_window(1,PLAYER_npc);
			TEXT_window(""
			);
		}
	}

//=========================================================================================
//            ONE PERSON, WALK ON A SET PATH, RUN TO XY IF YOURE WITHIN A RANGE
//=========================================================================================

	static NPC* NAME_npc = NULL;
	if(NAME_npc==NULL)
	{

		NPC_create_npc_xy_feet(&NAME_npc,SPRITE,16,40,64*8,36*8);
		//NPC_create_random_ADULT_xy_feet(&NAME_npc,11*8,34*8);

		NAME_npc->layer=2;
		NAME_npc->non_walkable=1;
		NPC_animate_set_direction_now(NAME_npc,RIGHT);

		NAME_npc->walking_speed = SPEED_NORMAL;
		NAME_npc->cycle=0;

	}
	if(NAME_npc!=NULL)
	{
		if(NPC_in_range_of_xy_xy_direction(PLAYER_npc,60*8,31*8,76*8,34*8,PLAYER_npc->anim_direction,0))
		{
			if(NPC_walk_to_xy_nohit(NAME_npc,NAME_npc->walking_speed, 66*8,36*8)==1)NPC_animate_set_direction_now(NAME_npc,UP);
		}
		else
		if(NPC_in_range_of_xy_xy_direction(PLAYER_npc,55*8,35*8,61*8,40*8,PLAYER_npc->anim_direction,0))
		{
			if(NPC_walk_to_xy_nohit(NAME_npc,NAME_npc->walking_speed, 61*8,36*8)==1)NPC_animate_set_direction_now(NAME_npc,LEFT);
		}
		else if(NAME_npc->cycle== 0){if(NPC_walk_to_xy_nohit(NAME_npc,NAME_npc->walking_speed,75*8,36*8)==1){NAME_npc->cycle=3;NAME_npc->vbl_timer=rand()%60;NPC_animate_set_direction_now(NAME_npc,UP);}}
		else if(NAME_npc->cycle== 1){if(NPC_walk_to_xy_nohit(NAME_npc,NAME_npc->walking_speed,67*8,36*8)==1){NAME_npc->cycle=3;NAME_npc->vbl_timer=rand()%60;NPC_animate_set_direction_now(NAME_npc,UP);}}
		else if(NAME_npc->cycle== 2){if(NPC_walk_to_xy_nohit(NAME_npc,NAME_npc->walking_speed,61*8,36*8)==1){NAME_npc->cycle=3;NAME_npc->vbl_timer=rand()%60;NPC_animate_set_direction_now(NAME_npc,UP);}}
		else if(NAME_npc->cycle== 3){if(NAME_npc->vbl_timer>120){NAME_npc->vbl_timer=0;NAME_npc->cycle=rand()%3;}}

		if(ACTION_range_xy_xy(58*8,33*8,77*8,40*8,"Talk To NAME"))
		{
			TEXT_set_sprite_window(0,NAME_npc);
			TEXT_set_sprite_window(1,PLAYER_npc);
			TEXT_window(""
			);
		}
	}

//=========================================================================================
//            TWO PEOPLE, WALK ON A SET PATH OPPOSITE EACH OTHER
//=========================================================================================

	static NPC* poolplayer5_npc = NULL;
	static NPC* poolplayer6_npc = NULL;

	if(poolplayer5_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&poolplayer5_npc,biker,16,40,14*8,52*8);
		NPC_create_random_ADULT_xy_feet(&poolplayer5_npc,24*8,39*8);

		poolplayer5_npc->layer=2;
		poolplayer5_npc->non_walkable=1;
		NPC_animate_set_direction_now(poolplayer5_npc,RIGHT);

		poolplayer5_npc->walking_speed = SPEED_SLOWEST+rand()%(SPEED_SLOWEST-SPEED_FASTEST);
		poolplayer5_npc->cycle=0;
	}
	if(poolplayer5_npc!=NULL)
	{
		if(poolplayer5_npc->cycle== 0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(poolplayer5_npc,poolplayer5_npc->walking_speed, 30*8,34*8)==1){poolplayer5_npc->cycle=4;poolplayer5_npc->vbl_timer=rand()%60;NPC_animate_set_direction_now(poolplayer5_npc,DOWN);}
		if(poolplayer5_npc->cycle== 1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(poolplayer5_npc,poolplayer5_npc->walking_speed, 27*8,40*8)==1){poolplayer5_npc->cycle=4;poolplayer5_npc->vbl_timer=rand()%60;NPC_animate_set_direction_now(poolplayer5_npc,RIGHT);}
		if(poolplayer5_npc->cycle== 2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(poolplayer5_npc,poolplayer5_npc->walking_speed, 30*8,42*8)==1){poolplayer5_npc->cycle=4;poolplayer5_npc->vbl_timer=rand()%60;NPC_animate_set_direction_now(poolplayer5_npc,UP);}
		if(poolplayer5_npc->cycle== 3)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(poolplayer5_npc,poolplayer5_npc->walking_speed, 34*8,39*8)==1){poolplayer5_npc->cycle=4;poolplayer5_npc->vbl_timer=rand()%60;NPC_animate_set_direction_now(poolplayer5_npc,LEFT);}

		if(poolplayer5_npc->cycle== 4)if(poolplayer5_npc->vbl_timer>150){poolplayer5_npc->vbl_timer=0;poolplayer5_npc->cycle=5;}//TODO: ball animation and crack sound
		if(poolplayer5_npc->cycle== 5)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(poolplayer5_npc,poolplayer5_npc->walking_speed,  24*8,39*8)==1){poolplayer5_npc->cycle=6;poolplayer5_npc->vbl_timer=rand()%60;NPC_animate_set_direction_now(poolplayer5_npc,RIGHT);}
		if(poolplayer5_npc->cycle== 6){poolplayer5_npc->vbl_timer=0;poolplayer6_npc->cycle=rand()%4;poolplayer5_npc->cycle=7;}
	}

	if(poolplayer6_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&poolplayer6_npc,biker,16,40,9*8,31*8);
		NPC_create_random_ADULT_xy_feet(&poolplayer6_npc,30*8,31*8);

		poolplayer6_npc->layer=2;
		poolplayer6_npc->non_walkable=1;
		NPC_animate_set_direction_now(poolplayer6_npc,DOWN);

		poolplayer6_npc->walking_speed = SPEED_SLOWEST+rand()%(SPEED_SLOWEST-SPEED_FASTEST);
		poolplayer6_npc->cycle=0;
	}
	if(poolplayer6_npc!=NULL)
	{
		if(poolplayer6_npc->cycle== 0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(poolplayer6_npc,poolplayer6_npc->walking_speed, 30*8,34*8)==1){poolplayer6_npc->cycle=4;poolplayer6_npc->vbl_timer=rand()%60;NPC_animate_set_direction_now(poolplayer6_npc,DOWN);}
		if(poolplayer6_npc->cycle== 1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(poolplayer6_npc,poolplayer6_npc->walking_speed, 27*8,40*8)==1){poolplayer6_npc->cycle=4;poolplayer6_npc->vbl_timer=rand()%60;NPC_animate_set_direction_now(poolplayer6_npc,RIGHT);}
		if(poolplayer6_npc->cycle== 2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(poolplayer6_npc,poolplayer6_npc->walking_speed, 30*8,42*8)==1){poolplayer6_npc->cycle=4;poolplayer6_npc->vbl_timer=rand()%60;NPC_animate_set_direction_now(poolplayer6_npc,UP);}
		if(poolplayer6_npc->cycle== 3)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(poolplayer6_npc,poolplayer6_npc->walking_speed, 34*8,39*8)==1){poolplayer6_npc->cycle=4;poolplayer6_npc->vbl_timer=rand()%60;NPC_animate_set_direction_now(poolplayer6_npc,LEFT);}

		if(poolplayer6_npc->cycle== 4)if(poolplayer6_npc->vbl_timer>150){poolplayer6_npc->vbl_timer=0;poolplayer6_npc->cycle=5;}//TODO: ball animation and crack sound
		if(poolplayer6_npc->cycle== 5)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(poolplayer6_npc,poolplayer6_npc->walking_speed, 30*8,31*8)==1){poolplayer6_npc->cycle=6;poolplayer6_npc->vbl_timer=rand()%60;NPC_animate_set_direction_now(poolplayer6_npc,DOWN);}
		if(poolplayer6_npc->cycle== 6){poolplayer6_npc->vbl_timer=0;poolplayer5_npc->cycle=rand()%4;poolplayer6_npc->cycle=7;}
	}

*/
