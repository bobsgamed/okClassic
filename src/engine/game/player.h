//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================
#ifndef PLAYER_H
#define PLAYER_H
//==============================================================================



//================
//defines
//================

#define GLOBALSPEED 1

#define SPEED_ACCEL_INCREMENT_AMOUNT 1


#define SPEED_CAR 	GLOBALSPEED*2
#define SPEED_FASTEST GLOBALSPEED*3
#define SPEED_FASTER	GLOBALSPEED*4
#define SPEED_FAST	GLOBALSPEED*5
#define SPEED_NORMAL	GLOBALSPEED*10
#define SPEED_SLOW	GLOBALSPEED*15
#define SPEED_SLOWER GLOBALSPEED*20
#define SPEED_SLOWEST GLOBALSPEED*30


#define SPEED_CAMERA_CONVERSATION GLOBALSPEED*1
#define SPEED_CAMERA_STOPPED SPEED_SLOWEST


#define YUU_WALKING_SPEED_KEYBOARD GLOBALSPEED*6
#define YUU_RUNNING_SPEED_KEYBOARD SPEED_FASTEST
#define YUU_STANDING_SPEED_KEYBOARD SPEED_SLOWER

#define YUU_WALKING_SPEED_JOYSTICK GLOBALSPEED*7
#define YUU_RUNNING_SPEED_JOYSTICK SPEED_FASTEST
#define YUU_STANDING_SPEED_JOYSTICK SPEED_SLOWER

//================
//variables
//================



extern int YUU_WALKING_SPEED;
extern int YUU_RUNNING_SPEED;
extern int YUU_STANDING_SPEED;


extern bool GLOBAL_no_sprite_buttons_pressed;
extern bool GLOBAL_main_sprite_standing;

extern bool GLOBAL_main_sprite_input_off;
extern bool GLOBAL_main_sprite_actions_off;
extern bool GLOBAL_main_sprite_fx_off;

extern bool GLOBAL_camera_fx_bounds_off;


extern int clicktarget_sprite_on;

extern int yuu_is_dead;

//================
//prototypes
//================

void PLAYER_animate_turn_if_needed();
void PLAYER_play_footstep();
void PLAYER_init();

void PLAYER_vbl();
void PLAYER_main();


void PLAYER_animate_turn_if_needed();
void PLAYER_check_fx_layer();
void PLAYER_set_main_sprite_screen_xy_to_map_cam();
void PLAYER_check_action(int);
bool PLAYER_check_action_dont_run(int);
bool PLAYER_check_hit_layer(int hit_direction);
bool PLAYER_check_hit_non_walkable_npcs(int direction);
void PLAYER_check_buttons();
bool walking_into_door(int x,int y,int x2,int y2);
void PLAYER_check_hit_move_pixel_animate(int dir);
bool PLAYER_walk_to_xy_basichit(int x,int y);





//==============================================================================
#endif
//==============================================================================
