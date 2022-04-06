

#include "../../main.h"
//#include "action.h"


	CAPTION* ACTION_caption=NULL;
	SPRITE* ACTION_icon_sprite=NULL;
	int ACTION_in_action_range=0;


//=========================================================================================================================
void ACTION_caption_delete_if_no_action()
{//=========================================================================================================================

	//if(PLAYER_check_action_dont_run(facing_direction)==0)
		if(ACTION_caption!=NULL)
			if(ACTION_caption->actioncaptiontype==ACTIONCAPTIONTYPE_TILE)	//only delete action tile captions
			{
				CAPTION_delete_caption(ACTION_caption);
				HARDWARE_delete_sprite(ACTION_icon_sprite);
			}
}


//=========================================================================================================================
void ACTION_caption_delete()
{//=========================================================================================================================

	//if(PLAYER_check_action_dont_run(facing_direction)==0)
	{

		if(ACTION_caption!=NULL)
		{
			//if(ACTION_caption->actioncaptiontype==ACTIONCAPTIONTYPE_TILE)	//only delete action tile captions
			{
				CAPTION_delete_caption(ACTION_caption);
				//delete action icon
				HARDWARE_delete_sprite(ACTION_icon_sprite);
				//HARDWARE_delete_sprite_gfxslot(1,ACTION_icon_gfx_slot);
			}
		}
	}
}
//=========================================================================================================================
bool ACTION_check(const char* label)	//for action tiles. need a way to deinit.
{//=========================================================================================================================

	if(PLAYER_npc==NULL){ERROR_set_error("ACTION_check()");return 0;}

	if(ACTION_in_action_range==0)
	{
		ACTION_in_action_range=1;

		if((GLOBAL_text_engine_state==0)&&GLOBAL_main_sprite_actions_off==0)
		{

			if(ACTION_caption!=NULL)
			{

					//int font = FONT_OUTLINED_ID;
					int px = ACTION_caption->width;
					int actionx=((PLAYER_npc->screen_x+PLAYER_npc->size_x/2)-((px+8)/2))+8; //center
					if(actionx+px>GAME_VIEWPORT_WIDTH_PIXELS)actionx=GAME_VIEWPORT_WIDTH_PIXELS-px;									//dont go past right
					if(actionx-8<0)actionx=0+8;											//dont go past left
					int actiony=PLAYER_npc->screen_y-16;

					if(strcmp(label,ACTION_caption->text)!=0)	//		if action icon exists,check new label against old label
					{
						//CAPTION_delete_caption(ACTION_caption);	//			if label is different,delete old,place new.
						//CAPTION_make_multiline_caption(&ACTION_caption,1,actionx,actiony,-1,label,font,BLACK,WHITE);

						//CAPTION_replace_text(ACTION_caption,label);
						//ACTION_caption->actioncaptiontype=ACTIONCAPTIONTYPE_TILE;
						 //move action icon sprite
					}
					else
						if(ACTION_caption->screen_x!=actionx||ACTION_caption->screen_y!=actiony)
						{
							int c=0;
							for(c=0;c<ACTION_caption->chunks;c++)						//			if sprite xy is different,move it to new one
							{
								//HARDWARE_set_sprite_xy(1,ACTION_caption->PLAYER_id[c],actionx+64*c,actiony);
							}
							ACTION_caption->screen_x = actionx;
							ACTION_caption->screen_y = actiony;

							HARDWARE_set_sprite_xy(ACTION_icon_sprite,actionx-8,actiony+1);//move action icon sprite

						}
			}
			else
				{//doesnt exist,make new one over sprites head

					int font = FONT_OUTLINED_ID;
					int px = CAPTION_get_pixel_length(label,font);

					int actionx=((PLAYER_npc->screen_x+PLAYER_npc->size_x/2)-((px+8)/2))+8; //centered over player sprite

					if(actionx+px>GAME_VIEWPORT_WIDTH_PIXELS)actionx=GAME_VIEWPORT_WIDTH_PIXELS-px;//dont go past right
					if(actionx-8<0)actionx=0+8;											//dont go past left

					int actiony=PLAYER_npc->screen_y-16;

					CAPTION_make_caption(&ACTION_caption,1,actionx,actiony,-1,label,font,BLACK,WHITE,1,1);

					if(ACTION_caption!=NULL)
					{
						ACTION_caption->actioncaptiontype=ACTIONCAPTIONTYPE_TILE;

						//ACTION_icon_gfx_slot = HARDWARE_create_sprite_gfxslot(1,TEXT_button_icon_GFX,0,8,8,1,0);

						ACTION_icon_sprite = HARDWARE_create_sprite(TEXT_button_icon_GFX,0,1,1.0f,actionx-8,actiony+1,255);
					}

				}

			if(ACTION_caption!=NULL)
			if(BUTTON_ACTION_PRESSED&&strcmp(label,ACTION_caption->text)==0
					&&ACTION_caption->actioncaptiontype==ACTIONCAPTIONTYPE_TILE)			//		playsound blip,delete,return 1 else return 0;
			{
				HARDWARE_play_sound("blip",63,70000,0);
				if(ACTION_caption!=NULL)
				{
					CAPTION_delete_caption(ACTION_caption);
					HARDWARE_delete_sprite(ACTION_icon_sprite);
					//HARDWARE_delete_sprite_gfxslot(1,ACTION_icon_gfx_slot);

				}
				return 1;
			}
		}
		else //else delete action icon and caption
		{
			if(ACTION_caption!=NULL)
			{
				 if(strcmp(label,ACTION_caption->text)==0
					&&ACTION_caption->actioncaptiontype==ACTIONCAPTIONTYPE_TILE
					)	//only delete itself
				 {
					CAPTION_delete_caption(ACTION_caption);
					//delete action icon
					HARDWARE_delete_sprite(ACTION_icon_sprite);
					//HARDWARE_delete_sprite_gfxslot(1,ACTION_icon_gfx_slot);
				}
			}
		}
	}

	return 0;

}

//=========================================================================================================================
bool ACTION_xy(int x,int y,const char* label)
{//=========================================================================================================================

	if(PLAYER_npc==NULL){ERROR_set_error("ACTION_xy()");return 0;}

	if(
		NPC_in_range_of_xy_in_direction_by_amount(&PLAYER_npc,x,y,PLAYER_npc->anim_dir,7)
		&&
		(GLOBAL_text_engine_state==0)
		&&
		GLOBAL_main_sprite_actions_off==0
	) //if main sprite xy is within range of xy
	{

		if(ACTION_caption!=NULL)
		{

				//int font = FONT_OUTLINED_ID;
				int px = ACTION_caption->width;
 				int actionx=((PLAYER_npc->screen_x+PLAYER_npc->size_x/2)-((px+8)/2))+8; //center
 				if(actionx+px>GAME_VIEWPORT_WIDTH_PIXELS)actionx=GAME_VIEWPORT_WIDTH_PIXELS-px;									//dont go past right
 				if(actionx-8<0)actionx=0+8;											//dont go past left
 				int actiony=PLAYER_npc->screen_y-16;


				if(strcmp(label,ACTION_caption->text)!=0)	//		if action icon exists,check new label against old label
				{
					//CAPTION_delete_caption(ACTION_caption);	//			if label is different,delete old,place new.
					//CAPTION_make_multiline_caption(&ACTION_caption,1,actionx,actiony,-1,label,font,BLACK,WHITE);

					//CAPTION_replace_text(ACTION_caption,label);
					//ACTION_caption->actioncaptiontype=ACTIONCAPTIONTYPE_XY;
					//ACTION_caption->range_x=x;
					//ACTION_caption->range_y=y;
					 //move action icon sprite
				}
				else
					if(ACTION_caption->screen_x!=actionx||ACTION_caption->screen_y!=actiony)
					{
						int c=0;
						for(c=0;c<ACTION_caption->chunks;c++)						//			if sprite xy is different,move it to new one
						{
							//HARDWARE_set_sprite_xy(1,ACTION_caption->PLAYER_id[c],actionx+64*c,actiony);
						}
						ACTION_caption->screen_x = actionx;
						ACTION_caption->screen_y = actiony;
						HARDWARE_set_sprite_xy(ACTION_icon_sprite,actionx-8,actiony+1);//move action icon sprite
					}
		}
		else
			{//doesnt exist,make new one over sprites head

				int font = FONT_OUTLINED_ID;
				int px = CAPTION_get_pixel_length(label,font);
 				int actionx=((PLAYER_npc->screen_x+PLAYER_npc->size_x/2)-((px+8)/2))+8; //center
 				if(actionx+px>GAME_VIEWPORT_WIDTH_PIXELS)actionx=GAME_VIEWPORT_WIDTH_PIXELS-px;									//dont go past right
 				if(actionx-8<0)actionx=0+8;											//dont go past left
 				int actiony=PLAYER_npc->screen_y-16;

				CAPTION_make_caption(&ACTION_caption,1,actionx,actiony,-1,label,font,BLACK,WHITE,1,1);

				if(ACTION_caption!=NULL)
				{
					ACTION_caption->actioncaptiontype=ACTIONCAPTIONTYPE_XY;
					ACTION_caption->range_x=x;
					ACTION_caption->range_y=y;
					//ACTION_icon_gfx_slot = HARDWARE_create_sprite_gfxslot(1,TEXT_button_icon_GFX,0,8,8,1,0);

					ACTION_icon_sprite = HARDWARE_create_sprite(TEXT_button_icon_GFX,0,1,1.0f,actionx-8,actiony+1,255);

					//HARDWARE_create_sprite(1,ACTION_icon_sprite_id,ACTION_icon_gfx_slot,8,8,1,0,0,0,0,0,1,0,actionx-8,actiony+1);
				}

			}

		if(ACTION_caption!=NULL)
		if(BUTTON_ACTION_PRESSED&&strcmp(label,ACTION_caption->text)==0
			&&ACTION_caption->actioncaptiontype==ACTIONCAPTIONTYPE_XY
			&&ACTION_caption->range_x==x
			&&ACTION_caption->range_y==y)			//		playsound blip,delete,return 1 else return 0;
		{

			HARDWARE_play_sound("blip",63,70000,0);

			if(ACTION_caption!=NULL)
			{
				CAPTION_delete_caption(ACTION_caption);
				HARDWARE_delete_sprite(ACTION_icon_sprite);
				//HARDWARE_delete_sprite_gfxslot(1,ACTION_icon_gfx_slot);

			}
			return 1;
		}

	}
	else //else delete action icon and caption
	{
		if(ACTION_caption!=NULL)
		{
		if(strcmp(label,ACTION_caption->text)==0
			&&ACTION_caption->actioncaptiontype==ACTIONCAPTIONTYPE_XY
			&&ACTION_caption->range_x==x
			&&ACTION_caption->range_y==y)	//only delete itself
			{
				CAPTION_delete_caption(ACTION_caption);
				//delete action icon
				HARDWARE_delete_sprite(ACTION_icon_sprite);
				//HARDWARE_delete_sprite_gfxslot(1,ACTION_icon_gfx_slot);

			}
		}
	}

	return 0;
}

//=========================================================================================================================
bool ACTION_range_xy_xy(int x,int y,int x2,int y2,const char* label)
{//=========================================================================================================================


	if(PLAYER_npc==NULL){ERROR_set_error("ACTION_range_xy_xy()");return 0;}

	if(
		NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,x,y,x2,y2,PLAYER_npc->anim_dir,7)
		&&
		(GLOBAL_text_engine_state==0)
		&&
		GLOBAL_main_sprite_actions_off==0
	) //if main sprite xy is within range of xy
	{

		if(ACTION_caption!=NULL)
		{
				//int font = FONT_OUTLINED_ID;
				int px = ACTION_caption->width;
 				int actionx=((PLAYER_npc->screen_x+PLAYER_npc->size_x/2)-((px+8)/2))+8; //center
 				if(actionx+px>GAME_VIEWPORT_WIDTH_PIXELS)actionx=GAME_VIEWPORT_WIDTH_PIXELS-px;									//dont go past right
 				if(actionx-8<0)actionx=0+8;											//dont go past left
 				int actiony=PLAYER_npc->screen_y-16;

				if(strcmp(label,ACTION_caption->text)!=0)	//		if action icon exists,check new label against old label
				{

					//CAPTION_replace_text(ACTION_caption,label);
					//ACTION_caption->actioncaptiontype=ACTIONCAPTIONTYPE_XYXY;
					//ACTION_caption->range_x=x;
					//ACTION_caption->range_y=y;
					 //move action icon sprite
				}
				else
					if(ACTION_caption->screen_x!=actionx||ACTION_caption->screen_y!=actiony)
					{
						int c=0;
						for(c=0;c<ACTION_caption->chunks;c++)						//			if sprite xy is different,move it to new one
						{
							//HARDWARE_set_sprite_xy(1,ACTION_caption->PLAYER_id[c],actionx+64*c,actiony);
						}
						ACTION_caption->screen_x = actionx;
						ACTION_caption->screen_y = actiony;
						HARDWARE_set_sprite_xy(ACTION_icon_sprite,actionx-8,actiony+1);//move action icon sprite
					}
		}
		else
			{//doesnt exist,make new one over sprites head

				int font = FONT_OUTLINED_ID;
				int px = CAPTION_get_pixel_length(label,font);
 				int actionx=((PLAYER_npc->screen_x+PLAYER_npc->size_x/2)-((px+8)/2))+8; //center
 				if(actionx+px>GAME_VIEWPORT_WIDTH_PIXELS)actionx=GAME_VIEWPORT_WIDTH_PIXELS-px;									//dont go past right
 				if(actionx-8<0)actionx=0+8;											//dont go past left
 				int actiony=PLAYER_npc->screen_y-16;

				CAPTION_make_caption(&ACTION_caption,1,actionx,actiony,-1,label,font,BLACK,WHITE,1,1);
				if(ACTION_caption!=NULL)
				{
					ACTION_caption->actioncaptiontype=ACTIONCAPTIONTYPE_XYXY;
					ACTION_caption->range_x=x;
					ACTION_caption->range_y=y;
					//ACTION_icon_gfx_slot = HARDWARE_create_sprite_gfxslot(1,TEXT_button_icon_GFX,0,8,8,1,0);

					ACTION_icon_sprite = HARDWARE_create_sprite(TEXT_button_icon_GFX,0,1,1.0f,actionx-8,actiony+1,255);

					//HARDWARE_create_sprite(1,ACTION_icon_sprite_id,ACTION_icon_gfx_slot,8,8,1,0,0,0,0,0,1,0,actionx-8,actiony+1);
				}

			}

		if(ACTION_caption!=NULL)
		if(BUTTON_ACTION_PRESSED&&strcmp(label,ACTION_caption->text)==0
				&&ACTION_caption->actioncaptiontype==ACTIONCAPTIONTYPE_XYXY
				&&ACTION_caption->range_x==x
				&&ACTION_caption->range_y==y)			//		playsound blip,delete,return 1 else return 0;
		{

			HARDWARE_play_sound("blip",63,70000,0);

			if(ACTION_caption!=NULL)
			{
				CAPTION_delete_caption(ACTION_caption);
				HARDWARE_delete_sprite(ACTION_icon_sprite);
				//HARDWARE_delete_sprite_gfxslot(1,ACTION_icon_gfx_slot);

			}
			return 1;
		}

	}
	else //else delete action icon and caption
	{
		if(ACTION_caption!=NULL)
		{
			if(strcmp(label,ACTION_caption->text)==0
				&&ACTION_caption->actioncaptiontype==ACTIONCAPTIONTYPE_XYXY
				&&ACTION_caption->range_x==x
				&&ACTION_caption->range_y==y)	//only delete itself
			{
				CAPTION_delete_caption(ACTION_caption);
				//delete action icon
				HARDWARE_delete_sprite(ACTION_icon_sprite);

				//HARDWARE_delete_sprite_gfxslot(1,ACTION_icon_gfx_slot);

			}
		}
	}

	return 0;
}
//=========================================================================================================================
bool ACTION_npc(NPC** npcpp,const char* label)
{//=========================================================================================================================

	if(PLAYER_npc==NULL){ERROR_set_error("ACTION_npc(&)");return 0;}

	if(npcpp==NULL){ERROR_set_error("ACTION_npc(&)");return 0;}
	if(*npcpp==NULL){ERROR_set_error("ACTION_npc(&)");return 0;}
	NPC* npc = *npcpp;

	if(npc!=NULL)
	{
		if(
			NPC_in_range_of_npc_in_direction_by_amount(&PLAYER_npc,npcpp,PLAYER_npc->anim_dir,7)
			&&
			(GLOBAL_text_engine_state==0)
			&&
			GLOBAL_main_sprite_actions_off==0
		) //if main sprite xy is within range of xy
		{
			if(ACTION_caption!=NULL)
			{
					//int font = FONT_OUTLINED_ID;
					int px = ACTION_caption->width;
					int actionx=((PLAYER_npc->screen_x+PLAYER_npc->size_x/2)-((px+8)/2))+8; //center
					if(actionx+px>GAME_VIEWPORT_WIDTH_PIXELS)actionx=GAME_VIEWPORT_WIDTH_PIXELS-px;									//dont go past right
					if(actionx-8<0)actionx=0+8;											//dont go past left
					int actiony=PLAYER_npc->screen_y-16;

					if(strcmp(label,ACTION_caption->text)!=0)	//		if action icon exists,check new label against old label
					{
						//dont do it! flicker :(

						//CAPTION_replace_text(ACTION_caption,label);
						//ACTION_caption->actioncaptiontype=ACTIONCAPTIONTYPE_NPC;
						//ACTION_caption->npc=npc;
						 //move action icon sprite
					}
					else
						if(ACTION_caption->screen_x!=actionx||ACTION_caption->screen_y!=actiony)
						{
							int c=0;
							for(c=0;c<ACTION_caption->chunks;c++)						//			if sprite xy is different,move it to new one
							{
								//HARDWARE_set_sprite_xy(1,ACTION_caption->PLAYER_id[c],actionx+64*c,actiony);
							}
							ACTION_caption->screen_x = actionx;
							ACTION_caption->screen_y = actiony;

							HARDWARE_set_sprite_xy(ACTION_icon_sprite,actionx-8,actiony+1);//move action icon sprite

						}
			}
			else
			{//doesnt exist,make new one over sprites head

				int font = FONT_OUTLINED_ID;
				int px = CAPTION_get_pixel_length(label,font);
				int actionx=((PLAYER_npc->screen_x+PLAYER_npc->size_x/2)-((px+8)/2))+8; //center
				if(actionx+px>GAME_VIEWPORT_WIDTH_PIXELS)actionx=GAME_VIEWPORT_WIDTH_PIXELS-px;									//dont go past right
				if(actionx-8<0)actionx=0+8;											//dont go past left
				int actiony=PLAYER_npc->screen_y-16;

				CAPTION_make_caption(&ACTION_caption,1,actionx,actiony,-1,label,font,BLACK,WHITE,1,1);
				if(ACTION_caption!=NULL)
				{
					ACTION_caption->actioncaptiontype=ACTIONCAPTIONTYPE_NPC;
					ACTION_caption->npc=npc;

					//ACTION_icon_gfx_slot = HARDWARE_create_sprite_gfxslot(1,TEXT_button_icon_GFX,0,8,8,1,0);

					ACTION_icon_sprite = HARDWARE_create_sprite(TEXT_button_icon_GFX,0,1,1.0f,actionx-8,actiony+1,255);

					//HARDWARE_create_sprite(1,ACTION_icon_sprite_id,ACTION_icon_gfx_slot,8,8,1,0,0,0,0,0,1,0,actionx-8,actiony+1);
				}
			}

			if(ACTION_caption!=NULL)
			if(BUTTON_ACTION_PRESSED
					&&strcmp(label,ACTION_caption->text)==0
					&&ACTION_caption->actioncaptiontype==ACTIONCAPTIONTYPE_NPC
					&&ACTION_caption->npc==npc)			//		playsound blip,delete,return 1 else return 0;
			{

				HARDWARE_play_sound("blip",63,70000,0);

				if(ACTION_caption!=NULL)
				{
					CAPTION_delete_caption(ACTION_caption);

					HARDWARE_delete_sprite(ACTION_icon_sprite);

					//HARDWARE_delete_sprite_gfxslot(1,ACTION_icon_gfx_slot);

				}
				return 1;
			}

		}
		else //else delete action icon and caption
		{
			if(ACTION_caption!=NULL)
			{
				if(strcmp(label,ACTION_caption->text)==0
					&&ACTION_caption->actioncaptiontype==ACTIONCAPTIONTYPE_NPC
					&&ACTION_caption->npc==npc)	//only delete itself
				{
					CAPTION_delete_caption(ACTION_caption);

					//delete action icon
					HARDWARE_delete_sprite(ACTION_icon_sprite);

					//HARDWARE_delete_sprite_gfxslot(1,ACTION_icon_gfx_slot);

				}
			}
		}
	}

	return 0;
}
