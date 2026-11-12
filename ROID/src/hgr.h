#ifndef __HGR_H__
#define __HGR_H__ 1

// Hires page
// - HGR_FULLPAGE_WIDTH/HEIGHT: Number of screen pixels

#define HGR_FULLPAGE_WIDTH 280
#define HGR_FULLPAGE_HEIGHT 192

// Hires page 1 screen
// - HGR_PAGE1_BASEADDR: Base address for page 1

#define HGR_PAGE1_BASEADDR 0x2000

// Hires page 2 screen
// - HGR_PAGE2_BASEADDR: Base address for page 2

#define HGR_PAGE2_BASEADDR 0x4000

// Drawing collision (from last collision-check drawing operation)
// - hgr_collision_rowpixel: Row pixel where collision took place
// - hgr_collision_colpixel: (Approximate) Column pixel where collision took place
unsigned short hgr_collision_rowpixel;
unsigned short hgr_collision_colpixel;

// Misc
// - HGR_MOVEMENT_DELTAX - (Unit) Amount of x-axis change based on rotation (0-15)
// - HGR_MOVEMENT_DELTAY - (Unit) Amount of y-axis change based on rotation (0-15)
//
const signed char HGR_MOVEMENT_DELTAX[16] = {  0,  1,  1,  2,  2,  2,  1,  1,  0, -1, -1, -2, -2, -2, -1, -1 };
const signed char HGR_MOVEMENT_DELTAY[16] = { -2, -2, -1, -1,  0,  1,  1,  2,  2,  2,  1,  1,  0, -1, -1, -2 };

#endif // __HGR_H__
