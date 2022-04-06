



#include "../../main.h"
//#include "sprites.h"


#include "gfx_vars.h"



int* GAME_original_SPRITE_PALETTE = NULL; //pointer to globalspritepalette.bin
int* GAME_hq2x_SPRITE_PALETTE = NULL; //pointer to hq2xpalette.bin

unsigned short GAME_temp_SPRITE_PALETTE[256] = {0};//holds brightened sprite palette

//int HARDWARE_texture_SPRITE_PALETTE[256] = {0}; //holds current palette loaded with HARDWARE_load_sprite_palette, so this is the one that gets used ultimately
int HARDWARE_ORIGINAL_SPRITE_PALETTE_ENHANCED_RGB[256*3] = {0};
int HARDWARE_HQ2X_SPRITE_PALETTE_ENHANCED_RGB[256*3] = {0};


GLuint GLTex_preloaded_sprite_textures[1024*8*8] = {0};

bool USED_preloaded_sprite_textures_USED[1024*8*8] = {0};//this is for each individual frame, recording that there is a texture there, since setting GLuint to zero is unreliable.

bool Used_Preloaded_Texture_ID_Array_Slots[1024] = {0};//this is for each 8x8 frame offset, per sprite file. the slot being marked as reserved here doesnt mean theres a texture there yet.

//float rotation_set[128] = {0};

SPRITE* HARDWARE_sprites[256];
GLuint HARDWARE_preload_sprite_texture_frame(GFX* gfx, int frame, int IndexInCachedTextureIDArray);


//==========================================================================================================================
void HARDWARE_init_arrays()
//==========================================================================================================================
{
	int x=0;

	//for(x=0;x<128;x++)GLTex_sprite[x]=-1;
	//for(x=0;x<1024;x++)GLTex_preloaded_gfx_structs[x]=NULL;
	for(x=0;x<1024;x++)Used_Preloaded_Texture_ID_Array_Slots[x]=0;
	//for(x=0;x<128;x++)PLAYER_id_gfx_slot[x]=-1;

	for(x=0;x<256;x++)HARDWARE_sprites[x]=NULL;

	for(x=0;x<1024*8*8;x++)GLTex_preloaded_sprite_textures[x]=0;
	for(x=0;x<1024*8*8;x++)USED_preloaded_sprite_textures_USED[x]=0;

	for(x=0;x<4;x++)AUX_bg_is_on[x]=0;
	for(x=0;x<4;x++)bg_is_on[x]=0;

	for(x=0;x<4*METATILES_POSSIBLE;x++)metatile_used[x]=0;

}




//==========================================================================================================================
void HARDWARE_load_sprite_palette(int* palette)//HARDWARE_LoadSpritePal
{//==========================================================================================================================

	palette=NULL;

	ERROR_set_error("need to fix palette loading");

}




//==========================================================================================================================
void HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX* gfx, const char* gfx_filename,int data_size_x, int data_size_y, int shadow, int preload)//HARDWARE_UpdateSpriteGfx
{//==========================================================================================================================


	//-----------------------------
	//if hq2x is on, use normal data sizes
	//-----------------------------
	if(GLOBAL_hq2x_is_on)
	{

		strcpy(gfx->FileName,gfx_filename);


		//if filename has hq2x
		if(strncmp(gfx_filename,"/sprite/hq2x",12)==0)
		{
			//normal character sprites are 16x40, kids are 16x32. (adults 32x80 and kids 32x64 for hq2x)
			if(data_size_x==32&&data_size_y==64)
			gfx->kid=1;

			if(data_size_x==32&&data_size_y==80)
			gfx->adult=1;

			if(
				gfx==GFX_CAR_car
				||gfx==GFX_CAR_truck
				||gfx==GFX_CAR_van
				||gfx==GFX_CAR_suv
				||gfx==GFX_CAR_ferrari
				||gfx==GFX_CAR_skycar
				||gfx==GFX_CAR_helicopter
				||gfx==GFX_CAR_minivan
				||gfx==GFX_CAR_ambulance
				||gfx==GFX_CAR_icecreamtruck
				||gfx==GFX_CAR_mafiacar
				||gfx==GFX_CAR_motorcycle
				||gfx==GFX_CAR_policecar
				||gfx==GFX_CAR_tank
				||gfx==GFX_CAR_tvvan
				||gfx==GFX_CAR_ufo
			)
			gfx->car=1;

			if(gfx==GFX_CAR_bicycle)
			gfx->bike=1;

			gfx->hq2x=1;
		}

	}
	else
	{
		//-----------------------------
		//hq2x is off, we need to cut down the data sizes and load the original sprites
		//-----------------------------

		//if filename has hq2x
		if(strncmp(gfx_filename,"/sprite/hq2x",12)==0)
		{
			//change filename
			//remove hq2x from string
			//cut off first 12 chars, replace with /sprite/

			sprintf(gfx->FileName,"/sprite/%s",(char*)(&gfx_filename[12]));


			//see if its a kid, car, adult, or bike
			if(data_size_x==32&&data_size_y==80)
			gfx->adult=1;

			//normal character sprites are 16x40, kids are 16x32. (adults 32x80 and kids 32x64 for hq2x)
			if(data_size_x==32&&data_size_y==64)
			gfx->kid=1;

			if(
				gfx==GFX_CAR_car
				||gfx==GFX_CAR_truck
				||gfx==GFX_CAR_van
				||gfx==GFX_CAR_suv
				||gfx==GFX_CAR_ferrari
				||gfx==GFX_CAR_skycar
				||gfx==GFX_CAR_helicopter
				||gfx==GFX_CAR_minivan
				||gfx==GFX_CAR_ambulance
				||gfx==GFX_CAR_icecreamtruck
				||gfx==GFX_CAR_mafiacar
				||gfx==GFX_CAR_motorcycle
				||gfx==GFX_CAR_policecar
				||gfx==GFX_CAR_tank
				||gfx==GFX_CAR_tvvan
				||gfx==GFX_CAR_ufo
			)
			gfx->car=1;

			if(gfx==GFX_CAR_bicycle)
			gfx->bike=1;

			//if kid, make 16x32
			if(gfx->kid){data_size_x=16;data_size_y=32;}
			//if adult, make 32 x 64. USED TO BE 16*40 but after i imported them into the editor it made them 32x64.
			//hq2x is 32x80 because they werent input into the editor, they were made with an image and a hq2x tool, i think...
			if(gfx->adult){data_size_x=32;data_size_y=64;}
			//if car or bike make 64x64
			if(gfx->car||gfx->bike){data_size_x=64;data_size_y=64;}


		}
		else strcpy(gfx->FileName,gfx_filename);
	}

	gfx->data_size_x=data_size_x;
	gfx->data_size_y=data_size_y;


	//find open slot in preloaded sprite textures (in steps of 64)
	int IndexInCachedTextureIDArray=-1;
	int s=0;
	for(s=0;s<1024;s++)
	{
		//if it doesn't have a texture
		if(Used_Preloaded_Texture_ID_Array_Slots[s]==0){IndexInCachedTextureIDArray=s;s=1024;break;}
	}

	if(IndexInCachedTextureIDArray==-1){ERROR_set_error("ran out of preloaded sprite slots \n");return;}

	//reference this later to find the appropriate texture slot when we are assigning the textures to the actual sprites


	//all this is used for is a marker to get a position in the GLTex_preloaded_sprite_textures, this array is not used outside of this function
	Used_Preloaded_Texture_ID_Array_Slots[IndexInCachedTextureIDArray]=1;


	gfx->IndexInCachedTextureIDArray=IndexInCachedTextureIDArray;

	gfx->shadow=shadow;


	if(preload==1)//HARDWARE_preload_sprite_textures(gfx,gfx->data_size_x,gfx->data_size_y,IndexInCachedTextureIDArray);
	{

		int gfx_data_is_file=1;

		int amount_of_frames_in_file=0;

		//if name is TEXT, TEXTANSWER, etc use internal arrays for sprite gfx "TEXTSPRITEWINDOW" "PINGPADDLE" "PINGBALL"
		if(	gfx==TEXT_GFX[0]
		||gfx==TEXT_GFX[1])
		{gfx_data_is_file=0;amount_of_frames_in_file=4*3;}

		if(	gfx==TEXTANSWER_GFX)
		{gfx_data_is_file=0;amount_of_frames_in_file=3*2;}

		if(	gfx==TEXTSPRITEWINDOW_GFX[0]
		||gfx==TEXTSPRITEWINDOW_GFX[1])
		{gfx_data_is_file=0;amount_of_frames_in_file=1;}

		if(	gfx==PINGPADDLE_GFX)
		{gfx_data_is_file=0;amount_of_frames_in_file=1;}

		if(	gfx==PINGBALL_GFX)
		{gfx_data_is_file=0;amount_of_frames_in_file=1;}




		//this is for caption chunks, it tracks a dynamic indexed graphic array inside itself
		if(gfx->indexed_gfx_data!=NULL)
		{
			//sprite_indexed_gfx_data = gfx->indexed_gfx_data;
			amount_of_frames_in_file=1;
			gfx_data_is_file=0;
		}

		if(gfx_data_is_file)
		{
			//need to figure out size of file and size of sprite to calculate amount of frames.
			//get filesize
			int filesize = 0;
			filesize = HARDWARE_get_file_size(gfx->FileName);

			amount_of_frames_in_file=filesize/(gfx->data_size_x*gfx->data_size_y);
		}


		//load all possible frames into slot
		int f=0;
		for(f=0;f<amount_of_frames_in_file;f++)
		{
			HARDWARE_preload_sprite_texture_frame(gfx,f,IndexInCachedTextureIDArray);
		}
	}


}

//==========================================================================================================================
GLuint HARDWARE_preload_sprite_texture_frame(GFX* gfx, int frame, int IndexInCachedTextureIDArray)//HARDWARE_UpdateSpriteGfx
{//==========================================================================================================================

		//-----------------------------
		//set the palette for hq2x or not
		//-----------------------------

		int* palette = HARDWARE_ORIGINAL_SPRITE_PALETTE_ENHANCED_RGB;//(int*)HARDWARE_texture_SPRITE_PALETTE;

		if(gfx->hq2x)
		{
			palette = HARDWARE_HQ2X_SPRITE_PALETTE_ENHANCED_RGB;//GAME_hq2x_SPRITE_PALETTE;
		}


		//-----------------------------
		//set texture size
		//-----------------------------
			int car=gfx->car;
			int kid=gfx->kid;
			int bike=gfx->bike;
			int adult=gfx->adult;

			int texture_size_x=gfx->data_size_x;
			int texture_size_y=gfx->data_size_y;


			//do this because there isnt enough room for shadow so i have to double the texture size y
			if(car||kid||adult||bike)texture_size_y*=2;

			//make sure texture size is power of 2!
			texture_size_x = power_of_two(texture_size_x);
			texture_size_y = power_of_two(texture_size_y);

			gfx->texture_size_x = texture_size_x;
			gfx->texture_size_y = texture_size_y;

		//-----------------------------
		//calculate gfx_index by frame and data size
		//-----------------------------
			int sprite_data_size_x=gfx->data_size_x;
			int sprite_data_size_y=gfx->data_size_y;

			int gfx_index=0;
			gfx_index=frame*sprite_data_size_x*sprite_data_size_y;

		//-----------------------------
		//determine whether we are loading from a file or from internal memory
		//-----------------------------
			int gfx_data_is_file=1;
			int* sprite_indexed_gfx_data = NULL;

			//if name is TEXT, TEXTANSWER, or CAPTION use internal arrays for sprite gfx "TEXTSPRITEWINDOW" "PINGPADDLE" "PINGBALL"
			if(gfx==TEXT_GFX[0])
			{sprite_indexed_gfx_data = TEXT_textbox[0].indexed_gfx_data; gfx_data_is_file=0;}
			if(gfx==TEXT_GFX[1])
			{sprite_indexed_gfx_data = TEXT_textbox[1].indexed_gfx_data; gfx_data_is_file=0;}

			if(gfx==TEXTANSWER_GFX)
			{sprite_indexed_gfx_data = TEXTANSWER_answerbox_indexed_gfx_data;gfx_data_is_file=0;}

			if(gfx==TEXTSPRITEWINDOW_GFX[0])
			{sprite_indexed_gfx_data = TEXT_textbox[0].sprite_window_indexed_gfx_data;gfx_data_is_file=0;if(GLOBAL_hq2x_is_on)palette = HARDWARE_HQ2X_SPRITE_PALETTE_ENHANCED_RGB;}
			if(gfx==TEXTSPRITEWINDOW_GFX[1])
			{sprite_indexed_gfx_data = TEXT_textbox[1].sprite_window_indexed_gfx_data;gfx_data_is_file=0;if(GLOBAL_hq2x_is_on)palette = HARDWARE_HQ2X_SPRITE_PALETTE_ENHANCED_RGB;}

			if(	gfx==PINGPADDLE_GFX)
			{sprite_indexed_gfx_data = PING_paddle_gfx;gfx_data_is_file=0;palette = HARDWARE_HQ2X_SPRITE_PALETTE_ENHANCED_RGB;}

			if(	gfx==PINGBALL_GFX)
			{sprite_indexed_gfx_data = PING_ball_gfx;gfx_data_is_file=0;}


			if(gfx->indexed_gfx_data!=NULL)
			{
				sprite_indexed_gfx_data = gfx->indexed_gfx_data;
				gfx_data_is_file=0;
			}

			if(gfx_data_is_file==1)sprite_indexed_gfx_data = (int*)HARDWARE_load_file(gfx->FileName);


			//-----------------------------
			//make the surface
			//-----------------------------
			//SDL_Surface * surface = SDL_CreateRGBSurface(SDL_SWSURFACE, texture_size_x, texture_size_y, 32, rmask, gmask, bmask, amask);
			//SDL_LockSurface( surface );

			unsigned char * rgba_data =  (unsigned char*)calloc(texture_size_x*texture_size_y*4, sizeof(unsigned char));//(unsigned char *)surface->pixels;


			//-----------------------------
			//find the top and bottom of the sprite for the shadow
			//-----------------------------

			int shadow=gfx->shadow;

			int x=0;
			int y=0;
			int z=0;

			int bottomy=0;
			int topy=0;
			int rightx=0;

				int stop=0;
				//find bottomy
				for(y=sprite_data_size_y-1;y>=0&&stop==0;y--)
					for(x=0;x<sprite_data_size_x&&stop==0;x++)
					{
						int i=0;
						i=
						((64*(x/8))+//skip 64 for each tile x
						(x%8))+//remaining x
						(64*(sprite_data_size_x/8)*(y/8))+//skip 2 x 64 for each tile y
						(8*(y%8));//8 for each row in tile y

						if(x<sprite_data_size_x&&y<sprite_data_size_y&&sprite_indexed_gfx_data[gfx_index+i]!=0)
						{
							bottomy=y+1;
							stop=1;
							break;
						}
					}

				//find topy
				stop=0;
				for(y=0;y<sprite_data_size_y&&stop==0;y++)
					for(x=0;x<sprite_data_size_x&&stop==0;x++)
					{
						int i=0;
						i=
						((64*(x/8))+//skip 64 for each tile x
						(x%8))+//remaining x
						(64*(sprite_data_size_x/8)*(y/8))+//skip 2 x 64 for each tile y
						(8*(y%8));//8 for each row in tile y

						if(x<sprite_data_size_x&&y<sprite_data_size_y&&sprite_indexed_gfx_data[gfx_index+i]!=0)
						{
							topy=y;
							stop=1;
							break;
						}

					}

				//find rightmost pixel
				stop=0;
				for(y=topy;y<bottomy&&stop==0;y++)
					for(x=0;x<sprite_data_size_x&&stop==0;x++)
					{
						int i=0;
						i=
						((64*(x/8))+//skip 64 for each tile x
						(x%8))+//remaining x
						(64*(sprite_data_size_x/8)*(y/8))+//skip 2 x 64 for each tile y
						(8*(y%8));//8 for each row in tile y

						if(x<sprite_data_size_x&&y<sprite_data_size_y&&sprite_indexed_gfx_data[gfx_index+i]!=0)
						{
							if(x>rightx)rightx=x;
						}

					}






			//set the texture content size for clipping while rendering to save render time
			gfx->content_size_x=rightx+1;
			if(gfx->content_size_x>gfx->texture_size_x)gfx->content_size_x=gfx->texture_size_x;

			if(bottomy+1>gfx->content_size_y)gfx->content_size_y=bottomy+1;

			if(shadow==1)
			{


				int size_y = (bottomy-1)-topy;//gfx->data_size_y;

				//from bottom of texture/3 tiles under bottom y to bottom y, mirror the pixels starting from the top as shadow
				int start_shadow_y = (texture_size_y/4)*3;

				//dont draw shadows longer than half the sprite height
				if(bottomy+size_y/2<start_shadow_y)start_shadow_y=bottomy+size_y/2;

				//if the sprite is less than half a person tall, draw a small shadow
				if((bottomy-topy)<size_y/2)start_shadow_y=bottomy+8;


				if(start_shadow_y+1>gfx->content_size_y)gfx->content_size_y=start_shadow_y+1;


				//fill the whole array with 0
				z=0;
				for(y=0;y<texture_size_y;y++)
				{
					for(x=0;x<texture_size_x;x++)
					{
							rgba_data[(z*4)+0] = 0;
							rgba_data[(z*4)+1] = 0;
							rgba_data[(z*4)+2] = 0;
							rgba_data[(z*4)+3] = 0;
							z++;
					}
				}

				z=0;
				for(y=start_shadow_y;y>=bottomy-(size_y/4);y--) //draw the shadow up to 1/4 the sprite height to make sure it covers the feet
				{
					for(x=0;x<texture_size_x;x++)
					{

						z=(y*texture_size_x)+x;

						int mirrory = topy+(int)((start_shadow_y-y)*1.25f);
						if(mirrory<0)mirrory=0;
						if(mirrory>bottomy)mirrory=bottomy;

						int i=0;
						i=
						((64*(x/8))+//skip 64 for each tile x
						(x%8))+//remaining x
						(64*(sprite_data_size_x/8)*(mirrory/8))+//skip 2 x 64 for each tile y
						(8*(mirrory%8));//8 for each row in tile y

						if(sprite_indexed_gfx_data[gfx_index+i]==0)
						{
							rgba_data[(z*4)+0] = 0;
							rgba_data[(z*4)+1] = 0;
							rgba_data[(z*4)+2] = 0;
							rgba_data[(z*4)+3] = 0;
						}
						else
						{
							rgba_data[(z*4)+0] = 0;
							rgba_data[(z*4)+1] = 0;
							rgba_data[(z*4)+2] = 0;

							int t=159;
							///ignoring alpha for now
							//if(PLAYER_gfx_slot_alpha[gfx_slot]<t)t=PLAYER_gfx_slot_alpha[gfx_slot];
							if(t<0)t=0;

							rgba_data[(z*4)+3] = t;

						}

					}
				}
			}


//fill as usual, ignoring 0 values.

				z=0;
				for(y=0;y<texture_size_y;y++)
				{
					for(x=0;x<texture_size_x;x++)
					{

						int i=0;
						i=
						((64*(x/8))+//skip 64 for each tile x
						(x%8))+//remaining x
						(64*(sprite_data_size_x/8)*(y/8))+//skip 2 x 64 for each tile y
						(8*(y%8));//8 for each row in tile y



						if(x>=sprite_data_size_x||y>=sprite_data_size_y)
						{
							if(!shadow)
							{
								rgba_data[(z*4)+2] = 0;
								rgba_data[(z*4)+1] = 0;
								rgba_data[(z*4)+0] = 0;
								rgba_data[(z*4)+3] = 0;
							}
						}
						else
						if(sprite_indexed_gfx_data[gfx_index+i]==0)
						{
							if(!shadow)
							{
								rgba_data[(z*4)+2] = 0;
								rgba_data[(z*4)+1] = 0;
								rgba_data[(z*4)+0] = 0;
								rgba_data[(z*4)+3] = 0;
							}

						}
						else
						{
							if(car||bike)
							{

								///lets fill in extra frames with different colors!
								///amount_of_frames_in_file


								/*if(PLAYER_gfx_slot_colorset[gfx_slot]==0)
								{
									PLAYER_gfx_slot_colorset[gfx_slot]=1+rand()%8;
								}*/

								//int r,g,b;
								//r=(spritepalette_bgr[sprite_indexed_gfx_data[gfx_index+i]]%32)*8;
								//g=((spritepalette_bgr[sprite_indexed_gfx_data[gfx_index+i]]/32)%32)*8;
								//b=(((spritepalette_bgr[sprite_indexed_gfx_data[gfx_index+i]]/32)/32)%32)*8;

								int r=palette[sprite_indexed_gfx_data[gfx_index+i]*3+0];
								int g=palette[sprite_indexed_gfx_data[gfx_index+i]*3+1];
								int b=palette[sprite_indexed_gfx_data[gfx_index+i]*3+2];


								/*if(r>g&&r>b)
								{

									if(PLAYER_gfx_slot_colorset[gfx_slot]==1)
									{
										//gray
										g=r;
										b=r;
									}
									if(PLAYER_gfx_slot_colorset[gfx_slot]==2)
									{
										//red
									}
									if(PLAYER_gfx_slot_colorset[gfx_slot]==3)
									{
										//blue
										int t=r;
										r=b;
										b=t;
									}
									if(PLAYER_gfx_slot_colorset[gfx_slot]==4)
									{
										//green
										int t=r;
										r=g;
										g=t;
									}
									if(PLAYER_gfx_slot_colorset[gfx_slot]==5)
									{
										//lightblue
										int t=(r*1.5f);if(t>255)t=255;
										r=r;
										g=t;
										b=t;
									}
									if(PLAYER_gfx_slot_colorset[gfx_slot]==6)
									{
										//yellow
										g=r;
									}
									if(PLAYER_gfx_slot_colorset[gfx_slot]==7)
									{
										//white
										int t=(r*1.5f);if(t>255)t=255;
										r=t;
										g=t;
										b=t;
									}
									if(PLAYER_gfx_slot_colorset[gfx_slot]==8)
									{
										//darkgray
										int t=(r*0.5f);if(t>255)t=255;
										r=t;
										g=t;
										b=t;
									}

								}*/

								rgba_data[(z*4)+BYTE_RED	] = r;
								rgba_data[(z*4)+BYTE_GREEN	] = g;
								rgba_data[(z*4)+BYTE_BLUE	] = b;
								rgba_data[(z*4)+3] = 255;

							}
							else
							{
								int r=palette[sprite_indexed_gfx_data[gfx_index+i]*3+0];			//(spritepalette_bgr[sprite_indexed_gfx_data[gfx_index+i]]%32)*8;
								int g=palette[sprite_indexed_gfx_data[gfx_index+i]*3+1];			//((spritepalette_bgr[sprite_indexed_gfx_data[gfx_index+i]]/32)%32)*8;
								int b=palette[sprite_indexed_gfx_data[gfx_index+i]*3+2];			//(((spritepalette_bgr[sprite_indexed_gfx_data[gfx_index+i]]/32)/32)%32)*8;
								int a=255;

								//adjust_color(&r,&g,&b);

								rgba_data[(z*4)+BYTE_RED	] = r;
								rgba_data[(z*4)+BYTE_GREEN	] = g;
								rgba_data[(z*4)+BYTE_BLUE	] = b;

								rgba_data[(z*4)+3] = a;
							}
						}

						z++;
					}
				}

				if(gfx_data_is_file)HARDWARE_unload_file((void**)&sprite_indexed_gfx_data);


				//SDL_UnlockSurface(surface);

				int w=texture_size_x;//surface->w;
				int h=texture_size_y;//surface->h;
				int* g=(int*)rgba_data;//surface->pixels;


				if(IndexInCachedTextureIDArray!=-2)///for normal textures
				{
					//if there is already a texture there delete it and throw error
					if(USED_preloaded_sprite_textures_USED[IndexInCachedTextureIDArray*8*8+frame]&&glIsTexture(GLTex_preloaded_sprite_textures[IndexInCachedTextureIDArray*8*8+frame]))
					///THIS IS THE MULTIPLE SPRITE BUG SINCE THERE IS A TEXTURE ZERO, EVERY SINGLE ENTRY IS GETTING DELETED
					{
						glDeleteTextures(1, &GLTex_preloaded_sprite_textures[IndexInCachedTextureIDArray*8*8+frame]);
						//fprintf(stderr,"texture %s already existed and was overwritten. this shouldn't normally happen, so find out why!\n",gfx->FileName);

					}

					glGenTextures(1, &GLTex_preloaded_sprite_textures[IndexInCachedTextureIDArray*8*8+frame]);
					glBindTexture(GL_TEXTURE_2D, GLTex_preloaded_sprite_textures[IndexInCachedTextureIDArray*8*8+frame]);
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_BGRA, GL_UNSIGNED_BYTE, g);

					glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
					glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

					//SDL_FreeSurface(surface);
					if(rgba_data!=NULL){free(rgba_data);rgba_data=NULL;}

					USED_preloaded_sprite_textures_USED[IndexInCachedTextureIDArray*8*8+frame]=1;

					return GLTex_preloaded_sprite_textures[IndexInCachedTextureIDArray*8*8+frame]; //dont have to do this
				}
				else /// is -2, for captions ONLY right now
				{
					GLuint newtex=0;
					glGenTextures(1, &newtex);
					glBindTexture(GL_TEXTURE_2D, newtex);
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_BGRA, GL_UNSIGNED_BYTE, g);

					glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
					glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);


					//glFinish();

					//SDL_FreeSurface(surface);
					if(rgba_data!=NULL){free(rgba_data);rgba_data=NULL;}

					return newtex;
				}

}


//==========================================================================================================================
void HARDWARE_update_sprite_texture(SPRITE* sprite, int gfx_index)
{//==========================================================================================================================



	//man i am going to cry right now. it's been over a year since i wrote any code at all. i feel stupid and empty and like a loser.
	//but i'm ok. i can focus if i try. it's scary.
	//right now i feel pretty bad for reggie, even though i want to heckle him at gdc.
	//he looks so unhappy after he talks sometimes. i guess that is what you get for crushing dreams :(
	//not that i think he can help it. oh well.
	//2011-01-20


	//holy shit i did so much work
	//i made that nD thing and the firmware and website and now im porting this to gles and cleaning it all up
	//im turning this giant tangled mess into something a little more manageable
	//im getting better at coding and im able to clean this up into something semi-pro-like
	//seeing tim work on that "real" other ocean game made in allegro made me realize my code is good
	//also i just decided to work on wiz and psp and got inspired
	//im smoking a little bit of pot and on 10mg ritalin, 2 cups of coffee, nicotine patches
	//2011-07-08-05.38


	//ok now i can just say 'now' and hit ctrl-j -> 2011-01-21-16.15


		if(sprite==NULL)
		{
			ERROR_set_error("HARDWARE_update_sprite_texture : no texture struct to update! \n");

		}
		else
		{
			GFX* gfx = sprite->gfx;

			int gfx_data_is_file=1;

			//if name is TEXT, TEXTANSWER, or CAPTION use internal arrays for sprite gfx "TEXTSPRITEWINDOW" "PINGPADDLE" "PINGBALL"
			if(gfx==TEXT_GFX[0]
			||gfx==TEXT_GFX[1]
			||gfx==TEXTANSWER_GFX
			||gfx==TEXTSPRITEWINDOW_GFX[0]
			||gfx==TEXTSPRITEWINDOW_GFX[1]
			||gfx==PINGPADDLE_GFX
			||gfx==PINGBALL_GFX)
			gfx_data_is_file=0;

			//if the gfx struct has a pointer to indexed data, then its a caption and the gfx struct was made dynamically.
			//it will create texture from this indexed data below.
			if(gfx->indexed_gfx_data!=NULL)
			{
				//sprite_indexed_gfx_data = gfx->indexed_gfx_data;
				//amount_of_frames_in_file=1;
				gfx_data_is_file=0;
			}



			int IndexInCachedTextureIDArray=-1;
			IndexInCachedTextureIDArray = gfx->IndexInCachedTextureIDArray;
			if(IndexInCachedTextureIDArray==-1)
			{
				//sprite filename wasnt loaded properly, throw error
				ERROR_set_error("sprite was not found in preloaded textures, fix this!\n");
			}


			//then figure out frame based on the gfx_index, should be very easy here because we have the sprite data sizes
			int frame=0;
			frame = gfx_index/(gfx->data_size_x*gfx->data_size_y);



			if(IndexInCachedTextureIDArray==-2)
			{
				//this means its a caption and it will have a unique texture every time

				//make new texture ID
				GLuint texture_id = HARDWARE_preload_sprite_texture_frame(gfx,frame,IndexInCachedTextureIDArray);

				sprite->texture_id = texture_id;
			}
			else
			{

				//if sprite isnt preloaded, load it
				//if it is a dynamic texture (text box, etc) load it again from internal data and overwrite the one thats there
				if(



					USED_preloaded_sprite_textures_USED[IndexInCachedTextureIDArray*8*8+frame]==0 //it hasnt been preloaded
					||
					gfx_data_is_file==0
				)
				{
					//load the frame and set the texture id
					sprite->texture_id = HARDWARE_preload_sprite_texture_frame(gfx,frame,IndexInCachedTextureIDArray);
				}


				if(glIsTexture(GLTex_preloaded_sprite_textures[IndexInCachedTextureIDArray*8*8+frame])==0)
				{
					ERROR_set_error("HARDWARE_update_sprite_texture: the texture was created but isnt a texture!\n");
				}

				if(USED_preloaded_sprite_textures_USED[IndexInCachedTextureIDArray*8*8+frame]==0)
				{

					ERROR_set_error("HARDWARE_update_sprite_texture: it wasn't marked as used!\n");
				}

				sprite->texture_id = GLTex_preloaded_sprite_textures[IndexInCachedTextureIDArray*8*8+frame];
			}

		}



}


//==========================================================================================================================
SPRITE* HARDWARE_create_sprite(GFX* gfx, int gfx_index, int layer, float scale, int screen_x, int screen_y, int alpha)//HARDWARE_CreateSpriteExFromGfx
{//==========================================================================================================================


		if(gfx==NULL)
		{
			ERROR_set_error("creating a sprite without graphics, this is bad! \n");
		}


		//create new sprite struct
		SPRITE* sprite = (SPRITE*)malloc(sizeof(SPRITE));

		//find available sprite slot (for z-ordering and rendering)
		int slot=-1;
		int x=0;
		for(x=0;x<256;x++)
		if(HARDWARE_sprites[x]==NULL){slot=x;x=256;break;}

		if(slot==-1)
		{
			ERROR_set_error("ran out of available sprite slots! \n");
		}



		sprite->layer=layer;
		sprite->scale=scale;
		sprite->screen_x=screen_x;
		sprite->screen_y=screen_y;
		sprite->gfx=gfx;

		sprite->texture_id=0;

		sprite->alpha=alpha;

		sprite->draw_size_x=0;
		sprite->draw_size_y=0;


		HARDWARE_update_sprite_texture(sprite, gfx_index);


		//the texture size isnt set until HARDWARE_update_sprite_texture calls HARDWARE_preload_sprite_texture_frame
		sprite->draw_size_x=gfx->content_size_x;
		sprite->draw_size_y=gfx->content_size_y;

		HARDWARE_sprites[slot]=sprite;


		return sprite;
}

//==========================================================================================================================
void HARDWARE_delete_sprite(SPRITE* sprite)//HARDWARE_DeleteSprite
{//==========================================================================================================================


		if(sprite==NULL)
		{
			ERROR_set_error("deleting a sprite twice somewhere, this is bad! \n");
		}

	//this deletes the sprite struct
		//check HARDWARE_sprites and remove it
		int x=0;
		for(x=0;x<256;x++)
			if(HARDWARE_sprites[x]==sprite)HARDWARE_sprites[x]=NULL;


		///should init all the data in the struct, i guess.

		///could check if the gfx texture is volatile and delete it here



		free(sprite);
}




///this should all be done by the npc vbl when it deletes and creates them
///special cases like the text box sprite movement should just set the sprite->screen_y;

//==========================================================================================================================
void HARDWARE_set_sprite_x(SPRITE* sprite, int screen_x)
{//==========================================================================================================================


	if(sprite==NULL){ERROR_set_error("moving a NULL sprite! \n");exit(2);}
		sprite->screen_x=screen_x;
}

//==========================================================================================================================
void HARDWARE_set_sprite_y(SPRITE* sprite, int screen_y)
{//==========================================================================================================================
	if(sprite==NULL){ERROR_set_error("moving a NULL sprite! \n");exit(2);}
	sprite->screen_y=screen_y;
}

//==========================================================================================================================
void HARDWARE_set_sprite_xy(SPRITE* sprite, int screen_x, int screen_y)
{//==========================================================================================================================
	if(sprite==NULL){ERROR_set_error("moving a NULL sprite! \n");exit(2);}
	sprite->screen_x=screen_x;
	sprite->screen_y=screen_y;

}

/*
//==========================================================================================================================
void HARDWARE_set_sprite_layer(SPRITE* sprite, int layer)
{//==========================================================================================================================


	///need to decide a limit on this for z-ordering? actually i might not have to, but is faster to only sort by a few layers

	sprite->layer=layer;
}

//==========================================================================================================================
void HARDWARE_set_sprite_scale(SPRITE* sprite, float scale)//HARDWARE_SetSpriteDblsize
{//==========================================================================================================================
	sprite->scale=scale;
}

//==========================================================================================================================
void HARDWARE_set_sprite_rotation(SPRITE* sprite, int rotset)//HARDWARE_SetSpriteRotEnable
{//==========================================================================================================================


}

//==========================================================================================================================
void HARDWARE_set_sprite_alpha(SPRITE* sprite, int alpha)//HARDWARE_SetSpriteMode
{//==========================================================================================================================

	///need to do this in the render function!

	sprite->alpha=alpha;
}
*/

/*
//==========================================================================================================================
void HARDWARE_create_rotation_set(int rotset, int zoomx, int zoomy)//HARDWARE_SetRotsetNoAngle
{//==========================================================================================================================


		//create global rotation set array. hold floating point value for zoom.
		rotation_set[rotset] = 1024.0f/((float)zoomx)/4.0f;



	//1024/512 = 2/4
	//1024/256 = 4/4


	//512 is 50%
	//256 is 100%
	//128 is 200%


}


//==========================================================================================================================
void HARDWARE_create_rotation_set_with_angle(int rotset, int angle, int zoomx, int zoomy)//HARDWARE_SetRotset
{//==========================================================================================================================

		//create global rotation set array. hold floating point value for zoom.
		rotation_set[rotset] = 1024.0f/((float)zoomx);

}*/


//==========================================================================================================================
void HARDWARE_init_gfx_data()
{//==========================================================================================================================


	//-----------------------------
	//load sprite palettes
	//-----------------------------

		GAME_original_SPRITE_PALETTE	= (int*)	HARDWARE_load_file("/sprite/globalspritepalette_SpritePalette.bin");
		GAME_hq2x_SPRITE_PALETTE	= (int*)	HARDWARE_load_file("/sprite/hq2xpalette_SpritePalette.bin");


		//-----------------------------
		//brighten palette
		//-----------------------------

		//HARDWARE_create_brightened_palette(GAME_original_SPRITE_PALETTE,(int*)&GAME_temp_SPRITE_PALETTE,2);


		//-----------------------------
		//enhance colors
		//-----------------------------
			int x=0;
			for(x=0;x<256;x++)
			{

				int r=(GAME_original_SPRITE_PALETTE[x]%32)*8;
				int g=((GAME_original_SPRITE_PALETTE[x]/32)%32)*8;
				int b=(((GAME_original_SPRITE_PALETTE[x]/32)/32)%32)*8;


				adjust_color(&r,&g,&b);

				HARDWARE_ORIGINAL_SPRITE_PALETTE_ENHANCED_RGB[x*3+0]=r;
				HARDWARE_ORIGINAL_SPRITE_PALETTE_ENHANCED_RGB[x*3+1]=g;
				HARDWARE_ORIGINAL_SPRITE_PALETTE_ENHANCED_RGB[x*3+2]=b;


				//int HARDWARE_ORIGINAL_SPRITE_PALETTE_ENHANCED_RGB[256*3];
				//int HARDWARE_HQ2X_SPRITE_PALETTE_ENHANCED_RGB[256*3];
			}

			for(x=0;x<256;x++)
			{

				int r=(GAME_hq2x_SPRITE_PALETTE[x]%32)*8;
				int g=((GAME_hq2x_SPRITE_PALETTE[x]/32)%32)*8;
				int b=(((GAME_hq2x_SPRITE_PALETTE[x]/32)/32)%32)*8;


				adjust_color(&r,&g,&b);

				HARDWARE_HQ2X_SPRITE_PALETTE_ENHANCED_RGB[x*3+0]=r;
				HARDWARE_HQ2X_SPRITE_PALETTE_ENHANCED_RGB[x*3+1]=g;
				HARDWARE_HQ2X_SPRITE_PALETTE_ENHANCED_RGB[x*3+2]=b;


				//int HARDWARE_ORIGINAL_SPRITE_PALETTE_ENHANCED_RGB[256*3];
				//int HARDWARE_HQ2X_SPRITE_PALETTE_ENHANCED_RGB[256*3];
			}

		//-----------------------------
		//set color 1 to black
		//-----------------------------
		HARDWARE_ORIGINAL_SPRITE_PALETTE_ENHANCED_RGB[1*3+0]=0;
		HARDWARE_ORIGINAL_SPRITE_PALETTE_ENHANCED_RGB[1*3+1]=0;
		HARDWARE_ORIGINAL_SPRITE_PALETTE_ENHANCED_RGB[1*3+2]=0;


		//color 16 green
		HARDWARE_ORIGINAL_SPRITE_PALETTE_ENHANCED_RGB[16*3+0]=0;
		HARDWARE_ORIGINAL_SPRITE_PALETTE_ENHANCED_RGB[16*3+1]=255;
		HARDWARE_ORIGINAL_SPRITE_PALETTE_ENHANCED_RGB[16*3+2]=0;

		//color 22 purple
		HARDWARE_ORIGINAL_SPRITE_PALETTE_ENHANCED_RGB[22*3+0]=170;//#8500ff
		HARDWARE_ORIGINAL_SPRITE_PALETTE_ENHANCED_RGB[22*3+1]=0;
		HARDWARE_ORIGINAL_SPRITE_PALETTE_ENHANCED_RGB[22*3+2]=220;

		//255 for hq2x for some reason
		HARDWARE_HQ2X_SPRITE_PALETTE_ENHANCED_RGB[255*3+0]=0;
		HARDWARE_HQ2X_SPRITE_PALETTE_ENHANCED_RGB[255*3+1]=0;
		HARDWARE_HQ2X_SPRITE_PALETTE_ENHANCED_RGB[255*3+2]=0;

		//GAME_temp_SPRITE_PALETTE[1]=HARDWARE_RGB(0,0,0);



		//set generic sprites to gray
		///this doesnt work because hq2x, random colors are also broken
	/*
		GAME_temp_SPRITE_PALETTE[GENERIChaireyescolors[0]]		= HARDWARE_RGB(2,2,2);//hair
		GAME_temp_SPRITE_PALETTE[GENERIChaireyescolors[1]]		= HARDWARE_RGB(5,5,5);//hair
		GAME_temp_SPRITE_PALETTE[GENERIChaireyescolors[2]]		= HARDWARE_RGB(9,9,9);//hair
		GAME_temp_SPRITE_PALETTE[GENERIChaireyescolors[3]]		= HARDWARE_RGB(11,11,11);//hair

		GAME_temp_SPRITE_PALETTE[GENERIChaireyescolors[4]]		= HARDWARE_RGB(1,1,1);//eyes

		GAME_temp_SPRITE_PALETTE[GENERICshirtpantsshoescolors[0]] = HARDWARE_RGB(10,10,10);//shirt
		GAME_temp_SPRITE_PALETTE[GENERICshirtpantsshoescolors[1]] = HARDWARE_RGB(15,15,15);//shirt
		GAME_temp_SPRITE_PALETTE[GENERICshirtpantsshoescolors[2]] = HARDWARE_RGB(20,20,20);//shirt
		GAME_temp_SPRITE_PALETTE[GENERICshirtpantsshoescolors[3]] = HARDWARE_RGB(25,25,25);//shirt

		GAME_temp_SPRITE_PALETTE[GENERICshirtpantsshoescolors[4]] = HARDWARE_RGB(3,3,3);//pants
		GAME_temp_SPRITE_PALETTE[GENERICshirtpantsshoescolors[5]] = HARDWARE_RGB(7,7,7);//pants
		GAME_temp_SPRITE_PALETTE[GENERICshirtpantsshoescolors[6]] = HARDWARE_RGB(10,10,10);//pants

		GAME_temp_SPRITE_PALETTE[GENERICshirtpantsshoescolors[7]] = HARDWARE_RGB(1,1,1);//shoes
		GAME_temp_SPRITE_PALETTE[GENERICshirtpantsshoescolors[8]] = HARDWARE_RGB(3,3,3);//shoes
		GAME_temp_SPRITE_PALETTE[GENERICshirtpantsshoescolors[9]] = HARDWARE_RGB(5,5,5);//shoes
	*/

		//HARDWARE_load_sprite_palette(0,(int*)&GAME_temp_SPRITE_PALETTE);


	//-----------------------------
	//init and preload gfx datas
	//-----------------------------

	//int SHADOW=1;
	int NO_SHADOW=0;

	//int DONT_PRELOAD=0;
	int PRELOAD=1;


	//void HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(char* filename_string, char* gfx_filename,int sprite_data_size_x, int sprite_data_size_y, int shadow, int preload)

	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(TEXT_GFX[0],"TEXT",64,64,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(TEXT_GFX[1],"TEXT",64,64,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(TEXTANSWER_GFX,"TEXTANSWER",64,32,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(TEXTSPRITEWINDOW_GFX[0],"TEXTSPRITEWINDOW",32,64,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(TEXTSPRITEWINDOW_GFX[1],"TEXTSPRITEWINDOW",32,64,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(PINGPADDLE_GFX,"PINGPADDLE",8,32,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(PINGBALL_GFX,"PINGBALL",8,8,NO_SHADOW,0);




	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(TEXT_button_icon_GFX,"/miscgfx/text_button_icon.bin",8,8,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(TEXT_button_icon_underneath_GFX,"/miscgfx/text_button_icon_underneath.bin",8,8,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(TEXTANSWER_cursor_GFX,"/miscgfx/answercursor.bin",8,8,NO_SHADOW,0);


	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(RAMIO_boba_gfx_GFX,"/minigame/ramio/ramiobob_Sprite.bin",16,16,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(RAMIO_moneyblock_gfx_GFX,"/minigame/ramio/ramiomoneyblock_Sprite.bin",16,16,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(RAMIO_money_gfx_GFX,"/minigame/ramio/ramiomoney_Sprite.bin",16,16,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(RAMIO_brickblock_gfx_GFX,"/minigame/ramio/ramiobrick_Sprite.bin",16,16,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(RAMIO_guy_gfx_GFX,"/minigame/ramio/ramio_Sprite.bin",16,32,NO_SHADOW,0);


	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(TEXT_keyboard_GFX,"/miscgfx/text_keyboard.bin",64,64,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(TEXT_keyboard_caps_GFX,"/miscgfx/text_keyboard_caps.bin",64,64,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(TEXT_numpad_GFX,"/miscgfx/text_numpad.bin",64,64,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(TEXT_keypressed_icon_GFX,"/miscgfx/text_keypressed_icon.bin",16,16,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(LETTERBOX_sprite_GFX,"/miscgfx/letterbox_sprite.bin",64,64,NO_SHADOW,0);
	//HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(shadow_GFX,"/miscgfx/shadow.bin");
	//HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(click_GFX,"/miscgfx/click.bin",8,8,NO_SHADOW,0);





	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_yuu,"/sprite/hq2xyuu_Sprite.bin",32,64,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_yuurunning,"/sprite/hq2xyuurunning_Sprite.bin",32,64,1,PRELOAD);

	PRELOAD=0;

	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_youngyuu,"/sprite/hq2xyoungyuu_Sprite.bin",32,64,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_youngyuurunning,"/sprite/hq2xyoungyuurunning_Sprite.bin",32,64,1,PRELOAD);


	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_youngfriend,"/sprite/hq2xyoungfriend_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_youngbrother,"/sprite/hq2xyoungbrother_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_baby,"/sprite/hq2xbaby_Sprite.bin",32,64,1,0);


	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_youngdad,"/sprite/hq2xyoungdad_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_youngmom,"/sprite/hq2xyoungmom_Sprite.bin",32,80,1,0);


	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_babyredhair,"/sprite/hq2xbabyredhair_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_brother,"/sprite/hq2xbrother_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_littlebrother,"/sprite/hq2xlittlebrother_Sprite.bin",32,64,1,0);


	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_bob,"/sprite/hq2xbob_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_bobscary,"/sprite/hq2xbobscary_Sprite.bin",32,80,1,0);

	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_dad,"/sprite/hq2xdad_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_mom,"/sprite/hq2xmom_Sprite.bin",32,80,1,0);

	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_CAR_car,"/sprite/hq2xcar_Sprite.bin",128,128,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_CAR_truck,"/sprite/hq2xtruck_Sprite.bin",128,128,1,0);

	//HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(getmycolorsright_GFX,"/sprite/getmycolorsright_Sprite.bin");
	//HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GENERIChaireyescolors_GFX,"/sprite/GENERIChaireyescolors_Sprite.bin");
	//HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GENERICshirtpantsshoescolors_GFX,"/sprite/GENERICshirtpantsshoescolors_Sprite.bin");
	//HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GENERICskincolors_GFX,"/sprite/GENERICskincolors_Sprite.bin");
	//HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GENERICcarcolors_GFX,"/sprite/GENERICcarcolors_Sprite.bin");

	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_MISC_dinner,"/sprite/dinner_Sprite.bin",16,16,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_MISC_plate,"/sprite/plate_Sprite.bin",16,16,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_MISC_lunchbag,"/sprite/lunchbag_Sprite.bin",16,16,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_MISC_coffeeandnewspaper,"/sprite/coffeeandnewspaper_Sprite.bin",16,16,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_MISC_tv3x2videogame,"/sprite/tv3x2videogame_Sprite.bin",32,16,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_MISC_sparks,"/sprite/sparks_Sprite.bin",16,16,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_MISC_electricshock,"/sprite/electricshock_Sprite.bin",64,64,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_MISC_batteries,"/sprite/batteries_Sprite.bin",16,16,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_MISC_pingcontroller,"/sprite/pingcontroller_Sprite.bin",32,64,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_MISC_tv2x1mesflash,"/sprite/tv2x1mesflash_Sprite.bin",16,8,NO_SHADOW,0);

	//HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(spotlight_GFX,"/sprite/spotlight_Sprite.bin");



	//kids are all 16x32 (hq2x size is 32x64)
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_notfriend,"/sprite/hq2xfriend_Sprite.bin",32,64,1,0);//sprite filename is friend, not notfriend
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_youngsister,"/sprite/hq2xyoungsister_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_sister,"/sprite/hq2xsister_Sprite.bin",32,64,1,0);





	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_bully,"/sprite/hq2xbully_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_skaterboy,"/sprite/hq2xskaterboy_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_bladerboy,"/sprite/hq2xbladerboy_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_gothboy,"/sprite/hq2xgothboy_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_punkboy,"/sprite/hq2xpunkboy_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_emoboy,"/sprite/hq2xemoboy_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_greaserboy,"/sprite/hq2xgreaserboy_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_jockboy,"/sprite/hq2xjockboy_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_pudgyboy,"/sprite/hq2xpudgyboy_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_nerdboy,"/sprite/hq2xnerdboy_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_thugboy,"/sprite/hq2xthugboy_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_conceitedboy,"/sprite/hq2xconceitedboy_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_uglyboy,"/sprite/hq2xuglyboy_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_scrawnyboy,"/sprite/hq2xscrawnyboy_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_uglygirl,"/sprite/hq2xuglygirl_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_pudgygirl,"/sprite/hq2xpudgygirl_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_gothgirl,"/sprite/hq2xgothgirl_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_nerdgirl,"/sprite/hq2xnerdgirl_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_conceitedgirl,"/sprite/hq2xconceitedgirl_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_punkgirl,"/sprite/hq2xpunkgirl_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_emogirl,"/sprite/hq2xemogirl_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_skatergirl,"/sprite/hq2xskatergirl_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_jockgirl,"/sprite/hq2xjockgirl_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_paperboy,"/sprite/hq2xpaperboy_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_foreignboy,"/sprite/hq2xforeignboy_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_japaneseboy,"/sprite/hq2xjapaneseboy_Sprite.bin",32,64,1,0);

	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ANIMAL_cat,"/sprite/hq2xcat_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ANIMAL_puppy,"/sprite/hq2xpuppy_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ANIMAL_skunk,"/sprite/hq2xskunk_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ANIMAL_bird,"/sprite/hq2xbird_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ANIMAL_turtle,"/sprite/hq2xturtle_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ANIMAL_hamster,"/sprite/hq2xhamster_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ANIMAL_squirrel,"/sprite/hq2xsquirrel_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ANIMAL_rat,"/sprite/hq2xrat_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ANIMAL_ant,"/sprite/hq2xant_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ANIMAL_fly,"/sprite/hq2xfly_Sprite.bin",32,64,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ANIMAL_snake,"/sprite/hq2xsnake_Sprite.bin",32,64,1,0);

	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_GENERICboy1,"/sprite/hq2xGENERICboy1_Sprite.bin",32,64,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_GENERICboy2,"/sprite/hq2xGENERICboy2_Sprite.bin",32,64,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_GENERICboy3,"/sprite/hq2xGENERICboy3_Sprite.bin",32,64,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_GENERICboy4,"/sprite/hq2xGENERICboy4_Sprite.bin",32,64,1,PRELOAD);
	//HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GENERICboy5_GFX,"/sprite/hq2xGENERICboy5_Sprite.bin",32,64,1,PRELOAD);//doesnt exist
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_GENERICgirl1,"/sprite/hq2xGENERICgirl1_Sprite.bin",32,64,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_GENERICgirl2,"/sprite/hq2xGENERICgirl2_Sprite.bin",32,64,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_GENERICgirl3,"/sprite/hq2xGENERICgirl3_Sprite.bin",32,64,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_GENERICgirl4,"/sprite/hq2xGENERICgirl4_Sprite.bin",32,64,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_GENERICgirl5,"/sprite/hq2xGENERICgirl5_Sprite.bin",32,64,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_GENERICgirl6,"/sprite/hq2xGENERICgirl6_Sprite.bin",32,64,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_GENERIClittleboy1,"/sprite/hq2xGENERIClittleboy1_Sprite.bin",32,64,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_GENERIClittleboy2,"/sprite/hq2xGENERIClittleboy2_Sprite.bin",32,64,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_GENERIClittleboy3,"/sprite/hq2xGENERIClittleboy3_Sprite.bin",32,64,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_GENERICpudgylittleboy,"/sprite/hq2xGENERICpudgylittleboy_Sprite.bin",32,64,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_GENERIClittlegirl1,"/sprite/hq2xGENERIClittlegirl1_Sprite.bin",32,64,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_GENERIClittlegirl2,"/sprite/hq2xGENERIClittlegirl2_Sprite.bin",32,64,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_KID_GENERIClittlegirl3,"/sprite/hq2xGENERIClittlegirl3_Sprite.bin",32,64,1,PRELOAD);


	//adults are all 16x40 (32x80 hq2x)
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_friendsdad,"/sprite/hq2xfriendsdad_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_friendsmom,"/sprite/hq2xfriendsmom_Sprite.bin",32,80,1,0);

	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_crazylady,"/sprite/hq2xcrazylady_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_librarian,"/sprite/hq2xlibrarian_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_secretary,"/sprite/hq2xsecretary_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_nurse,"/sprite/hq2xnurse_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_hallmonitor,"/sprite/hq2xhallmonitor_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_principal,"/sprite/hq2xprincipal_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_janitor,"/sprite/hq2xjanitor_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_momo,"/sprite/hq2xmomo_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_oldmomo,"/sprite/hq2xoldmomo_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_sleazyunclebob,"/sprite/hq2xsleazyunclebob_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_givenupteacher,"/sprite/hq2xgivenupteacher_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_maleangryteacher,"/sprite/hq2xmaleangryteacher_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_malesadteacher,"/sprite/hq2xmalesadteacher_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_femaleangryteacher,"/sprite/hq2xfemaleangryteacher_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_femalesadteacher,"/sprite/hq2xfemalesadteacher_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_grannycluelessteacher,"/sprite/hq2xgrannycluelessteacher_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_pcteacher,"/sprite/hq2xpcteacher_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_crossingguard,"/sprite/hq2xcrossingguard_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_mailman,"/sprite/hq2xmailman_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_doortodoorsalesman,"/sprite/hq2xdoortodoorsalesman_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_firefighter,"/sprite/hq2xfirefighter_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_securityguard,"/sprite/hq2xsecurityguard_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_townsheriff,"/sprite/hq2xtownsheriff_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_policeofficermale,"/sprite/hq2xpoliceofficermale_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_policeofficerfemale,"/sprite/hq2xpoliceofficerfemale_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_swat,"/sprite/hq2xswat_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_privateeye,"/sprite/hq2xprivateeye_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_cia,"/sprite/hq2xcia_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_newsreportermale,"/sprite/hq2xnewsreportermale_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_newsreporterfemale,"/sprite/hq2xnewsreporterfemale_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_cameraguy,"/sprite/hq2xcameraguy_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_familydoctordentist,"/sprite/hq2xfamilydoctordentist_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_surgeon,"/sprite/hq2xsurgeon_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_hospitaldirector,"/sprite/hq2xhospitaldirector_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_paramedic,"/sprite/hq2xparamedic_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_psychiatrist,"/sprite/hq2xpsychiatrist_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_madscientist,"/sprite/hq2xmadscientist_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_professor,"/sprite/hq2xprofessor_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_dogwalker,"/sprite/hq2xdogwalker_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_spandexjogger,"/sprite/hq2xspandexjogger_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_shoppinglady,"/sprite/hq2xshoppinglady_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_farmer,"/sprite/hq2xfarmer_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_deliicecreamman,"/sprite/hq2xdeliicecreamman_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_hotdogvendor,"/sprite/hq2xhotdogvendor_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_trafficcharityguy,"/sprite/hq2xtrafficcharityguy_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_magazinevendor,"/sprite/hq2xmagazinevendor_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_constructionworker,"/sprite/hq2xconstructionworker_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_businessguy,"/sprite/hq2xbusinessguy_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_businesswoman,"/sprite/hq2xbusinesswoman_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_richnerdguy,"/sprite/hq2xrichnerdguy_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_officeworkermale,"/sprite/hq2xofficeworkermale_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_officeworkerfemale,"/sprite/hq2xofficeworkerfemale_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_skinnymeekcoder,"/sprite/hq2xskinnymeekcoder_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_fatmeekcoder,"/sprite/hq2xfatmeekcoder_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_wealthylady,"/sprite/hq2xwealthylady_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_bigwig,"/sprite/hq2xbigwig_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_wealthygirl,"/sprite/hq2xwealthygirl_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_wealthyguy,"/sprite/hq2xwealthyguy_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_mayor,"/sprite/hq2xmayor_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_photographer,"/sprite/hq2xphotographer_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_pizzaguy,"/sprite/hq2xpizzaguy_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_mime,"/sprite/hq2xmime_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_guitarguy,"/sprite/hq2xguitarguy_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_magician,"/sprite/hq2xmagician_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_clown,"/sprite/hq2xclown_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_sandwichadguy,"/sprite/hq2xsandwichadguy_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_flyerguy,"/sprite/hq2xflyerguy_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_picketer,"/sprite/hq2xpicketer_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_samurai,"/sprite/hq2xsamurai_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_ninja,"/sprite/hq2xninja_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_karateguy,"/sprite/hq2xkarateguy_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_kungfumaster,"/sprite/hq2xkungfumaster_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_wiseman,"/sprite/hq2xwiseman_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_hermit,"/sprite/hq2xhermit_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_tinfoilhatman,"/sprite/hq2xtinfoilhatman_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_monk,"/sprite/hq2xmonk_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_shadywatchdealer,"/sprite/hq2xshadywatchdealer_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_pickpocket,"/sprite/hq2xpickpocket_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_prothief,"/sprite/hq2xprothief_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_pawnshopguy,"/sprite/hq2xpawnshopguy_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_mafiaguy,"/sprite/hq2xmafiaguy_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_crimeboss,"/sprite/hq2xcrimeboss_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_biker,"/sprite/hq2xbiker_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_dealer,"/sprite/hq2xdealer_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_bankrobber,"/sprite/hq2xbankrobber_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_convict,"/sprite/hq2xconvict_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_escapedconvict,"/sprite/hq2xescapedconvict_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_prostitute,"/sprite/hq2xprostitute_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_hustler,"/sprite/hq2xhustler_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_dancer,"/sprite/hq2xdancer_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_thug,"/sprite/hq2xthug_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_mechanic,"/sprite/hq2xmechanic_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_diseased,"/sprite/hq2xdiseased_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_crippled,"/sprite/hq2xcrippled_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_hobo,"/sprite/hq2xhobo_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_beggar,"/sprite/hq2xbeggar_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_terrorist,"/sprite/hq2xterrorist_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_cultenlister,"/sprite/hq2xcultenlister_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_alien,"/sprite/hq2xalien_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_ghost,"/sprite/hq2xghost_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_superhero,"/sprite/hq2xsuperhero_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_timetraveler,"/sprite/hq2xtimetraveler_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_robot,"/sprite/hq2xrobot_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_bubbleheadcyborg,"/sprite/hq2xbubbleheadcyborg_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_quack,"/sprite/hq2xquack_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_army,"/sprite/hq2xarmy_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_transvestite,"/sprite/hq2xtransvestite_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_astronaut,"/sprite/hq2xastronaut_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_buddy,"/sprite/hq2xbuddy_Sprite.bin",32,80,1,0);

	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_islandhermit,"/sprite/hq2xislandhermit_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_president,"/sprite/hq2xpresident_Sprite.bin",32,80,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_contortionistbountyhunter,"/sprite/hq2xcontortionistbountyhunter_Sprite.bin",32,80,1,0);


	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_GENERICsuitguy,"/sprite/hq2xGENERICsuitguy_Sprite.bin",32,80,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_GENERICbaldsuitguy,"/sprite/hq2xGENERICbaldsuitguy_Sprite.bin",32,80,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_GENERICbaldingmanashirt,"/sprite/hq2xGENERICbaldingmanashirt_Sprite.bin",32,80,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_GENERICbaldingmantshirt,"/sprite/hq2xGENERICbaldingmantshirt_Sprite.bin",32,80,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_GENERICmanlongsleeves,"/sprite/hq2xGENERICmanlongsleeves_Sprite.bin",32,80,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_GENERICbeardbaldingtshirt,"/sprite/hq2xGENERICbeardbaldingtshirt_Sprite.bin",32,80,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_GENERICwomanbobcut,"/sprite/hq2xGENERICwomanbobcut_Sprite.bin",32,80,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_GENERICwomanbun,"/sprite/hq2xGENERICwomanbun_Sprite.bin",32,80,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_GENERICwomanlonghair,"/sprite/hq2xGENERICwomanlonghair_Sprite.bin",32,80,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_GENERICwomanfancyhairblouse,"/sprite/hq2xGENERICwomanfancyhairblouse_Sprite.bin",32,80,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_GENERICmanbeardbaldingtshirt2,"/sprite/hq2xGENERICmanbeardbaldingtshirt2_Sprite.bin",32,80,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_GENERICmangrayhairsuit,"/sprite/hq2xGENERICmangrayhairsuit_Sprite.bin",32,80,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_GENERICmangrayhairbigheadsuit,"/sprite/hq2xGENERICmangrayhairbigheadsuit_Sprite.bin",32,80,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_GENERICwomangrayhairdress,"/sprite/hq2xGENERICwomangrayhairdress_Sprite.bin",32,80,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_GENERICwomangrayhairmakeupdress,"/sprite/hq2xGENERICwomangrayhairmakeupdress_Sprite.bin",32,80,1,PRELOAD);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ADULT_GENERICwomanwhitehair,"/sprite/hq2xGENERICwomanwhitehair_Sprite.bin",32,80,1,PRELOAD);

	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_CAR_motorcycle,"/sprite/hq2xmotorcycle_Sprite.bin",128,128,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_CAR_policecar,"/sprite/hq2xpolicecar_Sprite.bin",128,128,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_CAR_mafiacar,"/sprite/hq2xmafiacar_Sprite.bin",128,128,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_CAR_van,"/sprite/hq2xvan_Sprite.bin",128,128,1,0);

	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_CAR_suv,"/sprite/hq2xsuv_Sprite.bin",128,128,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_CAR_ferrari,"/sprite/hq2xferrari_Sprite.bin",128,128,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_CAR_skycar,"/sprite/hq2xskycar_Sprite.bin",128,128,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_CAR_tvvan,"/sprite/hq2xtvvan_Sprite.bin",128,128,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_CAR_ambulance,"/sprite/hq2xambulance_Sprite.bin",128,128,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_CAR_tank,"/sprite/hq2xtank_Sprite.bin",128,128,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_CAR_icecreamtruck,"/sprite/hq2xicecreamtruck_Sprite.bin",128,128,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_CAR_helicopter,"/sprite/hq2xhelicopter_Sprite.bin",128,128,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_CAR_minivan,"/sprite/hq2xminivan_Sprite.bin",128,128,1,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_CAR_ufo,"/sprite/hq2xufo_Sprite.bin",128,128,1,0);



	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_ANIMAL_bigdog,"/sprite/bigdog_Sprite.bin",64,64,1,0);

	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_MISC_shoppingcart,"/sprite/shoppingcart_Sprite.bin",64,64,1,0);//? check size
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_MISC_lawnmower,"/sprite/lawnmower_Sprite.bin",64,64,1,0);//? check size

	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_CAR_bicycle,"/sprite/bicycle_Sprite.bin",64,64,1,0);
	//HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(amrposter_GFX,"/sprite/amrposter_Sprite.bin");

	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_lawnchairfaceright,"/sprite/lawnchairfaceright_Sprite.bin",32,32,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_lawnchairfaceleft,"/sprite/lawnchairfaceleft_Sprite.bin",32,32,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_lawnchairfacedown,"/sprite/lawnchairfacedown_Sprite.bin",32,32,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_lawnbenchfacedown,"/sprite/lawnbenchfacedown_Sprite.bin",64,32,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_gardenhosecoil,"/sprite/gardenhosecoil_Sprite.bin",32,32,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_grillfaceleft,"/sprite/grillfaceleft_Sprite.bin",32,64,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_schoolxingsign,"/sprite/schoolxingsign_Sprite.bin",32,32,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_stopsignfaceup,"/sprite/stopsignfaceup_Sprite.bin",32,32,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_stopsignfacedown,"/sprite/stopsignfacedown_Sprite.bin",32,32,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_schoolflag,"/sprite/schoolflag_Sprite.bin",32,32,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_stainedglasswindow,"/sprite/stainedglasswindow_Sprite.bin",32,32,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_disorderofbobsign,"/sprite/disorderofbobsign_Sprite.bin",64,64,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_trafficlightfaceup,"/sprite/trafficlightfaceup_Sprite.bin",32,32,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_pizzasigndoorwide,"/sprite/pizzasigndoorwide_Sprite.bin",64,32,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_pizzasignwindow1,"/sprite/pizzasignwindow1_Sprite.bin",32,32,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_pizzasignwindow2,"/sprite/pizzasignwindow2_Sprite.bin",32,32,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_pizzasignwindow3,"/sprite/pizzasignwindow3_Sprite.bin",32,32,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_coffeecafesign,"/sprite/coffeecafesign_Sprite.bin",64,32,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_departmentsign,"/sprite/departmentsign_Sprite.bin",64,16,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_storedeptsign,"/sprite/storedeptsign_Sprite.bin",32,16,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_gasstationsign,"/sprite/gasstationsign_Sprite.bin",64,16,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_clubhouseboarded,"/sprite/clubhouseboarded_Sprite.bin",16,16,NO_SHADOW,0);//? check size
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_groceryexpresssignstacked,"/sprite/groceryexpresssignstacked_Sprite.bin",64,32,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_grocerysign,"/sprite/grocerysign_Sprite.bin",64,16,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_expresssign,"/sprite/expresssign_Sprite.bin",64,16,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_tacoburgersign,"/sprite/tacoburgersign_Sprite.bin",64,16,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_gamestoresign,"/sprite/gamestoresign_Sprite.bin",64,8,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_electronicssign,"/sprite/electronicssign_Sprite.bin",64,8,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_clinicsign,"/sprite/clinicsign_Sprite.bin",64,16,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_beautysalonstacked,"/sprite/beautysalonstacked_Sprite.bin",32,16,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_beautysalonsign,"/sprite/beautysalonsign_Sprite.bin",64,8,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_tanningsign,"/sprite/tanningsign_Sprite.bin",32,8,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_nailssign,"/sprite/nailssign_Sprite.bin",16,8,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_hairsign,"/sprite/hairsign_Sprite.bin",16,8,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_musicstoresign,"/sprite/musicstoresign_Sprite.bin",64,8,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_cdssign,"/sprite/cdssign_Sprite.bin",16,8,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_recordssign,"/sprite/recordssign_Sprite.bin",32,8,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_pets4lessdoorsign,"/sprite/pets4lessdoorsign_Sprite.bin",32,16,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_cutesign,"/sprite/cutesign_Sprite.bin",32,8,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_cheapsign,"/sprite/cheapsign_Sprite.bin",32,8,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_arcadesign,"/sprite/arcadesign_Sprite.bin",32,8,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_videorentsign,"/sprite/videorentsign_Sprite.bin",32,8,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_videorentsignstacked,"/sprite/videorentsignstacked_Sprite.bin",16,16,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_movietheatresign,"/sprite/movietheatresign_Sprite.bin",64,8,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_movietheatresignstacked,"/sprite/movietheatresignstacked_Sprite.bin",32,16,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_bookstoresign,"/sprite/bookstoresign_Sprite.bin",64,8,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_schoolsign,"/sprite/schoolsign_Sprite.bin",32,8,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_city50milesstreetsign,"/sprite/city50milesstreetsign_Sprite.bin",64,32,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_townstreetsign,"/sprite/townstreetsign_Sprite.bin",64,16,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_OUTSIDE_suburblanesign,"/sprite/suburblanesign_Sprite.bin",64,16,NO_SHADOW,0);




	//HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(mrcart_GFX,"/sprite/mrcart_Sprite.bin");

	//HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(dogwalk1sprite_GFX,"/sprite/dogwalk1sprite_Sprite.bin");
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_MISC_drums,"/sprite/drums_Sprite.bin",64,64,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_MISC_fountainwater,"/sprite/fountainwater_Sprite.bin",64,64,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_MISC_golfball,"/sprite/golfball_Sprite.bin",8,8,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_MISC_golfclub,"/sprite/golfclub_Sprite.bin",16,32,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_MISC_museumsheet,"/sprite/museumsheet_Sprite.bin",64,64,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_MISC_jewelsparkle,"/sprite/jewelsparkle_Sprite.bin",16,16,NO_SHADOW,0);
	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_MISC_bighead,"/sprite/bighead_Sprite.bin",64,64,NO_SHADOW,0);

	HARDWARE_set_sprite_texture_filename_and_maybe_preload_texture(GFX_MISC_bigscreen_scanlines,"/miscgfx/bigscreen_scanlines.bin",240,160,NO_SHADOW,0);





}
