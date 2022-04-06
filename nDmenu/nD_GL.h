

//uncomment to slow down speeds for wiz
//#define BUILD_WIZ

//uncomment for GLES 1, leave commented for GL
#define GLES1


#ifdef GLES1

	#include <SDL/SDL_syswm.h>
	#include <SDL/SDL.h>

	#ifdef BUILD_WIZ

	#include <GL/nanogl.h>
	#include <GL/gl.h>
	#include <GL/egl.h>

	#include <GL/libogl.h>

	#else
		//use windows GLES libs, with POWERVR emulation
		#include <GLES/egl.h>
		#include <GLES/gl.h>

	#endif

#else
	//use standard windows openGL
	#ifndef BUILD_WIZ
		#include "glee.h"
	#endif

	#include <SDL/SDL.h>

	#define NO_SDL_GLEXT
	#include "SDL/SDL_opengl.h"

#endif

#ifdef MIX_ON
#include "SDL/SDL_mixer.h"
#endif



#ifdef GLES1


EGLDisplay glDisplay;
EGLConfig glConfig;
EGLContext glContext;
EGLSurface glSurface;
NativeWindowType hNativeWnd = 0;
	EGLint numConfigs;
	EGLint majorVersion;
	EGLint minorVersion;


EGLint attrib_list[] =
{
  EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
  //EGL_BIND_TO_TEXTURE_RGBA,   EGL_TRUE,
    //EGL_RED_SIZE,               5,
   // EGL_GREEN_SIZE,             5,
   // EGL_BLUE_SIZE,              5,
    //EGL_ALPHA_SIZE,             1,
  //EGL_BUFFER_SIZE, 0,
  EGL_DEPTH_SIZE, 16,
  EGL_NONE
};





#endif

	typedef struct
	{
		int image_w;
		int image_h;
		int texture_w;
		int texture_h;
		GLuint texture_id;

	}texture_STRUCT;

int framebuffer=0;
texture_STRUCT* screen_TEXTURE;
GLuint fb;

//===========================================================================================================================
int power_of_two(int v)
{//===========================================================================================================================
	v--;
	v|=v>>1;
	v|=v>>2;
	v|=v>>4;
	v|=v>>8;
	v|=v>>16;
	v++;
	return v++;
}


//===========================================================================================================================
texture_STRUCT* load_texture(const char* filename)
{//===========================================================================================================================

	GLuint texture_id;

	SDL_Surface* image = IMG_Load(filename);

	int image_w = image->w;
	int image_h = image->h;

	int texture_w = power_of_two(image_w);
	int texture_h = power_of_two(image_h);

	//blit from bitmap to a temporary surface with 32 bits per pixel
	SDL_Surface* temp = SDL_CreateRGBSurface(SDL_SWSURFACE, texture_w, texture_h, 32, rmask, gmask, bmask, amask);

	SDL_Rect area;
	area.x = 0;
	area.y = 0;
	area.w = image_w;
	area.h = image_h;

	SDL_SetAlpha(image, 0, 0);

	SDL_BlitSurface(image, &area, temp, NULL);

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
	//free image surface
	SDL_FreeSurface(image);

	texture_STRUCT* temp_TEXTURE =	malloc(sizeof(texture_STRUCT));

	temp_TEXTURE->image_w=image_w;
	temp_TEXTURE->image_h=image_h;
	temp_TEXTURE->texture_w=texture_w;
	temp_TEXTURE->texture_h=texture_h;
	temp_TEXTURE->texture_id=texture_id;

	return temp_TEXTURE;

}



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


	texture_STRUCT* temp_TEXTURE =	malloc(sizeof(texture_STRUCT));

	temp_TEXTURE->image_w=image_w;
	temp_TEXTURE->image_h=image_h;
	temp_TEXTURE->texture_w=texture_w;
	temp_TEXTURE->texture_h=texture_h;
	temp_TEXTURE->texture_id=texture_id;




	return temp_TEXTURE;
}


//===========================================================================================================================
texture_STRUCT* load_texture_directly_from_square_surface(SDL_Surface *temp)
{//===========================================================================================================================


	GLuint texture_id;



	//create texture
	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);

	if (SDL_MUSTLOCK(temp))
		SDL_LockSurface(temp);

	//make texture from temp surface pixels
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, temp->w, temp->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, temp->pixels);



	if (SDL_MUSTLOCK(temp))
		SDL_UnlockSurface(temp);

	//set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);



	texture_STRUCT* temp_TEXTURE =	malloc(sizeof(texture_STRUCT));

	temp_TEXTURE->image_w=temp->w;
	temp_TEXTURE->image_h=temp->h;
	temp_TEXTURE->texture_w=temp->w;
	temp_TEXTURE->texture_h=temp->h;
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
void draw_framebuffer(texture_STRUCT* sprite_TEXTURE)
{//===========================================================================================================================

	GLuint texture_id = sprite_TEXTURE->texture_id;
	int w = sprite_TEXTURE->texture_w;
	int h = sprite_TEXTURE->texture_h;
	int x=0;
	int y=0;



	glBindTexture(GL_TEXTURE_2D,texture_id);
	glEnable(GL_TEXTURE_2D);

#ifdef GLES1




	GLfloat box[] = {x,y + h,0,  x + w,y + h,0,     x + w, y, 0,   x,y,0};
	GLfloat tex[] = {0,1, 1,1, 1,0, 0,0};

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0,box);
	glTexCoordPointer(2, GL_FLOAT, 0, tex);

	glDrawArrays(GL_TRIANGLE_FAN,0,4);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);


#else
		//glPushMatrix();

		//make a rectangle
		glBegin(GL_QUADS);
			//top left
			glTexCoord2i(0,1);
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

		//glDisable(GL_TEXTURE_2D );

		//glPopMatrix();

#endif

}




//===========================================================================================================================
void draw_texture(texture_STRUCT* sprite_TEXTURE, int x, int y)
{//===========================================================================================================================

	GLuint texture_id = sprite_TEXTURE->texture_id;
	int w = sprite_TEXTURE->texture_w;
	int h = sprite_TEXTURE->texture_h;



	glBindTexture(GL_TEXTURE_2D,texture_id);
	glEnable(GL_TEXTURE_2D);

#ifdef GLES1



	GLfloat box[] = {x,y + h,0,  x + w,y + h,0,     x + w, y, 0,   x,y,0};
	GLfloat tex[] = {0,1, 1,1, 1,0, 0,0};

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0,box);
	glTexCoordPointer(2, GL_FLOAT, 0, tex);

	glDrawArrays(GL_TRIANGLE_FAN,0,4);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);



#else
		//glPushMatrix();



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

		//glDisable(GL_TEXTURE_2D );

		//glPopMatrix();
	#endif
}


//===========================================================================================================================
void draw_texture_alpha(texture_STRUCT* sprite_TEXTURE, int x, int y, float a)
{//===========================================================================================================================

	GLuint texture_id = sprite_TEXTURE->texture_id;
	int w = sprite_TEXTURE->texture_w;
	int h = sprite_TEXTURE->texture_h;



	glBindTexture(GL_TEXTURE_2D,texture_id);
	glEnable(GL_TEXTURE_2D);

#ifdef GLES1


	GLfloat col[] = {
        1, 1, 1, a,
        1, 1, 1, a,
        1, 1, 1, a,
        1, 1, 1, a
    };

	GLfloat box[] ={
						x,		y+h,	0,
						x+w,	y+h,	0,
						x+w,	y,		0,
						x,		y,		0
					};

	GLfloat tex[] ={
						0,1,
						1,1,
						1,0,
						0,0
					};

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



#else
		//glPushMatrix();



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

		//glDisable(GL_TEXTURE_2D );

		//glPopMatrix();
	#endif
}
//===========================================================================================================================
void fill_rect_gradient(int x, int y, int w, int h, float r, float g, float b, float a)
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


#ifdef GLES1
	glDisable(GL_TEXTURE_2D);

	GLfloat box[] = {x,y + h,0, x + w,y + h,0, x + w, y, 0, x,y,0};

	GLfloat col[] = {
        0, 0, 0, 1,
        0, 0, 0, 1,
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

#endif

}
//===========================================================================================================================
void fill_rect(int x, int y, int w, int h, float r, float g, float b, float a)
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


#ifdef GLES1
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

#endif

}

//===========================================================================================================================
void init_gl()
{//===========================================================================================================================

//#define BUILD_WIZ

	//init gfx-----------------------
		//screen_SURFACE =

#ifdef GLES1


	#ifdef BUILD_WIZ
			SDL_SetVideoMode(320, 240, 16,  SDL_SWSURFACE);
	#else
	//windows GLES emulation
			SDL_SetVideoMode(320, 240, 16,  SDL_SWSURFACE | SDL_OPENGL);
	#endif

#else
//windows GL
		SDL_SetVideoMode(320, 240, 32,  SDL_OPENGL);
#endif

		SDL_ShowCursor(0);

		SDL_WM_SetCaption( "nD", "nD" );
		//SDL_WM_SetIcon(SDL_LoadBMP("icon.bmp"), NULL);



#if SDL_BYTEORDER == SDL_BIG_ENDIAN
	rmask = 0xff000000;
	gmask = 0x00ff0000;
	bmask = 0x0000ff00;
	amask = 0x000000ff;

#else
	rmask = 0x000000ff;
	gmask = 0x0000ff00;
	bmask = 0x00ff0000;
	amask = 0xff000000;
#endif


	//-------------------------------
	//init openGL ES 1
	//-------------------------------
#ifdef GLES1

		//SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
		//SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
		//SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
		//SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
		//SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 1);
		//SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);


	#ifdef BUILD_WIZ

		nanoGL_Init();

		// Create native window.
		hNativeWnd = OS_CreateWindow();
		//printf("create window.\n");SDL_Delay(1000);
		glDisplay = eglGetDisplay( (NativeDisplayType)0 );
		//printf("get display.\n");SDL_Delay(1000);


			eglInitialize( glDisplay, &majorVersion, &minorVersion );

			if(!eglChooseConfig( glDisplay, attrib_list, &glConfig, 1, &numConfigs))
			{
				exit(0);
			}

			glSurface = eglCreateWindowSurface( glDisplay, glConfig, hNativeWnd, attrib_list);

			glContext = eglCreateContext( glDisplay, glConfig, EGL_NO_CONTEXT, attrib_list);

			eglMakeCurrent( glDisplay, glSurface, glSurface, glContext );

	#else

			// Get the SDL window handle
			SDL_SysWMinfo wmInfo; //Will hold our Window information
			SDL_VERSION(&wmInfo.version); //Set SDL version
			if(SDL_GetWMInfo(&wmInfo) <= 0)
				printf("Unable to get window handle");


			NativeWindowType nativeWindow = (NativeWindowType)wmInfo.window;
			NativeDisplayType nativeDisplay = GetDC(nativeWindow);



			// use EGL to initialise GLES
			glDisplay = eglGetDisplay(nativeDisplay);
			if (glDisplay == EGL_NO_DISPLAY)
				printf("Unable to initialise EGL display.\n");

			 // Bind GLES and create the context
			eglBindAPI(EGL_OPENGL_ES_API);



			eglInitialize( glDisplay, NULL,NULL);//&majorVersion, &minorVersion );

			if(!eglChooseConfig( glDisplay, attrib_list, &glConfig, 1, &numConfigs))
			{
				exit(0);
			}

			glSurface = eglCreateWindowSurface( glDisplay, glConfig, hNativeWnd, 0);

			glContext = eglCreateContext( glDisplay, glConfig, EGL_NO_CONTEXT, NULL);

			eglMakeCurrent( glDisplay, glSurface, glSurface, glContext );

	#endif


		glViewport(0,0,320,240);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

	#ifdef BUILD_WIZ
			glOrtho( 0, 320, 240, 0, -1, 1 );
	#else
			glOrthof( 0, 320, 240, 0, -1, 1 );
	#endif
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();


		//glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		//glBlendFunc(GL_SRC_ALPHA, GL_ONE);




#else

	//-------------------------------
	//init regular openGL
	//-------------------------------

		//SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

		//if(GLEE_WGL_EXT_swap_control){wglSwapIntervalEXT(1);}
		//SDL_GL_SetAttribute( SDL_GL_SWAP_CONTROL, 1 );

		//if(GLEE_EXT_framebuffer_object){framebuffer=1;}

		glViewport(0,0,320,240);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho( 0, 320, 240, 0, -1, 1 );
		glMatrixMode(GL_MODELVIEW);

		glLoadIdentity();

		glClearColor(0, 0, 0, 0);

		glDisable(GL_DEPTH_TEST);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);


    //------------------------------------------
    //set up framebuffer object
    //------------------------------------------

		texture_STRUCT screen;
		screen_TEXTURE = &screen;

		screen_TEXTURE->texture_w=320;
		screen_TEXTURE->texture_h=240;



        glGenTextures(1,&screen_TEXTURE->texture_id); // make a new texture

        if(framebuffer)
        {
			glBindTexture(GL_TEXTURE_2D,screen_TEXTURE->texture_id); // modify (or draw) our texture

			glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA, 320,240,0, GL_RGBA,GL_UNSIGNED_BYTE,0); // the texture is w x h pixels

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

			glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, screen_TEXTURE->texture_id, 0);
        }

		//glClearColor(0.0f,0.0f,0.0f,1.0f);
		//Enable z-buffer
		//glEnable(GL_DEPTH_TEST);
		//glDepthMask(GL_TRUE);



		//glColor4f(1.0f,1.0f,1.0f,1.0f);
		//glEnable(GL_TEXTURE_2D);

		//glAlphaFunc(GL_GREATER,0.1f);

		//glLoadIdentity();

		#endif




}


//===========================================================================================================================
void begin_render_loop()
{//===========================================================================================================================

	#ifdef GLES1


	#else
		if(framebuffer)
		{
			glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fb);
			glClear( GL_COLOR_BUFFER_BIT );
		}
	#endif

}


//===========================================================================================================================
void finish_render_loop()
{//===========================================================================================================================


		//SDL_Flip( screen_TEXTURE ); //this waits for vblank too!!!


	#ifdef GLES1


	#else
		if(framebuffer)
		{
			//Be sure to reset the rendering state afterwards by binding the zero framebuffer object (the screen):
			glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
			//clear the screen
			glClear(GL_COLOR_BUFFER_BIT);

			draw_framebuffer(screen_TEXTURE);
		}
	#endif

	#ifdef GLES1
	eglSwapBuffers(glDisplay, glSurface);
	#else
	SDL_GL_SwapBuffers();
	#endif


}

//===========================================================================================================================
void deinit_gl()
{//===========================================================================================================================


	//------------------------------------------
	//deinit openGL stuff
	//------------------------------------------
		#ifdef GLES1
		eglMakeCurrent(glDisplay, NULL, NULL, EGL_NO_CONTEXT);
		eglDestroySurface(glDisplay, glSurface);
		eglDestroyContext(glDisplay, glContext);
		glSurface = 0;
		glContext = 0;
		glConfig = 0;
		eglTerminate(glDisplay);
		glDisplay = 0;


#ifdef BUILD_WIZ
			nanoGL_Destroy();
#endif


		#endif
	//------------------------------------------
}
