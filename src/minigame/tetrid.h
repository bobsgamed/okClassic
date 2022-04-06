
//==============================================================================
#ifndef TETRID_H
#define TETRID_H
//==============================================================================



//================
//defines
//================

#define TBLOCK 0
#define JBLOCK 1
#define LBLOCK 2
#define BACKZBLOCK 3
#define ZBLOCK 4
#define IBLOCK 5
#define SQUAREBLOCK 6
#define NONE 7
#define TETRID_DOWN 0
#define TETRID_RIGHT 1
#define TETRID_LEFT 2
#define ROTATECW 3
#define ROTATECCW 4
#define bBLUE 0
#define bYELLOW 1
#define bRED 2
#define bGREEN 3
#define bORANGE 4
#define bPURPLE 5
#define bPINK 6
#define bEMPTY 7


//================
//variables
//================

extern int GAME_playing_tetrid;

extern float TETRID_aspectratio;// = 1.0f;//((float)(((float)(GAME_VIEWPORT_HEIGHT_PIXELS)/1.6f))/192.0f);
extern int TETRID_fromx;// = 0; //((GAME_VIEWPORT_WIDTH_PIXELS-(TETRID_aspectratio*256.0f))/2);
extern int TETRID_fromy;// = 0;//(GAME_VIEWPORT_HEIGHT_PIXELS/3.5f)+7-4;

//================
//prototypes
//================





//#include <cstdio>





//-----------------------------
//tetrid
//-----------------------------



void TETRID_scrollbackground();
void TETRID_scrollplayingbackground();
void TETRID_shakeplayingfield();
void TETRID_init_playingfield_array();
void TETRID_redraw_playing_field();
void TETRID_set_playing_field_colors();
bool TETRID_new_piece(int type_of_piece);
void TETRID_set_block_colors(int type_of_piece);
void TETRID_set_block_locations(int type_of_piece, int rotation);
void TETRID_drop_piece();
void TETRID_move_piece(int TETRID_direction);
void TETRID_init_game();
void TETRID_query_keys();
void TETRID_dead();
void TETRID_end_game();
void TETRID_new_random_piece();
void TETRID_check_lines();
void TETRID_flash_line();
void TETRID_move_down_blocks(int y2);
void TETRID_update_score(int amt);
void TETRID_update_next_piece();
void TETRID_update_level();
void TETRID_flash_screen();
void TETRID_vbl();
void TETRID_main();






//==============================================================================
#endif
//==============================================================================
