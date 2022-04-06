//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================
#ifndef NPC_H
#define NPC_H
//==============================================================================




	struct NPC
	{

		SPRITE* sprite;
		GFX* gfx;

		struct NPC** npcpp;
		struct NPC *next;
		struct NPC *nearest_npc;
		struct NPC *znext;

		//sizes
		int data_size_x;
		int data_size_y;
		int size_x;
		int size_y;

		int hitsize_x;
		int hitsize_y;

		//coords
		int MAP_x;
		int MAP_y;
		int screen_x;
		int screen_y;


		//walking counters
		int walk_dir;
		int walking_speed;
		int pixels_to_walk;
		int x_pixel_counter; //used for setting diagonal ratio, walking in perfect diagonal line
		int y_pixel_counter;

		int vbls; //was vbl timer
		int ms; //was walk timer


		int AI;//was cycle
		int standing_cycles;
		int secondary_direction;

		bool is_walking_into_player;
		bool is_walking_into_wall;

		bool visible;




		//animation
		int gfx_index;
		bool animation_off;
		int anim_frame_count;
		int anim_dir;
		int vbl_animation_timer;

		int alpha;
		bool always_on_top;
		int layer;
		float scale;

		bool pushable;
		bool non_walkable;
		bool ignore_hit_layer;
		bool ignore_fx_layer;
		bool pull_player;
		bool push_player;
		bool ignore_player;

		bool random;
		int randomcolorset[7]; //hair,eyes,skin,clothes,pants,shoes12


		int chase_dir_x;
		int chase_dir_y;
		bool chase_flip_xy;
		int chase_stage;
		int chase_stuck_x;
		int chase_stuck_y;

		int voice_frequency;

	};




	 struct NPC_follower
	{
		NPC *NPC_id;
		int x_path[25];
		int y_path[25];
		int last_x;
		int last_y;
		int index;
		bool offscreen;
		struct NPC_follower *next;
	};



//================
//defines
//================



//================
//variables
//================


extern NPC main_npc;
extern NPC *PLAYER_npc;

extern NPC cameraman_npc;
extern NPC *cameraman;

//extern NPC shadownpc;
//extern NPC *main_sprite_shadow;

extern NPC mr_cart_npc;
extern NPC* mr_cart;

//extern NPC clicktarget_npc;
//extern NPC* clicktarget;

extern NPC* cameraman_target;

extern NPC dummy_camera_target_npc;
extern NPC* dummy_camera_target;


extern bool GLOBAL_npc_all_animation_off;

extern bool NPC_main_sprite_being_dragged;

extern int GLOBAL_npcs_pulling_main_sprite;
//extern NPC_chaser *first_npc_chaser;
//extern NPC_avoider *first_npc_avoider;
extern NPC_follower *first_npc_follower;
//extern NPC_pull_againster *first_npc_pull_againster;

extern NPC* first_NPC;

//================
//prototypes
//================


void NPC_main();
void NPC_init();
void NPC_init_npc_vars(NPC** npcpp, GFX* gfx, int size_x, int size_y, int MAP_x, int MAP_y);
void NPC_create_always_on_top_npc_if_within_range_else_delete(NPC** npcpp,GFX*gfx_struct,int sizex,int sizey,int x,int y);

bool NPC_in_range_of_npc_by_amount(NPC** npc1pp, NPC** npc2pp, int amt);
void NPC_create_npc_xy_feet(NPC** npcpp, GFX* gfx, int size_x, int size_y,	int x, int y);
bool NPC_in_range_of_xy_in_direction_by_amount(NPC** npcpp, int x, int y, int direction, int amt);
bool NPC_in_range_of_area_xyxy_in_direction_by_amount(NPC** npcpp, int x, int y, int x2, int y2, int direction, int amt);
void NPC_create_npc_if_within_range_else_delete(NPC** npcpp, GFX*gfx_struct, int sizex, int sizey, int x, int y) ;
bool NPC_within_range_of_nearest_npc(NPC** npcpp, int amt);
NPC *NPC_find_nearest_npc_besides_main_sprite(NPC** npcpp);
NPC *NPC_find_nearest_npc(NPC** npcpp);
bool NPC_should_animate(NPC** npcpp);
void NPC_delete_npc(NPC** npcpp);
void NPC_set_shape_and_size(NPC** npcpp);
bool NPC_check_collide_xy(int x,int y);
bool NPC_in_range_of_npc(NPC** npc1pp, NPC** npc2pp);
bool NPC_in_range_of_npc_in_direction_by_amount(NPC** npc1pp, NPC** npc2pp, int direction,int amt);
bool NPC_check_hit_layer_direction(NPC** npcpp,int dir);
bool NPC_check_collide_fx_xy(int x,int y);
bool NPC_cant_create_at_xy(int x,int y);
void NPC_set_screen_xy(NPC** npcpp);
void NPC_create_npc(NPC** npcpp, GFX* gfx,int size_x,int size_y,int MAP_x,int MAP_y);
void NPC_vbl();
void NPC_timer();
void NPC_clone_main_sprite();
void NPC_delete_all_npcs();

void NPC_animate_dir(NPC** npcpp, int dir);
void NPC_animate(NPC** npcpp);
void NPC_animate_cycle_through_frames_now(NPC** npcpp,int amt_of_frames);
void NPC_animate_stand_dir(NPC** npcpp,int anim_direction);
void NPC_set_anim_frame_now(NPC** npcpp,int frame);
void NPC_chase_nearest_npc(NPC** npcpp);
void NPC_draw_and_delete_sprites(NPC** npcpp);
void NPC_delete_npc(NPC** npcpp);




//==============================================================================
#endif
//==============================================================================
