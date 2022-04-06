

#include "../../main.h"
//#include "npc.h"




NPC main_npc;
NPC *PLAYER_npc = &main_npc;

NPC cameraman_npc;
NPC *cameraman = &cameraman_npc;

//NPC shadownpc;
//NPC *main_sprite_shadow = &shadownpc;

NPC mr_cart_npc;
NPC* mr_cart;

//NPC clicktarget_npc;
//NPC* clicktarget=&clicktarget_npc;

NPC* cameraman_target = &main_npc;

NPC dummy_camera_target_npc;
NPC* dummy_camera_target = &dummy_camera_target_npc;


bool GLOBAL_npc_all_animation_off=0;

bool NPC_main_sprite_being_dragged=0;

int GLOBAL_npcs_pulling_main_sprite=0;
//NPC_chaser *first_npc_chaser = NULL;
//NPC_avoider *first_npc_avoider = NULL;
NPC_follower *first_npc_follower = NULL;
//NPC_pull_againster *first_npc_pull_againster = NULL;


NPC* first_NPC = NULL;

//=========================================================================================================================
void NPC_init()
{//=========================================================================================================================
	if(GLOBAL_hq2x_is_on)
	{

		UPLEFT=4;
		DOWNRIGHT=5;
		DOWNLEFT=6;
		UPRIGHT=7;
	}
	else
	{

		UPLEFT=4;
		UPRIGHT=5;
		DOWNRIGHT=6;
		DOWNLEFT=7;
	}
}


//=========================================================================================================================
bool NPC_is_within_screen_bounds(NPC** npcpp)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_is_within_screen_bounds()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_is_within_screen_bounds()");return 0;}
	NPC* npc = *npcpp;

	int top 	= npc->MAP_y; //we want the actual top of the sprite
	int bottom = npc->MAP_y + npc->size_y;
	int left 	= npc->MAP_x;
	int right 	= npc->MAP_x + npc->size_x;


	int screentop = MAP_cam_y;
	int screenbottom = MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS;
	int screenleft = MAP_cam_x;
	int screenright = MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS;


	if(
		right<screenleft
		||
		left>screenright
		||
		bottom+32<screentop //+32 for shadow
		||
		top>screenbottom
	)
	{
		return 0;
	}
	else
	{
		return 1;
	}



}

//=========================================================================================================================
void NPC_set_screen_xy(NPC** npcpp)
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_set_screen_xy()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_set_screen_xy()");return;}
	NPC* npc = *npcpp;


	int top 	= npc->MAP_y; //we want the actual top of the sprite
	int bottom = npc->MAP_y + npc->size_y;
	int left 	= npc->MAP_x;
	int right 	= npc->MAP_x + npc->size_x;


	int screentop = MAP_cam_y;
	int screenbottom = MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS;
	int screenleft = MAP_cam_x;
	int screenright = MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS;


	if(
		right<screenleft
		||
		left>screenright
		||
		bottom+32<screentop //+32 for shadow
		||
		top>screenbottom
	)
	{
		npc->screen_x = GAME_VIEWPORT_WIDTH_PIXELS;
		npc->screen_y = GAME_VIEWPORT_HEIGHT_PIXELS;
		return;
	}



	if(right>=screenleft&&left<screenleft) //if npc is overlapping left side of screen
	{
		npc->screen_x = 0 - (screenleft-left);
	}

	if(left>=screenleft&&left<screenright)//if npc is onscreen and not overlapping the left side
	{
		npc->screen_x = left - screenleft;
	}

	if(bottom+32>=screentop&&top<screentop) //if npc is overlapping top side of screen
	{
		npc->screen_y = 0 -(screentop-top);
	}

	if(top>=screentop&&top<screenbottom)//if npc is onscreen and not overlapping the top side
	{
		npc->screen_y = top-screentop;
	}

}

//=========================================================================================================================
bool NPC_in_range_of_npc(NPC** npc1pp,NPC** npc2pp)
{//=========================================================================================================================

	if(npc1pp==NULL){ERROR_set_error("NPC_in_range_of_npc()");return 0;}
	if(*npc1pp==NULL){ERROR_set_error("NPC_in_range_of_npc()");return 0;}
	NPC* npc1 = *npc1pp;

	if(npc2pp==NULL){ERROR_set_error("NPC_in_range_of_npc()");return 0;}
	if(*npc2pp==NULL){ERROR_set_error("NPC_in_range_of_npc()");return 0;}
	NPC* npc2 = *npc2pp;

	int top 	= (npc1->MAP_y + npc1->size_y) - npc1->hitsize_y;
	int bottom = npc1->MAP_y + npc1->size_y;
	int left 	= npc1->MAP_x;
	int right 	= npc1->MAP_x + npc1->size_x;

	int top2 	= (npc2->MAP_y + npc2->size_y) - npc2->hitsize_y;
	int bottom2= npc2->MAP_y + npc2->size_y;
	int left2 	= npc2->MAP_x;
	int right2 = npc2->MAP_x + npc2->size_x;

	if(
		(
			(	//above
				(left>=left2&&left<=right2)//left side of npc is within sprite width
				||
				(right<=right2&&right>=left2)//right side of npc is within sprite width
			)
			&&
			(top<=bottom2&&top>=top2)
		)
		||
		(
			( //below
				(left>=left2&&left<=right2)//left side of npc is within sprite width
				||
				(right<=right2&&right>=left2)//right side of npc is within sprite width
			)
			&&
			(bottom>=top2&&bottom<=bottom2)
		)
		||
		 (
			(//to left
				(top>=top2&&top<=bottom2)//top side of npc is within sprite hit height
				||
				(bottom>=top2&&bottom<=bottom2)//bottom side of npc is within sprite hit height
			)
			&&
			(left<right2&&left>left2)
		)
		||
		(
			( //to right
				(top>=top2&&top<=bottom2)//top side of npc is within sprite hit height
				||
				(bottom>=top2&&bottom<=bottom2)//bottom side of npc is within sprite hit height
			)
			&&
			(right>left2&&right<right2)
		)
	)
	return 1;
		else return 0;
}

//=========================================================================================================================
bool NPC_in_range_of_npc_by_amount(NPC** npc1pp,NPC** npc2pp,int amt)
{//=========================================================================================================================

	if(npc1pp==NULL){ERROR_set_error("NPC_in_range_of_npc_by_amount()");return 0;}
	if(*npc1pp==NULL){ERROR_set_error("NPC_in_range_of_npc_by_amount()");return 0;}
	NPC* npc1 = *npc1pp;

	if(npc2pp==NULL){ERROR_set_error("NPC_in_range_of_npc_by_amount()");return 0;}
	if(*npc2pp==NULL){ERROR_set_error("NPC_in_range_of_npc_by_amount()");return 0;}
	NPC* npc2 = *npc2pp;

	int npc1x = npc1->MAP_x+npc1->size_x/2;
	int npc1y = npc1->MAP_y+(npc1->size_y-(npc1->hitsize_y/2));
	int npc2x = npc2->MAP_x+npc2->size_x/2;
	int npc2y = npc2->MAP_y+(npc2->size_y-(npc2->hitsize_y/2));

		if(npc1x+amt>=npc2x&&
			npc1x-amt<=npc2x&&
			npc1y+amt>=npc2y&&
			npc1y-amt<=npc2y)return 1;
		else return 0;
}

//=========================================================================================================================
bool NPC_in_range_of_npc_in_direction_by_amount(NPC** npc1pp,NPC** npc2pp,int direction,int amt)
{//=========================================================================================================================

	if(npc1pp==NULL){ERROR_set_error("NPC_in_range_of_npc_in_direction_by_amount()");return 0;}
	if(*npc1pp==NULL){ERROR_set_error("NPC_in_range_of_npc_in_direction_by_amount()");return 0;}
	NPC* npc1 = *npc1pp;

	if(npc2pp==NULL){ERROR_set_error("NPC_in_range_of_npc_in_direction_by_amount()");return 0;}
	if(*npc2pp==NULL){ERROR_set_error("NPC_in_range_of_npc_in_direction_by_amount()");return 0;}
	NPC* npc2 = *npc2pp;


	int top 	= (npc1->MAP_y + npc1->size_y) - npc1->hitsize_y;
	int bottom = npc1->MAP_y + npc1->size_y;
	int left 	= npc1->MAP_x;
	int right 	= npc1->MAP_x + npc1->size_x;

	int top2 	= (npc2->MAP_y + npc2->size_y) - npc2->hitsize_y;
	int bottom2= npc2->MAP_y + npc2->size_y;
	int left2 	= npc2->MAP_x;
	int right2 = npc2->MAP_x + npc2->size_x;

	//int amt = 2;
	bool detected=0;
	if(direction==UP)
	{
		if(
			(left)<=(right2)
			&&(right)>=(left2)
			&&(top-amt)<=(bottom2)
			&&(bottom)>=(bottom2)
		)detected=1;
	}
	if(direction==DOWN)
	{
		if(
			(left)<=(right2)
			&&(right)>=(left2)
			&&(top)<=(top2)
			&&(bottom+amt)>=(top2)
		)detected=1;
	}
	if(direction==LEFT)
	{
		if(
			(left-amt)<=(right2)
			&&(right)>=(right2)
			&&(top)<=(bottom2)		//was -4
			&&(bottom)>=(top2)
		)detected=1;
	}
	if(direction==RIGHT)
	{
		if(
			(left)<=(left2)
			&&(right+amt)>=(left2)
			&&(top)<=(bottom2)		//was -4
			&&(bottom)>=(top2)
		)detected=1;
	}
	if(direction==UPLEFT)
	{
		if(
			(left-amt)<(right2)
			&&(left-amt)>(left2)
			&&(top+2-amt)<(bottom2+amt)
			&&(top+2-amt)>((top2+2)-amt)
		)detected=1;
	}
	if(direction==UPRIGHT)
	{
		if(
			(right+amt)<(right2)
			&&(right+amt)>(left2)
			&&((top+2)-amt)<(bottom2+amt)
			&&((top+2)-amt)>((top2+2)-amt)
		)detected=1;
	}
	if(direction==DOWNLEFT)
	{
		if(
			(left-amt)<(right2)
			&&(left-amt)>(left2)
			&&(bottom+amt)<(bottom2)
			&&(bottom+amt)>((top2+4)-amt)
		)detected=1;
	}
	if(direction==DOWNRIGHT)
	{
		if(
			(right+amt)<(right2)
			&&(right+amt)>(left2)
			&&(bottom+amt)<(bottom2)
			&&(bottom+amt)>((top2+4)-amt)
		)detected=1;
	}
	return detected;
}
//=========================================================================================================================
bool NPC_in_range_of_xy_in_direction_by_amount(NPC** npcpp,int x,int y,int direction,int amt)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_in_range_of_xy_in_direction_by_amount()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_in_range_of_xy_in_direction_by_amount()");return 0;}
	NPC* npc = *npcpp;

	//todo: make this xy point shine or highlighted or something


	//todo: should draw all hit boxes for characters

	//this uses point collision

	if(x==-1)x=npc->MAP_x+npc->size_x/2;
	if(y==-1)y=(npc->MAP_y+npc->size_y-(npc->hitsize_y/2));

	int top 	= (npc->MAP_y + npc->size_y) - npc->hitsize_y;
	int bottom = npc->MAP_y + npc->size_y;
	int left 	= npc->MAP_x;
	int right 	= npc->MAP_x + npc->size_x;


	bool detected=0;
	if(direction==UP)
	{
		if(
			(left)<=(x)
			&&
			(right)>=(x)
			&&
			((top-2)-amt)<=(y)
			&&
			(top)>=(y-amt)

		)detected=1;
	}

	if(direction==DOWN)
	{
	 if(
			(left)<=(x)
			&&
			(right)>=(x)
			&&
			(bottom)<=(y)
			&&
			(bottom+amt)>=(y)
		)detected=1;
	}

	if(direction==LEFT)
	{
	 if(
			(left-amt)<=(x)
			&&
			(left)>=(x)
			&&
			(top-2)<=(y)
			&&
			(bottom)>=(y)

		)detected=1;
	}

	if(direction==RIGHT)
	{
	 if(
			(right+amt)>=(x)
			&&
			(right)<=(x)
			&&
			(top-2)<=(y)
			&&
			(bottom)>=(y)

		)detected=1;
	}


	if(direction==UPLEFT)
	{
	 if(
			(left-amt)<=(x)
			&&
			(left)>=(x)
			&&
			((top-2)-amt)<=(y)
			&&
			(top)>=(y)
		)detected=1;
	}

	if(direction==UPRIGHT)
	{
	 if(
			(right)<=(x)
			&&
			(right+amt)>=(x)
			&&
			((top-2)-amt)<=(y)
			&&
			(top)>=(y)
		)detected=1;
	}

	if(direction==DOWNLEFT)
	{
	 if(
			(left-amt)<=(x)
			&&
			(left)>=(x)
			&&
			(bottom)<=(y)
			&&
			(bottom+amt)>=(y)
		)detected=1;
	}

	if(direction==DOWNRIGHT)
	{
	 if(
			(right)<=(x)
			&&
			(right+amt)>=(x)
			&&
			(bottom)<=(y)
			&&
			(bottom+amt)>=(y)

		)detected=1;
	}
	return detected;

}
//=========================================================================================================================
bool NPC_in_range_of_area_xyxy_in_direction_by_amount(NPC** npcpp,int x,int y,int x2,int y2,int direction,int amt)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_in_range_of_area_xyxy_in_direction_by_amount()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_in_range_of_area_xyxy_in_direction_by_amount()");return 0;}
	NPC* npc = *npcpp;


	if(x==-1)x=npc->MAP_x+(npc->size_x/2);
	if(y==-1)y=(npc->MAP_y+npc->size_y-(npc->hitsize_y/2));
	if(x2==-1)x2=npc->MAP_x+(npc->size_x/2);
	if(y2==-1)y2=(npc->MAP_y+npc->size_y-(npc->hitsize_y/2));

	int top 	= (npc->MAP_y + npc->size_y) - npc->hitsize_y;
	int bottom = npc->MAP_y + npc->size_y;
	int left 	= npc->MAP_x;
	int right 	= npc->MAP_x + npc->size_x;


	bool detected=0;

	if(direction==UP)
	{
		if(
			(left)<=(x2)
			&&
			(right)>=(x)
			&&
			(top)<=(y2)
			&&
			((top-2)-amt)>=(y)

		)detected=1;
	}


	if(direction==DOWN)
	{
	 if(
			(left)<=(x2)
			&&
			(right)>=(x)
			&&
			(bottom)<=(y2)
			&&
			(bottom+amt)>=(y)
		)detected=1;
	}


	if(direction==LEFT)
	{
	 if(
			(left-amt)<=(x2)
			&&
			(left)>=(x)
			&&
			(top-2)<=(y2)
			&&
			(bottom)>=(y)
		)detected=1;
	}
	if(direction==RIGHT)
	{
	 if(
			(right)<=(x2)
			&&
			(right+amt)>=(x)
			&&
			(top-2)<=(y2)
			&&
			(bottom)>=(y)
		)detected=1;
	}

	if(direction==UPLEFT)
	{
	 if(

			(left-amt)<=(x2)
			&&
			(left)>=(x)
			&&
			(top)<=(y2)
			&&
			((top-2)-amt)>=(y)

		)detected=1;
	}
	if(direction==UPRIGHT)
	{
	 if(
			(right)<=(x2)
			&&
			(right+amt)>=(x)
			&&
			(top)<=(y2)
			&&
			((top-2)-amt)>=(y)

		)detected=1;
	}
	if(direction==DOWNLEFT)
	{
	 if(
			(left-amt)<=(x2)
			&&
			(left)>=(x)
			&&
			(bottom)<=(y2)
			&&
			(bottom+amt)>=(y)
		)detected=1;
	}
	if(direction==DOWNRIGHT)
	{
	 if(
			(right)<=(x2)
			&&
			(right+amt)>=(x)
			&&
			(bottom)<=(y2)
			&&
			(bottom+amt)>=(y)
		)detected=1;
	}
	return detected;

}

//=========================================================================================================================
NPC* NPC_find_nearest_npc(NPC** npcpp)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_find_nearest_npc()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_find_nearest_npc()");return 0;}
	NPC* npc = *npcpp;

	NPC* nearest_npc=NULL;

	int shortestdist=65535;

	NPC *current_npc = PLAYER_npc;

	bool stop=0;
	while(stop==0)
	{
		if(npc!=current_npc)
		{

			int x=(npc->MAP_x+npc->size_x/2)-(current_npc->MAP_x+current_npc->size_x/2);
			int y=(npc->MAP_y+npc->size_y-(npc->hitsize_y))-(current_npc->MAP_y+current_npc->size_y-(current_npc->hitsize_y));

			x=abs(x);
			y=abs(y);

			int dist = sqrt((x*x)+(y*y));

			if(dist<shortestdist)
			{
				shortestdist=dist;
				nearest_npc = current_npc;
			}
		}

		if(current_npc->next!=NULL)current_npc = (NPC *)current_npc->next;
		else stop=1;
	}

	return nearest_npc;
}

//=========================================================================================================================
NPC *NPC_find_nearest_npc_in_front_of_npc(NPC** npcpp)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_find_nearest_npc_in_front_of_npc()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_find_nearest_npc_in_front_of_npc()");return 0;}
	NPC* npc = *npcpp;

	NPC *nearest_npc=PLAYER_npc;

	int shortestdist=65535;

	NPC *current_npc = PLAYER_npc;

	int nx = npc->MAP_x+npc->size_x/2;
	int ny = npc->MAP_y+(npc->size_y-(npc->hitsize_y/2));
	int nsx = npc->size_x/2;
	int nsy = (npc->hitsize_y/2);

	bool stop=0;
	while(stop==0)
	{
		if(npc!=current_npc)
		{

			int cx = (current_npc->MAP_x+current_npc->size_x/2);
			int cy = (current_npc->MAP_y+current_npc->size_y-(current_npc->hitsize_y/2));
			int csx = current_npc->size_x/2;
			int csy = (current_npc->hitsize_y/2);

			if(npc->anim_dir==UP)
			{
				if(ny>=cy&&nx+nsx>=cx-csx&&nx-nsx<=cx+csx)
				{
					int dist = cy-ny;
					if(dist<shortestdist)
					{
						shortestdist=dist;
						nearest_npc=current_npc;
					}
				}
			}
			else
			if(npc->anim_dir==DOWN)
			{
				if(ny<=cy&&nx+nsx>=cx-csx&&nx-nsx<=cx+csx)
				{
					int dist = ny-cy;
					if(dist<shortestdist)
					{
						shortestdist=dist;
						nearest_npc=current_npc;
					}
				}
			}
			else
			if(npc->anim_dir==LEFT)
			{
				if(nx>=cx&&ny+nsy>=cy-csy&&ny-nsy<=cy+csy)
				{
					int dist = cx-nx;
					if(dist<shortestdist)
					{
						shortestdist=dist;
						nearest_npc=current_npc;
					}
				}
			}
			else
			if(npc->anim_dir==RIGHT)
			{
				if(nx<=cx&&ny+nsy>=cy-csy&&ny-nsy<=cy+csy)
				{
					int dist = nx-cx;
					if(dist<shortestdist)
					{
						shortestdist=dist;
						nearest_npc=current_npc;
					}
				}
			}


		}
		if(current_npc->next!=NULL)current_npc = (NPC *)current_npc->next;
		else stop=1;
	}

	return nearest_npc;
}

//=========================================================================================================================
NPC *NPC_find_nearest_npc_besides_main_sprite(NPC** npcpp)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_find_nearest_npc_besides_main_sprite()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_find_nearest_npc_besides_main_sprite()");return 0;}
	NPC* npc = *npcpp;

	NPC *nearest_npc=NULL;

	int shortestdist=65535;

	NPC *current_npc = PLAYER_npc;

	bool stop=0;
	while(stop==0)
	{
		if(npc!=current_npc&&current_npc!=PLAYER_npc)
		{
			int x=npc->MAP_x+npc->size_x/2-current_npc->MAP_x+current_npc->size_x/2;
			int y=npc->MAP_y+npc->size_y-(npc->hitsize_y)-current_npc->MAP_y+current_npc->size_y-(current_npc->hitsize_y);

			if(x<0)x=x*-1;
			if(y<0)y=y*-1;
			int dist = sqrt((x*x)+(y*y));
			if(dist<shortestdist)
			{
				shortestdist=dist;
				nearest_npc=current_npc;
			}
		}
		if(current_npc->next!=NULL)current_npc = (NPC *)current_npc->next;
		else stop=1;
	}

	return nearest_npc;
}

//=========================================================================================================================
bool NPC_within_range_of_nearest_npc(NPC** npcpp, int amt)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_within_range_of_nearest_npc()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_within_range_of_nearest_npc()");return 0;}

	NPC* nearest_npc = NPC_find_nearest_npc(npcpp);

	return NPC_in_range_of_npc_by_amount(npcpp,&nearest_npc,amt);

}

//=========================================================================================================================
bool NPC_check_collide_fx_xy(int x,int y)
{//=========================================================================================================================
	int index;
	if(y>=HARDWARE_map_height_tiles*8||x>=HARDWARE_map_width_tiles*8||y<=0||x<=0)
	return 1;
	else
	index = ((y/8)*HARDWARE_map_width_tiles) + (x/8);

	int hit=0;
	int t = HARDWARE_map_fx_layer[index];
	if(t==1||t==2)hit=1;

	return hit;
}
//=========================================================================================================================
bool NPC_check_collide_fx(NPC** npcpp, int dir)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_check_collide_fx()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_check_collide_fx()");return 0;}
	NPC* npc = *npcpp;


	int return_this=1;

	int top 	= (npc->MAP_y + npc->size_y) - npc->hitsize_y;
	int bottom = npc->MAP_y + npc->size_y;
	int left 	= npc->MAP_x;
	int right 	= npc->MAP_x + npc->size_x;
	int middle = npc->MAP_x+(npc->size_x/2);


	if(dir==UP)
	{
		if(
			!NPC_check_collide_fx_xy(left+1,top)
			&&
			!NPC_check_collide_fx_xy(middle-1,top)
			&&
			!NPC_check_collide_fx_xy(middle,top)
			&&
			!NPC_check_collide_fx_xy(right-2,top)
		)return_this=0;
	}
	else
	if(dir==DOWN)
	{
		if(
			!NPC_check_collide_fx_xy(left+1,bottom)
			&&
			!NPC_check_collide_fx_xy(middle-1,bottom)
			&&
			!NPC_check_collide_fx_xy(middle,bottom)
			&&
			!NPC_check_collide_fx_xy(right-2,bottom)
		)return_this=0;
	}
	else
	if(dir==LEFT)
	{
		if(
			!NPC_check_collide_fx_xy(left,bottom-1)
			&&
			!NPC_check_collide_fx_xy(left,bottom-4)
		)return_this=0;
	}
	else
	if(dir==RIGHT)
	{
		if(
			!NPC_check_collide_fx_xy(right-1,bottom-1)
			&&
			!NPC_check_collide_fx_xy(right-1,bottom-4)

		)return_this=0;
	}

	if(npc->ignore_fx_layer==1)return 0;

	return return_this;
}


//=========================================================================================================================
bool NPC_is_touching_player_npc_in_direction(NPC** npcpp, int dir)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_is_touching_player_npc_in_direction()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_is_touching_player_npc_in_direction()");return 0;}
	NPC* npc = *npcpp;


	bool touching_player_npc=0;

	int top 	= (npc->MAP_y + npc->size_y) - npc->hitsize_y;
	int bottom = npc->MAP_y + npc->size_y;
	int left 	= npc->MAP_x;
	int right 	= npc->MAP_x + npc->size_x;
	//int middle = MAP_x+(size_x/2);

	int playertop = (PLAYER_npc->MAP_y + PLAYER_npc->size_y) - PLAYER_npc->hitsize_y;
	int playerbottom = PLAYER_npc->MAP_y + PLAYER_npc->size_y;
	int playerleft = PLAYER_npc->MAP_x;
	int playerright = PLAYER_npc->MAP_x + PLAYER_npc->size_x;


	if(PLAYER_npc==NULL)return 0;
	if(npc==PLAYER_npc)return 0;


	if(dir==UP)
	{
			if(
				(
					(
						left>=playerleft
						&&
						left<=playerright
					)//left side of npc is within sprite width
					||
					(
						right<=playerright
						&&
						right>=playerleft
					)//right side of npc is within sprite width
				)
				&&
				(
					top-1<=playerbottom
					&&
					top-1>=playertop
				)
			)
			touching_player_npc=1;
	}
	else
	if(dir==DOWN)
	{

			if(
				(
					(
						left>=playerleft
						&&
						left<=playerright
					)//left side of npc is within sprite width
					||
					(
						right<=playerright
						&&
						right>=playerleft
					)//right side of npc is within sprite width
				)
				&&
				(
					bottom+1>=playertop
					&&
					bottom+1<=playerbottom
				)
			)touching_player_npc=1;

	}
	else
	if(dir==LEFT)
	{

			if(
				(
					(
						top>=playertop
						&&
						top<=playerbottom
					)//top side of npc is within sprite hit height
					||
					(
						bottom>=playertop
						&&
						bottom<=playerbottom
					)//bottom side of npc is within sprite hit height
				)
				&&
				(
					left<playerright
					&&
					left>playerleft
				)
			)touching_player_npc=1;

	}
	else
	if(dir==RIGHT)
	{

			if(
				(
					(
						top>=playertop
						&&
						top<=playerbottom
					)//top side of npc is within sprite hit height
					||
					(
						bottom>=playertop
						&&
						bottom<=playerbottom
					)//bottom side of npc is within sprite hit height
				)
				&&
				(
					right>playerleft
					&&
					right<playerright
				)
			)touching_player_npc=1;

	}

	return touching_player_npc;


}

//=========================================================================================================================
bool NPC_check_collide_xy(int x,int y)
{//=========================================================================================================================
	int index;
	if(y>=HARDWARE_map_height_tiles*8||x>=HARDWARE_map_width_tiles*8||y<=0||x<=0)
	return 1;
	else
	index = ((y/8)*HARDWARE_map_width_tiles) + (x/8);

	bool hit = HARDWARE_map_hit_layer[index];

	return hit;
}




//=========================================================================================================================
bool NPC_check_hit_layer_direction(NPC** npcpp,int dir)
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_check_hit_layer_direction()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_check_hit_layer_direction()");return 0;}
	NPC* npc = *npcpp;


	int hitting_wall=1;

	int top 	= (npc->MAP_y + npc->size_y) - npc->hitsize_y;
	int bottom = npc->MAP_y + npc->size_y;
	int left 	= npc->MAP_x;
	int right 	= npc->MAP_x + npc->size_x;
	int middle = npc->MAP_x+(npc->size_x/2);

	if(npc->ignore_hit_layer==1)return 0;


	if(dir==UP)
	{
		if(
			!NPC_check_collide_xy(left+1,top)
			&&
			!NPC_check_collide_xy(middle-1,top)
			&&
			!NPC_check_collide_xy(middle,top)
			&&
			!NPC_check_collide_xy(right-2,top)
		)
		hitting_wall=0;

	}
	else
	if(dir==DOWN)
	{
		if(
			!NPC_check_collide_xy(left+1,bottom)
			&&
			!NPC_check_collide_xy(middle-1,bottom)
			&&
			!NPC_check_collide_xy(middle,bottom)
			&&
			!NPC_check_collide_xy(right-2,bottom)
		)
		hitting_wall=0;

	}
	else
	if(dir==LEFT)
	{
		if(
			!NPC_check_collide_xy(left,bottom-1)
			&&
			!NPC_check_collide_xy(left,bottom-4)
		)
		hitting_wall=0;

	}
	else
	if(dir==RIGHT)
	{
		if(
			!NPC_check_collide_xy(right-1,bottom-1)
			&&
			!NPC_check_collide_xy(right-1,bottom-4)
		)
		hitting_wall=0;

	}


	///todo: i split off the check against PLAYER_npc into its own function above, also need to call this separately.
	npc->is_walking_into_player = NPC_is_touching_player_npc_in_direction(npcpp,dir);

	///todo: dont combine this, find where this function is called and do both.
	if(npc!=PLAYER_npc&&hitting_wall==0)hitting_wall=NPC_check_collide_fx(npcpp,dir); //&&NPC_dont_walk_in_fx_layer

	npc->is_walking_into_wall = hitting_wall;

	return hitting_wall;
}

//=========================================================================================================================
bool NPC_cant_create_at_xy(int x,int y)
{//=========================================================================================================================
//check hit and fx for x, x-8, y, y+6.
	if(
		!NPC_check_collide_xy(		x-8,y+6)&&
		!NPC_check_collide_fx_xy(	x-8,y+6)&&

		!NPC_check_collide_xy(		x-8,y)&&
		!NPC_check_collide_fx_xy(	x-8,y)&&


		!NPC_check_collide_xy(		x+8,y)&&
		!NPC_check_collide_fx_xy(	x+8,y)&&

		!NPC_check_collide_xy(		x+8,y+6)&&
		!NPC_check_collide_fx_xy(	x+8,y+6)&&

		!NPC_check_collide_xy(		x,y)&&
		!NPC_check_collide_fx_xy(	x,y)&&

		!NPC_check_collide_xy(		x,y+6)&&
		!NPC_check_collide_fx_xy(	x,y+6)
	)
	return 0;

	return 1;
}


//=========================================================================================================================
bool NPC_can_create_at_xy(int x,int y)
{//=========================================================================================================================
	return !NPC_cant_create_at_xy(x,y);
}
//=========================================================================================================================
void NPC_init_npc_vars(NPC** npcpp, GFX* gfx, int size_x, int size_y, int MAP_x, int MAP_y)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_init_npc_vars()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_init_npc_vars()");return;}
	NPC* npc = *npcpp;


	npc->sprite=NULL;
	npc->gfx = gfx;

	npc->next=NULL;
	npc->nearest_npc=NULL;
	npc->znext=NULL;

	//sizes
	npc->data_size_x=gfx->data_size_x;
	npc->data_size_y=gfx->data_size_y;
	npc->size_x=size_x;
	npc->size_y=size_y;

	npc->hitsize_x=16;
	npc->hitsize_y=8;

	//coords
	npc->MAP_x = MAP_x;
	npc->MAP_y = MAP_y;
	npc->screen_x=0;
	npc->screen_y=0;


	//walking counters
	npc->walk_dir=DOWN;
	npc->walking_speed=SPEED_NORMAL;
	npc->pixels_to_walk=0;
	npc->x_pixel_counter=0;
	npc->y_pixel_counter=0;

	npc->ms=0; //was walk timer. is milliseconds now.


	npc->AI=0;
	npc->standing_cycles=0;
	npc->secondary_direction=-1;

	npc->is_walking_into_player=0;
	npc->is_walking_into_wall=0;

	npc->visible=1;

	npc->vbls=0; //was vbl timer. is frames rendered!

	//animation
	npc->gfx_index=0;
	npc->animation_off=0;
	npc->anim_frame_count=0;
	npc->anim_dir=DOWN;
	npc->vbl_animation_timer=0;

	npc->alpha=255;
	npc->always_on_top=0;
	npc->layer=2;
	npc->scale=1.0f;

	npc->pushable=0;
	npc->non_walkable=0;
	npc->ignore_hit_layer=0;
	npc->ignore_fx_layer=0;
	npc->pull_player=0;
	npc->push_player=0;
	npc->ignore_player=0;

	npc->random=0;
	npc->randomcolorset[0]=0;
	npc->randomcolorset[1]=0;
	npc->randomcolorset[2]=0;
	npc->randomcolorset[3]=0;
	npc->randomcolorset[4]=0;
	npc->randomcolorset[5]=0;
	npc->randomcolorset[6]=0;


	npc->chase_dir_x=0;
	npc->chase_dir_y=0;
	npc->chase_flip_xy=0;
	npc->chase_stage=0;
	npc->chase_stuck_x=0;
	npc->chase_stuck_y=0;

	npc->voice_frequency=0;

}

//=========================================================================================================================
void NPC_create_npc(NPC** npcpp,GFX* gfx,int size_x,int size_y,int MAP_x,int MAP_y) // SIZE X AND Y ARE ACTUAL NPC HEIGHT AND WIDTH NOT SPRITE SIZE.. X AND Y ARE UPPER LEFT CORNER NOT FEET
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_create_npc()");return;}


	///todo: this should pull size x and size y from the gfx data, which should pull it from a sprite config file.

	if(npcpp==NULL||(npcpp!=NULL&&*npcpp==NULL))
	{

		NPC* new_npc = (NPC*)malloc(sizeof(NPC));

		NPC_init_npc_vars(&new_npc,gfx,size_x,size_y,MAP_x,MAP_y);

		new_npc->npcpp = (struct NPC**)npcpp;

		NPC_set_screen_xy(&new_npc);

		if(first_NPC!=NULL)
		{
			NPC* current_npc = first_NPC;
			while(current_npc->next!=NULL)
			{
			 current_npc = (NPC* )current_npc->next;
			}

			current_npc->next = (struct NPC*)new_npc;

		}else first_NPC=new_npc;

		if(npcpp!=NULL)*npcpp=new_npc;

		//npcs_created++;

	}

}
//=========================================================================================================================
void NPC_create_npc_xy_feet(NPC** npcpp,GFX*gfx_struct,int size_x,int size_y,int x,int y) // SIZE X AND Y ARE ACTUAL NPC HEIGHT AND WIDTH NOT SPRITE SIZE,X AND Y ARE FEET PLACEMENT
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_create_npc_xy_feet()");return;}


	NPC_create_npc(npcpp,gfx_struct,size_x,size_y,x-(size_x/2),y-(size_y-6));
}

//=========================================================================================================================
void NPC_create_npc_if_within_range_else_delete(NPC** npcpp,GFX*gfx_struct,int sizex,int sizey,int x,int y)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_create_npc_if_within_range_else_delete()");return;}


	if(MAP_is_xy_within_screen_by_amt(x+sizex/2,y+sizey/2,64)==1)
	{
		if(*npcpp==NULL)NPC_create_npc(npcpp,gfx_struct,sizex,sizey,x,y);

	}
	else
	if(*npcpp!=NULL)
	{
		NPC_delete_npc(npcpp);
	}

}

//=========================================================================================================================
void NPC_create_always_on_top_npc_if_within_range_else_delete(NPC** npcpp,GFX*gfx_struct,int sizex,int sizey,int x,int y)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_create_always_on_top_npc_if_within_range_else_delete()");return;}



	if(MAP_is_xy_within_screen_by_amt(x+sizex/2,y+sizey/2,64)==1)
	{
		if(*npcpp==NULL)NPC_create_npc(npcpp,gfx_struct,sizex,sizey,x,y);
		if(*npcpp!=NULL)
		{
			((NPC*)*npcpp)->always_on_top=1;
			((NPC*)*npcpp)->layer=1;
		}

	}
	else
	if(*npcpp!=NULL)
	{
		NPC_delete_npc(npcpp);
	}
}

//=========================================================================================================================
//void NPC_clone_main_sprite()
//{//=========================================================================================================================
	//int x = PLAYER_npc->MAP_x+10;
	//int y = PLAYER_npc->MAP_y+10;
	//NPC_create_npc(NULL,GFX_KID_yuu,PLAYER_npc->size_x,PLAYER_npc->size_y,x,y);
//}


//=========================================================================================================================
//void NPC_create_sprite(char *gfx_filename,int size_x,int size_y,int x,int y)
//{//=========================================================================================================================
	//NPC_create_npc(NULL,gfx_filename,size_x,size_y,x,y);
//}




//=========================================================================================================================
void NPC_delete_npc(NPC** npcpp)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_delete_npc()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_delete_npc()");return;}
	NPC* npc = *npcpp;


	if(npc!=NULL)
	{

		//if it's the first one, make the next one the first one.
		if(npc==first_NPC)
		{
			//if it's the only one, then npc->next will be NULL and this will set first_NPC to NULL
			//otherwise it makes the next one the first one
			first_NPC = npc->next;

		}
		else //connect the chain before and after this one
		{

			NPC* current_npc = first_NPC;

			//find the one that points to this npc (directly before it)
			while(current_npc->next!=npc)
			{
				current_npc = (NPC* )current_npc->next;
			}

			//set it to point to the one after this one
			//if this one is the last one it will point to NULL, so this will just set the second to last one to NULL.
			current_npc->next = npc->next;
		}

		if(npc->sprite!=NULL)HARDWARE_delete_sprite(npc->sprite);
		npc->sprite=NULL;

		NPC_stop_chasing(npcpp);
		NPC_stop_avoiding(npcpp);
		NPC_stop_following(npcpp);
		NPC_stop_pulling_against(npcpp);

		//if it has an external pointer (it should) then set that pointer to NULL
		if(npc->npcpp!=NULL)
		{
			//set the external pointer to NULL
			if(*(npc->npcpp)!=NULL)
			{
				*(npc->npcpp)=NULL;
			}

			//set the internal pointer to that pointer to NULL (dont really need to do this)
			npc->npcpp=NULL;
		}

		free(npc);
	}
}

//=========================================================================================================================
void NPC_delete_all_npcs()
{//=========================================================================================================================

	if(first_NPC!=NULL)
	{

		NPC* current_npc = first_NPC;

		while(current_npc->next!=NULL)
		{
			NPC* temp_npc = current_npc;
			current_npc = (NPC* )current_npc->next;

			if(temp_npc!=first_NPC)NPC_delete_npc(&temp_npc);
		}
		if(current_npc!=first_NPC)NPC_delete_npc(&current_npc);
	}

	NPC_delete_chase_structs();
	NPC_delete_follow_structs();
	NPC_delete_avoid_structs();
	NPC_delete_pull_againster_structs();
}



//=========================================================================================================================
void NPC_animate(NPC** npcpp)//increments the frame in the current walking direction
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_animate_increment_direction_frame_now()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_animate_increment_direction_frame_now()");return;}
	NPC* npc = *npcpp;


	///todo: the frame amount, gfx index, frame order, etc, should be stored in the NPC, pulled from the gfx data, pulled from the sprite config
	///should not need to use gfx data at all. should not need data size or size_x size_y

	int frame=0;
	int frame_order[8]={0,1,2,3,4,5,6,7};
	int amt_frames=8;

	npc->anim_frame_count++;
	if(npc->anim_frame_count>amt_frames-1)npc->anim_frame_count=0;
	frame=frame_order[npc->anim_frame_count];

	npc->vbl_animation_timer=0;

	npc->gfx_index = npc->data_size_x*npc->data_size_y*amt_frames*npc->walk_dir+(npc->data_size_x*npc->data_size_y*frame);

}


//=========================================================================================================================
void NPC_animate_dir(NPC** npcpp, int dir) //sets anim direction but doesnt set frame to 0
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_animate_increment_direction_frame_now()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_animate_increment_direction_frame_now()");return;}
	NPC* npc = *npcpp;


	///todo: the frame amount, gfx index, frame order, etc, should be stored in the NPC, pulled from the gfx data, pulled from the sprite config
	///should not need to use gfx data at all. should not need data size or size_x size_y

	int frame=0;
	int frame_order[8]={0,1,2,3,4,5,6,7};

	int amt_frames=0;

	amt_frames=8;

	npc->anim_frame_count++;
	if(npc->anim_frame_count>amt_frames-1)npc->anim_frame_count=0;
	frame=frame_order[npc->anim_frame_count];

	npc->vbl_animation_timer=0;

	npc->anim_dir=dir;

	npc->gfx_index = npc->data_size_x*npc->data_size_y*amt_frames*dir+(npc->data_size_x*npc->data_size_y*frame);

}

//=========================================================================================================================
void NPC_animate_cycle_through_frames_now(NPC** npcpp,int amt_of_frames) //cycles through arbitrary amount and order of frames
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_animate_cycle_through_frames_now()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_animate_cycle_through_frames_now()");return;}
	NPC* npc = *npcpp;

	 npc->anim_frame_count++;
	 if(npc->anim_frame_count>amt_of_frames-1)npc->anim_frame_count=0;

	 npc->vbl_animation_timer=0;

	npc->gfx_index = npc->data_size_x*npc->data_size_y*npc->anim_frame_count;

	//if(npc->random==1)NPC_random_update_gfx(npc,gfx_index);
	//else
	//{
		//if(npc->sprite!=NULL)HARDWARE_update_sprite_texture(npc->sprite,gfx_index);//doesnt care about sprite id
		//if(npc->gfx_slot_touchmap!=-1)HARDWARE_update_sprite_texture(0,npc->gfx_slot_touchmap,npc->gfx_struct,gfx_index, npc->shadow);
	//}

}
//=========================================================================================================================
void NPC_animate_stand_dir(NPC** npcpp,int anim_direction) //sets the frame to 0, sets anim direction
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_animate_set_direction_now()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_animate_set_direction_now()");return;}
	NPC* npc = *npcpp;

	if(npc->anim_dir!=anim_direction||npc->anim_frame_count!=0)
	{
		int frame=0;
		int frame_order[8]={0,1,2,3,4,5,6,7};

		int amt_frames=0;

		//if(npc==PLAYER_npc)amt_frames=8;else
		amt_frames=8;


		npc->anim_frame_count=0;
		npc->anim_dir=anim_direction;
		frame=frame_order[npc->anim_frame_count];

		npc->vbl_animation_timer=0;
		//if(npc->PLAYER_onscreen==1&&npc->PLAYER_id!=-1)
		//	HARDWARE_update_sprite_texture_by_sprite_id(1,npc->PLAYER_id,(unsigned char *)&npc->gfx_filename[npc->data_size_x*npc->data_size_y*4*npc->anim_direction+(npc->data_size_x*npc->data_size_y*frame)]);
		//if(npc->PLAYER_id_touchmap!=-1)
		//	HARDWARE_update_sprite_texture_by_sprite_id(0,npc->PLAYER_id_touchmap,(unsigned char *)&npc->gfx_filename[npc->data_size_x*npc->data_size_y*4*npc->anim_direction+(npc->data_size_x*npc->data_size_y*frame)]);


		npc->gfx_index = npc->data_size_x*npc->data_size_y*amt_frames*npc->anim_dir+(npc->data_size_x*npc->data_size_y*frame);

		//if(npc->random==1)NPC_random_update_gfx(npc,gfx_index);
		//else
		//{
			//if(npc->sprite!=NULL)HARDWARE_update_sprite_texture(npc->sprite,gfx_index);//doesnt care about sprite id
			//if(npc->gfx_slot_touchmap!=-1)HARDWARE_update_sprite_texture(0,npc->gfx_slot_touchmap,npc->gfx_struct,gfx_index, npc->shadow);
		//}
	}
}

//=========================================================================================================================
void NPC_stand(NPC** npcpp)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_stand()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_stand()");return;}
	NPC* npc = *npcpp;

	if(npc!=NULL)
	{
		if(npc->anim_frame_count!=0) //if not standing, stand.
		{
			npc->anim_frame_count=7;
			if(GLOBAL_npc_all_animation_off==0&&npc->animation_off==0)NPC_animate_dir(npcpp,npc->anim_dir);
		}
	}
}


//=========================================================================================================================
void NPC_set_anim_frame_now(NPC** npcpp,int frame) //sets arbitrary frame and nothing else
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_set_anim_frame_now()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_set_anim_frame_now()");return;}
	NPC* npc = *npcpp;

	if(npc->anim_frame_count!=frame)
	{
		npc->anim_frame_count=frame;
		//npc->anim_direction=frame;

		npc->vbl_animation_timer=0;


		npc->gfx_index = npc->data_size_x*npc->data_size_y*npc->anim_frame_count;

		//if(npc->random==1)NPC_random_update_gfx(npc,gfx_index);
		//else
		//{
			//if(npc->sprite!=NULL)HARDWARE_update_sprite_texture(npc->sprite,gfx_index);
		//}
	}
}
//=========================================================================================================================
bool NPC_should_animate(NPC** npcpp)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_should_animate()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_should_animate()");return 0;}
	NPC* npc = *npcpp;

	if(npc->walking_speed>=SPEED_NORMAL)//slower than normal
	{
		if(npc->vbl_animation_timer>npc->walking_speed/(GLOBALSPEED*6)&&npc->animation_off==0&&GLOBAL_npc_all_animation_off==0)
		{
			npc->vbl_animation_timer=0;
			return 1;
		}
	}
	else
	if(npc->vbl_animation_timer>npc->walking_speed/(GLOBALSPEED*2.5f)&&npc->animation_off==0&&GLOBAL_npc_all_animation_off==0)
	{
		npc->vbl_animation_timer=0;
		return 1;
	}

	return 0;
}

//=========================================================================================================================
void NPC_set_alpha(NPC** npcpp, int alpha)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_set_alpha()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_set_alpha()");return;}
	NPC* npc = *npcpp;

	if(npc!=NULL)
	{
		//if(alpha>255)alpha=255;
		//if(alpha<0)alpha=0;
		npc->alpha=alpha;
	}

}

//=========================================================================================================================
void NPC_vbl()
{//=========================================================================================================================

	if(first_NPC==NULL)return;


	if(first_NPC!=NULL)
	{
		int npc_onscreen_count=0;


		NPC* zstart=NULL;
		NPC* zcurrent=NULL;


		NPC* top_npc= NULL;

		int npccount=0;
		int npcs_pulling=0;

		NPC* current_npc = first_NPC;

		//-----------------------------
		//go through the whole npc linked list
		//-----------------------------
		bool stop=0;
		while(stop==0)
		{


				npccount++;

				//-----------------------------
				//set timers
				//-----------------------------
				current_npc->vbl_animation_timer++;
				current_npc->vbls++;
				if(current_npc->pull_player==1)npcs_pulling++;
				if(current_npc->vbls>=1024)current_npc->vbls=0;

				//-----------------------------
				//check if npc is onscreen
				//-----------------------------
				NPC_set_screen_xy(&current_npc);

				if(NPC_is_within_screen_bounds(&current_npc)&&current_npc->visible)
				{
					npc_onscreen_count++;

					//-----------------------------
					//make a zlist, with a start and an end, and in between only onscreen sprites
					//-----------------------------
					if(zstart==NULL)zstart=current_npc;
						else zcurrent->znext=(struct NPC*)current_npc;

					zcurrent=current_npc;
					current_npc->znext=NULL;

					//-----------------------------
					//and then we also find the topmost sprite while we are here
					//-----------------------------
					if(top_npc==NULL)top_npc=current_npc;
					if(current_npc->MAP_y+current_npc->size_y<=top_npc->MAP_y+top_npc->size_y)
					{
						top_npc=current_npc;
					}

					//-----------------------------
					//delete all onscreen npc sprites, we're going to reorder them.
					//-----------------------------
					//deleting all the sprites and recreating them isnt that big of a deal, all it does is free and malloc another sprite struct
					if(current_npc->sprite!=NULL)HARDWARE_delete_sprite(current_npc->sprite);
					current_npc->sprite=NULL;
				}

				//current_npc->PLAYER_onscreen=0;
				//if(current_npc->is_within_screen_bounds==0&&current_npc->gfx_slot!=-1){HARDWARE_delete_sprite_gfxslot(1,current_npc->gfx_slot);current_npc->gfx_slot=-1;}

				if(current_npc->next!=NULL)current_npc =(NPC*)current_npc->next; else stop=1;

				//could check for non-zordering npcs,npcs on top,npcs on bottom here.
				//could draw npcs always on top here and increment c for use below.
		}

//HERE IS A MUCH BETTER WAY,NO SCANLINES,NO ARRAYS
//go through once,make a new linked list of onscreen sprites,and a list of touchmap sprites
//then zorder those lists which are much smaller
//also can optimise the zlist as it goes through,each repetition is faster

		//-----------------------------
		//now we start at the top and find the bottommost npc onscreen and then draw it, we go through the list as many times as sprites we determined should be onscreen
		//-----------------------------
		NPC* bottom_npc = NULL;

		int c=0;
		for(c=0;c<npc_onscreen_count;c++)
		{
			bottom_npc=top_npc;
			current_npc = zstart;//this is the first onscreen npc we found

			NPC* previous_bottom_npc = NULL;
			NPC* previous_npc = NULL;

			//go through the onscreen list, find the bottommost
			stop=0;
			while(stop==0)
			{

				if(
					(
						current_npc->MAP_y+current_npc->size_y>=bottom_npc->MAP_y+bottom_npc->size_y//if this npc is lower than the topmost npc
						||
						current_npc->always_on_top
					)
					&&
					NPC_is_within_screen_bounds(&current_npc)
					&&
					current_npc->sprite==NULL
				)
				{
					previous_bottom_npc = previous_npc;
					bottom_npc = current_npc;
				}

				if(current_npc->znext!=NULL)
				{
					previous_npc=current_npc;
					current_npc=(NPC*)current_npc->znext;
				}
				else stop=1;
			}

			//now draw it and remove it from the onscreen list
			if(
				bottom_npc->sprite==NULL
				&&
				NPC_is_within_screen_bounds(&bottom_npc)
				&&
				bottom_npc->visible
			)
			{

				//NPC_set_shape_and_size(bottom_npc);
				//if(bottom_npc->gfx_slot==-1)
				//{
					//bottom_npc->gfx_slot = HARDWARE_create_sprite_gfxslot_alpha(1,bottom_npc->gfx_struct,bottom_npc->gfx_index,bottom_npc->data_size_x,bottom_npc->data_size_y,1,bottom_npc->shadow,bottom_npc->alpha);


					//if(bottom_npc->size_150_percent==1)NPC_set_car_anim_frame_now(bottom_npc, bottom_npc->walking_direction);//hack fix for CARS ONLY

				//}


				bottom_npc->sprite = HARDWARE_create_sprite(bottom_npc->gfx,bottom_npc->gfx_index,bottom_npc->layer,bottom_npc->scale,bottom_npc->screen_x,bottom_npc->screen_y,bottom_npc->alpha);

				//if any part of the feet are under a tile on the above layer, dont draw the shadow
					//3
					//0
					//2
					//1

				if(
						(
							bottom_npc->layer==3
							&&
							(
								HARDWARE_map_1[((((bottom_npc->MAP_y+bottom_npc->size_y-2)/8)*HARDWARE_map_width_tiles)+((bottom_npc->MAP_x/2+bottom_npc->size_x/2)/8))]!=0
								||
								HARDWARE_map_2[((((bottom_npc->MAP_y+bottom_npc->size_y-2)/8)*HARDWARE_map_width_tiles)+((bottom_npc->MAP_x/2+bottom_npc->size_x/2)/8))]!=0
							)
						)
						||
						(
							bottom_npc->layer==2
							&&
							HARDWARE_map_1[((((bottom_npc->MAP_y+bottom_npc->size_y-2)/8)*HARDWARE_map_width_tiles)+((bottom_npc->MAP_x+bottom_npc->size_x/2)/8))]!=0
						)
				)
				{
					//dont draw past the feet
					bottom_npc->sprite->draw_size_y=bottom_npc->size_y;
				}


				//-----------------------------
				//here we optimise the z list
				//-----------------------------
				if(bottom_npc==zstart)
				{
					if(bottom_npc->znext!=NULL)zstart=(NPC*)bottom_npc->znext;

				}
				else
				if(previous_bottom_npc!=NULL)//if its not the first one
				{
						if(bottom_npc->znext!=NULL)previous_bottom_npc->znext = bottom_npc->znext;//remove bottom_npc from zchain
						else previous_bottom_npc->znext = NULL;//if its the last one,set the previous one to be the last
				}
			}
		}


		//npcs_existing=npccount;
		GLOBAL_npcs_pulling_main_sprite=npcs_pulling;

		/*if(totalnpcs!=npccount)
		{
				totalnpcs=npccount;

				static CAPTION* npccountcaption= NULL;

				static char npcchar[4] = {0,0,0,'\0'};
				npcchar[0]=(totalnpcs/100)+48;
				npcchar[1]=(totalnpcs%100/10)+48;
				npcchar[2]=(totalnpcs%100%10)+48;
				if(npccountcaption!=NULL){CAPTION_replace_text(npccountcaption,(char*)npcchar);}
				if(npccountcaption==NULL)CAPTION_make_caption(&npccountcaption,0,128,10,-1,(char*)npcchar,FONT_TINY_ID,WHITE,BLACK);
		}*/


	} //end if PLAYER_npc!=NULL
}

//=========================================================================================================================
void NPC_main()
{//=========================================================================================================================


	NPC_pushable_avoid_other_npcs();//this does avoid for all the pushables.

	/* USEABLE NPC FUNCTIONS
	NPC_move_pixel(NPC* npc,int NPC_direction)
	NPC_walk_without_hit_detection(NPC* npc,int NPC_direction) NEED TO SET NPC->WALKING_SPEED,WILL DECREMENT NPC->PIXELS_TO_WALK
	NPC_walk(NPC* npc,int NPC_direction) NEED TO SET NPC->WALKING_SPEED,WILL DECREMENT NPC->PIXELS_TO_WALK,HAS HIT DETECTION WITH MAIN SPRITE,CAN USE NPC_IGNORE_SPRITE
	NPC_walk_dont_animate(NPC* npc,int NPC_direction)NEED TO SET NPC->WALKING SPEED,WILL DECREMENT NPC->PIXELS_TO_WALK,HAS HIT DETECTION WITH MAIN SPRITE AND WALLS,CAN USE NPC_IGNORE_SPRITE
	NPC_animate_increment_direction_frame_now(NPC* npc,int NPC_direction) SET NPC->ANIM_DIRECTION AND NPC->ANIM_FRAME_COUNT FIRST. INCREMENTS FRAME COUNT BY 1 SO MAKE IT -1 IF USING FOR STANDING
	NPC_animate_set_direction_now(NPC* npc,int anim_direction) SETS FRAME COUNT TO 0 AND ANIMATES TO DIRECTION INPUT
	NPC_animate_cycle_through_frames_now(NPC* npc,int amt_of_frames) NEEDS NPC->WALKING_SPEED TO BE SET,CYCLES DIRECTLY THROUGH AMT OF FRAMES YOU INPUT
	NPC_set_anim_frame_now(NPC* npc,int frame) USE TO SET ANY FRAME,DOESNT KEEP TRACK OF DIRECTIONS OR HOW MANY FRAMES OR ANYTHING
	NPC_random_walk_within_bounds(NPC* npc,int x1,int y1,int x2,int y2) HAS HIT DETECTION WITH MAIN SPRITE,CAN USE NPC_IGNORE_SPRITE
	NPC_randomly_walk_around_room(NPC* npc) HAS HIT DETECTION WITH MAIN SPRITE,CAN USE NPC_IGNORE_SPRITE
	NPC_randomly_walk_around_room_and_stop(NPC* npc)HAS HIT DETECTION WITH MAIN SPRITE,CAN USE NPC_IGNORE_SPRITE
	NPC_randomly_twitch_around_room(NPC) NO HIT DETECTION WITH MAIN SPRITE
	NPC_randomly_spin_around_room(NPC) NO HIT DETECTION WITH MAIN SPRITE
	NPC_follow_main_sprite(NPC* npc)NO HIT DETECTION WITH MAIN SPRITE
	bool NPC_walk_straight_to_point(NPC* npc,int speed,int x,int y) RETURNS 1 IF NPC IS AT COORDS,HAS HIT DETECTION WITH MAIN SPRITE,CAN USE NPC_IGNORE_SPRITE
	bool NPC_walk_to_point_LR_to_UD(NPC* npc,int speed,int x,int y) RETURNS 1 IF NPC IS AT COORDS,HAS HIT DETECTION WITH MAIN SPRITE,CAN USE NPC_IGNORE_SPRITE
	bool NPC_walk_to_point_UD_to_LR(NPC* npc,int speed,int x,int y) RETURNS 1 IF NPC IS AT COORDS,HAS HIT DETECTION WITH MAIN SPRITE,CAN USE NPC_IGNORE_SPRITE
	bool NPC_walk_distance(NPC* npc,int speed,int NPC_direction) RETURNS 1 IF NPC IS DONE WALKIN,NEEDS NPC->PIXELS_TO_WALK TO BE SET
	bool NPC_move_straight_to_point_without_hit_detection_or_animation(NPC* npc,int speed,int x,int y) RETURNS 1 IF NPC IS AT COORDS,NO HIT DETECTION WITH ANYTHING BE CAREFUL,DECREMENTS NPC->PIXELS_TO_WALK AS WELL
	NPC_walk_straight_from_point_to_point(NPC* npc,int speed,int x1,int y1,int x2,int y2) THIS USES WALKING DIRECTION AS A MOVEMENT SWITCH,HAS HIT DETECTION WITH MAIN SPRITE,CAN USE NPC_IGNORE_SPRITE
	NPC_walk_straight_from_point_to_point_and_stop(NPC* npc,int x1,int y1,int x2,int y2) THIS USES WALKING DIRECTION AS A MOVEMENT SWITCH,USES PIXELS TO WALK AS A STOP COUNTER,HAS HIT DETECTION WITH MAIN SPRITE,CAN USE NPC_IGNORE_SPRITE
	*/
	//MAKE DEINIT AND DELETE DESTROY THE NPC FOLLOW AND CHASE STRUCTS TOO
	//	static int memamt=0;
	//	mem_test *thingy = malloc(sizeof(mem_test));
	//	memamt++;
	//	int poo=0;
	//	for(poo=0;poo<1020;poo++)
	//	thingy->one_byte_array[poo]=254;
	//	ham_VBAText("thingy made at %X	made %d of em size %d\n",thingy,memamt,sizeof(mem_test));

//	static int movement_switch=20;

	/*if(BUTTON_ACTION_HELD)
	{
		while(BUTTON_ACTION_HELD&&MAIN_QUIT==false)whilefix();
		NPC_delete_chase_structs();
		movement_switch--;
	}
	if(movement_switch<0)movement_switch=23;*/

//	if(PLAYER_npc->next!=NULL)
//	{
//		NPC* previous_npc = PLAYER_npc;
//		NPC* current_npc = (NPC* )PLAYER_npc->next;
//		bool stop=0;
//		while(stop==0)
//		{
//	 	current_npc->non_walkable=1;
//		 current_npc->z_ordering=1;
//		 current_npc->pushable=1;
//		 static int circle_amt = 5;
//		 if(BUTTON_L_HELD)
//		 {
//			while(BUTTON_L_HELD&&MAIN_QUIT==false){whilefix();}
//			circle_amt++;
//		 }
//		if(movement_switch==0)NPC_randomly_walk_around_room(current_npc);
//		if(movement_switch==1)NPC_randomly_walk_around_room_and_stop(current_npc);
//		if(movement_switch==2)NPC_random_walk_within_bounds(current_npc,50,20,100,100);
//		if(movement_switch==3);
//		if(movement_switch==4)NPC_randomly_twitch_around_room(current_npc);
//		if(movement_switch==5)NPC_randomly_spin_around_room(current_npc);
//		if(movement_switch==6)NPC_walk_to_point_LR_to_UD(current_npc,SPEED_NORMAL,100,100);
//		if(movement_switch==7)NPC_walk_to_point_UD_to_LR(current_npc,SPEED_NORMAL,150,100);
//		if(movement_switch==8)NPC_walk_straight_to_point(current_npc,SPEED_NORMAL,200,100);
//		if(movement_switch==9)NPC_walk_straight_from_point_to_point(current_npc,SPEED_NORMAL,100,100,150,100);
//		if(movement_switch==10)NPC_walk_straight_from_point_to_point_and_stop(current_npc,100,100,150,100);
//		if(movement_switch==11){NPC_main_sprite_being_dragged=1;NPC_pull_against_main_sprite(current_npc);}else NPC_main_sprite_being_dragged=0;
//		if(movement_switch==12){PLAYER_input_off=1; NPC_randomly_spin_around_room(current_npc); NPC_main_sprite_follow_npc(current_npc);}else PLAYER_input_off=0;
//		if(movement_switch==13){if(NPC_avoid_npc(current_npc,PLAYER_npc,32))NPC_randomly_walk_around_room(current_npc);}
//		if(movement_switch==14)NPC_avoid_nearest_npc(current_npc,10);// THIS IS PUSHABLE WALKING CROWD
//		if(movement_switch==15)NPC_avoid_nearest_npc(current_npc,25);
//		if(movement_switch==16)NPC_pushable_crowd_behavior(current_npc);//THIS HAS AN AWESOME CROWD PUSHING EFFECT DONT TOUCH IT!!! its just avoid nearest npc with 10 avoid and no walking
//		if(movement_switch==17)NPC_dont_look_at_npc(current_npc,PLAYER_npc); // can combine this with crowd behavior,maybe everyones angry at you
//		if(movement_switch==18)NPC_stare_at_npc(current_npc,PLAYER_npc);
//		if(movement_switch==19)NPC_spin_in_circle(current_npc,circle_amt);
//		if(movement_switch==20)NPC_smart_avoid_npc(current_npc,PLAYER_npc);
//		if(movement_switch==21)NPC_chase_npc(current_npc,PLAYER_npc);
//		if(movement_switch==22)NPC_follow_npc(current_npc,previous_npc,20);
//		if(movement_switch==23)if(NPC_count==1)NPC_chase_nearest_npc(current_npc);else NPC_randomly_walk_around_room(current_npc);

//			//if(NPC_in_range_of_npc((void *)&npc[0],(void *)&npc[NPC_count]))ham_VBAText("YOU ARE TOUCHING NPC NUMBER %d!! \n",NPC_count);
//			//if(NPC_in_range_of_npc_direction(PLAYER_npc,current_npc,PLAYER_npc->anim_direction)){ham_VBAText("touching %d\n",PLAYER_npc->anim_direction);}
//			if(current_npc->next!=NULL)
//	 	{
//			previous_npc = (NPC* )current_npc;
//			current_npc = (NPC* )current_npc->next;
//	 	}
//	 	else stop=1;
//		}
//	}





	//int NPC_pull_againster_temp_amt = 0;
	//if(first_npc_pull_againster==NULL)NPC_pull_againster_temp_amt = 0;
	//else
	//{
		//NPC_pull_againster *current_npc_pull_againster = first_npc_pull_againster;
		//NPC_pull_againster_temp_amt = 1;
		//while(current_npc_pull_againster->next!=NULL)
		//{
		// current_npc_pull_againster = (NPC_pull_againster *)current_npc_pull_againster->next;
		// NPC_pull_againster_temp_amt++;
		//}
	//}
	//GLOBAL_npcs_pulling_main_sprite = NPC_pull_againster_temp_amt;
}

//=========================================================================================================================
void NPC_pause()
{//=========================================================================================================================

		//just deletes all the sprites

		if(first_NPC==NULL)return;

		NPC* current_npc = first_NPC;
		bool stop=0;
		while(stop==0)
		{
			if(current_npc->sprite!=NULL)HARDWARE_delete_sprite(current_npc->sprite);
			current_npc->sprite=NULL;


			if(current_npc->next!=NULL)current_npc = (NPC* )current_npc->next; else stop=1;
		}

}

//=========================================================================================================================
void NPC_unpause()
{//=========================================================================================================================

		//NPC_delete_all_npcs();

		NPC_vbl();

		//HARDWARE_create_sprite(1,main_sprite_shadow->PLAYER_id,main_sprite_shadow->gfx_slot,PLAYER_npc->data_size_x,PLAYER_npc->data_size_y,1,0,1,0,0,0,2,0,PLAYER_npc->screen_x,PLAYER_npc->screen_y);
		//HARDWARE_set_sprite_alpha(1,main_sprite_shadow->PLAYER_id,1);

		//HARDWARE_create_sprite(0,main_sprite_shadow->PLAYER_id_touchmap,main_sprite_shadow->gfx_slot_touchmap,PLAYER_npc->data_size_x,PLAYER_npc->data_size_y,1,0,0,0,0,0,2,0,PLAYER_npc->screen_x_touchmap,PLAYER_npc->screen_y_touchmap);
		//HARDWARE_set_sprite_rotation(0,main_sprite_shadow->PLAYER_id_touchmap,0);
		//HARDWARE_set_sprite_alpha(0,main_sprite_shadow->PLAYER_id_touchmap,1);
}
