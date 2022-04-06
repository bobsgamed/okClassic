//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================
#ifndef ACTION_H
#define ACTION_H
//==============================================================================


//================
//defines
//================
#define ACTIONCAPTIONTYPE_NONE 0
#define ACTIONCAPTIONTYPE_TILE 1
#define ACTIONCAPTIONTYPE_NPC 2
#define ACTIONCAPTIONTYPE_XY 3
#define ACTIONCAPTIONTYPE_XYXY 4


//================
//variables
//================
extern CAPTION* ACTION_caption;
extern SPRITE* ACTION_icon_sprite;
extern int ACTION_in_action_range;


//================
//prototypes
//================
bool ACTION_xy(int x, int y, const char* label);
bool ACTION_npc(NPC** npcpp, const char* label);
bool ACTION_range_xy_xy(int x, int y, int x2, int y2, const char* label);
bool ACTION_check(const char* label);
void ACTION_caption_delete_if_no_action();
void ACTION_caption_delete();
void ACTION_caption_delete_action_tile_caption_if_no_action();




//==============================================================================
#endif
//==============================================================================
