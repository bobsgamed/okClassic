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

*/

//#include <e32def.h>
//#include <e32std.h>
#include <stdio.h>
#include <string.h>

#include "GL/gl.h"
#include "glesinterface.h"

extern "C++" GlESInterface* glEsImpl;

void glEnable (GLenum cap)
    {
        glEsImpl->glEnable(cap);
    }

void glDisable (GLenum cap)
    {
        glEsImpl->glDisable(cap);
    }

void glViewport (GLint x, GLint y, GLsizei width, GLsizei height)
    {
    glEsImpl->glViewport(x,y,width,height);
    }

void glLoadIdentity (void)
    {
    glEsImpl->glLoadIdentity();
    }

void glOrtho (GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar)
    {
    glEsImpl->glOrthof(left,right,bottom,top, zNear,zFar);
    }

void glMatrixMode (GLenum mode)
    {
    glEsImpl->glMatrixMode(mode);
    }

void glTexParameteri (GLenum target, GLenum pname, GLint param)
    {
    glEsImpl->glTexParameteri(target, pname,param);
    }


void glTexParameterf (GLenum target, GLenum pname, GLfloat param)
    {
    glEsImpl->glTexParameterf(target, pname,param);
    }

void glTexParameterfv(	GLenum target, GLenum pname, const GLfloat *params)
    {
    glTexParameterf(target, pname, params[0]);
    }

void glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
    {
    glEsImpl->glTexImage2D(target, level, format, width, height,border,format,type,pixels);
    }

void glDrawBuffer(GLenum /*mode*/)
    {
    }

void glTranslatef (GLfloat x, GLfloat y, GLfloat z)
    {
    glEsImpl->glTranslatef(x,y,z);
    }

void glRotatef (GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
    {
    glEsImpl->glRotatef(angle, x, y, z);
    }

void glScalef (GLfloat x, GLfloat y, GLfloat z)
    {
    glEsImpl->glScalef(x,y,z);
    }

void glDepthRange(GLclampf zNear, GLclampf zFar)
    {
    glEsImpl->glDepthRangef(zNear, zFar);
    }

void glDepthFunc (GLenum func)
    {
    glEsImpl->glDepthFunc(func);
    }

void glFinish (void)
    {
    glEsImpl->glFinish();
    }

void glGetFloatv (GLenum pname, GLfloat *params)
    {
    glEsImpl->glGetFloatv(pname, params);
    }

void glCullFace (GLenum mode)
    {
    glEsImpl->glCullFace(mode);
    }

void glFrustum (GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar)
    {
    glEsImpl->glFrustumf(left,right,bottom,top,zNear,zFar);
    }

void glClear (GLbitfield mask)
    {
    glEsImpl->glClear(mask);
    }


void glHint (GLenum target, GLenum mode)
    {
    glEsImpl->glHint(target, mode);
    }

void glBlendFunc (GLenum sfactor, GLenum dfactor)
    {
    glEsImpl->glBlendFunc(sfactor, dfactor);
    }

void glPopMatrix (void)
    {
    glEsImpl->glPopMatrix();
    }

void glShadeModel (GLenum mode)
    {
    glEsImpl->glShadeModel(mode);
    }

void glPushMatrix (void)
    {
    glEsImpl->glPushMatrix();
    }

void glTexEnvf (GLenum target, GLenum pname, GLfloat param)
    {
    glEsImpl->glTexEnvf(target, pname, param);
    }

void glDepthMask (GLboolean flag)
    {
    glEsImpl->glDepthMask(flag);
    }

void glBindTexture (GLenum target, GLuint texture)
    {
    glEsImpl->glBindTexture(target, texture);
    }


void glGetIntegerv (GLenum pname, GLint *params)
    {
    glEsImpl->glGetIntegerv(pname, params);
    }

const GLubyte* glGetString (GLenum name)
    {
    return glEsImpl->glGetString(name);
    }

void glAlphaFunc (GLenum func, GLclampf ref)
    {
    glEsImpl->glAlphaFunc(func,ref);
    }

void glFlush (void)
    {
    glEsImpl->glFlush();
    }

void glReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels)
    {
    glEsImpl->glReadPixels(x,y,width,height,format,type,pixels);
    }

void glReadBuffer( GLenum /*mode*/ )
    {

    }

void glLoadMatrixf (const GLfloat *m)
    {
    glEsImpl->glLoadMatrixf(m);
    }

void glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
    {
    glEsImpl->glTexSubImage2D(target,level,xoffset,yoffset,width,height,format,type,pixels);
    }

void glClearColor (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
    {
    glEsImpl->glClearColor(red,green,blue,alpha);
    }

GLenum glGetError (void)
    {
    return glEsImpl->glGetError();
    }

void glActiveTexture (GLenum texture)
    {
    	glEsImpl->glActiveTexture(texture);
    }

void glClientActiveTexture (GLenum texture)
    {
    	glEsImpl->glClientActiveTexture(texture);
    }

void glPolygonMode( GLenum face, GLenum mode )
    {
    }

void glDeleteTextures( GLsizei n, const GLuint *textures )
    {
    glEsImpl->glDeleteTextures(n,textures);
    }

void glClearDepth( GLclampf depth )
    {
    glEsImpl->glClearDepthf( depth );
    }

void glClipPlane( GLenum plane, const GLdouble *equation )
    {
    float array[4];
    array[0] = (GLfloat)(equation[0]);
    array[1] = (GLfloat)(equation[1]);
    array[2] = (GLfloat)(equation[2]);
    array[3] = (GLfloat)(equation[3]);
    glEsImpl->glClipPlanef( plane, array );
    }

void glScissor( GLint x, GLint	y, GLsizei width, GLsizei height )
    {
    glEsImpl->glScissor( x, y, width,height);
    }

void glPointSize( GLfloat size )
    {
    glEsImpl->glPointSize( size );
    }

void glArrayElement(GLint i) {}
void glLineWidth(GLfloat width) {}
void glCallList( GLuint list ) {}
void glColorMask( GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha ) {}
void glStencilFunc( GLenum func, GLint ref, GLuint mask ) {}
void glStencilOp( GLenum fail, GLenum zfail, GLenum zpass ) {}

void glDrawElements( GLenum mode, GLsizei count, GLenum type, const GLvoid *indices )
    {
    glEsImpl->glDrawElements(mode, count, type, indices);
    }

void glDrawArrays( GLenum mode, GLint first, GLsizei count)
{
	glEsImpl->glDrawArrays(mode, first, count);
}

void glEnableClientState(GLenum  array)
    {
    	glEsImpl->glEnableClientState(array);
    }
void glDisableClientState(GLenum  array)
    {
    	glEsImpl->glDisableClientState(array);
    }

void glVertexPointer(	GLint size,	GLenum type,GLsizei	stride,	const GLvoid *pointer )
    {
    	glEsImpl->glVertexPointer(size, type, stride, pointer);
    }

void glTexCoordPointer( GLint	size,  GLenum type,  GLsizei stride,  const	GLvoid *pointer	)
    {
    	glEsImpl->glTexCoordPointer(size, type, stride, pointer);
    }
void glColorPointer( GLint size,  GLenum type,  GLsizei stride,  const GLvoid *pointer )

    {
    	glEsImpl->glColorPointer(size, type, stride, pointer);
    }

void glPolygonOffset( GLfloat factor, GLfloat units )
    {
    glEsImpl->glPolygonOffset(factor, units);
    }

void glStencilMask( GLuint mask ) {}
void glClearStencil( GLint s ) {}

// Added by Pickle
void glGenTextures( GLint n, GLenum *textures )
    {
    glEsImpl->glGenTextures( n, textures );
    }

void glPixelStorei( GLenum pname, GLint param )
    {
    glEsImpl->glPixelStorei( pname, param );
    }

void glDrawTexsOES(GLshort x, GLshort y, GLshort z, GLshort w, GLshort h)
{
	glEsImpl->glDrawTexsOES(x, y, z, w, h);
}
    
void glColor4f(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	glEsImpl->glColor4f(r, g, b, a);
}

void glGetBooleanv(GLenum pname, GLboolean *params)
{
	glEsImpl->glGetBooleanv(pname, params);
}

void glGetTexParameteriv(GLenum target, GLenum pname, GLint *params)
{
	glEsImpl->glGetTexParameteriv(target, pname, params);
}

GLboolean glIsEnabled(GLenum cap)
{
	return glEsImpl->glIsEnabled(cap);
}
