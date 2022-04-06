/*
Copyright (C) 2007-2009 Olli Hinkka

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

Modified for use in linux: Pickle

*/

#include <dlfcn.h>
#include <string.h>

#include "GL/gl.h"
#include "GL/nanogl.h"
#include "glesinterface.h"
#include "glesordinals.h"

char KGLESLibraryNam[30] = "libopengles_lite.so";

void* glesLib = NULL;

GlESInterface* glEsImpl = NULL;

void* error;

//extern void InitGLStructs();
//extern const int ordinals;

int CreateGlEsInterface()
{
    int count;

    // Create and initialize the interface
    glEsImpl = new GlESInterface;
    if (!glEsImpl)
    {
        printf( "NGL: Interface could be created!\n" );
        return -1;
    }

    printf( "NGL: Size %d\n", sizeof(GlESInterface) );
    memset( glEsImpl, 0, sizeof(GlESInterface) );
    int32_t** ptr = (int32_t**)(glEsImpl);

    // Dynamically link all the functions by ordinal string name
    printf( "NGL: Starting to dynamically link to %d functions!\n", ordinals );
    for (count = 0; count < ordinals; count++)
    {
        printf( "NGL: Linking to %s(%d)", GlESOrdinals[count].c_str(), count );
        *ptr = (int32_t*)(dlsym(glesLib, GlESOrdinals[count].c_str()));

        if (!*ptr)
        {
            printf( "NGL: FATAL ERROR %s\n", dlerror());
            return -1;
        }
        else printf( " Pointer %X\n", *ptr );

        ptr++;
    }
    return 0;
}

int nanoGL_Init( void )
{
    printf( "NGL: Starting\n  Using library: %s\n", KGLESLibraryNam );
    glesLib = dlopen(KGLESLibraryNam, RTLD_LAZY);
    if (!glesLib)
    {
        printf( "NGL: FATAL ERROR %s\n", dlerror());
        return -1;
    }
    printf( "NGL: Library opened! Making the interface\n" );
    if (CreateGlEsInterface() == -1)
    {
        if (glesLib)
        {
            dlclose(glesLib);
        }
        glesLib = NULL;

        return -1;
    }
//    printf( "NGL: Interface Complete! Init GLStructs\n" );
    //InitGLStructs();

    printf( "NGL: Init Complete! You should have a Opengl wrapper now :-)\n" );
    return 0;
}

void nanoGL_Destroy( void )
{
    if (glEsImpl)
    {
        delete glEsImpl;
        glEsImpl = NULL;
        printf( "NGL: Interface released!\n" );
    }
    if (glesLib)
    {
        dlclose(glesLib);
        printf( "NGL: Library released!\n" );
    }
    glesLib = NULL;
    printf( "NGL: Shutdown!\n" );
}

