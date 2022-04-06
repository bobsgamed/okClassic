



#include "../../main.h"
//#include "txtanswer.h"



int TEXTANSWER_answerbox_indexed_gfx_data[64*32*3*2]= {0};

char TEXTANSWER_string_1[MAX_ANSWER_LENGTH];
char TEXTANSWER_string_2[MAX_ANSWER_LENGTH];
char TEXTANSWER_string_3[MAX_ANSWER_LENGTH];
char TEXTANSWER_string_4[MAX_ANSWER_LENGTH];
char TEXTANSWER_string_5[MAX_ANSWER_LENGTH];
char TEXTANSWER_string_6[MAX_ANSWER_LENGTH];


char TEXTANSWER_selected_answer_string[MAX_ANSWER_LENGTH];

int TEXTANSWER_answerbox_y=0;
int TEXTANSWER_number_of_answers=0;
bool TEXTANSWER_deinit_answer_box=0;
int TEXTANSWER_amt_of_chunks=0;
int TEXTANSWER_amt_of_sprites=0;
int TEXTANSWER_selected_answer=0;

int TEXTANSWER_x_in_tile=0;
int TEXTANSWER_tile=0;
int TEXTANSWER_chunk=0;
int TEXTANSWER_line=0;

int TEXTANSWER_string_length=0;
int TEXTANSWER_string_position=0;

SPRITE* TEXTANSWER_answerbox_sprite[3] = {NULL, NULL, NULL};//[3]={TEXT_ANSWER_1_ID,TEXT_ANSWER_2_ID,TEXT_ANSWER_3_ID};
SPRITE* TEXTANSWER_cursor_sprite = NULL;

//=========================================================================================================================
void TEXTANSWER_draw_column(int letter_index,int x_in_letter)
{//=========================================================================================================================

	int chunk=TEXTANSWER_chunk;
	int tile=TEXTANSWER_tile;
	int x_in_tile=TEXTANSWER_x_in_tile;
	int* font_pointer = FONT_NORMAL_indexed_gfx_data;
	int y=0;
	int h=TEXT_font_height;

	//SPLIT FOR LINE 1
	if(TEXTANSWER_line==0)
	{
		for(y=0; y<8&&y<h; y++)TEXTANSWER_answerbox_indexed_gfx_data[((8*0)+(8*(y-0))+x_in_tile)+(tile*64)+(chunk*64*64)+(64*8*0)]=TEXT_color[font_pointer[(16*16*letter_index)+((16*y)+x_in_letter)]];
		for(y=8; y<10&&y<h; y++)TEXTANSWER_answerbox_indexed_gfx_data[((8*0)+(8*(y-8))+x_in_tile)+(tile*64)+(chunk*64*64)+(64*8*1)]=TEXT_color[font_pointer[(16*16*letter_index)+((16*y)+x_in_letter)]];
	}
	//SPLIT FOR LINE 2
	if(TEXTANSWER_line==1)
	{
		for(y=0; y<5&&y<h; y++)TEXTANSWER_answerbox_indexed_gfx_data[((8*3)+(8*(y-0))+x_in_tile)+(tile*64)+(chunk*64*64)+(64*8*1)]=TEXT_color[font_pointer[(16*16*letter_index)+((16*y)+x_in_letter)]];
		for(y=5; y<10&&y<h; y++)TEXTANSWER_answerbox_indexed_gfx_data[((8*0)+(8*(y-5))+x_in_tile)+(tile*64)+(chunk*64*64)+(64*8*2)]=TEXT_color[font_pointer[(16*16*letter_index)+((16*y)+x_in_letter)]];
	}
	//SPLIT FOR LINE 3
	if(TEXTANSWER_line==2)
	{
		for(y=0; y<2&&y<h; y++)TEXTANSWER_answerbox_indexed_gfx_data[((8*6)+(8*(y-0))+x_in_tile)+(tile*64)+(chunk*64*64)+(64*8*2)]=TEXT_color[font_pointer[(16*16*letter_index)+((16*y)+x_in_letter)]];
		for(y=2; y<10&&y<h; y++)TEXTANSWER_answerbox_indexed_gfx_data[((8*0)+(8*(y-2))+x_in_tile)+(tile*64)+(chunk*64*64)+(64*8*3)]=TEXT_color[font_pointer[(16*16*letter_index)+((16*y)+x_in_letter)]];
	}
	if(TEXTANSWER_line==3)
	{
		for(y=0; y<7&&y<h; y++)TEXTANSWER_answerbox_indexed_gfx_data[((8*1)+(8*(y-0))+x_in_tile)+(tile*64)+(chunk*64*64)+(64*8*4)]=TEXT_color[font_pointer[(16*16*letter_index)+((16*y)+x_in_letter)]];
		for(y=7; y<10&&y<h; y++)TEXTANSWER_answerbox_indexed_gfx_data[((8*0)+(8*(y-7))+x_in_tile)+(tile*64)+(chunk*64*64)+(64*8*5)]=TEXT_color[font_pointer[(16*16*letter_index)+((16*y)+x_in_letter)]];
	}
	//SPLIT FOR LINE 2
	if(TEXTANSWER_line==4)
	{
		for(y=0; y<4&&y<h; y++)TEXTANSWER_answerbox_indexed_gfx_data[((8*4)+(8*(y-0))+x_in_tile)+(tile*64)+(chunk*64*64)+(64*8*5)]=TEXT_color[font_pointer[(16*16*letter_index)+((16*y)+x_in_letter)]];
		for(y=4; y<10&&y<h; y++)TEXTANSWER_answerbox_indexed_gfx_data[((8*0)+(8*(y-4))+x_in_tile)+(tile*64)+(chunk*64*64)+(64*8*6)]=TEXT_color[font_pointer[(16*16*letter_index)+((16*y)+x_in_letter)]];
	}
	//SPLIT FOR LINE 3
	if(TEXTANSWER_line==5)
	{
		for(y=0; y<1&&y<h; y++)TEXTANSWER_answerbox_indexed_gfx_data[((8*7)+(8*(y-0))+x_in_tile)+(tile*64)+(chunk*64*64)+(64*8*6)]=TEXT_color[font_pointer[(16*16*letter_index)+((16*y)+x_in_letter)]];
		for(y=1; y<9&&y<h; y++)TEXTANSWER_answerbox_indexed_gfx_data[((8*0)+(8*(y-1))+x_in_tile)+(tile*64)+(chunk*64*64)+(64*8*7)]=TEXT_color[font_pointer[(16*16*letter_index)+((16*y)+x_in_letter)]];
	}//should be y<10 but i dont want it randomly drawing over the array,its one pixel over ,so cut it off i guess :[
}


//=========================================================================================================================
void TEXTANSWER_draw_letter(const char* answer_text)
{//=========================================================================================================================

	int letter_width = TEXT_get_char_width(font_index(answer_text[TEXTANSWER_string_position]));


	int answer_put_in_space_already=0;

	int x_in_letter=0;
	for(x_in_letter=0; x_in_letter<letter_width; x_in_letter++)
	{
		if(TEXTANSWER_x_in_tile>7)
		{
			TEXTANSWER_x_in_tile=0;
			TEXTANSWER_tile+=1;
		}
		if(TEXTANSWER_tile>7)
		{
			TEXTANSWER_tile=0;
			TEXTANSWER_x_in_tile=0;
			TEXTANSWER_chunk+=1;
		}
		if(TEXTANSWER_chunk<TEXTANSWER_amt_of_chunks)
		{
			TEXTANSWER_draw_column(font_index(answer_text[TEXTANSWER_string_position]),x_in_letter);
		}
		TEXTANSWER_x_in_tile+=1;
	}


	//insert a space between letters
	if(TEXTANSWER_chunk<3 && TEXTANSWER_tile<8 && TEXTANSWER_x_in_tile<8 && !answer_put_in_space_already)
	{
		TEXTANSWER_x_in_tile+=1;
		answer_put_in_space_already=1;
	}
	if(TEXTANSWER_x_in_tile>7)
	{
		if(answer_put_in_space_already)
		{
			TEXTANSWER_x_in_tile=0;
		}
		else
		{
			TEXTANSWER_x_in_tile=1;
		}
		TEXTANSWER_tile+=1;
	}
	if(TEXTANSWER_tile>7)
	{
		TEXTANSWER_tile=0;
		if(answer_put_in_space_already)
		{
			TEXTANSWER_x_in_tile=0;
		}
		else
		{
			TEXTANSWER_x_in_tile=1;
		}

		TEXTANSWER_chunk+=1;
	}

}


//=========================================================================================================================
int TEXTANSWER_get_pixel_length(char* answer)
{//=========================================================================================================================

	int answer_pixel_length=0;
	int temp_answer_position=0;
	int answer_string_length=strlen(answer);

	while(temp_answer_position<answer_string_length)
	{
		answer_pixel_length+=TEXT_get_char_width(font_index(answer[temp_answer_position]));

		if(answer[temp_answer_position]=='<'){int x=0;while(temp_answer_position+x<answer_string_length&&answer[temp_answer_position+x]!='>'){x++;}temp_answer_position+=x;answer_pixel_length--;break;}

		//add a space between letters
		answer_pixel_length++;

		temp_answer_position++;
	}
	return answer_pixel_length-1;
}


//=========================================================================================================================
void TEXTANSWER_clear_answerbox()
{//=========================================================================================================================

	int p=0;
	for(p=0; p<64*64*3; p++)
	{
		TEXTANSWER_answerbox_indexed_gfx_data[p]=TEXT_color[0];
	}
}


//=========================================================================================================================
void TEXTANSWER_move_answerbox()
{//=========================================================================================================================

	int x=0;
	for(x=0; x<TEXTANSWER_amt_of_chunks; x++)
	{
		//HARDWARE_set_sprite_y(TEXTANSWER_answerbox_sprite[x],TEXTANSWER_answerbox_y);
		if(TEXTANSWER_answerbox_sprite[x]!=NULL)TEXTANSWER_answerbox_sprite[x]->screen_y=TEXTANSWER_answerbox_y;
	}
}


//=========================================================================================================================
void TEXTANSWER_draw_answerbox_text(const char* answer_text)
{//=========================================================================================================================

	TEXTANSWER_string_length=strlen((char*)answer_text);

	while(TEXTANSWER_string_position<TEXTANSWER_string_length)
	{
		TEXTANSWER_draw_letter(answer_text);
		TEXTANSWER_string_position++;
	}


	int c=0;
	while(c<TEXTANSWER_amt_of_chunks)
	{
		HARDWARE_update_sprite_texture(TEXTANSWER_answerbox_sprite[c],((c)*64*64));
		c++;
	}

}

//=========================================================================================================================
void TEXTANSWER_answerbox(const char* TEXT_option_buffer,int TEXT_option_length)
{//=========================================================================================================================

	TEXTANSWER_number_of_answers=0;

	int current_answer_length=0;
	int total_answer_length=0;

	//-----------------------------
	//parse the answer strings from the text tag
	//-----------------------------
	while(total_answer_length<TEXT_option_length-2)
	{
		TEXTANSWER_number_of_answers++;
		while(TEXT_option_buffer[total_answer_length+2]!=':'&&total_answer_length<TEXT_option_length-2&&current_answer_length<MAX_ANSWER_LENGTH)
		{

			if(TEXTANSWER_number_of_answers==1)TEXTANSWER_string_1[current_answer_length] = TEXT_option_buffer[total_answer_length+2];
			if(TEXTANSWER_number_of_answers==2)TEXTANSWER_string_2[current_answer_length] = TEXT_option_buffer[total_answer_length+2];
			if(TEXTANSWER_number_of_answers==3)TEXTANSWER_string_3[current_answer_length] = TEXT_option_buffer[total_answer_length+2];
			if(TEXTANSWER_number_of_answers==4)TEXTANSWER_string_4[current_answer_length] = TEXT_option_buffer[total_answer_length+2];
			if(TEXTANSWER_number_of_answers==5)TEXTANSWER_string_5[current_answer_length] = TEXT_option_buffer[total_answer_length+2];
			if(TEXTANSWER_number_of_answers==6)TEXTANSWER_string_6[current_answer_length] = TEXT_option_buffer[total_answer_length+2];

			current_answer_length++;
			total_answer_length++;
		}

		if(TEXTANSWER_number_of_answers==1)TEXTANSWER_string_1[current_answer_length] = '\0';
		if(TEXTANSWER_number_of_answers==2)TEXTANSWER_string_2[current_answer_length] = '\0';
		if(TEXTANSWER_number_of_answers==3)TEXTANSWER_string_3[current_answer_length] = '\0';
		if(TEXTANSWER_number_of_answers==4)TEXTANSWER_string_4[current_answer_length] = '\0';
		if(TEXTANSWER_number_of_answers==5)TEXTANSWER_string_5[current_answer_length] = '\0';
		if(TEXTANSWER_number_of_answers==6)TEXTANSWER_string_6[current_answer_length] = '\0';

		total_answer_length++;
		current_answer_length=0;
	}


	int longest_answer_pixel_length = TEXTANSWER_get_pixel_length(TEXTANSWER_string_1);

	if(TEXTANSWER_number_of_answers==2)
	{
		if(TEXTANSWER_get_pixel_length(TEXTANSWER_string_2)>longest_answer_pixel_length)longest_answer_pixel_length = TEXTANSWER_get_pixel_length(TEXTANSWER_string_2);
	}
	if(TEXTANSWER_number_of_answers==3)
	{
		if(TEXTANSWER_get_pixel_length(TEXTANSWER_string_2)>longest_answer_pixel_length)longest_answer_pixel_length = TEXTANSWER_get_pixel_length(TEXTANSWER_string_2);
		if(TEXTANSWER_get_pixel_length(TEXTANSWER_string_3)>longest_answer_pixel_length)longest_answer_pixel_length = TEXTANSWER_get_pixel_length(TEXTANSWER_string_3);
	}
	if(TEXTANSWER_number_of_answers==4)
	{
		if(TEXTANSWER_get_pixel_length(TEXTANSWER_string_2)>longest_answer_pixel_length)longest_answer_pixel_length = TEXTANSWER_get_pixel_length(TEXTANSWER_string_2);
		if(TEXTANSWER_get_pixel_length(TEXTANSWER_string_3)>longest_answer_pixel_length)longest_answer_pixel_length = TEXTANSWER_get_pixel_length(TEXTANSWER_string_3);
		if(TEXTANSWER_get_pixel_length(TEXTANSWER_string_4)>longest_answer_pixel_length)longest_answer_pixel_length = TEXTANSWER_get_pixel_length(TEXTANSWER_string_4);
	}
	if(TEXTANSWER_number_of_answers==5)
	{
		if(TEXTANSWER_get_pixel_length(TEXTANSWER_string_2)>longest_answer_pixel_length)longest_answer_pixel_length = TEXTANSWER_get_pixel_length(TEXTANSWER_string_2);
		if(TEXTANSWER_get_pixel_length(TEXTANSWER_string_3)>longest_answer_pixel_length)longest_answer_pixel_length = TEXTANSWER_get_pixel_length(TEXTANSWER_string_3);
		if(TEXTANSWER_get_pixel_length(TEXTANSWER_string_4)>longest_answer_pixel_length)longest_answer_pixel_length = TEXTANSWER_get_pixel_length(TEXTANSWER_string_4);
		if(TEXTANSWER_get_pixel_length(TEXTANSWER_string_5)>longest_answer_pixel_length)longest_answer_pixel_length = TEXTANSWER_get_pixel_length(TEXTANSWER_string_5);
	}
	if(TEXTANSWER_number_of_answers==6)
	{
		if(TEXTANSWER_get_pixel_length(TEXTANSWER_string_2)>longest_answer_pixel_length)longest_answer_pixel_length = TEXTANSWER_get_pixel_length(TEXTANSWER_string_2);
		if(TEXTANSWER_get_pixel_length(TEXTANSWER_string_3)>longest_answer_pixel_length)longest_answer_pixel_length = TEXTANSWER_get_pixel_length(TEXTANSWER_string_3);
		if(TEXTANSWER_get_pixel_length(TEXTANSWER_string_4)>longest_answer_pixel_length)longest_answer_pixel_length = TEXTANSWER_get_pixel_length(TEXTANSWER_string_4);
		if(TEXTANSWER_get_pixel_length(TEXTANSWER_string_5)>longest_answer_pixel_length)longest_answer_pixel_length = TEXTANSWER_get_pixel_length(TEXTANSWER_string_5);
		if(TEXTANSWER_get_pixel_length(TEXTANSWER_string_6)>longest_answer_pixel_length)longest_answer_pixel_length = TEXTANSWER_get_pixel_length(TEXTANSWER_string_6);
	}


	if(longest_answer_pixel_length<64)TEXTANSWER_amt_of_chunks=1;
	else if(longest_answer_pixel_length<64*2)TEXTANSWER_amt_of_chunks=2;
	else if(longest_answer_pixel_length>=64*2)TEXTANSWER_amt_of_chunks=3;

	TEXTANSWER_amt_of_sprites=1*TEXTANSWER_amt_of_chunks;
	TEXTANSWER_answerbox_y=192;

	TEXTANSWER_clear_answerbox();


	int TEXTANSWER_chunk=0;
	for(TEXTANSWER_chunk=0; TEXTANSWER_chunk<TEXTANSWER_amt_of_chunks; TEXTANSWER_chunk++)
	{
		TEXTANSWER_answerbox_sprite[TEXTANSWER_chunk] = HARDWARE_create_sprite(TEXTANSWER_GFX,0,1,1.0f,TEXT_textbox[0].screen_x+(64*3)-(64*TEXTANSWER_amt_of_chunks)+(64*TEXTANSWER_chunk),TEXTANSWER_answerbox_y,255);
	}


	TEXTANSWER_selected_answer=0;

	if(TEXTANSWER_number_of_answers>=1){TEXTANSWER_line=0;TEXTANSWER_draw_answerbox_text(TEXTANSWER_string_1);}    //fill with transparent,draw
	if(TEXTANSWER_number_of_answers>=2){TEXTANSWER_line=1;TEXTANSWER_draw_answerbox_text(TEXTANSWER_string_2);}
	if(TEXTANSWER_number_of_answers>=3){TEXTANSWER_line=2;TEXTANSWER_draw_answerbox_text(TEXTANSWER_string_3);}
	if(TEXTANSWER_number_of_answers>=4){TEXTANSWER_line=3;TEXTANSWER_draw_answerbox_text(TEXTANSWER_string_4);}   //new sprite,fill with transparent,draw
	if(TEXTANSWER_number_of_answers>=5){TEXTANSWER_line=4;TEXTANSWER_draw_answerbox_text(TEXTANSWER_string_5);}
	if(TEXTANSWER_number_of_answers==6){TEXTANSWER_line=5;TEXTANSWER_draw_answerbox_text(TEXTANSWER_string_6);}


	GLOBAL_text_engine_state=3;
	GLOBAL_main_sprite_input_off=1;


	while(TEXT_textbox[0].screen_y!=GAME_VIEWPORT_HEIGHT_PIXELS-64-8-(11*TEXTANSWER_number_of_answers)-2||TEXTANSWER_answerbox_y!=TEXT_textbox[0].screen_y+64+8-2)
	{
		whilefix();
	}


	TEXTANSWER_cursor_sprite = HARDWARE_create_sprite(TEXTANSWER_cursor_GFX,0,1,1.0f,TEXT_textbox[0].screen_x+(64*3)-(64*TEXTANSWER_amt_of_chunks)-8,TEXTANSWER_answerbox_y+1+((TEXTANSWER_selected_answer-1)*11),255);

	TEXTANSWER_selected_answer=1;


	while(!BUTTON_ACTION_PRESSED)
	{
		whilefix();

		if(BUTTON_UP_PRESSED)
		{
			TEXTANSWER_selected_answer--;
			if(TEXTANSWER_selected_answer==0)
			{
				TEXTANSWER_selected_answer=TEXTANSWER_number_of_answers;
			}
			while(BUTTON_UP_HELD)
			{
				whilefix();
			}
		}

		if(BUTTON_DOWN_PRESSED)
		{
			TEXTANSWER_selected_answer++;
			if(TEXTANSWER_selected_answer>TEXTANSWER_number_of_answers)
			{
				TEXTANSWER_selected_answer=1;
			}
			while(BUTTON_DOWN_HELD)
			{
				whilefix();
			}
		}

	}

	while(BUTTON_ACTION_HELD)
	{
		whilefix();
	}

	HARDWARE_delete_sprite(TEXTANSWER_cursor_sprite);

	GLOBAL_text_engine_state=4;


	while(TEXTANSWER_answerbox_y<GAME_VIEWPORT_HEIGHT_PIXELS)
	{
		whilefix();
	}

	GLOBAL_main_sprite_input_off=0;


	int n=0;
	for(n=0; n<TEXTANSWER_amt_of_sprites; n++)
	{
		HARDWARE_delete_sprite(TEXTANSWER_answerbox_sprite[n]);
	}

	if(TEXTANSWER_selected_answer==1)strcpy(TEXTANSWER_selected_answer_string,TEXTANSWER_string_1);
	if(TEXTANSWER_selected_answer==2)strcpy(TEXTANSWER_selected_answer_string,TEXTANSWER_string_2);
	if(TEXTANSWER_selected_answer==3)strcpy(TEXTANSWER_selected_answer_string,TEXTANSWER_string_3);
	if(TEXTANSWER_selected_answer==4)strcpy(TEXTANSWER_selected_answer_string,TEXTANSWER_string_4);
	if(TEXTANSWER_selected_answer==5)strcpy(TEXTANSWER_selected_answer_string,TEXTANSWER_string_5);
	if(TEXTANSWER_selected_answer==6)strcpy(TEXTANSWER_selected_answer_string,TEXTANSWER_string_6);
}

