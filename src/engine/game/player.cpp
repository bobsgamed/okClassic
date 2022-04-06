

#include "../../main.h"
//#include "player.h"

int YUU_WALKING_SPEED=SPEED_FAST;
int YUU_RUNNING_SPEED=SPEED_FASTEST;
int YUU_STANDING_SPEED=SPEED_SLOWER;


bool GLOBAL_no_sprite_buttons_pressed=1;
bool GLOBAL_main_sprite_standing=1;

bool GLOBAL_main_sprite_input_off=0;
bool GLOBAL_main_sprite_actions_off=0;
bool GLOBAL_main_sprite_fx_off=0;

bool GLOBAL_camera_fx_bounds_off=0;


int clicktarget_sprite_on=1;

int yuu_is_dead=0;

//=========================================================================================================================
void PLAYER_play_footstep()
{//=========================================================================================================================

		static int last_vbl=0;

		if(last_vbl!=vbl_var)
		{
			last_vbl=vbl_var;
			if(((vbl_var%20==0&&PLAYER_npc->walking_speed>SPEED_FASTER)||(vbl_var%15==0&&PLAYER_npc->walking_speed<=SPEED_FASTER))&&GLOBAL_text_engine_state==0)
			HARDWARE_play_sound("footstep",127,40000+r(10000),0);
		}

}


//=========================================================================================================================
void PLAYER_init()
{//=========================================================================================================================


	//=====================================================


	//512 is 50% size,256 is 100% size
	//HARDWARE_create_rotation_set(0,512,512); //50%// FOR NPCS ON THE BOTTOM SCREEN
	//HARDWARE_create_rotation_set(2,384,384); //75% //FOR CARS ON THE BOTTOM SCREEN
	//HARDWARE_create_rotation_set(3,256,256); //100% //FOR TRANSPARENT ON BOTTOM SCREEN

	//HARDWARE_create_rotation_set(1,192,192); //150% //FOR CARS ON THE TOP SCREEN
	//HARDWARE_create_rotation_set(2,128,128); //200% // FOR LETTERBOX ON TOP SCREEN
	//HARDWARE_create_rotation_set(3,128,128); //200% //FOR TEXT SPRITE WINDOW ON BOTTOM SCREEN

	//==============================================================================


	NPC_init_npc_vars(&PLAYER_npc,GFX_KID_yuu,16,32,GAME_VIEWPORT_WIDTH_PIXELS/2-8,GAME_VIEWPORT_HEIGHT_PIXELS/2+16);

	NPC**mspp = &PLAYER_npc;
	PLAYER_npc->npcpp = (struct NPC**)mspp;

	PLAYER_npc->hitsize_x = 16;
	PLAYER_npc->hitsize_y = 6;

	NPC_set_screen_xy(&PLAYER_npc);

	first_NPC = PLAYER_npc;

	//PLAYER_npc->sprite = HARDWARE_create_sprite(PLAYER_npc->gfx,PLAYER_npc->gfx_index,PLAYER_npc->layer,PLAYER_npc->scale,PLAYER_npc->screen_x,PLAYER_npc->screen_y,255);

	//PLAYER_npc->gfx_slot = HARDWARE_create_sprite_gfxslot(1,PLAYER_npc->gfx_struct,PLAYER_npc->size_x*PLAYER_npc->size_y*4*PLAYER_npc->anim_direction,PLAYER_npc->data_size_x,PLAYER_npc->data_size_y,1, PLAYER_npc->shadow);
	//HARDWARE_create_sprite(1,PLAYER_npc->PLAYER_id,PLAYER_npc->gfx_slot,PLAYER_npc->data_size_x,PLAYER_npc->data_size_y,1,0,0,0,0,0,2,0,PLAYER_npc->screen_x,PLAYER_npc->screen_y);


	//==============================================================================
	//clicktarget->PLAYER_id=CLICKTARGET_ID;
	//clicktarget->PLAYER_id_touchmap=CLICKTARGET_ID;
	//clicktarget->size_x=8;
	//clicktarget->size_y=8;
	//clicktarget->hitsize_y=0;

	//clicktarget->gfx_struct= click_GFX;
	//clicktarget->gfx_slot = HARDWARE_create_sprite_gfxslot(1,clicktarget->gfx_struct,0,8,8,1,0);
	//NPC_set_screen_xy(&clicktarget);
	//HARDWARE_create_sprite(1,clicktarget->PLAYER_id,clicktarget->gfx_slot,8,8,1,0,1,0,0,0,2,0,clicktarget->screen_x,clicktarget->screen_y);
	//HARDWARE_set_sprite_alpha(1,clicktarget->PLAYER_id,1);
	//clicktarget->gfx_slot_touchmap = HARDWARE_create_sprite_gfxslot(0,clicktarget->gfx_struct,0,8,8,1,0);
	//HARDWARE_create_sprite(0,clicktarget->PLAYER_id_touchmap,clicktarget->gfx_slot_touchmap,8,8,1,0,0,0,0,0,2,0,clicktarget->screen_x_touchmap,clicktarget->screen_y_touchmap);
	//HARDWARE_set_sprite_rotation(0,clicktarget->PLAYER_id_touchmap,0);
	//HARDWARE_set_sprite_alpha(0,clicktarget->PLAYER_id_touchmap,1);

	//clicktarget=NULL;

	//==============================================================================
	cameraman->MAP_x = PLAYER_npc->MAP_x + PLAYER_npc->size_x/2;
	cameraman->MAP_y = PLAYER_npc->MAP_y + PLAYER_npc->size_y/2;
	cameraman->walking_speed=1;

	dummy_camera_target->MAP_x=0;
	dummy_camera_target->MAP_y=0;
	dummy_camera_target->size_x=0;
	dummy_camera_target->size_y=0;

	cameraman_target=PLAYER_npc;
	//==============================================================================

}

//=========================================================================================================================
int distance( int x1, int y1, int x2, int y2 )
{//=========================================================================================================================

	//Return the distance between the two points
	return (int)sqrt( pow( x2 - x1, 2 ) + pow( y2 - y1, 2 ) );
}



//=========================================================================================================================
void PLAYER_main()
{//=========================================================================================================================

	//if(!PLAYER_actions_off&&PLAYER_npc!=NULL){PLAYER_check_action(facing_direction);} //action layer bye
	if(!GLOBAL_main_sprite_fx_off&&PLAYER_npc!=NULL)PLAYER_check_fx_layer();

	//if touchmap clicked
	//find point on map
	//if tile is hit detection dont walk
	//if tile is outside map dont walk
	//else if(GLOBAL_no_sprite_buttons_pressed and no stylus input)make npc(icon) follow npc

	if(PLAYER_npc!=NULL&&GLOBAL_text_engine_state==0)
	{


		if(yuu_is_dead==1)
		{
			yuu_is_dead=2;
			//CAPTION_make_caption(NULL,1,80,80,5,"Yuu is dead.",FONT_BOB_ID,RED,BLACK);
			CAPTION_make_caption(NULL,1,80,80,5,"Hit by car.",FONT_BOB_ID,RED,BLACK,1,1);

			//invert palette
			int	c=0;
			for(c=0;c<256;c++) GAME_temp_TILESET_PALETTE[c]=~HARDWARE_map_palette[c];
			HARDWARE_load_bg_palette((int*)&GAME_temp_TILESET_PALETTE);

			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			//text_window("<NOCANCEL>It seems that Yuu has met his untimely demise.<.>Don't get killed, idiot.");
			TEXT_window("<NOCANCEL>Main character has died.");

		}

		if(yuu_is_dead==2)
		{
			if(GLOBAL_text_engine_state==0)
			{
				yuu_is_dead=0;
				load_bg_pals_based_on_time();
			}
			//shake screen
			//start screen TIMES DIED COUNT like it means something :) SPECIAL ENDING LOST
			//animate yuu laying on the ground
			//maybe have bloody death flag?
			//reset to room "it was all a dream?"
			//ds turn off?
			//mr cart tell at you?
			//wake up in morgue "sweet mother of bob!!please dont sue us"
			//youre grounded,mister.. dont you ever dare awaken from the dead again
			//if die enough times ambulance "this kid again.. should we even take him to the morgue? nah he'll wake up. but his brains.. yeah it was like that last time too. doesnt seem to make a difference *shrug* or maybe thats why he keeps getting killed"
		}


		//if(TouchScreen.Held)
		//{


			//int clickx=0;
			//int clicky=0;

			//int clickmapx=-1;
			//int clickmapy=-1;

			//clickx=TouchScreen.X;
			//clicky=TouchScreen.Y;

			//while(TouchScreen.Held&&MAIN_QUIT==false)whilefix();



			/*

			if(touchmap_cam_x<0) //whole map is onscreen,centered,since touchmap_cam never goes beyond the borders
			{
				if(clickx>touchmap_cam_x+((GAME_VIEWPORT_WIDTH_PIXELS-MAP_fx_border_width/2))&&clickx<touchmap_cam_x+((GAME_VIEWPORT_WIDTH_PIXELS-MAP_fx_border_width/2))+MAP_fx_border_width/2)
				clickmapx=clickx*2+touchmap_cam_x*2-4;
			}
			if(touchmap_cam_y<0) //whole map is onscreen,centered,since touchmap_cam never goes beyond the borders
			{
				if(clicky>touchmap_cam_y+((GAME_VIEWPORT_HEIGHT_PIXELS-MAP_fx_border_height/2))&&clicky<touchmap_cam_y+((GAME_VIEWPORT_HEIGHT_PIXELS-MAP_fx_border_height/2))+MAP_fx_border_height/2)
				clickmapy=clicky*2+touchmap_cam_y*2-4;
			}
			if(touchmap_cam_x>=0)clickmapx=touchmap_cam_x*2+clickx*2-4;
			if(touchmap_cam_y>=0)clickmapy=touchmap_cam_y*2+clicky*2-4;

			*///iphone hack


			//iphone hack

/*
			clickmapx=MAP_cam_x+clickx-4;
			clickmapy=MAP_cam_y+clicky-4;



			//end iphone hack



			if(clicktarget==NULL||(clicktarget!=NULL&&(clickmapx<=clicktarget->MAP_x-8||clickmapx>=clicktarget->MAP_x+8||clickmapy<=clicktarget->MAP_y-8||clickmapy>=clicktarget->MAP_y+8)))
			{
				if(clickmapx!=-1&&clickmapy!=-1
					&&!GLOBAL_main_sprite_input_off
					//&&!HARDWARE_map_hit_layer[(((clickmapy+4)/8)*HARDWARE_map_width)+((clickmapx+4)/8)]
					&&!(clickmapy+4>=HARDWARE_map_height_tiles*8-8)
					&&!(clickmapx+4>=HARDWARE_map_width_tiles*8-8)
					&&!(clickmapy+4<=0+8)
					&&!(clickmapx+4<=0+8))
				{
					if(clicktarget!=NULL)
					{
						NPC_stop_chasing(&PLAYER_npc);
						clicktarget->MAP_x=clickmapx;
						clicktarget->MAP_y=clickmapy;

					}//NPC_delete_npc(&clicktarget);NPC_stop_chasing(&PLAYER_npc);}

					if(clicktarget==NULL)
					{
						clicktarget = &clicktarget_npc;
						clicktarget->MAP_x=clickmapx;
						clicktarget->MAP_y=clickmapy;
						GLOBAL_main_sprite_actions_off=1;

						NPC_set_screen_xy(&clicktarget);
						if(clicktarget_sprite_on)HARDWARE_create_sprite(1,clicktarget->PLAYER_id,clicktarget->gfx_slot,8,8,1,0,1,0,0,0,2,0,clicktarget->screen_x,clicktarget->screen_y);
						if(clicktarget_sprite_on)HARDWARE_set_sprite_alpha(1,clicktarget->PLAYER_id,159);

						if(clicktarget_sprite_on)HARDWARE_create_sprite(0,clicktarget->PLAYER_id_touchmap,clicktarget->gfx_slot_touchmap,8,8,1,0,0,0,0,0,2,0,clicktarget->screen_x_touchmap,clicktarget->screen_y_touchmap);
						if(clicktarget_sprite_on)HARDWARE_set_sprite_rotation(0,clicktarget->PLAYER_id_touchmap,0);
						if(clicktarget_sprite_on)HARDWARE_set_sprite_alpha(0,clicktarget->PLAYER_id_touchmap,159);
					}

					//if its a hit tile, color cursor red
					if(!HARDWARE_map_hit_layer[(((clickmapy+4)/8)*HARDWARE_map_width_tiles)+((clickmapx+4)/8)])
					{
						HARDWARE_update_sprite_texture(0,clicktarget->gfx_slot,clicktarget->gfx_struct,8*8*0,0);
						HARDWARE_update_sprite_texture(1,clicktarget->gfx_slot,clicktarget->gfx_struct,8*8*0,0);

					}
					else
					{
						HARDWARE_update_sprite_texture(0,clicktarget->gfx_slot,clicktarget->gfx_struct,8*8*1,0);
						HARDWARE_update_sprite_texture(1,clicktarget->gfx_slot,clicktarget->gfx_struct,8*8*1,0);
					}


				}
			}
		}
		if(clicktarget!=NULL)
		{
			{

				bool there_yet = 0;
				if(HARDWARE_map_hit_layer[(((clicktarget->MAP_y+4)/8)*HARDWARE_map_width_tiles)+((clicktarget->MAP_x+4)/8)])
				there_yet = PLAYER_walk_to_xy_basichit(clicktarget->MAP_x+clicktarget->size_x/2,clicktarget->MAP_y+clicktarget->size_y-(clicktarget->hitsize_y));
				//there_yet = NPC_walk_straight_to_point(&PLAYER_npc,PLAYER_npc->walking_speed,clicktarget->MAP_x-PLAYER_npc->size_x/4,clicktarget->MAP_y-PLAYER_npc->size_y/2-8);
				else
				there_yet = NPC_chase_npc(&PLAYER_npc,clicktarget);

				NPC_set_screen_xy(&clicktarget);
				if(clicktarget_sprite_on)HARDWARE_set_sprite_xy(1,clicktarget->PLAYER_id,clicktarget->screen_x,clicktarget->screen_y);
				if(clicktarget_sprite_on)HARDWARE_set_sprite_xy(0,clicktarget->PLAYER_id_touchmap,clicktarget->screen_x_touchmap,clicktarget->screen_y_touchmap);

				static int last_footstep_x=0;
				static int last_footstep_y=0;


				//=================================footsteps
				if(last_footstep_x!=PLAYER_npc->MAP_x||last_footstep_y!=PLAYER_npc->MAP_y)
				PLAYER_play_footstep();

				last_footstep_x=PLAYER_npc->MAP_x;
				last_footstep_y=PLAYER_npc->MAP_y;



				if(NPC_in_range_of_npc_amt(&PLAYER_npc,clicktarget,8*4))GLOBAL_main_sprite_actions_off=0;
				else GLOBAL_main_sprite_actions_off=1;

				if(GLOBAL_no_sprite_buttons_pressed==0||there_yet==1||GLOBAL_main_sprite_input_off==1||GLOBAL_text_engine_state!=0)
				{
					NPC_stop_chasing(&PLAYER_npc);
					//delete clicktarget gfx/sprite
					if(clicktarget_sprite_on)HARDWARE_delete_sprite(1,clicktarget->PLAYER_id);
					if(clicktarget_sprite_on)HARDWARE_delete_sprite(0,clicktarget->PLAYER_id_touchmap);

					clicktarget=NULL;
					GLOBAL_main_sprite_actions_off=0;
				}
			}
		}*/
	}






	if(PLAYER_npc!=NULL)
	{
		//=======================walking acceleration,checking for dir change
		//bool direction_changed=0;
		int resetcam=0;

		/*if(cameraman->anim_direction!=PLAYER_npc->walking_direction)
		{
			if(PLAYER_npc->walking_direction==DOWN
			||PLAYER_npc->walking_direction==UP
			||PLAYER_npc->walking_direction==LEFT
			||PLAYER_npc->walking_direction==RIGHT)
			{
				cameraman->anim_direction=PLAYER_npc->walking_direction;
				resetcam=1;//dont stop camera for diagonals, only for main directions.
			}

			//direction_changed=1;//but slow down sprite for direction change.
			//PLAYER_npc->walking_speed=SPEED_NORMAL-8;
		}*/






		//====================if stopped walking,set walking acceleration back to 0,else if walking and isnt max speed,accelerate


		if(GLOBAL_npcs_pulling_main_sprite>0){PLAYER_npc->walking_speed=SPEED_SLOW+(GLOBAL_npcs_pulling_main_sprite*20);}
		else
			if(BUTTON_R_HELD||BUTTON_B_HELD)
			{
				PLAYER_npc->walking_speed=YUU_RUNNING_SPEED;
				if(PLAYER_npc->gfx==GFX_KID_yuu)PLAYER_npc->gfx=GFX_KID_yuurunning;
				else if(PLAYER_npc->gfx==GFX_KID_youngyuu)PLAYER_npc->gfx=GFX_KID_youngyuurunning;
				if(cameraman->walking_speed>PLAYER_npc->walking_speed)cameraman->walking_speed=PLAYER_npc->walking_speed;
			}

		//=================================actual sprite movement,depending on if r is pressed or not=====================


		GLOBAL_no_sprite_buttons_pressed=0;

		if(GLOBAL_main_sprite_input_off==0&&GLOBAL_text_engine_state==0)
		{
			if(BUTTON_DOWN_HELD&&BUTTON_LEFT_HELD)		 PLAYER_check_hit_move_pixel_animate(DOWNLEFT);
			else if(BUTTON_DOWN_HELD&&BUTTON_RIGHT_HELD) PLAYER_check_hit_move_pixel_animate(DOWNRIGHT);
			else if(BUTTON_UP_HELD&&BUTTON_LEFT_HELD)	 PLAYER_check_hit_move_pixel_animate(UPLEFT);
			else if(BUTTON_UP_HELD&&BUTTON_RIGHT_HELD)	 PLAYER_check_hit_move_pixel_animate(UPRIGHT);
			else if(BUTTON_RIGHT_HELD)					 PLAYER_check_hit_move_pixel_animate(RIGHT);
			else if(BUTTON_LEFT_HELD)					 PLAYER_check_hit_move_pixel_animate(LEFT);
			else if(BUTTON_DOWN_HELD)					 PLAYER_check_hit_move_pixel_animate(DOWN);
			else if(BUTTON_UP_HELD)						 PLAYER_check_hit_move_pixel_animate(UP);
			else GLOBAL_no_sprite_buttons_pressed=1;

			if(GLOBAL_no_sprite_buttons_pressed==1)GLOBAL_main_sprite_standing=1;
		}


		if((GLOBAL_main_sprite_standing==1))//&&clicktarget==NULL)
		{

			//==========================sprite is standing, reset walk speed, back to walking graphics==================
			PLAYER_npc->walking_speed=YUU_STANDING_SPEED;
			if(PLAYER_npc->gfx==GFX_KID_yuurunning)PLAYER_npc->gfx=GFX_KID_yuu;
			else if(PLAYER_npc->gfx==GFX_KID_youngyuurunning)PLAYER_npc->gfx=GFX_KID_youngyuu;


			//=======================animate to first frame==================================================
			if(PLAYER_npc->walk_dir!=PLAYER_npc->anim_dir)PLAYER_animate_turn_if_needed();
			else
			{
				NPC_animate_stand_dir(&PLAYER_npc,PLAYER_npc->anim_dir);
				PLAYER_npc->vbl_animation_timer=30;
			}
		}
		else
		{

			//=========================sprite is walking, accelerate to max speed==========================
			static int last_vbl=0;
			if(last_vbl!=vbl_var)
			{
				last_vbl=vbl_var;
				//if(vbl_var%5==0&&
					if(PLAYER_npc->walking_speed>YUU_WALKING_SPEED)PLAYER_npc->walking_speed-=SPEED_ACCEL_INCREMENT_AMOUNT;
			}

			//=============footsteps==========
			PLAYER_play_footstep();
		}




		//=============FIND BOUNDARY TARGETS,CENTER OF THE ROOM IF THE ROOM WILL FIT ONSCREEN,ELSE HALF A SCREEN AWAY FROM THE NEAREST BOUNDARY
		int topbounds=-1;
		int bottombounds=-1;
		int leftbounds=-1;
		int rightbounds=-1;
		int camstop_tile=4;

		int xtarget=-1;
		int ytarget=-1;

		static int lastxtarget=-1;
		static int lastytarget=-1;


		for(xtarget=(cameraman_target->MAP_x+cameraman_target->size_x/2)/8;xtarget>=0&&xtarget>=((cameraman_target->MAP_x+cameraman_target->size_x/2)/8)-(SCREEN_WIDTH_TILES);xtarget--)
			if(HARDWARE_map_fx_layer[xtarget+(((cameraman_target->MAP_y+cameraman_target->size_y/2)/8)*HARDWARE_map_width_tiles)]==camstop_tile){ leftbounds=(xtarget+1)*8; break;}


		for(xtarget=(cameraman_target->MAP_x+cameraman_target->size_x/2)/8;xtarget<=HARDWARE_map_width_tiles&&xtarget<=((cameraman_target->MAP_x+cameraman_target->size_x/2)/8)+(SCREEN_WIDTH_TILES);xtarget++)
			if(HARDWARE_map_fx_layer[xtarget+(((cameraman_target->MAP_y+cameraman_target->size_y/2)/8)*HARDWARE_map_width_tiles)]==camstop_tile){ rightbounds=xtarget*8; break;}
		xtarget=-1;
		if(leftbounds!=-1||rightbounds!=-1)
			{
				if(leftbounds!=-1&&rightbounds!=-1&&rightbounds-leftbounds<=GAME_VIEWPORT_WIDTH_PIXELS)xtarget=(leftbounds+((rightbounds-leftbounds)/2));
					else if(leftbounds!=-1&&(cameraman_target->MAP_x+cameraman_target->size_x/2)<=leftbounds+GAME_VIEWPORT_WIDTH_PIXELS/2)xtarget=(leftbounds+GAME_VIEWPORT_WIDTH_PIXELS/2);
						else if(rightbounds!=-1&&(cameraman_target->MAP_x+cameraman_target->size_x/2)>=rightbounds-GAME_VIEWPORT_WIDTH_PIXELS/2)xtarget=(rightbounds-GAME_VIEWPORT_WIDTH_PIXELS/2);

			}

		for(ytarget=(cameraman_target->MAP_y+cameraman_target->size_y/2)/8;ytarget>=0&&ytarget>=((cameraman_target->MAP_y+cameraman_target->size_y/2)/8)-(SCREEN_HEIGHT_TILES);ytarget--)
			if(HARDWARE_map_fx_layer[(cameraman_target->MAP_x+cameraman_target->size_x/2)/8+(ytarget*HARDWARE_map_width_tiles)]==camstop_tile){ topbounds=(ytarget+1)*8; break;}
		for(ytarget=(cameraman_target->MAP_y+cameraman_target->size_y/2)/8;ytarget<HARDWARE_map_height_tiles&&ytarget<=((cameraman_target->MAP_y+cameraman_target->size_y/2)/8)+(SCREEN_HEIGHT_TILES);ytarget++)
			if(HARDWARE_map_fx_layer[(cameraman_target->MAP_x+cameraman_target->size_x/2)/8+(ytarget*HARDWARE_map_width_tiles)]==camstop_tile){bottombounds=ytarget*8; break;}
		ytarget=-1;
		if(topbounds!=-1||bottombounds!=-1)
		{
			if(topbounds!=-1&&bottombounds!=-1&&bottombounds-topbounds<=GAME_VIEWPORT_HEIGHT_PIXELS)ytarget=(topbounds+((bottombounds-topbounds)/2));
				else if(topbounds!=-1&&(cameraman_target->MAP_y+cameraman_target->size_y/2)<=topbounds+GAME_VIEWPORT_HEIGHT_PIXELS/2)ytarget=(topbounds+GAME_VIEWPORT_HEIGHT_PIXELS/2);
					else if(bottombounds!=-1&&(cameraman_target->MAP_y+cameraman_target->size_y/2)>=bottombounds-GAME_VIEWPORT_HEIGHT_PIXELS/2)ytarget=(bottombounds-GAME_VIEWPORT_HEIGHT_PIXELS/2);

		}


		if((xtarget==-1&&lastxtarget!=-1)||(ytarget==-1&&lastytarget!=-1))resetcam=1;//dont keep resetting the camera if you're walking next to a boundary. only when entering or leaving a boundary.

		lastxtarget=xtarget;
		lastytarget=ytarget;

		if(xtarget==-1||GLOBAL_camera_fx_bounds_off==1)xtarget=cameraman_target->MAP_x+cameraman_target->size_x/2;
		if(ytarget==-1||GLOBAL_camera_fx_bounds_off==1)ytarget=cameraman_target->MAP_y+cameraman_target->size_y/2;




		//find distance x
		//find distance y
		int ydistance=0;
		int xdistance=0;
		if(cameraman->MAP_y>ytarget)ydistance=cameraman->MAP_y-ytarget;
		if(cameraman->MAP_y<ytarget)ydistance=ytarget-cameraman->MAP_y;

		if(cameraman->MAP_x>xtarget)xdistance=cameraman->MAP_x-xtarget;
		if(cameraman->MAP_x<xtarget)xdistance=xtarget-cameraman->MAP_x;


		//decide camera acceleration based on distance from yuu
		int accelspeed=2;
		int dist = distance(cameraman->MAP_x,cameraman->MAP_y,xtarget,ytarget);
		if(dist<0)dist*=-1;
		if(dist>0)accelspeed=(GAME_VIEWPORT_HEIGHT_PIXELS/8)/dist;

		//=======================cameraman acceleration,depending on if r is pressed or not==============================
		if(cameraman->vbls>accelspeed)//>accel speed
		{

			/*
			//============================slow down the camera gradually if the sprite isnt moving, and it's within a quarter screen of the sprite.
			if(GLOBAL_main_sprite_standing&&GLOBAL_text_engine_state==0&&xdistance<=GAME_VIEWPORT_WIDTH_PIXELS/4&&ydistance<=GAME_VIEWPORT_HEIGHT_PIXELS/4)
			{
				if(cameraman->walking_speed<SPEED_SLOWEST)cameraman->walking_speed+=SPEED_ACCEL_INCREMENT_AMOUNT;
				cameraman->vbl_timer=0;
			}
			*/


			//=======================if the camera is slower than yuu, speed up.=======================
			if(cameraman->walking_speed>PLAYER_npc->walking_speed-(SPEED_ACCEL_INCREMENT_AMOUNT))
			{
				cameraman->walking_speed-=SPEED_ACCEL_INCREMENT_AMOUNT;
				cameraman->walk_dir=PLAYER_npc->walk_dir;//uses this below so the camera resets itself if PLAYER_npc turns around and hits xy going opp dir
				cameraman->vbls=0;
			}

		}



		//=================================
		//if the cameraman has reached target,either keep up with the sprite at the sprite's speed (hardcam),
		//or if the sprite is stopped set the camera speed back to 0 so it can be soft again
		//=================================
		if(cameraman->MAP_x==xtarget&&cameraman->MAP_y==ytarget)//its keeping up with the sprite
		{
			{
				if(GLOBAL_no_sprite_buttons_pressed||
					(cameraman->walk_dir==UP&&PLAYER_npc->walk_dir==DOWN)|| //so turning around doesnt make the camera instantly go fullspeed
					(cameraman->walk_dir==DOWN&&PLAYER_npc->walk_dir==UP)|| //so turning around doesnt make the camera instantly go fullspeed
					(cameraman->walk_dir==LEFT&&PLAYER_npc->walk_dir==RIGHT)|| //so turning around doesnt make the camera instantly go fullspeed
					(cameraman->walk_dir==RIGHT&&PLAYER_npc->walk_dir==LEFT)|| //so turning around doesnt make the camera instantly go fullspeed
					resetcam==1
					//(xtarget!=cameraman_target->MAP_x+cameraman_target->size_x/2)||
					//(ytarget!=cameraman_target->MAP_y+cameraman_target->size_y/2)//so coming out of a boundary doesnt already have the cam accelerated
					)
					cameraman->walking_speed=SPEED_CAMERA_STOPPED;
					else cameraman->walking_speed=PLAYER_npc->walking_speed;
			}
			cameraman->vbls=0;
		}



		//=======================camera speed should be very fast for conversations=======================
		if(GLOBAL_text_engine_state!=0)cameraman->walking_speed=SPEED_CAMERA_CONVERSATION;



//variables
//camera fixed to sprite always
//camera acceleration speed
//camera starting speed
//camera slowdown while sprite is standing




		//=================================actual cameraman movement
		if(cameraman->ms>cameraman->walking_speed)
		{
			cameraman->ms=0;

			//if distance x>y only walk that way
			//if distance y>x only walk that way
			//if equal walk both

			int x_to_y_ratio=0;//xdistance/ydistance;
			int y_to_x_ratio=0;//ydistance/xdistance;

			if(ydistance>0)x_to_y_ratio=xdistance/ydistance;
			if(xdistance>0)y_to_x_ratio=ydistance/xdistance;


			static int xcounter=0;
			static int ycounter=0;


			if(xdistance>=ydistance||y_to_x_ratio<ycounter)
			{
				if(cameraman->MAP_x>xtarget)cameraman->MAP_x--;
				if(cameraman->MAP_x<xtarget)cameraman->MAP_x++;
				xcounter++;
				ycounter=0;
			}

			if(ydistance>=xdistance||x_to_y_ratio<xcounter)
			{
				if(cameraman->MAP_y>ytarget)cameraman->MAP_y--;
				if(cameraman->MAP_y<ytarget)cameraman->MAP_y++;
				ycounter++;
				xcounter=0;
			}

		}
	}

}

//=========================================================================================================================
void PLAYER_vbl()
{//=========================================================================================================================

	cameraman->vbls++;

	{//============here we are automatically making main sprite stand after half a second, and also turning off footstep sound.
		static int last_map_x=0;
		static int last_map_y=0;
		static int vbls_since_moved=0;

		if(last_map_x!=PLAYER_npc->MAP_x||last_map_y!=PLAYER_npc->MAP_y)
		{
			last_map_x=PLAYER_npc->MAP_x;
			last_map_y=PLAYER_npc->MAP_y;

			vbls_since_moved=0;
			GLOBAL_main_sprite_standing=0;
		}
		else vbls_since_moved++;

		if(vbls_since_moved>10)GLOBAL_main_sprite_standing=1;
	}

}
//=========================================================================================================================
bool PLAYER_check_hit_xy(int x,int y)
{//=========================================================================================================================
	int index;
	if(y>=HARDWARE_map_height_tiles*8||x>=HARDWARE_map_width_tiles*8||y<0||x<0)
	return 1;
	else
	index = ((y/8)*HARDWARE_map_width_tiles) + (x/8);

	return HARDWARE_map_hit_layer[index];
}

//=========================================================================================================================
bool walking_into_door(int x,int y,int x2,int y2)
{//=========================================================================================================================

	bool detected=0;

	if(GLOBAL_main_sprite_actions_off==0)
	{
		int dir = PLAYER_npc->walk_dir;

		NPC* npc = PLAYER_npc;

		int px=(npc->MAP_x+(npc->size_x/2));
		int py=(npc->MAP_y+(npc->size_y-(npc->hitsize_y/2)));

		if(dir==UP)
		{
			py=(npc->MAP_y+(npc->size_y-npc->hitsize_y))-1;
		}
		if(dir==DOWN)
		{
			py=npc->MAP_y+npc->size_y+1;
		}
		if(dir==LEFT)
		{
			px=npc->MAP_x-1;
		}
		if(dir==RIGHT)
		{
			px=npc->MAP_x+npc->size_x+1;
		}

		if(dir==UPLEFT)
		{
			px=npc->MAP_x-1;
			py=(npc->MAP_y+(npc->size_y-npc->hitsize_y))-1;
		}
		if(dir==UPRIGHT)
		{
			px=npc->MAP_x+npc->size_x+1;
			py=(npc->MAP_y+(npc->size_y-npc->hitsize_y))-1;
		}
		if(dir==DOWNLEFT)
		{
			px=npc->MAP_x-1;
			py=npc->MAP_y+npc->size_y+1;
		}
		if(dir==DOWNRIGHT)
		{
			px=npc->MAP_x+npc->size_x+1;
			py=npc->MAP_y+npc->size_y+1;
		}

		if(px>=x&&px<x2&&py>=y&&py<y2)detected=1;
	}

	return detected;

}

//=========================================================================================================================
void PLAYER_check_fx_layer()
{//=========================================================================================================================

static int under2=2,over1=1;	//+ under 0...tiles in the tileset.. i should standardize this,though it wastes valuable tiles :( maybe i can standardize them.. elsewhere :O 1025 1026 1027?

	if(
		(HARDWARE_map_fx_layer[((((PLAYER_npc->MAP_y+PLAYER_npc->size_y-2	)/8)*HARDWARE_map_width_tiles)+((PLAYER_npc->MAP_x+2	)/8))]==under2 ||
		HARDWARE_map_fx_layer[((((PLAYER_npc->MAP_y+PLAYER_npc->size_y-2	)/8)*HARDWARE_map_width_tiles)+((PLAYER_npc->MAP_x+PLAYER_npc->size_x-2)/8))]==under2 ||
		HARDWARE_map_fx_layer[((((PLAYER_npc->MAP_y+PLAYER_npc->size_y-8+2)/8)*HARDWARE_map_width_tiles)+((PLAYER_npc->MAP_x+2	)/8))]==under2 ||
		HARDWARE_map_fx_layer[((((PLAYER_npc->MAP_y+PLAYER_npc->size_y-8+2)/8)*HARDWARE_map_width_tiles)+((PLAYER_npc->MAP_x+PLAYER_npc->size_x-2)/8))]==under2||
		HARDWARE_map_fx_layer[((((PLAYER_npc->MAP_y+PLAYER_npc->size_y-4)/8)*HARDWARE_map_width_tiles)+((PLAYER_npc->MAP_x+PLAYER_npc->size_x/2)/8))]==under2)
		)
	{
		if(PLAYER_npc->layer!=3)
		{
			PLAYER_npc->layer=3;
		}
	}
	else
	if(
	(HARDWARE_map_fx_layer[((((PLAYER_npc->MAP_y+PLAYER_npc->size_y-2	)/8)*HARDWARE_map_width_tiles)+((PLAYER_npc->MAP_x+2	)/8))]==over1 ||
	HARDWARE_map_fx_layer[((((PLAYER_npc->MAP_y+PLAYER_npc->size_y-2	)/8)*HARDWARE_map_width_tiles)+((PLAYER_npc->MAP_x+PLAYER_npc->size_x-2)/8))]==over1 ||
	HARDWARE_map_fx_layer[((((PLAYER_npc->MAP_y+PLAYER_npc->size_y+2-8)/8)*HARDWARE_map_width_tiles)+((PLAYER_npc->MAP_x+2	)/8))]==over1 ||
	HARDWARE_map_fx_layer[((((PLAYER_npc->MAP_y+PLAYER_npc->size_y+2-8)/8)*HARDWARE_map_width_tiles)+((PLAYER_npc->MAP_x+PLAYER_npc->size_x-2)/8))]==over1||
	HARDWARE_map_fx_layer[((((PLAYER_npc->MAP_y+PLAYER_npc->size_y-4)/8)*HARDWARE_map_width_tiles)+((PLAYER_npc->MAP_x+PLAYER_npc->size_x/2)/8))]==over1)
	)
	{
		if(PLAYER_npc->layer!=1)
		{
			PLAYER_npc->layer=1;

		}
	}
	else
	if(PLAYER_npc->layer!=2)
	{
		PLAYER_npc->layer=2;
	}
}

//=========================================================================================================================
bool PLAYER_check_hit_non_walkable_npcs(int dir)
{//=========================================================================================================================
	NPC *current_npc = PLAYER_npc;
	bool hitting_npc=0;

	while(current_npc->next!=NULL)
	{
	current_npc = (NPC *)current_npc->next;

	if(current_npc->non_walkable==1)
	{
		bool detected=0;

		if(dir==UP)
		{
			if(((PLAYER_npc->MAP_x+(PLAYER_npc->size_x/2))<(current_npc->MAP_x+current_npc->hitsize_x))&&
				((PLAYER_npc->MAP_x+(PLAYER_npc->size_x/2))>(current_npc->MAP_x))&&
				((PLAYER_npc->MAP_y+PLAYER_npc->size_y-(PLAYER_npc->hitsize_y+2))<=(current_npc->MAP_y+current_npc->size_y))&&
				((PLAYER_npc->MAP_y+PLAYER_npc->size_y-(PLAYER_npc->hitsize_y+2))>=(current_npc->MAP_y+current_npc->size_y-(current_npc->hitsize_y)))
				)detected=1;
		}
		else
			if(dir==DOWN)
			{
				if(((PLAYER_npc->MAP_x+(PLAYER_npc->size_x/2))<(current_npc->MAP_x+current_npc->hitsize_x))&&
				((PLAYER_npc->MAP_x+(PLAYER_npc->size_x/2))>(current_npc->MAP_x))&&
				((PLAYER_npc->MAP_y+PLAYER_npc->size_y)<=(current_npc->MAP_y+current_npc->size_y))&&
				((PLAYER_npc->MAP_y+PLAYER_npc->size_y)>=(current_npc->MAP_y+current_npc->size_y-(current_npc->hitsize_y)))
				)detected=1;
			}
			else
				if(dir==LEFT)
				{
				if(((PLAYER_npc->MAP_x+2)<(current_npc->MAP_x+current_npc->hitsize_x))&&
					((PLAYER_npc->MAP_x+2)>(current_npc->MAP_x))&&
					((PLAYER_npc->MAP_y+PLAYER_npc->size_y-4)<=(current_npc->MAP_y+current_npc->size_y))&&
					((PLAYER_npc->MAP_y+PLAYER_npc->size_y-4)>=(current_npc->MAP_y+current_npc->size_y-(current_npc->hitsize_y)))
				)detected=1;
				}
				else
					if(dir==RIGHT)
					{
					if(((PLAYER_npc->MAP_x+PLAYER_npc->size_x-2)<(current_npc->MAP_x+current_npc->hitsize_x))&&
						((PLAYER_npc->MAP_x+PLAYER_npc->size_x-2)>(current_npc->MAP_x))&&
						((PLAYER_npc->MAP_y+PLAYER_npc->size_y-4)<=(current_npc->MAP_y+current_npc->size_y))&&
						((PLAYER_npc->MAP_y+PLAYER_npc->size_y-4)>=(current_npc->MAP_y+current_npc->size_y-(current_npc->hitsize_y)))
					)detected=1;
					}
		if(detected==1)
		{
			hitting_npc=detected;
			if(current_npc->pushable==1)NPC_move_pixel(&current_npc,dir);
		}
	}
	}
	return hitting_npc;
}

//=========================================================================================================================
bool PLAYER_check_hit_layer(int dir)
{//=========================================================================================================================
	int hitting_wall=1;

	if(dir==UP)
	{
		if(	!PLAYER_check_hit_xy(PLAYER_npc->MAP_x+1,PLAYER_npc->MAP_y+PLAYER_npc->size_y-PLAYER_npc->hitsize_y)
			&& 	!PLAYER_check_hit_xy(PLAYER_npc->MAP_x+(PLAYER_npc->size_x/2)-1,PLAYER_npc->MAP_y+PLAYER_npc->size_y-PLAYER_npc->hitsize_y)
			&& 	!PLAYER_check_hit_xy(PLAYER_npc->MAP_x+(PLAYER_npc->size_x/2),PLAYER_npc->MAP_y+PLAYER_npc->size_y-PLAYER_npc->hitsize_y)
			&& 	!PLAYER_check_hit_xy(PLAYER_npc->MAP_x+PLAYER_npc->size_x-2,PLAYER_npc->MAP_y+PLAYER_npc->size_y-PLAYER_npc->hitsize_y)
				)
			hitting_wall=0;
	}
	else
	if(dir==DOWN)
	{
		if(	!PLAYER_check_hit_xy(PLAYER_npc->MAP_x+1,PLAYER_npc->MAP_y+PLAYER_npc->size_y)
			&& 	!PLAYER_check_hit_xy(PLAYER_npc->MAP_x+(PLAYER_npc->size_x/2)-1,PLAYER_npc->MAP_y+PLAYER_npc->size_y)
			&& 	!PLAYER_check_hit_xy(PLAYER_npc->MAP_x+(PLAYER_npc->size_x/2),PLAYER_npc->MAP_y+PLAYER_npc->size_y)
			&& 	!PLAYER_check_hit_xy(PLAYER_npc->MAP_x+PLAYER_npc->size_x-2,PLAYER_npc->MAP_y+PLAYER_npc->size_y)
				)
			hitting_wall=0;
	}
	else
	if(dir==LEFT)
	{
		if(	!PLAYER_check_hit_xy(PLAYER_npc->MAP_x,PLAYER_npc->MAP_y+PLAYER_npc->size_y-1)
			&& 	!PLAYER_check_hit_xy(PLAYER_npc->MAP_x,PLAYER_npc->MAP_y+PLAYER_npc->size_y-(PLAYER_npc->hitsize_y-2))
				)
			hitting_wall=0;
	}
	else
	if(dir==RIGHT)
	{
		if(	!PLAYER_check_hit_xy(PLAYER_npc->MAP_x+PLAYER_npc->size_x-1,PLAYER_npc->MAP_y+PLAYER_npc->size_y-1)
			&& 	!PLAYER_check_hit_xy(PLAYER_npc->MAP_x+PLAYER_npc->size_x-1,PLAYER_npc->MAP_y+PLAYER_npc->size_y-(PLAYER_npc->hitsize_y-2))
				)
			hitting_wall=0;
	}
	return hitting_wall;
}

//=========================================================================================================================
void PLAYER_animate_turn_if_needed()
{//=========================================================================================================================

	//sprite turning animation

	int wd=PLAYER_npc->walk_dir;
	int ad=PLAYER_npc->anim_dir;
	int nd=ad;

	if(wd!=ad)
	{
		if(wd==UP)
		{
			if(ad==UP){nd=UP;}
			else if(ad==DOWN){if(r(2)==0)nd=DOWNLEFT;else nd=DOWNRIGHT;}
			else if(ad==LEFT){nd=UPLEFT;}
			else if(ad==RIGHT){nd=UPRIGHT;}
			else if(ad==UPLEFT){nd=UP;}
			else if(ad==UPRIGHT){nd=UP;}
			else if(ad==DOWNLEFT){nd=LEFT;}
			else if(ad==DOWNRIGHT){nd=RIGHT;}
		}
		else if(wd==DOWN)
		{
			if(ad==UP){if(r(2)==0)nd=UPLEFT;else nd=UPRIGHT;}
			else if(ad==DOWN){nd=DOWN;}
			else if(ad==LEFT){nd=DOWNLEFT;}
			else if(ad==RIGHT){nd=DOWNRIGHT;}
			else if(ad==UPLEFT){nd=LEFT;}
			else if(ad==UPRIGHT){nd=RIGHT;}
			else if(ad==DOWNLEFT){nd=DOWN;}
			else if(ad==DOWNRIGHT){nd=DOWN;}
		}
		else if(wd==LEFT)
		{
			if(ad==UP){nd=UPLEFT;}
			else if(ad==DOWN){nd=DOWNLEFT;}
			else if(ad==LEFT){nd=LEFT;}
			else if(ad==RIGHT){if(r(2)==0)nd=UPRIGHT;else nd=DOWNRIGHT;}
			else if(ad==UPLEFT){nd=LEFT;}
			else if(ad==UPRIGHT){nd=UP;}
			else if(ad==DOWNLEFT){nd=LEFT;}
			else if(ad==DOWNRIGHT){nd=DOWN;}
		}
		else if(wd==RIGHT)
		{
			if(ad==UP){nd=UPRIGHT;}
			else if(ad==DOWN){nd=DOWNRIGHT;}
			else if(ad==LEFT){if(r(2)==0)nd=DOWNLEFT;else nd=UPLEFT;}
			else if(ad==RIGHT){nd=RIGHT;}
			else if(ad==UPLEFT){nd=UP;}
			else if(ad==UPRIGHT){nd=RIGHT;}
			else if(ad==DOWNLEFT){nd=DOWN;}
			else if(ad==DOWNRIGHT){nd=RIGHT;}
		}
		else if(wd==UPLEFT)
		{
			if(ad==UP){nd=UPLEFT;}
			else if(ad==DOWN){nd=DOWNLEFT;}
			else if(ad==LEFT){nd=UPLEFT;}
			else if(ad==RIGHT){nd=UPRIGHT;}
			else if(ad==UPLEFT){nd=UPLEFT;}
			else if(ad==UPRIGHT){nd=UP;}
			else if(ad==DOWNLEFT){nd=LEFT;}
			else if(ad==DOWNRIGHT){if(r(2)==0)nd=DOWN;else nd=RIGHT;}
		}
		else if(wd==UPRIGHT)
		{
			if(ad==UP){nd=UPRIGHT;}
			else if(ad==DOWN){nd=DOWNRIGHT;}
			else if(ad==LEFT){nd=UPLEFT;}
			else if(ad==RIGHT){nd=UPRIGHT;}
			else if(ad==UPLEFT){nd=UP;}
			else if(ad==UPRIGHT){nd=UPRIGHT;}
			else if(ad==DOWNLEFT){if(r(2)==0)nd=LEFT;else nd=DOWN;}
			else if(ad==DOWNRIGHT){nd=RIGHT;}
		}
		else if(wd==DOWNLEFT)
		{
			if(ad==UP){nd=UPLEFT;}
			else if(ad==DOWN){nd=DOWNLEFT;}
			else if(ad==LEFT){nd=DOWNLEFT;}
			else if(ad==RIGHT){nd=DOWNRIGHT;}
			else if(ad==UPLEFT){nd=LEFT;}
			else if(ad==UPRIGHT){if(r(2)==0)nd=UP;else nd=RIGHT;}
			else if(ad==DOWNLEFT){nd=DOWNLEFT;}
			else if(ad==DOWNRIGHT){nd=DOWN;}
		}
		else if(wd==DOWNRIGHT)
		{
			if(ad==UP){nd=UPRIGHT;}
			else if(ad==DOWN){nd=DOWNRIGHT;}
			else if(ad==LEFT){nd=DOWNLEFT;}
			else if(ad==RIGHT){nd=DOWNRIGHT;}
			else if(ad==UPLEFT){if(r(2)==0)nd=UP;else nd=LEFT;}
			else if(ad==UPRIGHT){nd=RIGHT;}
			else if(ad==DOWNLEFT){nd=DOWN;}
			else if(ad==DOWNRIGHT){nd=DOWNRIGHT;}
		}

	}

	if(PLAYER_npc->anim_dir!=nd)
	{
		if(PLAYER_npc->vbl_animation_timer>5)if(GLOBAL_npc_all_animation_off==0&&PLAYER_npc->animation_off==0)NPC_animate_stand_dir(&PLAYER_npc,nd);
	}
	else
	if(NPC_should_animate(&PLAYER_npc))
	{
		NPC_animate_dir(&PLAYER_npc,nd);
	}

}

//=========================================================================================================================
void PLAYER_move_pixel_animate_turn(int dir)
{//=========================================================================================================================
	NPC_move_pixel(&PLAYER_npc,dir);
	PLAYER_animate_turn_if_needed();

}
//=========================================================================================================================
void PLAYER_check_hit_move_pixel_animate(int dir)
{//=========================================================================================================================


	int speed = PLAYER_npc->walking_speed;

	if(dir==DOWNLEFT||dir==DOWNRIGHT||dir==UPLEFT||dir==UPRIGHT)speed=(int)(((float)speed)*1.5f);//speed is cut in half for diagonals

	if(PLAYER_npc->ms>speed)
	{
		int success=1;


		PLAYER_npc->ms=0;

		if(dir==DOWNLEFT)
		{
			int down=0;
			int left=0;

			if(PLAYER_npc->MAP_x>0)
				if(PLAYER_check_hit_layer(LEFT)==0)
					if(PLAYER_check_hit_non_walkable_npcs(LEFT)==0)left=1;

			if(PLAYER_npc->MAP_y+PLAYER_npc->size_y<(HARDWARE_map_height_tiles*8))
				if(PLAYER_check_hit_layer(DOWN)==0)
					if(PLAYER_check_hit_non_walkable_npcs(DOWN)==0)down=1;

			if(down==1&&left==1)PLAYER_move_pixel_animate_turn(DOWNLEFT);
			else if(down==1)PLAYER_move_pixel_animate_turn(DOWN);
			else if(left==1)PLAYER_move_pixel_animate_turn(LEFT);
			else {success=0;PLAYER_npc->walk_dir=dir;}
		}

		if(dir==DOWNRIGHT)
		{
			int down=0;
			int right=0;

			if(PLAYER_npc->MAP_x+PLAYER_npc->size_x<(HARDWARE_map_width_tiles*8))
				if(PLAYER_check_hit_layer(RIGHT)==0)
					if(PLAYER_check_hit_non_walkable_npcs(RIGHT)==0)right=1;

			if(PLAYER_npc->MAP_y+PLAYER_npc->size_y<(HARDWARE_map_height_tiles*8))
				if(PLAYER_check_hit_layer(DOWN)==0)
					if(PLAYER_check_hit_non_walkable_npcs(DOWN)==0)down=1;

			if(down==1&&right==1)PLAYER_move_pixel_animate_turn(DOWNRIGHT);
			else if(down==1)PLAYER_move_pixel_animate_turn(DOWN);
			else if(right==1)PLAYER_move_pixel_animate_turn(RIGHT);
			else {success=0;PLAYER_npc->walk_dir=dir;}
		}

		if(dir==UPLEFT)
		{
			int up=0;
			int left=0;

			if(PLAYER_npc->MAP_x>0)
				if(PLAYER_check_hit_layer(LEFT)==0)
					if(PLAYER_check_hit_non_walkable_npcs(LEFT)==0)left=1;

			if(PLAYER_npc->MAP_y+PLAYER_npc->size_y-6>0)
				if(PLAYER_check_hit_layer(UP)==0)
					if(PLAYER_check_hit_non_walkable_npcs(UP)==0)up=1;

			if(up==1&&left==1)PLAYER_move_pixel_animate_turn(UPLEFT);
			else if(up==1)PLAYER_move_pixel_animate_turn(UP);
			else if(left==1)PLAYER_move_pixel_animate_turn(LEFT);
			else {success=0;PLAYER_npc->walk_dir=dir;}
		}

		if(dir==UPRIGHT)
		{
			int up=0;
			int right=0;

			if(PLAYER_npc->MAP_x+PLAYER_npc->size_x<(HARDWARE_map_width_tiles*8))
				if(PLAYER_check_hit_layer(RIGHT)==0)
					if(PLAYER_check_hit_non_walkable_npcs(RIGHT)==0)right=1;

			if(PLAYER_npc->MAP_y+PLAYER_npc->size_y-6>0)
				if(PLAYER_check_hit_layer(UP)==0)
					if(PLAYER_check_hit_non_walkable_npcs(UP)==0)up=1;

			if(up==1&&right==1)PLAYER_move_pixel_animate_turn(UPRIGHT);
			else if(up==1)PLAYER_move_pixel_animate_turn(UP);
			else if(right==1)PLAYER_move_pixel_animate_turn(RIGHT);
			else {success=0;PLAYER_npc->walk_dir=dir;}
		}

		if(dir==RIGHT)
		{
			int right=0;

			if(PLAYER_npc->MAP_x+PLAYER_npc->size_x<(HARDWARE_map_width_tiles*8))
				if(PLAYER_check_hit_layer(RIGHT)==0)
					if(PLAYER_check_hit_non_walkable_npcs(RIGHT)==0)right=1;

			if(right==1)PLAYER_move_pixel_animate_turn(RIGHT);
			else {success=0;PLAYER_npc->walk_dir=dir;}
		}

		if(dir==LEFT)
		{
			int left=0;

			if(PLAYER_npc->MAP_x>0)
				if(PLAYER_check_hit_layer(LEFT)==0)
					if(PLAYER_check_hit_non_walkable_npcs(LEFT)==0)left=1;

			if(left==1)PLAYER_move_pixel_animate_turn(LEFT);
			else {success=0;PLAYER_npc->walk_dir=dir;}
		}

		if(dir==DOWN)
		{
			int down=0;

			if(PLAYER_npc->MAP_y+PLAYER_npc->size_y<(HARDWARE_map_height_tiles*8))
				if(PLAYER_check_hit_layer(DOWN)==0)
					if(PLAYER_check_hit_non_walkable_npcs(DOWN)==0)down=1;

			if(down==1)PLAYER_move_pixel_animate_turn(DOWN);
			else {success=0;PLAYER_npc->walk_dir=dir;}
		}

		if(dir==UP)
		{
			int up=0;

			if(PLAYER_npc->MAP_y+PLAYER_npc->size_y-6>0)
				if(PLAYER_check_hit_layer(UP)==0)
					if(PLAYER_check_hit_non_walkable_npcs(UP)==0)up=1;

			if(up==1)PLAYER_move_pixel_animate_turn(UP);
			else
			{success=0;PLAYER_npc->walk_dir=dir;}
		}

		if(success==1)GLOBAL_main_sprite_standing=0;
		if(success==0)GLOBAL_main_sprite_standing=1;

	}
}

//=========================================================================================================================
bool PLAYER_walk_to_xy_basichit(int x,int y)
{//=========================================================================================================================

	if(x==-1)x=PLAYER_npc->MAP_x+PLAYER_npc->size_x/2;
	if(y==-1)y=PLAYER_npc->MAP_y+(PLAYER_npc->size_y-PLAYER_npc->hitsize_y);

	bool there_yet=0;

	int down=0;
	int up=0;
	int left=0;
	int right=0;


	if(PLAYER_npc->MAP_y+PLAYER_npc->size_y-PLAYER_npc->hitsize_y<y){down=1;}
	if(PLAYER_npc->MAP_y+PLAYER_npc->size_y-PLAYER_npc->hitsize_y>y){up=1;}
	if(PLAYER_npc->MAP_x+PLAYER_npc->size_x/2<x){right=1;}
	if(PLAYER_npc->MAP_x+PLAYER_npc->size_x/2>x){left=1;}

	if(down==1&&right==1)PLAYER_check_hit_move_pixel_animate(DOWNRIGHT);
	else if(down==1&&left==1)PLAYER_check_hit_move_pixel_animate(DOWNLEFT);
	else if(up==1&&right==1)PLAYER_check_hit_move_pixel_animate(UPRIGHT);
	else if(up==1&&left==1)PLAYER_check_hit_move_pixel_animate(UPLEFT);
	else if(down==1)PLAYER_check_hit_move_pixel_animate(DOWN);
	else if(up==1)PLAYER_check_hit_move_pixel_animate(UP);
	else if(left==1)PLAYER_check_hit_move_pixel_animate(LEFT);
	else if(right==1)PLAYER_check_hit_move_pixel_animate(RIGHT);


	if(PLAYER_npc->MAP_x+PLAYER_npc->size_x/2==x&&PLAYER_npc->MAP_y+PLAYER_npc->size_y-PLAYER_npc->hitsize_y==y){there_yet=1; GLOBAL_main_sprite_standing=1;}


	return there_yet;
}



