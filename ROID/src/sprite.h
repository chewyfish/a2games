#ifndef __SPRITE_H__
#define __SPRITE_H__ 1

// Sprite
// - SPRITE_TYPE_SHIP: Key used to specify spaceship sprites
// - SPRITE_TYPE_BULLET: Key used to specify bullet sprite
// - SPRITE_TYPE_ROID_SMALL: Key used to specify (small) asteroid sprites
// - SPRITE_TYPE_ROID_MEDIUM: Key used to specify (medium) asteroid sprites
// - SPRITE_TYPE_ROID_LARGE: Key used to specify (large) asteroid sprites
// - SPRITE_TYPE_ICON: Key used to specify icon sprites
// - SPRITE_TYPE_CHAR: Key used to specify character sprites
// - SPRITE_TYPE_GAMEOVER: Key used to specify game-over sprites

#define SPRITE_TYPE_SHIP 1
#define SPRITE_TYPE_BULLET 2
#define SPRITE_TYPE_ROID_SMALL 3
#define SPRITE_TYPE_ROID_MEDIUM 4
#define SPRITE_TYPE_ROID_LARGE 5
#define SPRITE_TYPE_ICON 6
#define SPRITE_TYPE_CHAR 7
#define SPRITE_TYPE_GAMEOVER 8

// Spaceship sprites
// - SPRITE_SHIP_WIDTHBYTES: Number of bytes used per bitmap row
// - SPRITE_SHIP_WIDTHPIXELS: Number of (x-axis) pixels of bitmap
// - SPRITE_SHIP_HEIGHTPIXELS: Number of (y-axis) pixels of bitmap
// - SPRITE_SHIP_NUMSHAPES: Number of distinct images (distinct ship rotations)
// - SPRITE_SHIP_NUMBITMAPSHIFTS: Number of shifted bitmaps per specific image
// - SPRITE_SHIP_NUMBITMAPBYTES: Number of bytes per specific image (SPRITE_SHIP_HEIGHTPIXELS*SPRITE_SHIP_WIDTHBYTES)
// - SPRITE_SHIP_MAXROTATION: Maximum ship rotation values (same as SPRITE_SHIP_NUMSHAPES - 1)

#define SPRITE_SHIP_WIDTHBYTES 0x3
#define SPRITE_SHIP_WIDTHPIXELS 0xE
#define SPRITE_SHIP_HEIGHTPIXELS 0xE
#define SPRITE_SHIP_NUMSHAPES 0x10
#define SPRITE_SHIP_NUMBITMAPSHIFTS 0x7
#define SPRITE_SHIP_NUMBITMAPBYTES 0x2A
#define SPRITE_SHIP_MAXROTATION 0xF

// Bullet sprite
// - SPRITE_BULLET_WIDTHBYTES: Number of bytes used per bitmap row
// - SPRITE_BULLET_WIDTHPIXELS: Number of (x-axis) pixels of bitmap
// - SPRITE_BULLET_HEIGHTPIXELS: Number of (y-axis) pixels of bitmap
// - SPRITE_BULLET_NUMBITMAPSHIFTS: Number of shifted bitmaps per specific image
// - SPRITE_BULLET_NUMBITMAPBYTES: Number of bytes per specific image (SPRITE_BULLET_HEIGHTPIXELS*SPRITE_BULLET_WIDTHBYTES)

#define SPRITE_BULLET_WIDTHBYTES 0x1
#define SPRITE_BULLET_WIDTHPIXELS 0x1
#define SPRITE_BULLET_HEIGHTPIXELS 0x1
#define SPRITE_BULLET_NUMBITMAPSHIFTS 0x7
#define SPRITE_BULLET_NUMBITMAPBYTES 0x7

// Asteroid sprites
// - SPRITE_ROID_NUMBITMAPSHIFTS: Number of shifted bitmaps per specific image
// - SPRITE_ROID_S/M/L_NUMSHAPES: Number of distinct images (distinct asteroid shapes)
// - SPRITE_ROID_S/M/L_WIDTHBYTES: Number of bytes used per bitmap row
// - SPRITE_ROID_S/M/L_WIDTHPIXELS: Number of (x-axis) pixels of bitmap
// - SPRITE_ROID_S/M/L_HEIGHTPIXELS: Number of (y-axis) pixels of bitmap
// - SPRITE_ROID_S/M/L_NUMBITMAPBYTES: Number of bytes per specific image (SPRITE_ROID_HEIGHTPIXELS*SPRITE_ROID_WIDTHBYTES)

#define SPRITE_ROID_NUMBITMAPSHIFTS 0x7
#define SPRITE_ROID_SMALL_NUMSHAPES 0x2
#define SPRITE_ROID_SMALL_WIDTHBYTES 0x4
#define SPRITE_ROID_SMALL_WIDTHPIXELS 0x16
#define SPRITE_ROID_SMALL_HEIGHTPIXELS 0x16
#define SPRITE_ROID_SMALL_NUMBITMAPBYTES 0x58
#define SPRITE_ROID_MEDIUM_NUMSHAPES 0x2
#define SPRITE_ROID_MEDIUM_WIDTHBYTES 0x5
#define SPRITE_ROID_MEDIUM_WIDTHPIXELS 0x21
#define SPRITE_ROID_MEDIUM_HEIGHTPIXELS 0x21
#define SPRITE_ROID_MEDIUM_NUMBITMAPBYTES 0xA5
#define SPRITE_ROID_LARGE_NUMSHAPES 0x1
#define SPRITE_ROID_LARGE_WIDTHBYTES 0x7
#define SPRITE_ROID_LARGE_WIDTHPIXELS 0x2C
#define SPRITE_ROID_LARGE_HEIGHTPIXELS 0x2C
#define SPRITE_ROID_LARGE_NUMBITMAPBYTES 0x134

// Icon sprites
// - SPRITE_ICON_NUMBITMAPSHIFTS: Number of shifted bitmaps per specific image
// - SPRITE_ICON_NUMSHAPES: Number of distinct images (distinct icons)
// - SPRITE_ICON_WIDTHBYTES: Number of bytes used per bitmap row
// - SPRITE_ICON_WIDTHPIXELS: Number of (x-axis) pixels of bitmap
// - SPRITE_ICON_HEIGHTPIXELS: Number of (y-axis) pixels of bitmap
// - SPRITE_ICON_NUMBITMAPBYTES: Number of bytes per specific image (SPRITE_ICON_HEIGHTPIXELS*SPRITE_ICON_WIDTHBYTES)
// - SPRITE_ICON_SHAPEIDX_TIME: Shape index for time icon
// - SPRITE_ICON_SHAPEIDX_SHIELD: Shape index for shield icon
// - SPRITE_ICON_SHAPEIDX_ASTEROID: Shape index for asteroid icon

#define SPRITE_ICON_NUMBITMAPSHIFTS 0x1
#define SPRITE_ICON_NUMSHAPES 0x3
#define SPRITE_ICON_WIDTHBYTES 0x6
#define SPRITE_ICON_WIDTHPIXELS 0x23
#define SPRITE_ICON_HEIGHTPIXELS 0x23
#define SPRITE_ICON_NUMBITMAPBYTES 0xD2
#define SPRITE_ICON_SHAPEIDX_TIME 0x00
#define SPRITE_ICON_SHAPEIDX_SHIELD 0x01
#define SPRITE_ICON_SHAPEIDX_ASTEROID 0x02

// Character sprites
// - SPRITE_CHAR_NUMBITMAPSHIFTS: Number of shifted bitmaps per specific image
// - SPRITE_CHAR_NUMSHAPES: Number of distinct images (distinct chars)
// - SPRITE_CHAR_WIDTHBYTES: Number of bytes used per bitmap row
// - SPRITE_CHAR_WIDTHPIXELS: Number of (x-axis) pixels of bitmap
// - SPRITE_CHAR_HEIGHTPIXELS: Number of (y-axis) pixels of bitmap
// - SPRITE_CHAR_NUMBITMAPBYTES: Number of bytes per specific image (SPRITE_CHAR_HEIGHTPIXELS*SPRITE_CHAR_WIDTHBYTES)

#define SPRITE_CHAR_NUMBITMAPSHIFTS 0x1
#define SPRITE_CHAR_NUMSHAPES 0xA
#define SPRITE_CHAR_WIDTHBYTES 0x3
#define SPRITE_CHAR_WIDTHPIXELS 0x0E
#define SPRITE_CHAR_HEIGHTPIXELS 0x0F
#define SPRITE_CHAR_NUMBITMAPBYTES 0x2D

// Game-over sprites
// - SPRITE_GAMEOVER_NUMBITMAPSHIFTS: Number of shifted bitmaps per specific image
// - SPRITE_GAMEOVER_NUMSHAPES: Number of distinct images
// - SPRITE_GAMEOVER_WIDTHBYTES: Number of bytes used per bitmap row (game-over image)
// - SPRITE_GAMEOVER_WIDTHPIXELS: Number of (x-axis) pixels of bitmap (game-over image)
// - SPRITE_GAMEOVER_HEIGHTPIXELS: Number of (y-axis) pixels of bitmap (game-over image)
// - SPRITE_GAMEOVER_NUMBITMAPBYTES: Number of bytes per specific image  (game-over image)

#define SPRITE_GAMEOVER_NUMBITMAPSHIFTS 0x1
#define SPRITE_GAMEOVER_NUMSHAPES 0x1
#define SPRITE_GAMEOVER_WIDTHBYTES 0x0B
#define SPRITE_GAMEOVER_WIDTHPIXELS 0x4B
#define SPRITE_GAMEOVER_HEIGHTPIXELS 0x5A
#define SPRITE_GAMEOVER_NUMBITMAPBYTES 0x3DE

#endif // __SPRITE_H__
