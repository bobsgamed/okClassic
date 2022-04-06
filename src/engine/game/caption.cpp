

#include "../../main.h"
//#include "caption.h"


CAPTION* first_CAPTION=NULL;
CAPTION* pause_CAPTION=NULL;
int caption_vbl_var=0;

//=========================================================================================================================
int CAPTION_get_char_width(int font_height, int* font_pointer, int letter_index)
{//=========================================================================================================================

	if(letter_index==-1)return 0;

	int x=0;
	int y=0;
	int w=0;
	for(x=15;x>=0;x--)
		for(y=0;y<font_height;y++)
			if(font_pointer[(letter_index*16*16)+(y*16)+x]!=0)
			{
				w=x+1;
				x=-1;
				y=font_height;
				break;
			}

	if(letter_index==font_index(' '))w=3;//WIDTH OF SPACE IS DETERMINED HERE

	return w;
}

//=========================================================================================================================
void CAPTION_draw_blank_column(CAPTION* c)
{//=========================================================================================================================

	int* gfxdata = c->gfx[c->chunk]->indexed_gfx_data;

	if(c->multiline==0)
	{
		int y;
		int h = c->font_height;
		for(y=0; y<8&&y<h+2; y++)gfxdata[((8*0)+(8*(y-0))+c->x_in_tile)+(c->tile*64)+(64*8*0)]=c->colors[0];
		for(y=8; y<14&&y<h+2;y++)gfxdata[((8*0)+(8*(y-8))+c->x_in_tile)+(c->tile*64)+(64*8*1)]=c->colors[0];
	}
	else
	{
		int y;
		int h = c->font_height;
		if(c->line==0)
		{
			for(y=0; y<8&&y<h; y++)gfxdata[((8*0)+(8*(y-0))+c->x_in_tile)+(c->tile*64)+(64*8*0)]=c->colors[0];
			for(y=8; y<10&&y<h;y++)gfxdata[((8*0)+(8*(y-8))+c->x_in_tile)+(c->tile*64)+(64*8*1)]=c->colors[0];
		}
		if(c->line==1)
		{
			for(y=0; y<5&&y<h; y++)gfxdata[((8*3)+(8*(y-0))+c->x_in_tile)+(c->tile*64)+(64*8*1)]=c->colors[0];
			for(y=5; y<10&&y<h;y++)gfxdata[((8*0)+(8*(y-5))+c->x_in_tile)+(c->tile*64)+(64*8*2)]=c->colors[0];
		}
		if(c->line==2)
		{
			for(y=0; y<2&&y<h; y++)gfxdata[((8*6)+(8*(y-0))+c->x_in_tile)+(c->tile*64)+(64*8*2)]=c->colors[0];
			for(y=2; y<10&&y<h;y++)gfxdata[((8*0)+(8*(y-2))+c->x_in_tile)+(c->tile*64)+(64*8*3)]=c->colors[0];
		}
	}
}
//=========================================================================================================================
void CAPTION_draw_column(CAPTION* c,int x_in_letter, int letter_index)
{//=========================================================================================================================

	int* gfxdata = c->gfx[c->chunk]->indexed_gfx_data;

	if(c->multiline==0)
	{
		int y;
		int h = c->font_height;
										gfxdata[((8*0)+(8*(0-0))+c->x_in_tile)+(c->tile*64)+(64*8*0)]=c->colors[0];
		for(y=0; y<7&&y<h+1; y++)gfxdata[((8*1)+(8*(y-0))+c->x_in_tile)+(c->tile*64)+(64*8*0)]=c->colors[(int)c->font_pointer[(letter_index*16*16)+((16*y)+x_in_letter)]];
		for(y=7; y<12&&y<h+1;y++)gfxdata[((8*0)+(8*(y-7))+c->x_in_tile)+(c->tile*64)+(64*8*1)]=c->colors[(int)c->font_pointer[(letter_index*16*16)+((16*y)+x_in_letter)]];
								if(h==12)gfxdata[((8*5)+(8*(0-0))+c->x_in_tile)+(c->tile*64)+(64*8*1)]=c->colors[0];
	}
	else
	{
		int y;
		int h = c->font_height;
		if(c->line==0)
		{
			for(y=0; y<8&&y<h; y++)gfxdata[((8*0)+(8*(y-0))+c->x_in_tile)+(c->tile*64)+(64*8*0)]=c->colors[(int)c->font_pointer[(letter_index*16*16)+((16*y)+x_in_letter)]];
			for(y=8; y<10&&y<h;y++)gfxdata[((8*0)+(8*(y-8))+c->x_in_tile)+(c->tile*64)+(64*8*1)]=c->colors[(int)c->font_pointer[(letter_index*16*16)+((16*y)+x_in_letter)]];
		}
		if(c->line==1)
		{
			for(y=0; y<5&&y<h; y++)gfxdata[((8*3)+(8*(y-0))+c->x_in_tile)+(c->tile*64)+(64*8*1)]=c->colors[(int)c->font_pointer[(letter_index*16*16)+((16*y)+x_in_letter)]];
			for(y=5; y<10&&y<h;y++)gfxdata[((8*0)+(8*(y-5))+c->x_in_tile)+(c->tile*64)+(64*8*2)]=c->colors[(int)c->font_pointer[(letter_index*16*16)+((16*y)+x_in_letter)]];
		}
		if(c->line==2)
		{
			for(y=0; y<2&&y<h; y++)gfxdata[((8*6)+(8*(y-0))+c->x_in_tile)+(c->tile*64)+(64*8*2)]=c->colors[(int)c->font_pointer[(letter_index*16*16)+((16*y)+x_in_letter)]];
			for(y=2; y<10&&y<h;y++)gfxdata[((8*0)+(8*(y-2))+c->x_in_tile)+(c->tile*64)+(64*8*3)]=c->colors[(int)c->font_pointer[(letter_index*16*16)+((16*y)+x_in_letter)]];
		}
	}

}
//=========================================================================================================================
void CAPTION_draw_letter(CAPTION* c, int letter_index)
{//=========================================================================================================================

	int letter_width = CAPTION_get_char_width(c->font_height,c->font_pointer,letter_index);

	if(c->TEXT_string_position==0&&c->chunk<c->chunks && c->tile<8 && c->x_in_tile<8 && c->line<3)
	{
		CAPTION_draw_blank_column(c);
		c->x_in_tile=1;
	}

	int caption_put_in_space_already=0;

	int x_in_letter=0;
	for(x_in_letter=0;x_in_letter<letter_width;x_in_letter++)
	{
		if(c->x_in_tile>7)
		{
			c->x_in_tile=0;
			c->tile+=1;
		}

		if(c->tile>7)
		{
			c->tile=0;
			c->x_in_tile=0;
			c->chunk+=1;
		}

		if(c->multiline==0)
		{
			if(c->chunk<c->chunks)
			{
				CAPTION_draw_column(c,x_in_letter,letter_index);
				c->x_in_tile+=1;
			}
		}
		else
		{
			if(c->chunk>=c->chunks)
			{
				c->line+=1;
				c->chunk=0;
				c->x_in_tile=0;
				c->tile=0;
			}

			if(c->line<3)
			{
				CAPTION_draw_column(c,x_in_letter,letter_index);
				c->x_in_tile+=1;
			}
		}
	}


	//-----------------------------
	//insert space (blank column)
	//-----------------------------

	if(c->font_id!=FONT_OUTLINED_ID)
	{
		if(c->chunk<c->chunks && c->tile<8 && c->x_in_tile<8 && !caption_put_in_space_already && c->line<3)
		{
			CAPTION_draw_blank_column(c);
			c->x_in_tile+=1;
			caption_put_in_space_already=1;
		}

		if(c->x_in_tile>7)
		{

			if(caption_put_in_space_already)
			{
				c->x_in_tile=0;
				c->tile+=1;
			}
			else
			{
				c->x_in_tile=0;
				c->tile+=1;

				if(c->tile<8)
				{
					CAPTION_draw_blank_column(c);
					c->x_in_tile=1;
				}
			}
		}

		if(c->tile>7)
		{
			c->tile=0;

			if(caption_put_in_space_already)
			{
				c->x_in_tile=0;
				c->chunk+=1;
			}
			else
			{
				c->x_in_tile=0;
				c->chunk+=1;

				if(c->multiline==0)
				{
					if(c->chunk<c->chunks)
					{
						CAPTION_draw_blank_column(c);
						c->x_in_tile=1;
					}
				}
				else
				{
					if(c->chunk>=c->chunks)
					{
						c->line+=1;
						c->chunk=0;
						c->x_in_tile=0;
						c->tile=0;
					}

					if(c->line<3)
					{
						CAPTION_draw_blank_column(c);
						c->x_in_tile=1;
					}
				}
			}
		}
	}
	//if(c->TEXT_string_position==strlen((char*)c->text)){CAPTION_draw_blank_column(charset,charset_width,c->x_in_tile,c->tile,caption_box_sprite_Bitmap,c->chunk ,0,c->chunks,c->font_height,caption_colors); c->x_in_tile++;}

	//END INSERT SPACE================================================
}




//=========================================================================================================================
int CAPTION_get_pixel_length(const char* text,int font_id)
{//=========================================================================================================================

	int font_height=0;
	int* font_pointer = NULL;

	if(font_id==FONT_OUTLINED_ID)	{font_pointer = FONT_OUTLINED_indexed_gfx_data; 	font_height = FONT_OUTLINED_HEIGHT;}
	if(font_id==FONT_NORMAL_ID)		{font_pointer = FONT_NORMAL_indexed_gfx_data; 		font_height = FONT_NORMAL_HEIGHT;}
	if(font_id==FONT_HUGE_ID)		{font_pointer = FONT_HUGE_indexed_gfx_data; 		font_height = FONT_HUGE_HEIGHT;}
	if(font_id==FONT_SMALL_ID)		{font_pointer = FONT_SMALL_indexed_gfx_data; 		font_height = FONT_SMALL_HEIGHT;}
	if(font_id==FONT_TINY_ID)		{font_pointer = FONT_TINY_indexed_gfx_data; 		font_height = FONT_TINY_HEIGHT;}
	if(font_id==FONT_BOB_ID)		{font_pointer = FONT_BOB_indexed_gfx_data; 			font_height = FONT_BOB_HEIGHT;}

	int pixel_length=0;
	int temp_position=0;

	int length = strlen(text);

	while(temp_position<length)
	{

		//if(text[temp_position]=='<') { int x=0; while(temp_position+x<length&&text[temp_position+x]!='>'){x++;} temp_position+=x; if(font_id!=FONT_OUTLINED_ID)pixel_length--;}
		pixel_length+=CAPTION_get_char_width(font_height,font_pointer,font_index(text[temp_position]));

		//add in a space between letters
		if(font_id!=FONT_OUTLINED_ID)pixel_length++;

		temp_position++;
	}
	pixel_length++;//for the space at the beginning

 	return pixel_length;
}


//=========================================================================================================================**
int CAPTION_get_next_word_length(CAPTION* c)
{//=========================================================================================================================**

	int pixel_length=0;
	int temp_position=c->TEXT_string_position;

	//starting on the beginning or on a space, calculate each letter length until we hit another space
	while(
			temp_position<(c->TEXT_length)
			&&
			(
				temp_position==c->TEXT_string_position
				||
				c->text[temp_position]!=' '
			)
		)
	{
		//handle tags
		//if(c->text[temp_position]=='<') {int x=0; while(temp_position+x<c->TEXT_length&&c->text[temp_position+x]!='>'){x++;} temp_position+=x; if(c->font_id!=FONT_OUTLINED_ID)pixel_length--;}

		pixel_length += CAPTION_get_char_width(c->font_height,c->font_pointer,font_index(c->text[temp_position]));

		//add in a space between letters
		if(c->font_id!=FONT_OUTLINED_ID)pixel_length++;

		temp_position++;
	}

	return pixel_length;
}


//=========================================================================================================================
void CAPTION_make_caption(CAPTION**cpp,int screen,int x,int y,int seconds,const char* text,int font_id,int text_color,int bg_color, int layer, float scale) //-1 seconds for stay open until manual delete :)
{//=========================================================================================================================

	if(cpp==NULL||(cpp!=NULL&&*cpp==NULL))
	{

		//-----------------------------
		//init caption struct
		//-----------------------------

		//allocate caption
		CAPTION* caption = (CAPTION*)malloc(sizeof(CAPTION));

		//get length
		caption->TEXT_length = strlen((char*)text);

		caption->sprite[0]=NULL;
		caption->sprite[1]=NULL;
		caption->sprite[2]=NULL;
		caption->sprite[3]=NULL;

		caption->gfx[0]=NULL;
		caption->gfx[1]=NULL;
		caption->gfx[2]=NULL;
		caption->gfx[3]=NULL;

		//allocate new string to store text
		char* newtext = (char*)malloc((caption->TEXT_length+1)*sizeof(char));
		sprintf(newtext,text);
		caption->text = newtext;

		caption->caption_pp = (struct CAPTION**)cpp;
		caption->next=NULL;


		caption->chunks=0;
		caption->screen_x=x;
		caption->screen_y=y;
		caption->layer=layer;
		caption->scale=scale;

		caption->main_sprite_map_x=0;
		caption->main_sprite_map_y=0;

		if(PLAYER_npc!=NULL)
		{
			caption->main_sprite_map_x=PLAYER_npc->MAP_x;
			caption->main_sprite_map_y=PLAYER_npc->MAP_y;
		}

		caption->width=0;

		caption->time_left=seconds;

		caption->font_id = font_id;
		caption->color_bg = bg_color;
		caption->color_txt = text_color;

		caption->multiline=0;

		caption->actioncaptiontype=ACTIONCAPTIONTYPE_NONE;
		caption->npc=NULL;
		caption->range_x=0;
		caption->range_y=0;

		caption->x_in_tile=0;
		caption->tile=0;
		caption->chunk=0;
		caption->line=0;

		caption->TEXT_string_position=0;

		caption->font_id=font_id;


		//-----------------------------
		//set color
		//-----------------------------

		//color 0 = bg color
		//color 1 = text color
		//color 2 = antialiasing color

		caption->colors[0]=bg_color;
		caption->colors[1]=text_color;

		if(bg_color==BLACK||bg_color==CLEAR)caption->colors[2]=text_color+1;else caption->colors[2]=text_color-1;

		if(text_color==WHITE)caption->colors[2]=GRAY;
		if(text_color==BLACK)caption->colors[2]=LIGHTGRAY;

		//if using outline font background color is automatically set to clear, and bg_color becomes the outline color.
		if(caption->font_id==FONT_OUTLINED_ID){caption->colors[0]=CLEAR; caption->colors[1]=text_color; caption->colors[2]=bg_color;}

		//-----------------------------
		//set font
		//-----------------------------
		if(caption->font_id==FONT_OUTLINED_ID)	{caption->font_pointer = FONT_OUTLINED_indexed_gfx_data; 	caption->font_height = FONT_OUTLINED_HEIGHT;}
		if(caption->font_id==FONT_NORMAL_ID)	{caption->font_pointer = FONT_NORMAL_indexed_gfx_data; 	caption->font_height = FONT_NORMAL_HEIGHT;}
		if(caption->font_id==FONT_HUGE_ID)		{caption->font_pointer = FONT_HUGE_indexed_gfx_data; 		caption->font_height = FONT_HUGE_HEIGHT;}
		if(caption->font_id==FONT_SMALL_ID)	{caption->font_pointer = FONT_SMALL_indexed_gfx_data; 		caption->font_height = FONT_SMALL_HEIGHT;}
		if(caption->font_id==FONT_TINY_ID)		{caption->font_pointer = FONT_TINY_indexed_gfx_data; 		caption->font_height = FONT_TINY_HEIGHT;}
		if(caption->font_id==FONT_BOB_ID)		{caption->font_pointer = FONT_BOB_indexed_gfx_data; 		caption->font_height = FONT_BOB_HEIGHT;}



		//-----------------------------
		//figure out if it is multiline
		//-----------------------------


			//text string includes newline char
			int temp_position=0;
			while(temp_position<caption->TEXT_length)
			{
				if(caption->text[temp_position]=='\n')caption->multiline=1;

				temp_position++;
			}


		///determine how many lines it will need
		//if total pixels > 3 lines, error
		//if more than 2 newline chars, error
		//otherwise, draw words until word wont fit or newline char, split line.
		//if more than 3 lines, error



		//-----------------------------
		//find the raw pixel length of the text (not split into words)
		//-----------------------------
		int total_pixel_length=0;

		temp_position=0;
		while(temp_position<caption->TEXT_length)
		{
			//handle tags (THERE SHOULD NOT BE TAGS IN CAPTIONS)
			if(caption->text[temp_position]=='<')
			{
				ERROR_set_error("found a tag inside caption string.");
				//int x=0; while(temp_position+x<caption->TEXT_length&&caption->text[temp_position+x]!='>'){x++;} temp_position+=x; if(caption->font_id!=FONT_OUTLINED_ID)total_pixel_length--;
			}

			total_pixel_length += CAPTION_get_char_width(caption->font_height,caption->font_pointer,font_index(caption->text[temp_position]));

			//add in space between letters
			if(caption->font_id!=FONT_OUTLINED_ID)total_pixel_length++;

			temp_position++;
		}
		total_pixel_length++;//for the space at the beginning


		//-----------------------------
		//determine how many 64*64 chunks the line will use (this is from DS sprite limitation, i could change this to a single sprite quite easily now)
		//-----------------------------

		if(total_pixel_length<=64*4)	caption->chunks=4;
		if(total_pixel_length<=64*3)	caption->chunks=3;
		if(total_pixel_length<=64*2)	caption->chunks=2;
		if(total_pixel_length<=64*1)	caption->chunks=1;

		//if it's a single string but it's longer than 4 chunks, it's multiline.
		if(total_pixel_length>64*4){caption->chunks=4; caption->multiline=1;}

		//if it's less than 4 chunks but greater than 3 chunks, make it multiline anyway so it splits nicely.
		if(total_pixel_length>64*2)caption->multiline=1; ///was 3 chunks, lets see

		//if it's still a single line caption, the longest pixel length is the total.
		if(caption->multiline==0)caption->width=total_pixel_length;

		//-----------------------------
		//allocate the chunk GFX and indexed gfx data
		//-----------------------------

		int c=0;
		for(c=0;c<caption->chunks;c++)
		{

			//make new GFX struct for caption chunk
			GFX* caption_chunk_GFX = (GFX*)malloc(sizeof(GFX));

			//init the GFX struct
			sprintf(caption_chunk_GFX->FileName,"caption temp");
			caption_chunk_GFX->indexed_gfx_data=NULL;
			caption_chunk_GFX->data_size_x=64;
			caption_chunk_GFX->data_size_y=32;
			caption_chunk_GFX->texture_size_x=64;
			caption_chunk_GFX->texture_size_y=32;
			caption_chunk_GFX->IndexInCachedTextureIDArray=-2;

			caption_chunk_GFX->shadow=0;

			caption_chunk_GFX->hq2x=0;
			caption_chunk_GFX->kid=0;
			caption_chunk_GFX->adult=0;
			caption_chunk_GFX->car=0;
			caption_chunk_GFX->bike=0;
            caption_chunk_GFX->generic=0;

            caption_chunk_GFX->content_size_x=64;
            caption_chunk_GFX->content_size_y=32;

			//make new memory to hold caption chunk data
			caption_chunk_GFX->indexed_gfx_data = (int*)malloc(64*32*sizeof(int));//64*32


			//fill the chunk GFX indexed gfx data with 0
			int i=0;
			for(i=0;i<64*32;i++)caption_chunk_GFX->indexed_gfx_data[i]=0;//caption_box_sprite_Bitmap[64*32*c+i];

			//set caption struct to point to GFX struct
			caption->gfx[c]=caption_chunk_GFX;
		}


		//-----------------------------
		//fill the indexed gfx data with text
		//-----------------------------
		while(caption->TEXT_string_position<caption->TEXT_length)
		{

			//-----------------------------
			//check each word length and start a new line if it is too long to fit
			//-----------------------------
			if(caption->multiline)
			{
				if(caption->TEXT_string_position==0||caption->text[caption->TEXT_string_position]==' ')//if we're on a space
				{

					int next_word_length=CAPTION_get_next_word_length(caption);

					if(
						(caption->x_in_tile+caption->tile*8+caption->chunk*64+next_word_length>(64*4))//if the next word won't fit in the remaining space
						||
						(caption->text[caption->TEXT_string_position]=='\n')//or its a newline
						||
						(
								//if it will fit on two lines but not one, split it nicely across 2
							(	//if its the first line and the text is over half the full pixels, evenly split the text to distribute nicely on two lines.
								(
									caption->x_in_tile+caption->tile*8+caption->chunk*64+next_word_length
									>
									(int)((float)total_pixel_length/2)+16//	(float)((float)total_pixel_length/(float)(64*4))	)+16 //16 is to make the top line longer than the bottom line
										///should be 64*64*num_lines, i think
								)
								&&
								caption->line==0
							)
						)
					)
					{
						if(caption->text[caption->TEXT_string_position]==' ')caption->TEXT_string_position++;//skip the space on the newline

						caption->line++;
						caption->chunk=0;
						caption->x_in_tile=0;
						caption->tile=0;

						if(caption->line>2)ERROR_set_error("caption has more than 3 lines!");
					}
				}
			}

			if(caption->text[caption->TEXT_string_position]!='\n')//dont draw a newline
			{
				int i = font_index(caption->text[caption->TEXT_string_position]);
				CAPTION_draw_letter(caption,i);

				//check to see if this line is the longest so far, use it to set width
				int longest=caption->x_in_tile+caption->tile*8+caption->chunk*64;
				if(longest>caption->width)caption->width=longest;
			}

			caption->TEXT_string_position++;
		}


		//-----------------------------
		//set x and y values
		//-----------------------------

		c=0;
		for(c=0;c<caption->chunks;c++)
		{

			int screen_x=caption->screen_x;

			if(caption->screen_x==CAPTION_CENTERED_OVER_SPRITE)
			{
				if(PLAYER_npc!=NULL)
				{
					screen_x=((PLAYER_npc->screen_x+PLAYER_npc->size_x/2)-((caption->width)/2));
					caption->screen_y=(PLAYER_npc->screen_y-10);
				}
			}
			else if(caption->screen_x==CAPTION_CENTERED_SCREEN)
			{
				screen_x=((GAME_VIEWPORT_WIDTH_PIXELS/2)-((caption->width)/2));
				caption->screen_y=(GAME_VIEWPORT_HEIGHT_PIXELS/2);
			}
			else if(caption->screen_x==CAPTION_CENTERED_X)
			{
				screen_x=((GAME_VIEWPORT_WIDTH_PIXELS/2)-((caption->width)/2));
			}
			else screen_x=caption->screen_x;

			if(screen_x+caption->width>=GAME_VIEWPORT_WIDTH_PIXELS)screen_x=GAME_VIEWPORT_WIDTH_PIXELS-(caption->width+1);
			if(screen_x<0)screen_x=0;

			///disabled for castroom

			//if(caption->screen_y+caption->font_height>=GAME_VIEWPORT_HEIGHT_PIXELS)caption->screen_y=GAME_VIEWPORT_HEIGHT_PIXELS-(caption->font_height+1);
			//if(caption->screen_y<0)caption->screen_y=0;


			//-----------------------------
			//create the sprite
			//-----------------------------
			caption->sprite[c]=HARDWARE_create_sprite(caption->gfx[c],0,caption->layer,caption->scale,screen_x+64*c,caption->screen_y,255);

		}

		//-----------------------------
		//append the new caption struct to the end of the first_CAPTION linked list
		//-----------------------------
		if(caption!=NULL)
		{
			if(first_CAPTION==NULL)first_CAPTION=caption;
				else
				{
					CAPTION* current_caption = first_CAPTION;
					while(current_caption->next!=NULL)
					{
					 current_caption = (CAPTION*)current_caption->next;
					}
					current_caption->next = (struct CAPTION*)caption;
				}
		}


		//return the caption pointer so it can be controlled from other parts of the program
		//this makes it so external pointers dont have to be set NULL after deleting them, they are already set to NULL from inside the caption itself
		if(cpp!=NULL)*cpp=caption;

		//caps_created++;

	}

}





//=========================================================================================================================
void CAPTION_delete_caption(CAPTION* delete_caption)
{//=========================================================================================================================

	if(delete_caption!=NULL)
	{

		if(delete_caption==first_CAPTION)
		{
			//if its not the only caption, make the next one the first one
			if(first_CAPTION->next!=NULL)first_CAPTION=(CAPTION*)first_CAPTION->next;
				else first_CAPTION=NULL;//else just set the first one to NULL
		}
		else
			//if its the last one
			if(delete_caption->next==NULL)
			{
				CAPTION* current_caption = first_CAPTION;

				//get to the one before the last one
				while((CAPTION*)current_caption->next!=(CAPTION*)delete_caption)
				{
					current_caption = (CAPTION*)current_caption->next;
				}
				current_caption->next = NULL;//set the next to NULL
			}
			else //remove the deleted one from the linked list and connect the previous and next
				{
					CAPTION* current_caption = first_CAPTION;
					while((CAPTION*)current_caption->next!=(CAPTION*)delete_caption&&current_caption->next!=NULL)
					{
						current_caption = (CAPTION*)current_caption->next;
					}
					current_caption->next = delete_caption->next;
				}


		if(delete_caption->text!=NULL)
			free(delete_caption->text);

		delete_caption->text=NULL;

		 int c=0;
		 for(c=0;c<delete_caption->chunks;c++)
		 {

			//delete each chunk sprite
			if(delete_caption->sprite[c]!=NULL)
			{
				//delete each chunk texture and graphics array
				///these textures are made custom per-caption and arent indexed anywhere.
				///have to delete them before deleting the gfx slot.
				if(glIsTexture(delete_caption->sprite[c]->texture_id))glDeleteTextures(1,(GLuint*)&delete_caption->sprite[c]->texture_id);

				HARDWARE_delete_sprite(delete_caption->sprite[c]);
			}
			delete_caption->sprite[c]=NULL;

		 }

		 delete_caption->screen_x=0;
		 delete_caption->screen_y=0;




		c=0;
		for(c=0;c<4;c++)
		if(delete_caption->gfx[c]!=NULL)
		{
			if(delete_caption->gfx[c]->indexed_gfx_data!=NULL)free(delete_caption->gfx[c]->indexed_gfx_data);
			free(delete_caption->gfx[c]);
		}


		if(delete_caption->caption_pp!=NULL)//if the caption has an external pointer
		{
			if(*(delete_caption->caption_pp)!=NULL)*(delete_caption->caption_pp)=NULL;//if that external pointer isn't NULL, set it to NULL
			delete_caption->caption_pp=NULL;//remove external pointer (not necessary)
		}



		free(delete_caption);

	}

}


//=========================================================================================================================
void CAPTION_replace_text(CAPTION* caption,const char *text)
{//=========================================================================================================================

	if(caption!=NULL)
	{
		int screen_x = caption->screen_x;
		int screen_y = caption->screen_y;
		int layer=caption->layer;
		float scale=caption->scale;
		int time_left = caption->time_left;
		int font_id = caption->font_id;
		int color_bg = caption->color_bg;
		int color_txt = caption->color_txt;

		struct CAPTION** caption_pp = caption->caption_pp;

		CAPTION_delete_caption(caption);

		CAPTION_make_caption((CAPTION**)caption_pp,screen,screen_x,screen_y,time_left,text,font_id,color_txt,color_bg,layer,scale);


	}
	else
	{
		ERROR_set_error("tried to replace a NULL caption, find out why! \n");
	}

}


//=========================================================================================================================
void CAPTION_vbl()
{//=========================================================================================================================



	//just set set the time left

	caption_vbl_var++;

	if(first_CAPTION!=NULL)
	{
		CAPTION* current_caption = first_CAPTION;
		bool stop=0;
		while(stop==0)
		{
			if(caption_vbl_var%60==0&&current_caption->time_left>0)current_caption->time_left--;
			if(current_caption->next!=NULL)current_caption=(CAPTION*)current_caption->next;else stop=1;
		}
	}



	//int caption_chunks_onscreen[2]={0,0};





}
//=========================================================================================================================
void CAPTION_main()
{//=========================================================================================================================

//fprintf(stderr,"captions-------------------------------------\n");

	//check each caption for time left, if there is no time left, delete it.

	if(first_CAPTION!=NULL) //dont bother if theres no captions
	{
		CAPTION* current_caption = first_CAPTION;
		CAPTION* next_caption= first_CAPTION;
		bool stop=0;
		while(stop==0)
		{
			next_caption=(CAPTION*)current_caption->next; //dont care if its NULL,the next line checks


			if(	next_caption!=NULL//if its not the last one
				&&
				(
					next_caption->time_left==0//and theres no time left
					||
					(
						next_caption->time_left==CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES//or delete when sprite moves
						&&
						(
							PLAYER_npc!=NULL
							&&
							(
								PLAYER_npc->MAP_x!=next_caption->main_sprite_map_x//and sprite has moved
								||
								PLAYER_npc->MAP_y!=next_caption->main_sprite_map_y
							)
						)
					)
				)
			)
			CAPTION_delete_caption(next_caption);

			//fprintf(stderr,"\n");
			//fprintf(stderr,"sprite id 1 %d \n",current_caption->PLAYER_id[0]);
			//fprintf(stderr,"gfx slot 1 %d \n",current_caption->gfx_slot[0]);
			//fprintf(stderr,"chunks %d \n",current_caption->chunks);
			//fprintf(stderr,"label %s \n",current_caption->label);
			//fprintf(stderr,"multiline %d \n",current_caption->multiline);



			//the reason i use next_caption is because delete_caption removes from the linked list and joins the parts,if i delete the current_caption it actually skips one
			// first->curr|here|->next
			//			|deleted|
			// first->next|here|->next
			if(current_caption->next!=NULL)current_caption=(CAPTION*)current_caption->next;else stop=1;
		}



		if(	first_CAPTION->time_left==0
			||
			(first_CAPTION->time_left==CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES
				&&(PLAYER_npc->MAP_x!=first_CAPTION->main_sprite_map_x||PLAYER_npc->MAP_y!=first_CAPTION->main_sprite_map_y)
			)
		)
		{CAPTION_delete_caption(first_CAPTION);}
	}



	//int capcount=0;

/*
	if(first_CAPTION!=NULL)
	{
		CAPTION* current_caption = first_CAPTION;
		bool stop=0;
		while(stop==0)
		{
			capcount++;

			if(current_caption->replacemeonvbl==1)
			{
				int screen = current_caption->screen;

				int screen_x = current_caption->screen_x;
				int screen_y = current_caption->screen_y;
				int prio=current_caption->prio;
				float scale=current_caption->scale;
				int time_left = current_caption->time_left;
				int font_id = current_caption->font_id;
				int color_bg = current_caption->color_bg;
				int color_txt = current_caption->color_txt;
				char* label = current_caption->newlabel;
				struct CAPTION** caption_pp = current_caption->caption_pp;
				bool deletemeonvbl = current_caption->deletemeonvbl;
				bool multiline=current_caption->multiline;

				if(current_caption->next!=NULL)
				{
					CAPTION* tempcaption = current_caption;
					current_caption=(CAPTION*)current_caption->next;
					TEXT_delete_caption_vbl(tempcaption);
				}
				else
				{
					stop=1;
					TEXT_delete_caption_vbl(current_caption);
				}

				if(multiline==0)CAPTION_make_caption((CAPTION**)caption_pp,screen,screen_x,screen_y,time_left,label,font_id,color_txt,color_bg,prio,scale);
				else CAPTION_make_multiline_caption((CAPTION**)caption_pp,screen,screen_x,screen_y,time_left,label,font_id,color_txt,color_bg,prio,scale);
				((CAPTION*)caption_pp)->deletemeonvbl=deletemeonvbl;
				((CAPTION*)caption_pp)->replacemeonvbl=0;

			}
			else
			if(current_caption->deletemeonvbl==1)
			{
				if(current_caption->next!=NULL)
				{
					CAPTION* tempcaption = current_caption;
					current_caption=(CAPTION*)current_caption->next;
					CAPTION_delete_caption(tempcaption);
				}
				else
				{
					stop=1;
					CAPTION_delete_caption(current_caption);
				}
			}
			else
			{

				//int c=0;
				//for(c=0;c<current_caption->chunks;c++)if(current_caption->PLAYER_id[c]!=-1){HARDWARE_delete_sprite(current_caption->screen,current_caption->PLAYER_id[c]);current_caption->PLAYER_id[c]=-1;}
				if(current_caption->next!=NULL)current_caption=(CAPTION*)current_caption->next;else stop=1;
			}
		}
	}*/


	//go through all caption chunks and make set sprite xy

	if(first_CAPTION!=NULL)
	{
		bool stop=0;
		CAPTION* current_caption = first_CAPTION;


		while(stop==0)
		{

			int c=0;
			for(c=0;c<current_caption->chunks;c++)
			{


				int screen_x=current_caption->screen_x;


				//set caption screen x
				if(current_caption->screen_x==CAPTION_CENTERED_OVER_SPRITE)
				{
					if(PLAYER_npc!=NULL)
					{
						screen_x=((PLAYER_npc->screen_x+PLAYER_npc->size_x/2)-((current_caption->width)/2));
						current_caption->screen_y=(PLAYER_npc->screen_y-10);
					}

				}
				else
				if(current_caption->screen_x==CAPTION_CENTERED_SCREEN)
				{
					screen_x=((GAME_VIEWPORT_WIDTH_PIXELS/2)-((current_caption->width)/2));
					current_caption->screen_y=(GAME_VIEWPORT_HEIGHT_PIXELS/2);

				}
				else if(current_caption->screen_x==CAPTION_CENTERED_X)
				{
					screen_x=((GAME_VIEWPORT_WIDTH_PIXELS/2)-((current_caption->width)/2));
				}
				else screen_x=current_caption->screen_x;

				if(screen_x+current_caption->width>=GAME_VIEWPORT_WIDTH_PIXELS)screen_x=GAME_VIEWPORT_WIDTH_PIXELS-(current_caption->width+1);
				if(screen_x<0)screen_x=0;

				//set caption screen y
				//dont let caption wrap offscreen
				///turned off for castroom
				/*
				if(current_caption->screen_y+current_caption->font_height>=GAME_VIEWPORT_HEIGHT_PIXELS)
				{
					current_caption->screen_y=GAME_VIEWPORT_HEIGHT_PIXELS-(current_caption->font_height+1);
				}

				if(current_caption->screen_y<0)current_caption->screen_y=0;*/

				if(current_caption->sprite[c]!=NULL)current_caption->sprite[c]->scale=current_caption->scale;
				if(current_caption->sprite[c]!=NULL)current_caption->sprite[c]->screen_x=(screen_x+64*c)*(current_caption->scale);
				if(current_caption->sprite[c]!=NULL)current_caption->sprite[c]->screen_y=current_caption->screen_y*(current_caption->scale);
			}
			if(current_caption->next!=NULL)current_caption=(CAPTION*)current_caption->next;else stop=1;
		}
	}

	//caps_existing=capcount;




}
//=========================================================================================================================
void CAPTION_delete_all_captions()
{//=========================================================================================================================
	while(first_CAPTION!=NULL)
	{
		CAPTION* current_caption=first_CAPTION;
		while(current_caption->next!=NULL)current_caption=(CAPTION*)current_caption->next;
		CAPTION_delete_caption(current_caption);
	}
}
//=========================================================================================================================
void CAPTION_pause()
{//=========================================================================================================================
		//delete all sprites but keep captions
		//set pause_CAPTION to first_CAPTION
		//set first_CAPTION to NULL
	pause_CAPTION= first_CAPTION;
	first_CAPTION=NULL;

	if(pause_CAPTION!=NULL)
	{
		CAPTION* current_caption = pause_CAPTION;
		bool stop=0;
		while(stop==0)
		{
			int c=0;
		 for(c=0;c<current_caption->chunks;c++)
		 {
		 	if(current_caption->sprite[c]!=NULL)
				{
					HARDWARE_delete_sprite(current_caption->sprite[c]);
					current_caption->sprite[c]=NULL;
				}
			}
			if(current_caption->next!=NULL)current_caption=(CAPTION*)current_caption->next;else stop=1;
		}
	}
}

//=========================================================================================================================
void CAPTION_unpause()
{//=========================================================================================================================
	//delete all captions from first_CAPTION on
	//set first_CAPTION back to pause_CAPTION
	//set pause_CAPTION to NULL
	//redraw all caption sprites

	//CAPTION_delete_all_captions();

	first_CAPTION= pause_CAPTION;
	pause_CAPTION=NULL;

	//int caption_chunks_onscreen[2]={0,0};

	if(first_CAPTION!=NULL)
	{
		CAPTION* current_caption = first_CAPTION;
		bool stop=0;
		while(stop==0)
		{
			int c=0;
		 for(c=0;c<current_caption->chunks;c++)
		 {
		 	if(current_caption->sprite[c]==NULL)
				{
					//current_caption->PLAYER_id[c]=FIRST_SPRITE_ID+caption_chunks_onscreen[current_caption->screen];

					current_caption->sprite[c]=HARDWARE_create_sprite(current_caption->gfx[c],0,current_caption->layer,current_caption->scale,current_caption->screen_x+64*c,current_caption->screen_y,255);

					//HARDWARE_create_sprite(current_caption->screen,current_caption->PLAYER_id[c],current_caption->gfx_slot[c],64,32,1,0,0,0,0,0,current_caption->prio,current_caption->scale,current_caption->screen_x+64*c,current_caption->screen_y);
					//caption_chunks_onscreen[current_caption->screen]++;
				}
			}
			if(current_caption->next!=NULL)current_caption=(CAPTION*)current_caption->next;else stop=1;
		}
	}

}



