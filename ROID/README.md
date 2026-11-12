[A2Games Home](../README.md)

<table>
<tr>
<td style="margin:0 15px 15px 0"><img src="https://raw.githubusercontent.com/chewyfish/project-assets/main/a2games/ROID-logo.png" width="130" alt="ROID"></td>
<td>
<h1>ROID - An Apple ][ Asteroids clone</h1>
<b>Note</b> Not a serious project, used as a playground for Apple ][ development.
</td>
</tr>
</table>

## Requirements

### Building

* sh-compatible shell (conforming to the POSIX standard)
* cl65 (MOS 6502 compiler/linker)
* GNU make
* Java (25+)
* Perl
* Python

### Running

* Apple ][ with disk drive (*)
* Apple DOS 3.3 Master

(*) - Emulator or native machine. This was tested natively on an Apple ][+ 64K. Using the microm8 emulator, it was tested on an Apple ][ + (48K and 64K), ][e and ][gs.

## Building

If you wish to merely run the game, skip this section and refer to "Running" below.

To build program:

`make cleanall all`

To install program in disk

`make install`

## Running

Boot up computer with Apple DOS 3.3. Insert disk (`a2games-roid.dsk`) with ROID installed into disk drive. Run the main game driver program.

`RUN ROID`

## Gameplay

The objective is to destroy all the asteroids. You have a ship, which can fly around space and fire missles at the asteroids. The game ends when you have either: ran out of time; been blown up crashing into asteroids too many times, or; destroyed all the asteroids.

### Controls

The keyboard or the joystick may be used to play the game.

| Control | Description |
| ------- | ----------- |
| JOY_UP or 'f' | Increase ship speed |
| JOY_DOWN or 'v' | Decrease ship speed |
| JOY_LEFT or 'o' | Rotate ship left |
| JOY_RIGHT or 'p' | Rotate ship right |
| JOY_BUTTON or '&lt;space&gt;' | Fire ship missle |
| 'q' | Quit game |

### Scoreboard

A scoreboard is shown on the screen. It shows:

* Time units left
* Shield (defensive) level
* Remaining asteroids count

### Screenshot

![ROID screenshot](https://raw.githubusercontent.com/chewyfish/project-assets/main/a2games/ROID-screenshot.png)
