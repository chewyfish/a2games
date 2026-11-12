#ifndef __COMMON_C__
#define __COMMON_C__ 1

// Retrieve latest keyboard input character
//
////////////////////////////////////////////////////////////////////////////////
char key_read()
{
    unsigned char ch;
    ch = 0;

    if (kbhit())
    {
        ch = cgetc();
    }

    return ch;
}

// Delay routine
//
////////////////////////////////////////////////////////////////////////////////
void wait(unsigned char count)
{
  while (count--)
  {
    unsigned char repeat_idx=0, multiplier_idx=0;
    for (repeat_idx=0; repeat_idx<100;)
    {
      if (++multiplier_idx == 10)
      {
        ++repeat_idx;
        multiplier_idx = 0;
      }
    }
  }
}

#endif // __COMMON_C__
