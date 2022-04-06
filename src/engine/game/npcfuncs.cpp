
#include "../../main.h"
//#include "npcfuncs.h"


//=========================================================================================================================
void NPC_animate_if_needed(NPC** npcpp, int dir)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_animate_if_needed()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_animate_if_needed()");return;}
	NPC* npc = *npcpp;


	if(npc->anim_dir!=dir)
	{
		if(GLOBAL_npc_all_animation_off==0&&npc->animation_off==0)NPC_animate_stand_dir(npcpp,dir);
	}

	if(NPC_should_animate(npcpp))
	{
		NPC_animate_dir(npcpp,dir);
	}
}
//=========================================================================================================================
void NPC_move_pixel(NPC** npcpp, int dir)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_move_pixel()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_move_pixel()");return;}
	NPC* npc = *npcpp;


	npc->walk_dir=dir;

	if(dir==DOWNLEFT){npc->MAP_x--;npc->MAP_y++;}
	else if(dir==DOWNRIGHT){npc->MAP_x++;npc->MAP_y++;}
	else if(dir==UPLEFT){npc->MAP_x--;npc->MAP_y--;}
	else if(dir==UPRIGHT){npc->MAP_x++;npc->MAP_y--;}
	else if(dir==UP){npc->MAP_y--;}
	else if(dir==DOWN){npc->MAP_y++;}
	else if(dir==LEFT){npc->MAP_x--;}
	else if(dir==RIGHT){npc->MAP_x++;}
}

//=========================================================================================================================
void NPC_move_pixel_animate(NPC** npcpp, int dir)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_move_pixel_animate()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_move_pixel_animate()");return;}
	//NPC* npc = *npcpp;

	NPC_move_pixel(npcpp,dir);
	NPC_animate_if_needed(npcpp,dir);
}

//=========================================================================================================================
bool NPC_check_hit_move_pixel(NPC** npcpp, int dir)	//returns 0 if hit wall   ( DOES HIT DETECTION/WALL DETECTION,HIT WITH SPRITE DETECTION )
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_check_hit_move_pixel()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_check_hit_move_pixel()");return 0;}
	NPC* npc = *npcpp;



	bool moved=true;

	if(!NPC_check_hit_layer_direction(npcpp,dir))
	{
		if(npc->is_walking_into_player==0||npc->ignore_player==1)NPC_move_pixel(npcpp,dir);
	}
	else {moved=false;}

	return moved;
}

//=========================================================================================================================
void NPC_check_hit_move_pixel_animate(NPC** npcpp,int dir)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_check_hit_move_pixel_animate()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_check_hit_move_pixel_animate()");return;}
	NPC* npc = *npcpp;


	if(npc==PLAYER_npc)PLAYER_check_hit_move_pixel_animate(dir);
	else
	{

		if(!NPC_check_hit_layer_direction(npcpp,dir))
		{
			if(npc->is_walking_into_player==0||npc->ignore_player==1)NPC_move_pixel_animate(npcpp,dir);
		}
	}
}
//=========================================================================================================================
void NPC_walk_direction(NPC** npcpp,int NPC_direction)
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_walk_direction()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_walk_direction()");return;}
	NPC* npc = *npcpp;

	if(npc->ms>npc->walking_speed)
	{
		NPC_check_hit_move_pixel_animate(npcpp,NPC_direction);

		if(npc->is_walking_into_player==1)npc->anim_frame_count=7;
		if(npc->is_walking_into_wall==1){npc->anim_frame_count=7;npc->pixels_to_walk=r(10);}
		if(npc->pixels_to_walk>0&&npc->is_walking_into_player==0)npc->pixels_to_walk--;

		npc->walk_dir=NPC_direction;

		npc->ms=0;
	}
}



//=========================================================================================================================
bool NPC_move_to_xy_nohit_noanim(NPC** npcpp,int speed,int x,int y)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_move_to_xy_nohit_noanim()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_move_to_xy_nohit_noanim()");return 0;}
	NPC* npc = *npcpp;


	npc->walking_speed = speed;


	int npcx = npc->MAP_x+npc->size_x/2;
	int npcy = npc->MAP_y+(npc->size_y-npc->hitsize_y);

	if(x==-1)x=npcx;
	if(y==-1)y=npcy;

	bool there_yet=0;

	if(npc->ms>npc->walking_speed)
	{


			//WALK PERFECT DIAGONAL

			int ydistance=0;
			int xdistance=0;
			if(npcy>y)ydistance=npcy-y;
			if(npcy<y)ydistance=y-npcy;

			if(npcx>x)xdistance=npcx-x;
			if(npcx<x)xdistance=x-npcx;



		float x_to_y_ratio=0;
		if(ydistance!=0)x_to_y_ratio=xdistance/ydistance;
		float y_to_x_ratio=0;
		if(xdistance!=0)y_to_x_ratio=ydistance/xdistance;


			if(xdistance>=ydistance||y_to_x_ratio<npc->y_pixel_counter)
			{
				if(npcx>x)npc->MAP_x--;
				if(npcx<x)npc->MAP_x++;
				npc->x_pixel_counter++;
				npc->y_pixel_counter=0;
			}

			if(ydistance>=xdistance||x_to_y_ratio<npc->x_pixel_counter)
			{
				if(npcy>y)npc->MAP_y--;
				if(npcy<y)npc->MAP_y++;
				npc->y_pixel_counter++;
				npc->x_pixel_counter=0;
			}



		if(npc->pixels_to_walk>0)npc->pixels_to_walk--;

		npc->ms=0;
	}

	npcx = npc->MAP_x+npc->size_x/2;
	npcy = npc->MAP_y+(npc->size_y-npc->hitsize_y);

	if(npcx==x&&npcy==y)
	{
		there_yet=1;
		npc->y_pixel_counter=0;
		npc->x_pixel_counter=0;
	}

	return there_yet;
}
//=========================================================================================================================
void NPC_walk_dont_animate(NPC** npcpp,int NPC_direction)
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_walk_dont_animate()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_walk_dont_animate()");return;}
	NPC* npc = *npcpp;

	if(npc->ms>npc->walking_speed)
	{
		NPC_check_hit_move_pixel(npcpp,NPC_direction);
		if(npc->pixels_to_walk>0&&npc->is_walking_into_player==0)npc->pixels_to_walk--;
		npc->ms=0;
	}
}
//=========================================================================================================================
void NPC_walk_without_hit_detection(NPC** npcpp,int NPC_direction)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_walk_without_hit_detection()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_walk_without_hit_detection()");return;}
	NPC* npc = *npcpp;


	if(npc->ms>npc->walking_speed)
	{
		if(npc->anim_dir!=NPC_direction)
		{
			if(GLOBAL_npc_all_animation_off==0&&npc->animation_off==0)NPC_animate_dir(npcpp,NPC_direction);
			npc->anim_dir=NPC_direction;
		}
		if(NPC_direction==UP)npc->MAP_y--;
		if(NPC_direction==DOWN)npc->MAP_y++;
		if(NPC_direction==LEFT)npc->MAP_x--;
		if(NPC_direction==RIGHT)npc->MAP_x++;

		if(npc->pixels_to_walk>0)npc->pixels_to_walk--;

		npc->walk_dir=NPC_direction;

		if(NPC_should_animate(npcpp))
		{
			if(GLOBAL_npc_all_animation_off==0&&npc->animation_off==0)NPC_animate_dir(npcpp,NPC_direction);
		}
	npc->ms=0;
	}
}
//=========================================================================================================================
void NPC_walk_randomly_around_room_and_stop(NPC** npcpp)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_walk_randomly_around_room_and_stop()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_walk_randomly_around_room_and_stop()");return;}
	NPC* npc = *npcpp;


	if(npc->pixels_to_walk==0)
	{
		npc->walk_dir=r(4);
		npc->pixels_to_walk=(r(100))+10;
		npc->walking_speed =((rand()%(SPEED_FASTEST-SPEED_SLOWEST))+SPEED_SLOWEST);
	}
	if(npc->pixels_to_walk==1){npc->walking_speed=(rand()%(SPEED_FASTEST-SPEED_SLOWEST))+SPEED_SLOWEST;npc->anim_frame_count=7;if(GLOBAL_npc_all_animation_off==0&&npc->animation_off==0)NPC_animate_dir(npcpp,npc->anim_dir);}

	if(npc->ms>npc->walking_speed)
	{
		if(npc->anim_dir!=npc->walk_dir)
		{
			if(GLOBAL_npc_all_animation_off==0&&npc->animation_off==0)NPC_animate(npcpp);
			npc->anim_dir=npc->walk_dir;
		}
		NPC_check_hit_move_pixel(npcpp,npc->walk_dir);
		if(npc->is_walking_into_player==1)npc->anim_frame_count=7;
		if(npc->is_walking_into_wall==1){npc->anim_frame_count=7;npc->pixels_to_walk=0;}
		if(npc->pixels_to_walk>0&&npc->is_walking_into_player==0)npc->pixels_to_walk--;
		if(NPC_should_animate(npcpp))
		{
			if(GLOBAL_npc_all_animation_off==0&&npc->animation_off==0)NPC_animate(npcpp);
		}
		npc->ms=0;
	}
}

//=========================================================================================================================
void NPC_walk_randomly_around_room_and_stop_no_animation(NPC** npcpp)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_walk_randomly_around_room_and_stop_no_animation()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_walk_randomly_around_room_and_stop_no_animation()");return;}
	NPC* npc = *npcpp;

	if(npc->pixels_to_walk==0)
	{
		npc->walk_dir=r(4);
		npc->pixels_to_walk=(r(100))+10;
		npc->walking_speed =((rand()%(SPEED_FASTEST-SPEED_SLOWEST))+SPEED_SLOWEST);
	}

	if(npc->pixels_to_walk==2){npc->vbl_animation_timer=0;npc->pixels_to_walk--;}
	if(npc->pixels_to_walk==1)if(npc->vbl_animation_timer>120)npc->pixels_to_walk=0;

	if(npc->ms>npc->walking_speed&&npc->pixels_to_walk>1)
	{
		npc->pixels_to_walk--;
		NPC_check_hit_move_pixel(npcpp,npc->walk_dir);
		npc->ms=0;
	}
}
//=========================================================================================================================
void NPC_walk_randomly_around_room(NPC** npcpp)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_walk_randomly_around_room()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_walk_randomly_around_room()");return;}
	NPC* npc = *npcpp;


	if(npc->pixels_to_walk==0)
	{
		npc->walk_dir=r(4);
		npc->pixels_to_walk=(r(100))+10;
		npc->walking_speed =(rand()%(SPEED_FASTEST-SPEED_SLOWEST))+SPEED_SLOWEST;
	}
	NPC_walk_direction(npcpp,npc->walk_dir);
}
//=========================================================================================================================
bool NPC_walk_randomly_within_xy_xy(NPC** npcpp,int x1,int y1,int x2,int y2)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_walk_randomly_within_xy_xy()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_walk_randomly_within_xy_xy()");return 0;}
	NPC* npc = *npcpp;


	if(npc->pixels_to_walk==0)
	{
		npc->walk_dir=r(4);

		if((x2-x1)>(y2-y1)){npc->pixels_to_walk=rand()%(x2-x1);} else {npc->pixels_to_walk=rand()%(y2-y1);}
		npc->walking_speed =(rand()%(SPEED_FASTEST-SPEED_SLOWEST))+SPEED_SLOWEST;
	}

	bool can_walk=0;

	if(npc->walk_dir==UP&&npc->MAP_y+(npc->size_y-npc->hitsize_y)>y1)can_walk=1;
	if(npc->walk_dir==DOWN&&npc->MAP_y+npc->size_y<y2)can_walk=1;
	if(npc->walk_dir==LEFT&&npc->MAP_x>x1)can_walk=1;
	if(npc->walk_dir==RIGHT&&npc->MAP_x+npc->size_x<x2)can_walk=1;

	if(npc->pixels_to_walk==1)//&&r(3)==1)
	{
		NPC_stand(npcpp);
	}

	if(can_walk==1)NPC_walk_direction_avoid_other_npcs(npcpp,npc->walk_dir);
		else npc->pixels_to_walk=0;

	if(npc->pixels_to_walk==0)return 1;
	return 0;
}
//=========================================================================================================================
void NPC_randomly_twitch_around_room(NPC** npcpp)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_randomly_twitch_around_room()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_randomly_twitch_around_room()");return;}
	NPC* npc = *npcpp;

	if(npc->pixels_to_walk==0||npc->pixels_to_walk>5)
	{
		npc->walk_dir=r(4);
		npc->pixels_to_walk=(r(5))+1;
		npc->walking_speed = SPEED_FAST;
	}
	npc->ignore_player=1;
	if(npc->ms>npc->walking_speed)
	{
		if(npc->anim_dir!=npc->walk_dir)
		{
			if(GLOBAL_npc_all_animation_off==0&&npc->animation_off==0)NPC_animate(npcpp);
			npc->anim_dir=npc->walk_dir;
		}
		NPC_check_hit_move_pixel(npcpp,npc->walk_dir);
		if(npc->is_walking_into_wall==1)npc->pixels_to_walk=0;
		if(npc->pixels_to_walk>0&&npc->is_walking_into_player==0)npc->pixels_to_walk--;
		if(NPC_should_animate(npcpp))
		{
			if(GLOBAL_npc_all_animation_off==0&&npc->animation_off==0)NPC_animate_dir(npcpp,npc->anim_dir);
		}
		npc->ms=0;
	}
	npc->ignore_player=0;
}
//=========================================================================================================================
void NPC_randomly_spin_around_room(NPC** npcpp)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_randomly_spin_around_room()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_randomly_spin_around_room()");return;}
	NPC* npc = *npcpp;


	npc->walking_speed = SPEED_FAST;
	if(npc->walk_dir<4)npc->walk_dir=(r(4))+4;

	if(NPC_should_animate(npcpp)) //spin regardless of walking
	{
		npc->anim_dir++; if(npc->anim_dir>3)npc->anim_dir=0;
		if(GLOBAL_npc_all_animation_off==0&&npc->animation_off==0)NPC_animate_dir(npcpp,npc->anim_dir);
	}
	if(npc->ms>npc->walking_speed)
	{
		npc->ignore_player=1;

		if(npc->walk_dir==UPLEFT)
		{
			NPC_check_hit_move_pixel(npcpp,UP);
			if(npc->is_walking_into_wall==1)npc->walk_dir=DOWNLEFT;

			NPC_check_hit_move_pixel(npcpp,LEFT);
			if(npc->is_walking_into_wall==1&&npc->walk_dir==UPLEFT)npc->walk_dir=UPRIGHT;
			if(npc->is_walking_into_wall==1&&npc->walk_dir==DOWNLEFT)npc->walk_dir=DOWNRIGHT;
		}
		else
		if(npc->walk_dir==UPRIGHT)
		{
			NPC_check_hit_move_pixel(npcpp,UP);
			if(npc->is_walking_into_wall==1)npc->walk_dir=DOWNRIGHT;

			NPC_check_hit_move_pixel(npcpp,RIGHT);
			if(npc->is_walking_into_wall==1&&npc->walk_dir==UPRIGHT)npc->walk_dir=UPLEFT;
			if(npc->is_walking_into_wall==1&&npc->walk_dir==DOWNRIGHT)npc->walk_dir=DOWNLEFT;
		}
		else
		if(npc->walk_dir==DOWNLEFT)
		{
			NPC_check_hit_move_pixel(npcpp,DOWN);
			if(npc->is_walking_into_wall==1)npc->walk_dir=UPLEFT;

			NPC_check_hit_move_pixel(npcpp,LEFT);
			if(npc->is_walking_into_wall==1&&npc->walk_dir==DOWNLEFT)npc->walk_dir=DOWNRIGHT;
			if(npc->is_walking_into_wall==1&&npc->walk_dir==UPLEFT)npc->walk_dir=UPRIGHT;
		}
		else
		if(npc->walk_dir==DOWNRIGHT)
		{
			NPC_check_hit_move_pixel(npcpp,DOWN);
			if(npc->is_walking_into_wall==1)npc->walk_dir=UPRIGHT;

			NPC_check_hit_move_pixel(npcpp,RIGHT);
			if(npc->is_walking_into_wall==1&&npc->walk_dir==DOWNRIGHT)npc->walk_dir=DOWNLEFT;
			if(npc->is_walking_into_wall==1&&npc->walk_dir==UPRIGHT)npc->walk_dir=UPLEFT;
		}

		npc->ignore_player=0;
		npc->ms=0;
	}
}

//=========================================================================================================================
void NPC_main_sprite_follow_npc(NPC** npcpp)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_main_sprite_follow_npc()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_main_sprite_follow_npc()");return;}
	NPC* npc = *npcpp;

	if(PLAYER_npc==NULL){ERROR_set_error("NPC_main_sprite_follow_npc()");return;}


	static int x_path[25]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	static int y_path[25]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	static int last_x=0;
	static int last_y=0;
	static int stand_count=0;

	if(npc->MAP_x<last_x-10||npc->MAP_x>last_x+10||npc->MAP_y<last_y-10||npc->MAP_y>last_y+10)
	{
		int t;
		for(t=0;t<25;t++)
		{
			x_path[t]=npc->MAP_x;
			y_path[t]=npc->MAP_y;
		}
		last_x=npc->MAP_x;
		last_y=npc->MAP_y;
	}
	PLAYER_npc->walking_speed=npc->walking_speed;

	if(npc->MAP_x!=last_x||npc->MAP_y!=last_y)
	{
		//can move npc up the array chain
		stand_count=0;
		if(x_path[23]>x_path[24]&&y_path[23]<y_path[24])PLAYER_npc->anim_dir=UPRIGHT;
		else if(x_path[23]<x_path[24]&&y_path[23]<y_path[24])PLAYER_npc->anim_dir=UPLEFT;
		else if(x_path[23]>x_path[24]&&y_path[23]>y_path[24])PLAYER_npc->anim_dir=DOWNRIGHT;
		else if(x_path[23]<x_path[24]&&y_path[23]>y_path[24])PLAYER_npc->anim_dir=DOWNLEFT;
		else if(x_path[23]>x_path[24])PLAYER_npc->anim_dir=RIGHT;
		else if(x_path[23]<x_path[24])PLAYER_npc->anim_dir=LEFT;
		else if(y_path[23]>y_path[24])PLAYER_npc->anim_dir=DOWN;
		else if(y_path[23]<y_path[24])PLAYER_npc->anim_dir=UP;

		if(NPC_should_animate(&PLAYER_npc))
		{
			if(GLOBAL_npc_all_animation_off==0&&PLAYER_npc->animation_off==0)NPC_animate_dir(&PLAYER_npc,PLAYER_npc->anim_dir);
		}

		int l;
		for(l=24;l>0;l--)
		{
			x_path[l]=x_path[l-1];
			y_path[l]=y_path[l-1];
		}
		x_path[0]=npc->MAP_x;
		y_path[0]=npc->MAP_y;

		last_x=npc->MAP_x;
		last_y=npc->MAP_y;
	}
	else
	{
		stand_count++;

		if(stand_count>200)
		{
			NPC_stand(npcpp);
		}
	}
	PLAYER_npc->MAP_x=x_path[24];
	PLAYER_npc->MAP_y=y_path[24];
}
//=========================================================================================================================
void NPC_follow_npc(NPC** follower_npcpp,NPC** follow_npcpp,int follow_amt)
{//=========================================================================================================================

	if(follower_npcpp==NULL){ERROR_set_error("NPC_follow_npc()");return;}
	if(*follower_npcpp==NULL){ERROR_set_error("NPC_follow_npc()");return;}
	NPC* follower_npc = *follower_npcpp;

	if(follow_npcpp==NULL){ERROR_set_error("NPC_follow_npc()");return;}
	if(*follow_npcpp==NULL){ERROR_set_error("NPC_follow_npc()");return;}
	NPC* follow_npc = *follow_npcpp;


	/*typedef struct
	{
	int NPC_id;
	int x_path[25];
	int y_path[25];
	int last_x;
	int last_y;
	int index;
	struct NPC_follower *next;
	}NPC_follower;*/

	if(follow_amt>25)follow_amt=25;

	NPC_follower *current_npc_follower = NULL;
	if(first_npc_follower==NULL)
	{
		first_npc_follower = (NPC_follower*)malloc(sizeof(NPC_follower));
		first_npc_follower->NPC_id = follower_npc;

		int f=0;
		for(f=0;f<follow_amt;f++)
		{
			first_npc_follower->x_path[f] = follow_npc->MAP_x;
			first_npc_follower->y_path[f] = follow_npc->MAP_y;
		}
		first_npc_follower->last_x =follow_npc->MAP_x;
		first_npc_follower->last_y =follow_npc->MAP_y;
		first_npc_follower->index =0;
		first_npc_follower->next=NULL;
	}

	current_npc_follower = first_npc_follower;
	while(current_npc_follower->NPC_id!=follower_npc)
	{
		if(current_npc_follower->next!=NULL)
		{
			NPC_follower *temp = (NPC_follower *)current_npc_follower->next;
			current_npc_follower = temp;
		}
		else
		{
			current_npc_follower->next = (NPC_follower*)malloc(sizeof(NPC_follower));
			current_npc_follower = (NPC_follower *)current_npc_follower->next;
			current_npc_follower->NPC_id = follower_npc;
			int f=0;
			for(f=0;f<follow_amt;f++)
			{
				current_npc_follower->x_path[f] = follow_npc->MAP_x;
				current_npc_follower->y_path[f] = follow_npc->MAP_y;
			}
			current_npc_follower->last_x =follow_npc->MAP_x;
			current_npc_follower->last_y =follow_npc->MAP_y;
			current_npc_follower->index =0;
			current_npc_follower->next=NULL;
		}
	}

	if(follow_npc->MAP_x<current_npc_follower->last_x-16||follow_npc->MAP_x>current_npc_follower->last_x+16||follow_npc->MAP_y<current_npc_follower->last_y-16||follow_npc->MAP_y>current_npc_follower->last_y+16)
	{
		NPC_follower *temp_npc_follower = first_npc_follower;
		bool stop=0;
		while(stop==0)
		{
			int t;
			for(t=0;t<follow_amt;t++)
			{
				temp_npc_follower->x_path[t]=follow_npc->MAP_x;
				temp_npc_follower->y_path[t]=follow_npc->MAP_y;
			}
			temp_npc_follower->last_x=follow_npc->MAP_x;
			temp_npc_follower->last_y=follow_npc->MAP_y;

			if(temp_npc_follower->next!=NULL)temp_npc_follower = (NPC_follower *)temp_npc_follower->next;
			else stop=1;
		}
	}
	follower_npc->walking_speed=follow_npc->walking_speed;

	if(follow_npc->MAP_x!=current_npc_follower->last_x||follow_npc->MAP_y!=current_npc_follower->last_y)
	{
		//can move npc up the array chain
		current_npc_follower->NPC_id->ms=0;
		int plustwo=0;
		int plusone=0;
		if(current_npc_follower->index+2>follow_amt-1)
		{
			if(current_npc_follower->index+1>follow_amt-1)
			{
				plusone=0;
				plustwo=1;
			}
			else
			{
				plusone = current_npc_follower->index+1;
				plustwo=0;
			}
		}
		else
		{
			plustwo=current_npc_follower->index+2;
			plusone=current_npc_follower->index+1;
		}
		if(current_npc_follower->x_path[plustwo]>current_npc_follower->x_path[plusone])follower_npc->anim_dir=RIGHT;
		if(current_npc_follower->x_path[plustwo]<current_npc_follower->x_path[plusone])follower_npc->anim_dir=LEFT;
		if(current_npc_follower->y_path[plustwo]>current_npc_follower->y_path[plusone])follower_npc->anim_dir=DOWN;
		if(current_npc_follower->y_path[plustwo]<current_npc_follower->y_path[plusone])follower_npc->anim_dir=UP;
		if(NPC_should_animate(follower_npcpp))
		{
			if(GLOBAL_npc_all_animation_off==0&&follower_npc->animation_off==0)NPC_animate_dir(follower_npcpp,follower_npc->anim_dir);
		}
		int newest=0;
		newest=current_npc_follower->index;
		current_npc_follower->index=plusone;
		current_npc_follower->x_path[newest]=follow_npc->MAP_x;
		current_npc_follower->y_path[newest]=follow_npc->MAP_y;
		current_npc_follower->last_x=follow_npc->MAP_x;
		current_npc_follower->last_y=follow_npc->MAP_y;
	}
	else
	{
		if(current_npc_follower->NPC_id->ms>50)
		{
			NPC_stand(follower_npcpp);
		}
	}
	follower_npc->MAP_x=current_npc_follower->x_path[current_npc_follower->index];
	follower_npc->MAP_y=current_npc_follower->y_path[current_npc_follower->index];
}
//=========================================================================================================================
void NPC_stop_following(NPC** npcpp)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_stop_following()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_stop_following()");return;}
	NPC* npc = *npcpp;


	NPC_follower *current_npc_follower = first_npc_follower;
	if(current_npc_follower!=NULL)
	{
		if(current_npc_follower->NPC_id==npc)
		{
		first_npc_follower = (NPC_follower *)current_npc_follower->next;
		free(current_npc_follower);
		}
		else
		{
		while(current_npc_follower->next!=NULL)
		{
			NPC_follower *temp_npc_follower = (NPC_follower *)current_npc_follower->next;
			if(temp_npc_follower->NPC_id==npc)
			{
				current_npc_follower->next = temp_npc_follower->next;
				free(temp_npc_follower);
			}
			if(current_npc_follower->next!=NULL)current_npc_follower = (NPC_follower *)current_npc_follower->next;
		}
		}
	}
}
//=========================================================================================================================
void NPC_pull_against_main_sprite(NPC** npcpp)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_pull_against_main_sprite()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_pull_against_main_sprite()");return;}
	NPC* npc = *npcpp;

	if(PLAYER_npc==NULL){ERROR_set_error("NPC_pull_against_main_sprite()");return;}


	//NPC_pull_againster *current_npc_pull_againster = NULL;
	//NPC_pull_againster *previous_npc_pull_againster = NULL;

	//if(first_npc_pull_againster==NULL)
	//{
		//first_npc_pull_againster = malloc(sizeof(NPC_pull_againster));
		//first_npc_pull_againster->NPC_id = in_npc;
		//NPC_stop_following(in_npc);
		//first_npc_pull_againster->next=NULL;
	//}

	//current_npc_pull_againster = first_npc_pull_againster;
	//while(current_npc_pull_againster->NPC_id!=in_npc)
	//{
	//	if(current_npc_pull_againster->next!=NULL)
	//	{
	//		NPC_pull_againster *temp = (NPC_pull_againster *)current_npc_pull_againster->next;
	//		previous_npc_pull_againster = current_npc_pull_againster;
	//		current_npc_pull_againster = temp;
	//	}
	//	else
	//	{
	//		previous_npc_pull_againster = current_npc_pull_againster;
	//		current_npc_pull_againster->next = malloc(sizeof(NPC_pull_againster));
	//		NPC_stop_following(in_npc);
	//		current_npc_pull_againster = (NPC_pull_againster *)current_npc_pull_againster->next;
	//		current_npc_pull_againster->NPC_id = in_npc;
	//		current_npc_pull_againster->next=NULL;
	//	}
	//}

	npc->pull_player=1;
	npc->animation_off=1; //dont automatically animate

	NPC_follow_npc(npcpp,&PLAYER_npc,10);
	//else NPC_follow_npc(npc,previous_npc_pull_againster->NPC_id ,10);

	npc->anim_frame_count = 0;// always animate on frame 1
	NPC_animate_dir(npcpp,npc->anim_dir);

}
//=========================================================================================================================
void NPC_stop_pulling_against(NPC** npcpp)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_stop_pulling_against()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_stop_pulling_against()");return;}
	NPC* npc = *npcpp;


	NPC_stop_following(npcpp);

	//NPC_pull_againster *current_npc_pull_againster = first_npc_pull_againster;
	//if(current_npc_pull_againster!=NULL)
	//{
	//	if(current_npc_pull_againster->NPC_id==delete_npc)
	//	{
	//		first_npc_pull_againster = (NPC_pull_againster *)current_npc_pull_againster->next;
	//		free(current_npc_pull_againster);
	//	}
	//	else
	//	{
	//		while(current_npc_pull_againster->next!=NULL)
	//		{
	//			NPC_pull_againster *temp_npc_pull_againster = (NPC_pull_againster *)current_npc_pull_againster->next;
	//			if(temp_npc_pull_againster->NPC_id==delete_npc)
	//			{
	//				current_npc_pull_againster->next = temp_npc_pull_againster->next;
	//				free(temp_npc_pull_againster);
	//			}
	//			if(current_npc_pull_againster->next!=NULL)current_npc_pull_againster = (NPC_pull_againster *)current_npc_pull_againster->next;
	//		}
	//	}
	//}
	npc->pull_player=0;
	npc->animation_off=0;

}
//=========================================================================================================================
bool NPC_walk_to_xy_LR_to_UD(NPC** npcpp,int speed,int x,int y)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_walk_to_xy_LR_to_UD()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_walk_to_xy_LR_to_UD()");return 0;}
	NPC* npc = *npcpp;


	npc->walking_speed = speed;
	bool there_yet=0;

	if(npc->MAP_x+npc->size_x/2<x){NPC_walk_direction(npcpp,RIGHT);there_yet=0;}
		else if(npc->MAP_x+npc->size_x/2>x){NPC_walk_direction(npcpp,LEFT);there_yet=0;}
			else if(npc->MAP_y+(npc->size_y-npc->hitsize_y)<y){NPC_walk_direction(npcpp,DOWN);there_yet=0;}
				else if(npc->MAP_y+(npc->size_y-npc->hitsize_y)>y){NPC_walk_direction(npcpp,UP);there_yet=0;}
					else there_yet=1;

	if(npc->is_walking_into_wall==1)
	{
		if(npc->MAP_y+(npc->size_y-npc->hitsize_y)<y){NPC_check_hit_move_pixel(npcpp,DOWN);there_yet=0;}
			else if(npc->MAP_y+(npc->size_y-npc->hitsize_y)>y){NPC_check_hit_move_pixel(npcpp,UP);there_yet=0;}
				else if(npc->MAP_x+npc->size_x/2<x){NPC_check_hit_move_pixel(npcpp,RIGHT);there_yet=0;}
					else if(npc->MAP_x+npc->size_x/2>x){NPC_check_hit_move_pixel(npcpp,LEFT);there_yet=0;}
	}

	if(there_yet==1)
	{
		NPC_stand(npcpp);
	}

	return there_yet;
}
//=========================================================================================================================
bool NPC_walk_to_xy_UD_to_LR(NPC** npcpp,int speed,int x,int y)
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_walk_to_xy_UD_to_LR()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_walk_to_xy_UD_to_LR()");return 0;}
	NPC* npc = *npcpp;

	npc->walking_speed = speed;

	bool there_yet=0;

	if(npc->MAP_y+(npc->size_y-npc->hitsize_y)<y){NPC_walk_direction(npcpp,DOWN);there_yet=0;}
		else if(npc->MAP_y+(npc->size_y-npc->hitsize_y)>y){NPC_walk_direction(npcpp,UP);there_yet=0;}
			else if(npc->MAP_x+npc->size_x/2<x){NPC_walk_direction(npcpp,RIGHT);there_yet=0;}
				else if(npc->MAP_x+npc->size_x/2>x){NPC_walk_direction(npcpp,LEFT);there_yet=0;}
					else there_yet=1;

	if(npc->is_walking_into_wall==1)
	{
		if(npc->MAP_x+npc->size_x/2<x){NPC_check_hit_move_pixel(npcpp,RIGHT);there_yet=0;}
			else if(npc->MAP_x+npc->size_x/2>x){NPC_check_hit_move_pixel(npcpp,LEFT);there_yet=0;}
				else if(npc->MAP_y+(npc->size_y-npc->hitsize_y)<y){NPC_check_hit_move_pixel(npcpp,DOWN);there_yet=0;}
					else if(npc->MAP_y+(npc->size_y-npc->hitsize_y)>y){NPC_check_hit_move_pixel(npcpp,UP);there_yet=0;}
	}

	if(there_yet==1)
	{
		NPC_stand(npcpp);
	}

	return there_yet;
}
//=========================================================================================================================
bool NPC_walk_to_xy_basichit(NPC** npcpp,int speed,int x,int y)
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_walk_to_xy_basichit()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_walk_to_xy_basichit()");return 0;}
	NPC* npc = *npcpp;

	npc->ignore_player=1;
	npc->walking_speed = speed;

	int npcx = npc->MAP_x+npc->size_x/2;
	int npcy = npc->MAP_y+(npc->size_y-npc->hitsize_y);

	if(x==-1)x=npcx;
	if(y==-1)y=npcy;

	bool there_yet=0;
	int direction=0;

	if(npc->ms>npc->walking_speed)
	{



			//WALK PERFECT DIAGONAL

			int ydistance=0;
			int xdistance=0;
			if(npcy>y)ydistance=npcy-y;
			if(npcy<y)ydistance=y-npcy;

			if(npcx>x)xdistance=npcx-x;
			if(npcx<x)xdistance=x-npcx;



		float x_to_y_ratio=0;
		if(ydistance!=0)x_to_y_ratio=xdistance/ydistance;
		float y_to_x_ratio=0;
		if(xdistance!=0)y_to_x_ratio=ydistance/xdistance;


			if(xdistance>=ydistance||y_to_x_ratio<npc->y_pixel_counter)
			{
				if(npcx>x){npc->MAP_x--;if(!npc->is_walking_into_wall&&ydistance<=xdistance)direction=LEFT;}
				if(npcx<x){npc->MAP_x++;if(!npc->is_walking_into_wall&&ydistance<=xdistance)direction=RIGHT;}
				npc->x_pixel_counter++;
				npc->y_pixel_counter=0;
			}

			if(ydistance>=xdistance||x_to_y_ratio<npc->x_pixel_counter)
			{
				if(npcy>y){npc->MAP_y--;if(ydistance>xdistance)direction=UP;}
				if(npcy<y){npc->MAP_y++;if(ydistance>xdistance)direction=DOWN;}
				npc->y_pixel_counter++;
				npc->x_pixel_counter=0;
			}






		if(npc->pixels_to_walk>0&&npc->is_walking_into_player==0)npc->pixels_to_walk--;

		npc->ms=0;
	}

	if(npc->MAP_x+npc->size_x/2==x&&npc->MAP_y+(npc->size_y-npc->hitsize_y)==y)
	{
		there_yet=1;

		npc->y_pixel_counter=0;
		npc->x_pixel_counter=0;

		NPC_stand(npcpp);
	}

	if(NPC_should_animate(npcpp)&&there_yet==0&&npc->is_walking_into_player==0&&npc->is_walking_into_wall==0)
	{
		if(GLOBAL_npc_all_animation_off==0&&npc->animation_off==0){npc->anim_dir=direction;NPC_animate_dir(npcpp,npc->anim_dir);}
	}
	else
		if(npc->is_walking_into_player==1||npc->is_walking_into_wall==1)
		{
			NPC_stand(npcpp);
		}

	return there_yet;
}

//=========================================================================================================================
bool NPC_walk_to_xy_nohit(NPC** npcpp,int speed,int x,int y)
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_walk_to_xy_nohit()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_walk_to_xy_nohit()");return 0;}
	NPC* npc = *npcpp;


	npc->ignore_player=1;
	npc->walking_speed = speed;

	int npcx = npc->MAP_x+npc->size_x/2;
	int npcy = npc->MAP_y+(npc->size_y-npc->hitsize_y);

	if(x==-1)x=npcx;
	if(y==-1)y=npcy;



	bool there_yet=0;

	if(npcx==x&&npcy==y)
	{
		there_yet=1;

		npc->y_pixel_counter=0;
		npc->x_pixel_counter=0;

		NPC_stand(npcpp);
	}
	else
	{

		if(npc->ms>npc->walking_speed)
		{


			int direction=0;


			//WALK PERFECT DIAGONAL

			int ydistance=0;
			int xdistance=0;
			if(npcy>y)ydistance=npcy-y;
			if(npcy<y)ydistance=y-npcy;

			if(npcx>x)xdistance=npcx-x;
			if(npcx<x)xdistance=x-npcx;



		float x_to_y_ratio=0;
		if(ydistance!=0)x_to_y_ratio=xdistance/ydistance;
		float y_to_x_ratio=0;
		if(xdistance!=0)y_to_x_ratio=ydistance/xdistance;


			if(xdistance>=ydistance||y_to_x_ratio<npc->y_pixel_counter)
			{
				if(npcx>x){npc->MAP_x--;if(!npc->is_walking_into_wall&&ydistance<=xdistance)direction=LEFT;}
				if(npcx<x){npc->MAP_x++;if(!npc->is_walking_into_wall&&ydistance<=xdistance)direction=RIGHT;}
				npc->x_pixel_counter++;
				npc->y_pixel_counter=0;
			}

			if(ydistance>=xdistance||x_to_y_ratio<npc->x_pixel_counter)
			{
				if(npcy>y){npc->MAP_y--;if(ydistance>xdistance)direction=UP;}
				if(npcy<y){npc->MAP_y++;if(ydistance>xdistance)direction=DOWN;}
				npc->y_pixel_counter++;
				npc->x_pixel_counter=0;
			}






			if(npc->anim_dir!=direction&&GLOBAL_npc_all_animation_off==0&&npc->animation_off==0){npc->anim_dir=direction;NPC_animate_dir(npcpp,npc->anim_dir);}//animate change direction

			if(npc->pixels_to_walk>0&&npc->is_walking_into_player==0)npc->pixels_to_walk--;

			npc->ms=0;
		}

		if(NPC_should_animate(npcpp)&&there_yet==0&&npc->is_walking_into_player==0&&npc->is_walking_into_wall==0)// animate walking.
		{
			if(GLOBAL_npc_all_animation_off==0&&npc->animation_off==0)NPC_animate_dir(npcpp,npc->anim_dir);
		}
		else
			if(npc->is_walking_into_player==1||npc->is_walking_into_wall==1) //if hit a wall or main sprite stand.
			{
				NPC_stand(npcpp);
			}
	}
	return there_yet;
}
//=========================================================================================================================
bool NPC_walk_to_xy_nohit_avoidothers_pushmain(NPC** npcpp,int speed,int x,int y)
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_walk_to_xy_nohit_avoidothers_pushmain()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_walk_to_xy_nohit_avoidothers_pushmain()");return 0;}
	NPC* npc = *npcpp;

	if(PLAYER_npc==NULL){ERROR_set_error("NPC_walk_to_xy_nohit_avoidothers_pushmain()");return 0;}


	npc->ignore_player=1;
	npc->walking_speed = speed;

	bool there_yet=0;

	int npcx = npc->MAP_x+npc->size_x/2;
	int npcy = npc->MAP_y+(npc->size_y-npc->hitsize_y);

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


			int direction=npc->anim_dir;

			NPC* nearestnpc = NPC_find_nearest_npc(npcpp);

			/*if(npc->nearest_npc!=NULL)
			{
				if(npc->standing_cycles!=0)
				{
					nearestnpc=(NPC*)npc->nearest_npc;
					npc->standing_cycles--;
				}
				else
				{
					npc->nearest_npc=(struct NPC*)nearestnpc;
					npc->standing_cycles=r(10);
				}
			}
			else
			{
				npc->nearest_npc=(struct NPC*)nearestnpc;
				nearestnpc=(NPC*)npc->nearest_npc;
			}*/


			int collide=0;
			int hit_ms=0;

			//WALK PERFECT DIAGONAL

			int ydistance=0;
			int xdistance=0;
			if(npcy>y)ydistance=npcy-y;
			if(npcy<y)ydistance=y-npcy;

			if(npcx>x)xdistance=npcx-x;
			if(npcx<x)xdistance=x-npcx;



			float x_to_y_ratio=0;
			if(ydistance!=0)x_to_y_ratio=xdistance/ydistance;

			float y_to_x_ratio=0;
			if(xdistance!=0)y_to_x_ratio=ydistance/xdistance;



			if(ydistance>=xdistance||x_to_y_ratio<npc->x_pixel_counter) //walk the greater distance first, up/down vs left/right
			{
				if(npcy<y)//walking down
				{

					if(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,12)==1)
					{
						if(nearestnpc==PLAYER_npc)
						{
							hit_ms=1;

						}
						//else
						if((npc->anim_dir==UP&&nearestnpc->MAP_y<=npc->MAP_y)||(npc->anim_dir==DOWN&&nearestnpc->MAP_y>=npc->MAP_y))
						if(npc->anim_dir!=nearestnpc->anim_dir||npc->walking_speed<=nearestnpc->walking_speed)
						{
							if(npcx<nearestnpc->MAP_x+nearestnpc->size_x/2){npc->MAP_x-=1;collide=1;}
							else {npc->MAP_x+=1;collide=1;}
						}
					}
					//else
					{
						npc->MAP_y++;
						npc->y_pixel_counter++;
						npc->x_pixel_counter=0;
						npc->standing_cycles=0;

					}
					if(ydistance>xdistance)direction=DOWN;


				}
				if(npcy>y)
				{
					if(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,13)==1)
					{
						if(nearestnpc==PLAYER_npc)
						{
							hit_ms=1;
						}
						//else
						if((npc->anim_dir==UP&&nearestnpc->MAP_y<=npc->MAP_y)||(npc->anim_dir==DOWN&&nearestnpc->MAP_y>=npc->MAP_y))
						if(npc->anim_dir!=nearestnpc->anim_dir||npc->walking_speed<=nearestnpc->walking_speed)
						//if(npc->standing_cycles==0&&nearestnpc->standing_cycles==0)
						{
							if(npcx<=nearestnpc->MAP_x+nearestnpc->size_x/2){npc->MAP_x-=1;collide=1;} //else walk left if slightly left
								else {npc->MAP_x+=1;collide=1;}		//else walk right
						}
					}
					//else
					{
						npc->MAP_y--;
						npc->y_pixel_counter++;
						npc->x_pixel_counter=0;
						npc->standing_cycles=0;

					}
					if(ydistance>xdistance)direction=UP;
				}
			}

			if(xdistance>=ydistance||y_to_x_ratio<npc->y_pixel_counter)
			{
				if(npcx<x)
				{
					if(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,12)==1)
					{
						if(nearestnpc==PLAYER_npc)
						{
							hit_ms=1;
						}
						//else
						if((npc->anim_dir==LEFT&&nearestnpc->MAP_x<=npc->MAP_x)||(npc->anim_dir==RIGHT&&nearestnpc->MAP_x>=npc->MAP_x))
						if(npc->anim_dir!=nearestnpc->anim_dir||npc->walking_speed<=nearestnpc->walking_speed)
						//if(npc->standing_cycles==0&&nearestnpc->standing_cycles==0)
						{
							if(npc->MAP_y+npc->size_y-(npc->hitsize_y/2)<nearestnpc->MAP_y+nearestnpc->size_y-(nearestnpc->hitsize_y/2)){npc->MAP_y-=1;collide=1;} //else walk up if slightly above
								else {npc->MAP_y+=1;collide=1;}			//else walk down

						}
					}
					//else
					{

						npc->MAP_x++;
						npc->x_pixel_counter++;
						npc->y_pixel_counter=0;
						npc->standing_cycles=0;

					}
					if(ydistance<xdistance&&xdistance-ydistance>8)direction=RIGHT;
				}



				if(npcx>x)
				{
					if(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,13)==1)
					{
						if(nearestnpc==PLAYER_npc)
						{
							hit_ms=1;
						}
						//else
						if((npc->anim_dir==LEFT&&nearestnpc->MAP_x<=npc->MAP_x)||(npc->anim_dir==RIGHT&&nearestnpc->MAP_x>=npc->MAP_x))
						if(npc->anim_dir!=nearestnpc->anim_dir||npc->walking_speed<=nearestnpc->walking_speed)
						//if(npc->standing_cycles==0&&nearestnpc->standing_cycles==0)
						{
							if(npc->MAP_y+npc->size_y-(npc->hitsize_y/2)<=nearestnpc->MAP_y+nearestnpc->size_y-(nearestnpc->hitsize_y/2)){npc->MAP_y-=1;collide=1;} //else walk up if slightly above
								else {npc->MAP_y+=1;collide=1;}			//else walk down
						}
					}
					//else
					{
						npc->MAP_x--;
						npc->x_pixel_counter++;
						npc->y_pixel_counter=0;
						npc->standing_cycles=0;

					}
					if(ydistance<xdistance&&xdistance-ydistance>8)direction=LEFT;
				}
			}

			if(collide==1)
			if(nearestnpc->anim_dir==npc->anim_dir&&nearestnpc->walking_speed==npc->walking_speed)
			{
				npc->walking_speed+=GLOBALSPEED*1;
			}

			if(hit_ms)
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
					NPC_animate_dir(&nearestnpc,wd);


			}

			if(npc->anim_dir!=direction&&GLOBAL_npc_all_animation_off==0&&npc->animation_off==0)
			{
				npc->anim_dir=direction;
				NPC_animate_dir(npcpp,npc->anim_dir);
			}//animate change direction

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


//=========================================================================================================================
bool NPC_walk_to_xy_stop_for_other_npcs_amt(NPC** npcpp,int speed,int x,int y,int amt)
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_walk_to_xy_stop_for_other_npcs_amt()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_walk_to_xy_stop_for_other_npcs_amt()");return 0;}
	NPC* npc = *npcpp;


	npc->ignore_player=1;
	npc->walking_speed = speed;

	bool there_yet=0;

	int npcx = npc->MAP_x+npc->size_x/2;
	int npcy = npc->MAP_y+(npc->size_y-npc->hitsize_y);

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


			int direction=npc->anim_dir;

			NPC* nearestnpc = NPC_find_nearest_npc(npcpp);

			/*if(npc->nearest_npc!=NULL)
			{
				if(npc->standing_cycles!=0)
				{
					nearestnpc=(NPC*)npc->nearest_npc;
					npc->standing_cycles--;
				}
				else
				{
					npc->nearest_npc=(struct NPC*)nearestnpc;
					npc->standing_cycles=r(10);
				}
			}
			else
			{
				npc->nearest_npc=(struct NPC*)nearestnpc;
				nearestnpc=(NPC*)npc->nearest_npc;
			}*/




			//WALK PERFECT DIAGONAL

			int ydistance=0;
			int xdistance=0;
			if(npcy>y)ydistance=npcy-y;
			if(npcy<y)ydistance=y-npcy;

			if(npcx>x)xdistance=npcx-x;
			if(npcx<x)xdistance=x-npcx;



			float x_to_y_ratio=0;
			if(ydistance!=0)x_to_y_ratio=xdistance/ydistance;

			float y_to_x_ratio=0;
			if(xdistance!=0)y_to_x_ratio=ydistance/xdistance;



			if(ydistance>=xdistance||x_to_y_ratio<npc->x_pixel_counter) //walk the greater distance first, up/down vs left/right
			{
				if(npcy<y)//walking down
				{

					if(
							!(
									(
										(npc->MAP_x>=nearestnpc->MAP_x&&npc->MAP_x<=nearestnpc->MAP_x+nearestnpc->size_x)||
										(npc->MAP_x+npc->size_x>=nearestnpc->MAP_x&&npc->MAP_x+npc->size_x<=nearestnpc->MAP_x+nearestnpc->size_x)||
										(nearestnpc->MAP_x>=npc->MAP_x&&nearestnpc->MAP_x<=npc->MAP_x+npc->size_x)||
										(nearestnpc->MAP_x+nearestnpc->size_x>=npc->MAP_x&&nearestnpc->MAP_x+nearestnpc->size_x<=npc->MAP_x+npc->size_x)
									)
									&&(npc->MAP_y+npc->size_y<=nearestnpc->MAP_y+(nearestnpc->size_y-nearestnpc->hitsize_y))
									&&(npc->MAP_y+npc->size_y>=(nearestnpc->MAP_y+(nearestnpc->size_y-nearestnpc->hitsize_y))-amt)
								)
						)
					{
						npc->MAP_y++;
						npc->y_pixel_counter++;
						npc->x_pixel_counter=0;
						npc->standing_cycles=0;

					}
					if(ydistance>xdistance)direction=DOWN;

				}

				if(npcy>y)//walking up
				{
					if(
							!(
									(
										(npc->MAP_x>=nearestnpc->MAP_x&&npc->MAP_x<=nearestnpc->MAP_x+nearestnpc->size_x)||
										(npc->MAP_x+npc->size_x>=nearestnpc->MAP_x&&npc->MAP_x+npc->size_x<=nearestnpc->MAP_x+nearestnpc->size_x)||
										(nearestnpc->MAP_x>=npc->MAP_x&&nearestnpc->MAP_x<=npc->MAP_x+npc->size_x)||
										(nearestnpc->MAP_x+nearestnpc->size_x>=npc->MAP_x&&nearestnpc->MAP_x+nearestnpc->size_x<=npc->MAP_x+npc->size_x)
									)
									&&(npc->MAP_y+(npc->size_y-npc->hitsize_y)>=nearestnpc->MAP_y+nearestnpc->size_y)
									&&(npc->MAP_y+(npc->size_y-npc->hitsize_y)<=(nearestnpc->MAP_y+nearestnpc->size_y)+amt)
								)
						)
					{
						npc->MAP_y--;
						npc->y_pixel_counter++;
						npc->x_pixel_counter=0;
						npc->standing_cycles=0;

					}
					if(ydistance>xdistance)direction=UP;
				}
			}


			if(xdistance>=ydistance||y_to_x_ratio<npc->y_pixel_counter)
			{
				if(npcx<x)//moving right
				{
					if(
							!(
									(
										(npc->MAP_y+(npc->size_y-npc->hitsize_y)>=nearestnpc->MAP_y+(nearestnpc->size_y-nearestnpc->hitsize_y)&&npc->MAP_y+(npc->size_y-npc->hitsize_y)<=nearestnpc->MAP_y+nearestnpc->size_y)||
										(npc->MAP_y+npc->size_y>=nearestnpc->MAP_y+(nearestnpc->size_y-nearestnpc->hitsize_y)&&npc->MAP_y+npc->size_y<=nearestnpc->MAP_y+nearestnpc->size_y)
									)
									&&(npc->MAP_x+npc->size_x<=nearestnpc->MAP_x)
									&&(npc->MAP_x+npc->size_x>=(nearestnpc->MAP_x)-amt)
								)
						)
					{

						npc->MAP_x++;
						npc->x_pixel_counter++;
						npc->y_pixel_counter=0;
						npc->standing_cycles=0;

					}
					if(ydistance<xdistance&&xdistance-ydistance>8)direction=RIGHT;
				}



				if(npcx>x)
				{
					if(
							!(
									(
										(npc->MAP_y+(npc->size_y-npc->hitsize_y)>=nearestnpc->MAP_y+(nearestnpc->size_y-nearestnpc->hitsize_y)&&npc->MAP_y+(npc->size_y-npc->hitsize_y)<=nearestnpc->MAP_y+nearestnpc->size_y)||
										(npc->MAP_y+npc->size_y>=nearestnpc->MAP_y+(nearestnpc->size_y-nearestnpc->hitsize_y)&&npc->MAP_y+npc->size_y<=nearestnpc->MAP_y+nearestnpc->size_y)
									)
									&&(npc->MAP_x>=nearestnpc->MAP_x+nearestnpc->size_x)
									&&(npc->MAP_x<=(nearestnpc->MAP_x+nearestnpc->size_x)+amt)
								)
						)
					{
						npc->MAP_x--;
						npc->x_pixel_counter++;
						npc->y_pixel_counter=0;
						npc->standing_cycles=0;

					}
					if(ydistance<xdistance&&xdistance-ydistance>8)direction=LEFT;
				}
			}


			if(npc->anim_dir!=direction&&GLOBAL_npc_all_animation_off==0&&npc->animation_off==0)
			{
				npc->anim_dir=direction;
				NPC_animate_dir(npcpp,npc->anim_dir);
			}//animate change direction

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
//=========================================================================================================================
void NPC_walk_direction_avoid_other_npcs(NPC** npcpp,int NPC_direction)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_walk_direction_avoid_other_npcs()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_walk_direction_avoid_other_npcs()");return;}
	NPC* npc = *npcpp;


	if(npc->ms>npc->walking_speed)
	{
		if(npc->anim_dir!=NPC_direction)
		{
			if(GLOBAL_npc_all_animation_off==0&&npc->animation_off==0)NPC_animate_dir(npcpp,NPC_direction);
			npc->anim_dir=NPC_direction;
		}

		int direction=0;
		NPC* nearestnpc = NPC_find_nearest_npc(npcpp);

		if(NPC_direction==DOWN)
		{
			if(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,8+r(6))==1)
			{
				if(npc->MAP_x+npc->size_x/2<=nearestnpc->MAP_x+nearestnpc->size_x/2)npc->MAP_x-=r(2);
					else npc->MAP_x+=r(2);
			}
			else
			{
				NPC_check_hit_move_pixel(npcpp,DOWN);
			}
			direction=DOWN;
		}

		if(NPC_direction==UP)
		{
			if(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,8+r(6))==1)
			{
				if(npc->MAP_x+npc->size_x/2<nearestnpc->MAP_x+nearestnpc->size_x/2)npc->MAP_x-=r(2); //else walk left if slightly left
					else npc->MAP_x+=r(2);			//else walk right
			}
			else
			{
				NPC_check_hit_move_pixel(npcpp,UP);
			}
			direction=UP;
		}

		if(NPC_direction==RIGHT)
		{
			if(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,8+r(6))==1)
			{
				if(npc->MAP_y+(npc->size_y-npc->hitsize_y)/2<=nearestnpc->MAP_y+nearestnpc->size_y-nearestnpc->hitsize_y/2)npc->MAP_y-=r(2); //else walk up if slightly above
					else npc->MAP_y+=r(2);			//else walk down
			}
			else
			{
				NPC_check_hit_move_pixel(npcpp,RIGHT);
			}
			direction=RIGHT;
		}

		if(NPC_direction==LEFT)
		{
			if(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,8+r(6))==1)
			{
				if(npc->MAP_y+(npc->size_y-npc->hitsize_y)/2<nearestnpc->MAP_y+nearestnpc->size_y-nearestnpc->hitsize_y/2)npc->MAP_y-=r(2); //else walk up if slightly above
					else npc->MAP_y+=r(2);			//else walk down
			}
			else
			{
				NPC_check_hit_move_pixel(npcpp,LEFT);
			}
			direction=LEFT;
		}

		if(npc->is_walking_into_player==1)npc->anim_frame_count=7;
		if(npc->is_walking_into_wall==1){npc->anim_frame_count=7;npc->pixels_to_walk=r(10);}
		if(npc->pixels_to_walk>0&&npc->is_walking_into_player==0)npc->pixels_to_walk--;

		npc->walk_dir=NPC_direction;
		if(NPC_should_animate(npcpp))
		{
			if(GLOBAL_npc_all_animation_off==0&&npc->animation_off==0)NPC_animate_dir(npcpp,NPC_direction);
		}

		npc->ms=0;
	}
}
//=========================================================================================================================
bool NPC_walk_to_xy_nohit_pushmain(NPC** npcpp,int speed,int x,int y)
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_walk_to_xy_nohit_pushmain()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_walk_to_xy_nohit_pushmain()");return 0;}
	NPC* npc = *npcpp;

	if(PLAYER_npc==NULL){ERROR_set_error("NPC_walk_to_xy_nohit_pushmain()");return 0;}

	npc->ignore_player=1;
	npc->walking_speed = speed;

	bool there_yet=0;

	if(x==-1)x=npc->MAP_x+npc->size_x/2;
	if(y==-1)y=npc->MAP_y+(npc->size_y-npc->hitsize_y);

	if(npc->MAP_x+npc->size_x/2==x&&npc->MAP_y+(npc->size_y-npc->hitsize_y)==y)
	{
		there_yet=1;

		NPC_stand(npcpp);
	}
	else
	{

		if(npc->ms>npc->walking_speed)
		{

			int xdistance=(npc->MAP_x+npc->size_x/2)-x;
			int ydistance=((npc->MAP_y+npc->size_y)-npc->hitsize_y)-y;

			if(xdistance<0)xdistance*=-1;
			if(ydistance<0)ydistance*=-1;

			int direction=0;

			if(ydistance>=xdistance) //walk the greater distance first, up/down vs left/right
			{
				if((npc->MAP_y+npc->size_y)-npc->hitsize_y<y)
				{

					if(NPC_in_range_of_npc_in_direction_by_amount(npcpp,&PLAYER_npc,DOWN,0)==1)
					{

							//push main sprite down
							if(!PLAYER_check_hit_layer(DOWN)&&!PLAYER_check_hit_non_walkable_npcs(DOWN))PLAYER_npc->MAP_y++;

							if(npc->MAP_x+npc->size_x/2<PLAYER_npc->MAP_x+PLAYER_npc->size_x/2)
							{//push main sprite right
								if(!PLAYER_check_hit_layer(RIGHT)&&!PLAYER_check_hit_non_walkable_npcs(RIGHT))PLAYER_npc->MAP_x++;
							}
							else
							{//push main sprite left
								if(!PLAYER_check_hit_layer(LEFT)&&!PLAYER_check_hit_non_walkable_npcs(LEFT))PLAYER_npc->MAP_x--;
							}
					}

					npc->MAP_y++;
					direction=DOWN;

				}
				if(npc->MAP_y+(npc->size_y-npc->hitsize_y)>y)
				{
					if(NPC_in_range_of_npc_in_direction_by_amount(npcpp,&PLAYER_npc,UP,0)==1)
					{
							//push main sprite up
							if(!PLAYER_check_hit_layer(UP)&&!PLAYER_check_hit_non_walkable_npcs(UP))PLAYER_npc->MAP_y--;

							if(npc->MAP_x+npc->size_x/2<=PLAYER_npc->MAP_x+PLAYER_npc->size_x/2)
							{//push main sprite right
								if(!PLAYER_check_hit_layer(RIGHT)&&!PLAYER_check_hit_non_walkable_npcs(RIGHT))PLAYER_npc->MAP_x++;
							}
							else
							{//push main sprite left
								if(!PLAYER_check_hit_layer(LEFT)&&!PLAYER_check_hit_non_walkable_npcs(LEFT))PLAYER_npc->MAP_x--;
							}
					}
					npc->MAP_y--;
					direction=UP;

				}
			}

			if(xdistance>=ydistance)
			{
				if(npc->MAP_x+npc->size_x/2<x)
				{
					if(NPC_in_range_of_npc_in_direction_by_amount(npcpp,&PLAYER_npc,RIGHT,0)==1)
					{
							//push main sprite right
							if(!PLAYER_check_hit_layer(RIGHT)&&!PLAYER_check_hit_non_walkable_npcs(RIGHT))PLAYER_npc->MAP_x++;

							if(npc->MAP_y+(npc->size_y-npc->hitsize_y)/2>=(PLAYER_npc->MAP_y+PLAYER_npc->size_y)-PLAYER_npc->hitsize_y/2)
							{//push main sprite up
								if(!PLAYER_check_hit_layer(UP)&&!PLAYER_check_hit_non_walkable_npcs(UP))PLAYER_npc->MAP_y--;
							}
							else
							{//push main sprite down
								if(!PLAYER_check_hit_layer(DOWN)&&!PLAYER_check_hit_non_walkable_npcs(DOWN))PLAYER_npc->MAP_y++;
							}
					}
					npc->MAP_x++;
					direction=RIGHT;

				}
				if(npc->MAP_x+npc->size_x/2>x)
				{
					if(NPC_in_range_of_npc_in_direction_by_amount(npcpp,&PLAYER_npc,LEFT,0)==1)
					{
							//push main sprite left
							if(!PLAYER_check_hit_layer(LEFT)&&!PLAYER_check_hit_non_walkable_npcs(LEFT))PLAYER_npc->MAP_x--;

							if(npc->MAP_y+(npc->size_y-npc->hitsize_y)/2>=PLAYER_npc->MAP_y+PLAYER_npc->size_y-PLAYER_npc->hitsize_y/2)
							{//push main sprite up
								if(!PLAYER_check_hit_layer(UP)&&!PLAYER_check_hit_non_walkable_npcs(UP))PLAYER_npc->MAP_y--;
							}
							else
							{//push main sprite down
								if(!PLAYER_check_hit_layer(DOWN)&&!PLAYER_check_hit_non_walkable_npcs(DOWN))PLAYER_npc->MAP_y++;
							}

					}
					npc->MAP_x--;
					direction=LEFT;

				}
			}

			if(npc->anim_dir!=direction&&GLOBAL_npc_all_animation_off==0&&npc->animation_off==0){npc->anim_dir=direction;NPC_animate_dir(npcpp,npc->anim_dir);}//animate change direction

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














///TEMP TEMP TEMP



















//=========================================================================================================================
bool NPC_walk_to_xy_intelligenthit_pushothers(NPC** npcpp,int speed,int x,int y)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_walk_to_xy_intelligenthit_pushothers()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_walk_to_xy_intelligenthit_pushothers()");return 0;}
	NPC* npc = *npcpp;

	if(PLAYER_npc==NULL){ERROR_set_error("NPC_walk_to_xy_intelligenthit_pushothers()");return 0;}


	npc->ignore_player=1;
	npc->walking_speed = speed;

	bool there_yet=0;

	if(x==-1)x=npc->MAP_x+npc->size_x/2;
	if(y==-1)y=npc->MAP_y+(npc->size_y-npc->hitsize_y);



	if(npc->MAP_x+npc->size_x/2==x&&npc->MAP_y+(npc->size_y-npc->hitsize_y)==y)
	{
		there_yet=1;

		NPC_stand(npcpp);
	}
	else
	{


		if(npc->ms>npc->walking_speed)
		{

			int xdistance=(npc->MAP_x+npc->size_x/2)-x;
			int ydistance=((npc->MAP_y+npc->size_y)-npc->hitsize_y)-y;

			if(xdistance<0)xdistance*=-1;
			if(ydistance<0)ydistance*=-1;

			int direction=0;
			NPC* nearestnpc = NPC_find_nearest_npc(npcpp);



///==================================

			if(ydistance>=xdistance)//walk the greater distance first, up/down vs left/right
			{
				if((npc->MAP_y+npc->size_y)-npc->hitsize_y<y)
				{
					if(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,7)==1)
					{
						if(nearestnpc==PLAYER_npc)
						{
							//push main sprite down
							if(!PLAYER_check_hit_layer(DOWN)&&!PLAYER_check_hit_non_walkable_npcs(DOWN))PLAYER_npc->MAP_y++;

							if(npc->MAP_x+npc->size_x/2<nearestnpc->MAP_x+nearestnpc->size_x/2)
							{//push main sprite right
								if(!PLAYER_check_hit_layer(RIGHT)&&!PLAYER_check_hit_non_walkable_npcs(RIGHT))PLAYER_npc->MAP_x++;
							}
							else
							{//push main sprite left
								if(!PLAYER_check_hit_layer(LEFT)&&!PLAYER_check_hit_non_walkable_npcs(LEFT))PLAYER_npc->MAP_x--;
							}
						}

						else

						{

							NPC_check_hit_move_pixel(&nearestnpc,DOWN);

							if(npc->MAP_x+npc->size_x/2<=nearestnpc->MAP_x+nearestnpc->size_x/2)
							{
								NPC_check_hit_move_pixel(&nearestnpc,RIGHT);
							}
							else
							{
								NPC_check_hit_move_pixel(&nearestnpc,LEFT);
							}
						}

						direction=DOWN;


					}

					{
						if(NPC_check_hit_move_pixel(npcpp,DOWN)==0||NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,7)==1)
						{
							if(npc->walk_dir!=LEFT&&npc->walk_dir!=RIGHT)
							{
								if(r(2)==0)npc->walk_dir=LEFT;
								else npc->walk_dir=RIGHT;
							}
						}
						else
						{
							npc->walk_dir=4;
							direction=DOWN;
						}
					}

				}

				///======
				///======
				///======
				///======


				if(npc->MAP_y+(npc->size_y-npc->hitsize_y)>y)
				{
					if(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,7)==1)
					{
						if(nearestnpc==PLAYER_npc)
						{
							//push main sprite up
							if(!PLAYER_check_hit_layer(UP)&&!PLAYER_check_hit_non_walkable_npcs(UP))PLAYER_npc->MAP_y--;

							if(npc->MAP_x+npc->size_x/2<=nearestnpc->MAP_x+nearestnpc->size_x/2)
							{//push main sprite right
								if(!PLAYER_check_hit_layer(RIGHT)&&!PLAYER_check_hit_non_walkable_npcs(RIGHT))PLAYER_npc->MAP_x++;
							}
							else
							{//push main sprite left
								if(!PLAYER_check_hit_layer(LEFT)&&!PLAYER_check_hit_non_walkable_npcs(LEFT))PLAYER_npc->MAP_x--;
							}
						}
						else
						{

							NPC_check_hit_move_pixel(&nearestnpc,UP);

							if(npc->MAP_x+npc->size_x/2<nearestnpc->MAP_x+nearestnpc->size_x/2)
							{
								NPC_check_hit_move_pixel(&nearestnpc,RIGHT);
							}
							else
							{
								NPC_check_hit_move_pixel(&nearestnpc,LEFT);
							}
						}

						direction=UP;
					}

					{
						if(NPC_check_hit_move_pixel(npcpp,UP)==0||NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,7)==1)
						{
							if(npc->walk_dir!=LEFT&&npc->walk_dir!=RIGHT)
							{
								if(r(2)==0)npc->walk_dir=LEFT;
								else npc->walk_dir=RIGHT;
							}
						}
						else
						{
							npc->walk_dir=4;
							direction=UP;
						}
					}
				}

			}
///===========================================
			if(xdistance>ydistance)
			{
				if(npc->MAP_x+npc->size_x/2<x)
				{
					if(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,7)==1)
					{
						if(nearestnpc==PLAYER_npc)
						{
							//push main sprite right
							if(!PLAYER_check_hit_layer(RIGHT)&&!PLAYER_check_hit_non_walkable_npcs(RIGHT))PLAYER_npc->MAP_x++;

							if(npc->MAP_y+(npc->size_y-npc->hitsize_y)/2>(nearestnpc->MAP_y+nearestnpc->size_y)-nearestnpc->hitsize_y/2)
							{//push main sprite up
								if(!PLAYER_check_hit_layer(UP)&&!PLAYER_check_hit_non_walkable_npcs(UP))PLAYER_npc->MAP_y--;
							}
							else
							{//push main sprite down
								if(!PLAYER_check_hit_layer(DOWN)&&!PLAYER_check_hit_non_walkable_npcs(DOWN))PLAYER_npc->MAP_y++;
							}
						}
						else
						{

							NPC_check_hit_move_pixel(&nearestnpc,RIGHT);

							if(npc->MAP_y+(npc->size_y-npc->hitsize_y)/2>=nearestnpc->MAP_y+nearestnpc->size_y-nearestnpc->hitsize_y/2)
							{
								NPC_check_hit_move_pixel(&nearestnpc,UP);
							}
							else
							{
								NPC_check_hit_move_pixel(&nearestnpc,DOWN);
							}
						}

						direction=RIGHT;
					}

					{
						if(NPC_check_hit_move_pixel(npcpp,RIGHT)==0||NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,7)==1)
						{
							if(npc->walk_dir!=UP&&npc->walk_dir!=DOWN)
							{
								if(r(2)==0)npc->walk_dir=UP;
								else npc->walk_dir=DOWN;
							}
						}
						else
						{
							npc->walk_dir=4;
							direction=RIGHT;
						}
					}

				}

				if(npc->MAP_x+npc->size_x/2>x)
				{
					if(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,7)==1)
					{
						if(nearestnpc==PLAYER_npc)
						{
							//push main sprite left
							if(!PLAYER_check_hit_layer(LEFT)&&!PLAYER_check_hit_non_walkable_npcs(LEFT))PLAYER_npc->MAP_x--;

							if(npc->MAP_y+(npc->size_y-npc->hitsize_y)/2>=nearestnpc->MAP_y+nearestnpc->size_y-nearestnpc->hitsize_y/2)
							{//push main sprite up
								if(!PLAYER_check_hit_layer(UP)&&!PLAYER_check_hit_non_walkable_npcs(UP))PLAYER_npc->MAP_y--;
							}
							else
							{//push main sprite down
								if(!PLAYER_check_hit_layer(DOWN)&&!PLAYER_check_hit_non_walkable_npcs(DOWN))PLAYER_npc->MAP_y++;
							}
						}
						else
						{

							NPC_check_hit_move_pixel(&nearestnpc,LEFT);

							if(npc->MAP_y+(npc->size_y-npc->hitsize_y)/2>nearestnpc->MAP_y+nearestnpc->size_y-nearestnpc->hitsize_y/2)
							{
								NPC_check_hit_move_pixel(&nearestnpc,UP);
							}
							else
							{
								NPC_check_hit_move_pixel(&nearestnpc,DOWN);
							}
						}

						direction=LEFT;
					}

					{
						if(NPC_check_hit_move_pixel(npcpp,LEFT)==0||NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,7)==1)
						{
							if(npc->walk_dir!=UP&&npc->walk_dir!=DOWN)
							{
								if(r(2)==0)npc->walk_dir=UP;
								else npc->walk_dir=DOWN;
							}
						}
						else
						{
							npc->walk_dir=4;
							direction=LEFT;
						}
					}

				}
			}

			if(npc->walk_dir==UP){if(NPC_check_hit_move_pixel(npcpp,UP)==0||NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,10+r(6))==1){npc->walk_dir=4;}else direction=UP;}
			else if(npc->walk_dir==DOWN){if(NPC_check_hit_move_pixel(npcpp,DOWN)==0||NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,10+r(6))==1){npc->walk_dir=4;}else direction=DOWN;}
			else if(npc->walk_dir==LEFT){if(NPC_check_hit_move_pixel(npcpp,LEFT)==0||NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,10+r(6))==1){npc->walk_dir=4;}else direction=LEFT;}
			else if(npc->walk_dir==RIGHT){if(NPC_check_hit_move_pixel(npcpp,RIGHT)==0||NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,10+r(6))==1){npc->walk_dir=4;}else direction=RIGHT;}

			int d = (xdistance-ydistance);
			if(d<0)d*=-1;
			if(npc->anim_dir!=direction&&GLOBAL_npc_all_animation_off==0&&npc->animation_off==0&&d>=8){npc->anim_dir=direction;NPC_animate_dir(npcpp,npc->anim_dir);}//animate change direction

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
//=========================================================================================================================
bool NPC_walk_to_xy_intelligenthit_avoidothers(NPC** npcpp,int speed,int x,int y)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_walk_to_xy_intelligenthit_avoidothers()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_walk_to_xy_intelligenthit_avoidothers()");return 0;}
	NPC* npc = *npcpp;


	npc->ignore_player=1;
	npc->walking_speed = speed;

	bool there_yet=0;
	int avoided=0;

	if(x==-1)x=npc->MAP_x+npc->size_x/2;
	if(y==-1)y=npc->MAP_y+(npc->size_y-npc->hitsize_y);

	if(npc->MAP_x+npc->size_x/2==x&&npc->MAP_y+(npc->size_y-npc->hitsize_y)==y)
	{
		there_yet=1;

		NPC_stand(npcpp);
	}
	else
	{

		if(npc->ms>npc->walking_speed)
		{

			int xdistance=(npc->MAP_x+npc->size_x/2)-x;
			int ydistance=((npc->MAP_y+npc->size_y)-npc->hitsize_y)-y;

			if(xdistance<0)xdistance*=-1;
			if(ydistance<0)ydistance*=-1;

			int direction=0;
			NPC* nearestnpc = NPC_find_nearest_npc(npcpp);

			if(ydistance>=xdistance) //walk the greater distance first, up/down vs left/right
			{
				if((npc->MAP_y+npc->size_y)-npc->hitsize_y<y)
				{
					if(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,10+r(6))==1)
					{
						{
							avoided=r(2);
							if(npc->MAP_x+npc->size_x/2<=nearestnpc->MAP_x+nearestnpc->size_x/2)
							{
								if(avoided==1)NPC_check_hit_move_pixel(npcpp,LEFT);
								npc->walk_dir=4;
							}
							else
							{
								if(avoided==1)NPC_check_hit_move_pixel(npcpp,RIGHT);
								npc->walk_dir=4;
							}
						}
						direction=DOWN;
					}

					if(avoided==0)
					{
						if(NPC_check_hit_move_pixel(npcpp,DOWN)==0)
						{
							if(npc->walk_dir!=LEFT&&npc->walk_dir!=RIGHT)
							{
								if(r(2)==0)npc->walk_dir=LEFT;
								else npc->walk_dir=RIGHT;
							}
						}
						else
						{
							npc->walk_dir=4;
							direction=DOWN;
						}
					}

				}
				avoided=0;
				if(npc->MAP_y+(npc->size_y-npc->hitsize_y)>y)
				{
					if(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,10+r(6))==1)
					{
						{
							avoided=r(2);
							if(npc->MAP_x+npc->size_x/2<nearestnpc->MAP_x+nearestnpc->size_x/2)
							{
								if(avoided==1)NPC_check_hit_move_pixel(npcpp,LEFT); //else walk left if slightly left
								npc->walk_dir=4;
							}
							else
							{
								if(avoided==1)NPC_check_hit_move_pixel(npcpp,RIGHT);			//else walk right
								npc->walk_dir=4;
							}
						}
						direction=UP;
					}

					if(avoided==0)
					{
						if(NPC_check_hit_move_pixel(npcpp,UP)==0)
						{
							if(npc->walk_dir!=LEFT&&npc->walk_dir!=RIGHT)
							{
								if(r(2)==0)npc->walk_dir=LEFT;
								else npc->walk_dir=RIGHT;
							}
						}
						else
						{
							npc->walk_dir=4;
							direction=UP;
						}
					}
				}
				avoided=0;

			}

			if(xdistance>ydistance)
			{
				if(npc->MAP_x+npc->size_x/2<x)
				{
					if(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,10+r(6))==1)
					{
						{
							avoided=r(2);
							if(npc->MAP_y+(npc->size_y-npc->hitsize_y)/2<=nearestnpc->MAP_y+nearestnpc->size_y-nearestnpc->hitsize_y/2)
							{
								if(avoided==1)NPC_check_hit_move_pixel(npcpp,UP); //else walk up if slightly above
								npc->walk_dir=4;
							}
							else
							{
								if(avoided==1)NPC_check_hit_move_pixel(npcpp,DOWN);			//else walk down
								npc->walk_dir=4;
							}
						}
						direction=RIGHT;
					}

					if(avoided==0)
					{
						if(NPC_check_hit_move_pixel(npcpp,RIGHT)==0)
						{
							if(npc->walk_dir!=UP&&npc->walk_dir!=DOWN)
							{
								if(r(2)==0)npc->walk_dir=UP;
								else npc->walk_dir=DOWN;
							}
						}
						else
						{
							npc->walk_dir=4;
							direction=RIGHT;
						}
					}

				}
				avoided=0;
				if(npc->MAP_x+npc->size_x/2>x)
				{
					if(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,10+r(6))==1)
					{
						{
							avoided=r(2);
							if(npc->MAP_y+(npc->size_y-npc->hitsize_y)/2<nearestnpc->MAP_y+nearestnpc->size_y-nearestnpc->hitsize_y/2)
							{
								if(avoided==1)NPC_check_hit_move_pixel(npcpp,UP); //else walk up if slightly above
								npc->walk_dir=4;
							}
							else
							{
								if(avoided==1)NPC_check_hit_move_pixel(npcpp,DOWN);			//else walk down
								npc->walk_dir=4;
							}
						}
						direction=LEFT;
					}

					if(avoided==0)
					{
						if(NPC_check_hit_move_pixel(npcpp,LEFT)==0)
						{
							if(npc->walk_dir!=UP&&npc->walk_dir!=DOWN)
							{
								if(r(2)==0)npc->walk_dir=UP;
								else npc->walk_dir=DOWN;
							}
						}
						else
						{
							npc->walk_dir=4;
							direction=LEFT;
						}
					}

				}
			}

			if(npc->walk_dir==UP){if(NPC_check_hit_move_pixel(npcpp,UP)==0||NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,10+r(6))==1){npc->walk_dir=4;}else direction=UP;}
			else if(npc->walk_dir==DOWN){if(NPC_check_hit_move_pixel(npcpp,DOWN)==0||NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,10+r(6))==1){npc->walk_dir=4;}else direction=DOWN;}
			else if(npc->walk_dir==LEFT){if(NPC_check_hit_move_pixel(npcpp,LEFT)==0||NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,10+r(6))==1){npc->walk_dir=4;}else direction=LEFT;}
			else if(npc->walk_dir==RIGHT){if(NPC_check_hit_move_pixel(npcpp,RIGHT)==0||NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,10+r(6))==1){npc->walk_dir=4;}else direction=RIGHT;}

			int d = (xdistance-ydistance);
			if(d<0)d*=-1;
			if(npc->anim_dir!=direction&&GLOBAL_npc_all_animation_off==0&&npc->animation_off==0&&d>=8){npc->anim_dir=direction;NPC_animate_dir(npcpp,npc->anim_dir);}//animate change direction

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

//=========================================================================================================================
bool NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(NPC** npcpp,int speed,int x,int y)
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_walk_to_xy_intelligenthit_stopforothers_pushmain()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_walk_to_xy_intelligenthit_stopforothers_pushmain()");return 0;}
	NPC* npc = *npcpp;

	if(PLAYER_npc==NULL){ERROR_set_error("NPC_walk_to_xy_intelligenthit_stopforothers_pushmain()");return 0;}


	npc->ignore_player=1;
	npc->walking_speed = speed;

	if(x==-1)x=npc->MAP_x+npc->size_x/2;
	if(y==-1)y=npc->MAP_y+(npc->size_y-npc->hitsize_y);

	bool there_yet=0;
	int noanim=0;

	if(npc->MAP_x+npc->size_x/2==x&&npc->MAP_y+(npc->size_y-npc->hitsize_y)==y)
	{
		there_yet=1;

		NPC_stand(npcpp);
	}
	else
	{
		if(npc->ms>npc->walking_speed)
		{
			int xdistance=(npc->MAP_x+npc->size_x/2)-x;
			int ydistance=((npc->MAP_y+npc->size_y)-npc->hitsize_y)-y;

			if(xdistance<0)xdistance*=-1;
			if(ydistance<0)ydistance*=-1;

			int direction=0;

			NPC* nearestnpc = NPC_find_nearest_npc(npcpp);

			if(ydistance>=xdistance) //walk the greater distance first, up/down vs left/right
			{
				if((npc->MAP_y+npc->size_y)-npc->hitsize_y<y)
				{
					if(NPC_in_range_of_npc_in_direction_by_amount(npcpp,&nearestnpc,DOWN,5+speed%16)==1&&(npc->MAP_x!=nearestnpc->MAP_x||npc->MAP_y!=nearestnpc->MAP_y))
					{
						if(nearestnpc==PLAYER_npc)
						{
							//push main sprite down
							if(!PLAYER_check_hit_layer(DOWN)&&!PLAYER_check_hit_non_walkable_npcs(DOWN))PLAYER_npc->MAP_y++;

							if(npc->MAP_x+npc->size_x/2<nearestnpc->MAP_x+nearestnpc->size_x/2)
							{//push main sprite right
								if(!PLAYER_check_hit_layer(RIGHT)&&!PLAYER_check_hit_non_walkable_npcs(RIGHT))PLAYER_npc->MAP_x++;
							}
							else
							{//push main sprite left
								if(!PLAYER_check_hit_layer(LEFT)&&!PLAYER_check_hit_non_walkable_npcs(LEFT))PLAYER_npc->MAP_x--;
							}
						}

						noanim=1;
						npc->walk_dir=4;
						direction=DOWN;

					}
					else
					if(NPC_check_hit_move_pixel(npcpp,DOWN)==0)
					{
						if(npc->walk_dir!=LEFT&&npc->walk_dir!=RIGHT)
						{
							if(r(2)==0)npc->walk_dir=LEFT;
							else npc->walk_dir=RIGHT;
						}
					}
					else
					{
						npc->walk_dir=4;
						direction=DOWN;
					}
				}
				if((npc->MAP_y+npc->size_y)-npc->hitsize_y>y)
				{
					if(NPC_in_range_of_npc_in_direction_by_amount(npcpp,&nearestnpc,UP,5+speed%16)==1&&(npc->MAP_x!=nearestnpc->MAP_x||npc->MAP_y!=nearestnpc->MAP_y))
					{
						if(nearestnpc==PLAYER_npc)
						{
							//push main sprite up
							if(!PLAYER_check_hit_layer(UP)&&!PLAYER_check_hit_non_walkable_npcs(UP))PLAYER_npc->MAP_y--;

							if(npc->MAP_x+npc->size_x/2<=nearestnpc->MAP_x+nearestnpc->size_x/2)
							{//push main sprite right
								if(!PLAYER_check_hit_layer(RIGHT)&&!PLAYER_check_hit_non_walkable_npcs(RIGHT))PLAYER_npc->MAP_x++;
							}
							else
							{//push main sprite left
								if(!PLAYER_check_hit_layer(LEFT)&&!PLAYER_check_hit_non_walkable_npcs(LEFT))PLAYER_npc->MAP_x--;
							}
						}
						noanim=1;
						npc->walk_dir=4;
						direction=UP;

					}
					else
					if(NPC_check_hit_move_pixel(npcpp,UP)==0)
					{
						if(npc->walk_dir!=LEFT&&npc->walk_dir!=RIGHT)
						{
							if(r(2)==0)npc->walk_dir=LEFT;
							else npc->walk_dir=RIGHT;
						}
					}
					else
					{
						npc->walk_dir=4;
						direction=UP;
					}
				}
			}

			if(xdistance>=ydistance)
			{
				if(npc->MAP_x+npc->size_x/2<x)
				{
					if(NPC_in_range_of_npc_in_direction_by_amount(npcpp,&nearestnpc,RIGHT,5+speed%16)==1&&(npc->MAP_x!=nearestnpc->MAP_x||npc->MAP_y!=nearestnpc->MAP_y))
					{
						if(nearestnpc==PLAYER_npc)
						{
							//push main sprite right
							if(!PLAYER_check_hit_layer(RIGHT)&&!PLAYER_check_hit_non_walkable_npcs(RIGHT))PLAYER_npc->MAP_x++;

							if(npc->MAP_y+(npc->size_y-npc->hitsize_y)/2>(nearestnpc->MAP_y+nearestnpc->size_y)-nearestnpc->hitsize_y/2)
							{//push main sprite up
								if(!PLAYER_check_hit_layer(UP)&&!PLAYER_check_hit_non_walkable_npcs(UP))PLAYER_npc->MAP_y--;
							}
							else
							{//push main sprite down
								if(!PLAYER_check_hit_layer(DOWN)&&!PLAYER_check_hit_non_walkable_npcs(DOWN))PLAYER_npc->MAP_y++;
							}
						}
						noanim=1;
						npc->walk_dir=4;
						direction=RIGHT;

					}
					else
					if(NPC_check_hit_move_pixel(npcpp,RIGHT)==0)
					{
						if(npc->walk_dir!=UP&&npc->walk_dir!=DOWN)
						{
							if(r(2)==0)npc->walk_dir=UP;
							else npc->walk_dir=DOWN;
						}
					}
					else
					{
						npc->walk_dir=4;
						direction=RIGHT;
					}

				}
				if(npc->MAP_x+npc->size_x/2>x)
				{
					if(NPC_in_range_of_npc_in_direction_by_amount(npcpp,&nearestnpc,LEFT,5+speed%16)==1&&(npc->MAP_x!=nearestnpc->MAP_x||npc->MAP_y!=nearestnpc->MAP_y))
					{
						if(nearestnpc==PLAYER_npc)
						{
							//push main sprite left
							if(!PLAYER_check_hit_layer(LEFT)&&!PLAYER_check_hit_non_walkable_npcs(LEFT))PLAYER_npc->MAP_x--;

							if(npc->MAP_y+(npc->size_y-npc->hitsize_y)/2>=nearestnpc->MAP_y+nearestnpc->size_y-nearestnpc->hitsize_y/2)
							{//push main sprite up
								if(!PLAYER_check_hit_layer(UP)&&!PLAYER_check_hit_non_walkable_npcs(UP))PLAYER_npc->MAP_y--;
							}
							else
							{//push main sprite down
								if(!PLAYER_check_hit_layer(DOWN)&&!PLAYER_check_hit_non_walkable_npcs(DOWN))PLAYER_npc->MAP_y++;
							}
						}
						noanim=1;
						npc->walk_dir=4;
						direction=LEFT;
					}
					else
					if(NPC_check_hit_move_pixel(npcpp,LEFT)==0)
					{
						if(npc->walk_dir!=UP&&npc->walk_dir!=DOWN)
						{
							if(r(2)==0)npc->walk_dir=UP;
							else npc->walk_dir=DOWN;
						}
					}
					else
					{
						npc->walk_dir=4;
						direction=LEFT;
					}
				}
			}

			if(npc->walk_dir==UP){if(NPC_check_hit_move_pixel(npcpp,UP)==0||NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,10+r(6))==1){npc->walk_dir=4;}else direction=UP;}
			else if(npc->walk_dir==DOWN){if(NPC_check_hit_move_pixel(npcpp,DOWN)==0||NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,10+r(6))==1){npc->walk_dir=4;}else direction=DOWN;}
			else if(npc->walk_dir==LEFT){if(NPC_check_hit_move_pixel(npcpp,LEFT)==0||NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,10+r(6))==1){npc->walk_dir=4;}else direction=LEFT;}
			else if(npc->walk_dir==RIGHT){if(NPC_check_hit_move_pixel(npcpp,RIGHT)==0||NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,10+r(6))==1){npc->walk_dir=4;}else direction=RIGHT;}

			int d = (xdistance-ydistance);if(d<0)d*=-1;
			if(npc->anim_dir!=direction&&GLOBAL_npc_all_animation_off==0&&npc->animation_off==0&&d>=8){npc->anim_dir=direction;NPC_animate_dir(npcpp,npc->anim_dir);}
			//animate change direction but not for when walking diagonally, otherwise it keeps twitching updown/leftright for every other pixel

			npc->ms=0;

			if(NPC_should_animate(npcpp)&&there_yet==0&&noanim==0)//animate walking
			{
				if(GLOBAL_npc_all_animation_off==0&&npc->animation_off==0)NPC_animate_dir(npcpp,npc->anim_dir);
			}
		}
	}
	return there_yet;
}



//=========================================================================================================================
bool NPC_walk_as_fast_as_possible_straight_to_point(NPC** npcpp,int x,int y)
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_walk_as_fast_as_possible_straight_to_point()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_walk_as_fast_as_possible_straight_to_point()");return 0;}
	NPC* npc = *npcpp;

	npc->ignore_player=1;
	bool there_yet= NPC_walk_to_xy_basichit(npcpp,SPEED_FASTEST,x,y);

//	if(npc->walk_timer>SPEED_FASTEST)
//	{
//
//			if(npc->MAP_y+npc->size_y-6<y){npc->anim_direction=DOWN;NPC_check_hit_move_pixel(npc,DOWN);}
//			if(npc->MAP_y+npc->size_y-6>y){npc->anim_direction=UP;NPC_check_hit_move_pixel(npc,UP);}
//			if(npc->MAP_x+npc->size_x/2<x){NPC_check_hit_move_pixel(npc,RIGHT);if(!npc->walking_into_wall)npc->anim_direction=RIGHT;}
//			if(npc->MAP_x+npc->size_x/2>x){NPC_check_hit_move_pixel(npc,LEFT);if(!npc->walking_into_wall)npc->anim_direction=LEFT;}
//
//		if(npc->pixels_to_walk>0&&npc->walking_into_sprite==0)npc->pixels_to_walk--;
//		npc->walk_timer=0;
//	}
//
//	if(npc->MAP_x+npc->size_x/2==x&&npc->MAP_y+npc->size_y-6==y){there_yet=1;npc->anim_frame_count=7;if(GLOBAL_npc_all_animation_off==0&&npc->animation_off==0)NPC_animate_increment_direction_frame_now(npc,npc->anim_direction);}
//
//	if(NPC_should_animate(npc)&&there_yet==0&&npc->walking_into_sprite==0&&npc->walking_into_wall==0)
//	{
//		if(GLOBAL_npc_all_animation_off==0&&npc->animation_off==0)NPC_animate_increment_direction_frame_now(npc,npc->anim_direction);
//	}
//	else
//		if(npc->walking_into_sprite==1||npc->walking_into_wall==1)
//		{
//			npc->anim_frame_count=7;
//			if(GLOBAL_npc_all_animation_off==0&&npc->animation_off==0)NPC_animate_increment_direction_frame_now(npc,npc->anim_direction);
//		}
//
	return there_yet;
}



//=========================================================================================================================
void NPC_walk_straight_from_point_to_point(NPC** npcpp,int speed,int x1,int y1,int x2,int y2)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_walk_straight_from_point_to_point()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_walk_straight_from_point_to_point()");return;}
	NPC* npc = *npcpp;

	if(npc->walk_dir>1)npc->walk_dir=0;//this will simply be used as a movement switch in this function // no its not appropriate but fuck it
	bool there_yet=0;
	if(npc->walk_dir==0)
	{
		there_yet=NPC_walk_to_xy_basichit(npcpp,speed,x1,y1);
		if(there_yet==1)npc->walk_dir++;
	}
	if(npc->walk_dir==1)
	{
		there_yet=NPC_walk_to_xy_basichit(npcpp,speed,x2,y2);
		if(there_yet==1)npc->walk_dir=0;
	}
}



//=========================================================================================================================
void NPC_walk_straight_from_point_to_point_and_stop(NPC** npcpp,int x1,int y1,int x2,int y2)
{//=========================================================================================================================


	if(npcpp==NULL){ERROR_set_error("NPC_walk_straight_from_point_to_point_and_stop()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_walk_straight_from_point_to_point_and_stop()");return;}
	NPC* npc = *npcpp;

	if(npc->walk_dir>1)npc->walk_dir=0;//this will simply be used as a movement switch in this function // no its not appropriate but fuck it

	if(npc->pixels_to_walk==0)
	{
		npc->pixels_to_walk=(r(50))+10;
		npc->walking_speed =(r(SPEED_FASTEST-SPEED_SLOWEST))+SPEED_SLOWEST;
	}

	if(npc->pixels_to_walk==1)
	{
		npc->walking_speed=(r(SPEED_FASTEST-SPEED_SLOWEST))+SPEED_SLOWEST;
		NPC_stand(npcpp);
	}

	bool there_yet=0;
	if(npc->walk_dir==0)
	{
		there_yet=NPC_walk_to_xy_basichit(npcpp,npc->walking_speed,x1,y1);
		if(there_yet==1)npc->walk_dir++;
	}
	if(npc->walk_dir==1)
	{
		there_yet=NPC_walk_to_xy_basichit(npcpp,npc->walking_speed,x2,y2);
		if(there_yet==1)npc->walk_dir=0;
	}
}



//=========================================================================================================================
void NPC_walk_away_from_point(NPC** npcpp,int speed,int x,int y)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_walk_away_from_point()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_walk_away_from_point()");return;}
	NPC* npc = *npcpp;

	npc->ignore_player=1;
	npc->walking_speed = speed;
	if(npc->ms>npc->walking_speed)
	{
		if(npc->MAP_y+(npc->size_y-npc->hitsize_y)>y){npc->anim_dir=DOWN;NPC_check_hit_move_pixel(npcpp,DOWN);}
		if(npc->MAP_y+(npc->size_y-npc->hitsize_y)<y){npc->anim_dir=UP;NPC_check_hit_move_pixel(npcpp,UP);}
		if(npc->MAP_x+npc->size_x/2>x){NPC_check_hit_move_pixel(npcpp,RIGHT);if(!npc->is_walking_into_wall)npc->anim_dir=RIGHT;}
		if(npc->MAP_x+npc->size_x/2<x){NPC_check_hit_move_pixel(npcpp,LEFT);if(!npc->is_walking_into_wall)npc->anim_dir=LEFT;}

		if(npc->pixels_to_walk>0&&npc->is_walking_into_player==0)npc->pixels_to_walk--;

		npc->ms=0;
	}

	if(NPC_should_animate(npcpp)&&npc->is_walking_into_player==0&&npc->is_walking_into_wall==0)
	{
		if(GLOBAL_npc_all_animation_off==0&&npc->animation_off==0)NPC_animate_dir(npcpp,npc->anim_dir);
	}
	else
		if(npc->is_walking_into_player==1||npc->is_walking_into_wall==1)
		{
			NPC_stand(npcpp);
		}
}



//=========================================================================================================================
bool NPC_walk_distance(NPC** npcpp,int speed,int NPC_direction)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_walk_distance()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_walk_distance()");return 0;}
	NPC* npc = *npcpp;

	bool there_yet=0;

	if(npc->pixels_to_walk>0)
	{
		npc->walk_dir=NPC_direction;
		npc->walking_speed = speed;
		NPC_walk_direction(npcpp,npc->walk_dir);
	}
	else there_yet=1;

	return there_yet;
}



//=========================================================================================================================
bool NPC_avoid_npc(NPC** in_npcpp,NPC** avoid_npcpp,int avoid_amt)//returns 1 if not in npc area,use it to do something else outside,standing,staring,walking randomly etc
{//=========================================================================================================================


	if(in_npcpp==NULL){ERROR_set_error("NPC_avoid_npc()");return 0;}
	if(*in_npcpp==NULL){ERROR_set_error("NPC_avoid_npc()");return 0;}
	NPC* in_npc = *in_npcpp;


	if(avoid_npcpp==NULL){ERROR_set_error("NPC_avoid_npc()");return 0;}
	if(*avoid_npcpp==NULL){ERROR_set_error("NPC_avoid_npc()");return 0;}
	NPC* avoid_npc = *avoid_npcpp;


	bool outside_area=0;

	if(in_npc->MAP_x+(in_npc->size_x/2)>avoid_npc->MAP_x+(in_npc->size_x/2)-avoid_amt &&
		in_npc->MAP_x+(in_npc->size_x/2)<avoid_npc->MAP_x+(in_npc->size_x/2)+avoid_amt &&
		in_npc->MAP_y+in_npc->size_y-(in_npc->hitsize_y/2)>avoid_npc->MAP_y+in_npc->size_y-(in_npc->hitsize_y/2)-avoid_amt &&
		in_npc->MAP_y+in_npc->size_y-(in_npc->hitsize_y/2)<avoid_npc->MAP_y+in_npc->size_y-(in_npc->hitsize_y/2)+avoid_amt
		)
	{
		outside_area=0;
		int temp_speed = in_npc->walking_speed;
		in_npc->walking_speed=1;
		in_npc->ignore_player=1;

		if(in_npc->MAP_x<=avoid_npc->MAP_x){in_npc->walk_dir = LEFT;} //move left
		if(in_npc->MAP_x>=avoid_npc->MAP_x){in_npc->walk_dir = RIGHT;}//move right
		if(in_npc->MAP_y<=avoid_npc->MAP_y){in_npc->walk_dir = UP;}//move up
		if(in_npc->MAP_y>=avoid_npc->MAP_y){in_npc->walk_dir = DOWN;}//move down

		if(in_npc->ms>in_npc->walking_speed)
		{
		if(in_npc->MAP_x<=avoid_npc->MAP_x){NPC_check_hit_move_pixel(in_npcpp,LEFT);} //move left
		if(in_npc->MAP_x>=avoid_npc->MAP_x){NPC_check_hit_move_pixel(in_npcpp,RIGHT);}//move right
		if(in_npc->MAP_y<=avoid_npc->MAP_y){NPC_check_hit_move_pixel(in_npcpp,UP);}//move up
		if(in_npc->MAP_y>=avoid_npc->MAP_y){NPC_check_hit_move_pixel(in_npcpp,DOWN);}//move down
			in_npc->ms=0;
		}

		if(NPC_should_animate(in_npcpp))
		{
		if(GLOBAL_npc_all_animation_off==0&&in_npc->animation_off==0)NPC_animate(in_npcpp);
		}
		in_npc->anim_dir = in_npc->walk_dir;
		in_npc->ignore_player=0;
		in_npc->walking_speed = temp_speed;
	}
	else outside_area=1;

	return outside_area;
}



//=========================================================================================================================
bool NPC_avoid_nearest_npc(NPC** npcpp,int avoid_amt)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_avoid_nearest_npc()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_avoid_nearest_npc()");return 0;}
	//NPC* npc = *npcpp;

	NPC* nearestnpc = NPC_find_nearest_npc(npcpp);

	return NPC_avoid_npc(npcpp,&nearestnpc,avoid_amt);

}

//=========================================================================================================================
void NPC_chase_nearest_npc(NPC** npcpp)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_chase_nearest_npc()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_chase_nearest_npc()");return;}
	//NPC* npc = *npcpp;

	NPC* nearestnpc = NPC_find_nearest_npc(npcpp);

	NPC_chase_npc(npcpp,&nearestnpc);
}



//=========================================================================================================================
void NPC_pushable_crowd_behavior(NPC** npcpp)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_pushable_crowd_behavior()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_pushable_crowd_behavior()");return;}
	//NPC* npc = *npcpp;

	NPC* nearestnpc = NPC_find_nearest_npc(npcpp);

	if(NPC_avoid_npc(npcpp,&nearestnpc,4))//based on npc avoid nearest npc,send in all the npcs you want to be in the crowd
	{
		// avoiding.. hehe i could just leave this out
	}
}




//=========================================================================================================================
void NPC_dont_look_at_npc(NPC** staring_npcpp,NPC** stared_at_npcpp)//first id is npc to be avoiding LOOKING,second id is one to NOT BE LOOKED AT
{//=========================================================================================================================

	if(staring_npcpp==NULL){ERROR_set_error("NPC_dont_look_at_npc()");return;}
	if(*staring_npcpp==NULL){ERROR_set_error("NPC_dont_look_at_npc()");return;}
	NPC* staring_npc = *staring_npcpp;

	if(stared_at_npcpp==NULL){ERROR_set_error("NPC_dont_look_at_npc()");return;}
	if(*stared_at_npcpp==NULL){ERROR_set_error("NPC_dont_look_at_npc()");return;}
	NPC* stared_at_npc = *stared_at_npcpp;



	if(staring_npc!=PLAYER_npc)
	{
		int amt1 = (staring_npc->MAP_x+staring_npc->size_x/2)-(stared_at_npc->MAP_x+stared_at_npc->size_x/2);
		int amt2 = (staring_npc->MAP_y+(staring_npc->size_y-(staring_npc->hitsize_y)))-(stared_at_npc->MAP_y+(stared_at_npc->size_y-(stared_at_npc->hitsize_y)));
		if (amt1<0) amt1 = amt1 * -1;
		if (amt2<0) amt2 = amt2 * -1;

		if(amt2>=amt1)
		{
			if(staring_npc->MAP_y+(staring_npc->size_y-(staring_npc->hitsize_y))<stared_at_npc->MAP_y+(stared_at_npc->size_y-(stared_at_npc->hitsize_y)))staring_npc->anim_dir = UP;
			if(staring_npc->MAP_y+(staring_npc->size_y-(staring_npc->hitsize_y))>stared_at_npc->MAP_y+(stared_at_npc->size_y-(stared_at_npc->hitsize_y)))staring_npc->anim_dir = DOWN;
		}
		else
		{
			if(staring_npc->MAP_x+staring_npc->size_x/2>stared_at_npc->MAP_x+stared_at_npc->size_x/2)staring_npc->anim_dir = RIGHT;
			if(staring_npc->MAP_x+staring_npc->size_x/2<stared_at_npc->MAP_x+stared_at_npc->size_x/2)staring_npc->anim_dir = LEFT;
		}
	}
	else
	{
		if(staring_npc->MAP_x+staring_npc->size_x/2<=stared_at_npc->MAP_x+stared_at_npc->size_x/2){staring_npc->anim_dir = LEFT;} // left
		if(staring_npc->MAP_x+staring_npc->size_x/2>=stared_at_npc->MAP_x+stared_at_npc->size_x/2){staring_npc->anim_dir = RIGHT;}// right
		if(staring_npc->MAP_y+staring_npc->size_y-(staring_npc->hitsize_y)<=stared_at_npc->MAP_y+stared_at_npc->size_y-(stared_at_npc->hitsize_y)){staring_npc->anim_dir = UP;}// up
		if(staring_npc->MAP_y+staring_npc->size_y-(staring_npc->hitsize_y)>=stared_at_npc->MAP_y+stared_at_npc->size_y-(stared_at_npc->hitsize_y)){staring_npc->anim_dir = DOWN;}// down
		if(staring_npc->MAP_x+staring_npc->size_x/2<=stared_at_npc->MAP_x+stared_at_npc->size_x/2&&staring_npc->MAP_y+staring_npc->size_y-(staring_npc->hitsize_y)<=stared_at_npc->MAP_y+stared_at_npc->size_y-(stared_at_npc->hitsize_y)){staring_npc->anim_dir = UPLEFT;}
		if(staring_npc->MAP_x+staring_npc->size_x/2>=stared_at_npc->MAP_x+stared_at_npc->size_x/2&&staring_npc->MAP_y+staring_npc->size_y-(staring_npc->hitsize_y)<=stared_at_npc->MAP_y+stared_at_npc->size_y-(stared_at_npc->hitsize_y)){staring_npc->anim_dir = UPRIGHT;}
		if(staring_npc->MAP_y+staring_npc->size_y-(staring_npc->hitsize_y)>=stared_at_npc->MAP_y+stared_at_npc->size_y-(stared_at_npc->hitsize_y)&&staring_npc->MAP_x+staring_npc->size_x/2<=stared_at_npc->MAP_x+stared_at_npc->size_x/2){staring_npc->anim_dir = DOWNLEFT;}
		if(staring_npc->MAP_y+staring_npc->size_y-(staring_npc->hitsize_y)>=stared_at_npc->MAP_y+stared_at_npc->size_y-(stared_at_npc->hitsize_y)&&staring_npc->MAP_x+staring_npc->size_x/2>=stared_at_npc->MAP_x+stared_at_npc->size_x/2){staring_npc->anim_dir = DOWNRIGHT;}
	}
	NPC_stand(staring_npcpp);
}



//=========================================================================================================================
void NPC_stare_at_npc(NPC** staring_npcpp,NPC** stared_at_npcpp)
{//=========================================================================================================================


	if(staring_npcpp==NULL){ERROR_set_error("NPC_stare_at_npc()");return;}
	if(*staring_npcpp==NULL){ERROR_set_error("NPC_stare_at_npc()");return;}
	NPC* staring_npc = *staring_npcpp;

	if(stared_at_npcpp==NULL){ERROR_set_error("NPC_stare_at_npc()");return;}
	if(*stared_at_npcpp==NULL){ERROR_set_error("NPC_stare_at_npc()");return;}
	NPC* stared_at_npc = *stared_at_npcpp;

	int direction=0;
	if(staring_npc!=PLAYER_npc)
	{
		int amt1 = (staring_npc->MAP_x+staring_npc->size_x/2)-(stared_at_npc->MAP_x+stared_at_npc->size_x/2);
		int amt2 = (staring_npc->MAP_y+(staring_npc->size_y-(staring_npc->hitsize_y)))-(stared_at_npc->MAP_y+(stared_at_npc->size_y-(stared_at_npc->hitsize_y)));
		if (amt1<0) amt1 = amt1 * -1;
		if (amt2<0) amt2 = amt2 * -1;

		if(amt2>=amt1)
		{
			if(staring_npc->MAP_y+staring_npc->size_y-(staring_npc->hitsize_y)<stared_at_npc->MAP_y+stared_at_npc->size_y-(stared_at_npc->hitsize_y))direction = DOWN;
			if(staring_npc->MAP_y+staring_npc->size_y-(staring_npc->hitsize_y)>stared_at_npc->MAP_y+stared_at_npc->size_y-(stared_at_npc->hitsize_y))direction = UP;
		}
		else
		{
			if(staring_npc->MAP_x+staring_npc->size_x/2>stared_at_npc->MAP_x+stared_at_npc->size_x/2)direction = LEFT;
			if(staring_npc->MAP_x+staring_npc->size_x/2<stared_at_npc->MAP_x+stared_at_npc->size_x/2)direction = RIGHT;
		}
	}
	else
	{
		if(staring_npc->MAP_x+staring_npc->size_x/2<=stared_at_npc->MAP_x+stared_at_npc->size_x/2){direction = RIGHT;} //move left
		if(staring_npc->MAP_x+staring_npc->size_x/2>=stared_at_npc->MAP_x+stared_at_npc->size_x/2){direction = LEFT;}//move right
		if(staring_npc->MAP_y+staring_npc->size_y-(staring_npc->hitsize_y)<=stared_at_npc->MAP_y+stared_at_npc->size_y-(stared_at_npc->hitsize_y)){direction = DOWN;}//move up
		if(staring_npc->MAP_y+staring_npc->size_y-(staring_npc->hitsize_y)>=stared_at_npc->MAP_y+stared_at_npc->size_y-(stared_at_npc->hitsize_y)){direction = UP;}//move down
		if(staring_npc->MAP_x+staring_npc->size_x/2<=stared_at_npc->MAP_x+stared_at_npc->size_x/2&&staring_npc->MAP_y+staring_npc->size_y-(staring_npc->hitsize_y)<=stared_at_npc->MAP_y+stared_at_npc->size_y-(stared_at_npc->hitsize_y)){direction = DOWNRIGHT;}
		if(staring_npc->MAP_x+staring_npc->size_x/2>=stared_at_npc->MAP_x+stared_at_npc->size_x/2&&staring_npc->MAP_y+staring_npc->size_y-(staring_npc->hitsize_y)<=stared_at_npc->MAP_y+stared_at_npc->size_y-(stared_at_npc->hitsize_y)){direction = DOWNLEFT;}
		if(staring_npc->MAP_y+staring_npc->size_y-(staring_npc->hitsize_y)>=stared_at_npc->MAP_y+stared_at_npc->size_y-(stared_at_npc->hitsize_y)&&staring_npc->MAP_x+staring_npc->size_x/2<=stared_at_npc->MAP_x+stared_at_npc->size_x/2){direction = UPRIGHT;}
		if(staring_npc->MAP_y+staring_npc->size_y-(staring_npc->hitsize_y)>=stared_at_npc->MAP_y+stared_at_npc->size_y-(stared_at_npc->hitsize_y)&&staring_npc->MAP_x+staring_npc->size_x/2>=stared_at_npc->MAP_x+stared_at_npc->size_x/2){direction = UPLEFT;}
	}
	//staring_npc->anim_frame_count=7;
	if(GLOBAL_npc_all_animation_off==0&&staring_npc->animation_off==0)NPC_animate_stand_dir(staring_npcpp,direction);
}
//=========================================================================================================================
void NPC_stare_at_npc_not_opposite_walking_direction(NPC** staring_npcpp,NPC** stared_at_npcpp)
{//=========================================================================================================================

	if(staring_npcpp==NULL){ERROR_set_error("NPC_stare_at_npc_not_opposite_walking_direction()");return;}
	if(*staring_npcpp==NULL){ERROR_set_error("NPC_stare_at_npc_not_opposite_walking_direction()");return;}
	NPC* staring_npc = *staring_npcpp;

	if(stared_at_npcpp==NULL){ERROR_set_error("NPC_stare_at_npc_not_opposite_walking_direction()");return;}
	if(*stared_at_npcpp==NULL){ERROR_set_error("NPC_stare_at_npc_not_opposite_walking_direction()");return;}
	NPC* stared_at_npc = *stared_at_npcpp;



		int amt1 = (staring_npc->MAP_x+staring_npc->size_x/2)-(stared_at_npc->MAP_x+stared_at_npc->size_x/2);
		int amt2 = (staring_npc->MAP_y+(staring_npc->size_y-(staring_npc->hitsize_y)))-(stared_at_npc->MAP_y+(stared_at_npc->size_y-(stared_at_npc->hitsize_y)));
		if (amt1<0) amt1 = amt1 * -1;
		if (amt2<0) amt2 = amt2 * -1;

		if(amt2>=amt1)
		{
			if(staring_npc->MAP_y+staring_npc->size_y-(staring_npc->hitsize_y)<stared_at_npc->MAP_y+stared_at_npc->size_y-(stared_at_npc->hitsize_y))if(staring_npc->walk_dir!=UP)staring_npc->anim_dir = DOWN;
			if(staring_npc->MAP_y+staring_npc->size_y-(staring_npc->hitsize_y)>stared_at_npc->MAP_y+stared_at_npc->size_y-(stared_at_npc->hitsize_y))if(staring_npc->walk_dir!=DOWN)staring_npc->anim_dir = UP;
		}
		else
		{
			if(staring_npc->MAP_x+staring_npc->size_x/2>stared_at_npc->MAP_x+stared_at_npc->size_x/2)if(staring_npc->walk_dir!=RIGHT)staring_npc->anim_dir = LEFT;
			if(staring_npc->MAP_x+staring_npc->size_x/2<stared_at_npc->MAP_x+stared_at_npc->size_x/2)if(staring_npc->walk_dir!=LEFT)staring_npc->anim_dir = RIGHT;
		}

		NPC_stand(staring_npcpp);
}




	//Declare constants
	const int tileSize = 8;
	int onClosedList = 10;
	const int notfinished = 0, notStarted = 0;// path-related constants
	const int found = 1, nonexistent = 2;
	const int walkable = 0, unwalkable = 1;// walkability array constants

	//Create needed arrays
	int* openList=NULL;//[62*43+2]; //1 dimensional array holding ID# of open list items
	int** whichList=NULL;//[62+1][43+1];  //2 dimensional array used to record
// 		whether a cell is on the open list or on the closed list.
	int* openX=NULL;//[62*43+2]; //1d array stores the x location of an item on the open list
	int* openY=NULL;//[62*43+2]; //1d array stores the y location of an item on the open list
	int** parentX=NULL;//[62+1][43+1]; //2d array to store parent of each cell (x)
	int** parentY=NULL;//[62+1][43+1]; //2d array to store parent of each cell (y)
	int* Fcost=NULL;//[62*43+2];	//1d array to store F cost of a cell on the open list
	int** Gcost=NULL;//[62+1][43+1]; 	//2d array to store G cost for each cell.
	int* Hcost=NULL;//[62*43+2];	//1d array to store H cost of a cell on the open list
	int pathLength=0;     //stores length of the found path for critter
	int pathLocation=0;   //stores current position along the chosen path for critter
	int* pathBank=NULL;

	//Path reading variables
	int pathStatus=0;
	int xPath=0;
	int yPath=0;



//=============================================================================
// Function Prototypes: where needed
//=============================================================================
void ReadPath(int currentX,int currentY);
int ReadPathX(int pathLocation);
int ReadPathY(int pathLocation);

//=============================================================================
// Name: InitializePathfinder
// Desc: Allocates memory for the pathfinder.
//=============================================================================
void InitializePathfinder (void)
{
	//int x = 0;
	//for (x = 0; x < 1; x++)
		pathBank  = (int*) malloc(4);


		openList	= (int*)malloc(((HARDWARE_map_width_tiles*HARDWARE_map_height_tiles)+2) * sizeof(int));
		openX		= (int*)malloc(((HARDWARE_map_width_tiles*HARDWARE_map_height_tiles)+2) * sizeof(int));
		openY		= (int*)malloc(((HARDWARE_map_width_tiles*HARDWARE_map_height_tiles)+2) * sizeof(int));
		Fcost		= (int*)malloc(((HARDWARE_map_width_tiles*HARDWARE_map_height_tiles)+2) * sizeof(int));
		Hcost		= (int*)malloc(((HARDWARE_map_width_tiles*HARDWARE_map_height_tiles)+2) * sizeof(int));



		//variable length multidimensional array malloc
		parentX		= (int**) malloc((HARDWARE_map_width_tiles+1) * sizeof(int *));
		parentY		= (int**) malloc((HARDWARE_map_width_tiles+1) * sizeof(int *));
		Gcost			= (int**) malloc((HARDWARE_map_width_tiles+1) * sizeof(int *));
		whichList		= (int**) malloc((HARDWARE_map_width_tiles+1) * sizeof(int *));

		int i=0;
		for(i = 0; i < HARDWARE_map_width_tiles+1; i++)
		{
			parentX[i]		=  (int*)malloc((HARDWARE_map_height_tiles+1) * sizeof(int));
			parentY[i]		=  (int*)malloc((HARDWARE_map_height_tiles+1) * sizeof(int));
			Gcost[i]			= (int*)malloc((HARDWARE_map_height_tiles+1) * sizeof(int));
			whichList[i]		= (int*)malloc((HARDWARE_map_height_tiles+1) * sizeof(int));
		}

}


//=============================================================================
// Name: EndPathfinder
// Desc: Frees memory used by the pathfinder.
//=============================================================================
void UnInitializePathfinder (void)
{
	//int x = 0;
	//for (x = 0; x < 1; x++)
	if(pathBank!=NULL)
	{
		free ((void *)pathBank);

		//normal free
		free ((void *)openList);
		free ((void *)openX);
		free ((void *)openY);
		free ((void *)Fcost);
		free ((void *)Hcost);

		//variable length multidimensional array free
		int i=0;
		for(i = 0; i < HARDWARE_map_width_tiles+1; i++)
		{
			free((void *)parentX[i]);
			free((void *)parentY[i]);
			free((void *)Gcost[i]);
			free((void *)whichList[i]);
		}
		free((void *)parentX);
		free((void *)parentY);
		free((void *)Gcost);
		free((void *)whichList);

		pathBank=NULL;

		pathStatus=0;
		pathLength=0;
        pathLocation=0;
		xPath=0;
		yPath=0;

    }
}




int abs(int v)
{
	if(v<0)v=v*-1;

	return v;

}


//=============================================================================
// Name: FindPath
// Desc: Finds a path using A*
//=============================================================================
int FindPath (NPC *npc, int startingX, int startingY,int maptargetX, int maptargetY)
{
	int onOpenList=0, parentXval=0, parentYval=0,
	a=0, b=0, m=0, u=0, v=0, temp=0, corner=0, numberOfOpenListItems=0,
	addedGCost=0, tempGcost = 0, path = 0,
	tempx, pathX, pathY, cellPosition,
	newOpenListItemID=0;

//1. Convert location data (in pixels) to coordinates in the walkability array.
	int startX = startingX/tileSize;
	int startY = startingY/tileSize;
	int targetX = maptargetX/tileSize;
	int targetY = maptargetY/tileSize;

//2.Quick Path Checks: Under the some circumstances no path needs to
//	be generated ...

//	If starting location and target are in the same location...
	if ((startX) == targetX && (startY) == targetY && pathLocation > 0)
		return found;
	if ((startX) == targetX && (startY) == targetY && pathLocation == 0)
		return nonexistent;

//	If target square is unwalkable, return that it's a nonexistent path.
	if (
		(HARDWARE_map_hit_layer[((targetY)*HARDWARE_map_width_tiles) + (targetX)] == unwalkable)//||//middle
		//(HARDWARE_map_hit_layer[(((maptargetY-(npc->hitsize_y/2)))*HARDWARE_map_width) + ((maptargetX-(npc->size_x/2)))] == unwalkable)||//topleft
		//(HARDWARE_map_hit_layer[(((maptargetY-(npc->hitsize_y/2)))*HARDWARE_map_width) + ((maptargetX+(npc->size_x/2)))] == unwalkable)||//topright
		//(HARDWARE_map_hit_layer[(((maptargetY+(npc->hitsize_y/2)))*HARDWARE_map_width) + ((maptargetX-(npc->size_x/2)))] == unwalkable)||//bottomleft
		//(HARDWARE_map_hit_layer[(((maptargetY+(npc->hitsize_y/2)))*HARDWARE_map_width) + ((maptargetX+(npc->size_x/2)))] == unwalkable)//bottomright

		)
		goto noPath;

//3.Reset some variables that need to be cleared
	if (onClosedList > 1000000) //reset whichList occasionally
	{
		int x = 0;
		for (x = 0; x < HARDWARE_map_width_tiles;x++) {
			int y=0;
			for (y = 0; y < HARDWARE_map_height_tiles;y++)
				whichList [x][y] = 0;
		}
		onClosedList = 10;
	}
	onClosedList = onClosedList+2; //changing the values of onOpenList and onClosed list is faster than redimming whichList() array
	onOpenList = onClosedList-1;
	pathLength  = notStarted;//i.e, = 0
	pathLocation  = notStarted;//i.e, = 0
	Gcost[(startX)][(startY)] = 0; //reset starting square's G value to 0

//4.Add the starting location to the open list of squares to be checked.
	numberOfOpenListItems = 1;
	openList[1] = 1;//assign it as the top (and currently only) item in the open list, which is maintained as a binary heap (explained below)
	openX[1] = (startX) ; openY[1] = (startY);

//5.Do the following until a path is found or deemed nonexistent.
	do
	{

		//6.If the open list is not empty, take the first cell off of the list.
		//	This is the lowest F cost cell on the open list.
		if (numberOfOpenListItems != 0)
		{

			//7. Pop the first item off the open list.
			parentXval = openX[openList[1]];
			parentYval = openY[openList[1]]; //record cell coordinates of the item
			whichList[parentXval][parentYval] = onClosedList;//add the item to the closed list

			//	Open List = Binary Heap: Delete this item from the open list, which
			//  is maintained as a binary heap. For more information on binary heaps, see:
			//	http://www.policyalmanac.org/games/binaryHeaps.htm
			numberOfOpenListItems = numberOfOpenListItems - 1;//reduce number of open list items by 1

			//	Delete the top item in binary heap and reorder the heap, with the lowest F cost item rising to the top.
			openList[1] = openList[numberOfOpenListItems+1];//move the last item in the heap up to slot #1
			v = 1;

			//	Repeat the following until the new item in slot #1 sinks to its proper spot in the heap.
			do
			{
				u = v;
				if (2*u+1 <= numberOfOpenListItems) //if both children exist
				{
					//Check if the F cost of the parent is greater than each child.
					//Select the lowest of the two children.
					if (Fcost[openList[u]] >= Fcost[openList[2*u]])
						v = 2*u;
					if (Fcost[openList[v]] >= Fcost[openList[2*u+1]])
						v = 2*u+1;
				}
				else
				{
					if (2*u <= numberOfOpenListItems) //if only child #1 exists
					{
					//Check if the F cost of the parent is greater than child #1
						if (Fcost[openList[u]] >= Fcost[openList[2*u]])
							v = 2*u;
					}
				}

				if (u != v) //if parent's F is > one of its children, swap them
				{
					temp = openList[u];
					openList[u] = openList[v];
					openList[v] = temp;
				}
				else
					break; //otherwise, exit loop

			}
			while (1);//reorder the binary heap


		//7.Check the adjacent squares. (Its "children" -- these path children
		//	are similar, conceptually, to the binary heap children mentioned
		//	above, but don't confuse them. They are different. Path children
		//	are portrayed in Demo 1 with grey pointers pointing toward
		//	their parents.) Add these adjacent child squares to the open list
		//	for later consideration if appropriate (see various if statements
		//	below).
			for (b = parentYval-1; b <= parentYval+1; b+=1)
			{
				for (a = parentXval-1; a <= parentXval+1; a+=1)
				{

				//	If not off the map (do this first to avoid array out-of-bounds errors)
					if (a >=1 && b >=1 && a < HARDWARE_map_width_tiles-1 && b < HARDWARE_map_height_tiles-1)
					{

					//	If not already on the closed list (items on the closed list have
					//	already been considered and can now be ignored).
						if (whichList[a][b] != onClosedList)
						{

							//int amt=1;

						//	If not a wall/obstacle square.
							if(
								(

									HARDWARE_map_hit_layer[((a)) + (((b))*HARDWARE_map_width_tiles)] != unwalkable//middle hitzone
									&&
									HARDWARE_map_hit_layer[((a)) + (((b+1))*HARDWARE_map_width_tiles)] != unwalkable//middle hitzone
									&&
									HARDWARE_map_hit_layer[((a+1)) + ((b)*HARDWARE_map_width_tiles)] != unwalkable//middle hitzone
									&&
									HARDWARE_map_hit_layer[((a+1)) + (((b+1))*HARDWARE_map_width_tiles)] != unwalkable//middle hitzone
								)

							)
							{

								corner = walkable;

								if (corner == walkable)
								{
								//	If not already on the open list, add it to the open list.
									if (whichList[a][b] != onOpenList)
									{

										//Create a new open list item in the binary heap.
										newOpenListItemID = newOpenListItemID + 1; //each new item has a unique ID #
										m = numberOfOpenListItems+1;
										openList[m] = newOpenListItemID;//place the new open list item (actually, its ID#) at the bottom of the heap
										openX[newOpenListItemID] = a;
										openY[newOpenListItemID] = b;//record the x and y coordinates of the new item

										//Figure out its G cost
										if (abs(a-parentXval) == 1 && abs(b-parentYval) == 1)
											addedGCost = 14;//cost of going to diagonal squares
										else
											addedGCost = 10;//cost of going to non-diagonal squares
										Gcost[a][b] = Gcost[parentXval][parentYval] + addedGCost;

										//Figure out its H and F costs and parent
										Hcost[openList[m]] = 10*(abs(a - targetX) + abs(b - targetY));
										Fcost[openList[m]] = Gcost[a][b] + Hcost[openList[m]];
										parentX[a][b] = parentXval ; parentY[a][b] = parentYval;

										//Move the new open list item to the proper place in the binary heap.
										//Starting at the bottom, successively compare to parent items,
										//swapping as needed until the item finds its place in the heap
										//or bubbles all the way to the top (if it has the lowest F cost).
										while (m != 1) //While item hasn't bubbled to the top (m=1)
										{
											//Check if child's F cost is < parent's F cost. If so, swap them.
											if (Fcost[openList[m]] <= Fcost[openList[m/2]])
											{
												temp = openList[m/2];
												openList[m/2] = openList[m];
												openList[m] = temp;
												m = m/2;
											}
											else
												break;
										}
										numberOfOpenListItems = numberOfOpenListItems+1;//add one to the number of items in the heap

										//Change whichList to show that the new item is on the open list.
										whichList[a][b] = onOpenList;
									}

									//8.If adjacent cell is already on the open list, check to see if this
									//	path to that cell from the starting location is a better one.
									//	If so, change the parent of the cell and its G and F costs.
									else //If whichList(a,b) = onOpenList
									{


										//Figure out the G cost of this possible new path
										if (abs(a-parentXval) == 1 && abs(b-parentYval) == 1)
											addedGCost = 14;//cost of going to diagonal tiles
										else
											addedGCost = 10;//cost of going to non-diagonal tiles
										tempGcost = Gcost[parentXval][parentYval] + addedGCost;

										//If this path is shorter (G cost is lower) then change
										//the parent cell, G cost and F cost.
										if (tempGcost < Gcost[a][b]) //if G cost is less,
										{
											parentX[a][b] = parentXval; //change the square's parent
											parentY[a][b] = parentYval;
											Gcost[a][b] = tempGcost;//change the G cost

											//Because changing the G cost also changes the F cost, if
											//the item is on the open list we need to change the item's
											//recorded F cost and its position on the open list to make
											//sure that we maintain a properly ordered open list.
											int x=0;
											for (x = 1; x <= numberOfOpenListItems; x++) //look for the item in the heap
											{
												if (openX[openList[x]] == a && openY[openList[x]] == b) //item found
												{
													Fcost[openList[x]] = Gcost[a][b] + Hcost[openList[x]];//change the F cost

													//See if changing the F score bubbles the item up from it's current location in the heap
													m = x;
													while (m != 1) //While item hasn't bubbled to the top (m=1)
													{
														//Check if child is < parent. If so, swap them.
														if (Fcost[openList[m]] < Fcost[openList[m/2]])
														{
															temp = openList[m/2];
															openList[m/2] = openList[m];
															openList[m] = temp;
															m = m/2;
														}
														else
															break;
													}
													break; //exit for x = loop
												} //If openX(openList(x)) = a
											} //For x = 1 To numberOfOpenListItems
										}//If tempGcost < Gcost(a,b)

									}//else If whichList(a,b) = onOpenList
								}//If not cutting a corner
							}//If not a wall/obstacle square.
							//else whichList[a][b] = onClosedList;


						}//If not already on the closed list
					}//If not off the map
				}//for (a = parentXval-1; a <= parentXval+1; a++){
			}//for (b = parentYval-1; b <= parentYval+1; b++){

		}//if (numberOfOpenListItems != 0)

		//9.If open list is empty then there is no path.
		else
		{
			path = nonexistent; break;
		}

		//If target is added to open list then path has been found.
		if (whichList[targetX][targetY] == onOpenList)
		{
			path = found; break;
		}

	}
	while (1);//Do until path is found or deemed nonexistent

	//10.Save the path if it exists.
	if (path == found)
	{

		//a.Working backwards from the target to the starting location by checking
		//	each cell's parent, figure out the length of the path.
		pathX = targetX; pathY = targetY;
		do
		{
			//Look up the parent of the current cell.
			tempx = parentX[pathX][pathY];
			pathY = parentY[pathX][pathY];
			pathX = tempx;

			//Figure out the path length
			pathLength = pathLength + 1;
		}
		while (pathX != (startX) || pathY != (startY));

		//b.Resize the data bank to the right size in bytes
		pathBank = (int*) realloc (pathBank,
			pathLength*8);

		//c. Now copy the path information over to the databank. Since we are
		//	working backwards from the target to the start location, we copy
		//	the information to the data bank in reverse order. The result is
		//	a properly ordered set of path data, from the first step to the
		//	last.
		pathX = targetX ; pathY = targetY;
		cellPosition = pathLength*2;//start at the end
		do
		{
			cellPosition = cellPosition - 2;//work backwards 2 integers
			pathBank [cellPosition] = pathX;
			pathBank [cellPosition+1] = pathY;

			//d.Look up the parent of the current cell.
			tempx = parentX[pathX][pathY];
			pathY = parentY[pathX][pathY];
			pathX = tempx;

			//e.If we have reached the starting square, exit the loop.
		}
		while (pathX != (startX) || pathY != (startY));

		//11.Read the first path step into xPath/yPath arrays
		ReadPath(startingX,startingY);

	}
	return path;


//13.If there is no path to the selected target, set the pathfinder's
//	xPath and yPath equal to its current location and return that the
//	path is nonexistent.
noPath:
	xPath = startingX;
	yPath = startingY;
	return nonexistent;
}




//==========================================================
//READ PATH DATA: These functions read the path data and convert
//it to screen pixel coordinates.
void ReadPath(int currentX,int currentY)
{

//;	Note on PixelsPerFrame: The need for this parameter probably isn't
//;	that obvious, so a little explanation is in order. This
//;	parameter is used to determine if the pathfinder has gotten close
//;	enough to the center of a given path square to warrant looking up
//;	the next step on the path.
//;
//;	This is needed because the speed of certain sprites can
//;	make reaching the exact center of a path square impossible.
//;	In Demo #2, the chaser has a velocity of 3 pixels per frame. Our
//;	tile size is 50 pixels, so the center of a tile will be at location
//;	25, 75, 125, etc. Some of these are not evenly divisible by 3, so
//;	our pathfinder has to know how close is close enough to the center.
//;	It calculates this by seeing if the pathfinder is less than
//;	pixelsPerFrame # of pixels from the center of the square.
//
//;	This could conceivably cause problems if you have a *really* fast
//;	sprite and/or really small tiles, in which case you may need to
//;	adjust the formula a bit. But this should almost never be a problem
//;	for games with standard sized tiles and normal speeds. Our smiley
//;	in Demo #4 moves at a pretty fast clip and it isn't even close
//;	to being a problem.




	//If a path has been found for the pathfinder	...
	if (pathStatus == found)
	{

		//If path finder is just starting a new path or has reached the
		//center of the current path square (and the end of the path
		//hasn't been reached), look up the next path square.
		if (pathLocation < pathLength)
		{
			//if just starting or if close enough to center of square
			if (pathLocation == 0)
					pathLocation = pathLocation + 1;
		}

		//Read the path data.
		xPath = ReadPathX(pathLocation);
		yPath = ReadPathY(pathLocation);

	}

	//If there is no path for this pathfinder, simply stay in the current
 	//location.
	else
	{
		xPath = currentX;
		yPath = currentY;
	}
}


//The following two functions read the raw path data from the pathBank.
//You can call these functions directly and skip the readPath function
//above if you want. Make sure you know what your current pathLocation
//is.

//=============================================================================
// Name: ReadPathX
// Desc: Reads the x coordinate of the next path step
//=============================================================================
int ReadPathX(int pathLocation)
{
	int x=0;
	if (pathLocation <= pathLength)
	{

	//Read coordinate from bank
	x = pathBank [pathLocation*2-2];

	//Adjust the coordinates so they align with the center
	//of the path square (optional). This assumes that you are using
	//sprites that are centered -- i.e., with the midHandle command.
	//Otherwise you will want to adjust this.
	x = tileSize*x + 6;

	}
	return x;
}


//=============================================================================
// Name: ReadPathY
// Desc: Reads the y coordinate of the next path step
//=============================================================================
int ReadPathY(int pathLocation)
{
	int y=0;
	if (pathLocation <= pathLength)
	{

	//Read coordinate from bank
	y = pathBank [pathLocation*2-1];

	//Adjust the coordinates so they align with the center
	//of the path square (optional). This assumes that you are using
	//sprites that are centered -- i.e., with the midHandle command.
	//Otherwise you will want to adjust this.
	y = tileSize*y + 6;

	}
	return y;
}





//=========================================================================================================================
bool NPC_chase_npc(NPC** chaser_npcpp,NPC** target_npcpp)
{//=========================================================================================================================


	if(chaser_npcpp==NULL){ERROR_set_error("NPC_chase_npc()");return 0;}
	if(*chaser_npcpp==NULL){ERROR_set_error("NPC_chase_npc()");return 0;}
	NPC* chaser_npc = *chaser_npcpp;

	if(target_npcpp==NULL){ERROR_set_error("NPC_chase_npc()");return 0;}
	if(*target_npcpp==NULL){ERROR_set_error("NPC_chase_npc()");return 0;}
	NPC* target_npc = *target_npcpp;


	bool thereyet=0;

	if(chaser_npc==NULL||target_npc==NULL)
	{
		thereyet=1;
	}
	else
	{


		int xtarget=target_npc->MAP_x+target_npc->size_x/2;
		int ytarget=target_npc->MAP_y+(target_npc->size_y);//-(target_npc->hitsize_y));


		int chaserx=chaser_npc->MAP_x+chaser_npc->size_x/2;
		int chasery=chaser_npc->MAP_y+(chaser_npc->size_y-(chaser_npc->hitsize_y));














if(HARDWARE_map_id!=MAP_bobsgame_INTROTown)
{

		pathStatus = FindPath(chaser_npc, chaserx,chasery,xtarget,ytarget);

		if (pathStatus == found)//&&chaser_npc->walk_timer>chaser_npc->walking_speed)
		{
			//chaser_npc->walk_timer=0;

		//1.Read path information
			ReadPath(chaserx,chasery);

		//2.Move sprite. xLoc/yLoc = current location of sprite. xPath and
		//	yPath = coordinates of next step on the path that were/are
		//	read using the readPath function.
			//if (chaserx > xPath) NPC_move_pixel_animate(chaser_npc,LEFT);
			//if (chaserx < xPath) NPC_move_pixel_animate(chaser_npc,RIGHT);
			//if (chasery > yPath) NPC_move_pixel_animate(chaser_npc,UP);
			//if (chasery < yPath) NPC_move_pixel_animate(chaser_npc,DOWN);

			NPC_walk_to_xy_basichit(chaser_npcpp,SPEED_FASTEST,xPath,yPath);
			//PLAYER_walk_to_xy_basichit(xPath,yPath);


		}
}
else
{
	thereyet = PLAYER_walk_to_xy_basichit(xtarget,ytarget);


}

































		//if(stage==0)
		{


			//if(chaser_npc==PLAYER_npc)
			//{

				//thereyet = PLAYER_walk_to_xy_basichit(xtarget,ytarget);
			//}
			//else
			//{
				//thereyet = NPC_walk_to_xy_basichit(chaser_npc,chaser_npc->walking_speed,xtarget,ytarget);
			//}


			int amt=1; //if the chaser is within amt of npc,thereyet=1;
			if(chaserx>=xtarget-amt&&
			chaserx<=xtarget+amt &&
				chasery>=ytarget-amt&&
				chasery<=ytarget+amt)
				thereyet=1;

		}
		chaser_npc->ignore_player=0;


		//chaser_npc->chase_dir_x=chase_dir_x;
		//chaser_npc->chase_dir_y=chase_dir_y;
		//chaser_npc->chase_flip_xy=flip_xy;
		//chaser_npc->chase_stage=stage;
		//chaser_npc->chase_stuck_x=stuck_x;
		//chaser_npc->chase_stuck_y=stuck_y;

	}


	return thereyet;
}


/*

//=========================================================================================================================
bool NPC_chase_npc(NPC *chaser_npc,NPC *target_npc)
{//=========================================================================================================================
	bool thereyet=0;

	if(chaser_npc==NULL||target_npc==NULL)
	{
		thereyet=1;
	}
	else
	{



		int xtarget=target_npc->MAP_x+target_npc->size_x/2;
		int ytarget=target_npc->MAP_y+(target_npc->size_y-target_npc->hitsize_y);


		int chaserx=chaser_npc->MAP_x+chaser_npc->size_x/2;
		int chasery=chaser_npc->MAP_y+(chaser_npc->size_y-chaser_npc->hitsize_y);

		//typedef struct
		//	{
		//	int NPC_id;
		//	int chase_dir_x=0;
		//	int chase_dir_y=0;
		//	int opp_dir_x=0;
		//	int opp_dir_y=0;
		//	bool flip_xy=0;
		//	int stage=0;
		//	int stuck_x;
		//	int stuck_y;
		//	struct NPC_chaser *next;
		//	}NPC_chaser;

		static int last_x=0;//current_npc_chaser->last_x;
		static int last_y=0;//current_npc_chaser->last_y;
		//static int new_x=0;//current_npc_chaser->new_x;
		//static int new_y=0;//current_npc_chaser->new_y;
		//static bool waiting=0;//current_npc_chaser->waiting;



		int chase_dir_x=chaser_npc->chase_dir_x;
		int chase_dir_y=chaser_npc->chase_dir_y;

		bool flip_xy=chaser_npc->chase_flip_xy;
		int stage=chaser_npc->chase_stage;
		int stuck_x=chaser_npc->chase_stuck_x;
		int stuck_y=chaser_npc->chase_stuck_y;

		int opp_dir_x=0;
		int opp_dir_y=0;

		if(chase_dir_x==LEFT)opp_dir_x = RIGHT;
		if(chase_dir_x==RIGHT)opp_dir_x = LEFT;
		if(chase_dir_y==UP)opp_dir_y = DOWN;
		if(chase_dir_y==DOWN)opp_dir_y = UP;


		//if((last_x!=0||last_y!=0) &&// this is so a cluster of guys can pop on the screen one after the other i think
		//	(xtarget>last_x+16||target_npc->MAP_x+target_npc->MAP_x/2<last_x-16||ytarget>last_y+16||ytarget<last_y-16))
		//{
		//	///NPC_chaser *NPC_chaser = first_npc_chaser;
		//	//bool stop=0;
		//	//while(stop==0)
		//	//{
		//		//NPC_chaser->NPC_id->MAP_x = -NPC_chaser->NPC_id->size_x;
		//		//NPC_chaser->NPC_id->MAP_y = -NPC_chaser->NPC_id->size_y;//hiding
		//		//NPC_chaser->stage=0;
		//		//if(NPC_chaser->next!=NULL)NPC_chaser = (NPC_chaser *)NPC_chaser->next;
		//		//else stop=1;
		//	//}
		//	waiting=1;
		//	new_x = xtarget;
		//	new_y = ytarget;
		//	last_x = xtarget;
		//	last_y = ytarget;
		//}
		//else
		//if(waiting==1)
		//{
		//	last_x = xtarget;
		//	last_y = ytarget;
		//	if(xtarget<new_x-16||xtarget>new_x+16||ytarget<new_y-16||ytarget>new_y+16)
		//	{
		//		waiting=0;
	////			NPC_chaser *NPC_chaser = first_npc_chaser;
	////			bool stop=0;
	////			while(stop==0)
	////			{
		////			NPC_chaser->NPC_id->MAP_x = new_x;
		////			NPC_chaser->NPC_id->MAP_y = new_y;
		////			NPC_chaser->NPC_id->walk_timer = 0;
		////			if(NPC_chaser->next!=NULL)NPC_chaser = (NPC_chaser *)NPC_chaser->next;
		////			else stop=1;
	////			}
		//	}
		//}
		//else
		{
			last_x = xtarget;
			last_y = ytarget;
			npc->ignore_player=1;
			if(stage==0)
			{
			if(xtarget<chaserx) {chase_dir_x = LEFT;	opp_dir_x = RIGHT;}// chasing to the left
			if(xtarget>chaserx) {chase_dir_x = RIGHT; opp_dir_x = LEFT;}// chasing to the right
			if(ytarget<chasery) {chase_dir_y = UP;	opp_dir_y = DOWN;}// chasing up
			if(ytarget>chasery) {chase_dir_y = DOWN;	opp_dir_y = UP;}// chasing down

			if(!(	xtarget<chaserx&&
					xtarget>chaserx&&
					ytarget<chasery&&
					ytarget>chasery)
				)// IF ITS NOT ALREADY CLOSE TO THE SPRITE THEN CHECK TO SEE IF ITS BEING BLOCKED
				{
					if(NPC_check_hit_layer_direction(chaser_npc,chase_dir_x)&&NPC_check_hit_layer_direction(chaser_npc,chase_dir_y))
					{
						stage = 2;//IF IT CANT GO IN BOTH CHASE DIRECTIONS,START THE SEQUENCE
					}
					else
						if((NPC_check_hit_layer_direction(chaser_npc,chase_dir_x)&&ytarget==chasery)||
							(NPC_check_hit_layer_direction(chaser_npc,chase_dir_y)&&xtarget==chaserx)
						)
						{
							stage = 1;// IF ITS TRAPPED BY BEING DIRECTLY ACROSS FROM THE MAIN SPRITE WITH A WALL BETWEEN,DO STAGE 1
						}
				}
			}
			if(stage!=0)//&&chaser_npc->walk_timer>chaser_npc->walking_speed)
			{
				//chaser_npc->walk_timer=0;


				if(stage==1) //STAGE 1 check if its stuck on anything
				{
					if(NPC_check_hit_layer_direction(chaser_npc,chase_dir_x)&&NPC_check_hit_layer_direction(chaser_npc,chase_dir_y))
					{
						stage = 2; //THIS IS THE SAME AS ABOVE,BUT ITS A BREAK-OUT FOR WHEN IT HITS A CORNER IN THIS LOOP
					}
					else
						if(NPC_check_hit_layer_direction(chaser_npc,chase_dir_y))
						{
							NPC_check_hit_move_pixel_animate(chaser_npc,chase_dir_x); // NEED TO GO Y
							flip_xy = 1;
						}
						else
							if(NPC_check_hit_layer_direction(chaser_npc,chase_dir_x))
							{
								NPC_check_hit_move_pixel_animate(chaser_npc,chase_dir_y); // NEED TO GO X
								if(!NPC_check_hit_layer_direction(chaser_npc,chase_dir_x))NPC_check_hit_move_pixel_animate(chaser_npc,chase_dir_x);
								flip_xy = 0;
							}
								else stage = 0;
				}
				else
				if(stage==2)
				{
					if(flip_xy==1)
					{
						int temp_chase = chase_dir_x;
						int temp_opp = opp_dir_x;
						chase_dir_x = chase_dir_y;
						opp_dir_x = opp_dir_y;
						chase_dir_y = temp_chase;
						opp_dir_y = temp_opp;
						flip_xy=0;
					}
					NPC_check_hit_move_pixel_animate(chaser_npc,opp_dir_y);// keep going down
					//		go opp_dir_y until hit wall or can go chase_dir_x
					//			IF CAN GO chase_dir_x UNSTUCK
					if(!NPC_check_hit_layer_direction(chaser_npc,chase_dir_x)){NPC_check_hit_move_pixel_animate(chaser_npc,chase_dir_x); stage = 0;}
					if(NPC_check_hit_layer_direction(chaser_npc,opp_dir_y))
					{
						if(chaserx==stuck_x&&chasery==stuck_y)
						{
							stage=10;
						}
						else
						{
							stuck_x =chaserx;
							stuck_y =chasery;
							stage = 3;
						}
					}
				}
				else
				if(stage==3) // THIS IS WHERE I SHOULD FLIP IT!
				{
					//if cant go opp_dir_y
					NPC_check_hit_move_pixel_animate(chaser_npc,opp_dir_x);// keep going right
					if(!NPC_check_hit_layer_direction(chaser_npc,opp_dir_y)){NPC_check_hit_move_pixel_animate(chaser_npc,opp_dir_y);stage=2;}
					if(NPC_check_hit_layer_direction(chaser_npc,opp_dir_x))stage=4;
				}
				else
				if(stage==4)
				{
					NPC_check_hit_move_pixel_animate(chaser_npc,chase_dir_x);
					NPC_check_hit_move_pixel_animate(chaser_npc,chase_dir_y);
					if(NPC_check_hit_layer_direction(chaser_npc,chase_dir_x)&&NPC_check_hit_layer_direction(chaser_npc,chase_dir_y)) stage = 5;
				}
				else
				if(stage==5)
				{
					NPC_check_hit_move_pixel_animate(chaser_npc,opp_dir_x); // keep going right
					if (!NPC_check_hit_layer_direction(chaser_npc,chase_dir_y)){NPC_check_hit_move_pixel_animate(chaser_npc,chase_dir_y); stage = 6; }//if can go up do stage 5
					if (NPC_check_hit_layer_direction(chaser_npc,opp_dir_x))stage = 7; // if hit right wall do stage 7
				}
				else
				if(stage==6)
				{
					NPC_check_hit_move_pixel_animate(chaser_npc,chase_dir_y); // go up until hit wall or can go left
					if(!(NPC_check_hit_layer_direction(chaser_npc,chase_dir_x))){NPC_check_hit_move_pixel_animate(chaser_npc,chase_dir_x); stage = 0;}
					if (NPC_check_hit_layer_direction(chaser_npc,chase_dir_y))stage=0 ; //UNSTUCK HOPEFULLY
				}
				else
				if(stage==7)
				{
					NPC_check_hit_move_pixel_animate(chaser_npc,opp_dir_y); //go down until hit wall or can go right
					if(!(NPC_check_hit_layer_direction(chaser_npc,opp_dir_x)))stage = 5;
					if (NPC_check_hit_layer_direction(chaser_npc,opp_dir_y))
					{
						stage=8 ; //UNSTUCK HOPEFULLY
					}
				}
				else
				if(stage==8)
				{
					NPC_check_hit_move_pixel_animate(chaser_npc,chase_dir_x);
					if(!NPC_check_hit_layer_direction(chaser_npc,opp_dir_y)){ NPC_check_hit_move_pixel_animate(chaser_npc,opp_dir_y); stage = 0;}
					if(NPC_check_hit_layer_direction(chaser_npc,chase_dir_x))stage = 9;
				}
				else
				if(stage==9)
				{
					NPC_check_hit_move_pixel_animate(chaser_npc,chase_dir_y);
					if(!NPC_check_hit_layer_direction(chaser_npc,chase_dir_x)){NPC_check_hit_move_pixel_animate(chaser_npc,chase_dir_x);stage=8;}
					if(NPC_check_hit_layer_direction(chaser_npc,chase_dir_y))stage=0;
				}
				else
				if(stage==10)
				{
					NPC_check_hit_move_pixel_animate(chaser_npc,chase_dir_y);
					if (NPC_check_hit_layer_direction(chaser_npc,chase_dir_y)) stage = 11; // if hit right wall do stage 7
				}
				else
				if(stage==11)
				{
					NPC_check_hit_move_pixel_animate(chaser_npc,opp_dir_x);
					if (NPC_check_hit_layer_direction(chaser_npc,opp_dir_x))stage=0 ; //UNSTUCK HOPEFULLY
				}
			}
			else
			if(stage==0)
			{
				//NPC_chaser *NPC_chaser = first_npc_chaser;
				//bool stop=0;
				//while(stop==0)
				//{
					//if(chaser_npc!=NPC_chaser->NPC_id)
					//{
						//int amt=9; //if the chaser is right on top of the a different npc,wiggle to get past it..
							//if(chaserx>=NPC_chaser->NPC_id->MAP_x+NPC_chaser->NPC_id->size_x/2-amt&&chaserx<=NPC_chaser->NPC_id->MAP_x+NPC_chaser->NPC_id->size_x/2+amt &&
								//chasery>=NPC_chaser->NPC_id->MAP_y+NPC_chaser->NPC_id->size_y-(NPC_chaser->NPC_id->hitsize_y)-amt&&chasery<=NPC_chaser->NPC_id->MAP_y+NPC_chaser->NPC_id->size_y-(NPC_chaser->NPC_id->hitsize_y)+amt)
								//{
								//bool nostuck=r(2);
									//if(nostuck)
								//	{
										//if(chaserx<=NPC_chaser->NPC_id->MAP_x+NPC_chaser->NPC_id->size_x/2){NPC_check_hit_move_pixel(chaser_npc,LEFT);} //move left
									//	if(chaserx>=NPC_chaser->NPC_id->MAP_x+NPC_chaser->NPC_id->size_x/2){NPC_check_hit_move_pixel(chaser_npc,RIGHT);}//move right
								//	}
								//	else
								//	{
									//	if(chasery<=NPC_chaser->NPC_id->MAP_y+NPC_chaser->NPC_id->size_y-(NPC_chaser->NPC_id->hitsize_y)){NPC_check_hit_move_pixel(chaser_npc,UP);}//move up
								//		if(chasery>=NPC_chaser->NPC_id->MAP_y+NPC_chaser->NPC_id->size_y-(NPC_chaser->NPC_id->hitsize_y)){NPC_check_hit_move_pixel(chaser_npc,DOWN);}//move down
								//	}
								//}
					//}
					//if(NPC_chaser->next!=NULL)NPC_chaser = (NPC_chaser *)NPC_chaser->next;
					//else stop=1;
				//}





				if(chaser_npc==PLAYER_npc)
				{

					thereyet = PLAYER_walk_to_xy_basichit(xtarget,ytarget);
				}
				else
				{
					thereyet = NPC_walk_to_xy_basichit(chaser_npc,chaser_npc->walking_speed,xtarget,ytarget);
				}


				int amt=9; //if the chaser is within amt of npc,thereyet=1;
				if(chaserx>=xtarget-amt&&
				chaserx<=xtarget+amt &&
					chasery>=ytarget-amt&&
					chasery<=ytarget+amt)
					thereyet=1;

			}
			npc->ignore_player=0;
		}

		chaser_npc->chase_dir_x=chase_dir_x;
		chaser_npc->chase_dir_y=chase_dir_y;
		chaser_npc->chase_flip_xy=flip_xy;
		chaser_npc->chase_stage=stage;
		chaser_npc->chase_stuck_x=stuck_x;
		chaser_npc->chase_stuck_y=stuck_y;
	}

	return thereyet;
}

*/












//=========================================================================================================================
void NPC_stop_chasing(NPC** npcpp)
{//=========================================================================================================================



	if(npcpp==NULL){ERROR_set_error("NPC_stop_chasing()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_stop_chasing()");return;}
	NPC* npc = *npcpp;


/*
	NPC_chaser *current_npc_chaser = first_npc_chaser;
	if(current_npc_chaser!=NULL)
	{
		if(current_npc_chaser->NPC_id==delete_npc)
		{
			first_npc_chaser = (NPC_chaser *)current_npc_chaser->next;
			free(current_npc_chaser);
		}
		else
		{
			while(current_npc_chaser->next!=NULL)
			{
				NPC_chaser *temp_npc_chaser = (NPC_chaser *)current_npc_chaser->next;
				if(temp_npc_chaser->NPC_id==delete_npc)
				{
					current_npc_chaser->next = temp_npc_chaser->next;
					free(temp_npc_chaser);
				}
				if(current_npc_chaser->next!=NULL)current_npc_chaser = (NPC_chaser *)current_npc_chaser->next;
			}
		}
		//first one, last one, only one.
	}
	*/

		npc->chase_dir_x=0;
		npc->chase_dir_y=0;
		npc->chase_flip_xy=0;
		npc->chase_stage=0;
		npc->chase_stuck_x=0;
		npc->chase_stuck_y=0;

}
//=========================================================================================================================
void NPC_smart_avoid_npc(NPC** avoider_npcpp,NPC** avoid_npcpp)
{//=========================================================================================================================

	if(avoider_npcpp==NULL){ERROR_set_error("NPC_smart_avoid_npc()");return;}
	if(*avoider_npcpp==NULL){ERROR_set_error("NPC_smart_avoid_npc()");return;}
	NPC* avoider_npc = *avoider_npcpp;

	if(avoid_npcpp==NULL){ERROR_set_error("NPC_smart_avoid_npc()");return;}
	if(*avoid_npcpp==NULL){ERROR_set_error("NPC_smart_avoid_npc()");return;}
	NPC* avoid_npc = *avoid_npcpp;




	/*
	typedef struct
	{
	int NPC_id;
	int avoid_dir_x=0;
	int avoid_dir_y=0;
	int opp_dir_x=0;
	int opp_dir_y=0;
	bool flip_xy=0;
	int stage=0;
	struct NPC_avoider *next;
	}NPC_avoider;
	*/

	//NPC_avoider *current_npc_avoider = NULL;

	//if(first_npc_avoider==NULL)
	//{
		//first_npc_avoider = malloc(sizeof(NPC_avoider));
		//first_npc_avoider->NPC_id = (NPC *)avoider_npc;
		//first_npc_avoider->avoid_dir_x = 0;
		//first_npc_avoider->avoid_dir_y = 0;
		//first_npc_avoider->opp_dir_x = 0;
		//first_npc_avoider->opp_dir_y = 0;
		//first_npc_avoider->flip_xy = 0;
		//first_npc_avoider->stage=0;
		//first_npc_avoider->next=NULL;
	//}

	//current_npc_avoider = first_npc_avoider;
	//while(current_npc_avoider->NPC_id!=avoider_npc)
	//{
		//if(current_npc_avoider->next!=NULL)
		//{
			//NPC_avoider *temp = (NPC_avoider *)current_npc_avoider->next;
			//current_npc_avoider = temp;
		//}
		//else
		//{
			//current_npc_avoider->next = malloc(sizeof(NPC_avoider));
			//current_npc_avoider = (NPC_avoider *)current_npc_avoider->next;
			//current_npc_avoider->NPC_id = (NPC *)avoider_npc;
			//current_npc_avoider->avoid_dir_x = 0;
			//current_npc_avoider->avoid_dir_y = 0;
			//current_npc_avoider->opp_dir_x = 0;
			//current_npc_avoider->opp_dir_y = 0;
			//current_npc_avoider->flip_xy = 0;
			//current_npc_avoider->stage=0;
			//current_npc_avoider->next=NULL;
		//}
	//}//

	int avoid_dir_x=avoider_npc->chase_dir_x;
	int avoid_dir_y=avoider_npc->chase_dir_y;

	bool flip_xy=avoider_npc->chase_flip_xy;
	int stage=avoider_npc->chase_stage;


		int opp_dir_x=0;
		int opp_dir_y=0;

		if(avoid_dir_x==LEFT)opp_dir_x = RIGHT;
		if(avoid_dir_x==RIGHT)opp_dir_x = LEFT;
		if(avoid_dir_y==UP)opp_dir_y = DOWN;
		if(avoid_dir_y==DOWN)opp_dir_y = UP;

	avoider_npc->ignore_player=1;
	int amt_x = avoider_npc->MAP_x - avoid_npc->MAP_x;
	int amt_y = avoider_npc->MAP_y - avoid_npc->MAP_y;
	if(amt_x<0)amt_x = amt_x * -1;
	if(amt_y<0)amt_y = amt_y * -1;

	if(amt_x<16&&amt_y<16)stage=0;
	if(stage==0)
	{
		if(avoid_npc->MAP_x>avoider_npc->MAP_x) {avoid_dir_x = LEFT;	opp_dir_x = RIGHT;}// chasing to the left
		if(avoid_npc->MAP_x<avoider_npc->MAP_x) {avoid_dir_x = RIGHT; opp_dir_x = LEFT;}// chasing to the right
		if(avoid_npc->MAP_y>avoider_npc->MAP_y) {avoid_dir_y = UP;	opp_dir_y = DOWN;}// chasing up
		if(avoid_npc->MAP_y<avoider_npc->MAP_y) {avoid_dir_y = DOWN;	opp_dir_y = UP;}// chasing down

		if(!(avoid_npc->MAP_x<avoider_npc->MAP_x+avoider_npc->size_x&&
			avoid_npc->MAP_x+avoid_npc->size_x>avoider_npc->MAP_x&&
			avoid_npc->MAP_y+avoid_npc->size_y-(avoid_npc->hitsize_y)<avoider_npc->MAP_y+avoider_npc->size_y&&
			avoid_npc->MAP_y+avoid_npc->size_y>avoider_npc->MAP_y+avoider_npc->size_y-(avoider_npc->hitsize_y))
		)// IF ITS NOT ALREADY CLOSE TO THE SPRITE THEN CHECK TO SEE IF ITS BEING BLOCKED
		{
			if(NPC_check_hit_layer_direction(avoider_npcpp,avoid_dir_x)&&NPC_check_hit_layer_direction(avoider_npcpp,avoid_dir_y))
			{
				stage = 2;//IF IT CANT GO IN BOTH avoid DIRECTIONS,START THE SEQUENCE
			}
			else
				if((NPC_check_hit_layer_direction(avoider_npcpp,avoid_dir_x)&&avoid_npc->MAP_y==avoider_npc->MAP_y)||
					(NPC_check_hit_layer_direction(avoider_npcpp,avoid_dir_y)&&avoid_npc->MAP_x==avoider_npc->MAP_x))
				{
					stage = 1;// IF ITS TRAPPED BY BEING DIRECTLY ACROSS FROM THE MAIN SPRITE WITH A WALL BETWEEN,DO STAGE 1
				}
		}
	}
	if(avoider_npc->ms>avoider_npc->walking_speed&&stage!=0)
	{
		if(stage==1) //STAGE 1 check if its stuck on anything
		{
			if(NPC_check_hit_layer_direction(avoider_npcpp,avoid_dir_x)&&NPC_check_hit_layer_direction(avoider_npcpp,avoid_dir_y))
			{
				stage = 2; //THIS IS THE SAME AS ABOVE,BUT ITS A BREAK-OUT FOR WHEN IT HITS A CORNER IN THIS LOOP
			}
			else
				if(NPC_check_hit_layer_direction(avoider_npcpp,avoid_dir_y))
				{
					NPC_check_hit_move_pixel_animate(avoider_npcpp,avoid_dir_x); // NEED TO GO Y
					flip_xy = 1;
				}
				else
					if(NPC_check_hit_layer_direction(avoider_npcpp,avoid_dir_x))
					{
						NPC_check_hit_move_pixel_animate(avoider_npcpp,avoid_dir_y); // NEED TO GO X
						if(!NPC_check_hit_layer_direction(avoider_npcpp,avoid_dir_x))NPC_check_hit_move_pixel_animate(avoider_npcpp,avoid_dir_x);
						flip_xy = 0;
					}
						else stage = 0;
		}
		if(stage==2)
		{
			if(flip_xy==1)
			{
				int temp_avoid = avoid_dir_x;
				int temp_opp = opp_dir_x;
				avoid_dir_x = avoid_dir_y;
				opp_dir_x = opp_dir_y;
				avoid_dir_y = temp_avoid;
				opp_dir_y = temp_opp;
				flip_xy=0;
			}
			NPC_check_hit_move_pixel_animate(avoider_npcpp,opp_dir_y);// keep going down
			//		go opp_dir_y until hit wall or can go avoid_dir_x
			//			IF CAN GO avoid_dir_x UNSTUCK
			if(!NPC_check_hit_layer_direction(avoider_npcpp,avoid_dir_x)){NPC_check_hit_move_pixel_animate(avoider_npcpp,avoid_dir_x); stage = 0;}
			if(NPC_check_hit_layer_direction(avoider_npcpp,opp_dir_y))
			{
					stage = 3;
			}
		}
		if(stage==3) // THIS IS WHERE I SHOULD FLIP IT!
		{//if cant go opp_dir_y
			NPC_check_hit_move_pixel_animate(avoider_npcpp,opp_dir_x);// keep going right
			if(!NPC_check_hit_layer_direction(avoider_npcpp,opp_dir_y)){NPC_check_hit_move_pixel_animate(avoider_npcpp,opp_dir_y);stage=2;}
			if(NPC_check_hit_layer_direction(avoider_npcpp,opp_dir_x))stage=4;
		}
		if(stage==4)
		{
			NPC_check_hit_move_pixel_animate(avoider_npcpp,avoid_dir_x);
			if(NPC_check_hit_layer_direction(avoider_npcpp,avoid_dir_x))stage=5;
		}
		if(stage==5)
		{
			NPC_check_hit_move_pixel_animate(avoider_npcpp,avoid_dir_y);
			if(NPC_check_hit_layer_direction(avoider_npcpp,avoid_dir_y))
			{
					flip_xy=1;
					stage=2;
			}
		}
		avoider_npc->ms=0;
	}
	if(stage==0)
	{
		//NPC_avoider *NPC_avoider = first_npc_avoider;
		//bool stop=0;
		//while(stop==0)
		//{
		//if(avoider_npc!=NPC_avoider->NPC_id)
		//{
			//int amt=9;
			//if(avoider_npc->MAP_x+avoider_npc->size_x/2>=NPC_avoider->NPC_id->MAP_x+NPC_avoider->NPC_id->size_x/2-amt&&avoider_npc->MAP_x+avoider_npc->size_x/2<=NPC_avoider->NPC_id->MAP_x+NPC_avoider->NPC_id->size_x/2+amt&&
				//avoider_npc->MAP_y+avoider_npc->size_y-(avoider_npc->hitsize_y)>=NPC_avoider->NPC_id->MAP_y+NPC_avoider->NPC_id->size_y-(NPC_avoider->NPC_id->hitsize_y)-amt&&avoider_npc->MAP_y+avoider_npc->size_y-(avoider_npc->hitsize_y)<=NPC_avoider->NPC_id->MAP_y+NPC_avoider->NPC_id->size_y-(NPC_avoider->NPC_id->hitsize_y)+amt)
				//{
					//bool nostuck=r(2);
					//if(nostuck)
					//{
						//if(avoider_npc->MAP_x<=NPC_avoider->NPC_id->MAP_x){NPC_check_hit_move_pixel(avoider_npc,LEFT);} //move left
						//if(avoider_npc->MAP_x>=NPC_avoider->NPC_id->MAP_x){NPC_check_hit_move_pixel(avoider_npc,RIGHT);}//move right
					//}
					//else
					//{
						//if(avoider_npc->MAP_y<=NPC_avoider->NPC_id->MAP_y){NPC_check_hit_move_pixel(avoider_npc,UP);}//move up
						//if(avoider_npc->MAP_y>=NPC_avoider->NPC_id->MAP_y){NPC_check_hit_move_pixel(avoider_npc,DOWN);}//move down
					//}
				//}
		//}
		//if(NPC_avoider->next!=NULL)NPC_avoider = (NPC_avoider *)NPC_avoider->next;
		//else stop=1;
		//}
		NPC_walk_away_from_point(avoider_npcpp,SPEED_FAST,avoid_npc->MAP_x,avoid_npc->MAP_y);
	}
	avoider_npc->ignore_player=0;
	avoider_npc->chase_dir_x=avoid_dir_x;
	avoider_npc->chase_dir_y=avoid_dir_y;

	avoider_npc->chase_flip_xy=flip_xy;
	avoider_npc->chase_stage=stage;
}



//=========================================================================================================================
void NPC_stop_avoiding(NPC** npcpp)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_stop_avoiding()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_stop_avoiding()");return;}
	NPC* npc = *npcpp;

	/*NPC_avoider *current_npc_avoider = first_npc_avoider;
	if(current_npc_avoider!=NULL)
	{
		if(current_npc_avoider->NPC_id==delete_npc)
		{
		first_npc_avoider = (NPC_avoider *)current_npc_avoider->next;
		free(current_npc_avoider);
		}
		else
		{
		while(current_npc_avoider->next!=NULL)
		{
			NPC_avoider *temp_npc_avoider = (NPC_avoider *)current_npc_avoider->next;
			if(temp_npc_avoider->NPC_id==delete_npc)
			{
				current_npc_avoider->next = temp_npc_avoider->next;
				free(temp_npc_avoider);
			}
			if(current_npc_avoider->next!=NULL)current_npc_avoider = (NPC_avoider *)current_npc_avoider->next;
		}
		}
	}*/

		npc->chase_dir_x=0;
		npc->chase_dir_y=0;

		npc->chase_flip_xy=0;
		npc->chase_stage=0;
		npc->chase_stuck_x=0;
		npc->chase_stuck_y=0;

}
//=========================================================================================================================
void NPC_spin_in_circle(NPC** npcpp ,int r)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_spin_in_circle()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_spin_in_circle()");return;}
	NPC* npc = *npcpp;

	static int mapx=0;
	static int mapy=0;
	if(mapx==0) mapx = npc->MAP_x;
	if(mapy==0) mapy = npc->MAP_y;
	static int y=0;
	int x=0;
	static bool flipy=0;
	static bool flipx=0;
	static int last_x=0;
	static int changed_amt=0;
	if(npc->ms>npc->walking_speed)
	{
		if(flipy==0)
		{
			y+=changed_amt;
			if(y>r)
			{
				flipy=1;
				y = r;
				flipx=1;
			}
		}
		else
			if(flipy==1)
			{
				y-=changed_amt;
				if(y<-r)
				{
					flipy=0;
					y = -r;
					flipx=0;
				}
			}
		int tempy;
		tempy = y;

		if(tempy<0)tempy*=-1;
		x = (int)sqrt((r*r)-(tempy*tempy));
			// x = (int)x*x;
			changed_amt = 1 + x-last_x;
			if(changed_amt<0)changed_amt*=-1;
			last_x = x;
		if(flipx==1)npc->MAP_x = mapx-x;
			else npc->MAP_x = mapx+x;
		npc->MAP_y = mapy+y;
		npc->ms=0;
	}
	/*
	look at radius
	points = radius * 2;

	y based = middle (both sides)
	x based = bottom and top
	example:
		radius 20
		start 0,20 x based
	do 10 x based
		start 10,y
		10 y points,etc

	private final void circlePoints(int cx,int cy,int x,int y,int pix)
	{
		int act = Color.red.getRGB();

		if (x == 0) {
			raster.setPixel(act,cx,cy + y);
			raster.setPixel(pix,cx,cy - y);
			raster.setPixel(pix,cx + y,cy);
			raster.setPixel(pix,cx - y,cy);
		} else
		if (x == y) {
			raster.setPixel(act,cx + x,cy + y);
			raster.setPixel(pix,cx - x,cy + y);
			raster.setPixel(pix,cx + x,cy - y);
			raster.setPixel(pix,cx - x,cy - y);
		} else
		if (x < y) {
			raster.setPixel(act,cx + x,cy + y);
			raster.setPixel(pix,cx - x,cy + y);
			raster.setPixel(pix,cx + x,cy - y);
			raster.setPixel(pix,cx - x,cy - y);
			raster.setPixel(pix,cx + y,cy + x);
			raster.setPixel(pix,cx - y,cy + x);
			raster.setPixel(pix,cx + y,cy - x);
			raster.setPixel(pix,cx - y,cy - x);
		}
	}
	public void circleMidpoint(int xCenter,int yCenter,int radius,Color c)
	{
		int pix = c.getRGB();
		int x = 0;
		int y = radius;
		int p = (5 - radius*4)/4;

		circlePoints(xCenter,yCenter,x,y,pix);
		while (x < y) {
			x++;
			if (p < 0) {
				p += 2*x+1;
			} else {
				y--;
				p += 2*(x-y)+1;
			}
			circlePoints(xCenter,yCenter,x,y,pix);
		}
	}*/
}
//=========================================================================================================================
void NPC_pushable_avoid_other_npcs()
{//=========================================================================================================================

	if(first_NPC==NULL)return;

	NPC *current_npc = first_NPC;
	while(current_npc->next!=NULL)
	{
		current_npc = (NPC *)current_npc->next;
		if(current_npc->pushable==1)NPC_pushable_crowd_behavior(&current_npc);
	}
}
//=========================================================================================================================
void NPC_delete_chase_structs()
{//=========================================================================================================================
	/*NPC_chaser *current_npc_chaser;
	NPC_chaser *next_npc_chaser;
	if(first_npc_chaser!=NULL)
	{
		while(first_npc_chaser->next!=NULL)
		{
			current_npc_chaser = first_npc_chaser;
			next_npc_chaser = current_npc_chaser;
			while(next_npc_chaser->next!=NULL)
			{
				current_npc_chaser=next_npc_chaser;
				next_npc_chaser = (NPC_chaser *)next_npc_chaser->next;
			}
			free(next_npc_chaser);
			current_npc_chaser->next=NULL;
		}
		free(first_npc_chaser);
		first_npc_chaser = NULL;
	}*/
}
//=========================================================================================================================
void NPC_delete_avoid_structs()
{//=========================================================================================================================
	/*NPC_avoider *current_npc_avoider;
	NPC_avoider *next_npc_avoider;
	if(first_npc_avoider!=NULL)
	{
		while(first_npc_avoider->next!=NULL)
		{
			current_npc_avoider = first_npc_avoider;
			next_npc_avoider = current_npc_avoider;
			while(next_npc_avoider->next!=NULL)
			{
				current_npc_avoider=next_npc_avoider;
				next_npc_avoider = (NPC_avoider *)next_npc_avoider->next;
			}
			free(next_npc_avoider);
			current_npc_avoider->next=NULL;
		}
		free(first_npc_avoider);
		first_npc_avoider = NULL;
	}*/
}
//=========================================================================================================================
void NPC_delete_follow_structs()
{//=========================================================================================================================
	NPC_follower *current_npc_follower;
	NPC_follower *next_npc_follower;
	if(first_npc_follower!=NULL)
	{
		while(first_npc_follower->next!=NULL)
		{
			current_npc_follower = first_npc_follower;
			next_npc_follower = current_npc_follower;
			while(next_npc_follower->next!=NULL)
			{
				current_npc_follower=next_npc_follower;
				next_npc_follower = (NPC_follower *)next_npc_follower->next;
			}
			free(next_npc_follower);
			current_npc_follower->next=NULL;
		}
		free(first_npc_follower);
		first_npc_follower = NULL;
	}
}
//=========================================================================================================================
void NPC_delete_pull_againster_structs()
{//=========================================================================================================================
	//NPC_pull_againster *current_npc_pull_againster;
	//NPC_pull_againster *next_npc_pull_againster;
	//if(first_npc_pull_againster!=NULL)
	//{
	//	while(first_npc_pull_againster->next!=NULL)
	//	{
	//		current_npc_pull_againster = first_npc_pull_againster;
	//		next_npc_pull_againster = current_npc_pull_againster;
	//		while(next_npc_pull_againster->next!=NULL)
	//		{
	//			current_npc_pull_againster=next_npc_pull_againster;
	//			next_npc_pull_againster = (NPC_pull_againster *)next_npc_pull_againster->next;
	//		}
	//		free(next_npc_pull_againster);
	//		current_npc_pull_againster->next=NULL;
	//	}
	//	free(first_npc_pull_againster);
	//	first_npc_pull_againster = NULL;
	//}
}

//=========================================================================================================================
void NPC_fade_out_and_delete(NPC** npcpp)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_fade_out_and_delete()");return;}
	if(*npcpp==NULL){ERROR_set_error("NPC_fade_out_and_delete()");return;}
	NPC* npc = *npcpp;


	if(npc!=NULL)
	{
		if(npc->alpha>0){NPC_set_alpha(npcpp,npc->alpha-1);}else{NPC_delete_npc(npcpp);}
	}

}









































///================================================
///================================================
///================================================
///================================================
///================================================
///================================================
///================================================
///================================================
///================================================BEGIN BEGIN BEGIN
///================================================
///================================================
///================================================
///================================================
///================================================
///================================================
///================================================
///================================================
///================================================
///================================================
///================================================













//problems:

//npc still gets stuck facing down sometimes
//npcs are too jittery
//walking into corners back and forth looks bad.


//solutions:
//npc can stop momentarily if there is someone in their way, unless they are walking faster

//npcs can all push each other out of the way and never change direction when stuck in a corner

//npcs should pathfind their way out of corners and not randomly decide a direction

//jitter is caused by pushing back and forth. npcs should communicate to decide who is pushing and who is being pushed?


//i need some fucking adderall (feb 2010)






//=========================================================================================================================
bool NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(NPC** npcpp,int speed,int x,int y)
{//=========================================================================================================================

	if(npcpp==NULL){ERROR_set_error("NPC_walk_to_xy_intelligenthit_avoidothers_pushmain()");return 0;}
	if(*npcpp==NULL){ERROR_set_error("NPC_walk_to_xy_intelligenthit_avoidothers_pushmain()");return 0;}
	NPC* npc = *npcpp;

	if(PLAYER_npc==NULL){ERROR_set_error("NPC_walk_to_xy_intelligenthit_avoidothers_pushmain()");return 0;}


	npc->ignore_player=1;
	npc->walking_speed = speed;


	bool there_yet=0;
	int avoided=0;
	int facing_direction=0;
	int already_walked=0;


	if(x==-1)x=npc->MAP_x+npc->size_x/2;
	if(y==-1)y=npc->MAP_y+(npc->size_y-(npc->hitsize_y/2));

//if already there return 1, animate standing

	if(npc->MAP_x+npc->size_x/2==x&&npc->MAP_y+(npc->size_y-(npc->hitsize_y/2))==y)
	{
		there_yet=1;

		NPC_stand(npcpp);
	}

	else

	{

		if(npc->ms>npc->walking_speed)
		{

		//if time to walk

		//calc distance x and y
			int xdistance=(npc->MAP_x+npc->size_x/2)-x;
			int ydistance=((npc->MAP_y+npc->size_y)-npc->hitsize_y)-y;

			if(xdistance<0)xdistance*=-1;
			if(ydistance<0)ydistance*=-1;





		//find nearest npc
			NPC* nearestnpc = NPC_find_nearest_npc(npcpp);


			int npcx = (npc->MAP_x+(npc->size_x/2));
			int npcy = (npc->MAP_y+npc->size_y)-(npc->hitsize_y/2);

			int nearestx = (nearestnpc->MAP_x+(nearestnpc->size_x/2));
			int nearesty = (nearestnpc->MAP_y+nearestnpc->size_y)-(nearestnpc->hitsize_y/2);


			if(ydistance>=xdistance) //walk the greater distance first, up/down vs left/right
			{



				///walking down
				if(npcy<y)
				{



					if(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,10)==1)
					{



						if(nearestnpc==PLAYER_npc)
						{

							//push main sprite down
							if((npcy<nearesty)&&!PLAYER_check_hit_layer(DOWN)&&!PLAYER_check_hit_non_walkable_npcs(DOWN))PLAYER_npc->MAP_y++;

							if(npcx<nearestx)
							{//push main sprite right
								if(!PLAYER_check_hit_layer(RIGHT)&&!PLAYER_check_hit_non_walkable_npcs(RIGHT))PLAYER_npc->MAP_x++;
							}

							else

							{//push main sprite left
								if(!PLAYER_check_hit_layer(LEFT)&&!PLAYER_check_hit_non_walkable_npcs(LEFT))PLAYER_npc->MAP_x--;
							}

						}



						{

							avoided=r(2);
							if(npcx<=nearestx)
							{

								if(avoided==1)NPC_check_hit_move_pixel(npcpp,LEFT);
								already_walked=1;

							}
							else
							{

								if(avoided==1)NPC_check_hit_move_pixel(npcpp,RIGHT);
								already_walked=1;

							}
						}


						facing_direction=DOWN;

					}


					if(avoided==0)
					{
						if(NPC_check_hit_move_pixel(npcpp,DOWN)==0)
						{
							if(npc->walk_dir!=LEFT&&npc->walk_dir!=RIGHT)
							{
								if(npcx>=x)npc->walk_dir=LEFT;
								else npc->walk_dir=RIGHT;
							}
						}
						else
						{
							already_walked=1;
							facing_direction=DOWN;
						}
					}

				}


				avoided=0;

				///walking up
				if(npcy>y)
				{
					if(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,10)==1)
					{
						if(nearestnpc==PLAYER_npc)
						{
							//push main sprite up
							if((npcy>nearesty)&&!PLAYER_check_hit_layer(UP)&&!PLAYER_check_hit_non_walkable_npcs(UP))PLAYER_npc->MAP_y--;

							if(npcx<=nearestx)
							{//push main sprite right
								if(!PLAYER_check_hit_layer(RIGHT)&&!PLAYER_check_hit_non_walkable_npcs(RIGHT))PLAYER_npc->MAP_x++;
							}
							else
							{//push main sprite left
								if(!PLAYER_check_hit_layer(LEFT)&&!PLAYER_check_hit_non_walkable_npcs(LEFT))PLAYER_npc->MAP_x--;
							}
						}

						{
							avoided=r(2);

							if(npcx<nearestx)
							{
								if(avoided==1)NPC_check_hit_move_pixel(npcpp,LEFT); //else walk left if slightly left
								already_walked=1;
							}
							else
							{
								if(avoided==1)NPC_check_hit_move_pixel(npcpp,RIGHT);			//else walk right
								already_walked=1;
							}
						}
						facing_direction=UP;
					}

					if(avoided==0)
					{
						if(NPC_check_hit_move_pixel(npcpp,UP)==0)
						{
							if(npc->walk_dir!=LEFT&&npc->walk_dir!=RIGHT)
							{
								if(npcx>=x)npc->walk_dir=LEFT;
								else npc->walk_dir=RIGHT;
							}
						}
						else
						{
							already_walked=1;
							facing_direction=UP;
						}
					}
				}
				avoided=0;

			}






			//if walk right/left first
			if(xdistance>ydistance)
			{


				///walking right
				if(npcx<x)
				{
					if(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,10)==1)
					{
						if(nearestnpc==PLAYER_npc)
						{

							//push main sprite right
							if((npcx<nearestx)&&!PLAYER_check_hit_layer(RIGHT)&&!PLAYER_check_hit_non_walkable_npcs(RIGHT))PLAYER_npc->MAP_x++;

							if(npcy>nearesty)
							{//push main sprite up
								if(!PLAYER_check_hit_layer(UP)&&!PLAYER_check_hit_non_walkable_npcs(UP))PLAYER_npc->MAP_y--;
							}
							else
							{//push main sprite down
								if(!PLAYER_check_hit_layer(DOWN)&&!PLAYER_check_hit_non_walkable_npcs(DOWN))PLAYER_npc->MAP_y++;
							}
						}

						{

							avoided=r(2);

							if(npcy<=nearesty)
							{
								if(avoided==1)NPC_check_hit_move_pixel(npcpp,UP); //else walk up if slightly above
								already_walked=1;
							}
							else
							{
								if(avoided==1)NPC_check_hit_move_pixel(npcpp,DOWN);			//else walk down
								already_walked=1;
							}
						}
						facing_direction=RIGHT;
					}

					if(avoided==0)
					{
						if(NPC_check_hit_move_pixel(npcpp,RIGHT)==0)
						{
							if(npc->walk_dir!=UP&&npc->walk_dir!=DOWN)
							{
								if(npcy>=y)npc->walk_dir=UP;
								else npc->walk_dir=DOWN;
							}
						}
						else
						{
							already_walked=1;
							facing_direction=RIGHT;
						}
					}

				}



				avoided=0;


				///walking left
				if(npcx>x)
				{
					if(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,10)==1)
					{
						if(nearestnpc==PLAYER_npc)
						{
							//push main sprite left
							if((npcx>nearestx)&&!PLAYER_check_hit_layer(LEFT)&&!PLAYER_check_hit_non_walkable_npcs(LEFT))PLAYER_npc->MAP_x--;

							if(npcy>=nearesty)
							{//push main sprite up
								if(!PLAYER_check_hit_layer(UP)&&!PLAYER_check_hit_non_walkable_npcs(UP))PLAYER_npc->MAP_y--;
							}
							else
							{//push main sprite down
								if(!PLAYER_check_hit_layer(DOWN)&&!PLAYER_check_hit_non_walkable_npcs(DOWN))PLAYER_npc->MAP_y++;
							}
						}

						{
							avoided=r(2);
							if(npcy<nearesty)
							{
								if(avoided==1)NPC_check_hit_move_pixel(npcpp,UP); //else walk up if slightly above
								already_walked=1;
							}
							else
							{
								if(avoided==1)NPC_check_hit_move_pixel(npcpp,DOWN);			//else walk down
								already_walked=1;
							}
						}
						facing_direction=LEFT;
					}

					if(avoided==0)
					{
						if(NPC_check_hit_move_pixel(npcpp,LEFT)==0)
						{
							if(npc->walk_dir!=UP&&npc->walk_dir!=DOWN)
							{
								if(npcy>=y)npc->walk_dir=UP;
								else npc->walk_dir=DOWN;
							}
						}
						else
						{
							already_walked=1;
							facing_direction=LEFT;
						}
					}

				}
			}



			if(already_walked==0)
			{
				if(npc->walk_dir==UP){if(NPC_check_hit_move_pixel(npcpp,UP)==0||(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,10+r(6)==1)&&npcy>nearesty)){npc->walk_dir=4;}else facing_direction=UP;}
				else if(npc->walk_dir==DOWN){if(NPC_check_hit_move_pixel(npcpp,DOWN)==0||(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,10+r(6)==1)&&npcy<nearesty)){npc->walk_dir=4;}else facing_direction=DOWN;}
				else if(npc->walk_dir==LEFT){if(NPC_check_hit_move_pixel(npcpp,LEFT)==0||(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,10+r(6)==1)&&npcx>nearestx)){npc->walk_dir=4;}else facing_direction=LEFT;}
				else if(npc->walk_dir==RIGHT){if(NPC_check_hit_move_pixel(npcpp,RIGHT)==0||(NPC_in_range_of_npc_by_amount(npcpp,&nearestnpc,10+r(6)==1)&&npcx<nearestx)){npc->walk_dir=4;}else facing_direction=RIGHT;}
			}

			int d = (xdistance-ydistance);
			if(d<0)d*=-1;
			if(npc->anim_dir!=facing_direction&&GLOBAL_npc_all_animation_off==0&&npc->animation_off==0&&d>=8)
			{
				npc->anim_dir=facing_direction;NPC_animate_dir(npcpp,npc->anim_dir);
			}//animate change direction

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







