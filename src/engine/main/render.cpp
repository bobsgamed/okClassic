




#include "../../main.h"
//#include "render.h"




//-----------------------------
//openGL variables
//-----------------------------
GLuint fb=0;
unsigned int screen=0;
GLuint scalescreen=0;



//shader program
GLuint vert[2];
GLuint frag[2];
GLuint p[2];

unsigned char * rgba_fbo_data = NULL; //framebuffer array
unsigned char * filtered_rgba_fbo_data = NULL;




//-----------------------------
//render flags
//-----------------------------
int framebuffer=1;

int GLOBAL_bg_layer_enabled[4] = {1,1,1,1};
int GLOBAL_sprite_layer_enabled=1;

int fade_alpha=0;
int fade_layer=0;

int GLOBAL_FRAMEBUFFER_FILTER_TYPE=GL_LINEAR;

int fade_vbl_counter=0;

SDL_Surface* SDLSurface_screen = NULL;


bool ZOOMlock=0;

float ZOOM=1.0f;
float ZOOMto=1.0f;

int HARDWARE_SCREEN_WIDTH_PIXELS=1920;//640;//256
int HARDWARE_SCREEN_HEIGHT_PIXELS=1080;//480;//192

int GAME_VIEWPORT_WIDTH_PIXELS=960;//256
int GAME_VIEWPORT_HEIGHT_PIXELS=540;//192

int SCREEN_WIDTH_TILES=960/8;//32
int SCREEN_HEIGHT_TILES=540/8;//24

//===========================================================================================================================
void draw_texture_alpha(GLuint textureid, int x, int y, int w, int h, int tw, int th, int f, float a)
{//===========================================================================================================================


	if(a==1.0f&&glDrawTexiES!=NULL)
	{

		glBindTexture(GL_TEXTURE_2D,textureid);

		glActiveTexture(textureid);

		//have to copy from negative y inside the texture, otherwise its flipped upside down
		GLint param[4] = {0,0,0,0};
		param[0]=0;//0-(tw-w);
		param[1]=0-(th-h);
		param[2]=w;
		param[3]=0-h;

		glTexParameteriv(GL_TEXTURE_2D,GL_TEXTURE_CROP_RECT_OES,param);

		//glBindTexture(GL_TEXTURE_2D,textureid);
		glEnable(GL_TEXTURE_2D);
		glColor4f(1,1,1,1);



		//draw it with mirrored coords
		glDrawTexiES(x,240 - (y + h),0,w,h);

		glDisable(GL_TEXTURE_2D);

	}
	else
	{

		glBindTexture(GL_TEXTURE_2D,textureid);


		if(f==1)
		{
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
		}


		glEnable(GL_TEXTURE_2D);


		float tx=(float)w/(float)tw;
		float ty=(float)h/(float)th;


		GLfloat col[] = {
			1, 1, 1, a,
			1, 1, 1, a,
			1, 1, 1, a,
			1, 1, 1, a
		};


		GLfloat box[] ={
							x,		y,		0,
							x,		y+h,	0,
							x+w,	y+h,	0,
							x+w,	y,		0
						};

		GLfloat tex[] ={
							0,0,
							0,ty,
							tx,ty,
							tx,0
						};

		//GLfloat tex[] ={ //before flipping because drawtex is upside down
							//0,0,
							//0,ty,
							//tx,ty,
							//tx,0
						//};

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glVertexPointer(3, GL_FLOAT, 0,box);
		glColorPointer(4, GL_FLOAT, 0, col);
		glTexCoordPointer(2, GL_FLOAT, 0, tex);

		glDrawArrays(GL_TRIANGLE_FAN,0,4);

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);

		glDisable(GL_TEXTURE_2D);
	}

ERROR_check_SDL_and_GL_errors("draw_texture_alpha");

}
//===========================================================================================================================
void draw_texture(GLuint textureid, int x, int y, int w, int h)
{//===========================================================================================================================
	draw_texture_alpha(textureid,x,y,w,h,w,h,0,1);

	//fprintf(stderr,"drawing texture: %d\n",textureid);
}

//===========================================================================================================================
void gl_draw_flipped(GLuint textureid, int x, int y, int w, int h)
{//===========================================================================================================================

	glBindTexture(GL_TEXTURE_2D, textureid);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GLOBAL_FRAMEBUFFER_FILTER_TYPE);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GLOBAL_FRAMEBUFFER_FILTER_TYPE);

	glEnable(GL_TEXTURE_2D);


	GLfloat box[] ={
						x,		y,		0,
						x,		y+h,	0,
						x+w,	y+h,	0,
						x+w,	y,		0
					};

	GLfloat tex[] ={
						0,1,
						0,0,
						1,0,
						1,1
					};

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0,box);
	glTexCoordPointer(2, GL_FLOAT, 0, tex);

	glDrawArrays(GL_TRIANGLE_FAN,0,4);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

ERROR_check_SDL_and_GL_errors("gl_draw_flipped");

}

//===========================================================================================================================
void draw_sprite(SPRITE* s)
{//===========================================================================================================================
	GLuint texid = s->texture_id;
	int x=s->screen_x*ZOOM;



	int y=s->screen_y*ZOOM;

	//we're sending in the sprite draw_size_y, not the texture_size_y, for the texture coords
	int w=(s->draw_size_x*(s->scale*(1.0f+(s->gfx->hq2x*-0.5f))))*ZOOM;
	int h=(s->draw_size_y*(s->scale*(1.0f+(s->gfx->hq2x*-0.5f))))*ZOOM;

	int tw=(s->gfx->texture_size_x*(s->scale*(1.0f+(s->gfx->hq2x*-0.5f))))*ZOOM;
	int th=(s->gfx->texture_size_y*(s->scale*(1.0f+(s->gfx->hq2x*-0.5f))))*ZOOM;

	bool f=0;
	if((s->scale!=1.0f&&s->scale!=2.0f)||s->gfx->hq2x==1)f=1;//linear filter

	float a=s->alpha/255.0;


	draw_texture_alpha(texid,x,y,w,h,tw,th,f,a);


	//fprintf(stderr,"drawing sprite: %s\n",s->gfx->FileName);


}

//===========================================================================================================================
void gl_draw_sprites(int layer)
{//===========================================================================================================================

	int i=0;
	for(i=255;i>=0;i--)
	{

		//if(PLAYER_id_gfx_slot[i]!=-1&&((PLAYER_id_priority[i]==layer)||(layer==4&&PLAYER_id_priority[i]>=4)))
		if(HARDWARE_sprites[i]!=NULL)
		{

			SPRITE* sprite = HARDWARE_sprites[i];

			if((sprite->layer==layer)||(layer==4&&sprite->layer>=4))
			{
				if(GLOBAL_sprite_layer_enabled)
				{
					if(glIsTexture(sprite->texture_id))
					{
						draw_sprite(sprite);

					}
					else
					{
						ERROR_set_error("gl_draw_sprites:sprite has no texture! \n");//error
					}
				}
			}
		}
	}

}




//===========================================================================================================================
void gl_draw_bg(int bg)
{//===========================================================================================================================

	if(metatile_map==1)
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

				int s=0;

				//int x=0;
				//int y=0;

				//starting at first possible grid position off left of screen (metatiles will always be drawn at even intervals metatile_size * n)
				///i dont really need to do this in order! big waste of cpu!
				///for(y=(MAP_cam_y-(METATILE_SIZE/2))-((MAP_cam_y-(METATILE_SIZE/2))%METATILE_SIZE);y<(MAP_cam_y+(METATILE_SIZE/2))+GAME_VIEWPORT_HEIGHT_PIXELS;y+=METATILE_SIZE)
					///for(x=(MAP_cam_x-(METATILE_SIZE/2))-((MAP_cam_x-(METATILE_SIZE/2))%METATILE_SIZE);x<(MAP_cam_x+(METATILE_SIZE/2))+GAME_VIEWPORT_WIDTH_PIXELS;x+=METATILE_SIZE)
					{

						for(s=0;s<METATILES_POSSIBLE;s++)
							if(metatile_used[bg*METATILES_POSSIBLE+s]==1)
							{
								if(glIsTexture(GLTex_map_metatile[bg*METATILES_POSSIBLE+s]))
								{
									///if(metatile_x[bg*METATILES_POSSIBLE+s]==x&&metatile_y[bg*METATILES_POSSIBLE+s]==y)//if it exists, draw it.
									{
										draw_texture(GLTex_map_metatile[((bg*METATILES_POSSIBLE)+s)], ZOOM*(metatile_x[bg*METATILES_POSSIBLE+s]-MAP_cam_x), ZOOM*(metatile_y[bg*METATILES_POSSIBLE+s]-MAP_cam_y),ZOOM*METATILE_SIZE,ZOOM*METATILE_SIZE);
									}
								}
								else
								{
									ERROR_set_error("trying to draw a metatile that doesnt exist!");

								}
							}
					}
			}
		}

	}
	else
	if(metatile_map==0)
	{
		//opengl
		if(bg==3)if(GLOBAL_bg_layer_enabled[3])if(HARDWARE_map_3!=NULL)if(bg_is_on[3])if(glIsTexture(GLTex_bg[3]))draw_texture(GLTex_bg[3],ZOOM*(0-MAP_cam_x),ZOOM*(0-MAP_cam_y), ZOOM*bg_texture_size_x[3], ZOOM*bg_texture_size_y[3]);
		if(bg==0)if(GLOBAL_bg_layer_enabled[0])if(HARDWARE_map_0!=NULL)if(bg_is_on[0])if(glIsTexture(GLTex_bg[0]))draw_texture(GLTex_bg[0],ZOOM*(0-MAP_cam_x),ZOOM*(0-MAP_cam_y), ZOOM*bg_texture_size_x[0], ZOOM*bg_texture_size_y[0]);
		if(bg==2)if(GLOBAL_bg_layer_enabled[2])if(HARDWARE_map_2!=NULL)if(bg_is_on[2])if(glIsTexture(GLTex_bg[2]))draw_texture(GLTex_bg[2],ZOOM*(0-MAP_cam_x),ZOOM*(0-MAP_cam_y), ZOOM*bg_texture_size_x[2], ZOOM*bg_texture_size_y[2]);
		if(bg==1)if(GLOBAL_bg_layer_enabled[1])if(HARDWARE_map_1!=NULL)if(bg_is_on[1])if(glIsTexture(GLTex_bg[1]))draw_texture(GLTex_bg[1],ZOOM*(0-MAP_cam_x),ZOOM*(0-MAP_cam_y), ZOOM*bg_texture_size_x[1], ZOOM*bg_texture_size_y[1]);

		//sdl
		//if(SDLSurface_bg[0]!=NULL)
		//SDL_BlitSurface( SDLSurface_bg[0], NULL, SDLSurface_screen, &mapxy[0] );

	}

}


//===========================================================================================================================
void draw_black_overlay()
{//===========================================================================================================================
	/*glDisable(GL_TEXTURE_2D);

	glColor4f(r,g,b,a);

	GLfloat box[] = {x,y + h,0, x + w,y + h,0, x + w, y, 0, x,y,0};
	GLfloat tex[] = {0,1, 1,1, 1,0, 0,0};

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0,box);
	glTexCoordPointer(2, GL_FLOAT, 0, tex);

	glDrawArrays(GL_TRIANGLE_FAN,0,4);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	glEnable(GL_TEXTURE_2D);*/

	int x=0;
	int y=0;
	int w=HARDWARE_SCREEN_WIDTH_PIXELS;
	int h=HARDWARE_SCREEN_HEIGHT_PIXELS;
	float r=0;
	float g=0;
	float b=0;
	float a=fade_alpha/255.0;



	glDisable(GL_TEXTURE_2D);

	GLfloat box[] = {x,y + h,0, x + w,y + h,0, x + w, y, 0, x,y,0};

	GLfloat col[] = {
		r, g, b, a,
		r, g, b, a,
		r, g, b, a,
		r, g, b, a
	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, box);
	glColorPointer(4, GL_FLOAT, 0, col);
	glDrawArrays(GL_TRIANGLE_FAN,0,4);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	glEnable(GL_TEXTURE_2D);


}

//===========================================================================================================================
void set_zoom()
{//===========================================================================================================================

		if(ZOOM!=ZOOMto)
		{
			if(ZOOM>ZOOMto)ZOOM-=0.05f;
			if(ZOOM<ZOOMto)ZOOM+=0.05f;
		}

		GAME_VIEWPORT_WIDTH_PIXELS=HARDWARE_SCREEN_WIDTH_PIXELS/2/ZOOM;//256
		GAME_VIEWPORT_HEIGHT_PIXELS=HARDWARE_SCREEN_HEIGHT_PIXELS/2/ZOOM;//192

		SCREEN_WIDTH_TILES=GAME_VIEWPORT_WIDTH_PIXELS/8;//32
		SCREEN_HEIGHT_TILES=GAME_VIEWPORT_HEIGHT_PIXELS/8;//24


}

//===========================================================================================================================
void render()
{//===========================================================================================================================

	//GLint loc;
	//loc = glGetUniformLocation(p[0], "Tex0");
	//glUniform1i(loc, screen);

	//glUseProgram(p[0]);

	set_zoom();

	float tempZOOM=ZOOM;

	if(framebuffer)
	{
		//attach a texture to a framebuffer, render directly into texture
		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fb);
	}
	glClear( GL_COLOR_BUFFER_BIT );

	ZOOM=2.0f;

	//confusingly, the game scales everything by 2x at ZOOM 1x. the internal game engine thinks it is running at half the rendered resolution.







	gl_draw_bg(3);
	gl_draw_sprites(0);

	if(fade_alpha>0&&fade_layer==0)draw_black_overlay();

	gl_draw_bg(0);
	gl_draw_sprites(3);

	if(fade_alpha>0&&fade_layer==1)draw_black_overlay();

	gl_draw_bg(2);
	gl_draw_sprites(2);

	if(fade_alpha>0&&fade_layer==2)draw_black_overlay();

	gl_draw_bg(1);
	gl_draw_sprites(1);

	if(fade_alpha>0&&fade_layer==3)draw_black_overlay();



	//AUX bg

	int a=0;
	a=0;
	if(AUX_bg_is_on[a])if(glIsTexture(GLTex_AUX_bg[a]))draw_texture(GLTex_AUX_bg[a],ZOOM*AUX_bg_x[a],ZOOM*AUX_bg_y[a],ZOOM*AUX_bg_zoom[a]*AUX_bg_texture_size_x[a], ZOOM*AUX_bg_zoom[a]*AUX_bg_texture_size_y[a]);
	gl_draw_sprites(4);

	if(fade_alpha>0&&fade_layer==4)draw_black_overlay();

	a=1;
	if(AUX_bg_is_on[a])if(glIsTexture(GLTex_AUX_bg[a]))draw_texture(GLTex_AUX_bg[a],ZOOM*AUX_bg_x[a],ZOOM*AUX_bg_y[a],ZOOM*AUX_bg_zoom[a]*AUX_bg_texture_size_x[a], ZOOM*AUX_bg_zoom[a]*AUX_bg_texture_size_y[a]);
	gl_draw_sprites(5);

	if(fade_alpha>0&&fade_layer==5)draw_black_overlay();

	a=2;
	if(AUX_bg_is_on[a])if(glIsTexture(GLTex_AUX_bg[a]))draw_texture(GLTex_AUX_bg[a],ZOOM*AUX_bg_x[a],ZOOM*AUX_bg_y[a],ZOOM*AUX_bg_zoom[a]*AUX_bg_texture_size_x[a], ZOOM*AUX_bg_zoom[a]*AUX_bg_texture_size_y[a]);
	gl_draw_sprites(6);

	if(fade_alpha>0&&fade_layer==6)draw_black_overlay();

	a=3;
	if(AUX_bg_is_on[a])if(glIsTexture(GLTex_AUX_bg[a]))draw_texture(GLTex_AUX_bg[a],ZOOM*AUX_bg_x[a],ZOOM*AUX_bg_y[a],ZOOM*AUX_bg_zoom[a]*AUX_bg_texture_size_x[a], ZOOM*AUX_bg_zoom[a]*AUX_bg_texture_size_y[a]);
	gl_draw_sprites(7);

	if(fade_alpha>0&&fade_layer==7)draw_black_overlay();



	ZOOM=tempZOOM;




	//i wanted to draw everything into a single texture so i could zoom into it? i think thats why
	//i think i wanted to double the resolution and draw everything at 2x


	if(!framebuffer)
	{
		//=====================
		//Copy texture from back buffer manually (slow)
		//=====================

		int pw=GAME_VIEWPORT_WIDTH_PIXELS;
		int ph=GAME_VIEWPORT_HEIGHT_PIXELS;
		if(IsNPOT(pw,ph))
		{
		pw = (int)powf(2.0, ceilf(logf((float)pw)/logf(2.0f)));
		ph = (int)powf(2.0, ceilf(logf((float)ph)/logf(2.0f)));
		}

		int pwdiff = pw-GAME_VIEWPORT_WIDTH_PIXELS;
		int phdiff = ph-GAME_VIEWPORT_HEIGHT_PIXELS;

		//bind screen texture to 2d
		glBindTexture(GL_TEXTURE_2D, screen);

		//copy back buffer image into screen texture
		glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, 0,HARDWARE_SCREEN_HEIGHT_PIXELS/2-GAME_VIEWPORT_HEIGHT_PIXELS,pw, ph, 0);
		//clear back buffer
		glClear( GL_COLOR_BUFFER_BIT );
		//draw screen to back buffer, but flipped because its upside down for some reason
		gl_draw_flipped(screen,0,-(phdiff*ZOOM),HARDWARE_SCREEN_WIDTH_PIXELS/2+(pwdiff*ZOOM),HARDWARE_SCREEN_HEIGHT_PIXELS/2+(phdiff*ZOOM));
	}


	if(framebuffer)
	{

		//Be sure to reset the rendering state afterwards by binding the zero framebuffer object (the screen):
		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);

		//clear the screen
		glClear(GL_COLOR_BUFFER_BIT);


		/*GLint loc;
		loc = glGetUniformLocation(p[1], "Tex0");
		glUniform1i(loc, 0);

		loc = glGetUniformLocation(p[1], "Gamma");
		glUniform1f(loc, 0.9f);

		glUseProgram(p[1]);*/

		//#ifdef ND gl_draw_flipped(screen,0,0,(HARDWARE_SCREEN_WIDTH_PIXELS*ZOOM),(HARDWARE_SCREEN_HEIGHT_PIXELS*ZOOM));

		gl_draw_flipped(screen,0,0//-(((HARDWARE_SCREEN_HEIGHT_PIXELS/4)*((float)((float)(HARDWARE_SCREEN_HEIGHT_PIXELS*2)/(float)(GAME_VIEWPORT_HEIGHT_PIXELS*2)))))
						,
						(HARDWARE_SCREEN_WIDTH_PIXELS*ZOOM)//*2*((float)((float)(HARDWARE_SCREEN_WIDTH_PIXELS*2)/(float)(GAME_VIEWPORT_WIDTH_PIXELS*2))))
						,
						(HARDWARE_SCREEN_HEIGHT_PIXELS*ZOOM)//*2*((float)((float)(HARDWARE_SCREEN_HEIGHT_PIXELS*2)/(float)(GAME_VIEWPORT_HEIGHT_PIXELS*2))))
						);
	}



//this needs to be here because for some reason it gets clipped after zooming if i draw it on the framebuffer
	if(error_console_on)ERROR_draw_error_console();
	DEBUG_draw_overlays();




}
