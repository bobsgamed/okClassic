
varying vec2 TexCoord;

void main(void)
{
	gl_Position = ftransform();
	gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;


    TexCoord    = gl_MultiTexCoord0.st;

}
