



#include "../../main.h"
//#include "misc.h"
//===========================================================================================================================
int r(int lessthan)
{//===========================================================================================================================
	return rand()%lessthan;
}


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


//==========================================================================================================================
int IsNPOT(int width, int height)// Check for non-power-of-two textures
{//==========================================================================================================================
	if ((int)powf(2.0f, ceilf(logf((float)width)/logf(2.0f))) != width)
		return 1;
	if ((int)powf(2.0f, ceilf(logf((float)height)/logf(2.0f))) != height)
		return 1;
	else
		return 0;
}



//==========================================================================================================================
int HARDWARE_modulo(int var, int modulo)
{//==========================================================================================================================
    while(var < 0) var += modulo;
    return (var%modulo);
}

//==========================================================================================================================
int HARDWARE_RGB(int r, int g, int b)
{//==========================================================================================================================
	return ((1<<15)+(r)+((g)<<5)+((b)<<10));
}


//==========================================================================================================================
void RGBToHSL(float r, float g, float b, float *h, float *s, float *l)
{//==========================================================================================================================


	//float fmin = min(min(r, g), b);    //Min. value of RGB
	//float fmax = max(max(r, g), b);    //Max. value of RGB
	float fmin = r;
	if(g<fmin)fmin=g;
	if(b<fmin)fmin=b;

	float fmax = r;
	if(g>fmax)fmax=g;
	if(b>fmax)fmax=b;

	float delta = fmax - fmin;             //Delta RGB value

	*l = (fmax + fmin) / 2.0; // Luminance

	if (delta == 0.0)		//This is a gray, no chroma...
	{
		*h = 0.0;	// Hue
		*s = 0.0;	// Saturation
	}
	else                                    //Chromatic data...
	{
		if (*l < 0.5)
			*s = delta / (fmax + fmin); // Saturation
		else
			*s = delta / (2.0 - fmax - fmin); // Saturation

		float deltaR = (((fmax - r) / 6.0) + (delta / 2.0)) / delta;
		float deltaG = (((fmax - g) / 6.0) + (delta / 2.0)) / delta;
		float deltaB = (((fmax - b) / 6.0) + (delta / 2.0)) / delta;

		if (r == fmax )
			*h = deltaB - deltaG; // Hue
		else if (g == fmax)
			*h = (1.0 / 3.0) + deltaR - deltaB; // Hue
		else if (b == fmax)
			*h = (2.0 / 3.0) + deltaG - deltaR; // Hue

		if (*h < 0.0)
			*h += 1.0; // Hue
		else if (*h > 1.0)
			*h -= 1.0; // Hue
	}


}
//==========================================================================================================================
float HueToRGB(float f1, float f2, float hue)
{//==========================================================================================================================
	if (hue < 0.0)
		hue += 1.0;
	else if (hue > 1.0)
		hue -= 1.0;
	float res;
	if ((6.0 * hue) < 1.0)
		res = f1 + (f2 - f1) * 6.0 * hue;
	else if ((2.0 * hue) < 1.0)
		res = f2;
	else if ((3.0 * hue) < 2.0)
		res = f1 + (f2 - f1) * ((2.0 / 3.0) - hue) * 6.0;
	else
		res = f1;
	return res;
}
//==========================================================================================================================
void HSLToRGB(float h,float s,float l,float *r,float *g,float *b)
{//==========================================================================================================================


	if (s == 0.0)
	{
		*r=l;
		*g=l;
		*b=l;
	}
	else
	{
		float f2;

		if (l < 0.5)
			f2 = l * (1.0 + s);
		else
			f2 = (l + s) - (s * l);

		float f1 = 2.0 * l - f2;

		*r = HueToRGB(f1, f2, h + (1.0/3.0));
		*g = HueToRGB(f1, f2, h);
		*b= HueToRGB(f1, f2, h - (1.0/3.0));
	}

}

//float adjust_gamma = 1.0f;
//float adjust_brightness = 1.0f;
//float adjust_lightness = 1.0f;

//==========================================================================================================================
void adjust_color(int *pr, int *pg, int *pb)
{//==========================================================================================================================

	int r,g,b;
	r=*pr;
	g=*pg;
	b=*pb;

	//if its not black
	if(r!=b||r!=g||(r==b&&r==g&&r>16))
	{


		float fr,fg,fb,fh,fs,fl;
		fr=(float)((float)r/256.0f);
		fg=(float)((float)g/256.0f);
		fb=(float)((float)b/256.0f);


		//gamma
		//fr = pow(fr,0.8f);
		//fg = pow(fg,0.8f);
		//fb = pow(fb,0.8f);

		//increase blue hue unless color is gray
		if(r!=b||r!=g)
		fb = fb+(5.0f/256.0f);

		//increase lightness
		RGBToHSL(fr,fg,fb,&fh,&fs,&fl);
		fl+=(10.0f/256.0f);
		fs+=(5.0f/256.0f);
		if(fl>1.0f)fl=1.0f;
		if(fs>1.0f)fs=1.0f;
		HSLToRGB(fh,fs,fl,&fr,&fg,&fb);

		//brighten
		//fr*=1.1f;
		//fg*=1.1f;
		//fb*=1.1f;


		r=(int)(fr*256.0f);
		g=(int)(fg*256.0f);
		b=(int)(fb*256.0f);

		if(r>255)r=255;
		if(g>255)g=255;
		if(b>255)b=255;
	}

	*pr=r;
	*pb=b;
	*pg=g;

/*
	vec3 hslcolor = RGBToHSL(color);
	//hslcolor.x+=(3.0f/255.0f);
	hslcolor.z+=(5.0f/255.0f);
	color = HSLToRGB(hslcolor);


	color = ContrastSaturationBrightness(color,1.0,1.0,1.1);

	*/


}




		//==========================================================================================================================
		void HARDWARE_create_brightened_palette(int *pal, int *newpal, int bright)//HARDWARE_CreatePalBright
		{//==========================================================================================================================

            int x=0;
            for(x=0;x<256;x++)
            {




//bgr->rgb->hsl->lighten->rgb->bgr
/*

                int bgr=pal[x];

                //bgr to r g b

                int r=((((bgr%32))*8));
                int g=((((bgr/32)%32))*8);
                int b=(((bgr/1024))*8);


                //r g b to h s l

                	float hue, saturation, brightness;

                    int cmax = (r > g) ? r : g;
                    if (b > cmax) cmax = b;
                    int cmin = (r < g) ? r : g;
                    if (b < cmin) cmin = b;

                    brightness = ((float) cmax) / 255.0f;
                    if (cmax != 0)
                        saturation = ((float) (cmax - cmin)) / ((float) cmax);
                    else
                        saturation = 0;
                    if (saturation == 0)
                        hue = 0;
                    else {
                        float redc = ((float) (cmax - r)) / ((float) (cmax - cmin));
                        float greenc = ((float) (cmax - g)) / ((float) (cmax - cmin));
                        float bluec = ((float) (cmax - b)) / ((float) (cmax - cmin));
                        if (r == cmax)
                        hue = bluec - greenc;
                        else if (g == cmax)
                            hue = 2.0f + redc - bluec;
                            else
                        hue = 4.0f + greenc - redc;
                        hue = hue / 6.0f;
                        if (hue < 0)
                        hue = hue + 1.0f;
                    }


                //h s l lighten

                    brightness=brightness*((((float)bright)+31.0f)/31.0f);
                    if(brightness<0.0f)brightness=0.0f;
                    //if(brightness>1.0f)brightness=1.0f;

                //h s l to r g b



                            if (saturation == 0)
                            {
                                r = g = b = (int) (brightness * 255.0f + 0.5f);
                            }
                            else
                            {
                                float h = (hue - (float)floor(hue)) * 6.0f;
                                float f = h - (float)floor(h);
                                float p = brightness * (1.0f - saturation);
                                float q = brightness * (1.0f - saturation * f);
                                float t = brightness * (1.0f - (saturation * (1.0f - f)));
                                switch ((int) h)
                                {
                                    case 0:
                                    r = (int) (brightness * 255.0f + 0.5f);
                                    g = (int) (t * 255.0f + 0.5f);
                                    b = (int) (p * 255.0f + 0.5f);
                                    break;
                                    case 1:
                                    r = (int) (q * 255.0f + 0.5f);
                                    g = (int) (brightness * 255.0f + 0.5f);
                                    b = (int) (p * 255.0f + 0.5f);
                                    break;
                                    case 2:
                                    r = (int) (p * 255.0f + 0.5f);
                                    g = (int) (brightness * 255.0f + 0.5f);
                                    b = (int) (t * 255.0f + 0.5f);
                                    break;
                                    case 3:
                                    r = (int) (p * 255.0f + 0.5f);
                                    g = (int) (q * 255.0f + 0.5f);
                                    b = (int) (brightness * 255.0f + 0.5f);
                                    break;
                                    case 4:
                                    r = (int) (t * 255.0f + 0.5f);
                                    g = (int) (p * 255.0f + 0.5f);
                                    b = (int) (brightness * 255.0f + 0.5f);
                                    break;
                                    case 5:
                                    r = (int) (brightness * 255.0f + 0.5f);
                                    g = (int) (p * 255.0f + 0.5f);
                                    b = (int) (q * 255.0f + 0.5f);
                                    break;
                                }
                            }

                //r g b to bgr
                if(r>255)r=255;
                if(g>255)g=255;
                if(b>255)b=255;

                int newbgr =((b/8)*1024)+((g/8)*32)+((r/8));
*/

                //plain old rgb lightening

                int r, g, b;

				r = pal[x]&31; r+= bright; if (r < 0) r = 0; if (r > 31) r = 31;
				g = (pal[x]>>5)&31; g+= bright; if (g < 0) g = 0; if (g > 31) g = 31;
				b = (pal[x]>>10)&31; b+= bright; if (b < 0) b = 0; if (b > 31) b = 31;
				newpal[x] = HARDWARE_RGB(r, g, b);

            }

		}




	//==========================================================================================================================
	void* HARDWARE_load_file(const char* name)
	{//==========================================================================================================================

		char* filepointer=NULL;
        FILE* file;
        int size;

        char fullname[1024];

        //strcpy(fullname,"data");
        //strcat(fullname,name);
        sprintf(fullname,"data%s",name);

        file = fopen(fullname, "rb");

        if(file!=NULL)
		{
            //get file size using stat
			fseek(file, 0, SEEK_END);
			size = ftell(file);
			rewind(file);

			//fprintf(stdout,"loaded file: %s size: %d\n",fullname,size);

            filepointer = (char*)malloc(size * sizeof(char));

			if(filepointer==NULL){ERROR_set_error(name);ERROR_set_error(" malloc failed\n");}

            fread(filepointer, 1, size, file);
        }
        if(file==NULL){ERROR_set_error(name);ERROR_set_error(" was not found\n");}

		fclose(file);
		//HARDWARE_wait_for_vbl();


		return (void*)filepointer;
	}

	//==========================================================================================================================
	void HARDWARE_unload_file(void** data_pointer)
	{//==========================================================================================================================

		if(*data_pointer!=NULL)
		{
			free(*data_pointer);

			*data_pointer=NULL;
		}
	}

	//==========================================================================================================================
	int HARDWARE_get_file_size(const char* name)//HARDWARE_FSFile[HARDWARE_FSGetFile(0,name,"")].Length;
	{//==========================================================================================================================

		//char* filepointer=NULL;
        FILE* file;
        int size=0;

        char fullname[1024];

        strcpy(fullname,"data");
        strcat(fullname,name);

        file = fopen(fullname, "rb");
        if(file != NULL)
		{
            // get file size using stat
			fseek(file, 0, SEEK_END);
			size = ftell(file);
			rewind(file);
        }
        if(file==NULL){ERROR_set_error(name);ERROR_set_error(" was not found\n");}

		fclose(file);

		return size;
	}

