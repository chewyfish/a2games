#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <peekpoke.h>
#include <joystick.h>

#include "common.c"
#include "hgr.c"
#include "sound.c"
#include "sprite.h"
#include "text.c"

void init_screen();
void init_asteroids();
signed char find_closest_asteroid(unsigned short x, unsigned short y);
unsigned char explode_asteroid(unsigned char r_idx);
void update_scoreboard_time(unsigned char value);
void update_scoreboard_shields(unsigned char value);
void update_scoreboard_roids(unsigned char value);

// Game state
// - state_time: Amount of game time units remaining
// - state_shields: Amount of game shield units remaining
// - state_roids: Current number of active/rendered asteroids

unsigned char state_time = 40;
unsigned char state_shields = 20;
unsigned char state_roids = 0;

// Gameplay pane
// - GAMEPLAY_PANE_STARTX/Y: Left (X), Top (Y) starting offset for gameplay pane
// - GAMEPLAY_PANE_WIDTH/HEIGHT: Number of screen pixels for gameplay pane
// - GAMEPLAY_PANE_SIZE_NA: Unsupplied gameplay pane size

#define GAMEPLAY_PANE_STARTX 1
#define GAMEPLAY_PANE_STARTY 1
#define GAMEPLAY_PANE_WIDTH 229
#define GAMEPLAY_PANE_HEIGHT 190
#define GAMEPLAY_PANE_SIZE_NA 255

// Rendered asteroids
// - ROID_MOVECYCLETHRESH: How often (event loop cycle) to consider asteroid moving
// - ROID_MAXSTEPMOVES: Maximum number of asteroids to move in a event loop step
// - ROID_MAXRENDERED: Maximum number of rendered asteroids
// - ROID_NUMROTATIONS: Total number of rotations for a rendered asteroid
// - ROID_META_FIELD_*: Meta (array) structure field indices
// - ROID_POS_FIELD_*: Position (array) structure field indices
// - roid_meta: Contains various information for the rendered asteroids
// - roid_position: Contains screen position for the rendered asteroids

#define ROID_MOVECYCLETHRESH 12
#define ROID_MAXSTEPMOVES 1
#define ROID_MAXRENDERED 14
#define ROID_NUMROTATIONS 16
#define ROID_META_FIELD_TYPE 0
#define ROID_META_FIELD_SHAPENUM 1
#define ROID_META_FIELD_DIRECTION 2
#define ROID_META_FIELD_RIGHTMARGIN 3
#define ROID_META_FIELD_BOTTOMMARGIN 4
#define ROID_POS_FIELD_X 0
#define ROID_POS_FIELD_Y 1

unsigned char roid_meta[ROID_MAXRENDERED][5];
unsigned char roid_position[ROID_MAXRENDERED][2];

// Rendered weapon fire
// - BULLET_MAXRENDERED: Maximum number of rendered bullets
// - BULLET_META_FIELD_*: Meta (array) structure field indices
// - BULLET_POS_FIELD_*: Position (array) structure field indices

#define BULLET_MAXRENDERED 3
#define BULLET_META_FIELD_LIFETIME 0
#define BULLET_META_FIELD_DIRECTION 1
#define BULLET_POS_FIELD_X 0
#define BULLET_POS_FIELD_Y 1

// Scoreboard
// - SCOREBOARD_ICON_VALUE0/1_XPOS: The x-axis value for the tens and ones digits
// - SCOREBOARD_ICON_TIME_XPOS/YPOS: Position for the time icon
// - SCOREBOARD_ICON_TIME_VALUE_YPOS: The y-axis value for time value
// - SCOREBOARD_ICON_SHIELD_XPOS/YPOS: Position for the shields icon
// - SCOREBOARD_ICON_SHIELD_VALUE_YPOS: The y-axis value for the time value
// - SCOREBOARD_ICON_ROID_XPOS/YPOS: Position for the asteroids icon
// - SCOREBOARD_ICON_ROID_VALUE_YPOS: The y-axis value for the asteroids value
// - SCOREBOARD_VALUE_NA: Non-supplied scoreboard value
// - scoreboard_time[2]: Time value shown on scoreboard (stored as digits)
// - scoreboard_shields[2]: Shields value shown on scoreboard (stored as digits)
// - scoreboard_roids[2]: Asteroids value shown on scoreboard (stored as digits)

#define SCOREBOARD_ICON_VALUE0_XPOS 243
#define SCOREBOARD_ICON_VALUE1_XPOS 257
#define SCOREBOARD_ICON_TIME_XPOS 239
#define SCOREBOARD_ICON_TIME_YPOS 7
#define SCOREBOARD_ICON_TIME_VALUE_YPOS 47
#define SCOREBOARD_ICON_SHIELD_XPOS 239
#define SCOREBOARD_ICON_SHIELD_YPOS 69
#define SCOREBOARD_ICON_SHIELD_VALUE_YPOS 109
#define SCOREBOARD_ICON_ROID_XPOS 239
#define SCOREBOARD_ICON_ROID_YPOS 131
#define SCOREBOARD_ICON_ROID_VALUE_YPOS 171
#define SCOREBOARD_VALUE_NA 0xFF

unsigned char scoreboard_time[2] = { SCOREBOARD_VALUE_NA, SCOREBOARD_VALUE_NA };
unsigned char scoreboard_shields[2] = { SCOREBOARD_VALUE_NA, SCOREBOARD_VALUE_NA };
unsigned char scoreboard_roids[2] = { SCOREBOARD_VALUE_NA, SCOREBOARD_VALUE_NA };

// Misc
// - GAMEOVER_IMAGE_XPOS: The x-axis value for the game-over image
// - GAMEOVER_IMAGE_YPOS: The y-axis value for the game-over image
// - SHIPNOSE_STARTING_OFFSETX: (x-axis) Offset from ship sprite origin of the leading nose cone
// - SHIPNOSE_STARTING_OFFSETY: (y-axis) Offset from ship sprite origin of the leading nose cone

#define GAMEOVER_IMAGE_XPOS 78
#define GAMEOVER_IMAGE_YPOS 51

const unsigned char SHIPNOSE_STARTING_OFFSETX[16] = { 0x06, 0x0B, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0B, 0x07, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02 };
const unsigned char SHIPNOSE_STARTING_OFFSETY[16] = { 0x00, 0x00, 0x00, 0x02, 0x06, 0x0B, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0B, 0x06, 0x02, 0x00, 0x00 };

// Main program
//
////////////////////////////////////////////////////////////////////////////////
int main(void)
{
  unsigned char continue_game = 1, event_cycle = 0;
  unsigned char joystick_loaded, inpkey, inpjoy;
  signed short ship_lft_margin, ship_rgt_margin, ship_top_margin, ship_bot_margin;
  unsigned char ship_start_x, ship_start_y, ship_ox, ship_oy;
  unsigned char ship_x, ship_y;
  unsigned char ship_rot, ship_orot, ship_speed;
  unsigned char ship_check_coll = 0;

  signed short roid_lft_margin, roid_top_margin;
  unsigned char roid_move_cycle;

  signed short bullet_lft_margin, bullet_rgt_margin, bullet_top_margin, bullet_bot_margin;
  unsigned char bullet_next_idx, bullet_total_active;
  signed char bullet_meta[BULLET_MAXRENDERED][2];
  unsigned char bullet_position[BULLET_MAXRENDERED][2];

  ship_lft_margin = GAMEPLAY_PANE_STARTX + 1;
  ship_rgt_margin = GAMEPLAY_PANE_STARTX + (GAMEPLAY_PANE_WIDTH - SPRITE_SHIP_WIDTHPIXELS) - 2;
  ship_top_margin = GAMEPLAY_PANE_STARTY + 1;
  ship_bot_margin = GAMEPLAY_PANE_STARTY + (GAMEPLAY_PANE_HEIGHT - SPRITE_SHIP_HEIGHTPIXELS) - 2;
  ship_start_x = GAMEPLAY_PANE_STARTY + ((GAMEPLAY_PANE_WIDTH / 2) - (SPRITE_SHIP_WIDTHPIXELS / 2)) - 1;
  ship_start_y = GAMEPLAY_PANE_STARTY + ((GAMEPLAY_PANE_HEIGHT / 2) - (SPRITE_SHIP_HEIGHTPIXELS / 2)) - 1;

  roid_move_cycle = 0;
  roid_lft_margin = GAMEPLAY_PANE_STARTX + 1;
  roid_top_margin = GAMEPLAY_PANE_STARTY + 1;

  bullet_lft_margin = GAMEPLAY_PANE_STARTX + 1;
  bullet_rgt_margin = GAMEPLAY_PANE_STARTX + (GAMEPLAY_PANE_WIDTH - 1) - 2;
  bullet_top_margin = GAMEPLAY_PANE_STARTY + 1;;
  bullet_bot_margin = GAMEPLAY_PANE_STARTY + (GAMEPLAY_PANE_HEIGHT - 1) - 2;

  srand(PEEKW(0x004E));

  joystick_loaded = (joy_install(joy_static_stddrv) == JOY_ERR_OK);

  while (continue_game)
  {
    init_screen();

    ship_x = ship_start_x;
    ship_y = ship_start_y;
    ship_ox = ship_x;
    ship_oy = ship_y;
    ship_rot = 0;
    ship_orot = ship_rot;
    ship_speed = 0;

    bullet_next_idx = 0;
    bullet_total_active = 0;

    init_asteroids();

    hgr_xor_sprite(1, SPRITE_TYPE_SHIP, ship_rot, ship_x, ship_y);

    while (continue_game)
    {
      if (state_roids && (++event_cycle == 110))
      {
        event_cycle = 0;

        update_scoreboard_time(--state_time);

        if (state_time == 0)
        {
          continue_game = 0;
          continue;
        }
      }

      // Parse user input
      // - - - - - - - -

      inpkey = toupper(key_read());
      inpjoy = (joystick_loaded ? joy_read(JOY_1) : 0);

      if ((inpkey == 'F') || (JOY_UP(inpjoy))) // Speed increase
      {
        if (ship_speed < 3)
        {
          ++ship_speed;
          tone(10-(ship_speed*3), 10, 1);
        }
      }
      else if ((inpkey == 'V') || JOY_DOWN(inpjoy)) // Speed decrease
      {
        if (ship_speed > 0)
        {
          --ship_speed;
          tone(10-(ship_speed*3), 10, 1);
        }
      }
      else if ((inpkey == 'O') || JOY_LEFT(inpjoy)) // Rotate left
      {
        if (ship_rot == 0) { ship_rot = SPRITE_SHIP_MAXROTATION; }
        else { --ship_rot; }
      }
      else if ((inpkey == 'P') || JOY_RIGHT(inpjoy)) // Rotate right
      {
        if (ship_rot == SPRITE_SHIP_MAXROTATION) { ship_rot = 0; }
        else { ++ship_rot; }
      }
      else if ((inpkey == ' ') || JOY_BTN_1(inpjoy)) // Fire bullet
      {
        if (bullet_total_active < BULLET_MAXRENDERED)
        {
          bullet_meta[bullet_next_idx][BULLET_META_FIELD_LIFETIME] = 24;
          bullet_meta[bullet_next_idx][BULLET_META_FIELD_DIRECTION] = ship_rot;
          bullet_position[bullet_next_idx][BULLET_POS_FIELD_X] = ship_x + SHIPNOSE_STARTING_OFFSETX[ship_rot];
          bullet_position[bullet_next_idx][BULLET_POS_FIELD_Y] = ship_y + SHIPNOSE_STARTING_OFFSETY[ship_rot];
          ++bullet_total_active;

          if (++bullet_next_idx == BULLET_MAXRENDERED) { bullet_next_idx = 0; }

          tone(1, 30, 1);
        }
      }
      else if (inpkey == 'Q') // Quit game
      {
        continue_game = 0;
        break;
      }

      // Draw asteroids
      // - - - - - - -

      if (state_roids && (++roid_move_cycle == ROID_MOVECYCLETHRESH))
      {
        unsigned char r_maxmoves, r_moved;
        unsigned char r_idx0, r_idx1;
        unsigned char r_type, r_dir, r_speed;
        unsigned char r_nx, r_ox;
        signed short r_ny, r_oy;
        unsigned char r_x;
        unsigned char r_y;

        r_maxmoves = (state_roids < ROID_MAXSTEPMOVES) ? state_roids : ROID_MAXSTEPMOVES;
        roid_move_cycle = 0;

        for (
            r_idx0=0, r_idx1=(rand()%ROID_MAXRENDERED), r_moved=0;
            (r_idx0<ROID_MAXRENDERED) && (r_moved < r_maxmoves);
            ++r_idx0, ++r_idx1
            )
        {
          if (r_idx1 == ROID_MAXRENDERED) { r_idx1 = 0; }

          r_type = roid_meta[r_idx1][ROID_META_FIELD_TYPE];

          if (r_type == 0) { continue; } // Non-asteroid slot, skip

          // Determine speed (based on size)

          r_speed = rand() % 2;

          if (r_type == SPRITE_TYPE_ROID_SMALL) { r_speed += 1; }
          else if (r_type == SPRITE_TYPE_ROID_MEDIUM) { r_speed = 1; }

          if (r_speed == 0) { continue; }

          // Determine new asteroid position

          r_dir = roid_meta[r_idx1][ROID_META_FIELD_DIRECTION];
          r_ox = roid_position[r_idx1][ROID_POS_FIELD_X];
          r_oy = roid_position[r_idx1][ROID_POS_FIELD_Y];
          r_nx = ((signed short)r_ox) + (HGR_MOVEMENT_DELTAX[r_dir] * r_speed);
          r_ny = ((signed short)r_oy) + (HGR_MOVEMENT_DELTAY[r_dir] * r_speed);

          if (r_nx < roid_lft_margin) { r_x = roid_meta[r_idx1][ROID_META_FIELD_RIGHTMARGIN]; }
          else if (r_nx > roid_meta[r_idx1][ROID_META_FIELD_RIGHTMARGIN]) { r_x = roid_lft_margin; }
          else { r_x = r_nx; }

          if (r_ny < roid_top_margin) { r_y = roid_meta[r_idx1][ROID_META_FIELD_BOTTOMMARGIN]; }
          else if (r_ny > roid_meta[r_idx1][ROID_META_FIELD_BOTTOMMARGIN]) { r_y = roid_top_margin; }
          else { r_y = r_ny; }

          // Draw repositioned asteroid

          hgr_xor_sprite(1, r_type, roid_meta[r_idx1][ROID_META_FIELD_SHAPENUM], r_ox, r_oy); // Erase old position

          if (hgr_collision_sprite(1, r_type, roid_meta[r_idx1][ROID_META_FIELD_SHAPENUM], r_x, r_y)) // Check collision
          {
            ship_check_coll = 1;
          }

          hgr_xor_sprite(1, r_type, roid_meta[r_idx1][ROID_META_FIELD_SHAPENUM], r_x, r_y); // Draw new position

          roid_position[r_idx1][ROID_POS_FIELD_X] = r_x;
          roid_position[r_idx1][ROID_POS_FIELD_Y] = r_y;

          ++r_moved;
        }
      }

      // Draw weapon fire
      // - - - - - - - -

      if (bullet_total_active > 0)
      {
        unsigned char repeat_idx, b_idx;
        signed char erase_idx = 0;
        signed short b_ox[3] = { -1, -1, -1 };
        signed short b_oy[3] = { -1, -1, -1 };

        for (repeat_idx=0; repeat_idx<3; ++repeat_idx) // Repeat bullets' processing
        {
          for (b_idx=0; b_idx<BULLET_MAXRENDERED; ++b_idx) // Process (if active) each bullet
          {
            if (bullet_meta[b_idx][BULLET_META_FIELD_LIFETIME] > 0)
            {
              // Determine new bullet position

              unsigned char b_dir = bullet_meta[b_idx][BULLET_META_FIELD_DIRECTION];
              signed short b_nx = ((signed short)bullet_position[b_idx][BULLET_POS_FIELD_X]) + (HGR_MOVEMENT_DELTAX[b_dir] * 2);
              signed short b_ny = ((signed short)bullet_position[b_idx][BULLET_POS_FIELD_Y]) + (HGR_MOVEMENT_DELTAY[b_dir] * 2);
              unsigned char b_x, b_y;

              if (b_nx < bullet_lft_margin) { b_x = bullet_rgt_margin; }
              else if (b_nx > bullet_rgt_margin) { b_x = bullet_lft_margin; }
              else { b_x = b_nx; }

              if (b_ny < bullet_top_margin) { b_y = bullet_bot_margin; }
              else if (b_ny > bullet_bot_margin) { b_y = bullet_top_margin; }
              else { b_y = b_ny; }

              // Erase previous bullet

              erase_idx = (erase_idx + 1) % 3;
              if (b_ox[erase_idx] != -1)
              {
                hgr_xor_sprite(1, SPRITE_TYPE_BULLET, 0, b_ox[erase_idx], b_oy[erase_idx]);
              }

              // Process asteroid collision

              if (state_roids && hgr_collision_sprite(1, SPRITE_TYPE_BULLET, 0, b_x, b_y))
              {
                if (explode_asteroid(find_closest_asteroid(hgr_collision_colpixel, hgr_collision_rowpixel)))
                {
                  bullet_meta[b_idx][BULLET_META_FIELD_LIFETIME] = 0;
                  erase_idx = (erase_idx - 1) % 3;
                }
              }

              // Draw repositioned bullet

              else
              {
                hgr_xor_sprite(1, SPRITE_TYPE_BULLET, 0, b_x, b_y);

                b_ox[erase_idx] = b_x;
                b_oy[erase_idx] = b_y;
              }

              // Bullet lifetime exhausted

              if (--bullet_meta[b_idx][BULLET_META_FIELD_LIFETIME] <= 0)
              {
                bullet_next_idx = b_idx;
                --bullet_total_active;
              }

              // Else save bullet position

              else
              {
                bullet_position[b_idx][BULLET_POS_FIELD_X] = b_x;
                bullet_position[b_idx][BULLET_POS_FIELD_Y] = b_y;
              }
            }
          }
        }

        for (erase_idx=0; erase_idx<3; ++erase_idx)
        {
          if (b_ox[erase_idx] != -1)
          {
            hgr_xor_sprite(1, SPRITE_TYPE_BULLET, 0, b_ox[erase_idx], b_oy[erase_idx]);
          }
        }
      }

      // Draw ship
      // - - - - -

      {
        unsigned char ship_step_speed = ship_speed;
        unsigned char ship_step_rot = ship_rot;
        unsigned char ship_step_collnum = 0;

        while (1)
        {
          // Determine new ship position

          if (ship_step_speed != 0)
          {
            signed short ship_nx = ((signed short)ship_x) + (HGR_MOVEMENT_DELTAX[ship_step_rot] * ship_step_speed);
            signed short ship_ny = ((signed short)ship_y) + (HGR_MOVEMENT_DELTAY[ship_step_rot] * ship_step_speed);
      
            if (ship_nx < ship_lft_margin) { ship_x = ship_rgt_margin; }
            else if (ship_nx > ship_rgt_margin) { ship_x = ship_lft_margin; }
            else ship_x = ship_nx;

            if (ship_ny < ship_top_margin) { ship_y = ship_bot_margin; }
            else if (ship_ny > ship_bot_margin) { ship_y = ship_top_margin; }
            else ship_y = ship_ny;
          }

          // Ship drawing process

          if (ship_check_coll || (ship_x != ship_ox) || (ship_y != ship_oy) || (ship_step_rot != ship_orot))
          {
            // Erase previous ship

            if (ship_step_collnum == 0)
            {
              hgr_xor_sprite(1, SPRITE_TYPE_SHIP, ship_orot, ship_ox, ship_oy);
            }

            // Process ship collistion

            if (hgr_collision_sprite(1, SPRITE_TYPE_SHIP, ship_step_rot, ship_x, ship_y))
            {
              // Change speed, rotation (will repeat until no collistion detected)

              if (++ship_step_collnum == 1)
              {
                ship_step_speed = 1;
              }

              update_scoreboard_shields(--state_shields);
              tone(3, 50, 1);

              if (state_shields == 0)
              {
                continue_game = 0;
                break;
              }

              ship_x = ship_ox;
              ship_y = ship_oy;
              ship_step_rot = ship_rot = (ship_step_rot + 1) % (SPRITE_SHIP_MAXROTATION + 1);

              continue;
            }

            // Draw repositioned ship

            hgr_xor_sprite(1, SPRITE_TYPE_SHIP, ship_step_rot, ship_x, ship_y);
            ship_ox = ship_x;
            ship_oy = ship_y;
            ship_orot = ship_step_rot;
          }

          ship_check_coll = 0;

          break;
        }
      }
    }
  }

  // Display game-over splash image, emit sound

  wait(10);

  hgr_draw_sprite(1, SPRITE_TYPE_GAMEOVER, 0, GAMEOVER_IMAGE_XPOS, GAMEOVER_IMAGE_YPOS);

  if (state_roids) // User lost
  {
    unsigned char period = 60;
    for (; period<=100; period+=5) { tone(period, 50, 1); }
  }
  else // User won
  {
    signed char repeat_idx = 4, duration;
    for (; repeat_idx>=0; --repeat_idx)
    {
      signed char duration_delta = (repeat_idx * 4);
      for (duration=16+duration_delta; duration>=duration_delta; duration-=1) { tone(1, duration, 1); }
      wait(5);
    }
  }

  cgetc();

 // Exit game

  if (joystick_loaded) { joy_uninstall(); }

  text_init_page();

  return EXIT_SUCCESS;
}

// Setup screen panes
//
void init_screen()
{
  hgr_init_page(1);

  // Draw pane dividers

  hgr_xor_vline(1, (GAMEPLAY_PANE_STARTX + GAMEPLAY_PANE_WIDTH), 0, (HGR_FULLPAGE_HEIGHT - 1));
  hgr_xor_vline(1, (GAMEPLAY_PANE_STARTX + GAMEPLAY_PANE_WIDTH + 2), 0, (HGR_FULLPAGE_HEIGHT - 1));
  hgr_xor_vline(1, (GAMEPLAY_PANE_STARTX - 1), (GAMEPLAY_PANE_STARTY - 1), (GAMEPLAY_PANE_STARTY + GAMEPLAY_PANE_HEIGHT));
  hgr_xor_hline(1, (GAMEPLAY_PANE_STARTY - 1), (GAMEPLAY_PANE_STARTX - 1), (GAMEPLAY_PANE_STARTX + GAMEPLAY_PANE_WIDTH));
  hgr_xor_hline(1, (GAMEPLAY_PANE_STARTY + GAMEPLAY_PANE_HEIGHT), (GAMEPLAY_PANE_STARTX - 1), GAMEPLAY_PANE_WIDTH);

  // Draw scoreboard

  hgr_xor_sprite(1, SPRITE_TYPE_ICON, SPRITE_ICON_SHAPEIDX_TIME, SCOREBOARD_ICON_TIME_XPOS, SCOREBOARD_ICON_TIME_YPOS);
  hgr_xor_sprite(1, SPRITE_TYPE_ICON, SPRITE_ICON_SHAPEIDX_SHIELD, SCOREBOARD_ICON_SHIELD_XPOS, SCOREBOARD_ICON_SHIELD_YPOS);
  hgr_xor_sprite(1, SPRITE_TYPE_ICON, SPRITE_ICON_SHAPEIDX_ASTEROID, SCOREBOARD_ICON_ROID_XPOS, SCOREBOARD_ICON_ROID_YPOS);

  update_scoreboard_time(state_time);
  update_scoreboard_shields(state_shields);
}

// Draw newly created asteroid on screen
//
////////////////////////////////////////////////////////////////////////////////
void draw_new_asteroid(
    unsigned char r_type,
    unsigned char r_shape,
    unsigned char r_dir,
    unsigned char r_x,
    unsigned char r_y,
    unsigned char p_xoff,
    unsigned char p_yoff,
    unsigned char p_width,
    unsigned char p_height)
{
  unsigned char r_idx = 0;
  unsigned char r_width, r_height;

  for (; r_idx<ROID_MAXRENDERED; ++r_idx) {

    if (roid_meta[r_idx][ROID_META_FIELD_TYPE] != 0) { continue; } // Finding next available slot

    if (r_type == SPRITE_TYPE_ROID_SMALL)
    {
      r_width = SPRITE_ROID_SMALL_WIDTHPIXELS;
      r_height = SPRITE_ROID_SMALL_HEIGHTPIXELS;
    }
    else if (r_type == SPRITE_TYPE_ROID_MEDIUM)
    {
      r_width = SPRITE_ROID_MEDIUM_WIDTHPIXELS;
      r_height = SPRITE_ROID_MEDIUM_HEIGHTPIXELS;
    }
    else
    {
      r_width = SPRITE_ROID_LARGE_WIDTHPIXELS;
      r_height = SPRITE_ROID_LARGE_HEIGHTPIXELS;
    }

    // Determine default position (if not supplied)

    if (r_x == GAMEPLAY_PANE_SIZE_NA) { r_x = ((rand() % ((p_width-10) - r_width)) + p_xoff + 5); }
    if (r_y == GAMEPLAY_PANE_SIZE_NA) { r_y = ((rand() % ((p_height-10) - r_height)) + p_yoff + 5); }

    // Setup/draw new asteroid

    roid_position[r_idx][ROID_POS_FIELD_X] = r_x;
    roid_position[r_idx][ROID_POS_FIELD_Y] = r_y;
    roid_meta[r_idx][ROID_META_FIELD_TYPE] = r_type;
    roid_meta[r_idx][ROID_META_FIELD_SHAPENUM] = r_shape;
    roid_meta[r_idx][ROID_META_FIELD_DIRECTION] = r_dir;
    roid_meta[r_idx][ROID_META_FIELD_RIGHTMARGIN] = GAMEPLAY_PANE_STARTX + (GAMEPLAY_PANE_WIDTH - r_width) - 2;
    roid_meta[r_idx][ROID_META_FIELD_BOTTOMMARGIN] = GAMEPLAY_PANE_STARTY + (GAMEPLAY_PANE_HEIGHT - r_height) - 2;

    hgr_xor_sprite(1, r_type, r_shape, r_x, r_y);

    update_scoreboard_roids(++state_roids);

    break;
  }
}

// Setup initial asteroids on screen
//
////////////////////////////////////////////////////////////////////////////////
void init_asteroids()
{
  const unsigned char tot_rendered = 6;
  const unsigned char roid_types[6] = {
    SPRITE_TYPE_ROID_LARGE, SPRITE_TYPE_ROID_SMALL, SPRITE_TYPE_ROID_MEDIUM,
    SPRITE_TYPE_ROID_SMALL, SPRITE_TYPE_ROID_MEDIUM, SPRITE_TYPE_ROID_LARGE
  };
  const unsigned char roid_shapes[6] = { 0, 0, 0, 1, 1, 0 };

  unsigned char row, col;
  unsigned char r_idx = 0;

  for (row=0; row<2; ++row)
  {
    for (col=0; col<3 && (r_idx < tot_rendered); ++col)
    {
      draw_new_asteroid(
          roid_types[r_idx], roid_shapes[r_idx],
          (rand() % ROID_NUMROTATIONS),
          GAMEPLAY_PANE_SIZE_NA, GAMEPLAY_PANE_SIZE_NA,
          (col * 70), (row * 95), 70, 95);

      ++r_idx;
    }
  }

  for (r_idx=tot_rendered; r_idx<ROID_MAXRENDERED; ++r_idx) {
    roid_meta[r_idx][ROID_META_FIELD_TYPE] = 0;
  }
}

// Find closest asteroid to given position
//
////////////////////////////////////////////////////////////////////////////////
signed char find_closest_asteroid(unsigned short x, unsigned short y)
{
  unsigned char r_idx, r_idx_closest=ROID_MAXRENDERED;
  unsigned short r_delta, r_delta_closest=GAMEPLAY_PANE_WIDTH+GAMEPLAY_PANE_HEIGHT+10;

  for (r_idx=0; r_idx<ROID_MAXRENDERED; ++r_idx)
  {
    if (roid_meta[r_idx][ROID_META_FIELD_TYPE] == 0) { continue; }

    r_delta = abs(roid_position[r_idx][ROID_POS_FIELD_X] - x) + abs(roid_position[r_idx][ROID_POS_FIELD_Y] - y);

    if (r_delta < r_delta_closest) {
      r_idx_closest = r_idx;
      r_delta_closest = r_delta;
    }
  }

  return r_idx_closest;
}

// Explode given asteroid
//
////////////////////////////////////////////////////////////////////////////////
unsigned char explode_asteroid(unsigned char r_idx)
{
  unsigned char r_type, r_shape;
  unsigned char r_x, r_y;

  if (r_idx >= ROID_MAXRENDERED) { return 0; }

  r_type = roid_meta[r_idx][ROID_META_FIELD_TYPE];
  r_shape = roid_meta[r_idx][ROID_META_FIELD_SHAPENUM];
  r_x = roid_position[r_idx][ROID_POS_FIELD_X];
  r_y = roid_position[r_idx][ROID_POS_FIELD_Y];

  tone(30, 60, 1);

  // Erase asteroid

  hgr_xor_sprite(1, r_type, r_shape, r_x, r_y);
  roid_meta[r_idx][ROID_META_FIELD_TYPE] = 0;
  update_scoreboard_roids(--state_roids);

  // Replace with 2 next-smaller asteroids (if approp)

  if (r_type == SPRITE_TYPE_ROID_LARGE)
  {
    unsigned char r_dir = (rand() % ROID_NUMROTATIONS);
    draw_new_asteroid(
        SPRITE_TYPE_ROID_MEDIUM, 0, r_dir,
        r_x, r_y,
        GAMEPLAY_PANE_SIZE_NA, GAMEPLAY_PANE_SIZE_NA, GAMEPLAY_PANE_SIZE_NA, GAMEPLAY_PANE_SIZE_NA);
    draw_new_asteroid(
        SPRITE_TYPE_ROID_MEDIUM, 1,
        ((r_dir + ROID_NUMROTATIONS/2) % ROID_NUMROTATIONS),
        (r_x+(SPRITE_ROID_LARGE_WIDTHPIXELS - SPRITE_ROID_MEDIUM_WIDTHPIXELS)),
        (r_x+(SPRITE_ROID_LARGE_HEIGHTPIXELS - SPRITE_ROID_MEDIUM_HEIGHTPIXELS)),
        GAMEPLAY_PANE_SIZE_NA, GAMEPLAY_PANE_SIZE_NA, GAMEPLAY_PANE_SIZE_NA, GAMEPLAY_PANE_SIZE_NA);
  }
  else if (r_type == SPRITE_TYPE_ROID_MEDIUM)
  {
    unsigned char r_dir = (rand() % ROID_NUMROTATIONS);
    draw_new_asteroid(
        SPRITE_TYPE_ROID_SMALL, 0, r_dir,
        r_x, r_y,
        GAMEPLAY_PANE_SIZE_NA, GAMEPLAY_PANE_SIZE_NA, GAMEPLAY_PANE_SIZE_NA, GAMEPLAY_PANE_SIZE_NA);
    draw_new_asteroid(
        SPRITE_TYPE_ROID_SMALL, 1,
        ((r_dir + ROID_NUMROTATIONS/2) % ROID_NUMROTATIONS),
        (r_x+(SPRITE_ROID_MEDIUM_WIDTHPIXELS - SPRITE_ROID_SMALL_WIDTHPIXELS)),
        (r_x+(SPRITE_ROID_MEDIUM_HEIGHTPIXELS - SPRITE_ROID_SMALL_HEIGHTPIXELS)),
        GAMEPLAY_PANE_SIZE_NA, GAMEPLAY_PANE_SIZE_NA, GAMEPLAY_PANE_SIZE_NA, GAMEPLAY_PANE_SIZE_NA);
  }

  return 1;
}

// Update scoreboard value
//
////////////////////////////////////////////////////////////////////////////////
void update_scoreboard_value(unsigned char *scoreboard, unsigned char value, unsigned char ypos)
{
  unsigned char tens = (value / 10);
  unsigned char ones = (value - (tens * 10));

  if (tens != scoreboard[0])
  {
    if (scoreboard[0] != SCOREBOARD_VALUE_NA)
    {
      hgr_xor_sprite(1, SPRITE_TYPE_CHAR, scoreboard[0], SCOREBOARD_ICON_VALUE0_XPOS, ypos);
    }
    hgr_xor_sprite(1, SPRITE_TYPE_CHAR, tens, SCOREBOARD_ICON_VALUE0_XPOS, ypos);
    scoreboard[0] = tens;
  }
  if (ones != scoreboard[1])
  {
    if (scoreboard[1] != SCOREBOARD_VALUE_NA)
    {
      hgr_xor_sprite(1, SPRITE_TYPE_CHAR, scoreboard[1], SCOREBOARD_ICON_VALUE1_XPOS, ypos);
    }
    hgr_xor_sprite(1, SPRITE_TYPE_CHAR, ones, SCOREBOARD_ICON_VALUE1_XPOS, ypos);
    scoreboard[1] = ones;
  }
}

// Update scoreboard time
//
////////////////////////////////////////////////////////////////////////////////
void update_scoreboard_time(unsigned char value)
{
  update_scoreboard_value((unsigned char*)scoreboard_time, value, SCOREBOARD_ICON_TIME_VALUE_YPOS);
}

// Update scoreboard shields
//
////////////////////////////////////////////////////////////////////////////////
void update_scoreboard_shields(unsigned char value)
{
  update_scoreboard_value((unsigned char*)scoreboard_shields, value, SCOREBOARD_ICON_SHIELD_VALUE_YPOS);
}

// Update scoreboard asteroids
//
////////////////////////////////////////////////////////////////////////////////
void update_scoreboard_roids(unsigned char value)
{
  update_scoreboard_value((unsigned char*)scoreboard_roids, value, SCOREBOARD_ICON_ROID_VALUE_YPOS);
}
