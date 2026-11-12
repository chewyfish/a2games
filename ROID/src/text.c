#ifndef __TEXT_C__
#define __TEXT_C__ 1

// Switch to text and clear page
//
////////////////////////////////////////////////////////////////////////////////
void text_init_page()
{
  __asm__ ("jsr $FC58"); // Invoke "HOME" subroutine
  __asm__ ("bit $C051"); // Select text mode
}

#endif // __TEXT_C__
