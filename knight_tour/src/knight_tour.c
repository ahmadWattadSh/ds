
#include <assert.h> /*assert*/

#include "knight_tour.h"
#include <stdio.h>



/**************************** Global variables ********************************/

enum {FALSE = 0, TRUE =1};
enum {NUM_OF_DIRECTIONS = 8, BOARD_WIDTH = 8, PLACES_OF_BOARD = 64};
typedef unsigned long bit_array_ty;

/************************** Forward Declarations ******************************/

/*recursive function that does the knight tour*/
static int IsGoodStep(bit_array_ty bit_array, pos_ty pos_, pos_ty *path);

/*checks if the position is out of board*/
static int IsOutOfBoard(pos_ty pos_);

/*calculate position x,y into an index number*/
static int CalculatePosition(pos_ty pos_);

/*check if it is already visited*/
static int HasVisited(bit_array_ty bit_array, int place_on_board_);

/*Mark On the board*/
static void MarkOnBoard(bit_array_ty *bit_array, int place_on_board);

/*find out if this is the last step for the tour*/
static int IsLastStep(bit_array_ty bit_array);

/*calculates next move*/
static pos_ty StepImp(pos_ty pos_, size_t direction_);
/******************************************************************************/
/******************************* API Funcs ************************************/
/******************************************************************************/


/*, time_t max_wait_*/
/*status*/
int IsKnightAble(int x_, int y_, pos_ty path_[64])
{
	/*need bit array*/
	size_t bit_array = 0;
	pos_ty pos = {0};
	
	assert(NULL != path_);
	/*assert(legal x and y);*/
	
	pos.x = x_;
	pos.y = y_;

	/*recursive for checking if the next step is a good one*/
	return IsGoodStep(bit_array, pos, path_); /*now +max_wait*/
}

/*status*/
static int IsGoodStep(bit_array_ty bit_array, pos_ty pos_, pos_ty *path)
{
	size_t i = 0; 
	pos_ty next_pos = {0};
	size_t place_on_board = 0;
	
	/*if (deadline passed) timeout, return failure*/

	/*if out of board*/
		/*return false*/	
	if(0 != IsOutOfBoard(pos_))
	{
		return FALSE;
	}	
	
	place_on_board = CalculatePosition(pos_);

	/*if been here*/
		/*return false*/
	if(HasVisited(bit_array, place_on_board))
	{
		return FALSE;
	}

	/*record this step in the bit array*//*using set bit on*/
	MarkOnBoard(&bit_array, place_on_board);

	/*if last step*/
		/*put step on path*/
		/*return true*/	
	if(IsLastStep(bit_array))
	{
		*path = pos_;
		return TRUE;	
	}

	/*for each direction*/
	for(i = 0; i < NUM_OF_DIRECTIONS ; ++i)
	{
		/*calc next step in direction*/
		next_pos = StepImp(pos_, i);
		
		/*if IsGoodStep(...path+1)*/
		if(IsGoodStep(bit_array, next_pos, path + 1))
		{
			/*put step on path*/
			*path= pos_;
			/*return true*/	
			return TRUE;
		}

	}	
			
	/*return false*/
	return FALSE;		
}




static int IsOutOfBoard(pos_ty pos_)
{	
	if(0 > pos_.x || 0 > pos_.y || BOARD_WIDTH <= pos_.x || BOARD_WIDTH <= pos_.y)
	{
		return TRUE; /*false*/
	}
	
	return FALSE;
}

static int CalculatePosition(pos_ty pos_)
{
	/*assert on board*/
	return pos_.x  + (pos_.y) *8;
}

static int HasVisited(bit_array_ty bit_array, int place_on_board_)
{
	bit_array_ty mask = 1;

	assert(place_on_board_<64 && place_on_board_>= 0);
		
	return !!((mask << place_on_board_) & bit_array);	
}

static void MarkOnBoard(bit_array_ty *bit_array, int place_on_board_)
{
	bit_array_ty mask = (bit_array_ty)1 << place_on_board_;
	*bit_array |= mask;
}

static int IsLastStep(bit_array_ty bit_array)
{
	return !(~bit_array);
}

static pos_ty StepImp(pos_ty pos_, size_t direction_)
{
	static const pos_ty offsets[8] = {{2,1}, {1,2}, {-1,2}, {-2,1},
		 {-2,-1}, {-1,-2}, {1,-2}, {2,-1}};

	/*assert direction*/
	assert(direction_ < 8);
	/*assert pos_*/
	assert(pos_.x >= 0 && pos_.y >= 0 && pos_.x < 8 && pos_.y < 8);
	
	pos_.x += offsets[direction_].x;
	pos_.y += offsets[direction_].y;

	return pos_;
}



/******************************** SET ALL *************************************/



