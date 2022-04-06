
#include <iostream>

#include <SDL/SDL.h>

#include <SDL/SDL_syswm.h>



#include <GLES/egl.h>

#include <GLES/gl.h>



using namespace std;



int main(int argc, char* argv[])

{

SDL_Init(SDL_INIT_EVERYTHING);

const int winw = 320;

const int winh = 240;

SDL_SetVideoMode(winw, winh, 32, 0);



// grab the window's HWND

static SDL_SysWMinfo wmInfo;

SDL_VERSION( &wmInfo.version );

SDL_GetWMInfo( &wmInfo );



NativeDisplayType nativeDisplay = (NativeDisplayType)GetDC(wmInfo.window);

NativeWindowType nativeWindow = (NativeWindowType)wmInfo.window;



const int pbw = 512;

const int pbh = 512;



EGLDisplay eglDisplay;

EGLConfig eglConfig;

EGLSurface eglSurface;

EGLContext eglContext;



eglDisplay = eglGetDisplay( nativeDisplay );

eglInitialize(eglDisplay, NULL, NULL);

EGLint attribs[] = {

    EGL_RED_SIZE,               5,

    EGL_GREEN_SIZE,             5,

    EGL_BLUE_SIZE,              5,

    EGL_ALPHA_SIZE,             0,

    EGL_DEPTH_SIZE,             16,

    EGL_MAX_PBUFFER_WIDTH,      pbw,

    EGL_MAX_PBUFFER_HEIGHT,     pbh,

    EGL_BIND_TO_TEXTURE_RGBA,   EGL_TRUE,

    EGL_SURFACE_TYPE,           EGL_WINDOW_BIT | EGL_PBUFFER_BIT,

    EGL_NONE,

};

int iConfigs = 0;

eglChooseConfig(eglDisplay, attribs, &eglConfig, 1, &iConfigs);

eglSurface = eglCreateWindowSurface(eglDisplay, eglConfig, nativeWindow, NULL);

eglContext = eglCreateContext(eglDisplay, eglConfig, NULL, NULL);



eglMakeCurrent(eglDisplay, eglSurface, eglSurface, eglContext);



EGLint pbuffer_attribs[] = {

     EGL_WIDTH,                  pbw,

     EGL_HEIGHT,                 pbh,

     EGL_TEXTURE_TARGET,         EGL_TEXTURE_2D,

     EGL_TEXTURE_FORMAT,         EGL_TEXTURE_RGBA,

     EGL_NONE

};

EGLSurface pbuffer = eglCreatePbufferSurface(eglDisplay, eglConfig, pbuffer_attribs);



GLuint pbuffer_texobj;

glEnable(GL_TEXTURE_2D);

glGenTextures(1, &pbuffer_texobj);

glBindTexture(GL_TEXTURE_2D, pbuffer_texobj);

glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);

glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);





// ES1.1 only allows 4-component colors

GLfloat verts[] = {

    0.0f, 0.0f, 0.0f,           // pos

    1.0f, 0.0f, 0.0f, 1.0f,     // color

    1.0f, 0.0f, 0.0f,           // pos

    0.0f, 1.0f, 0.0f, 1.0f,     // color

    1.0f, 1.0f, 0.0f,           // pos

    0.0f, 0.0f, 1.0f, 1.0f,     // color

    };

GLubyte index[] = {0, 1, 2};



// textured quad

GLfloat verts2[] = {

    0, 0, 0,

    0, 0,

    1, 0, 0,

    1, 0,

    1, 1, 0,

    1, 1,

    0, 1, 0,

    0, 1,

    };

GLubyte index2[] = {0, 1, 3, 3, 1, 2};



float size;



bool running = true;

SDL_Event event;

while( running )

    {

    // handle all pending events

    while( SDL_PollEvent(&event) ) {

         switch (event.type) {

              case SDL_KEYDOWN: switch(event.key.keysym.sym) {

                   case SDLK_ESCAPE: running = false; break;

                   default: break;

             } break;

              case SDL_QUIT: running = false; break;

              default: break;

        }

    }



    // render to texture bound to our pbuffer

    eglMakeCurrent(eglDisplay, pbuffer, pbuffer, eglContext);

    glViewport(0, 0, pbw, pbh);

    glClearColor(1,0,1,1);

    glClear(GL_COLOR_BUFFER_BIT);



    glMatrixMode(GL_PROJECTION); glLoadIdentity();

    size = 0.6f;

    glOrthof(-size, size, -size, size, -1.0f, 1.0f);

    glMatrixMode(GL_MODELVIEW); glLoadIdentity();



    glEnableClientState(GL_VERTEX_ARRAY);

    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, sizeof(GLfloat)*7, &verts[0]);

    glColorPointer(4, GL_FLOAT, sizeof(GLfloat)*7, &verts[3]);



    glDisable(GL_TEXTURE_2D);

    glPushMatrix();

    glRotatef(SDL_GetTicks() / 10.0f, 0, 0, 1);

    glTranslatef(-0.5f, -0.5f, 0);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glPopMatrix();





    // render textured quad using pbuffer texture

    eglMakeCurrent(eglDisplay, eglSurface, eglSurface, eglContext);



    glBindTexture(GL_TEXTURE_2D, pbuffer_texobj);

    eglBindTexImage(eglDisplay, pbuffer, EGL_BACK_BUFFER);



    glViewport(0, 0, winw, winh);

    glClearColor(0,0,0,1);

    glClear(GL_COLOR_BUFFER_BIT);



    glMatrixMode(GL_PROJECTION); glLoadIdentity();

    size = 0.8f;

    glOrthof(-size, size, -size, size, -1.0f, 1.0f);

    glMatrixMode(GL_MODELVIEW); glLoadIdentity();



    glDisableClientState(GL_COLOR_ARRAY);

    glEnableClientState(GL_VERTEX_ARRAY);

    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glVertexPointer(3, GL_FLOAT, sizeof(GLfloat)*5, &verts2[0]);

    glTexCoordPointer(2, GL_FLOAT, sizeof(GLfloat)*5, &verts2[3]);



    glEnable(GL_TEXTURE_2D);

    glColor4f(1,1,1,1);

    glBindTexture(GL_TEXTURE_2D, pbuffer_texobj);

    glPushMatrix();

    //glRotatef(-(float)SDL_GetTicks() / 100.0f, 0, 0, 1);

    glTranslatef(-0.5f, -0.5f, 0);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, index2);

    glPopMatrix();



    eglReleaseTexImage(eglDisplay, pbuffer, EGL_BACK_BUFFER);





    glFlush();

    eglSwapBuffers(eglDisplay, eglSurface);

    SDL_Delay(1);

    }



eglReleaseTexImage(eglDisplay, pbuffer, EGL_BACK_BUFFER);

eglDestroySurface(eglDisplay, pbuffer);

glDeleteTextures(1, &pbuffer_texobj);



eglMakeCurrent(eglDisplay, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);

eglTerminate(eglDisplay);



SDL_Quit();

return 0;

}
