
#include "../../main.h"
//#include "npccar.h"


//=========================================================================================================================
void NPC_set_car_anim_frame_now(NPC** npcpp,int frame)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_set_car_anim_frame_now()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_set_car_anim_frame_now()");return;}
	NPC* npc = *npcpp;

	npc->anim_frame_count=frame;
	npc->walk_dir=frame;
	npc->anim_dir=frame;
	npc->gfx_index = (npc->data_size_x*npc->data_size_y*npc->anim_frame_count);

	//if(npc->gfx_slot!=-1||npc->gfx_slot_touchmap!=-1)
	{

		/*int c;

		for(c=0;c<64*64;c++)
		{
			int color = npc->gfx_filename[(npc->data_size_x*npc->data_size_y*npc->anim_frame_count)+c];

			if(color==GENERICcarcolors[0])color = GENERICcarcolors[0+8*npc->randomcolorset[0]];
			else if(color==GENERICcarcolors[1])color = GENERICcarcolors[1+8*npc->randomcolorset[0]];
			else if(color==GENERICcarcolors[2])color = GENERICcarcolors[2+8*npc->randomcolorset[0]];
			else if(color==GENERICcarcolors[3])color = GENERICcarcolors[3+8*npc->randomcolorset[0]];
			else if(color==GENERICcarcolors[4])color = GENERICcarcolors[4+8*npc->randomcolorset[0]];

			randomtempcarsprite[c]= color;
		}*/

		//DMA_Copy(((int*)&randomtempcarsprite),(void*)(SPRITE_GFX1 + (0x200000 *	(1)) + ((npc->gfx_slot) << NUMBER_DECAL)),(used_mem[1][npc->gfx_slot] << (MEM_DECAL+1)),DMA_16NOW);
		//DMA_Copy(((int*)&randomtempcarsprite),(void*)(SPRITE_GFX1 + (0x200000 *	(0)) + ((npc->gfx_slot_touchmap) << NUMBER_DECAL)),(used_mem[0][npc->gfx_slot_touchmap] << (MEM_DECAL+1)),DMA_16NOW);

/*
		int m=0;
		int *location;

		if(npc->gfx_slot!=-1)
		{

			location = (void*)(SPRITE_GFX1 + (0x200000 *	(1)) + ((npc->gfx_slot) << NUMBER_DECAL));

			for(m=0;m<(used_mem[1][npc->gfx_slot] << (MEM_DECAL+1));m++)
				location[m]=(int)((randomtempcarsprite[m*2])+(randomtempcarsprite[(m*2)+1]<<8));
		}

		if(npc->gfx_slot_touchmap!=-1)
		{
			location = (void*)(SPRITE_GFX1 + (0x200000 *	(0)) + ((npc->gfx_slot_touchmap) << NUMBER_DECAL));

			for(m=0;m<(used_mem[0][npc->gfx_slot_touchmap] << (MEM_DECAL+1));m++)
				location[m]=(int)((randomtempcarsprite[m*2])+(randomtempcarsprite[(m*2)+1]<<8));
		}	*/

		if(npc->sprite!=NULL)			HARDWARE_update_sprite_texture(npc->sprite,(npc->data_size_x*npc->data_size_y*npc->anim_frame_count));//doesnt care about sprite id
		//if(npc->gfx_slot_touchmap!=-1)	HARDWARE_update_sprite_texture(0,npc->gfx_slot_touchmap,npc->gfx_struct,(npc->data_size_x*npc->data_size_y*npc->anim_frame_count), 1);

		if(frame==LEFT	||	frame==RIGHT)
		{
			npc->hitsize_x = 96;
			npc->hitsize_y = 40;
			npc->size_x = 96;
			npc->size_y = 80;
		}

		if(frame==UP	||	frame==DOWN)
		{
			npc->hitsize_x = 64;
			npc->hitsize_y = 96;
			npc->size_x = 64;
			npc->size_y = 96;
		}
	}
}

//=========================================================================================================================
NPC *NPC_find_nearest_car_in_direction(NPC** npcpp)
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_find_nearest_car_in_direction()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_find_nearest_car_in_direction()");return 0;}
	NPC* npc = *npcpp;


	NPC *nearest_npc_id=NULL;

	int smallest_dist=65535;

	int c=0;
	for(c=0;c<16;c++)
	{

		//TODO: support special cars here
		//ice cream truck, police cars, ambulance, etc.

		if(car_npc[c]!=NULL&&car_npc[c]!=npc)
		{

			int dist=0;

			if( npc->walk_dir==LEFT&&
				npc->MAP_y>=car_npc[c]->MAP_y-10&&
				npc->MAP_y<=car_npc[c]->MAP_y+10&&
				npc->MAP_x>=car_npc[c]->MAP_x
			)
			dist=(npc->MAP_x)-(car_npc[c]->MAP_x);

			if(
				npc->walk_dir==RIGHT&&
				npc->MAP_y>=car_npc[c]->MAP_y-10&&
				npc->MAP_y<=car_npc[c]->MAP_y+10&&
				npc->MAP_x<=car_npc[c]->MAP_x
			)
			dist=(npc->MAP_x)-(car_npc[c]->MAP_x);

			if( npc->walk_dir==UP&&
				npc->MAP_x>=car_npc[c]->MAP_x-10&&
				npc->MAP_x<=car_npc[c]->MAP_x+10&&
				npc->MAP_y>=car_npc[c]->MAP_y
			)
			dist=(npc->MAP_y)-(car_npc[c]->MAP_y);

			if( npc->walk_dir==DOWN&&
				npc->MAP_x>=car_npc[c]->MAP_x-10&&
				npc->MAP_x<=car_npc[c]->MAP_x+10&&
				npc->MAP_y<=car_npc[c]->MAP_y
			)
			dist=(npc->MAP_y)-(car_npc[c]->MAP_y);

			if(dist<0)dist=dist*-1;

			if(dist<smallest_dist&&dist!=0)
			{
				smallest_dist=dist;
				nearest_npc_id=car_npc[c];
			}
		}
	}
	return nearest_npc_id;
}

//=========================================================================================================================
bool NPC_car_move_no_hit_no_anim(NPC** npcpp,int speed,int x,int y)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_car_move_no_hit_no_anim()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_car_move_no_hit_no_anim()");return 0;}
	NPC* npc = *npcpp;


	npc->ignore_player=1;
	npc->walking_speed = speed;

	bool there_yet=0;

	if(npc->MAP_x+npc->size_x/2==x&&npc->MAP_y+npc->size_y-npc->hitsize_y==y)
	{
		there_yet=1;
	}
	else
	{
		if(npc->ms>npc->walking_speed)
		{
			int direction=0;
			if(npc->MAP_y+npc->size_y-npc->hitsize_y<y){npc->MAP_y++;direction=DOWN;}
			if(npc->MAP_y+npc->size_y-npc->hitsize_y>y){npc->MAP_y--;direction=UP;}
			if(npc->MAP_x+npc->size_x/2<x){npc->MAP_x++;direction=RIGHT;}
			if(npc->MAP_x+npc->size_x/2>x){npc->MAP_x--;direction=LEFT;}

			if(npc->pixels_to_walk>0&&npc->is_walking_into_player==0)npc->pixels_to_walk--;

			npc->ms=0;
		}
	}
	return there_yet;
}
//=========================================================================================================================
bool NPC_move_car_dont_hit_other_cars(NPC** npcpp,int speed,int x,int y)
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_move_car_dont_hit_other_cars()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_move_car_dont_hit_other_cars()");return 0;}



	NPC* nearnpc = NPC_find_nearest_car_in_direction(npcpp);

	if(nearnpc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(npcpp,&nearnpc,128)==0)return NPC_car_move_no_hit_no_anim(npcpp,speed,x,y);

	}else return NPC_car_move_no_hit_no_anim(npcpp,speed,x,y);

	return 0;

}
//=========================================================================================================================
void NPC_create_car_if_within_range_else_delete(NPC** npcpp,int x,int y,int direction)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_create_car_if_within_range_else_delete()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_create_car_if_within_range_else_delete()");return;}
	NPC* npc = *npcpp;


	if(MAP_is_xy_within_screen_by_amt(x+96/2,y+96/2,128)==1)//&&xy_within_touchmap_cam(x+64/2,y+64/2)==0)
	{
		if(npc==NULL)NPC_create_car(npcpp,x,y,direction);
	}
	else
	if(npc!=NULL)
	{
		NPC_delete_npc(npcpp);
	}

}

//=========================================================================================================================
void NPC_create_car(NPC** npcpp,int x,int y,int direction)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_create_car()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_create_car()");return;}
	NPC* npc = *npcpp;


	if(npc==NULL)
	{
		y-=8;
		int type;
		type = r(5);
		if(type==0)NPC_create_npc(npcpp,GFX_CAR_car,64,64,x,y);
		if(type==1)NPC_create_npc(npcpp,GFX_CAR_van,64,64,x,y);
		if(type==2)NPC_create_npc(npcpp,GFX_CAR_truck,64,64,x,y);
		if(type==3)NPC_create_npc(npcpp,GFX_CAR_suv,64,64,x,y);
		if(type==4)NPC_create_npc(npcpp,GFX_CAR_minivan,64,64,x,y);
		npc->randomcolorset[0]=r(13);
		NPC_set_car_anim_frame_now(npcpp,direction);
		npc->non_walkable=1;
		npc->animation_off=1;
		npc->scale=1.5f;

	}

}

//=========================================================================================================================
void NPC_create_bicycle_if_within_range_else_delete(NPC** npcpp,int x,int y,int direction)
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_create_bicycle_if_within_range_else_delete()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_create_bicycle_if_within_range_else_delete()");return;}
	NPC* npc = *npcpp;


	if(MAP_is_xy_within_screen_by_amt(x+64/2,y+64/2,128)==1)//&&xy_within_touchmap_cam(x+64/2,y+64/2)==0)
	{
		if(npc==NULL)
		{
			NPC_create_npc(npcpp,GFX_CAR_bicycle,64,64,x,y);
			npc->randomcolorset[0]=r(13);
			NPC_set_car_anim_frame_now(npcpp,direction);
			npc->non_walkable=1;
			npc->animation_off=1;
			npc->layer=1;
			if(direction==LEFT	||	direction==RIGHT)
			{
				npc->hitsize_y = 8;
				npc->hitsize_x = 50;
				npc->size_x =50;
				npc->size_y =32;

			}
			if(direction==UP	||	direction==DOWN)
			{
				npc->hitsize_y = 32;
				npc->hitsize_x = 16;
				npc->size_x =16;
				npc->size_y =40;

			}
		}
	}
	else
	if(npc!=NULL)
	{
		NPC_delete_npc(npcpp);
	}

}




//=========================================================================================================================
void NPC_car_play_sound_if_near_player(NPC** npcpp)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_car_play_sound_if_near_player()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_car_play_sound_if_near_player()");return;}

	if(PLAYER_npc==NULL){ERROR_set_error("NPC_car_play_sound_if_near_player()");return;}

	if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,npcpp,200))HARDWARE_play_sound("carpass",64,44100,0);

}



//=========================================================================================================================
bool NPC_car_check_if_hit_player(NPC** npcpp, int direction, int* hit_direction_x, int* hit_direction_y)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_car_check_if_hit_player()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_car_check_if_hit_player()");return 0;}
	NPC* npc = *npcpp;

	if(PLAYER_npc==NULL){ERROR_set_error("NPC_car_check_if_hit_player()");return 0;}

	bool hit_by_car=0;

		if(direction==DOWN||direction==UP)
		{
			if(NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,npc->MAP_x+16,npc->MAP_y,npc->MAP_x+npc->size_x-8,npc->MAP_y+npc->size_y+32,PLAYER_npc->anim_dir,0))
				{
					hit_by_car=1;
					*hit_direction_y=direction;
					if(PLAYER_npc->MAP_x+PLAYER_npc->size_x/2>(npc->MAP_x+(npc->size_x/2))+16)*hit_direction_x=RIGHT;
					else *hit_direction_x=LEFT;
				}
		}
		if(direction==LEFT||direction==RIGHT)
		{
			if(NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,npc->MAP_x,npc->MAP_y+32,npc->MAP_x+npc->size_x+32,npc->MAP_y+npc->size_y-10,PLAYER_npc->anim_dir,0))
				{
					hit_by_car=1;
					*hit_direction_x=direction;
					if(PLAYER_npc->MAP_y+PLAYER_npc->size_y-PLAYER_npc->hitsize_y>(npc->MAP_y+(npc->size_y/2))+32)*hit_direction_y=DOWN;
					else *hit_direction_y=UP;
				}
		}

	return hit_by_car;


}


//=========================================================================================================================
bool NPC_car_xyxy(NPC** npcpp,int x,int y,int x2,int y2,int speed,int direction,int* hit_direction_x,int* hit_direction_y)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_car_xyxy()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_car_xyxy()");return 0;}
	NPC* npc = *npcpp;



	//make the car if it doesnt exist
	if(npc==NULL)
	{

		int type;
		type = r(5);
		if(type==0)NPC_create_npc_xy_feet(npcpp,GFX_CAR_car,64,64,x,y);
		if(type==1)NPC_create_npc_xy_feet(npcpp,GFX_CAR_van,64,64,x,y);
		if(type==2)NPC_create_npc_xy_feet(npcpp,GFX_CAR_truck,64,64,x,y);
		if(type==3)NPC_create_npc_xy_feet(npcpp,GFX_CAR_suv,64,64,x,y);
		if(type==4)NPC_create_npc_xy_feet(npcpp,GFX_CAR_minivan,64,64,x,y);
		npc->non_walkable=1;
		npc->animation_off=1;
		npc->scale=1.5f;
		npc->randomcolorset[0]=r(13);
		NPC_set_car_anim_frame_now(npcpp,direction);
	}

	//move the car and delete it if it gets to where it needs to go
	if(npc!=NULL)if(NPC_move_car_dont_hit_other_cars(npcpp,speed,x2,y2)){NPC_delete_npc(npcpp);}



	//see if it hits the player
	int hit_by_car=0;

	if(npc!=NULL)
	{
		//okay, size y and map y are accurate now,but dont forget that the car sprite has blank space above and below :)

		NPC_car_play_sound_if_near_player(npcpp);
		hit_by_car = NPC_car_check_if_hit_player(npcpp, direction, hit_direction_x, hit_direction_y);


	}
	return hit_by_car;
}

//=========================================================================================================================
bool NPC_car_counterclockwise(NPC** npcpp,int speed,int* hit_direction_x,int* hit_direction_y)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_car_counterclockwise()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_car_counterclockwise()");return 0;}
	NPC* npc = *npcpp;

	if(PLAYER_npc==NULL){ERROR_set_error("NPC_car_counterclockwise()");return 0;}

	int hit_by_car=0;

	if(npc==NULL)
	{

		int type;
		type = r(5);
		if(type==0)NPC_create_npc_xy_feet(npcpp,GFX_CAR_car,64,64,649*8,16*8);	//	car created (feet middle) at 649,16
		if(type==1)NPC_create_npc_xy_feet(npcpp,GFX_CAR_van,64,64,649*8,16*8);	//	car created (feet middle) at 649,16
		if(type==2)NPC_create_npc_xy_feet(npcpp,GFX_CAR_truck,64,64,649*8,16*8);	//	car created (feet middle) at 649,16
		if(type==3)NPC_create_npc_xy_feet(npcpp,GFX_CAR_suv,64,64,649*8,16*8);	//	car created (feet middle) at 649,16
		if(type==4)NPC_create_npc_xy_feet(npcpp,GFX_CAR_minivan,64,64,649*8,16*8);	//	car created (feet middle) at 649,16

		npc->non_walkable=1;
		npc->animation_off=1;
		npc->scale=1.5f;
		npc->AI=0;
		npc->walk_dir=0;
		npc->randomcolorset[0]=r(13);
		NPC_set_car_anim_frame_now(npcpp,DOWN);
		npc->walk_dir=DOWN;
	}


	if(npc!=NULL)
	{

		int tempx = npc->MAP_x;
		int tempy = npc->MAP_y;

		if(npc->AI==0)
		{	//travel to 649 313
			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,649*8,309*8))
			{
				npc->AI++;
				npc->vbl_animation_timer=0;
			}

		}
		if(npc->AI==1&&npc->vbl_animation_timer>60)
		{	// stop. decide to turn left or right. if turn left set walking_direction to 0
			//stopped.
			//decide to turn left or right.
			//if traffic light is ok
			//if yuu isnt in the street
			//if(!NPC_in_range_of_xy_xy_direction(PLAYER_npc,*8,*8,*8,*8,PLAYER_npc->anim_direction,8))
			//if(!NPC_in_range_of_xy_xy_direction(PLAYER_npc,*8,*8,*8,*8,PLAYER_npc->anim_direction,8))		 //traffic light crosswalks	//traffic light crosswalk middle 638,319	680,325
			if(!NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,638*8,319*8,680*8,325*8,PLAYER_npc->anim_dir,0))npc->AI++;

		}
		if(npc->AI==2)
		{	//649,336 down,animate left.
			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,649*8,332*8))
			{
				NPC_set_car_anim_frame_now(npcpp,LEFT);
				npc->AI++;
			}
		}
		if(npc->AI==3)
		{	//travel to 260,337,
			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,260*8,333*8))
			{
				npc->AI++;
				npc->vbl_animation_timer=0;
			}
		}
		if(npc->AI==4&&npc->vbl_animation_timer>60)
		{	//stop. school crossing.
			//stopped.
			//if yuu isnt in the street
			//if school crossing lady isnt in the street																	//crosswalk school cross 239,329	248,352
			if(crossingguard_npc!=NULL)
			{
				if(!NPC_in_range_of_area_xyxy_in_direction_by_amount(&crossingguard_npc,239*8,332*8,248*8,352*8,RIGHT,8)
					&&!NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,239*8,329*8,248*8,352*8,PLAYER_npc->anim_dir,0))npc->AI++;
			}
			else
			if(!NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,239*8,329*8,248*8,352*8,PLAYER_npc->anim_dir,0))npc->AI++; 	//school crosswalk
		}
		if(npc->AI==5)
		{	//travel to 85. 337,
			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,85*8,333*8))
			{
				npc->AI++;
				npc->vbl_animation_timer=0;
			}
		}
		if(npc->AI==6&&npc->vbl_animation_timer>60)
		{	//stop. stop sign.
			//stopped.
			//if yuu isnt in the street
			if(!NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,39*8,354*8,61*8,360*8,PLAYER_npc->anim_dir,0))		//upper left crosswalks	//crosswalks upper left	39,354 61,360	65,328 72,351
			if(!NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,65*8,328*8,72*8,351*8,PLAYER_npc->anim_dir,0))npc->AI++;
		}
		if(npc->AI==7)
		{	//travel to 45,337,animate down.
			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,45*8,333*8))
			{
				NPC_set_car_anim_frame_now(npcpp,DOWN);
				npc->AI++;
			}
		}
		if(npc->AI==8)
		{	//travel to 45 520
			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,45*8,516*8))
			{
				npc->AI++;
				npc->vbl_animation_timer=0;
			}
		}
		if(npc->AI==9&&npc->vbl_animation_timer>60)
		{	//stop,stop sign
			//stopped.
			//if yuu isnt in the street
			if(!NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,65*8,541*8,72*8,565*8,PLAYER_npc->anim_dir,0))				//lower left crosswalks	//crosswalks bottom left	65.541	72.565	39.529	62.535
			if(!NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,39*8,529*8,62*8,535*8,PLAYER_npc->anim_dir,0))npc->AI++;
		}
		if(npc->AI==10)
		{	//travel to 45,560 animate right.
			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,45*8,556*8))
			{
				NPC_set_car_anim_frame_now(npcpp,RIGHT);
				npc->AI++;
			}
		}
		if(npc->AI==11)
		{	//travel to 1496 560
			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,1496*8,556*8))
			{
				npc->AI++;
				npc->vbl_animation_timer=0;
			}
		}
		if(npc->AI==12&&npc->vbl_animation_timer>60)
		{	//stop sign
			//stopped.
			//if yuu isnt in the street
			if(!NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,1518*8,529*8,1543*8,534*8,PLAYER_npc->anim_dir,0))				 //lower right crosswalks	//crosswalks bottom right 1518.529	1543.534	1508.542	1515.565
			if(!NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,1508*8,542*8,1515*8,565*8,PLAYER_npc->anim_dir,0))npc->AI++;
		}
		if(npc->AI==13)
		{	//1535,560 animate up
			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,1535*8,556*8))
			{
				NPC_set_car_anim_frame_now(npcpp,UP);
				npc->AI++;
			}
		}
		if(npc->AI==14)
		{	//1535 377
			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,1535*8,373*8))
			{
				npc->AI++;
				npc->vbl_animation_timer=0;
			}
		}
		if(npc->AI==15&&npc->vbl_animation_timer>60)
		{	//stop sign
			//stopped.
			//if yuu isnt in the street
			if(!NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,1508*8,329*8,1515*8,352*8,PLAYER_npc->anim_dir,0))				//upper right crosswalks	//crosswalks upper right	1508.329	1515.352	1519.354	1542.360
			if(!NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,1519*8,354*8,1542*8,360*8,PLAYER_npc->anim_dir,0))npc->AI++;
		}
		if(npc->AI==16)
		{	//1535 337 animate left
			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,1535*8,333*8))
			{
				NPC_set_car_anim_frame_now(npcpp,LEFT);
				npc->AI++;
			}
		}
		if(npc->AI==17)
		{	//693 337
			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,693*8,333*8))
			{
				npc->AI++;
				npc->vbl_animation_timer=0;
			}
		}
		if(npc->AI==18&&npc->vbl_animation_timer>60)
		{	//stop light
			//stopped.
			//if yuu isnt in the street
			//if(!NPC_in_range_of_xy_xy_direction(PLAYER_npc,*8,*8,*8,*8,PLAYER_npc->anim_direction,0))			//traffic light crosswalks
			//if(!NPC_in_range_of_xy_xy_direction(PLAYER_npc,*8,*8,*8,*8,PLAYER_npc->anim_direction,0))			//traffic light crosswalk middle 638,319	680,325
			if(!NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,638*8,319*8,680*8,325*8,PLAYER_npc->anim_dir,0))npc->AI++;
		}
		if(npc->AI==19)
		{	//670,337 animate up
			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,670*8,333*8))
			{
				NPC_set_car_anim_frame_now(npcpp,UP);
				npc->AI++;
			}
		}
		if(npc->AI==20)
		{	//670,17 delete
			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,670*8,13*8))
			{
				npc->AI=0;
				NPC_delete_npc(npcpp);
			}
		}

		if(npc!=NULL)
		{

			int direction = npc->walk_dir;

			if(tempx != npc->MAP_x || tempy != npc->MAP_y) //if the car isnt stopped (has moved a pixel)
			{


				NPC_car_play_sound_if_near_player(npcpp);
				hit_by_car = NPC_car_check_if_hit_player(npcpp, direction, hit_direction_x, hit_direction_y);

			}
		}
	}
	return hit_by_car;
}
//=========================================================================================================================
bool NPC_car_clockwise(NPC** npcpp,int speed,int* hit_direction_x,int* hit_direction_y)
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_car_clockwise()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_car_clockwise()");return 0;}
	NPC* npc = *npcpp;

	if(PLAYER_npc==NULL){ERROR_set_error("NPC_car_counterclockwise()");return 0;}

	int hit_by_car=0;

	if(npc==NULL)
	{
		int type;
		type = r(5);
		if(type==0)NPC_create_npc_xy_feet(npcpp,GFX_CAR_car,64,64,649*8,16*8);	//	car created (feet middle) at 649,16
		if(type==1)NPC_create_npc_xy_feet(npcpp,GFX_CAR_van,64,64,649*8,16*8);	//	car created (feet middle) at 649,16
		if(type==2)NPC_create_npc_xy_feet(npcpp,GFX_CAR_truck,64,64,649*8,16*8);	//	car created (feet middle) at 649,16
		if(type==3)NPC_create_npc_xy_feet(npcpp,GFX_CAR_suv,64,64,649*8,16*8);	//	car created (feet middle) at 649,16
		if(type==4)NPC_create_npc_xy_feet(npcpp,GFX_CAR_minivan,64,64,649*8,16*8);	//	car created (feet middle) at 649,16
		npc->non_walkable=1;
		npc->animation_off=1;
		npc->scale=1.5f;
		npc->AI=0;
		npc->walk_dir=0;
		npc->randomcolorset[0]=r(13);
		NPC_set_car_anim_frame_now(npcpp,DOWN);
	}


	if(npc!=NULL)
	{

		int tempx = npc->MAP_x;
		int tempy = npc->MAP_y;

		if(npc->AI==0)
		{	//649,313

			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,649*8,309*8))
			{
				npc->AI++;
				npc->vbl_animation_timer=0;
			}
		}
		if(npc->AI==1&&npc->vbl_animation_timer>60)
		{	// stop. decide to turn left or right. if turn left set walking_direction to 0
			//stopped.
			//decide to turn left or right.
			//if traffic light is ok
			//if yuu isnt in the street

			//stop. if turn right set walking_direction to 1
			//if(!NPC_in_range_of_xy_xy_direction(PLAYER_npc,*8,*8,*8,*8,PLAYER_npc->anim_direction,8)) //traffic light crosswalks	//traffic light crosswalk middle 638,319	680,325
		//if(!NPC_in_range_of_xy_xy_direction(PLAYER_npc,*8,*8,*8,*8,PLAYER_npc->anim_direction,8))
			if(!NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,638*8,319*8,680*8,325*8,PLAYER_npc->anim_dir,8))npc->AI++;
		}
		if(npc->AI==2)
		{	//649,348,animate right

			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,649*8,344*8))
			{
				NPC_set_car_anim_frame_now(npcpp,RIGHT);
				npc->AI++;
			}
		}
		if(npc->AI==3)
		{	//1495 348

			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,1495*8,344*8))
			{
				npc->AI++;
				npc->vbl_animation_timer=0;
			}
		}
		if(npc->AI==4&&npc->vbl_animation_timer>60)
		{
			//stop sign
			//stopped.
			//if yuu isnt in the street
			if(!NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,1508*8,329*8,1515*8,352*8,PLAYER_npc->anim_dir,0))	//upper right crosswalks	//crosswalks upper right	1508.329	1515.352	1519.354	1542.360
			if(!NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,1519*8,354*8,1542*8,360*8,PLAYER_npc->anim_dir,0))npc->AI++;
		}
		if(npc->AI==5)
		{	//1524 348 animate down

			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,1524*8,344*8))
			{
				NPC_set_car_anim_frame_now(npcpp,DOWN);
				npc->AI++;
			}
		}
		if(npc->AI==6)
		{	//1524 520
			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,1524*8,516*8))
			{
				npc->AI++;
				npc->vbl_animation_timer=0;
			}
		}
		if(npc->AI==7&&npc->vbl_animation_timer>60)
		{	//stop sign
			//stopped.
			//if yuu isnt in the street
			if(!NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,1518*8,529*8,1543*8,534*8,PLAYER_npc->anim_dir,0))	 //lower right crosswalks	//crosswalks bottom right 1518.529	1543.534	1508.542	1515.565
			if(!NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,1508*8,542*8,1515*8,565*8,PLAYER_npc->anim_dir,0))npc->AI++;

		}
		if(npc->AI==8)
		{	//1524 550 animate left

			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,1524*8,546*8))
			{
				NPC_set_car_anim_frame_now(npcpp,LEFT);
				npc->AI++;
			}
		}
		if(npc->AI==9)
		{	//83 549
			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,83*8,545*8))
			{
				npc->AI++;
				npc->vbl_animation_timer=0;
			}
		}
		if(npc->AI==10&&npc->vbl_animation_timer>60)
		{	//stop sign
			//stopped.
			//if yuu isnt in the street
			if(!NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,65*8,541*8,72*8,565*8,PLAYER_npc->anim_dir,0))		//lower left crosswalks	//crosswalks bottom left	65.541	72.565	39.529	62.535
		if(!NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,39*8,529*8,62*8,535*8,PLAYER_npc->anim_dir,0))npc->AI++;

		}
		if(npc->AI==11)
		{	//55 549 animate up

			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,55*8,545*8))
			{
				NPC_set_car_anim_frame_now(npcpp,UP);
				npc->AI++;
			}
		}
		if(npc->AI==12)
		{	//55 376
			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,55*8,372*8))
			{
				npc->AI++;
				npc->vbl_animation_timer=0;
			}
		}
		if(npc->AI==13&&npc->vbl_animation_timer>60)
		{	//stop sign
			//stopped.
			//if yuu isnt in the street
			if(!NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,39*8,354*8,61*8,360*8,PLAYER_npc->anim_dir,0))		//upper left crosswalks	//crosswalks upper left	39,354 61,360	65,328 72,351
		if(!NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,65*8,328*8,72*8,351*8,PLAYER_npc->anim_dir,0))npc->AI++;

		}
		if(npc->AI==14)
		{	//55 348 animate right

			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,55*8,344*8))
			{
				NPC_set_car_anim_frame_now(npcpp,RIGHT);
				npc->AI++;
			}
		}
		if(npc->AI==15)
		{	//226,348
			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,226*8,344*8))
			{
				npc->AI++;
				npc->vbl_animation_timer=0;
			}
		}
		if(npc->AI==16&&npc->vbl_animation_timer>60)
		{	//stop. school crossing.
				//stopped.
				//if yuu isnt in the street
				//if school crossing lady isnt in the street											 //school crossing		//crosswalk school cross 239,329	248,352
			if(crossingguard_npc!=NULL)
			{
				if(!NPC_in_range_of_area_xyxy_in_direction_by_amount(&crossingguard_npc,239*8,332*8,248*8,352*8,RIGHT,8)
					&&!NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,239*8,329*8,248*8,352*8,PLAYER_npc->anim_dir,0))npc->AI++;
			}
			else
			if(!NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,239*8,329*8,248*8,352*8,PLAYER_npc->anim_dir,0))npc->AI++;

		}
		if(npc->AI==17)
		{	//623 348

			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,623*8,344*8))
			{
				npc->AI++;
				npc->vbl_animation_timer=0;
			}
		}
		if(npc->AI==18&&npc->vbl_animation_timer>60)
		{	//stop light
			//stopped.
			//if yuu isnt in the street
			//traffic light
			//if(!NPC_in_range_of_xy_xy_direction(PLAYER_npc,*8,*8,*8,*8,PLAYER_npc->anim_direction,8)) //traffic light crosswalk 1	//traffic light crosswalk middle 638,319	680,325
			//if(!NPC_in_range_of_xy_xy_direction(PLAYER_npc,*8,*8,*8,*8,PLAYER_npc->anim_direction,8)) //traffic light crosswalk 2
			if(!NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,638*8,319*8,680*8,325*8,PLAYER_npc->anim_dir,0))npc->AI++; //traffic light crosswalk 3
		}
		if(npc->AI==19)
		{	//670 348 animate up

			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,670*8,344*8))
			{
				NPC_set_car_anim_frame_now(npcpp,UP);
				npc->AI++;
			}
		}
		if(npc->AI==20)
		{	//670,17 delete.
			if(NPC_move_car_dont_hit_other_cars(npcpp,speed,670*8,13*8))
			{
				npc->AI=0;
				NPC_delete_npc(npcpp);
			}
		}
		if(npc!=NULL)
		{
			int direction = npc->walk_dir;

			if(tempx != npc->MAP_x || tempy != npc->MAP_y) //if car isnt stopped (has moved a pixel)
			{

				NPC_car_play_sound_if_near_player(npcpp);
				hit_by_car = NPC_car_check_if_hit_player(npcpp, direction, hit_direction_x, hit_direction_y);
			}
		}
	}
	return hit_by_car;
}

//need a way to keep track of other cars,dont crash into each other
//maybe maximum cars? cars only create when the previous car has got to the stop sign?
//cars stop at stop signs and wait for yuu at the corners to cross either crosswalk
//cars obey traffic light

//crosswalks upper left	39,354 61,360	65,328 72,351
//crosswalks upper right	1508.329	1515.352	1519.354	1542.360

//crosswalk school cross 239,329	248,352

//traffic light crosswalk left
//traffic light crosswalk middle 638,319	680,325
//traffic light crosswalk right

//crosswalks bottom left	65.541	72.565	39.529	62.529
//crosswalks bottom right 1518.529	1543.534	1508.542	1515.565
