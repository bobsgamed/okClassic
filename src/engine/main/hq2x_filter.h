//==============================================================================
//Copyright 2003-2009 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



inline void Interp1(unsigned char * pc, int c1, int c2)
{
  *((int*)pc) = (c1*3+c2) >> 2;
}

inline void Interp2(unsigned char * pc, int c1, int c2, int c3)
{
  *((int*)pc) = (c1*2+c2+c3) >> 2;
}

inline void Interp5(unsigned char * pc, int c1, int c2)
{
  *((int*)pc) = (c1+c2) >> 1;
}

inline void Interp6(unsigned char * pc, int c1, int c2, int c3)
{
//*((int*)pc) = (c1*5+c2*2+c3)/8;

  *((int*)pc) = ((((c1 & 0x00FF00)*5 + (c2 & 0x00FF00)*2 + (c3 & 0x00FF00) ) & 0x0007F800) +
				 (((c1 & 0xFF00FF)*5 + (c2 & 0xFF00FF)*2 + (c3 & 0xFF00FF) ) & 0x07F807F8)) >> 3;
}

inline void Interp7(unsigned char * pc, int c1, int c2, int c3)
{
//*((int*)pc) = (c1*6+c2+c3)/8;

  *((int*)pc) = ((((c1 & 0x00FF00)*6 + (c2 & 0x00FF00) + (c3 & 0x00FF00) ) & 0x0007F800) +
				 (((c1 & 0xFF00FF)*6 + (c2 & 0xFF00FF) + (c3 & 0xFF00FF) ) & 0x07F807F8)) >> 3;
}

inline void Interp9(unsigned char * pc, int c1, int c2, int c3)
{
//*((int*)pc) = (c1*2+(c2+c3)*3)/8;

  *((int*)pc) = ((((c1 & 0x00FF00)*2 + ((c2 & 0x00FF00) + (c3 & 0x00FF00))*3 ) & 0x0007F800) +
				 (((c1 & 0xFF00FF)*2 + ((c2 & 0xFF00FF) + (c3 & 0xFF00FF))*3 ) & 0x07F807F8)) >> 3;
}

inline void Interp10(unsigned char * pc, int c1, int c2, int c3)
{
//*((int*)pc) = (c1*14+c2+c3)/16;

  *((int*)pc) = ((((c1 & 0x00FF00)*14 + (c2 & 0x00FF00) + (c3 & 0x00FF00) ) & 0x000FF000) +
				 (((c1 & 0xFF00FF)*14 + (c2 & 0xFF00FF) + (c3 & 0xFF00FF) ) & 0x0FF00FF0)) >> 4;
}




int   LUT16to32[65536];
int   RGBtoYUV[65536];
int   YUV1, YUV2;
const  int   Ymask = 0x00FF0000;
const  int   Umask = 0x0000FF00;
const  int   Vmask = 0x000000FF;
const  int   trY   = 0x00300000;
const  int   trU   = 0x00000700;
const  int   trV   = 0x00000006;

inline bool Diff(unsigned int w1, unsigned int w2)
{
YUV1 = RGBtoYUV[w1];
YUV2 = RGBtoYUV[w2];
return ( ( abs((YUV1 & Ymask) - (YUV2 & Ymask)) > trY ) ||
		   ( abs((YUV1 & Umask) - (YUV2 & Umask)) > trU ) ||
		   ( abs((YUV1 & Vmask) - (YUV2 & Vmask)) > trV ) );
}




void scale_filter(int m_Xres, int m_Yres, int* rgba_data, int* scaled_rgba_data)
{

//	unsigned short m_BitPerPixel = 32;

// unsigned char  * m_pBitmap;
	//_BGR             m_Pal[256];

//  int              m_NumPixel;
//  FILE             * f;
//  int              m_nCount;
// char             m_cBuf[32768];


// m_NumPixel = m_Xres*m_Yres;
// int size = m_NumPixel*((m_BitPerPixel+7)/8);
// m_pBitmap=(unsigned char *)malloc(size);


//need to convert bgra bitmap data to 16 bit. outputs 32 bit for some reason.


//int CImage::ConvertTo16( void )



	unsigned char * new_16bit_bitmap_data = (unsigned char *)malloc(m_Xres*m_Yres*2);

	if ( new_16bit_bitmap_data != null )
	{

		unsigned short * m16bp = (unsigned short*) new_16bit_bitmap_data;

		unsigned char r, g, b;

		int i=0;
		for ( i=0; i<m_Xres*m_Yres*4; i+=4 )
		{

			r = rgba_data[i+2]>>3;
			g = rgba_data[i+1]>>2;
			b = rgba_data[i+0]>>3;

			//scaled_rgba_data[(i*2)+3] = rgba_data[i+3];

			*(m16bp++) = (r << 11) + (g << 5) + b;

		}

	}









//InitLUTs();

//void InitLUTs(void)

{

int i, j, k, r, g, b, Y, u, v;

for (i=0; i<65536; i++)
	LUT16to32[i] = ((i & 0xF800) << 8) + ((i & 0x07E0) << 5) + ((i & 0x001F) << 3);

for (i=0; i<32; i++)
for (j=0; j<64; j++)
for (k=0; k<32; k++)
{
	r = i << 3;
	g = j << 2;
	b = k << 3;
	Y = (r + g + b) >> 2;
	u = 128 + ((r - b) >> 2);
	v = 128 + ((-r + 2*g -b)>>3);
	RGBtoYUV[ (i << 11) + (j << 5) + k ] = (Y<<16) + (u<<8) + v;
}

}



unsigned char * pIn = (unsigned char*)new_16bit_bitmap_data;

unsigned char * pOut = scaled_rgba_data;

int Xres = m_Xres;

int Yres = m_Yres;

int BpL = m_Xres*4*2;

{
int  i, j, k;
int  prevline, nextline;
int  w[10];
int  c[10];

//   +----+----+----+
//   |    |    |    |
//   | w1 | w2 | w3 |
//   +----+----+----+
//   |    |    |    |
//   | w4 | w5 | w6 |
//   +----+----+----+
//   |    |    |    |
//   | w7 | w8 | w9 |
//   +----+----+----+

for (j=0; j<Yres; j++)
{
	if (j>0)      prevline = -Xres*2; else prevline = 0;
	if (j<Yres-1) nextline =  Xres*2; else nextline = 0;

	for (i=0; i<Xres; i++)
	{
	  w[2] = *((unsigned short*)(pIn + prevline));
	  w[5] = *((unsigned short*)pIn);
	  w[8] = *((unsigned short*)(pIn + nextline));

	  if (i>0)
	  {
		w[1] = *((unsigned short*)(pIn + prevline - 2));
		w[4] = *((unsigned short*)(pIn - 2));
		w[7] = *((unsigned short*)(pIn + nextline - 2));
	  }
	  else
	  {
		w[1] = w[2];
		w[4] = w[5];
		w[7] = w[8];
	  }

	  if (i<Xres-1)
	  {
		w[3] = *((unsigned short*)(pIn + prevline + 2));
		w[6] = *((unsigned short*)(pIn + 2));
		w[9] = *((unsigned short*)(pIn + nextline + 2));
	  }
	  else
	  {
		w[3] = w[2];
		w[6] = w[5];
		w[9] = w[8];
	  }

	  int pattern = 0;
	  int flag = 1;

	  YUV1 = RGBtoYUV[w[5]];

	  for (k=1; k<=9; k++)
	  {
		if (k==5) continue;

		if ( w[k] != w[5] )
		{
		  YUV2 = RGBtoYUV[w[k]];
		  if ( ( abs((YUV1 & Ymask) - (YUV2 & Ymask)) > trY ) ||
			   ( abs((YUV1 & Umask) - (YUV2 & Umask)) > trU ) ||
			   ( abs((YUV1 & Vmask) - (YUV2 & Vmask)) > trV ) )
			pattern |= flag;
		}
		flag <<= 1;
	  }

	  for (k=1; k<=9; k++)
		c[k] = LUT16to32[w[k]];

	  switch (pattern)
	  {
		case 0:
		case 1:
		case 4:
		case 32:
		case 128:
		case 5:
		case 132:
		case 160:
		case 33:
		case 129:
		case 36:
		case 133:
		case 164:
		case 161:
		case 37:
		case 165:
		{
		  Interp2(pOut, c[5], c[4], c[2]);
		  Interp2(pOut+4, c[5], c[2], c[6]);
		  Interp2(pOut+BpL, c[5], c[8], c[4]);
		  Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  break;
		}
		case 2:
		case 34:
		case 130:
		case 162:
		{
		  Interp2(pOut, c[5], c[1], c[4]);
		  Interp2(pOut+4, c[5], c[3], c[6]);
		  Interp2(pOut+BpL, c[5], c[8], c[4]);
		  Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  break;
		}
		case 16:
		case 17:
		case 48:
		case 49:
		{
		  Interp2(pOut, c[5], c[4], c[2]);
		  Interp2(pOut+4, c[5], c[3], c[2]);
		  Interp2(pOut+BpL, c[5], c[8], c[4]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[8]);
		  break;
		}
		case 64:
		case 65:
		case 68:
		case 69:
		{
		  Interp2(pOut, c[5], c[4], c[2]);
		  Interp2(pOut+4, c[5], c[2], c[6]);
		  Interp2(pOut+BpL, c[5], c[7], c[4]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[6]);
		  break;
		}
		case 8:
		case 12:
		case 136:
		case 140:
		{
		  Interp2(pOut, c[5], c[1], c[2]);
		  Interp2(pOut+4, c[5], c[2], c[6]);
		  Interp2(pOut+BpL, c[5], c[7], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  break;
		}
		case 3:
		case 35:
		case 131:
		case 163:
		{
		  Interp1(pOut, c[5], c[4]);
		  Interp2(pOut+4, c[5], c[3], c[6]);
		  Interp2(pOut+BpL, c[5], c[8], c[4]);
		  Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  break;
		}
		case 6:
		case 38:
		case 134:
		case 166:
		{
		  Interp2(pOut, c[5], c[1], c[4]);
		  Interp1(pOut+4, c[5], c[6]);
		  Interp2(pOut+BpL, c[5], c[8], c[4]);
		  Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  break;
		}
		case 20:
		case 21:
		case 52:
		case 53:
		{
		  Interp2(pOut, c[5], c[4], c[2]);
		  Interp1(pOut+4, c[5], c[2]);
		  Interp2(pOut+BpL, c[5], c[8], c[4]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[8]);
		  break;
		}
		case 144:
		case 145:
		case 176:
		case 177:
		{
		  Interp2(pOut, c[5], c[4], c[2]);
		  Interp2(pOut+4, c[5], c[3], c[2]);
		  Interp2(pOut+BpL, c[5], c[8], c[4]);
		  Interp1(pOut+BpL+4, c[5], c[8]);
		  break;
		}
		case 192:
		case 193:
		case 196:
		case 197:
		{
		  Interp2(pOut, c[5], c[4], c[2]);
		  Interp2(pOut+4, c[5], c[2], c[6]);
		  Interp2(pOut+BpL, c[5], c[7], c[4]);
		  Interp1(pOut+BpL+4, c[5], c[6]);
		  break;
		}
		case 96:
		case 97:
		case 100:
		case 101:
		{
		  Interp2(pOut, c[5], c[4], c[2]);
		  Interp2(pOut+4, c[5], c[2], c[6]);
		  Interp1(pOut+BpL, c[5], c[4]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[6]);
		  break;
		}
		case 40:
		case 44:
		case 168:
		case 172:
		{
		  Interp2(pOut, c[5], c[1], c[2]);
		  Interp2(pOut+4, c[5], c[2], c[6]);
		  Interp1(pOut+BpL, c[5], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  break;
		}
		case 9:
		case 13:
		case 137:
		case 141:
		{
		  Interp1(pOut, c[5], c[2]);
		  Interp2(pOut+4, c[5], c[2], c[6]);
		  Interp2(pOut+BpL, c[5], c[7], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  break;
		}
		case 18:
		case 50:
		{
		  Interp2(pOut, c[5], c[1], c[4]);
		  if (Diff(w[2], w[6]))
		  {
			Interp1(pOut+4, c[5], c[3]);
		  }
		  else
		  {
			Interp2(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp2(pOut+BpL, c[5], c[8], c[4]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[8]);
		  break;
		}
		case 80:
		case 81:
		{
		  Interp2(pOut, c[5], c[4], c[2]);
		  Interp2(pOut+4, c[5], c[3], c[2]);
		  Interp2(pOut+BpL, c[5], c[7], c[4]);
		  if (Diff(w[6], w[8]))
		  {
			Interp1(pOut+BpL+4, c[5], c[9]);
		  }
		  else
		  {
			Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 72:
		case 76:
		{
		  Interp2(pOut, c[5], c[1], c[2]);
		  Interp2(pOut+4, c[5], c[2], c[6]);
		  if (Diff(w[8], w[4]))
		  {
			Interp1(pOut+BpL, c[5], c[7]);
		  }
		  else
		  {
			Interp2(pOut+BpL, c[5], c[8], c[4]);
		  }
		  Interp2(pOut+BpL+4, c[5], c[9], c[6]);
		  break;
		}
		case 10:
		case 138:
		{
		  if (Diff(w[4], w[2]))
		  {
			Interp1(pOut, c[5], c[1]);
		  }
		  else
		  {
			Interp2(pOut, c[5], c[4], c[2]);
		  }
		  Interp2(pOut+4, c[5], c[3], c[6]);
		  Interp2(pOut+BpL, c[5], c[7], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  break;
		}
		case 66:
		{
		  Interp2(pOut, c[5], c[1], c[4]);
		  Interp2(pOut+4, c[5], c[3], c[6]);
		  Interp2(pOut+BpL, c[5], c[7], c[4]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[6]);
		  break;
		}
		case 24:
		{
		  Interp2(pOut, c[5], c[1], c[2]);
		  Interp2(pOut+4, c[5], c[3], c[2]);
		  Interp2(pOut+BpL, c[5], c[7], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[8]);
		  break;
		}
		case 7:
		case 39:
		case 135:
		{
		  Interp1(pOut, c[5], c[4]);
		  Interp1(pOut+4, c[5], c[6]);
		  Interp2(pOut+BpL, c[5], c[8], c[4]);
		  Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  break;
		}
		case 148:
		case 149:
		case 180:
		{
		  Interp2(pOut, c[5], c[4], c[2]);
		  Interp1(pOut+4, c[5], c[2]);
		  Interp2(pOut+BpL, c[5], c[8], c[4]);
		  Interp1(pOut+BpL+4, c[5], c[8]);
		  break;
		}
		case 224:
		case 228:
		case 225:
		{
		  Interp2(pOut, c[5], c[4], c[2]);
		  Interp2(pOut+4, c[5], c[2], c[6]);
		  Interp1(pOut+BpL, c[5], c[4]);
		  Interp1(pOut+BpL+4, c[5], c[6]);
		  break;
		}
		case 41:
		case 169:
		case 45:
		{
		  Interp1(pOut, c[5], c[2]);
		  Interp2(pOut+4, c[5], c[2], c[6]);
		  Interp1(pOut+BpL, c[5], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  break;
		}
		case 22:
		case 54:
		{
		  Interp2(pOut, c[5], c[1], c[4]);
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp2(pOut+BpL, c[5], c[8], c[4]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[8]);
		  break;
		}
		case 208:
		case 209:
		{
		  Interp2(pOut, c[5], c[4], c[2]);
		  Interp2(pOut+4, c[5], c[3], c[2]);
		  Interp2(pOut+BpL, c[5], c[7], c[4]);
		  if (Diff(w[6], w[8]))
		  {
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 104:
		case 108:
		{
		  Interp2(pOut, c[5], c[1], c[2]);
		  Interp2(pOut+4, c[5], c[2], c[6]);
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL, c[5], c[8], c[4]);
		  }
		  Interp2(pOut+BpL+4, c[5], c[9], c[6]);
		  break;
		}
		case 11:
		case 139:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
		  }
		  else
		  {
			Interp2(pOut, c[5], c[4], c[2]);
		  }
		  Interp2(pOut+4, c[5], c[3], c[6]);
		  Interp2(pOut+BpL, c[5], c[7], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  break;
		}
		case 19:
		case 51:
		{
		  if (Diff(w[2], w[6]))
		  {
			Interp1(pOut, c[5], c[4]);
			Interp1(pOut+4, c[5], c[3]);
		  }
		  else
		  {
			Interp6(pOut, c[5], c[2], c[4]);
			Interp9(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp2(pOut+BpL, c[5], c[8], c[4]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[8]);
		  break;
		}
		case 146:
		case 178:
		{
		  Interp2(pOut, c[5], c[1], c[4]);
		  if (Diff(w[2], w[6]))
		  {
			Interp1(pOut+4, c[5], c[3]);
			Interp1(pOut+BpL+4, c[5], c[8]);
		  }
		  else
		  {
			Interp9(pOut+4, c[5], c[2], c[6]);
			Interp6(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  Interp2(pOut+BpL, c[5], c[8], c[4]);
		  break;
		}
		case 84:
		case 85:
		{
		  Interp2(pOut, c[5], c[4], c[2]);
		  if (Diff(w[6], w[8]))
		  {
			Interp1(pOut+4, c[5], c[2]);
			Interp1(pOut+BpL+4, c[5], c[9]);
		  }
		  else
		  {
			Interp6(pOut+4, c[5], c[6], c[2]);
			Interp9(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  Interp2(pOut+BpL, c[5], c[7], c[4]);
		  break;
		}
		case 112:
		case 113:
		{
		  Interp2(pOut, c[5], c[4], c[2]);
		  Interp2(pOut+4, c[5], c[3], c[2]);
		  if (Diff(w[6], w[8]))
		  {
			Interp1(pOut+BpL, c[5], c[4]);
			Interp1(pOut+BpL+4, c[5], c[9]);
		  }
		  else
		  {
			Interp6(pOut+BpL, c[5], c[8], c[4]);
			Interp9(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 200:
		case 204:
		{
		  Interp2(pOut, c[5], c[1], c[2]);
		  Interp2(pOut+4, c[5], c[2], c[6]);
		  if (Diff(w[8], w[4]))
		  {
			Interp1(pOut+BpL, c[5], c[7]);
			Interp1(pOut+BpL+4, c[5], c[6]);
		  }
		  else
		  {
			Interp9(pOut+BpL, c[5], c[8], c[4]);
			Interp6(pOut+BpL+4, c[5], c[8], c[6]);
		  }
		  break;
		}
		case 73:
		case 77:
		{
		  if (Diff(w[8], w[4]))
		  {
			Interp1(pOut, c[5], c[2]);
			Interp1(pOut+BpL, c[5], c[7]);
		  }
		  else
		  {
			Interp6(pOut, c[5], c[4], c[2]);
			Interp9(pOut+BpL, c[5], c[8], c[4]);
		  }
		  Interp2(pOut+4, c[5], c[2], c[6]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[6]);
		  break;
		}
		case 42:
		case 170:
		{
		  if (Diff(w[4], w[2]))
		  {
			Interp1(pOut, c[5], c[1]);
			Interp1(pOut+BpL, c[5], c[8]);
		  }
		  else
		  {
			Interp9(pOut, c[5], c[4], c[2]);
			Interp6(pOut+BpL, c[5], c[4], c[8]);
		  }
		  Interp2(pOut+4, c[5], c[3], c[6]);
		  Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  break;
		}
		case 14:
		case 142:
		{
		  if (Diff(w[4], w[2]))
		  {
			Interp1(pOut, c[5], c[1]);
			Interp1(pOut+4, c[5], c[6]);
		  }
		  else
		  {
			Interp9(pOut, c[5], c[4], c[2]);
			Interp6(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp2(pOut+BpL, c[5], c[7], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  break;
		}
		case 67:
		{
		  Interp1(pOut, c[5], c[4]);
		  Interp2(pOut+4, c[5], c[3], c[6]);
		  Interp2(pOut+BpL, c[5], c[7], c[4]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[6]);
		  break;
		}
		case 70:
		{
		  Interp2(pOut, c[5], c[1], c[4]);
		  Interp1(pOut+4, c[5], c[6]);
		  Interp2(pOut+BpL, c[5], c[7], c[4]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[6]);
		  break;
		}
		case 28:
		{
		  Interp2(pOut, c[5], c[1], c[2]);
		  Interp1(pOut+4, c[5], c[2]);
		  Interp2(pOut+BpL, c[5], c[7], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[8]);
		  break;
		}
		case 152:
		{
		  Interp2(pOut, c[5], c[1], c[2]);
		  Interp2(pOut+4, c[5], c[3], c[2]);
		  Interp2(pOut+BpL, c[5], c[7], c[8]);
		  Interp1(pOut+BpL+4, c[5], c[8]);
		  break;
		}
		case 194:
		{
		  Interp2(pOut, c[5], c[1], c[4]);
		  Interp2(pOut+4, c[5], c[3], c[6]);
		  Interp2(pOut+BpL, c[5], c[7], c[4]);
		  Interp1(pOut+BpL+4, c[5], c[6]);
		  break;
		}
		case 98:
		{
		  Interp2(pOut, c[5], c[1], c[4]);
		  Interp2(pOut+4, c[5], c[3], c[6]);
		  Interp1(pOut+BpL, c[5], c[4]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[6]);
		  break;
		}
		case 56:
		{
		  Interp2(pOut, c[5], c[1], c[2]);
		  Interp2(pOut+4, c[5], c[3], c[2]);
		  Interp1(pOut+BpL, c[5], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[8]);
		  break;
		}
		case 25:
		{
		  Interp1(pOut, c[5], c[2]);
		  Interp2(pOut+4, c[5], c[3], c[2]);
		  Interp2(pOut+BpL, c[5], c[7], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[8]);
		  break;
		}
		case 26:
		case 31:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
		  }
		  else
		  {
			Interp2(pOut, c[5], c[4], c[2]);
		  }
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp2(pOut+BpL, c[5], c[7], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[8]);
		  break;
		}
		case 82:
		case 214:
		{
		  Interp2(pOut, c[5], c[1], c[4]);
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp2(pOut+BpL, c[5], c[7], c[4]);
		  if (Diff(w[6], w[8]))
		  {
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 88:
		case 248:
		{
		  Interp2(pOut, c[5], c[1], c[2]);
		  Interp2(pOut+4, c[5], c[3], c[2]);
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL, c[5], c[8], c[4]);
		  }
		  if (Diff(w[6], w[8]))
		  {
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 74:
		case 107:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
		  }
		  else
		  {
			Interp2(pOut, c[5], c[4], c[2]);
		  }
		  Interp2(pOut+4, c[5], c[3], c[6]);
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL, c[5], c[8], c[4]);
		  }
		  Interp2(pOut+BpL+4, c[5], c[9], c[6]);
		  break;
		}
		case 27:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
		  }
		  else
		  {
			Interp2(pOut, c[5], c[4], c[2]);
		  }
		  Interp1(pOut+4, c[5], c[3]);
		  Interp2(pOut+BpL, c[5], c[7], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[8]);
		  break;
		}
		case 86:
		{
		  Interp2(pOut, c[5], c[1], c[4]);
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp2(pOut+BpL, c[5], c[7], c[4]);
		  Interp1(pOut+BpL+4, c[5], c[9]);
		  break;
		}
		case 216:
		{
		  Interp2(pOut, c[5], c[1], c[2]);
		  Interp2(pOut+4, c[5], c[3], c[2]);
		  Interp1(pOut+BpL, c[5], c[7]);
		  if (Diff(w[6], w[8]))
		  {
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 106:
		{
		  Interp1(pOut, c[5], c[1]);
		  Interp2(pOut+4, c[5], c[3], c[6]);
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL, c[5], c[8], c[4]);
		  }
		  Interp2(pOut+BpL+4, c[5], c[9], c[6]);
		  break;
		}
		case 30:
		{
		  Interp1(pOut, c[5], c[1]);
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp2(pOut+BpL, c[5], c[7], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[8]);
		  break;
		}
		case 210:
		{
		  Interp2(pOut, c[5], c[1], c[4]);
		  Interp1(pOut+4, c[5], c[3]);
		  Interp2(pOut+BpL, c[5], c[7], c[4]);
		  if (Diff(w[6], w[8]))
		  {
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 120:
		{
		  Interp2(pOut, c[5], c[1], c[2]);
		  Interp2(pOut+4, c[5], c[3], c[2]);
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL, c[5], c[8], c[4]);
		  }
		  Interp1(pOut+BpL+4, c[5], c[9]);
		  break;
		}
		case 75:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
		  }
		  else
		  {
			Interp2(pOut, c[5], c[4], c[2]);
		  }
		  Interp2(pOut+4, c[5], c[3], c[6]);
		  Interp1(pOut+BpL, c[5], c[7]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[6]);
		  break;
		}
		case 29:
		{
		  Interp1(pOut, c[5], c[2]);
		  Interp1(pOut+4, c[5], c[2]);
		  Interp2(pOut+BpL, c[5], c[7], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[8]);
		  break;
		}
		case 198:
		{
		  Interp2(pOut, c[5], c[1], c[4]);
		  Interp1(pOut+4, c[5], c[6]);
		  Interp2(pOut+BpL, c[5], c[7], c[4]);
		  Interp1(pOut+BpL+4, c[5], c[6]);
		  break;
		}
		case 184:
		{
		  Interp2(pOut, c[5], c[1], c[2]);
		  Interp2(pOut+4, c[5], c[3], c[2]);
		  Interp1(pOut+BpL, c[5], c[8]);
		  Interp1(pOut+BpL+4, c[5], c[8]);
		  break;
		}
		case 99:
		{
		  Interp1(pOut, c[5], c[4]);
		  Interp2(pOut+4, c[5], c[3], c[6]);
		  Interp1(pOut+BpL, c[5], c[4]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[6]);
		  break;
		}
		case 57:
		{
		  Interp1(pOut, c[5], c[2]);
		  Interp2(pOut+4, c[5], c[3], c[2]);
		  Interp1(pOut+BpL, c[5], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[8]);
		  break;
		}
		case 71:
		{
		  Interp1(pOut, c[5], c[4]);
		  Interp1(pOut+4, c[5], c[6]);
		  Interp2(pOut+BpL, c[5], c[7], c[4]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[6]);
		  break;
		}
		case 156:
		{
		  Interp2(pOut, c[5], c[1], c[2]);
		  Interp1(pOut+4, c[5], c[2]);
		  Interp2(pOut+BpL, c[5], c[7], c[8]);
		  Interp1(pOut+BpL+4, c[5], c[8]);
		  break;
		}
		case 226:
		{
		  Interp2(pOut, c[5], c[1], c[4]);
		  Interp2(pOut+4, c[5], c[3], c[6]);
		  Interp1(pOut+BpL, c[5], c[4]);
		  Interp1(pOut+BpL+4, c[5], c[6]);
		  break;
		}
		case 60:
		{
		  Interp2(pOut, c[5], c[1], c[2]);
		  Interp1(pOut+4, c[5], c[2]);
		  Interp1(pOut+BpL, c[5], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[8]);
		  break;
		}
		case 195:
		{
		  Interp1(pOut, c[5], c[4]);
		  Interp2(pOut+4, c[5], c[3], c[6]);
		  Interp2(pOut+BpL, c[5], c[7], c[4]);
		  Interp1(pOut+BpL+4, c[5], c[6]);
		  break;
		}
		case 102:
		{
		  Interp2(pOut, c[5], c[1], c[4]);
		  Interp1(pOut+4, c[5], c[6]);
		  Interp1(pOut+BpL, c[5], c[4]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[6]);
		  break;
		}
		case 153:
		{
		  Interp1(pOut, c[5], c[2]);
		  Interp2(pOut+4, c[5], c[3], c[2]);
		  Interp2(pOut+BpL, c[5], c[7], c[8]);
		  Interp1(pOut+BpL+4, c[5], c[8]);
		  break;
		}
		case 58:
		{
		  if (Diff(w[4], w[2]))
		  {
			Interp1(pOut, c[5], c[1]);
		  }
		  else
		  {
			Interp7(pOut, c[5], c[4], c[2]);
		  }
		  if (Diff(w[2], w[6]))
		  {
			Interp1(pOut+4, c[5], c[3]);
		  }
		  else
		  {
			Interp7(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp1(pOut+BpL, c[5], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[8]);
		  break;
		}
		case 83:
		{
		  Interp1(pOut, c[5], c[4]);
		  if (Diff(w[2], w[6]))
		  {
			Interp1(pOut+4, c[5], c[3]);
		  }
		  else
		  {
			Interp7(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp2(pOut+BpL, c[5], c[7], c[4]);
		  if (Diff(w[6], w[8]))
		  {
			Interp1(pOut+BpL+4, c[5], c[9]);
		  }
		  else
		  {
			Interp7(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 92:
		{
		  Interp2(pOut, c[5], c[1], c[2]);
		  Interp1(pOut+4, c[5], c[2]);
		  if (Diff(w[8], w[4]))
		  {
			Interp1(pOut+BpL, c[5], c[7]);
		  }
		  else
		  {
			Interp7(pOut+BpL, c[5], c[8], c[4]);
		  }
		  if (Diff(w[6], w[8]))
		  {
			Interp1(pOut+BpL+4, c[5], c[9]);
		  }
		  else
		  {
			Interp7(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 202:
		{
		  if (Diff(w[4], w[2]))
		  {
			Interp1(pOut, c[5], c[1]);
		  }
		  else
		  {
			Interp7(pOut, c[5], c[4], c[2]);
		  }
		  Interp2(pOut+4, c[5], c[3], c[6]);
		  if (Diff(w[8], w[4]))
		  {
			Interp1(pOut+BpL, c[5], c[7]);
		  }
		  else
		  {
			Interp7(pOut+BpL, c[5], c[8], c[4]);
		  }
		  Interp1(pOut+BpL+4, c[5], c[6]);
		  break;
		}
		case 78:
		{
		  if (Diff(w[4], w[2]))
		  {
			Interp1(pOut, c[5], c[1]);
		  }
		  else
		  {
			Interp7(pOut, c[5], c[4], c[2]);
		  }
		  Interp1(pOut+4, c[5], c[6]);
		  if (Diff(w[8], w[4]))
		  {
			Interp1(pOut+BpL, c[5], c[7]);
		  }
		  else
		  {
			Interp7(pOut+BpL, c[5], c[8], c[4]);
		  }
		  Interp2(pOut+BpL+4, c[5], c[9], c[6]);
		  break;
		}
		case 154:
		{
		  if (Diff(w[4], w[2]))
		  {
			Interp1(pOut, c[5], c[1]);
		  }
		  else
		  {
			Interp7(pOut, c[5], c[4], c[2]);
		  }
		  if (Diff(w[2], w[6]))
		  {
			Interp1(pOut+4, c[5], c[3]);
		  }
		  else
		  {
			Interp7(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp2(pOut+BpL, c[5], c[7], c[8]);
		  Interp1(pOut+BpL+4, c[5], c[8]);
		  break;
		}
		case 114:
		{
		  Interp2(pOut, c[5], c[1], c[4]);
		  if (Diff(w[2], w[6]))
		  {
			Interp1(pOut+4, c[5], c[3]);
		  }
		  else
		  {
			Interp7(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp1(pOut+BpL, c[5], c[4]);
		  if (Diff(w[6], w[8]))
		  {
			Interp1(pOut+BpL+4, c[5], c[9]);
		  }
		  else
		  {
			Interp7(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 89:
		{
		  Interp1(pOut, c[5], c[2]);
		  Interp2(pOut+4, c[5], c[3], c[2]);
		  if (Diff(w[8], w[4]))
		  {
			Interp1(pOut+BpL, c[5], c[7]);
		  }
		  else
		  {
			Interp7(pOut+BpL, c[5], c[8], c[4]);
		  }
		  if (Diff(w[6], w[8]))
		  {
			Interp1(pOut+BpL+4, c[5], c[9]);
		  }
		  else
		  {
			Interp7(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 90:
		{
		  if (Diff(w[4], w[2]))
		  {
			Interp1(pOut, c[5], c[1]);
		  }
		  else
		  {
			Interp7(pOut, c[5], c[4], c[2]);
		  }
		  if (Diff(w[2], w[6]))
		  {
			Interp1(pOut+4, c[5], c[3]);
		  }
		  else
		  {
			Interp7(pOut+4, c[5], c[2], c[6]);
		  }
		  if (Diff(w[8], w[4]))
		  {
			Interp1(pOut+BpL, c[5], c[7]);
		  }
		  else
		  {
			Interp7(pOut+BpL, c[5], c[8], c[4]);
		  }
		  if (Diff(w[6], w[8]))
		  {
			Interp1(pOut+BpL+4, c[5], c[9]);
		  }
		  else
		  {
			Interp7(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 55:
		case 23:
		{
		  if (Diff(w[2], w[6]))
		  {
			Interp1(pOut, c[5], c[4]);
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp6(pOut, c[5], c[2], c[4]);
			Interp9(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp2(pOut+BpL, c[5], c[8], c[4]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[8]);
		  break;
		}
		case 182:
		case 150:
		{
		  Interp2(pOut, c[5], c[1], c[4]);
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
			Interp1(pOut+BpL+4, c[5], c[8]);
		  }
		  else
		  {
			Interp9(pOut+4, c[5], c[2], c[6]);
			Interp6(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  Interp2(pOut+BpL, c[5], c[8], c[4]);
		  break;
		}
		case 213:
		case 212:
		{
		  Interp2(pOut, c[5], c[4], c[2]);
		  if (Diff(w[6], w[8]))
		  {
			Interp1(pOut+4, c[5], c[2]);
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp6(pOut+4, c[5], c[6], c[2]);
			Interp9(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  Interp2(pOut+BpL, c[5], c[7], c[4]);
		  break;
		}
		case 241:
		case 240:
		{
		  Interp2(pOut, c[5], c[4], c[2]);
		  Interp2(pOut+4, c[5], c[3], c[2]);
		  if (Diff(w[6], w[8]))
		  {
			Interp1(pOut+BpL, c[5], c[4]);
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp6(pOut+BpL, c[5], c[8], c[4]);
			Interp9(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 236:
		case 232:
		{
		  Interp2(pOut, c[5], c[1], c[2]);
		  Interp2(pOut+4, c[5], c[2], c[6]);
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
			Interp1(pOut+BpL+4, c[5], c[6]);
		  }
		  else
		  {
			Interp9(pOut+BpL, c[5], c[8], c[4]);
			Interp6(pOut+BpL+4, c[5], c[8], c[6]);
		  }
		  break;
		}
		case 109:
		case 105:
		{
		  if (Diff(w[8], w[4]))
		  {
			Interp1(pOut, c[5], c[2]);
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp6(pOut, c[5], c[4], c[2]);
			Interp9(pOut+BpL, c[5], c[8], c[4]);
		  }
		  Interp2(pOut+4, c[5], c[2], c[6]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[6]);
		  break;
		}
		case 171:
		case 43:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
			Interp1(pOut+BpL, c[5], c[8]);
		  }
		  else
		  {
			Interp9(pOut, c[5], c[4], c[2]);
			Interp6(pOut+BpL, c[5], c[4], c[8]);
		  }
		  Interp2(pOut+4, c[5], c[3], c[6]);
		  Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  break;
		}
		case 143:
		case 15:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
			Interp1(pOut+4, c[5], c[6]);
		  }
		  else
		  {
			Interp9(pOut, c[5], c[4], c[2]);
			Interp6(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp2(pOut+BpL, c[5], c[7], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  break;
		}
		case 124:
		{
		  Interp2(pOut, c[5], c[1], c[2]);
		  Interp1(pOut+4, c[5], c[2]);
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL, c[5], c[8], c[4]);
		  }
		  Interp1(pOut+BpL+4, c[5], c[9]);
		  break;
		}
		case 203:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
		  }
		  else
		  {
			Interp2(pOut, c[5], c[4], c[2]);
		  }
		  Interp2(pOut+4, c[5], c[3], c[6]);
		  Interp1(pOut+BpL, c[5], c[7]);
		  Interp1(pOut+BpL+4, c[5], c[6]);
		  break;
		}
		case 62:
		{
		  Interp1(pOut, c[5], c[1]);
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp1(pOut+BpL, c[5], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[8]);
		  break;
		}
		case 211:
		{
		  Interp1(pOut, c[5], c[4]);
		  Interp1(pOut+4, c[5], c[3]);
		  Interp2(pOut+BpL, c[5], c[7], c[4]);
		  if (Diff(w[6], w[8]))
		  {
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 118:
		{
		  Interp2(pOut, c[5], c[1], c[4]);
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp1(pOut+BpL, c[5], c[4]);
		  Interp1(pOut+BpL+4, c[5], c[9]);
		  break;
		}
		case 217:
		{
		  Interp1(pOut, c[5], c[2]);
		  Interp2(pOut+4, c[5], c[3], c[2]);
		  Interp1(pOut+BpL, c[5], c[7]);
		  if (Diff(w[6], w[8]))
		  {
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 110:
		{
		  Interp1(pOut, c[5], c[1]);
		  Interp1(pOut+4, c[5], c[6]);
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL, c[5], c[8], c[4]);
		  }
		  Interp2(pOut+BpL+4, c[5], c[9], c[6]);
		  break;
		}
		case 155:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
		  }
		  else
		  {
			Interp2(pOut, c[5], c[4], c[2]);
		  }
		  Interp1(pOut+4, c[5], c[3]);
		  Interp2(pOut+BpL, c[5], c[7], c[8]);
		  Interp1(pOut+BpL+4, c[5], c[8]);
		  break;
		}
		case 188:
		{
		  Interp2(pOut, c[5], c[1], c[2]);
		  Interp1(pOut+4, c[5], c[2]);
		  Interp1(pOut+BpL, c[5], c[8]);
		  Interp1(pOut+BpL+4, c[5], c[8]);
		  break;
		}
		case 185:
		{
		  Interp1(pOut, c[5], c[2]);
		  Interp2(pOut+4, c[5], c[3], c[2]);
		  Interp1(pOut+BpL, c[5], c[8]);
		  Interp1(pOut+BpL+4, c[5], c[8]);
		  break;
		}
		case 61:
		{
		  Interp1(pOut, c[5], c[2]);
		  Interp1(pOut+4, c[5], c[2]);
		  Interp1(pOut+BpL, c[5], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[8]);
		  break;
		}
		case 157:
		{
		  Interp1(pOut, c[5], c[2]);
		  Interp1(pOut+4, c[5], c[2]);
		  Interp2(pOut+BpL, c[5], c[7], c[8]);
		  Interp1(pOut+BpL+4, c[5], c[8]);
		  break;
		}
		case 103:
		{
		  Interp1(pOut, c[5], c[4]);
		  Interp1(pOut+4, c[5], c[6]);
		  Interp1(pOut+BpL, c[5], c[4]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[6]);
		  break;
		}
		case 227:
		{
		  Interp1(pOut, c[5], c[4]);
		  Interp2(pOut+4, c[5], c[3], c[6]);
		  Interp1(pOut+BpL, c[5], c[4]);
		  Interp1(pOut+BpL+4, c[5], c[6]);
		  break;
		}
		case 230:
		{
		  Interp2(pOut, c[5], c[1], c[4]);
		  Interp1(pOut+4, c[5], c[6]);
		  Interp1(pOut+BpL, c[5], c[4]);
		  Interp1(pOut+BpL+4, c[5], c[6]);
		  break;
		}
		case 199:
		{
		  Interp1(pOut, c[5], c[4]);
		  Interp1(pOut+4, c[5], c[6]);
		  Interp2(pOut+BpL, c[5], c[7], c[4]);
		  Interp1(pOut+BpL+4, c[5], c[6]);
		  break;
		}
		case 220:
		{
		  Interp2(pOut, c[5], c[1], c[2]);
		  Interp1(pOut+4, c[5], c[2]);
		  if (Diff(w[8], w[4]))
		  {
			Interp1(pOut+BpL, c[5], c[7]);
		  }
		  else
		  {
			Interp7(pOut+BpL, c[5], c[8], c[4]);
		  }
		  if (Diff(w[6], w[8]))
		  {
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 158:
		{
		  if (Diff(w[4], w[2]))
		  {
			Interp1(pOut, c[5], c[1]);
		  }
		  else
		  {
			Interp7(pOut, c[5], c[4], c[2]);
		  }
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp2(pOut+BpL, c[5], c[7], c[8]);
		  Interp1(pOut+BpL+4, c[5], c[8]);
		  break;
		}
		case 234:
		{
		  if (Diff(w[4], w[2]))
		  {
			Interp1(pOut, c[5], c[1]);
		  }
		  else
		  {
			Interp7(pOut, c[5], c[4], c[2]);
		  }
		  Interp2(pOut+4, c[5], c[3], c[6]);
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL, c[5], c[8], c[4]);
		  }
		  Interp1(pOut+BpL+4, c[5], c[6]);
		  break;
		}
		case 242:
		{
		  Interp2(pOut, c[5], c[1], c[4]);
		  if (Diff(w[2], w[6]))
		  {
			Interp1(pOut+4, c[5], c[3]);
		  }
		  else
		  {
			Interp7(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp1(pOut+BpL, c[5], c[4]);
		  if (Diff(w[6], w[8]))
		  {
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 59:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
		  }
		  else
		  {
			Interp2(pOut, c[5], c[4], c[2]);
		  }
		  if (Diff(w[2], w[6]))
		  {
			Interp1(pOut+4, c[5], c[3]);
		  }
		  else
		  {
			Interp7(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp1(pOut+BpL, c[5], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[8]);
		  break;
		}
		case 121:
		{
		  Interp1(pOut, c[5], c[2]);
		  Interp2(pOut+4, c[5], c[3], c[2]);
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL, c[5], c[8], c[4]);
		  }
		  if (Diff(w[6], w[8]))
		  {
			Interp1(pOut+BpL+4, c[5], c[9]);
		  }
		  else
		  {
			Interp7(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 87:
		{
		  Interp1(pOut, c[5], c[4]);
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp2(pOut+BpL, c[5], c[7], c[4]);
		  if (Diff(w[6], w[8]))
		  {
			Interp1(pOut+BpL+4, c[5], c[9]);
		  }
		  else
		  {
			Interp7(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 79:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
		  }
		  else
		  {
			Interp2(pOut, c[5], c[4], c[2]);
		  }
		  Interp1(pOut+4, c[5], c[6]);
		  if (Diff(w[8], w[4]))
		  {
			Interp1(pOut+BpL, c[5], c[7]);
		  }
		  else
		  {
			Interp7(pOut+BpL, c[5], c[8], c[4]);
		  }
		  Interp2(pOut+BpL+4, c[5], c[9], c[6]);
		  break;
		}
		case 122:
		{
		  if (Diff(w[4], w[2]))
		  {
			Interp1(pOut, c[5], c[1]);
		  }
		  else
		  {
			Interp7(pOut, c[5], c[4], c[2]);
		  }
		  if (Diff(w[2], w[6]))
		  {
			Interp1(pOut+4, c[5], c[3]);
		  }
		  else
		  {
			Interp7(pOut+4, c[5], c[2], c[6]);
		  }
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL, c[5], c[8], c[4]);
		  }
		  if (Diff(w[6], w[8]))
		  {
			Interp1(pOut+BpL+4, c[5], c[9]);
		  }
		  else
		  {
			Interp7(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 94:
		{
		  if (Diff(w[4], w[2]))
		  {
			Interp1(pOut, c[5], c[1]);
		  }
		  else
		  {
			Interp7(pOut, c[5], c[4], c[2]);
		  }
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+4, c[5], c[2], c[6]);
		  }
		  if (Diff(w[8], w[4]))
		  {
			Interp1(pOut+BpL, c[5], c[7]);
		  }
		  else
		  {
			Interp7(pOut+BpL, c[5], c[8], c[4]);
		  }
		  if (Diff(w[6], w[8]))
		  {
			Interp1(pOut+BpL+4, c[5], c[9]);
		  }
		  else
		  {
			Interp7(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 218:
		{
		  if (Diff(w[4], w[2]))
		  {
			Interp1(pOut, c[5], c[1]);
		  }
		  else
		  {
			Interp7(pOut, c[5], c[4], c[2]);
		  }
		  if (Diff(w[2], w[6]))
		  {
			Interp1(pOut+4, c[5], c[3]);
		  }
		  else
		  {
			Interp7(pOut+4, c[5], c[2], c[6]);
		  }
		  if (Diff(w[8], w[4]))
		  {
			Interp1(pOut+BpL, c[5], c[7]);
		  }
		  else
		  {
			Interp7(pOut+BpL, c[5], c[8], c[4]);
		  }
		  if (Diff(w[6], w[8]))
		  {
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 91:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
		  }
		  else
		  {
			Interp2(pOut, c[5], c[4], c[2]);
		  }
		  if (Diff(w[2], w[6]))
		  {
			Interp1(pOut+4, c[5], c[3]);
		  }
		  else
		  {
			Interp7(pOut+4, c[5], c[2], c[6]);
		  }
		  if (Diff(w[8], w[4]))
		  {
			Interp1(pOut+BpL, c[5], c[7]);
		  }
		  else
		  {
			Interp7(pOut+BpL, c[5], c[8], c[4]);
		  }
		  if (Diff(w[6], w[8]))
		  {
			Interp1(pOut+BpL+4, c[5], c[9]);
		  }
		  else
		  {
			Interp7(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 229:
		{
		  Interp2(pOut, c[5], c[4], c[2]);
		  Interp2(pOut+4, c[5], c[2], c[6]);
		  Interp1(pOut+BpL, c[5], c[4]);
		  Interp1(pOut+BpL+4, c[5], c[6]);
		  break;
		}
		case 167:
		{
		  Interp1(pOut, c[5], c[4]);
		  Interp1(pOut+4, c[5], c[6]);
		  Interp2(pOut+BpL, c[5], c[8], c[4]);
		  Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  break;
		}
		case 173:
		{
		  Interp1(pOut, c[5], c[2]);
		  Interp2(pOut+4, c[5], c[2], c[6]);
		  Interp1(pOut+BpL, c[5], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  break;
		}
		case 181:
		{
		  Interp2(pOut, c[5], c[4], c[2]);
		  Interp1(pOut+4, c[5], c[2]);
		  Interp2(pOut+BpL, c[5], c[8], c[4]);
		  Interp1(pOut+BpL+4, c[5], c[8]);
		  break;
		}
		case 186:
		{
		  if (Diff(w[4], w[2]))
		  {
			Interp1(pOut, c[5], c[1]);
		  }
		  else
		  {
			Interp7(pOut, c[5], c[4], c[2]);
		  }
		  if (Diff(w[2], w[6]))
		  {
			Interp1(pOut+4, c[5], c[3]);
		  }
		  else
		  {
			Interp7(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp1(pOut+BpL, c[5], c[8]);
		  Interp1(pOut+BpL+4, c[5], c[8]);
		  break;
		}
		case 115:
		{
		  Interp1(pOut, c[5], c[4]);
		  if (Diff(w[2], w[6]))
		  {
			Interp1(pOut+4, c[5], c[3]);
		  }
		  else
		  {
			Interp7(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp1(pOut+BpL, c[5], c[4]);
		  if (Diff(w[6], w[8]))
		  {
			Interp1(pOut+BpL+4, c[5], c[9]);
		  }
		  else
		  {
			Interp7(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 93:
		{
		  Interp1(pOut, c[5], c[2]);
		  Interp1(pOut+4, c[5], c[2]);
		  if (Diff(w[8], w[4]))
		  {
			Interp1(pOut+BpL, c[5], c[7]);
		  }
		  else
		  {
			Interp7(pOut+BpL, c[5], c[8], c[4]);
		  }
		  if (Diff(w[6], w[8]))
		  {
			Interp1(pOut+BpL+4, c[5], c[9]);
		  }
		  else
		  {
			Interp7(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 206:
		{
		  if (Diff(w[4], w[2]))
		  {
			Interp1(pOut, c[5], c[1]);
		  }
		  else
		  {
			Interp7(pOut, c[5], c[4], c[2]);
		  }
		  Interp1(pOut+4, c[5], c[6]);
		  if (Diff(w[8], w[4]))
		  {
			Interp1(pOut+BpL, c[5], c[7]);
		  }
		  else
		  {
			Interp7(pOut+BpL, c[5], c[8], c[4]);
		  }
		  Interp1(pOut+BpL+4, c[5], c[6]);
		  break;
		}
		case 205:
		case 201:
		{
		  Interp1(pOut, c[5], c[2]);
		  Interp2(pOut+4, c[5], c[2], c[6]);
		  if (Diff(w[8], w[4]))
		  {
			Interp1(pOut+BpL, c[5], c[7]);
		  }
		  else
		  {
			Interp7(pOut+BpL, c[5], c[8], c[4]);
		  }
		  Interp1(pOut+BpL+4, c[5], c[6]);
		  break;
		}
		case 174:
		case 46:
		{
		  if (Diff(w[4], w[2]))
		  {
			Interp1(pOut, c[5], c[1]);
		  }
		  else
		  {
			Interp7(pOut, c[5], c[4], c[2]);
		  }
		  Interp1(pOut+4, c[5], c[6]);
		  Interp1(pOut+BpL, c[5], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  break;
		}
		case 179:
		case 147:
		{
		  Interp1(pOut, c[5], c[4]);
		  if (Diff(w[2], w[6]))
		  {
			Interp1(pOut+4, c[5], c[3]);
		  }
		  else
		  {
			Interp7(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp2(pOut+BpL, c[5], c[8], c[4]);
		  Interp1(pOut+BpL+4, c[5], c[8]);
		  break;
		}
		case 117:
		case 116:
		{
		  Interp2(pOut, c[5], c[4], c[2]);
		  Interp1(pOut+4, c[5], c[2]);
		  Interp1(pOut+BpL, c[5], c[4]);
		  if (Diff(w[6], w[8]))
		  {
			Interp1(pOut+BpL+4, c[5], c[9]);
		  }
		  else
		  {
			Interp7(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 189:
		{
		  Interp1(pOut, c[5], c[2]);
		  Interp1(pOut+4, c[5], c[2]);
		  Interp1(pOut+BpL, c[5], c[8]);
		  Interp1(pOut+BpL+4, c[5], c[8]);
		  break;
		}
		case 231:
		{
		  Interp1(pOut, c[5], c[4]);
		  Interp1(pOut+4, c[5], c[6]);
		  Interp1(pOut+BpL, c[5], c[4]);
		  Interp1(pOut+BpL+4, c[5], c[6]);
		  break;
		}
		case 126:
		{
		  Interp1(pOut, c[5], c[1]);
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+4, c[5], c[2], c[6]);
		  }
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL, c[5], c[8], c[4]);
		  }
		  Interp1(pOut+BpL+4, c[5], c[9]);
		  break;
		}
		case 219:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
		  }
		  else
		  {
			Interp2(pOut, c[5], c[4], c[2]);
		  }
		  Interp1(pOut+4, c[5], c[3]);
		  Interp1(pOut+BpL, c[5], c[7]);
		  if (Diff(w[6], w[8]))
		  {
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 125:
		{
		  if (Diff(w[8], w[4]))
		  {
			Interp1(pOut, c[5], c[2]);
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp6(pOut, c[5], c[4], c[2]);
			Interp9(pOut+BpL, c[5], c[8], c[4]);
		  }
		  Interp1(pOut+4, c[5], c[2]);
		  Interp1(pOut+BpL+4, c[5], c[9]);
		  break;
		}
		case 221:
		{
		  Interp1(pOut, c[5], c[2]);
		  if (Diff(w[6], w[8]))
		  {
			Interp1(pOut+4, c[5], c[2]);
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp6(pOut+4, c[5], c[6], c[2]);
			Interp9(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  Interp1(pOut+BpL, c[5], c[7]);
		  break;
		}
		case 207:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
			Interp1(pOut+4, c[5], c[6]);
		  }
		  else
		  {
			Interp9(pOut, c[5], c[4], c[2]);
			Interp6(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp1(pOut+BpL, c[5], c[7]);
		  Interp1(pOut+BpL+4, c[5], c[6]);
		  break;
		}
		case 238:
		{
		  Interp1(pOut, c[5], c[1]);
		  Interp1(pOut+4, c[5], c[6]);
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
			Interp1(pOut+BpL+4, c[5], c[6]);
		  }
		  else
		  {
			Interp9(pOut+BpL, c[5], c[8], c[4]);
			Interp6(pOut+BpL+4, c[5], c[8], c[6]);
		  }
		  break;
		}
		case 190:
		{
		  Interp1(pOut, c[5], c[1]);
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
			Interp1(pOut+BpL+4, c[5], c[8]);
		  }
		  else
		  {
			Interp9(pOut+4, c[5], c[2], c[6]);
			Interp6(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  Interp1(pOut+BpL, c[5], c[8]);
		  break;
		}
		case 187:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
			Interp1(pOut+BpL, c[5], c[8]);
		  }
		  else
		  {
			Interp9(pOut, c[5], c[4], c[2]);
			Interp6(pOut+BpL, c[5], c[4], c[8]);
		  }
		  Interp1(pOut+4, c[5], c[3]);
		  Interp1(pOut+BpL+4, c[5], c[8]);
		  break;
		}
		case 243:
		{
		  Interp1(pOut, c[5], c[4]);
		  Interp1(pOut+4, c[5], c[3]);
		  if (Diff(w[6], w[8]))
		  {
			Interp1(pOut+BpL, c[5], c[4]);
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp6(pOut+BpL, c[5], c[8], c[4]);
			Interp9(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 119:
		{
		  if (Diff(w[2], w[6]))
		  {
			Interp1(pOut, c[5], c[4]);
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp6(pOut, c[5], c[2], c[4]);
			Interp9(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp1(pOut+BpL, c[5], c[4]);
		  Interp1(pOut+BpL+4, c[5], c[9]);
		  break;
		}
		case 237:
		case 233:
		{
		  Interp1(pOut, c[5], c[2]);
		  Interp2(pOut+4, c[5], c[2], c[6]);
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp10(pOut+BpL, c[5], c[8], c[4]);
		  }
		  Interp1(pOut+BpL+4, c[5], c[6]);
		  break;
		}
		case 175:
		case 47:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
		  }
		  else
		  {
			Interp10(pOut, c[5], c[4], c[2]);
		  }
		  Interp1(pOut+4, c[5], c[6]);
		  Interp1(pOut+BpL, c[5], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  break;
		}
		case 183:
		case 151:
		{
		  Interp1(pOut, c[5], c[4]);
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp10(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp2(pOut+BpL, c[5], c[8], c[4]);
		  Interp1(pOut+BpL+4, c[5], c[8]);
		  break;
		}
		case 245:
		case 244:
		{
		  Interp2(pOut, c[5], c[4], c[2]);
		  Interp1(pOut+4, c[5], c[2]);
		  Interp1(pOut+BpL, c[5], c[4]);
		  if (Diff(w[6], w[8]))
		  {
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp10(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 250:
		{
		  Interp1(pOut, c[5], c[1]);
		  Interp1(pOut+4, c[5], c[3]);
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL, c[5], c[8], c[4]);
		  }
		  if (Diff(w[6], w[8]))
		  {
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 123:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
		  }
		  else
		  {
			Interp2(pOut, c[5], c[4], c[2]);
		  }
		  Interp1(pOut+4, c[5], c[3]);
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL, c[5], c[8], c[4]);
		  }
		  Interp1(pOut+BpL+4, c[5], c[9]);
		  break;
		}
		case 95:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
		  }
		  else
		  {
			Interp2(pOut, c[5], c[4], c[2]);
		  }
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp1(pOut+BpL, c[5], c[7]);
		  Interp1(pOut+BpL+4, c[5], c[9]);
		  break;
		}
		case 222:
		{
		  Interp1(pOut, c[5], c[1]);
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp1(pOut+BpL, c[5], c[7]);
		  if (Diff(w[6], w[8]))
		  {
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 252:
		{
		  Interp2(pOut, c[5], c[1], c[2]);
		  Interp1(pOut+4, c[5], c[2]);
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL, c[5], c[8], c[4]);
		  }
		  if (Diff(w[6], w[8]))
		  {
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp10(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 249:
		{
		  Interp1(pOut, c[5], c[2]);
		  Interp2(pOut+4, c[5], c[3], c[2]);
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp10(pOut+BpL, c[5], c[8], c[4]);
		  }
		  if (Diff(w[6], w[8]))
		  {
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 235:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
		  }
		  else
		  {
			Interp2(pOut, c[5], c[4], c[2]);
		  }
		  Interp2(pOut+4, c[5], c[3], c[6]);
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp10(pOut+BpL, c[5], c[8], c[4]);
		  }
		  Interp1(pOut+BpL+4, c[5], c[6]);
		  break;
		}
		case 111:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
		  }
		  else
		  {
			Interp10(pOut, c[5], c[4], c[2]);
		  }
		  Interp1(pOut+4, c[5], c[6]);
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL, c[5], c[8], c[4]);
		  }
		  Interp2(pOut+BpL+4, c[5], c[9], c[6]);
		  break;
		}
		case 63:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
		  }
		  else
		  {
			Interp10(pOut, c[5], c[4], c[2]);
		  }
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp1(pOut+BpL, c[5], c[8]);
		  Interp2(pOut+BpL+4, c[5], c[9], c[8]);
		  break;
		}
		case 159:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
		  }
		  else
		  {
			Interp2(pOut, c[5], c[4], c[2]);
		  }
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp10(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp2(pOut+BpL, c[5], c[7], c[8]);
		  Interp1(pOut+BpL+4, c[5], c[8]);
		  break;
		}
		case 215:
		{
		  Interp1(pOut, c[5], c[4]);
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp10(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp2(pOut+BpL, c[5], c[7], c[4]);
		  if (Diff(w[6], w[8]))
		  {
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 246:
		{
		  Interp2(pOut, c[5], c[1], c[4]);
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp1(pOut+BpL, c[5], c[4]);
		  if (Diff(w[6], w[8]))
		  {
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp10(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 254:
		{
		  Interp1(pOut, c[5], c[1]);
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+4, c[5], c[2], c[6]);
		  }
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL, c[5], c[8], c[4]);
		  }
		  if (Diff(w[6], w[8]))
		  {
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp10(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 253:
		{
		  Interp1(pOut, c[5], c[2]);
		  Interp1(pOut+4, c[5], c[2]);
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp10(pOut+BpL, c[5], c[8], c[4]);
		  }
		  if (Diff(w[6], w[8]))
		  {
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp10(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 251:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
		  }
		  else
		  {
			Interp2(pOut, c[5], c[4], c[2]);
		  }
		  Interp1(pOut+4, c[5], c[3]);
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp10(pOut+BpL, c[5], c[8], c[4]);
		  }
		  if (Diff(w[6], w[8]))
		  {
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 239:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
		  }
		  else
		  {
			Interp10(pOut, c[5], c[4], c[2]);
		  }
		  Interp1(pOut+4, c[5], c[6]);
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp10(pOut+BpL, c[5], c[8], c[4]);
		  }
		  Interp1(pOut+BpL+4, c[5], c[6]);
		  break;
		}
		case 127:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
		  }
		  else
		  {
			Interp10(pOut, c[5], c[4], c[2]);
		  }
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+4, c[5], c[2], c[6]);
		  }
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL, c[5], c[8], c[4]);
		  }
		  Interp1(pOut+BpL+4, c[5], c[9]);
		  break;
		}
		case 191:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
		  }
		  else
		  {
			Interp10(pOut, c[5], c[4], c[2]);
		  }
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp10(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp1(pOut+BpL, c[5], c[8]);
		  Interp1(pOut+BpL+4, c[5], c[8]);
		  break;
		}
		case 223:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
		  }
		  else
		  {
			Interp2(pOut, c[5], c[4], c[2]);
		  }
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp10(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp1(pOut+BpL, c[5], c[7]);
		  if (Diff(w[6], w[8]))
		  {
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp2(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 247:
		{
		  Interp1(pOut, c[5], c[4]);
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp10(pOut+4, c[5], c[2], c[6]);
		  }
		  Interp1(pOut+BpL, c[5], c[4]);
		  if (Diff(w[6], w[8]))
		  {
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp10(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
		case 255:
		{
		  if (Diff(w[4], w[2]))
		  {
			*((int*)(pOut)) = c[5];
		  }
		  else
		  {
			Interp10(pOut, c[5], c[4], c[2]);
		  }
		  if (Diff(w[2], w[6]))
		  {
			*((int*)(pOut+4)) = c[5];
		  }
		  else
		  {
			Interp10(pOut+4, c[5], c[2], c[6]);
		  }
		  if (Diff(w[8], w[4]))
		  {
			*((int*)(pOut+BpL)) = c[5];
		  }
		  else
		  {
			Interp10(pOut+BpL, c[5], c[8], c[4]);
		  }
		  if (Diff(w[6], w[8]))
		  {
			*((int*)(pOut+BpL+4)) = c[5];
		  }
		  else
		  {
			Interp10(pOut+BpL+4, c[5], c[6], c[8]);
		  }
		  break;
		}
	  }
	  pIn+=2;
	  pOut+=8;
	}
	pOut+=BpL;
}
}



int x=0;
int y=0;

for(y=0; y<m_Yres; y++)
	for(x=0; x<m_Xres; x++)
	{
		scaled_rgba_data[(((y*2*m_Xres*2)+x*2)*4)+3] = rgba_data[(((y*m_Xres)+x)*4)+3];
		scaled_rgba_data[(((y*2*m_Xres*2)+x*2+1)*4)+3] = rgba_data[(((y*m_Xres)+x)*4)+3];
		scaled_rgba_data[((((y*2+1)*m_Xres*2)+x*2)*4)+3] = rgba_data[(((y*m_Xres)+x)*4)+3];
		scaled_rgba_data[((((y*2+1)*m_Xres*2)+x*2+1)*4)+3] = rgba_data[(((y*m_Xres)+x)*4)+3];
	}



free(new_16bit_bitmap_data);



}



