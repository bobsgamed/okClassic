




#include "../../main.h"
//#include "error.h"


bool error_console_on=1;
char* error_messages[128];
int error_array[128]={0};

DEBUG_overlay_STRUCT* DEBUG_overlays[128];

char error_message[1024];
char sdlerror[1024];
char lastsdlerror[1024];



//===========================================================================================================================
texture_STRUCT* load_texture_from_non_square_surface(SDL_Surface *surface)
{//===========================================================================================================================

	GLuint texture_id;

	int image_w = surface->w;
	int image_h = surface->h;

	int texture_w = power_of_two(image_w);
	int texture_h = power_of_two(image_h);


	//blit from bitmap to a temporary surface with 32 bits per pixel
	SDL_Surface* temp = SDL_CreateRGBSurface(SDL_SWSURFACE, texture_w, texture_h, 32, rmask, gmask, bmask, amask);

	SDL_Rect area;
	area.x = 0;
	area.y = 0;
	area.w = image_w;
	area.h = image_h;

	//SDL_SetAlpha(surface, 0, 0);

	SDL_BlitSurface(surface, &area, temp, NULL);


	//create texture
	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);

	if (SDL_MUSTLOCK(temp))
		SDL_LockSurface(temp);

	//make texture from temp surface pixels
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture_w, texture_h, 0, GL_RGBA, GL_UNSIGNED_BYTE, temp->pixels);



	if (SDL_MUSTLOCK(temp))
		SDL_UnlockSurface(temp);

	//set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	//free temporary surface
	SDL_FreeSurface(temp);


	texture_STRUCT* temp_TEXTURE =	(texture_STRUCT*)malloc(sizeof(texture_STRUCT));

	temp_TEXTURE->image_w=image_w;
	temp_TEXTURE->image_h=image_h;
	temp_TEXTURE->texture_w=texture_w;
	temp_TEXTURE->texture_h=texture_h;
	temp_TEXTURE->texture_id=texture_id;




	return temp_TEXTURE;
}

//===========================================================================================================================
void delete_texture(texture_STRUCT *temp_TEXTURE)
{//===========================================================================================================================


	temp_TEXTURE->image_w=0;
	temp_TEXTURE->image_h=0;
	temp_TEXTURE->texture_w=0;
	temp_TEXTURE->texture_h=0;


	if(glIsTexture(temp_TEXTURE->texture_id))
	{
		glDeleteTextures(1, &temp_TEXTURE->texture_id);
		//glFlush();
	}

	free(temp_TEXTURE);

}

//===========================================================================================================================
void draw_texture_struct(texture_STRUCT* PLAYER_TEXTURE, int x, int y)
{//===========================================================================================================================

	GLuint texture_id = PLAYER_TEXTURE->texture_id;
	int w = PLAYER_TEXTURE->texture_w;
	int h = PLAYER_TEXTURE->texture_h;


	glBindTexture(GL_TEXTURE_2D,texture_id);
	glEnable(GL_TEXTURE_2D);


	GLfloat box[] = {x,y + h,0,  x + w,y + h,0,     x + w, y, 0,   x,y,0};
	GLfloat tex[] = {0,1, 1,1, 1,0, 0,0};

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0,box);
	glTexCoordPointer(2, GL_FLOAT, 0, tex);

	glDrawArrays(GL_TRIANGLE_FAN,0,4);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

}





//===========================================================================================================================
void ERROR_init_error_console()
{//===========================================================================================================================

	int x=0;
	for(x=0;x<128;x++)error_messages[x]=NULL;

	for(x=0;x<128;x++)DEBUG_overlays[x]=NULL;

}

//===========================================================================================================================
void ERROR_set_error(const char* error_string)
{//===========================================================================================================================


		//copy the new error string into a stored string
		char* new_error = (char*)malloc( (strlen(error_string)+2) * sizeof(char) );
		sprintf(new_error,"%s\n",error_string);

		//add this string to the error message array
		int slot=-1;
		int x=0;
		for(x=0;x<128;x++)if(error_messages[x]==NULL){slot=x;x=128;break;}

		if(slot==-1)
		{
			//too many errors, could recycle the array, could use linked list, could delete errors as they get bumped off screen.
			return;
		}

		error_messages[slot]=new_error;

		fprintf(stderr,new_error);


}


//===========================================================================================================================
void ERROR_draw_error_console()
{//===========================================================================================================================
	//go through error_messages
	//find non-NULL value

	int amount_of_errors=0;

	int x=0;
	for(x=0;x<128;x++)
	if(error_messages[x]!=NULL)amount_of_errors++;


	//start at top of screen
	//fill values

	int line_height=12;

	int max_lines;
	max_lines = HARDWARE_SCREEN_HEIGHT_PIXELS/line_height;

	//if height of screen is greater than lines that can fit, start at the last error - amount

	int start_error=0;
	if(amount_of_errors>max_lines)start_error=amount_of_errors-max_lines;


	SDL_Surface* error_SURFACE=NULL;
	texture_STRUCT* error_TEXTURE = NULL;
	SDL_Color green_COLOR = {0,255,0,255};
	SDL_Color white_COLOR = {255,255,255,255};
	SDL_Color black_COLOR = {0,0,0,255};

	int line=0;
	//draw font to screen
	for(x=amount_of_errors-1;x>=start_error;x--)
	{
		line++;

		if(x==amount_of_errors-1)error_SURFACE=TTF_RenderText_Shaded(font_bobsgame_8px,error_messages[x],green_COLOR, black_COLOR);
		else error_SURFACE=TTF_RenderText_Shaded(font_bobsgame_8px,error_messages[x],white_COLOR, black_COLOR);

		error_TEXTURE=load_texture_from_non_square_surface(error_SURFACE);

		draw_texture_struct(error_TEXTURE,0,(HARDWARE_SCREEN_HEIGHT_PIXELS)-(line_height*line));

		if(error_SURFACE!=NULL){SDL_FreeSurface(error_SURFACE);error_SURFACE=NULL;}
		if(error_TEXTURE!=NULL){delete_texture(error_TEXTURE);error_TEXTURE=NULL;}
	}
}


//===========================================================================================================================
void ERROR_check_SDL_and_GL_errors(const char* error_string)
{//===========================================================================================================================

	if(debug==1)
	{

		strcpy(error_message,error_string);

		//check GL errors
		int errloop=0;

		do
		{
			error_array[errloop]=glGetError();
			errloop++;
		}
		while(error_array[errloop-1]!=0);


		errloop=0;
		while(error_array[errloop]!=0)
		{

			int val = error_array[errloop];

			if(val==GL_INVALID_ENUM)strcat(error_message," GL_INVALID_ENUM \n");
			else if(val==GL_INVALID_VALUE)strcat(error_message," GL_INVALID_VALUE \n");
			else if(val==GL_INVALID_OPERATION)strcat(error_message," GL_INVALID_OPERATION \n");
			else if(val==GL_STACK_OVERFLOW)strcat(error_message," GL_STACK_OVERFLOW \n");
			else if(val==GL_STACK_UNDERFLOW)strcat(error_message," GL_STACK_UNDERFLOW \n");
			else if(val==GL_OUT_OF_MEMORY)strcat(error_message," GL_OUT_OF_MEMORY \n");
			//else if(val==GL_TABLE_TOO_LARGE)strcat(error_message," GL_TABLE_TOO_LARGE \n");
			else strcat(error_message," UNKNOWN GL ERROR \n");

			//fprintf(stderr,error_message);
			ERROR_set_error(error_message);

			errloop++;
		}

		//check SDL errors

		strcpy(sdlerror,SDL_GetError());
		if(strcmp(lastsdlerror,sdlerror)!=0)
		{
			strcpy(lastsdlerror,sdlerror);
			//fprintf(stderr,sdlerror,"\n");
			ERROR_set_error(sdlerror);
		}
	}
}




//===========================================================================================================================
DEBUG_overlay_STRUCT* DEBUG_make_overlay(const char* text, int hardware_screen_x, int hardware_screen_y)
{//===========================================================================================================================


//this uses actual hardware screen x and y because it does not render as a game sprite like most other objects like captions, so it isnt affected by ZOOM


	//copy the new error string into a stored string
	DEBUG_overlay_STRUCT* overlay = (DEBUG_overlay_STRUCT*)malloc(sizeof(DEBUG_overlay_STRUCT));

	//add this string to the error message array
	int slot=-1;
	int x=0;
	for(x=0;x<128;x++)if(DEBUG_overlays[x]==NULL){slot=x;x=128;break;}

	if(slot==-1)
	{
		//too many errors, could recycle the array, could use linked list, could delete errors as they get bumped off screen.
		return NULL;
	}

	DEBUG_overlays[slot]=overlay;

	sprintf(overlay->text,text);
	overlay->x=hardware_screen_x;
	overlay->y=hardware_screen_y;
	overlay->width=0;


	return overlay;

}

//===========================================================================================================================
void DEBUG_update_overlay(DEBUG_overlay_STRUCT* overlay, const char* text, int hardware_screen_x, int hardware_screen_y)
{//===========================================================================================================================

	sprintf(overlay->text,text);
	overlay->x=hardware_screen_x;
	overlay->y=hardware_screen_y;

}

//===========================================================================================================================
void DEBUG_delete_overlay(DEBUG_overlay_STRUCT* overlay)
{//===========================================================================================================================

	if(overlay==NULL)return;

	int x=0;
	for(x=0;x<128;x++)if(DEBUG_overlays[x]==overlay){DEBUG_overlays[x]=NULL;x=128;break;}

	free(overlay);

}

//===========================================================================================================================
void DEBUG_draw_overlays()
{//===========================================================================================================================


	SDL_Surface* error_SURFACE=NULL;
	texture_STRUCT* error_TEXTURE = NULL;
	SDL_Color white_COLOR = {255,255,255,255};
	SDL_Color black_COLOR = {0,0,0,255};

	int x=0;
	for(x=0;x<128;x++)
	{
		if(DEBUG_overlays[x]!=NULL)
		{

			error_SURFACE=TTF_RenderText_Shaded(font_bobsgame_8px,DEBUG_overlays[x]->text,white_COLOR, black_COLOR);
			error_TEXTURE=load_texture_from_non_square_surface(error_SURFACE);

			draw_texture_struct(error_TEXTURE,DEBUG_overlays[x]->x,DEBUG_overlays[x]->y);

			DEBUG_overlays[x]->width=error_TEXTURE->image_w;

			if(error_SURFACE!=NULL){SDL_FreeSurface(error_SURFACE);error_SURFACE=NULL;}
			if(error_TEXTURE!=NULL){delete_texture(error_TEXTURE);error_TEXTURE=NULL;}


		}
	}

}
