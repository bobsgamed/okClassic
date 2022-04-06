




#include "../../main.h"
//#include "tilemaps.h"



bool AUX_bg_is_on[4]={0};
bool bg_is_on[4]={0};


GLuint GLTex_bg[4] = {0};
int bg_texture_size_x[4] = {0};
int bg_texture_size_y[4] = {0};



GLuint GLTex_AUX_bg[4] = {0};
int AUX_bg_texture_size_x[4] = {0};
int AUX_bg_texture_size_y[4] = {0};
int AUX_bg_x[4] = {0};
int AUX_bg_y[4] = {0};
float AUX_bg_zoom[4] = {0};


GLuint GLTex_map_metatile[4*METATILES_POSSIBLE] = {0};//6 onscreen max
		//so metatile size has to be bigger than 640/2. lets say 512x512

int metatile_x[4*METATILES_POSSIBLE]={0};
int metatile_y[4*METATILES_POSSIBLE]={0};
bool metatile_used[4*METATILES_POSSIBLE]={0};

bool metatile_map=1;

unsigned short GAME_temp_TILESET_PALETTE[256]= {0};

unsigned short temp_palette[256]= {0}; //used for modified palettes
unsigned short clear_palette[256]= {0}; //always filled with 0



unsigned short HARDWARE_MAP_PALETTE_ENHANCED_RGB[256*3] = {0};





//==========================================================================================================================
void delete_bg_metatiles(int bg)
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
void create_needed_metatiles(int bg)
{//==========================================================================================================================

	if(metatile_map==1)
	{
		if(HARDWARE_map_tileset!=NULL&&HARDWARE_map_palette!=NULL)
		{
			//check for each metatile coordinate that should be onscreen.
			//if it's there, draw it. if it isn't, make it, and draw it.



			int s=0;

			int x=0;
			int y=0;

			int xstart = (MAP_cam_x-(METATILE_SIZE/2))-((MAP_cam_x-(METATILE_SIZE/2))%METATILE_SIZE);
			int ystart = (MAP_cam_y-(METATILE_SIZE/2))-((MAP_cam_y-(METATILE_SIZE/2))%METATILE_SIZE);

			//if(xstart<0)xstart=0;
			//if(ystart<0)ystart=0;

			int xend = (MAP_cam_x+(METATILE_SIZE/2))+GAME_VIEWPORT_WIDTH_PIXELS;
			int yend = (MAP_cam_y+(METATILE_SIZE/2))+GAME_VIEWPORT_HEIGHT_PIXELS;

			//starting at first possible grid position off left of screen (metatiles will always be drawn at even intervals metatile_size * n)
			for(y=ystart;y<yend;y+=METATILE_SIZE)
				for(x=xstart;x<xend;x+=METATILE_SIZE)
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
						//fprintf(stdout,"creating metatile x:%d y:%d bg:%d\n",x/8,y/8,bg);

						if(bg==3)HARDWARE_load_metatile(3, HARDWARE_map_width_tiles*8, HARDWARE_map_height_tiles*8, x , y, HARDWARE_map_3_filename);
						if(bg==0)HARDWARE_load_metatile(0, HARDWARE_map_width_tiles*8, HARDWARE_map_height_tiles*8, x , y, HARDWARE_map_0_filename);
						if(bg==2)HARDWARE_load_metatile(2, HARDWARE_map_width_tiles*8, HARDWARE_map_height_tiles*8, x , y, HARDWARE_map_2_filename);
						if(bg==1)HARDWARE_load_metatile(1, HARDWARE_map_width_tiles*8, HARDWARE_map_height_tiles*8, x , y, HARDWARE_map_1_filename);
						//gl_draw(GLTex_map_metatile[((3*METATILES_POSSIBLE)+s)], metatile_x[3*METATILES_POSSIBLE+s]-MAP_cam_x, metatile_y[3*METATILES_POSSIBLE+s]-MAP_cam_y,METATILE_SIZE,METATILE_SIZE);
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
							metatile_x[bg*METATILES_POSSIBLE+s]>MAP_cam_x+(METATILE_SIZE/2)+GAME_VIEWPORT_WIDTH_PIXELS|| //off the right side
							metatile_x[bg*METATILES_POSSIBLE+s]<MAP_cam_x-(METATILE_SIZE/2)-METATILE_SIZE|| //off the left side

							metatile_y[bg*METATILES_POSSIBLE+s]>MAP_cam_y+(METATILE_SIZE/2)+GAME_VIEWPORT_HEIGHT_PIXELS|| //off the bottom
							metatile_y[bg*METATILES_POSSIBLE+s]<MAP_cam_y-(METATILE_SIZE/2)-METATILE_SIZE //off the top
						)
						{

							//fprintf(stdout,"deleting metatile x:%d y:%d bg:%d\n",metatile_x[bg*METATILES_POSSIBLE+s]/8,metatile_y[bg*METATILES_POSSIBLE+s]/8,bg);

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



//==========================================================================================================================
void HARDWARE_delete_AUX_bg( int bg_layer)//HARDWARE_DeleteBg
{//==========================================================================================================================

	if(AUX_bg_is_on[bg_layer]&&glIsTexture(GLTex_AUX_bg[bg_layer]))
	{
		glDeleteTextures(1, &GLTex_AUX_bg[bg_layer]);
		//GLTex_AUX_bg[bg_layer]=0;
	}
	AUX_bg_is_on[bg_layer]=0;
}



//==========================================================================================================================
void HARDWARE_delete_all_bg_data()//HARDWARE_ResetBgSys
{//==========================================================================================================================


	if(metatile_map)
	{
		delete_all_metatiles();
	}
	else
	{
		int x=0;
		for(x=0;x>4;x++)
		{
			if(bg_is_on[x]&&glIsTexture(GLTex_bg[x]))
			{
				glDeleteTextures(1, &GLTex_bg[x]);

			}
		}
	}


	///unload layer file
	HARDWARE_unload_file((void**)&HARDWARE_map_0);
	HARDWARE_unload_file((void**)&HARDWARE_map_1);
	HARDWARE_unload_file((void**)&HARDWARE_map_2);
	HARDWARE_unload_file((void**)&HARDWARE_map_3);

	HARDWARE_unload_file((void**)&HARDWARE_map_hit_layer);
	HARDWARE_unload_file((void**)&HARDWARE_map_fx_layer);

	HARDWARE_unload_file((void**)&HARDWARE_map_palette);

	HARDWARE_unload_file((void**)&HARDWARE_map_tileset);



}

//==========================================================================================================================
void HARDWARE_reload_bg_textures()
{//==========================================================================================================================

	if(metatile_map==0)
	{
		if(HARDWARE_map_0!=NULL)HARDWARE_load_map(0,HARDWARE_map_0,HARDWARE_map_width,HARDWARE_map_height);
		if(HARDWARE_map_1!=NULL)HARDWARE_load_map(1,HARDWARE_map_1,HARDWARE_map_width,HARDWARE_map_height);
		if(HARDWARE_map_2!=NULL)HARDWARE_load_map(2,HARDWARE_map_2,HARDWARE_map_width,HARDWARE_map_height);
		if(HARDWARE_map_3!=NULL)HARDWARE_load_map(3,HARDWARE_map_3,HARDWARE_map_width,HARDWARE_map_height);
	}
	else
	{
		//delete all metatiles so they get redrawn
		delete_all_metatiles();

		int c=0;
		for(c=0;c<4;c++)
		create_needed_metatiles(c);
	}

}


//==========================================================================================================================
void HARDWARE_load_bg_palette(int* palette)//HARDWARE_LoadBgPal
{//==========================================================================================================================


		int x=0;
		for(x=0;x<256;x++)
		{
			int r=(palette[x]%32)*8;
			int g=((palette[x]/32)%32)*8;
			int b=(((palette[x]/32)/32)%32)*8;

			adjust_color(&r,&g,&b);

			HARDWARE_MAP_PALETTE_ENHANCED_RGB[3*x+0]=r;
			HARDWARE_MAP_PALETTE_ENHANCED_RGB[3*x+1]=g;
			HARDWARE_MAP_PALETTE_ENHANCED_RGB[3*x+2]=b;
		}

}



//==========================================================================================================================
void HARDWARE_set_bg_palette_color(int color_number, int color)
{//==========================================================================================================================

	///this shouldnt alter the HARDWARE_map_palette
	HARDWARE_map_palette[color_number]=color;
	HARDWARE_load_bg_palette(HARDWARE_map_palette);
}


//==========================================================================================================================
void HARDWARE_set_AUX_map_xy(int bg_layer, int x, int y)
{//==========================================================================================================================
		AUX_bg_x[bg_layer]=x;
		AUX_bg_y[bg_layer]=y;
}

//==========================================================================================================================
void HARDWARE_load_AUX_map_to_xy_xy(int bg_layer, unsigned short* MAP_data, unsigned char* tileset_data, unsigned short* palette_data,int pwidth,int pheight,int from_x,int from_y, float zoom, int transparent)
{//==========================================================================================================================

		unsigned short* MAP_layer_data = (unsigned short*)MAP_data;


		int twidth = power_of_two(pwidth);
		int theight = power_of_two(pheight);

		//calc texture size
		AUX_bg_texture_size_x[bg_layer] = twidth;
		AUX_bg_texture_size_y[bg_layer] = theight;


		AUX_bg_x[bg_layer]=from_x;
		AUX_bg_y[bg_layer]=from_y;
		AUX_bg_zoom[bg_layer]=zoom;


		unsigned char* MAP_rgba_data = (unsigned char*)calloc(twidth * theight * 4, sizeof(unsigned char));


		int x=0;
		int y=0;
		int z=0;

		for(y=0;y<theight;y++)
		{
			for(x=0;x<twidth;x++)
			{


				int tile_index = 0;

				if(x<pwidth&&y<pheight)
				tile_index = 64 * (MAP_layer_data[(x/8)+((pwidth/8)*(y/8))]);


				int pixel_in_tile_index = 0;

				if(x<pwidth&&y<pheight)
				pixel_in_tile_index = (x%8) + ((y%8) * 8);


				z = x + (y*twidth);


				if(x>=pwidth||y>=pheight)
				{
					MAP_rgba_data[(z*4)+0] = 0;
					MAP_rgba_data[(z*4)+1] = 0;
					MAP_rgba_data[(z*4)+2] = 0;
					MAP_rgba_data[(z*4)+3] = 0;
				}
				else
				if(tileset_data[tile_index+pixel_in_tile_index]==0)
				{
					MAP_rgba_data[(z*4)+0] = 0;
					MAP_rgba_data[(z*4)+1] = 0;
					MAP_rgba_data[(z*4)+2] = 0;
					MAP_rgba_data[(z*4)+3] = 0;
				}
				else
				{

					int r,g,b,a;
					r=(palette_data[tileset_data[tile_index+pixel_in_tile_index]]%32)*8;
					g=((palette_data[tileset_data[tile_index+pixel_in_tile_index]]/32)%32)*8;
					b=(((palette_data[tileset_data[tile_index+pixel_in_tile_index]]/32)/32)%32)*8;

					if(transparent==1)
					a=159;
					else
					a=255;

					//adjust_color(&r,&g,&b);

					MAP_rgba_data[(z*4)+BYTE_RED	] = r;
					MAP_rgba_data[(z*4)+BYTE_GREEN	] = g;
					MAP_rgba_data[(z*4)+BYTE_BLUE	] = b;

					MAP_rgba_data[(z*4)+3] = a;
				}
			}
		}



		int w=twidth;
		int h=theight;
		int* g=(int*)MAP_rgba_data;

		//if there is already a texture there delete it and set to 0
		if(AUX_bg_is_on[bg_layer]&&glIsTexture(GLTex_AUX_bg[bg_layer]))
		{
			glDeleteTextures(1, &GLTex_AUX_bg[bg_layer]);

			//GLTex_AUX_bg[bg_layer]=0///this is still a texture and it will be drawn in render!!!!
		}

		glGenTextures(1, &GLTex_AUX_bg[bg_layer]);
		glBindTexture(GL_TEXTURE_2D, GLTex_AUX_bg[bg_layer]);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_BGRA, GL_UNSIGNED_BYTE, g);

		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

		//glFinish();

		if(MAP_rgba_data!=NULL){free(MAP_rgba_data);MAP_rgba_data=NULL;}

		AUX_bg_is_on[bg_layer]=1;
}

//==========================================================================================================================
void HARDWARE_load_map(int bg_layer, void* MAP_data, int width, int height)//HARDWARE_LoadBgMap
{//==========================================================================================================================





		unsigned short* MAP_layer_data = (unsigned short*)MAP_data;



		//translate into rgba
		//get width, height of file
		int pwidth = width;
		int pheight = height;

		int twidth = power_of_two(pwidth);
		int theight = power_of_two(pheight);

		bg_texture_size_x[bg_layer]=twidth;
		bg_texture_size_y[bg_layer]=theight;



		unsigned char * MAP_rgba_data = (unsigned char *)calloc(twidth * theight * 4, sizeof(unsigned char));



		int x=0;
		int y=0;
		int z=0;

		for(y=0;y<theight;y++)
		{
			for(x=0;x<twidth;x++)
			{


				int tile_index = 0;

				if(x<pwidth&&y<pheight)
				tile_index = 64 * (MAP_layer_data[(x/8)+((pwidth/8)*(y/8))]);




				int pixel_in_tile_index = 0;

				if(x<pwidth&&y<pheight)
				pixel_in_tile_index = (x%8) + ((y%8) * 8);


				z = x + (y*twidth);


				if(x>=pwidth||y>=pheight)
				{
					MAP_rgba_data[(z*4)+0] = 0;
					MAP_rgba_data[(z*4)+1] = 0;
					MAP_rgba_data[(z*4)+2] = 0;
					MAP_rgba_data[(z*4)+3] = 0;
				}
				else
					if(HARDWARE_map_tileset[tile_index+pixel_in_tile_index]==0)
					{
						MAP_rgba_data[(z*4)+0] = 0;
						MAP_rgba_data[(z*4)+1] = 0;
						MAP_rgba_data[(z*4)+2] = 0;
						MAP_rgba_data[(z*4)+3] = 0;
					}
					else
					{

						int r,g,b,a;

						r=HARDWARE_MAP_PALETTE_ENHANCED_RGB[3*HARDWARE_map_tileset[tile_index+pixel_in_tile_index]+0];//(HARDWARE_map_palette[HARDWARE_map_tileset[tile_index+pixel_in_tile_index]]%32)*8;
						g=HARDWARE_MAP_PALETTE_ENHANCED_RGB[3*HARDWARE_map_tileset[tile_index+pixel_in_tile_index]+1];//((HARDWARE_map_palette[HARDWARE_map_tileset[tile_index+pixel_in_tile_index]]/32)%32)*8;
						b=HARDWARE_MAP_PALETTE_ENHANCED_RGB[3*HARDWARE_map_tileset[tile_index+pixel_in_tile_index]+2];//(((HARDWARE_map_palette[HARDWARE_map_tileset[tile_index+pixel_in_tile_index]]/32)/32)%32)*8;
						if(bg_layer==0)
						a=159;
						else
						a=255;

						//adjust_color(&r,&g,&b);

						MAP_rgba_data[(z*4)+BYTE_RED	] = r;
						MAP_rgba_data[(z*4)+BYTE_GREEN	] = g;
						MAP_rgba_data[(z*4)+BYTE_BLUE	] = b;

						MAP_rgba_data[(z*4)+3] = a;


					}
			}
		}



		//if(bg_layer==0)SDL_SetAlpha( SDLSurface_bg[0], SDL_SRCALPHA, 128 );

		int w=twidth;
		int h=theight;
		int* g=(int*)MAP_rgba_data;

		//if there is already a texture there delete it and set to 0
		if(bg_is_on[bg_layer]&&glIsTexture(GLTex_bg[bg_layer]))
		{
			glDeleteTextures(1, &GLTex_bg[bg_layer]);
			//GLTex_bg[bg_layer]=0;
		}

		glGenTextures(1, &GLTex_bg[bg_layer]);
		glBindTexture(GL_TEXTURE_2D, GLTex_bg[bg_layer]);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_BGRA, GL_UNSIGNED_BYTE, g);

		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

//lTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
//glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &fLargest);
//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, fLargest);
//glPrioritizeTextures(1,&GLTex_bg[bg_layer],q);
//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_PRIORITY, 1.0f);
//glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, bc);

		//glFinish();

		if(MAP_rgba_data!=NULL){free(MAP_rgba_data);MAP_rgba_data=NULL;}

		bg_is_on[bg_layer]=1;


}

/*
GLuint GLTex_Tiles[1024*4];

//==========================================================================================================================
void HARDWARE_load_tileset_to_textures(int screen, int bg_layer, int* tileset_data, int size)//HARDWARE_LoadBgMap
{//==========================================================================================================================

	if(screen!=0)
	{


//==================for each tile make a sdl surface, make a gl texture============================

		int amountOfTiles = size/16;

		int t=0;
		for(t=0;t<amountOfTiles;t++)
		{

			//make sdl surface from tile/palette data

			Uint32 rmask, gmask, bmask, amask;

			// SDL interprets each pixel as a 32-bit number, so our masks must depend
			//     on the endianness (byte order) of the machine
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



			SDL_Surface* surface = SDL_CreateRGBSurface(SDL_SWSURFACE, 8, 8, 32, rmask, gmask, bmask, amask);

			SDL_LockSurface(surface);

			unsigned char * tile_rgba_data = (unsigned char *)surface->pixels;


			int x=0;
			int y=0;
			int z=0;

			for(y=0;y<8;y++)
			{
				for(x=0;x<8;x++)
				{

					z=(y*8)+x;

					if(tileset_data[(t*64)+z]==0)
					{
						tile_rgba_data[(z*4)+0] = 0;
						tile_rgba_data[(z*4)+1] = 0;
						tile_rgba_data[(z*4)+2] = 0;
						tile_rgba_data[(z*4)+3] = 0;
					}
					else
					{
						tile_rgba_data[(z*4)+0] = (HARDWARE_map_palette[tileset_data[(t*64)+z]]%32)*8;
						tile_rgba_data[(z*4)+1] = ((HARDWARE_map_palette[tileset_data[(t*64)+z]]/32)%32)*8;
						tile_rgba_data[(z*4)+2] = (((HARDWARE_map_palette[tileset_data[(t*64)+z]]/32)/32)%32)*8;
						if(bg_layer==0)
						tile_rgba_data[(z*4)+3] = 159;
						else
						tile_rgba_data[(z*4)+3] = 255;
					}
				}
			}

			SDL_UnlockSurface(surface);

			int w=surface->w;
			int h=surface->h;
			int* g=surface->pixels;

			//if there is already a texture there delete it and set to 0
			if(glIsTexture(GLTex_Tiles[(bg_layer*1024)+t]))
			{
				glDeleteTextures(1, &GLTex_Tiles[(bg_layer*1024)+t]);
				GLTex_Tiles[(bg_layer*1024)+t]=0;

			}

			//create one texture name
			glGenTextures(1, &GLTex_Tiles[(bg_layer*1024)+t]);

			//tell opengl to use the generated texture name
			glBindTexture(GL_TEXTURE_2D, GLTex_Tiles[(bg_layer*1024)+t]);

			//this reads from the sdl surface and puts it into an opengl texture
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_BGRA, GL_UNSIGNED_BYTE, g);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

			SDL_FreeSurface(surface);

		}
	}

}


*/


//==========================================================================================================================
void HARDWARE_load_metatile(int bg_layer, int MAP_width_pixels, int MAP_height_pixels, int clipx, int clipy, char* name)//HARDWARE_LoadBgMap
{//==========================================================================================================================

	//find an unused metatile slot
	int s=0;
	int metatile_index=0;


	for(s=0;s<METATILES_POSSIBLE;s++)
	if(metatile_used[bg_layer*METATILES_POSSIBLE+s]==0){metatile_index=s;s=METATILES_POSSIBLE;break;}

	metatile_x[bg_layer*METATILES_POSSIBLE+metatile_index]=clipx;
	metatile_y[bg_layer*METATILES_POSSIBLE+metatile_index]=clipy;
	metatile_used[bg_layer*METATILES_POSSIBLE+metatile_index]=1;


	//need to load only from x,y to metatile size
	//so make a new map array screen width and height
	//open the file, figure out location for each width starting at x y
	//fill the new array with each width
	//load that into a texture

	//calloc mallocs and inits
	int* clipmap = (int*)calloc(METATILE_SIZE/8 * METATILE_SIZE/8, sizeof(int));

	int* map = NULL;

	if(bg_layer==0)map=HARDWARE_map_0;
	if(bg_layer==1)map=HARDWARE_map_1;
	if(bg_layer==2)map=HARDWARE_map_2;
	if(bg_layer==3)map=HARDWARE_map_3;

	//if the clipped region isn't even on the map, don't bother opening any file.
	//just keep it blank.
	if(clipx+METATILE_SIZE>0&&clipx<MAP_width_pixels&&clipy+METATILE_SIZE>0&&clipy<MAP_height_pixels)
	{


		//lets keep the whole file loaded in memory and just copy the tiles we need
		//FILE* file;

		//char fullname[1024];

		//strcpy(fullname,"data");
		//strcat(fullname,name);

		//file = fopen(fullname, "rb");

		//if(file != NULL)
		{

			int y=0;
			int bigmapindex = 0;
			int clipmapindex = 0;


			for(y=(clipy/8);y<(clipy/8)+METATILE_SIZE/8;y++)
			{
				//only read to the bottom edge
				if(y>=0&&y<(MAP_height_pixels/8))
				{

					if(clipx>=0)
					{
						//calculate index for larger map file.
						bigmapindex = (y*(MAP_width_pixels/8))+(clipx/8);

						//seek to correct part of larger map file
						//fseek(file,sizeof(int)*bigmapindex,SEEK_SET);

						int* cmp = &clipmap[clipmapindex];

						//if its off the edge of the map, only read to the edge
						if((clipx/8)+METATILE_SIZE/8>=(MAP_width_pixels/8))
						{
							//fread(cmp, sizeof(int), (MAP_width_pixels/8)-(clipx/8), file);

							int t=0;
							for(t=0;t<(MAP_width_pixels/8)-(clipx/8);t++)
							cmp[t]=map[bigmapindex+t];
						}
						else
						{
							//fread(cmp, sizeof(int), METATILE_SIZE/8, file);

							int t=0;
							for(t=0;t<METATILE_SIZE/8;t++)
							cmp[t]=map[bigmapindex+t];
						}

						clipmapindex+=(METATILE_SIZE/8);

					}
					else
					{
						bigmapindex = (y*(MAP_width_pixels/8));
						int offset = 0-clipx/8;

							//seek to correct part of larger map file
							//fseek(file,sizeof(int)*bigmapindex,SEEK_SET);

							int* cmp = &clipmap[clipmapindex+offset]; //skip the blank space

							//if its off the edge of the map, only read to the edge
							if((METATILE_SIZE/8)-offset>=(MAP_width_pixels/8))
							{

								//fread(cmp, sizeof(int), (MAP_width_pixels/8), file);

								int t=0;
								for(t=0;t<(MAP_width_pixels/8);t++)
								cmp[t]=map[bigmapindex+t];
							}
							else
							{
								//fread(cmp, sizeof(int), (METATILE_SIZE/8)-offset, file);

								int t=0;
								for(t=0;t<(METATILE_SIZE/8)-offset;t++)
								cmp[t]=map[bigmapindex+t];
							}

							clipmapindex+=(METATILE_SIZE/8)-offset;
					}
				}
				else
				clipmapindex+=METATILE_SIZE/8; //if part of the clipmap is above the larger map, skip the row

			}

		}
		//fclose(file);
	}


	unsigned short* MAP_layer_data = (unsigned short*)clipmap;

	int texture_width = METATILE_SIZE;
	int texture_height = METATILE_SIZE;

	unsigned char * MAP_rgba_data = (unsigned char*)calloc(texture_width*texture_height*4, sizeof(unsigned char));//(unsigned char *)surface->pixels;

	int x=0;
	int y=0;
	int z=0;

	for(y=0;y<texture_height;y++)
	{
		for(x=0;x<texture_width;x++)
		{

			int tile_index = 0;

			if(x<METATILE_SIZE&&y<METATILE_SIZE)
			tile_index = 64 * (MAP_layer_data[(x/8)+((METATILE_SIZE/8)*(y/8))]);

			int pixel_in_tile_index = 0;

			if(x<METATILE_SIZE&&y<METATILE_SIZE)
			pixel_in_tile_index = (x%8) + ((y%8) * 8);

			z = x + (y*texture_width);

			if(x>=METATILE_SIZE||y>=METATILE_SIZE)
			{
				MAP_rgba_data[(z*4)+0] = 0;
				MAP_rgba_data[(z*4)+1] = 0;
				MAP_rgba_data[(z*4)+2] = 0;
				MAP_rgba_data[(z*4)+3] = 0;
			}
			else
			if(HARDWARE_map_tileset[tile_index+pixel_in_tile_index]==0)
			{
				MAP_rgba_data[(z*4)+0] = 0;
				MAP_rgba_data[(z*4)+1] = 0;
				MAP_rgba_data[(z*4)+2] = 0;
				MAP_rgba_data[(z*4)+3] = 0;
			}
			else
			{
				int r,g,b,a;
				r=HARDWARE_MAP_PALETTE_ENHANCED_RGB[3*HARDWARE_map_tileset[tile_index+pixel_in_tile_index]+0];//(HARDWARE_map_palette[HARDWARE_map_tileset[tile_index+pixel_in_tile_index]]%32)*8;
				g=HARDWARE_MAP_PALETTE_ENHANCED_RGB[3*HARDWARE_map_tileset[tile_index+pixel_in_tile_index]+1];//((HARDWARE_map_palette[HARDWARE_map_tileset[tile_index+pixel_in_tile_index]]/32)%32)*8;
				b=HARDWARE_MAP_PALETTE_ENHANCED_RGB[3*HARDWARE_map_tileset[tile_index+pixel_in_tile_index]+2];//(((HARDWARE_map_palette[HARDWARE_map_tileset[tile_index+pixel_in_tile_index]]/32)/32)%32)*8;
				if(bg_layer==0)
				a=159;
				else
				a=255;

				MAP_rgba_data[(z*4)+BYTE_RED	] = r;
				MAP_rgba_data[(z*4)+BYTE_GREEN	] = g;
				MAP_rgba_data[(z*4)+BYTE_BLUE	] = b;

				MAP_rgba_data[(z*4)+3] = a;
			}
		}
	}

	if(clipmap!=NULL){free(clipmap);clipmap=NULL;}

	int w=texture_width;//surface->w;
	int h=texture_height;//surface->h;
	int* g=(int*)MAP_rgba_data;//surface->pixels;

	{
		glGenTextures(1, &GLTex_map_metatile[bg_layer*METATILES_POSSIBLE+metatile_index]);
		glBindTexture(GL_TEXTURE_2D, GLTex_map_metatile[bg_layer*METATILES_POSSIBLE+metatile_index]);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_BGRA, GL_UNSIGNED_BYTE, g);
	}

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

	//glFinish();

	if(MAP_rgba_data!=NULL){free(MAP_rgba_data);MAP_rgba_data=NULL;}

}

