/*Name: HRD 32
  Project: Bit Array Functions Implementation
  Reviewer: Liel
  Date: 07/08/2023
  Version: 1.0
*/
/******************************************************************************/

#ifndef __KNIGHT_TOUR_H__
#define __KNIGHT_TOUR_H__

#include <stddef.h> /*size_t*/

typedef struct pos
{
	int x;
	int y;
}pos_ty;



int IsKnightAble(int x_, int y_, pos_ty path_[64]);

/******************************************************************************/
#endif /*(__KNIGHT_TOUR_H__)*/

