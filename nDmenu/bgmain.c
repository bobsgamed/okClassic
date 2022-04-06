


void gl_error(int val);
int debug=1;
int error[1024]={0};
int errloop=0;

int novsync=0;
int fpsmeter=1;



//===============================================================================
//SDL AND GL HEADERS
//===============================================================================

//#define GL_GLEXT_PROTOTYPES 1

#include "glee.h"

#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"

#define NO_SDL_GLEXT
#include "SDL/SDL_opengl.h"




//===========================================================================================================================
//main vars
//===========================================================================================================================

//Quit flag
bool quit = false;
SDL_Event event;



s16 HARDWARE_brightness=0;


GLuint fb=0;
GLuint screen;
GLuint scalescreen;

int framebuffer=1;
int hqscale=0;
int ntscfilter=0;



CAPTION* fpscaption = NULL;
int framesrendered=0;
int secondspassed =0;
int lastsecondspassed=0;
int fps=0;



SDL_Joystick *stick = NULL;

LARGE_INTEGER hires_ticks_per_second;//=0;
LARGE_INTEGER newvbltimer;//=0;
LARGE_INTEGER lastvbltimer;//=0;

unsigned char * rgba_fbo_data;
unsigned char * filtered_rgba_fbo_data;


//shader program
	GLuint vert[2];
	GLuint frag[2];
    GLuint p[2];





	unsigned char* output_pixels; /* 16-bit RGB */
	long output_pitch;

	int sony_decoder = 1;
	int merge_fields = 0;
	int burst_phase = 0;
	snes_ntsc_setup_t snes_setup;
	snes_ntsc_t* ntsc;

//===========================================================================================================================
void error(char* errorstring)
{//===========================================================================================================================

	if(debug==1)
	{

	char errormessage[1024];
	strcat(errormessage,errorstring);
	strcat(errormessage," Error:%d\n");

	errloop=0;do{error[errloop]=glGetError();errloop++;}while(error[errloop-1]!=0);
	errloop=0;while(error[errloop]!=0){gl_error(error[errloop]);fprintf(stderr,errormessage, error[errloop]);errloop++;}
	}
}



//===========================================================================================================================
void gl_error(int val)
{//===========================================================================================================================

	if(val==GL_INVALID_ENUM)fprintf(stderr,"GL_INVALID_ENUM ");
	if(val==GL_INVALID_VALUE)fprintf(stderr,"GL_INVALID_VALUE ");
	if(val==GL_INVALID_OPERATION)fprintf(stderr,"GL_INVALID_OPERATION ");
	if(val==GL_STACK_OVERFLOW)fprintf(stderr,"GL_STACK_OVERFLOW ");
	if(val==GL_STACK_UNDERFLOW)fprintf(stderr,"GL_STACK_UNDERFLOW ");
	if(val==GL_OUT_OF_MEMORY)fprintf(stderr,"GL_OUT_OF_MEMORY ");
	if(val==GL_TABLE_TOO_LARGE)fprintf(stderr,"GL_TABLE_TOO_LARGE ");
}


//===========================================================================================================================
void gl_draw(GLuint textureid, int x, int y, int w, int h, u8 filter)
{//===========================================================================================================================

		glBindTexture(GL_TEXTURE_2D, textureid);

		if(filter==1)
		{
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
		}

		glEnable(GL_TEXTURE_2D);

		//make a rectangle
		glBegin(GL_QUADS);
			//top left
			glTexCoord2i(0,0);
			glVertex3f(x, y, 0);
			//top right
			glTexCoord2i(1, 0);
			glVertex3f(x+w, y, 0);
			//bottom right
			glTexCoord2i(1, 1);
			glVertex3f(x+w, y+h, 0);
			//bottom left
			glTexCoord2i(0, 1);
			glVertex3f(x, y+h, 0);
		glEnd();

		glDisable(GL_TEXTURE_2D );

		error("glDraw TexID");

		//glFlush(); //dont need
}


//===========================================================================================================================
void gl_draw_flipped(GLuint textureid, int x, int y, int w, int h)
{//===========================================================================================================================

            //tell opengl to use the generated texture name
            glBindTexture(GL_TEXTURE_2D, textureid);

            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,FILTER_TYPE);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,FILTER_TYPE);

			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);


            glEnable(GL_TEXTURE_2D);

            //make a rectangle
            glBegin(GL_QUADS);
            //top left
            glTexCoord2i(0, 1);
            glVertex3f(x, y, 0);
            //top right
            glTexCoord2i(1, 1);
            glVertex3f(x+w, y, 0);
            //bottom right
            glTexCoord2i(1, 0);
            glVertex3f(x+w, y+h, 0);
            //bottom left
            glTexCoord2i(0, 0);
            glVertex3f(x, y+h, 0);

            glEnd();

            glDisable(GL_TEXTURE_2D );


if(debug==1)
{
errloop=0;do{error[errloop]=glGetError();errloop++;}while(error[errloop-1]!=0);
errloop=0;while(error[errloop]!=0){gl_error(error[errloop]);fprintf(stderr,"glDrawFlipped TexID:%d \n",textureid);errloop++;}
}



}

//===========================================================================================================================
void gl_draw_sprites(u8 layer)
{//===========================================================================================================================

    s16 i=0;
    for(i=127;i>=0;i--)
	{

        if(sprite_id_gfx_slot[i]!=-1&&((sprite_id_priority[i]==layer)||(layer==4&&sprite_id_priority[i]>=4)))
        {
            if(GLOBAL_sprite_layer_enabled)
            {
				u8 filter=0;
            	if((sprite_id_scale[i]!=1.0f&&sprite_id_scale[i]!=2.0f)||sprite_gfx_slot_hq2x[sprite_id_gfx_slot[i]]==1)filter=1;

				if(GLTex_sprite[sprite_id_gfx_slot[i]]==-1)//||glIsTexture(GLTex_sprite[sprite_id_gfx_slot[i]]==0))
				{
					fprintf(stderr,"sprite shouldnt be drawn what is going on \n");//errer
				}
				else
            	gl_draw(GLTex_sprite[sprite_id_gfx_slot[i]],ZOOM*sprite_obj_x[i],ZOOM*sprite_obj_y[i], ZOOM*sprite_texture_size_x[sprite_id_gfx_slot[i]]*(sprite_id_scale[i]*(1.0f+(sprite_gfx_slot_hq2x[sprite_id_gfx_slot[i]]*-0.5f))),ZOOM*sprite_texture_size_y[sprite_id_gfx_slot[i]]*(sprite_id_scale[i]*(1.0f+(sprite_gfx_slot_hq2x[sprite_id_gfx_slot[i]]*-0.5f))),filter);
            }
        }
	}

}




//==========================================================================================================================
void delete_bg_metatiles(u8 bg)
{//==========================================================================================================================

	int s=0;
	for(s=0;s<METATILES_POSSIBLE;s++)
		if(metatile_used[bg*METATILES_POSSIBLE+s]==1)
		{
				if(glIsTexture(GLTex_map_metatile[bg*METATILES_POSSIBLE+s]))
				{
					glDeleteTextures(1, &GLTex_map_metatile[bg*METATILES_POSSIBLE+s]);
					//GLTex_map_metatile[bg*METATILES_POSSIBLE+s]=0;
					//glFlush();
				}
				metatile_used[bg*METATILES_POSSIBLE+s]=0;
		}


}

//==========================================================================================================================
void delete_all_metatiles()
{//==========================================================================================================================


	int bg=0;
	for(bg=0;bg<4;bg++)
	{
		int s=0;
		for(s=0;s<METATILES_POSSIBLE;s++)
			if(metatile_used[bg*METATILES_POSSIBLE+s]==1)
			{
				if(glIsTexture(GLTex_map_metatile[bg*METATILES_POSSIBLE+s]))
				{
					glDeleteTextures(1, &GLTex_map_metatile[bg*METATILES_POSSIBLE+s]);
					//GLTex_map_metatile[bg*METATILES_POSSIBLE+s]=0;
					//glFlush();
				}
				metatile_used[bg*METATILES_POSSIBLE+s]=0;
			}
	}


}

//==========================================================================================================================
void create_needed_metatiles(u8 bg)
{//==========================================================================================================================

	if(metatile_map==1)
	{
		if(HARDWARE_map_tileset!=NULL&&HARDWARE_map_palette!=NULL)
		{
			//check for each metatile coordinate that should be onscreen.
			//if it's there, draw it. if it isn't, make it, and draw it.



			u16 s=0;

			s64 x=0;
			s64 y=0;

			//starting at first possible grid position off left of screen (metatiles will always be drawn at even intervals metatile_size * n)
			for(y=(map_cam_y-(METATILE_SIZE/2))-((map_cam_y-(METATILE_SIZE/2))%METATILE_SIZE);y<(map_cam_y+(METATILE_SIZE/2))+SCREEN_HEIGHT_PIXELS;y+=METATILE_SIZE)
				for(x=(map_cam_x-(METATILE_SIZE/2))-((map_cam_x-(METATILE_SIZE/2))%METATILE_SIZE);x<(map_cam_x+(METATILE_SIZE/2))+SCREEN_WIDTH_PIXELS;x+=METATILE_SIZE)
				{
					bool make=1;
					for(s=0;s<METATILES_POSSIBLE;s++)
						if(metatile_used[bg*METATILES_POSSIBLE+s]==1)
						{
							if(metatile_x[bg*METATILES_POSSIBLE+s]==x&&metatile_y[bg*METATILES_POSSIBLE+s]==y)//if it exists, draw it.
							{
								make=0;
							}
						}
					if(make==1)//it doesn't exist, so make it and draw it.
					{
						if(bg==3)HARDWARE_load_metatile(1, 3, current_map_width_tiles*8, current_map_height_tiles*8, x , y, current_map_3_filename);
						if(bg==0)HARDWARE_load_metatile(1, 0, current_map_width_tiles*8, current_map_height_tiles*8, x , y, current_map_0_filename);
						if(bg==2)HARDWARE_load_metatile(1, 2, current_map_width_tiles*8, current_map_height_tiles*8, x , y, current_map_2_filename);
						if(bg==1)HARDWARE_load_metatile(1, 1, current_map_width_tiles*8, current_map_height_tiles*8, x , y, current_map_1_filename);
						//gl_draw(GLTex_map_metatile[((3*METATILES_POSSIBLE)+s)], metatile_x[3*METATILES_POSSIBLE+s]-map_cam_x, metatile_y[3*METATILES_POSSIBLE+s]-map_cam_y,METATILE_SIZE,METATILE_SIZE);
						//for some reason openGL blits the texture white for a frame. i guess there's a lag somewhere, so we just wait a frame to draw it.
					}
				}
		}
	}
}


//==========================================================================================================================
void delete_unneeded_metatiles()
{//==========================================================================================================================


	//metatiles should always be created starting at 0,0, in chunks of 512x512.
	//so walking around, when the camera moves,
	//check for tiles that don't need to be onscreen. delete them.
	//determine whether all the tiles that need to be onscreen exist
	//if they don't, create them.

	if(metatile_map==1)
	{
		int bg=0;

		for(bg=0;bg<4;bg++)
		{
			int s=0;
			for(s=0;s<METATILES_POSSIBLE;s++)
			{
				if(metatile_used[bg*METATILES_POSSIBLE+s]==1)
				{
					//check if tile needs to be onscreen or not.
					if(
							((map_cam_x+(METATILE_SIZE/2))+SCREEN_WIDTH_PIXELS<=metatile_x[bg*METATILES_POSSIBLE+s])|| //off the right side
							((map_cam_x-(METATILE_SIZE/2))>=metatile_x[bg*METATILES_POSSIBLE+s]+METATILE_SIZE)|| //off the left side

							((map_cam_y+(METATILE_SIZE/2))+SCREEN_HEIGHT_PIXELS<=metatile_y[bg*METATILES_POSSIBLE+s])|| //off the bottom
							((map_cam_y-(METATILE_SIZE/2))>=metatile_y[bg*METATILES_POSSIBLE+s]+METATILE_SIZE) //off the top
						)
						{
							//don't need it. delete it.
							if(glIsTexture(GLTex_map_metatile[bg*METATILES_POSSIBLE+s]))
							{
								glDeleteTextures(1, &GLTex_map_metatile[bg*METATILES_POSSIBLE+s]);
								//GLTex_map_metatile[bg*METATILES_POSSIBLE+s]=0;
								//glFlush();
							}
							metatile_used[bg*METATILES_POSSIBLE+s]=0;
						}
				}
			}
		}
	}

}


//===========================================================================================================================
void gl_draw_bg(u8 bg)
{//===========================================================================================================================

    if(metatile_map==1&&GLOBAL_map_initialized==1)
    {

		if(
		(bg==3&&GLOBAL_bg_layer_enabled[3])||
		(bg==0&&GLOBAL_bg_layer_enabled[0])||
		(bg==2&&GLOBAL_bg_layer_enabled[2])||
		(bg==1&&GLOBAL_bg_layer_enabled[1])
		)
		{
			if(HARDWARE_map_tileset!=NULL&&HARDWARE_map_palette!=NULL)
			{
				//check for each metatile coordinate that should be onscreen.
				//if it's there, draw it. if it isn't, make it, and draw it.

				u16 s=0;

				s64 x=0;
				s64 y=0;

				//starting at first possible grid position off left of screen (metatiles will always be drawn at even intervals metatile_size * n)
				for(y=(map_cam_y-(METATILE_SIZE/2))-((map_cam_y-(METATILE_SIZE/2))%METATILE_SIZE);y<(map_cam_y+(METATILE_SIZE/2))+SCREEN_HEIGHT_PIXELS;y+=METATILE_SIZE)
					for(x=(map_cam_x-(METATILE_SIZE/2))-((map_cam_x-(METATILE_SIZE/2))%METATILE_SIZE);x<(map_cam_x+(METATILE_SIZE/2))+SCREEN_WIDTH_PIXELS;x+=METATILE_SIZE)
					{

						for(s=0;s<METATILES_POSSIBLE;s++)
							if(metatile_used[bg*METATILES_POSSIBLE+s]==1)
							{
								if(metatile_x[bg*METATILES_POSSIBLE+s]==x&&metatile_y[bg*METATILES_POSSIBLE+s]==y)//if it exists, draw it.
								{
									gl_draw(GLTex_map_metatile[((bg*METATILES_POSSIBLE)+s)], ZOOM*(metatile_x[bg*METATILES_POSSIBLE+s]-map_cam_x), ZOOM*(metatile_y[bg*METATILES_POSSIBLE+s]-map_cam_y),ZOOM*METATILE_SIZE,ZOOM*METATILE_SIZE,0);
								}
							}
					}
			}
		}

    }
    else
    if(metatile_map==0&&GLOBAL_map_initialized==1)
    {
        //opengl
        if(bg==3)if(GLOBAL_bg_layer_enabled[3]&&GLTex_bg[3]!=0&&HARDWARE_map_3!=NULL)gl_draw(GLTex_bg[3],ZOOM*(0-map_cam_x),ZOOM*(0-map_cam_y), ZOOM*bg_texture_size_x[3], ZOOM*bg_texture_size_y[3],0);
        if(bg==0)if(GLOBAL_bg_layer_enabled[0]&&GLTex_bg[0]!=0&&HARDWARE_map_0!=NULL)gl_draw(GLTex_bg[0],ZOOM*(0-map_cam_x),ZOOM*(0-map_cam_y), ZOOM*bg_texture_size_x[0], ZOOM*bg_texture_size_y[0],0);
        if(bg==2)if(GLOBAL_bg_layer_enabled[2]&&GLTex_bg[2]!=0&&HARDWARE_map_2!=NULL)gl_draw(GLTex_bg[2],ZOOM*(0-map_cam_x),ZOOM*(0-map_cam_y), ZOOM*bg_texture_size_x[2], ZOOM*bg_texture_size_y[2],0);
        if(bg==1)if(GLOBAL_bg_layer_enabled[1]&&GLTex_bg[1]!=0&&HARDWARE_map_1!=NULL)gl_draw(GLTex_bg[1],ZOOM*(0-map_cam_x),ZOOM*(0-map_cam_y), ZOOM*bg_texture_size_x[1], ZOOM*bg_texture_size_y[1],0);

        //sdl
        //if(SDLSurface_bg[0]!=NULL)
        //SDL_BlitSurface( SDLSurface_bg[0], NULL, SDLSurface_screen, &mapxy[0] );

    }

}


//===========================================================================================================================
void set_zoom()
{//===========================================================================================================================

		if(ZOOM!=ZOOMto)
		{
			if(ZOOM>ZOOMto)ZOOM-=0.05f;
			if(ZOOM<ZOOMto)ZOOM+=0.05f;
		}

        SCREEN_WIDTH_PIXELS=HARDWARE_SCREEN_WIDTH_PIXELS/ZOOM;//256
        SCREEN_HEIGHT_PIXELS=HARDWARE_SCREEN_HEIGHT_PIXELS/ZOOM;//192

        SCREEN_WIDTH_TILES=SCREEN_WIDTH_PIXELS/8;//32
        SCREEN_HEIGHT_TILES=SCREEN_HEIGHT_PIXELS/8;//24

}

//===========================================================================================================================
void render()
{//===========================================================================================================================

	//shader step 1
	//GLint loc;
	//loc = glGetUniformLocation(p[0], "Tex0");
	//glUniform1i(loc, screen);
	//glUseProgram(p[0]);

	set_zoom();

//attach a texture to a framebuffer, render directly into texture
	if(framebuffer)glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fb);



	glClear( GL_COLOR_BUFFER_BIT );


	float tempZOOM=ZOOM;
	ZOOM=2.0f;






            gl_draw_bg(3);
            gl_draw_sprites(0);

            gl_draw_bg(0);
            gl_draw_sprites(3);

            gl_draw_bg(2);
            gl_draw_sprites(2);

            gl_draw_bg(1);
            gl_draw_sprites(1);


	//AUX bg
    int a=0;
    a=0;
    if(glIsTexture(GLTex_AUX_bg[a]))gl_draw(GLTex_AUX_bg[a],AUX_bg_x[a],AUX_bg_y[a],ZOOM*AUX_bg_zoom[a]*AUX_bg_texture_size_x[a], ZOOM*AUX_bg_zoom[a]*AUX_bg_texture_size_y[a],0);
	gl_draw_sprites(4);

    a=1;
    if(glIsTexture(GLTex_AUX_bg[a]))gl_draw(GLTex_AUX_bg[a],AUX_bg_x[a],AUX_bg_y[a],ZOOM*AUX_bg_zoom[a]*AUX_bg_texture_size_x[a], ZOOM*AUX_bg_zoom[a]*AUX_bg_texture_size_y[a],0);
	gl_draw_sprites(5);

    a=2;
    if(glIsTexture(GLTex_AUX_bg[a]))gl_draw(GLTex_AUX_bg[a],AUX_bg_x[a],AUX_bg_y[a],ZOOM*AUX_bg_zoom[a]*AUX_bg_texture_size_x[a], ZOOM*AUX_bg_zoom[a]*AUX_bg_texture_size_y[a],0);
	gl_draw_sprites(6);

    a=3;
    if(glIsTexture(GLTex_AUX_bg[a]))gl_draw(GLTex_AUX_bg[a],AUX_bg_x[a],AUX_bg_y[a],ZOOM*AUX_bg_zoom[a]*AUX_bg_texture_size_x[a], ZOOM*AUX_bg_zoom[a]*AUX_bg_texture_size_y[a],0);
	gl_draw_sprites(7);


		ZOOM=tempZOOM;





	if(!framebuffer)
	{
		//=====================
		//Copy texture from back buffer manually (slow)
		//=====================

		int pw=SCREEN_WIDTH_PIXELS;
		int ph=SCREEN_HEIGHT_PIXELS;
		if(IsNPOT(pw,ph))
		{
		   pw = (int)powf(2.0, ceilf(logf((float)pw)/logf(2.0f)));
		   ph = (int)powf(2.0, ceilf(logf((float)ph)/logf(2.0f)));
		}

		int pwdiff = pw-SCREEN_WIDTH_PIXELS;
		int phdiff = ph-SCREEN_HEIGHT_PIXELS;

		//bind screen texture to 2d
		glBindTexture(GL_TEXTURE_2D, screen);

		//copy back buffer image into screen texture
		glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, 0,HARDWARE_SCREEN_HEIGHT_PIXELS-SCREEN_HEIGHT_PIXELS,pw, ph, 0);

		//clear back buffer
		glClear( GL_COLOR_BUFFER_BIT );

		//draw screen to back buffer, but flipped because its upside down for some reason
		gl_draw_flipped(screen,0,-(phdiff*ZOOM),HARDWARE_SCREEN_WIDTH_PIXELS+(pwdiff*ZOOM),HARDWARE_SCREEN_HEIGHT_PIXELS+(phdiff*ZOOM));

	}


	if(framebuffer&&!hqscale&&!ntscfilter)
	{

		//Be sure to reset the rendering state afterwards by binding the zero framebuffer object (the screen):
		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);

		//clear the screen
		glClear(GL_COLOR_BUFFER_BIT);

	//shader step 2
	//GLint loc;
	//loc = glGetUniformLocation(p[1], "Tex0");
	//glUniform1i(loc, 0);
	//loc = glGetUniformLocation(p[1], "Gamma");
	//glUniform1f(loc, 0.9f);
	//glUseProgram(p[1]);

		gl_draw_flipped(screen,0,0//-(((HARDWARE_SCREEN_HEIGHT_PIXELS/4)*((float)((float)(HARDWARE_SCREEN_HEIGHT_PIXELS*2)/(float)(SCREEN_HEIGHT_PIXELS*2)))))
						,
						(HARDWARE_SCREEN_WIDTH_PIXELS*2*ZOOM)//*2*((float)((float)(HARDWARE_SCREEN_WIDTH_PIXELS*2)/(float)(SCREEN_WIDTH_PIXELS*2))))
						,
						(HARDWARE_SCREEN_HEIGHT_PIXELS*2*ZOOM)//*2*((float)((float)(HARDWARE_SCREEN_HEIGHT_PIXELS*2)/(float)(SCREEN_HEIGHT_PIXELS*2))))
						);



	}

    SDL_GL_SwapBuffers();

    //Update the screen
    //SDL_Flip(SDLSurface_screen);
}







//bool JOYSTICK_USED_X=0;
//bool JOYSTICK_USED_Y=0;
//bool JOYSTICK_USED_HAT=0;


s32 DEADZONE=8000;

bool KEY_UP_HELD=0;
bool KEY_DOWN_HELD=0;
bool KEY_LEFT_HELD=0;
bool KEY_RIGHT_HELD=0;

bool KEY_START_HELD=0;
bool KEY_SELECT_HELD=0;

bool KEY_A_HELD=0;
bool KEY_B_HELD=0;
bool KEY_Y_HELD=0;
bool KEY_X_HELD=0;
bool KEY_L_HELD=0;
bool KEY_R_HELD=0;


//===========================================================================================================================
void check_controls()
{//===========================================================================================================================



//see if button was held last frame
//if it wasnt, pressed = 1


u8 LAST_BUTTON_A_HELD=BUTTON_A_HELD;
u8 LAST_BUTTON_B_HELD=BUTTON_B_HELD;
u8 LAST_BUTTON_Y_HELD=BUTTON_Y_HELD;
u8 LAST_BUTTON_X_HELD=BUTTON_X_HELD;
u8 LAST_BUTTON_L_HELD=BUTTON_L_HELD;
u8 LAST_BUTTON_R_HELD=BUTTON_R_HELD;

u8 LAST_BUTTON_START_HELD=BUTTON_START_HELD;
u8 LAST_BUTTON_SELECT_HELD=BUTTON_SELECT_HELD;

u8 LAST_BUTTON_UP_HELD=BUTTON_UP_HELD;
u8 LAST_BUTTON_DOWN_HELD=BUTTON_DOWN_HELD;
u8 LAST_BUTTON_LEFT_HELD=BUTTON_LEFT_HELD;
u8 LAST_BUTTON_RIGHT_HELD=BUTTON_RIGHT_HELD;

BUTTON_ACTION_HELD=0;

BUTTON_A_HELD=0;
BUTTON_B_HELD=0;
BUTTON_Y_HELD=0;
BUTTON_X_HELD=0;
BUTTON_L_HELD=0;
BUTTON_R_HELD=0;

BUTTON_START_HELD=0;
BUTTON_SELECT_HELD=0;

BUTTON_UP_HELD=0;
BUTTON_DOWN_HELD=0;
BUTTON_LEFT_HELD=0;
BUTTON_RIGHT_HELD=0;



if(stick!=NULL)
{

    //joystick
    SDL_JoystickUpdate();


    //analog
    s32 xval=0;
    s32 yval=0;

    xval = SDL_JoystickGetAxis(stick,0);//x axis, returns -32767 to 32767
    yval = SDL_JoystickGetAxis(stick,1);//y axis

    if(xval<0-DEADZONE||xval>DEADZONE)
    {
        if(xval>0){BUTTON_RIGHT_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_JOYSTICK;}
        if(xval<0){BUTTON_LEFT_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_JOYSTICK;}
    }

    if(yval<0-DEADZONE||yval>DEADZONE)
    {
        if(yval>0){BUTTON_DOWN_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_JOYSTICK;}
        if(yval<0){BUTTON_UP_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_JOYSTICK;}
    }


    //dpad
    u8 dpad = SDL_JoystickGetHat(stick, 0);

    switch (dpad)
    {

        case SDL_HAT_RIGHTUP:{BUTTON_UP_HELD=1;BUTTON_RIGHT_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_JOYSTICK;}break;
        case SDL_HAT_RIGHTDOWN:{BUTTON_DOWN_HELD=1;BUTTON_RIGHT_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_JOYSTICK;}break;
        case SDL_HAT_LEFTUP:{BUTTON_UP_HELD=1;BUTTON_LEFT_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_JOYSTICK;}break;
        case SDL_HAT_LEFTDOWN:{BUTTON_DOWN_HELD=1;BUTTON_LEFT_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_JOYSTICK;}break;

        case SDL_HAT_UP:{BUTTON_UP_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_JOYSTICK;}break;
        case SDL_HAT_RIGHT:{BUTTON_RIGHT_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_JOYSTICK;}break;
        case SDL_HAT_DOWN:{BUTTON_DOWN_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_JOYSTICK;}break;
        case SDL_HAT_LEFT:{BUTTON_LEFT_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_JOYSTICK;}break;

        /*
        case SDL_HAT_CENTERED:
        {
            BUTTON_UP_HELD=0;
            BUTTON_DOWN_HELD=0;
            BUTTON_LEFT_HELD=0;
            BUTTON_RIGHT_HELD=0;
        }break;
        */

        default:break;

    }


    //buttons
     if(SDL_JoystickGetButton(stick, 1)==1)BUTTON_A_HELD=1;
     if(SDL_JoystickGetButton(stick, 0)==1)BUTTON_B_HELD=1;

     if(SDL_JoystickGetButton(stick, 2)==1)BUTTON_Y_HELD=1;
     if(SDL_JoystickGetButton(stick, 3)==1)BUTTON_X_HELD=1;

     if(SDL_JoystickGetButton(stick, 4)==1)BUTTON_L_HELD=1;
     if(SDL_JoystickGetButton(stick, 5)==1)BUTTON_R_HELD=1;

     if(SDL_JoystickGetButton(stick, 6)==1)BUTTON_SELECT_HELD=1;
     if(SDL_JoystickGetButton(stick, 7)==1)BUTTON_START_HELD=1;

}







        //=====================
        //EVENTS
        //=====================

        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                MAIN_QUIT = true;

            }

/*
            if( event.type == SDL_MOUSEBUTTONDOWN )
            { //If the left mouse button was pressed
                if( event.button.button == SDL_BUTTON_LEFT )
                { //Get the mouse offsets
                    TouchScreen.Held=true;
                    TouchScreen.X = event.button.x/ZOOM;
                    TouchScreen.Y = event.button.y/ZOOM;
                }
            }
*/
            //If a key was pressed
            if( event.type == SDL_KEYDOWN )
            {
                //Adjust the velocity
                switch( event.key.keysym.sym )
                {
                    case SDLK_w:
                    case SDLK_UP: {KEY_UP_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_KEYBOARD;} break;
                    case SDLK_s:
                    case SDLK_DOWN: {KEY_DOWN_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_KEYBOARD;} break;
                    case SDLK_a:
                    case SDLK_LEFT: {KEY_LEFT_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_KEYBOARD;} break;
                    case SDLK_d:
                    case SDLK_RIGHT: {KEY_RIGHT_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_KEYBOARD;} break;

					case SDLK_RETURN:
                    case SDLK_RIGHTBRACKET: {KEY_START_HELD=1;} break;
                    case SDLK_BACKSPACE:
                    case SDLK_LEFTBRACKET: {KEY_SELECT_HELD=1;} break;


                    case SDLK_SPACE: {KEY_A_HELD=1;} break;

                    case SDLK_LSHIFT: {KEY_B_HELD=1;} break;

                    case SDLK_q: {KEY_L_HELD=1;} break;
                    case SDLK_e: {KEY_R_HELD=1;} break;

                    case SDLK_z: {KEY_Y_HELD=1;} break;
                    case SDLK_x: {KEY_X_HELD=1;} break;

                    default:break;
                }

            }


            //If a key was released
            else if( event.type == SDL_KEYUP )
            {
                //Adjust the velocity
                switch( event.key.keysym.sym )
                {
                    case SDLK_w:
                    case SDLK_UP: {KEY_UP_HELD=0;} break;
                    case SDLK_s:
                    case SDLK_DOWN: {KEY_DOWN_HELD=0;} break;
                    case SDLK_a:
                    case SDLK_LEFT: {KEY_LEFT_HELD=0;} break;
                    case SDLK_d:
                    case SDLK_RIGHT: {KEY_RIGHT_HELD=0;} break;

					case SDLK_RETURN:
                    case SDLK_RIGHTBRACKET: {KEY_START_HELD=0;} break;

                    case SDLK_BACKSPACE:
                    case SDLK_LEFTBRACKET: {KEY_SELECT_HELD=0;} break;


                    case SDLK_SPACE: {KEY_A_HELD=0;} break;
                    case SDLK_LSHIFT: {KEY_B_HELD=0;} break;

                    case SDLK_q: {KEY_L_HELD=0;} break;
                    case SDLK_e: {KEY_R_HELD=0;} break;

                    case SDLK_z: {KEY_Y_HELD=0;} break;
                    case SDLK_x: {KEY_X_HELD=0;} break;


					//case SDLK_f: {if(fpsmeter==0)fpsmeter=1;else fpsmeter=0;}break;
                    //debug


					//map layer on/off
					case SDLK_1: {if(GLOBAL_bg_layer_enabled[1]==1)GLOBAL_bg_layer_enabled[1]=0;else GLOBAL_bg_layer_enabled[1]=1;} break;
					case SDLK_2: {if(GLOBAL_bg_layer_enabled[2]==1)GLOBAL_bg_layer_enabled[2]=0;else GLOBAL_bg_layer_enabled[2]=1;} break;
					case SDLK_3: {if(GLOBAL_bg_layer_enabled[3]==1)GLOBAL_bg_layer_enabled[3]=0;else GLOBAL_bg_layer_enabled[3]=1;} break;
					case SDLK_0: {if(GLOBAL_bg_layer_enabled[0]==1)GLOBAL_bg_layer_enabled[0]=0;else GLOBAL_bg_layer_enabled[0]=1;} break;
					case SDLK_4: {if(GLOBAL_sprite_layer_enabled==1)GLOBAL_sprite_layer_enabled=0;else GLOBAL_sprite_layer_enabled=1;} break;

					case SDLK_f: {if(FILTER_TYPE==GL_LINEAR)FILTER_TYPE=GL_NEAREST;else FILTER_TYPE=GL_LINEAR;}break;

					case SDLK_5: {clock_hour--;update_clock=true;clock_update_clock();}break;
					case SDLK_6: {clock_hour++;update_clock=true;clock_update_clock();}break;
					case SDLK_7: {clock_minute--;update_clock=true;clock_update_clock();}break;
					case SDLK_8: {clock_minute++;update_clock=true;clock_update_clock();}break;


                    //TODO: brightness controls



                    case SDLK_MINUS:
                    {
                        if(ZOOMlock==0)if(ZOOMto>MINZOOM)ZOOMto-=ZOOMINCREMENT;
                        //HARDWARE_brightness--;
                        //HARDWARE_create_brightened_palette((void*)MainSpritePalette,(u16*)sprite_palette,HARDWARE_brightness);
                        //HARDWARE_load_sprite_palette(1,0,(u16*)sprite_palette);
                        //HARDWARE_refresh_sprite_textures();
                     break;
                    }
                    case SDLK_EQUALS:
                    {
                        if(ZOOMlock==0)if(ZOOMto<MAXZOOM)ZOOMto+=ZOOMINCREMENT;
                        //HARDWARE_brightness++;
                        //HARDWARE_create_brightened_palette((void*)MainSpritePalette,(u16*)sprite_palette,HARDWARE_brightness);
                        //HARDWARE_load_sprite_palette(1,0,(u16*)sprite_palette);
                        //HARDWARE_refresh_sprite_textures();
                     break;
                    }


                    case SDLK_ESCAPE: {MAIN_QUIT = true; } break;

                    default:break;
                }

            }

        }




        if(KEY_A_HELD==1)BUTTON_A_HELD=1;
        if(KEY_B_HELD==1)BUTTON_B_HELD=1;
        if(KEY_Y_HELD==1)BUTTON_Y_HELD=1;
        if(KEY_X_HELD==1)BUTTON_X_HELD=1;
        if(KEY_L_HELD==1)BUTTON_L_HELD=1;
        if(KEY_R_HELD==1)BUTTON_R_HELD=1;

        if(KEY_UP_HELD==1)BUTTON_UP_HELD=1;
        if(KEY_DOWN_HELD==1)BUTTON_DOWN_HELD=1;
        if(KEY_LEFT_HELD==1)BUTTON_LEFT_HELD=1;
        if(KEY_RIGHT_HELD==1)BUTTON_RIGHT_HELD=1;

        if(KEY_START_HELD==1)BUTTON_START_HELD=1;
        if(KEY_SELECT_HELD==1)BUTTON_SELECT_HELD=1;




        if(BUTTON_A_HELD==1&&LAST_BUTTON_A_HELD==0)BUTTON_A_PRESSED=1;
        if(BUTTON_B_HELD==1&&LAST_BUTTON_B_HELD==0)BUTTON_B_PRESSED=1;
        if(BUTTON_Y_HELD==1&&LAST_BUTTON_Y_HELD==0)BUTTON_Y_PRESSED=1;
        if(BUTTON_X_HELD==1&&LAST_BUTTON_X_HELD==0)BUTTON_X_PRESSED=1;
        if(BUTTON_L_HELD==1&&LAST_BUTTON_L_HELD==0)BUTTON_L_PRESSED=1;
        if(BUTTON_R_HELD==1&&LAST_BUTTON_R_HELD==0)BUTTON_R_PRESSED=1;

        if(BUTTON_START_HELD==1&&LAST_BUTTON_START_HELD==0)BUTTON_START_PRESSED=1;
        if(BUTTON_SELECT_HELD==1&&LAST_BUTTON_SELECT_HELD==0)BUTTON_SELECT_PRESSED=1;

        if(BUTTON_UP_HELD==1&&LAST_BUTTON_UP_HELD==0)BUTTON_UP_PRESSED=1;
        if(BUTTON_DOWN_HELD==1&&LAST_BUTTON_DOWN_HELD==0)BUTTON_DOWN_PRESSED=1;
        if(BUTTON_LEFT_HELD==1&&LAST_BUTTON_LEFT_HELD==0)BUTTON_LEFT_PRESSED=1;
        if(BUTTON_RIGHT_HELD==1&&LAST_BUTTON_RIGHT_HELD==0)BUTTON_RIGHT_PRESSED=1;





        if(BUTTON_A_HELD==1||BUTTON_L_HELD==1)BUTTON_ACTION_HELD=1;else BUTTON_ACTION_HELD=0;

        if(BUTTON_A_PRESSED==1||BUTTON_L_PRESSED==1)BUTTON_ACTION_PRESSED=1;



}


//==========================================================================================================================
void reset_controls()
{//==========================================================================================================================


        if(BUTTON_ACTION_PRESSED==1)BUTTON_ACTION_PRESSED=0;

        if(BUTTON_A_PRESSED==1)BUTTON_A_PRESSED=0;
        if(BUTTON_B_PRESSED==1)BUTTON_B_PRESSED=0;
        if(BUTTON_Y_PRESSED==1)BUTTON_Y_PRESSED=0;
        if(BUTTON_X_PRESSED==1)BUTTON_X_PRESSED=0;
        if(BUTTON_L_PRESSED==1)BUTTON_L_PRESSED=0;
        if(BUTTON_R_PRESSED==1)BUTTON_R_PRESSED=0;

        if(BUTTON_START_PRESSED==1)BUTTON_START_PRESSED=0;
        if(BUTTON_SELECT_PRESSED==1)BUTTON_SELECT_PRESSED=0;


        if(BUTTON_UP_PRESSED==1)BUTTON_UP_PRESSED=0;
        if(BUTTON_DOWN_PRESSED==1)BUTTON_DOWN_PRESSED=0;
        if(BUTTON_LEFT_PRESSED==1)BUTTON_LEFT_PRESSED=0;
        if(BUTTON_RIGHT_PRESSED==1)BUTTON_RIGHT_PRESSED=0;

        if(TouchScreen.Held==true)TouchScreen.Held=false;


}







//==========================================================================================================================
void main_vbl()
{//==========================================================================================================================

		//====================vbl==========================================

		if(intro_run==1)intro_vbl();

		intro_vbl_counter++;
		if(intro_vbl_counter>600)intro_vbl_counter=0;
		intro_vbl_counter2++;
		if(intro_vbl_counter2>600)intro_vbl_counter2=0;

		fade_vbl_counter++;
		if(fade_vbl_counter>600)fade_vbl_counter=0;

		if(game_run==1)game_vbl();


		render();

}


//==========================================================================================================================
void main_vbl_timed()
{//==========================================================================================================================

		//====================vbl==========================================

		QueryPerformanceCounter(&newvbltimer);

		if(newvbltimer.QuadPart-lastvbltimer.QuadPart>=(16*(hires_ticks_per_second.QuadPart/1000)))
		{
			lastvbltimer.QuadPart=newvbltimer.QuadPart;


			vbl_ticks=lastvbltimer.QuadPart;

			main_vbl();

		}


}


//==========================================================================================================================
int main(int argc, char *argv[])//int argc, char **argv)
{//==========================================================================================================================

//=====================
//	HARDWARE_init();
//=====================
//HARDWARE_FS_init();




//load ini file


//easy mode

//skiptext

//bpp

//fullscreen



	dictionary	*	ini ;

	/* Some temporary variables to hold query results */
	//int				b ;
	//int				i ;
	//double			d ;
	//char		*	s ;

	ini = iniparser_load("config.ini");
	//if (ini==NULL) {
		//fprintf(stderr, "cannot parse file: %s\n", ini_name);
		//return -1 ;
	//}
	//iniparser_dump(ini, stderr);

	fullscreen = iniparser_getboolean(ini, "bobsgame:fullscreen", 0);
	easymode = iniparser_getboolean(ini, "bobsgame:easymode", 0);
	debug = iniparser_getboolean(ini, "bobsgame:debug", 0);
	//s = iniparser_getstring(ini, "bobsgame:easymode", NULL);
    //i = iniparser_getint(ini, "skiptext:year", -1);
	//s = iniparser_getstring(ini, "wine:country", NULL);
    //d = iniparser_getdouble(ini, "wine:alcohol", -1.0);

	iniparser_freedict(ini);


	if(debug)skiptext=1;




    // Initialize the SDL library
    if ( SDL_Init(SDL_INIT_EVERYTHING) < 0 ) {
        fprintf(stderr, "Couldn't initialize SDL: %s\n",SDL_GetError());
        exit(2);
    }
    atexit(SDL_Quit);


    SDL_WM_SetCaption( "\"bob's game\" demo 3", "\"bob's game\" demo 3" );
    SDL_WM_SetIcon(SDL_LoadBMP("icon.bmp"), NULL);


SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);


    // Open the display device
    if(fullscreen==1)
    SDLSurface_screen = SDL_SetVideoMode(HARDWARE_SCREEN_WIDTH_PIXELS*2, HARDWARE_SCREEN_HEIGHT_PIXELS*2, 32, SDL_OPENGL|SDL_FULLSCREEN);
    else
    SDLSurface_screen = SDL_SetVideoMode(HARDWARE_SCREEN_WIDTH_PIXELS*2, HARDWARE_SCREEN_HEIGHT_PIXELS*2, 32, SDL_OPENGL);
    if ( SDLSurface_screen == NULL ) {
        fprintf(stderr,"Couldn't set video mode: %s\n",
                            SDL_GetError());
        exit(2);
    }


char infostring[1024];
strcpy(infostring,"GL Version: ");
strcat(infostring,(char*)glGetString(GL_VERSION));
strcat(infostring,"\n");

fprintf(stderr,infostring);



//GLeeInit();



	if(GLEE_WGL_EXT_swap_control){wglSwapIntervalEXT(1);}
	else
	{novsync=1;fprintf(stderr,"Vsync Failed.\n");}


	if(GLEE_EXT_framebuffer_object){framebuffer=1;}
	else {framebuffer=0;fprintf(stderr,"No Framebuffer.\n");}





    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glOrtho(0, HARDWARE_SCREEN_WIDTH_PIXELS*2, HARDWARE_SCREEN_HEIGHT_PIXELS*2, 0, -1, 1 );

	//glViewport(0,0,HARDWARE_SCREEN_WIDTH_PIXELS,HARDWARE_SCREEN_HEIGHT_PIXELS);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glClearColor(0, 0, 0, 0);

	glDisable(GL_DEPTH_TEST);



    glEnable(GL_BLEND);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);





    //=====================
    //FRAMEBUFFER INIT
    //=====================

        glGenTextures(1,&screen); // make a new texture

        if(framebuffer)
        {
			glBindTexture(GL_TEXTURE_2D,screen); // modify (or draw) our texture

			glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8, HARDWARE_SCREEN_WIDTH_PIXELS*2,HARDWARE_SCREEN_HEIGHT_PIXELS*2,0, GL_BGRA,GL_UNSIGNED_BYTE,0); // the texture is w x h pixels

			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR); //no mipmaps (see below)

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);  //no repeat (see below)
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

			glGenerateMipmapEXT(GL_TEXTURE_2D);

			glBindTexture(GL_TEXTURE_2D,0); //back to default texture

			//You can render pixels into a texture using a framebuffer object.  Here's how you make a framebuffer object "fb" hooked up to render into "myTex":
			glGenFramebuffersEXT(1, &fb);
			glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fb);

			glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, screen, 0);
        }

        if(ntscfilter)
        {
        	glGenTextures(1,&scalescreen);

			rgba_fbo_data = (unsigned char *)malloc((HARDWARE_SCREEN_WIDTH_PIXELS*2) * (HARDWARE_SCREEN_HEIGHT_PIXELS*2) * 4);
			filtered_rgba_fbo_data = (unsigned char *)malloc((HARDWARE_SCREEN_WIDTH_PIXELS*4) * (HARDWARE_SCREEN_HEIGHT_PIXELS*8) * 4);

        }




//==================================================================
//SHADERS
//==================================================================





	char *fs,*vs;

	vert[0] = glCreateShader(GL_VERTEX_SHADER);
	vs = textFileRead("shaders/coord.vert");
	glShaderSource(vert[0], 1, (const char **)&vs, NULL);
	free(vs);
	glCompileShader(vert[0]);

	frag[0] = glCreateShader(GL_FRAGMENT_SHADER);
	fs = textFileRead("shaders/nothing.frag");
	glShaderSource(frag[0], 1, (const char **)&fs, NULL);
	free(fs);
	glCompileShader(frag[0]);



	p[0] = glCreateProgram();
	glAttachShader(p[0], vert[0]);
	glAttachShader(p[0], frag[0]);
	glLinkProgram(p[0]);


	vert[1] = glCreateShader(GL_VERTEX_SHADER);
	vs = textFileRead("shaders/coord.vert");
	glShaderSource(vert[1], 1, (const char **)&vs, NULL);
	free(vs);
	glCompileShader(vert[1]);

	frag[1] = glCreateShader(GL_FRAGMENT_SHADER);
	fs = textFileRead("shaders/gamma.frag");
	glShaderSource(frag[1], 1, (const char **)&fs, NULL);
	free(fs);
	glCompileShader(frag[1]);



	p[1] = glCreateProgram();
	glAttachShader(p[1], vert[1]);
	glAttachShader(p[1], frag[1]);
	glLinkProgram(p[1]);








//==================================================================
//SNES NTSC FILTER
//==================================================================
	snes_setup = snes_ntsc_composite;

	ntsc = (snes_ntsc_t*) malloc( sizeof (snes_ntsc_t) );
	//if ( !ntsc )
		//fatal_error( "Out of memory" );

	snes_setup.merge_fields = merge_fields;

	/* available parameters: hue, saturation, contrast, brightness,
	sharpness, gamma, bleed, resolution, artifacts, fringing */
	snes_setup.sharpness = 1;
	snes_setup.gamma     = 0.5f;

	snes_setup.decoder_matrix = 0;
	if ( sony_decoder )
	{
		/* Sony CXA2025AS US */
		static float matrix [6] = { 1.630, 0.317, -0.378, -0.466, -1.089, 1.677 };
		snes_setup.decoder_matrix = matrix;
	}




	snes_ntsc_init( ntsc, &snes_setup );





    //=====================


if(debug==1)
{
errloop=0;do{error[errloop]=glGetError();errloop++;}while(error[errloop-1]!=0);
errloop=0;while(error[errloop]!=0){fprintf(stderr,"glGenTextures Error:%d\n", error[errloop]);errloop++;}
}

//=====================
//vbl setup using SDL timers. nope. pretty useless. still limited to SDL_ticks, might as well keep it in the main loop
//=====================
/*
    SDL_TimerID vbl_timer_id = NULL;
    SDL_TimerID timer2_timer_id = NULL;

    vbl_timer_id = SDL_AddTimer(30, (void*)main_vbl, NULL);
    timer2_timer_id = SDL_AddTimer(10, (void*)main_timer2, NULL);
*/

//=====================
//try using threads. also useless, limited to SDL_ticks.
//=====================

//SDL_Thread *timer2thread = NULL;
//timer2thread = SDL_CreateThread( main_timer2, NULL );




//=====================
//	SOUND
//=====================

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) < 0 ){fprintf(stderr,"Warning: Couldn't set 44100 Hz 16-bit audio\n- Reason: %s\n",SDL_GetError());}

    Mix_AllocateChannels(32);

	HARDWARE_sound_init(); //load wavs into buffers

	if(SDL_NumJoysticks()>=1)
	{
		stick = SDL_JoystickOpen(0);
	}

	srand(time(NULL));





    u64 timer_ticks=0;

	game_init();

	game_run=1;


	LARGE_INTEGER newtimer;//=0;
	LARGE_INTEGER lasttimer;//=0;
	//LARGE_INTEGER hires_ticks_per_second;//=0;
	lasttimer.QuadPart=0;
	lastvbltimer.QuadPart=0;

	QueryPerformanceFrequency(&hires_ticks_per_second);

	while(MAIN_QUIT==FALSE)
	{



		if(novsync==0)
		{

			kodenermascheinin(20); //kodenermaschiniene
			main_vbl();

			framesrendered++;

		}
		else
		if(novsync==1)
		{
			QueryPerformanceCounter(&newtimer);

			if(newtimer.QuadPart-lasttimer.QuadPart>=(16*(hires_ticks_per_second.QuadPart/1000)))
			{
				lasttimer.QuadPart=newtimer.QuadPart;
				kodenermascheinin(20); //kodenermaschiniene
				main_vbl();
				framesrendered++;
			}
			else
			{
				render();
				framesrendered++;
			}

		}

		//render();
		//framesrendered++;

		delete_unneeded_metatiles();

		static u8 f=0;

		if(framesrendered%2==0)
		{
			f++;
			if(f>3)f=0;
			create_needed_metatiles(f);//nice and smooth! a little bit of ghosting but thats ok :-)
		}

        //=====================
        //FPS
        //=====================

			static u64 secondstotal=0;

			secondspassed = (float)(SDL_GetTicks())/1000;

			if(secondspassed>lastsecondspassed)
			{
				lastsecondspassed=secondspassed;
				fps = framesrendered;
				framesrendered=0;

				secondstotal++;

				if(fpsmeter)
				{
					static char fpschar[8];

					fpschar[0] = 'F';
					fpschar[1] = 'P';
					fpschar[2] = 'S';
					fpschar[3] = ':';
					fpschar[4] = 48+((fps/100)%10);
					fpschar[5] = 48+((fps/10)%10);
					fpschar[6] = 48+(fps%10);
					fpschar[7] = '\0';

					if(fpscaption==null)text_make_caption(&fpscaption,1,CAPTION_CENTERED_X,0,-1,(char*)fpschar,FONT_SMALL_ID,WHITE,CLEAR,1,1);
					//void text_make_caption(CAPTION**caption_pp,u8 screen,s16 x,s16 y,s32 seconds,char *caption_text,u8 caption_font_id,u8 caption_text_color,u8 caption_bg_color) //-1 seconds for stay open until manual delete :)
					else
					if(fpscaption!=null)text_caption_replace_text(fpscaption,(char*)fpschar);

				}
				else
				{
					if(fpscaption!=null)text_delete_caption(fpscaption);
				}


				if(secondstotal>1&&fps>70&&novsync==0)
				{
					novsync=1;

					text_make_caption(NULL,1,CAPTION_CENTERED_X,10,10,"Please Turn VSync On - See Readme",FONT_HUGE_ID,RED,CLEAR,5,1);
					//fprintf(stderr,"Vsync Hard-Limiter Activated. Please check your Video Settings Control Panel for a \"vertical sync\" option and turn it on for smoother gameplay.\n");
				}

			}


			static u8 tilexyswitch=1;
			static CAPTION* tilecaption=NULL;
			static char tilexy[10];
			static u16 curx=0;
			static u16 cury=0;

			if(tilexyswitch==1)
			{
				if(curx!= (main_sprite->map_x+main_sprite->size_x/2)/8||cury!=((main_sprite->map_y+(main_sprite->size_y-6))/8)+1)
				{
					curx=(main_sprite->map_x+main_sprite->size_x/2)/8;
					cury=((main_sprite->map_y+(main_sprite->size_y-main_sprite->hitsize_y))/8)+1;
					tilexy[0]=(curx/1000)+48;
					tilexy[1]=(curx%1000/100)+48;
					tilexy[2]=(curx%1000%100/10)+48;
					tilexy[3]=(curx%1000%100%10)+48;
					tilexy[4]=',';
					tilexy[5]=(cury/1000)+48;
					tilexy[6]=(cury%1000/100)+48;
					tilexy[7]=(cury%1000%100/10)+48;
					tilexy[8]=(cury%1000%100%10)+48;
					tilexy[9]='\0';

					if(tilecaption==null)text_make_caption(&tilecaption,1,SCREEN_WIDTH_PIXELS-(50*ZOOM),0,-1,(char*)tilexy,FONT_SMALL_ID,WHITE,BLACK,5,1);
					if(tilecaption!=NULL){text_caption_replace_text(tilecaption,(char*)tilexy);}//text_delete_caption(tilecaption);}
				}
			}


			static u8 zoomcaptionswitch=1;
			static CAPTION* zoomcaption=NULL;
			static char zoomchar[4];
			static float curzoom=1.00f;

			if(zoomcaptionswitch==1)
			{
				if(curzoom!=ZOOMto)
				{
					curzoom=ZOOMto;
					zoomchar[0]=((int)((int)(curzoom)))+48;
					zoomchar[1]=((int)((int)(curzoom*10.0f))%10)+48;
					zoomchar[2]=((int)((int)(curzoom*100.0f))%10)+48;
					zoomchar[3]='\0';

					if(zoomcaption==null)text_make_caption(&zoomcaption,1,200,0,-1,(char*)zoomchar,FONT_SMALL_ID,WHITE,BLACK,5,1);
					if(zoomcaption!=NULL){text_caption_replace_text(zoomcaption,(char*)zoomchar);}//text_delete_caption(tilecaption);}
				}
			}

/*
            char mapxchar[5];
            mapxchar[0] = 48+((abs(map_cam_x)/1000)%10);
            mapxchar[1] = 48+((abs(map_cam_x)/100)%10);
            mapxchar[2] = 48+((abs(map_cam_x)/10)%10);
            mapxchar[3] = 48+(abs(map_cam_x)%10);
            mapxchar[4] = '\0';

            static CAPTION* mapxcaption = NULL;
            if(mapxcaption==null)text_make_caption(&mapxcaption,1,SCREEN_WIDTH_PIXELS/2+100,0,-1,(char*)mapxchar,FONT_SMALL_ID,WHITE,BLACK);
            //void text_make_caption(CAPTION**caption_pp,u8 screen,s16 x,s16 y,s32 seconds,char *caption_text,u8 caption_font_id,u8 caption_text_color,u8 caption_bg_color) //-1 seconds for stay open until manual delete :)
            text_caption_replace_text(mapxcaption,(char*)mapxchar);
*/

if(debug==1)
{

	static char sdlerror[1024];
	static char lastsdlerror[1024];
	strcpy(sdlerror,SDL_GetError());
	if(strcmp(lastsdlerror,sdlerror)!=0)
	{
		strcpy(lastsdlerror,sdlerror);

		fprintf(stderr,sdlerror);
		fprintf(stderr," \n");

	}

}

		//QueryPerformanceCounter(&newtimer);
        u64 ticks = SDL_GetTicks();//newtimer.QuadPart*(hires_ticks_per_second.QuadPart/1000);//SDL_GetTicks();
		u16 tickspassed = ticks-timer_ticks;
		timer_ticks=ticks;


		if(novsync==0)
		{
			//sleep for 10 ms. prevent CPU from 100%. went down to like 4% every once in awhile, nice.
			s16 time=16-(tickspassed%16);
			if(time>0)Sleep(time);
		}
		else
		if(novsync==1)
		{
			Sleep(2);
		}

	}



	//Free the surfaces
	//SDL_FreeSurface(background);

	SDL_JoystickClose(stick);
	//Quit SDL
	SDL_Quit();

	return 0;
}
