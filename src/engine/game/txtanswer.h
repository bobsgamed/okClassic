//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================
#ifndef TXTANSWER_H
#define TXTANSWER_H
//==============================================================================



//================
//defines
//================

#define MAX_ANSWER_LENGTH 50

//================
//variables
//================

extern SPRITE* TEXTANSWER_cursor_sprite;

extern int TEXTANSWER_answerbox_y;
extern int TEXTANSWER_number_of_answers;
extern bool TEXTANSWER_deinit_answer_box;
extern int TEXTANSWER_amt_of_chunks;
extern int TEXTANSWER_amt_of_sprites;
extern int TEXTANSWER_selected_answer;
extern int TEXTANSWER_answerbox_indexed_gfx_data[64*32*3*2];
extern char TEXTANSWER_selected_answer_string[MAX_ANSWER_LENGTH];
//================
//prototypes
//================


int TEXTANSWER_get_pixel_length(const char* answer);
void TEXTANSWER_draw_letter(const char* answer_text);
void TEXTANSWER_draw_answerbox_text(const char* answer_text);
void TEXTANSWER_clear_answerbox();
void TEXTANSWER_move_answerbox();

void TEXTANSWER_answerbox(const char* TEXT_option_buffer,int TEXT_option_length);













//==============================================================================
#endif
//==============================================================================
