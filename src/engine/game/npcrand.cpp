

#include "../../main.h"
//#include "npcrand.h"


int CROWDSIZE=30;



//=========================================================================================================================
void NPC_random_update_gfx(NPC** npcpp,int gfx_index)
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_random_update_gfx()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_random_update_gfx()");return;}
	NPC* npc = *npcpp;

	//make array size of sprite

	if(npc->sprite!=NULL)
	{
		if(gfx_index==0);

		//int c;
		//int x,y;

		//for(c=0;c<npc->data_size_x*npc->data_size_y;c++)
		//{
		//for(y=0;y<npc->size_y;y++)
		//{
			//for(x=0;x<npc->size_x;x++)
			//{
				//c=((y/8)*(npc->data_size_x/8)*64)+((y%8)*8)+((x/8)*64)+(x%8);

				/*int color = npc->gfx_filename[c+gfx_index];

				//hair
				if	   (color==GENERIChaireyescolors[0])color = GENERIChaireyescolors[0+8*npc->randomcolorset[0]];//r(7)+1
				else if(color==GENERIChaireyescolors[1])color = GENERIChaireyescolors[1+8*npc->randomcolorset[0]];
				else if(color==GENERIChaireyescolors[2])color = GENERIChaireyescolors[2+8*npc->randomcolorset[0]];
				else if(color==GENERIChaireyescolors[3])color = GENERIChaireyescolors[3+8*npc->randomcolorset[0]];
				//blank
				//eyes
				else if(color==GENERIChaireyescolors[4])color = GENERIChaireyescolors[4+8*npc->randomcolorset[1]];//r(6)+1
				//skin
				else if(color==GENERICskincolors[0])color = GENERICskincolors[0+8*npc->randomcolorset[2]];//r(6)+1
				else if(color==GENERICskincolors[1])color = GENERICskincolors[1+8*npc->randomcolorset[2]];
				else if(color==GENERICskincolors[2])color = GENERICskincolors[2+8*npc->randomcolorset[2]];
				else if(color==GENERICskincolors[3])color = GENERICskincolors[3+8*npc->randomcolorset[2]];
				else if(color==GENERICskincolors[4])color = GENERICskincolors[4+8*npc->randomcolorset[2]];
				else if(color==GENERICskincolors[5])color = GENERICskincolors[5+8*npc->randomcolorset[2]];

				//shirt
				else if(color==GENERICshirtpantsshoescolors[0])color = GENERICshirtpantsshoescolors[2+0+((npc->randomcolorset[3]/7)*3)+8*((npc->randomcolorset[3]%7)+1)];//r(14)
				else if(color==GENERICshirtpantsshoescolors[1])color = GENERICshirtpantsshoescolors[2+1+((npc->randomcolorset[3]/7)*3)+8*((npc->randomcolorset[3]%7)+1)];
				else if(color==GENERICshirtpantsshoescolors[2])color = GENERICshirtpantsshoescolors[2+2+((npc->randomcolorset[3]/7)*3)+8*((npc->randomcolorset[3]%7)+1)];
				else if(color==GENERICshirtpantsshoescolors[3])color = GENERICshirtpantsshoescolors[2+3+((npc->randomcolorset[3]/7)*3)+8*((npc->randomcolorset[3]%7)+1)];

				//pants
				else if(color==GENERICshirtpantsshoescolors[4])color = GENERICshirtpantsshoescolors[2+4+((npc->randomcolorset[4]/7)*3)+8*((npc->randomcolorset[4]%7)+1)];
				else if(color==GENERICshirtpantsshoescolors[5])color = GENERICshirtpantsshoescolors[2+5+((npc->randomcolorset[4]/7)*3)+8*((npc->randomcolorset[4]%7)+1)];
				else if(color==GENERICshirtpantsshoescolors[6])color = GENERICshirtpantsshoescolors[2+6+((npc->randomcolorset[4]/7)*3)+8*((npc->randomcolorset[4]%7)+1)];
				//blank
				//shoes
				else if(color==GENERICshirtpantsshoescolors[7])color = GENERICshirtpantsshoescolors[2+7+((npc->randomcolorset[5]/7)*3)+8*((npc->randomcolorset[5]%7)+1)];
				else if(color==GENERICshirtpantsshoescolors[8])color = GENERICshirtpantsshoescolors[2+8+((npc->randomcolorset[5]/7)*3)+8*((npc->randomcolorset[5]%7)+1)];
				else if(color==GENERICshirtpantsshoescolors[9])color = GENERICshirtpantsshoescolors[2+9+((npc->randomcolorset[5]/7)*3)+8*((npc->randomcolorset[5]%7)+1)];

				randomtempsprite[c]= color;*/

			//}
		//}

		//DMA_Copy(((int*)&tempsprite),(void*)(SPRITE_GFX1 + (0x200000 *	(1)) + ((npc->gfx_slot) << NUMBER_DECAL)),(used_mem[1][npc->gfx_slot] << (MEM_DECAL+1)),DMA_16NOW);
		//DMA_Copy(((int*)&tempsprite),(void*)(SPRITE_GFX1 + (0x200000 *	(0)) + ((npc->gfx_slot_touchmap) << NUMBER_DECAL)),(used_mem[0][npc->gfx_slot_touchmap] << (MEM_DECAL+1)),DMA_16NOW);
/*
		int m=0;
		int *location;

		if(npc->gfx_slot!=-1)
		{
			location = (void*)(SPRITE_GFX1 + (0x200000 *	(1)) + ((npc->gfx_slot) << NUMBER_DECAL));

			for(m=0;m<(number_of_used_vram_blocks[1][npc->gfx_slot] << (MEM_DECAL+1));m++)
				location[m]=(int)((randomtempsprite[m*2])+(randomtempsprite[(m*2)+1]<<8));
		}

		if(npc->gfx_slot_touchmap!=-1)
		{
			location = (void*)(SPRITE_GFX1 + (0x200000 *	(0)) + ((npc->gfx_slot_touchmap) << NUMBER_DECAL));

			for(m=0;m<(number_of_used_vram_blocks[0][npc->gfx_slot_touchmap] << (MEM_DECAL+1));m++)
				location[m]=(int)((randomtempsprite[m*2])+(randomtempsprite[(m*2)+1]<<8));
		}

 */
	}
}

//=========================================================================================================================
void NPC_create_random_npc_xy_feet(NPC** npcpp, GFX* gfx_struct,int size_x,int size_y,int x,int y) // SIZE X AND Y ARE ACTUAL NPC HEIGHT AND WIDTH NOT SPRITE SIZE,X AND Y ARE FEET PLACEMENT
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_create_random_npc_xy_feet()");return;}




	NPC_create_npc(npcpp,gfx_struct,size_x,size_y,x-(size_x/2),y-(size_y-6));


	if(*npcpp==NULL){ERROR_set_error("NPC_create_random_npc_xy_feet()");return;}
	NPC* npc = *npcpp;


	npc->random=1;
	npc->randomcolorset[0]=(r(7))+1;
	npc->randomcolorset[1]=(r(6))+1;
	npc->randomcolorset[2]=(r(6))+1;
	npc->randomcolorset[3]=r(14);
	npc->randomcolorset[4]=r(14);
	npc->randomcolorset[5]=r(14);

	npc->anim_dir=DOWN;
	NPC_set_anim_frame_now(npcpp,0);

}

//=========================================================================================================================
void NPC_create_random_CHILD_xy_feet(NPC** npcpp,int x,int y) // SIZE X AND Y ARE ACTUAL NPC HEIGHT AND WIDTH NOT SPRITE SIZE,X AND Y ARE FEET PLACEMENT
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_create_random_CHILD_xy_feet()");return;}


	GFX* gfx_filename = NULL;

	switch(r(17))
	{
		case  0:{gfx_filename = GFX_KID_GENERICboy1; break;}
		case  1:{gfx_filename = GFX_KID_GENERICboy2; break;}
		case  2:{gfx_filename = GFX_KID_GENERICboy3; break;}
		case  3:{gfx_filename = GFX_KID_GENERICboy4; break;}
		case  4:{gfx_filename = GFX_KID_GENERICgirl1; break;}
		case  5:{gfx_filename = GFX_KID_GENERICgirl2; break;}
		case  6:{gfx_filename = GFX_KID_GENERICgirl3; break;}
		case  7:{gfx_filename = GFX_KID_GENERICgirl4; break;}
		case  8:{gfx_filename = GFX_KID_GENERICgirl5; break;}
		case  9:{gfx_filename = GFX_KID_GENERICgirl6; break;}
		case 10:{gfx_filename = GFX_KID_GENERIClittleboy1; break;}
		case 11:{gfx_filename = GFX_KID_GENERIClittleboy2; break;}
		case 12:{gfx_filename = GFX_KID_GENERIClittleboy3; break;}
		case 13:{gfx_filename = GFX_KID_GENERICpudgylittleboy; break;}
		case 14:{gfx_filename = GFX_KID_GENERIClittlegirl1; break;}
		case 15:{gfx_filename = GFX_KID_GENERIClittlegirl2; break;}
		case 16:{gfx_filename = GFX_KID_GENERIClittlegirl3; break;}
		default: gfx_filename = GFX_KID_GENERICboy1;
	}

	NPC_create_npc(npcpp,gfx_filename,16,32,x-(16/2),y-(32-6));

	if(*npcpp==NULL){ERROR_set_error("NPC_create_random_CHILD_xy_feet()");return;}
	NPC* npc = *npcpp;

	//npc->random=1;
	npc->randomcolorset[0]=(r(7))+1;
	npc->randomcolorset[1]=(r(6))+1;
	npc->randomcolorset[2]=(r(6))+1;
	npc->randomcolorset[3]=r(14);
	npc->randomcolorset[4]=r(14);
	npc->randomcolorset[5]=r(14);

	npc->anim_dir=DOWN;
	NPC_set_anim_frame_now(npcpp,0);

}

//=========================================================================================================================
void NPC_create_random_LITTLE_CHILD_xy_feet(NPC** npcpp,int x,int y) // SIZE X AND Y ARE ACTUAL NPC HEIGHT AND WIDTH NOT SPRITE SIZE,X AND Y ARE FEET PLACEMENT
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_create_random_LITTLE_CHILD_xy_feet()");return;}

	GFX*gfx_filename = NULL;

	switch(r(7))
	{
		case  0:{gfx_filename = GFX_KID_GENERIClittleboy1; break;}
		case  1:{gfx_filename = GFX_KID_GENERIClittleboy2; break;}
		case  2:{gfx_filename = GFX_KID_GENERIClittleboy3; break;}
		case  3:{gfx_filename = GFX_KID_GENERICpudgylittleboy; break;}
		case  4:{gfx_filename = GFX_KID_GENERIClittlegirl1; break;}
		case  5:{gfx_filename = GFX_KID_GENERIClittlegirl2; break;}
		case  6:{gfx_filename = GFX_KID_GENERIClittlegirl3; break;}
		default: gfx_filename = GFX_KID_GENERICboy1;
	}

	NPC_create_npc(npcpp,gfx_filename,16,32,x-(16/2),y-(32-6));

	if(*npcpp==NULL){ERROR_set_error("NPC_create_random_LITTLE_CHILD_xy_feet()");return;}
	NPC* npc = *npcpp;

	//npc->random=1;
	npc->randomcolorset[0]=(r(7))+1;
	npc->randomcolorset[1]=(r(6))+1;
	npc->randomcolorset[2]=(r(6))+1;
	npc->randomcolorset[3]=r(14);
	npc->randomcolorset[4]=r(14);
	npc->randomcolorset[5]=r(14);

	npc->anim_dir=DOWN;
	NPC_set_anim_frame_now(npcpp,0);

}

//=========================================================================================================================
void NPC_create_random_ADULT_xy_feet(NPC** npcpp,int x,int y) // SIZE X AND Y ARE ACTUAL NPC HEIGHT AND WIDTH NOT SPRITE SIZE,X AND Y ARE FEET PLACEMENT
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_create_random_ADULT_xy_feet()");return;}

	GFX*gfx_filename = NULL;

	switch(r(15))
	{
		case  0:{gfx_filename = GFX_ADULT_GENERICsuitguy; break;}
		case  1:{gfx_filename = GFX_ADULT_GENERICbaldsuitguy; break;}
		case  2:{gfx_filename = GFX_ADULT_GENERICbaldingmanashirt; break;}
		case  3:{gfx_filename = GFX_ADULT_GENERICbaldingmantshirt; break;}
		case  4:{gfx_filename = GFX_ADULT_GENERICmanlongsleeves; break;}
		case  5:{gfx_filename = GFX_ADULT_GENERICbeardbaldingtshirt; break;}
		case  6:{gfx_filename = GFX_ADULT_GENERICwomanbobcut; break;}
		case  7:{gfx_filename = GFX_ADULT_GENERICwomanbun; break;}
		case  8:{gfx_filename = GFX_ADULT_GENERICwomanlonghair; break;}
		case  9:{gfx_filename = GFX_ADULT_GENERICwomanfancyhairblouse; break;}
		case 10:{gfx_filename = GFX_ADULT_GENERICmanbeardbaldingtshirt2; break;}
		case 11:{gfx_filename = GFX_ADULT_GENERICmangrayhairbigheadsuit; break;}
		case 12:{gfx_filename = GFX_ADULT_GENERICwomangrayhairdress; break;}
		case 13:{gfx_filename = GFX_ADULT_GENERICwomangrayhairmakeupdress; break;}
		case 14:{gfx_filename = GFX_ADULT_GENERICwomanwhitehair; break;}
		default: gfx_filename = GFX_KID_GENERICboy1;
	}

	 NPC_create_npc(npcpp,gfx_filename,16,40,x-(16/2),y-(40-6));

	if(*npcpp==NULL){ERROR_set_error("NPC_create_random_ADULT_xy_feet()");return;}
	NPC* npc = *npcpp;

	//tempnpc->random=1;
	npc->randomcolorset[0]=(r(7))+1;
	npc->randomcolorset[1]=(r(6))+1;
	npc->randomcolorset[2]=(r(6))+1;
	npc->randomcolorset[3]=r(14);
	npc->randomcolorset[4]=r(14);
	npc->randomcolorset[5]=r(14);

	npc->anim_dir=DOWN;
	NPC_set_anim_frame_now(npcpp,0);

}

//=========================================================================================================================
void NPC_create_random_MAN_xy_feet(NPC** npcpp,int x,int y) // SIZE X AND Y ARE ACTUAL NPC HEIGHT AND WIDTH NOT SPRITE SIZE,X AND Y ARE FEET PLACEMENT
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_create_random_MAN_xy_feet()");return;}

	GFX*gfx_filename = NULL;

	switch(r(8))
	{
		case  0:{gfx_filename = GFX_ADULT_GENERICsuitguy; break;}
		case  1:{gfx_filename = GFX_ADULT_GENERICbaldsuitguy; break;}
		case  2:{gfx_filename = GFX_ADULT_GENERICbaldingmanashirt; break;}
		case  3:{gfx_filename = GFX_ADULT_GENERICbaldingmantshirt; break;}
		case  4:{gfx_filename = GFX_ADULT_GENERICmanlongsleeves; break;}
		case  5:{gfx_filename = GFX_ADULT_GENERICbeardbaldingtshirt; break;}
		case  6:{gfx_filename = GFX_ADULT_GENERICmanbeardbaldingtshirt2; break;}
		case  7:{gfx_filename = GFX_ADULT_GENERICmangrayhairbigheadsuit; break;}

		default: gfx_filename = GFX_KID_GENERICboy1;
	}

	 NPC_create_npc(npcpp,gfx_filename,16,40,x-(16/2),y-(40-6));

	if(*npcpp==NULL){ERROR_set_error("NPC_create_random_MAN_xy_feet()");return;}
	NPC* npc = *npcpp;

	//tempnpc->random=1;
	npc->randomcolorset[0]=(r(7))+1;
	npc->randomcolorset[1]=(r(6))+1;
	npc->randomcolorset[2]=(r(6))+1;
	npc->randomcolorset[3]=r(14);
	npc->randomcolorset[4]=r(14);
	npc->randomcolorset[5]=r(14);

	npc->anim_dir=DOWN;
	NPC_set_anim_frame_now(npcpp,0);

}

//=========================================================================================================================
void NPC_create_random_WOMAN_xy_feet(NPC** npcpp,int x,int y) // SIZE X AND Y ARE ACTUAL NPC HEIGHT AND WIDTH NOT SPRITE SIZE,X AND Y ARE FEET PLACEMENT
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_create_random_WOMAN_xy_feet()");return;}

	GFX*gfx_filename = NULL;

	switch(r(7))
	{
		case  0:{gfx_filename = GFX_ADULT_GENERICwomanbobcut; break;}
		case  1:{gfx_filename = GFX_ADULT_GENERICwomanbun; break;}
		case  2:{gfx_filename = GFX_ADULT_GENERICwomanlonghair; break;}
		case  3:{gfx_filename = GFX_ADULT_GENERICwomanfancyhairblouse; break;}
		case  4:{gfx_filename = GFX_ADULT_GENERICwomangrayhairdress; break;}
		case  5:{gfx_filename = GFX_ADULT_GENERICwomangrayhairmakeupdress; break;}
		case  6:{gfx_filename = GFX_ADULT_GENERICwomanwhitehair; break;}
		default: gfx_filename = GFX_KID_GENERICboy1;
	}

	 NPC_create_npc(npcpp,gfx_filename,16,40,x-(16/2),y-(40-6));

	if(*npcpp==NULL){ERROR_set_error("NPC_create_random_WOMAN_xy_feet()");return;}
	NPC* npc = *npcpp;

	//tempnpc->random=1;
	npc->randomcolorset[0]=(r(7))+1;
	npc->randomcolorset[1]=(r(6))+1;
	npc->randomcolorset[2]=(r(6))+1;
	npc->randomcolorset[3]=r(14);
	npc->randomcolorset[4]=r(14);
	npc->randomcolorset[5]=r(14);

	npc->anim_dir=DOWN;
	NPC_set_anim_frame_now(npcpp,0);

}

//=========================================================================================================================
void NPC_create_random_ADULT_OR_CHILD_xy_feet(NPC** npcpp,int x,int y) // SIZE X AND Y ARE ACTUAL NPC HEIGHT AND WIDTH NOT SPRITE SIZE,X AND Y ARE FEET PLACEMENT
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_create_random_ADULT_OR_CHILD_xy_feet()");return;}

	GFX* gfx_filename = NULL;
	int sizex=16;
	int sizey=40;

	switch(r(32))
	{
		case  0:{gfx_filename = GFX_ADULT_GENERICsuitguy; break;}
		case  1:{gfx_filename = GFX_ADULT_GENERICbaldsuitguy; break;}
		case  2:{gfx_filename = GFX_ADULT_GENERICbaldingmanashirt; break;}
		case  3:{gfx_filename = GFX_ADULT_GENERICbaldingmantshirt; break;}
		case  4:{gfx_filename = GFX_ADULT_GENERICmanlongsleeves; break;}
		case  5:{gfx_filename = GFX_ADULT_GENERICbeardbaldingtshirt; break;}
		case  6:{gfx_filename = GFX_ADULT_GENERICwomanbobcut; break;}
		case  7:{gfx_filename = GFX_ADULT_GENERICwomanbun; break;}
		case  8:{gfx_filename = GFX_ADULT_GENERICwomanlonghair; break;}
		case  9:{gfx_filename = GFX_ADULT_GENERICwomanfancyhairblouse; break;}
		case 10:{gfx_filename = GFX_ADULT_GENERICmanbeardbaldingtshirt2; break;}
		case 11:{gfx_filename = GFX_ADULT_GENERICmangrayhairbigheadsuit; break;}
		case 12:{gfx_filename = GFX_ADULT_GENERICwomangrayhairdress; break;}
		case 13:{gfx_filename = GFX_ADULT_GENERICwomangrayhairmakeupdress; break;}
		case 14:{gfx_filename = GFX_ADULT_GENERICwomanwhitehair; break;}

		case 15:{gfx_filename = GFX_KID_GENERICboy1; sizey=32;break;}
		case 16:{gfx_filename = GFX_KID_GENERICboy2; sizey=32;break;}
		case 17:{gfx_filename = GFX_KID_GENERICboy3; sizey=32;break;}
		case 18:{gfx_filename = GFX_KID_GENERICboy4; sizey=32;break;}
		case 19:{gfx_filename = GFX_KID_GENERICgirl1; sizey=32;break;}
		case 20:{gfx_filename = GFX_KID_GENERICgirl2; sizey=32;break;}
		case 21:{gfx_filename = GFX_KID_GENERICgirl3; sizey=32;break;}
		case 22:{gfx_filename = GFX_KID_GENERICgirl4; sizey=32;break;}
		case 23:{gfx_filename = GFX_KID_GENERICgirl5; sizey=32;break;}
		case 24:{gfx_filename = GFX_KID_GENERICgirl6; sizey=32;break;}
		case 25:{gfx_filename = GFX_KID_GENERIClittleboy1; sizey=32;break;}
		case 26:{gfx_filename = GFX_KID_GENERIClittleboy2; sizey=32;break;}
		case 27:{gfx_filename = GFX_KID_GENERIClittleboy3; sizey=32;break;}
		case 28:{gfx_filename = GFX_KID_GENERICpudgylittleboy; sizey=32;break;}
		case 29:{gfx_filename = GFX_KID_GENERIClittlegirl1;sizey=32; break;}
		case 30:{gfx_filename = GFX_KID_GENERIClittlegirl2;sizey=32;break;}
		case 31:{gfx_filename = GFX_KID_GENERIClittlegirl3; sizey=32;break;}
		default: gfx_filename = GFX_KID_GENERICboy1;
	}

	 NPC_create_npc(npcpp,gfx_filename,sizex,sizey,x-(16/2),y-(sizey-6));


	if(*npcpp==NULL){ERROR_set_error("NPC_create_random_ADULT_OR_CHILD_xy_feet()");return;}
	NPC* npc = *npcpp;

	//tempnpc->random=1;
	npc->randomcolorset[0]=(r(7))+1;
	npc->randomcolorset[1]=(r(6))+1;
	npc->randomcolorset[2]=(r(6))+1;
	npc->randomcolorset[3]=r(14);
	npc->randomcolorset[4]=r(14);
	npc->randomcolorset[5]=r(14);

	npc->anim_dir=DOWN;
	NPC_set_anim_frame_now(npcpp,0);

}

//=========================================================================================================================
NPC *NPC_find_nearest_crowd_npc_or_main_sprite(NPC** npcpp)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_find_nearest_crowd_npc_or_main_sprite()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_find_nearest_crowd_npc_or_main_sprite()");return 0;}
	NPC* npc = *npcpp;

	NPC *nearest_npc_id=NULL;

	int shortestdist=65535;

	int c=0;
	for(c=0;c<CROWDSIZE;c++)
	{

		if(randomcrowd_npcs[c]!=NULL&&randomcrowd_npcs[c]!=npc)
		{
			int x=(npc->MAP_x+npc->size_x/2)-(randomcrowd_npcs[c]->MAP_x+randomcrowd_npcs[c]->size_x/2);
			int y=(npc->MAP_y+npc->size_y-(npc->hitsize_y))-(randomcrowd_npcs[c]->MAP_y+randomcrowd_npcs[c]->size_y-(randomcrowd_npcs[c]->hitsize_y));

			if(x<0)x=x*-1;
			if(y<0)y=y*-1;
			int dist = ((x+y)/2);	//sqrt((x*x)+(y*y));
			if(dist<shortestdist)
			{
				shortestdist=dist;
				nearest_npc_id= randomcrowd_npcs[c];
			}
		}

	}

	int x=(npc->MAP_x+npc->size_x/2)-(PLAYER_npc->MAP_x+PLAYER_npc->size_x/2);
	int y=(npc->MAP_y+npc->size_y-(npc->hitsize_y))-(PLAYER_npc->MAP_y+PLAYER_npc->size_y-(PLAYER_npc->hitsize_y));

	if(x<0)x=x*-1;
	if(y<0)y=y*-1;
	int dist = ((x+y)/2);	//sqrt((x*x)+(y*y));
	if(dist<shortestdist)
	{
		shortestdist=dist;
		nearest_npc_id= PLAYER_npc;
	}

	return nearest_npc_id;
}

//=========================================================================================================================
bool NPC_crowd_move(NPC** npcpp,int speed,int x,int y)//NPC_walk_straight_to_point_intelligent_hit_avoid_other_npcs_push_main_sprite with only detect nearest crowd.
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_crowd_move()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_crowd_move()");return 0;}
	NPC* npc = *npcpp;


	if(npc!=NULL)
	{

		npc->ignore_player=1;
		npc->walking_speed = speed;

		bool there_yet=0;


		int npcx = npc->MAP_x+(npc->size_x/2);
		int npcy = npc->MAP_y+(npc->size_y-(npc->hitsize_y/2));

		if(x==-1)x=npcx;
		if(y==-1)y=npcy;


		if(npcx==x&&npcy==y)
		{
			there_yet=1;

			NPC_stand(npcpp);
		}
		else
		{

			if(npc->ms>npc->walking_speed)
			{

				int xdistance=npcx-x;
				int ydistance=npcy-y;

				if(xdistance<0)xdistance*=-1;
				if(ydistance<0)ydistance*=-1;

				int direction=-1;
				NPC* nearestnpc = NPC_find_nearest_crowd_npc_or_main_sprite(npcpp);
				if(nearestnpc==NULL)nearestnpc=PLAYER_npc;

				if(ydistance>=xdistance) //walk the greater distance first, up/down vs left/right
				{
					if(npcy<y)
					{

						direction=DOWN;

						if(NPC_check_hit_move_pixel(npcpp,DOWN)==0)
						{
							if(npc->secondary_direction!=LEFT&&npc->secondary_direction!=RIGHT)
							{
								if(r(2)==0)npc->secondary_direction=LEFT;
								else npc->secondary_direction=RIGHT;
							}
						}
						else
						{
							npc->secondary_direction=-1;
						}

					}
					if(npcy>y)
					{

						direction=UP;

						if(NPC_check_hit_move_pixel(npcpp,UP)==0)
						{
							if(npc->secondary_direction!=LEFT&&npc->secondary_direction!=RIGHT)
							{
								if(r(2)==0)npc->secondary_direction=LEFT;
								else npc->secondary_direction=RIGHT;
							}
						}
						else
						{
							npc->secondary_direction=-1;
						}
					}

				}

				if(xdistance>=ydistance)
				{
					if(npcx<x)
					{

						direction=RIGHT;

						if(NPC_check_hit_move_pixel(npcpp,RIGHT)==0)
						{
							if(npc->secondary_direction!=UP&&npc->secondary_direction!=DOWN)
							{
								npc->secondary_direction=UP;
								//if(r(2)==0)
								//else npc->secondary_direction=DOWN;
							}
						}
						else
						{

							npc->secondary_direction=-1;
						}

					}
					if(npcx>x)
					{

						direction=LEFT;

						if(NPC_check_hit_move_pixel(npcpp,LEFT)==0)
						{
							if(npc->secondary_direction!=UP&&npc->secondary_direction!=DOWN)
							{
								npc->secondary_direction=UP;
								//if(r(2)==0)npc->secondary_direction=UP;
								//else npc->secondary_direction=DOWN;
							}
						}
						else
						{
							npc->secondary_direction=-1;
						}

					}
				}



				if(npc->secondary_direction==-1&&NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,14)==1)
				{
					if(nearestnpc==PLAYER_npc)
					{
						int nx = npc->MAP_x+(npc->size_x/2);
						int ny = npc->MAP_y+(npc->size_y-(npc->hitsize_y/2));
						int sx = nearestnpc->MAP_x+(nearestnpc->size_x/2);
						int sy = nearestnpc->MAP_y+(nearestnpc->size_y-(nearestnpc->hitsize_y/2));

						int wd=nearestnpc->walk_dir;

						if(nx>sx&&ny<sy)wd=(DOWNLEFT);
						else
						if(nx<sx&&ny<sy)wd=(DOWNRIGHT);
						else
						if(ny>sy&&nx>sx)wd=(UPLEFT);
						else
						if(ny>sy&&nx<sx)wd=(UPRIGHT);
						else
						if(nx>sx)wd=(LEFT);
						else
						if(nx<sx)wd=(RIGHT);
						else
						if(ny>sy)wd=(UP);
						else
						if(ny<sy)wd=(DOWN);

						nearestnpc->ms=nearestnpc->walking_speed*2;
						PLAYER_check_hit_move_pixel_animate(wd);
						//NPC_animate_increment_direction_frame_now(nearestnpc,wd);
					}

					if(direction==RIGHT||direction==LEFT)
					{
						if(npcy<nearestnpc->MAP_y+(nearestnpc->size_y-(nearestnpc->hitsize_y/2)))
						{
							NPC_check_hit_move_pixel(npcpp,UP); //else walk up if slightly above
						}
						else
						{
							NPC_check_hit_move_pixel(npcpp,DOWN);			//else walk down
						}
					}
					else
					if(direction==UP||direction==DOWN)
					{
						if(npcx<nearestnpc->MAP_x+nearestnpc->size_x/2)
						{
							NPC_check_hit_move_pixel(npcpp,LEFT); //else walk left if slightly left
						}
						else
						{
							NPC_check_hit_move_pixel(npcpp,RIGHT);			//else walk right
						}
					}


					if(nearestnpc->anim_dir==npc->anim_dir&&nearestnpc->walking_speed==npc->walking_speed)
					{
						npc->walking_speed+=GLOBALSPEED*1;
					}
				}




				if(npc->standing_cycles==0)
				{
					if(npc->secondary_direction==UP)
					{
						if(NPC_check_hit_move_pixel(npcpp,UP)==1)
						{
							if(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,8)==1)
							{
								if(nearestnpc->MAP_y<=npc->MAP_y)
								{
									npc->standing_cycles=r(20);
									if(r(2)==0)npc->secondary_direction=DOWN;
								}

							}
						}
						else npc->secondary_direction=DOWN;
					}
					else
					if(npc->secondary_direction==DOWN)
					{
						if(NPC_check_hit_move_pixel(npcpp,DOWN)==1)
						{
							if(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,8)==1)
							{
								if(nearestnpc->MAP_y>=npc->MAP_y)
								{
									npc->standing_cycles=r(20);
									if(r(2)==0)npc->secondary_direction=UP;
								}
							}
						}
						else npc->secondary_direction=UP;
					}
					else
					if(npc->secondary_direction==LEFT)
					{
						if(NPC_check_hit_move_pixel(npcpp,LEFT)==1)
						{
							if(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,8)==1)
							{
								if(nearestnpc->MAP_x<=npc->MAP_x)
								{
									npc->standing_cycles=r(20);
									if(r(2)==0)npc->secondary_direction=RIGHT;
								}
							}
						}
						else npc->secondary_direction=RIGHT;
					}
					else
					if(npc->secondary_direction==RIGHT)
					{
						if(NPC_check_hit_move_pixel(npcpp,RIGHT)==1)
						{
							if(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,8)==1)
							{
								if(nearestnpc->MAP_x>=npc->MAP_x)
								{
									npc->standing_cycles=r(20);
									if(r(2)==0)npc->secondary_direction=LEFT;
								}

							}
						}
						else npc->secondary_direction=LEFT;
					}
				}
				else npc->standing_cycles--;


				//if stuck on wall and moving another direction, face that direction
				if(npc->secondary_direction!=-1)direction = npc->secondary_direction;


				if(npc->anim_dir!=direction&&GLOBAL_npc_all_animation_off==0&&npc->animation_off==0)
					{npc->anim_dir=direction;NPC_animate_dir(npcpp,npc->anim_dir);}//animate change direction

				if(npc->pixels_to_walk>0&&npc->is_walking_into_player==0)npc->pixels_to_walk--;

				npc->ms=0;
			}

			if(NPC_should_animate(npcpp)&&there_yet==0)//&&npc->walking_into_sprite==0&&npc->walking_into_wall==0)// animate walking.
			{
				if(GLOBAL_npc_all_animation_off==0&&npc->animation_off==0)NPC_animate_dir(npcpp,npc->anim_dir);
			}

		}
		return there_yet;
	}
	return 0;
}
//=========================================================================================================================
void NPC_random_crowd_left_right_xyxy(int x,int y, int x2, int y2, int amount)
{//=========================================================================================================================




	//random npc engine will do this automatically, keep track of an array of random npcs,	random npcs get removed once offscreen
	//NPC_random_crowd(x,y,x,y,amount);
	//if any part of the camera is within x,y,x,y?
	//hmm.. if horizontal region is within the camera, create guys at x-32, walk offscreen?
	//have npcs created offscreen within xyxy region, and if the other side of the screen is xyxy region walk there, otherwise turn around and walk back offscreen the way they came?
	//they should always be trying to walk to the farthest point across the camera(+32) thats still within their region
	//so if the camera only shows a little corner of the screen, they pop on, walk 2 feet and pop off, in that corner
	//if the camera is entirely spanning a sidewalk, they are created at -32,topy, walk across, and delete at cam+32, bottomy
	//maybe "trying to walk left and right" or "trying to walk up and down"
	//only create random guys offscreen, there should be amount random guys walking around between xy and xy?
	//maybe for the city/town stuff i should do it manually. create guy in front of door, walk to xy,xy,xy,go in door?

	if(MAP_is_xyxy_within_screen_by_amt(x,y,x2,y2,GAME_VIEWPORT_WIDTH_PIXELS/4)==1)
	{

		static int last_vbl_10=0;

		int c=0;
		for(c=0;c<CROWDSIZE&&c<amount;c++)
		if(randomcrowd_npcs[c]==NULL)
		{

			//if top side of screen is above y2 and less than y1+32, create npcs randomly between x and x2 at touchmapcamy*2-32, random walk left or right
			//if bottom side of screen is below y1 and less than y2-32, create npcs randomly between x and x2 at touchmapcamy*2+32, random walk left or right

			//if left side of the screen is within range, create npcs randomly between y and y2 at touchmapcamx*2-16, try to walk right.
			if(c%2==0||!(MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS>=x&&MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS<=x2&&((y>=MAP_cam_y&&y<=MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS)||(y2>=MAP_cam_y&&y2<=MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS))))
			{

				if(MAP_cam_x>=x&&MAP_cam_x<=x2&&((y>=MAP_cam_y&&y<=MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS)||(y2>=MAP_cam_y&&y2<=MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS)))
				{
					int amt=r(y2-y);
					int xamt=r(32);
					if(!NPC_cant_create_at_xy(MAP_cam_x-16-xamt,y+amt)&&last_vbl_10!=vbl_10_var)
					{

						last_vbl_10=vbl_10_var;

						NPC_create_random_ADULT_xy_feet(&randomcrowd_npcs[c],MAP_cam_x-16-xamt,y+amt);
						randomcrowd_npcs[c]->non_walkable=1;
						randomcrowd_npcs[c]->walking_speed = SPEED_NORMAL+r(SPEED_SLOWEST-SPEED_FASTEST);
						randomcrowd_npcs[c]->AI=RIGHT;
						randomcrowd_npcs[c]->walk_dir=4;

					}
				}

			}
			else
			{
				//if right side of screen is within range, create npcs randomly between y and y2 at touchmapcam_x*2+512+16 try to walk left
				if(MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS>=x&&MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS<=x2&&((y>=MAP_cam_y&&y<=MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS)||(y2>=MAP_cam_y&&y2<=MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS)))
				{
					int amt=r(y2-y);
					int xamt=r(32);
					if(!NPC_cant_create_at_xy(MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16+xamt,y+amt)&&last_vbl_10!=vbl_10_var)
					{

						last_vbl_10=vbl_10_var;

						NPC_create_random_ADULT_xy_feet(&randomcrowd_npcs[c],MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16+xamt,y+amt);
						randomcrowd_npcs[c]->non_walkable=1;
						randomcrowd_npcs[c]->walking_speed = SPEED_NORMAL+r(SPEED_SLOWEST-SPEED_FASTEST);
						randomcrowd_npcs[c]->AI=LEFT;
						randomcrowd_npcs[c]->walk_dir=4;
					}
				}
			}
		}

		for(c=0;c<CROWDSIZE&&c<amount;c++)
		if(randomcrowd_npcs[c]!=NULL)
		{

			if(randomcrowd_npcs[c]->MAP_x-1<x)randomcrowd_npcs[c]->AI=RIGHT;
			if(randomcrowd_npcs[c]->MAP_x+randomcrowd_npcs[c]->size_x+1>x2)randomcrowd_npcs[c]->AI=LEFT;

			//if noc is trying to walk left, left side of screen is not in range, hit boundary and turn around
			//else if npc is trying to walk left and left side of screen IS in range, walk to touchmap_cam_c*2-16

			if(randomcrowd_npcs[c]->AI==LEFT)
			{
				if((MAP_is_xy_within_screen_by_amt(randomcrowd_npcs[c]->MAP_x+randomcrowd_npcs[c]->size_x/2,randomcrowd_npcs[c]->MAP_y+randomcrowd_npcs[c]->size_y-randomcrowd_npcs[c]->hitsize_y,64)==0)||
					NPC_crowd_move(&randomcrowd_npcs[c], randomcrowd_npcs[c]->walking_speed, MAP_cam_x-16, -1))
				{
					NPC_delete_npc(&randomcrowd_npcs[c]);

				}
			}
			else
			//if npc is trying to walk right, right side of screen is not in range, hit boundary and turn around.
			//else if npc is trying to walk right, and right side of screen is in range, walk to touchmap_cam_x*2+512+16 delete
			if(randomcrowd_npcs[c]->AI==RIGHT)
			{
				if((MAP_is_xy_within_screen_by_amt(randomcrowd_npcs[c]->MAP_x+randomcrowd_npcs[c]->size_x/2,randomcrowd_npcs[c]->MAP_y+randomcrowd_npcs[c]->size_y-randomcrowd_npcs[c]->hitsize_y,64)==0)||
					NPC_crowd_move(&randomcrowd_npcs[c], randomcrowd_npcs[c]->walking_speed, MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16, -1))
				{
					NPC_delete_npc(&randomcrowd_npcs[c]);

				}
			}
		}
	}
	else
	{
		int c=0;
		for(c=0;c<CROWDSIZE;c++)
		if(randomcrowd_npcs[c]!=NULL)
		{
			if(MAP_is_xy_within_screen_by_amt(randomcrowd_npcs[c]->MAP_x,randomcrowd_npcs[c]->MAP_y,64)==0)
			{
				NPC_delete_npc(&randomcrowd_npcs[c]);

			}
		}
	}
}
//=========================================================================================================================
void NPC_fade_out_random_crowd()
{//=========================================================================================================================

		int c=0;
		for(c=0;c<CROWDSIZE;c++)
		if(randomcrowd_npcs[c]!=NULL)
		{
			if(MAP_is_xy_within_screen_by_amt(randomcrowd_npcs[c]->MAP_x,randomcrowd_npcs[c]->MAP_y,64)==0)
			{
				NPC_delete_npc(&randomcrowd_npcs[c]);
			}
			else
			{
				if(randomcrowd_npcs[c]->alpha>0){NPC_set_alpha(&randomcrowd_npcs[c],randomcrowd_npcs[c]->alpha-1);}else{NPC_delete_npc(&randomcrowd_npcs[c]);}

			}
		}


}
