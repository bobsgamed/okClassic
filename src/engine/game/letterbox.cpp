

#include "../../main.h"
//#include "letterbox.h"

SPRITE* LETTERBOX_sprite[4] = {NULL, NULL, NULL, NULL};

int LETTERBOX_size=0;
int LETTERBOX_top_y=0;
int LETTERBOX_bottom_y=0;

bool LETTERBOX_on=0;
bool LETTERBOX_sprites_exist=0;

//=========================================================================================================================
void LETTERBOX_init(int size,bool transparent)
{//=========================================================================================================================

	if(size>64)size=64;


 	LETTERBOX_size=size*5;

 	LETTERBOX_top_y=0-LETTERBOX_size;
 	LETTERBOX_bottom_y=GAME_VIEWPORT_HEIGHT_PIXELS;

	int alpha=255;

	if(LETTERBOX_sprites_exist==0)
	{
		if(transparent)
		{
			alpha=159;
		}

		LETTERBOX_sprite[0] = HARDWARE_create_sprite(LETTERBOX_sprite_GFX,0,4,1.0f,0,LETTERBOX_top_y,alpha);
		LETTERBOX_sprite[1] = HARDWARE_create_sprite(LETTERBOX_sprite_GFX,0,4,1.0f,0,LETTERBOX_bottom_y,alpha);

		LETTERBOX_sprite[0]->scale=5;
		LETTERBOX_sprite[1]->scale=5;
	}

	LETTERBOX_on=1;
	LETTERBOX_sprites_exist=1;
}

//=========================================================================================================================
void LETTERBOX_deinit()
{//=========================================================================================================================

	LETTERBOX_on=0;

}

//=========================================================================================================================
void LETTERBOX_timer()
{//=========================================================================================================================

}

//=========================================================================================================================
void LETTERBOX_vbl()
{//=========================================================================================================================
	if(LETTERBOX_sprites_exist&&LETTERBOX_on)
	{
		if(LETTERBOX_top_y<64-LETTERBOX_size)LETTERBOX_top_y+=4;
		if(LETTERBOX_top_y>64-LETTERBOX_size)LETTERBOX_top_y=64-LETTERBOX_size;

		if(LETTERBOX_bottom_y>GAME_VIEWPORT_HEIGHT_PIXELS-64)LETTERBOX_bottom_y-=4;
		if(LETTERBOX_bottom_y<GAME_VIEWPORT_HEIGHT_PIXELS-64)LETTERBOX_bottom_y=GAME_VIEWPORT_HEIGHT_PIXELS-64;

		HARDWARE_set_sprite_y(LETTERBOX_sprite[0],LETTERBOX_top_y);
		HARDWARE_set_sprite_y(LETTERBOX_sprite[1],LETTERBOX_bottom_y);

	}

	if(LETTERBOX_sprites_exist&&LETTERBOX_on==0)
	{
		if(LETTERBOX_top_y>0-LETTERBOX_size)LETTERBOX_top_y-=4;
		if(LETTERBOX_top_y<0-LETTERBOX_size)LETTERBOX_top_y=0-LETTERBOX_size;

		if(LETTERBOX_bottom_y<GAME_VIEWPORT_HEIGHT_PIXELS)LETTERBOX_bottom_y+=4;
		if(LETTERBOX_bottom_y>GAME_VIEWPORT_HEIGHT_PIXELS)LETTERBOX_bottom_y=GAME_VIEWPORT_HEIGHT_PIXELS;

		HARDWARE_set_sprite_y(LETTERBOX_sprite[0],LETTERBOX_top_y);
		HARDWARE_set_sprite_y(LETTERBOX_sprite[1],LETTERBOX_bottom_y);
	}

	if(LETTERBOX_on==0&&LETTERBOX_sprites_exist&&LETTERBOX_top_y==0-LETTERBOX_size&&LETTERBOX_bottom_y==GAME_VIEWPORT_HEIGHT_PIXELS)
	{
		HARDWARE_delete_sprite(LETTERBOX_sprite[0]);
		HARDWARE_delete_sprite(LETTERBOX_sprite[1]);

		LETTERBOX_sprites_exist=0;
	}

}

//=========================================================================================================================
void LETTERBOX_main()
{//=========================================================================================================================

}


