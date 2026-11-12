#ifndef __HGR_C__
#define __HGR_C__ 1

#include "hgr.h"
#include "sprite.h"
#include "sprite.c"

// Hires page 1 screen
// - HGR_PAGE1_ROWADDR: Starting address for page 1's rows

#define PG1CALC(x) (unsigned char *)(HGR_PAGE1_BASEADDR | x)
const unsigned char *const HGR_SCREEN_PAGE1_ROWADDR[HGR_FULLPAGE_HEIGHT] = {
    PG1CALC(0x0000), PG1CALC(0x0400), PG1CALC(0x0800), PG1CALC(0x0C00), PG1CALC(0x1000), PG1CALC(0x1400), PG1CALC(0x1800), PG1CALC(0x1C00),
    PG1CALC(0x0080), PG1CALC(0x0480), PG1CALC(0x0880), PG1CALC(0x0C80), PG1CALC(0x1080), PG1CALC(0x1480), PG1CALC(0x1880), PG1CALC(0x1C80),
    PG1CALC(0x0100), PG1CALC(0x0500), PG1CALC(0x0900), PG1CALC(0x0D00), PG1CALC(0x1100), PG1CALC(0x1500), PG1CALC(0x1900), PG1CALC(0x1D00),
    PG1CALC(0x0180), PG1CALC(0x0580), PG1CALC(0x0980), PG1CALC(0x0D80), PG1CALC(0x1180), PG1CALC(0x1580), PG1CALC(0x1980), PG1CALC(0x1D80),
    PG1CALC(0x0200), PG1CALC(0x0600), PG1CALC(0x0A00), PG1CALC(0x0E00), PG1CALC(0x1200), PG1CALC(0x1600), PG1CALC(0x1A00), PG1CALC(0x1E00),
    PG1CALC(0x0280), PG1CALC(0x0680), PG1CALC(0x0A80), PG1CALC(0x0E80), PG1CALC(0x1280), PG1CALC(0x1680), PG1CALC(0x1A80), PG1CALC(0x1E80),
    PG1CALC(0x0300), PG1CALC(0x0700), PG1CALC(0x0B00), PG1CALC(0x0F00), PG1CALC(0x1300), PG1CALC(0x1700), PG1CALC(0x1B00), PG1CALC(0x1F00),
    PG1CALC(0x0380), PG1CALC(0x0780), PG1CALC(0x0B80), PG1CALC(0x0F80), PG1CALC(0x1380), PG1CALC(0x1780), PG1CALC(0x1B80), PG1CALC(0x1F80),
    PG1CALC(0x0028), PG1CALC(0x0428), PG1CALC(0x0828), PG1CALC(0x0C28), PG1CALC(0x1028), PG1CALC(0x1428), PG1CALC(0x1828), PG1CALC(0x1C28),
    PG1CALC(0x00A8), PG1CALC(0x04A8), PG1CALC(0x08A8), PG1CALC(0x0CA8), PG1CALC(0x10A8), PG1CALC(0x14A8), PG1CALC(0x18A8), PG1CALC(0x1CA8),
    PG1CALC(0x0128), PG1CALC(0x0528), PG1CALC(0x0928), PG1CALC(0x0D28), PG1CALC(0x1128), PG1CALC(0x1528), PG1CALC(0x1928), PG1CALC(0x1D28),
    PG1CALC(0x01A8), PG1CALC(0x05A8), PG1CALC(0x09A8), PG1CALC(0x0DA8), PG1CALC(0x11A8), PG1CALC(0x15A8), PG1CALC(0x19A8), PG1CALC(0x1DA8),
    PG1CALC(0x0228), PG1CALC(0x0628), PG1CALC(0x0A28), PG1CALC(0x0E28), PG1CALC(0x1228), PG1CALC(0x1628), PG1CALC(0x1A28), PG1CALC(0x1E28),
    PG1CALC(0x02A8), PG1CALC(0x06A8), PG1CALC(0x0AA8), PG1CALC(0x0EA8), PG1CALC(0x12A8), PG1CALC(0x16A8), PG1CALC(0x1AA8), PG1CALC(0x1EA8),
    PG1CALC(0x0328), PG1CALC(0x0728), PG1CALC(0x0B28), PG1CALC(0x0F28), PG1CALC(0x1328), PG1CALC(0x1728), PG1CALC(0x1B28), PG1CALC(0x1F28),
    PG1CALC(0x03A8), PG1CALC(0x07A8), PG1CALC(0x0BA8), PG1CALC(0x0FA8), PG1CALC(0x13A8), PG1CALC(0x17A8), PG1CALC(0x1BA8), PG1CALC(0x1FA8),
    PG1CALC(0x0050), PG1CALC(0x0450), PG1CALC(0x0850), PG1CALC(0x0C50), PG1CALC(0x1050), PG1CALC(0x1450), PG1CALC(0x1850), PG1CALC(0x1C50),
    PG1CALC(0x00D0), PG1CALC(0x04D0), PG1CALC(0x08D0), PG1CALC(0x0CD0), PG1CALC(0x10D0), PG1CALC(0x14D0), PG1CALC(0x18D0), PG1CALC(0x1CD0),
    PG1CALC(0x0150), PG1CALC(0x0550), PG1CALC(0x0950), PG1CALC(0x0D50), PG1CALC(0x1150), PG1CALC(0x1550), PG1CALC(0x1950), PG1CALC(0x1D50),
    PG1CALC(0x01D0), PG1CALC(0x05D0), PG1CALC(0x09D0), PG1CALC(0x0DD0), PG1CALC(0x11D0), PG1CALC(0x15D0), PG1CALC(0x19D0), PG1CALC(0x1DD0),
    PG1CALC(0x0250), PG1CALC(0x0650), PG1CALC(0x0A50), PG1CALC(0x0E50), PG1CALC(0x1250), PG1CALC(0x1650), PG1CALC(0x1A50), PG1CALC(0x1E50),
    PG1CALC(0x02D0), PG1CALC(0x06D0), PG1CALC(0x0AD0), PG1CALC(0x0ED0), PG1CALC(0x12D0), PG1CALC(0x16D0), PG1CALC(0x1AD0), PG1CALC(0x1ED0),
    PG1CALC(0x0350), PG1CALC(0x0750), PG1CALC(0x0B50), PG1CALC(0x0F50), PG1CALC(0x1350), PG1CALC(0x1750), PG1CALC(0x1B50), PG1CALC(0x1F50),
    PG1CALC(0x03D0), PG1CALC(0x07D0), PG1CALC(0x0BD0), PG1CALC(0x0FD0), PG1CALC(0x13D0), PG1CALC(0x17D0), PG1CALC(0x1BD0), PG1CALC(0x1FD0)};

// Hires page 2 screen
// - HGR_PAGE2_ROWADDR: Starting address for page 2's rows

#ifdef HGRPAGE2
#define PG2CALC(x) (unsigned char *)(HGR_PAGE2_BASEADDR | x)
const unsigned char *const HGR_SCREEN_PAGE2_ROWADDR[HGR_FULLPAGE_HEIGHT] = {
    PG2CALC(0x0000), PG2CALC(0x0400), PG2CALC(0x0800), PG2CALC(0x0C00), PG2CALC(0x1000), PG2CALC(0x1400), PG2CALC(0x1800), PG2CALC(0x1C00),
    PG2CALC(0x0080), PG2CALC(0x0480), PG2CALC(0x0880), PG2CALC(0x0C80), PG2CALC(0x1080), PG2CALC(0x1480), PG2CALC(0x1880), PG2CALC(0x1C80),
    PG2CALC(0x0100), PG2CALC(0x0500), PG2CALC(0x0900), PG2CALC(0x0D00), PG2CALC(0x1100), PG2CALC(0x1500), PG2CALC(0x1900), PG2CALC(0x1D00),
    PG2CALC(0x0180), PG2CALC(0x0580), PG2CALC(0x0980), PG2CALC(0x0D80), PG2CALC(0x1180), PG2CALC(0x1580), PG2CALC(0x1980), PG2CALC(0x1D80),
    PG2CALC(0x0200), PG2CALC(0x0600), PG2CALC(0x0A00), PG2CALC(0x0E00), PG2CALC(0x1200), PG2CALC(0x1600), PG2CALC(0x1A00), PG2CALC(0x1E00),
    PG2CALC(0x0280), PG2CALC(0x0680), PG2CALC(0x0A80), PG2CALC(0x0E80), PG2CALC(0x1280), PG2CALC(0x1680), PG2CALC(0x1A80), PG2CALC(0x1E80),
    PG2CALC(0x0300), PG2CALC(0x0700), PG2CALC(0x0B00), PG2CALC(0x0F00), PG2CALC(0x1300), PG2CALC(0x1700), PG2CALC(0x1B00), PG2CALC(0x1F00),
    PG2CALC(0x0380), PG2CALC(0x0780), PG2CALC(0x0B80), PG2CALC(0x0F80), PG2CALC(0x1380), PG2CALC(0x1780), PG2CALC(0x1B80), PG2CALC(0x1F80),
    PG2CALC(0x0028), PG2CALC(0x0428), PG2CALC(0x0828), PG2CALC(0x0C28), PG2CALC(0x1028), PG2CALC(0x1428), PG2CALC(0x1828), PG2CALC(0x1C28),
    PG2CALC(0x00A8), PG2CALC(0x04A8), PG2CALC(0x08A8), PG2CALC(0x0CA8), PG2CALC(0x10A8), PG2CALC(0x14A8), PG2CALC(0x18A8), PG2CALC(0x1CA8),
    PG2CALC(0x0128), PG2CALC(0x0528), PG2CALC(0x0928), PG2CALC(0x0D28), PG2CALC(0x1128), PG2CALC(0x1528), PG2CALC(0x1928), PG2CALC(0x1D28),
    PG2CALC(0x01A8), PG2CALC(0x05A8), PG2CALC(0x09A8), PG2CALC(0x0DA8), PG2CALC(0x11A8), PG2CALC(0x15A8), PG2CALC(0x19A8), PG2CALC(0x1DA8),
    PG2CALC(0x0228), PG2CALC(0x0628), PG2CALC(0x0A28), PG2CALC(0x0E28), PG2CALC(0x1228), PG2CALC(0x1628), PG2CALC(0x1A28), PG2CALC(0x1E28),
    PG2CALC(0x02A8), PG2CALC(0x06A8), PG2CALC(0x0AA8), PG2CALC(0x0EA8), PG2CALC(0x12A8), PG2CALC(0x16A8), PG2CALC(0x1AA8), PG2CALC(0x1EA8),
    PG2CALC(0x0328), PG2CALC(0x0728), PG2CALC(0x0B28), PG2CALC(0x0F28), PG2CALC(0x1328), PG2CALC(0x1728), PG2CALC(0x1B28), PG2CALC(0x1F28),
    PG2CALC(0x03A8), PG2CALC(0x07A8), PG2CALC(0x0BA8), PG2CALC(0x0FA8), PG2CALC(0x13A8), PG2CALC(0x17A8), PG2CALC(0x1BA8), PG2CALC(0x1FA8),
    PG2CALC(0x0050), PG2CALC(0x0450), PG2CALC(0x0850), PG2CALC(0x0C50), PG2CALC(0x1050), PG2CALC(0x1450), PG2CALC(0x1850), PG2CALC(0x1C50),
    PG2CALC(0x00D0), PG2CALC(0x04D0), PG2CALC(0x08D0), PG2CALC(0x0CD0), PG2CALC(0x10D0), PG2CALC(0x14D0), PG2CALC(0x18D0), PG2CALC(0x1CD0),
    PG2CALC(0x0150), PG2CALC(0x0550), PG2CALC(0x0950), PG2CALC(0x0D50), PG2CALC(0x1150), PG2CALC(0x1550), PG2CALC(0x1950), PG2CALC(0x1D50),
    PG2CALC(0x01D0), PG2CALC(0x05D0), PG2CALC(0x09D0), PG2CALC(0x0DD0), PG2CALC(0x11D0), PG2CALC(0x15D0), PG2CALC(0x19D0), PG2CALC(0x1DD0),
    PG2CALC(0x0250), PG2CALC(0x0650), PG2CALC(0x0A50), PG2CALC(0x0E50), PG2CALC(0x1250), PG2CALC(0x1650), PG2CALC(0x1A50), PG2CALC(0x1E50),
    PG2CALC(0x02D0), PG2CALC(0x06D0), PG2CALC(0x0AD0), PG2CALC(0x0ED0), PG2CALC(0x12D0), PG2CALC(0x16D0), PG2CALC(0x1AD0), PG2CALC(0x1ED0),
    PG2CALC(0x0350), PG2CALC(0x0750), PG2CALC(0x0B50), PG2CALC(0x0F50), PG2CALC(0x1350), PG2CALC(0x1750), PG2CALC(0x1B50), PG2CALC(0x1F50),
    PG2CALC(0x03D0), PG2CALC(0x07D0), PG2CALC(0x0BD0), PG2CALC(0x0FD0), PG2CALC(0x13D0), PG2CALC(0x17D0), PG2CALC(0x1BD0), PG2CALC(0x1FD0)};
#endif // HGRPAGE2

// Hires lookup maps
// - HGR_MAP_ROWPIXEL2BYTE: Map row byte number (array value) based on row pixel (array index) 
// - HGR_MAP_ROWPIXEL2SHIFT: Map sprite shift (array value) based on row pixel (array index)

const unsigned char HGR_MAP_ROWPIXEL2BYTE[HGR_FULLPAGE_WIDTH] = {
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x02,0x02,0x02,0x02,0x02,0x02,0x02,
	0x03,0x03,0x03,0x03,0x03,0x03,0x03,
	0x04,0x04,0x04,0x04,0x04,0x04,0x04,
	0x05,0x05,0x05,0x05,0x05,0x05,0x05,
	0x06,0x06,0x06,0x06,0x06,0x06,0x06,
	0x07,0x07,0x07,0x07,0x07,0x07,0x07,
	0x08,0x08,0x08,0x08,0x08,0x08,0x08,
	0x09,0x09,0x09,0x09,0x09,0x09,0x09,
	0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,
	0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,
	0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,
	0x0D,0x0D,0x0D,0x0D,0x0D,0x0D,0x0D,
	0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,
	0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,
	0x10,0x10,0x10,0x10,0x10,0x10,0x10,
	0x11,0x11,0x11,0x11,0x11,0x11,0x11,
	0x12,0x12,0x12,0x12,0x12,0x12,0x12,
	0x13,0x13,0x13,0x13,0x13,0x13,0x13,
	0x14,0x14,0x14,0x14,0x14,0x14,0x14,
	0x15,0x15,0x15,0x15,0x15,0x15,0x15,
	0x16,0x16,0x16,0x16,0x16,0x16,0x16,
	0x17,0x17,0x17,0x17,0x17,0x17,0x17,
	0x18,0x18,0x18,0x18,0x18,0x18,0x18,
	0x19,0x19,0x19,0x19,0x19,0x19,0x19,
	0x1A,0x1A,0x1A,0x1A,0x1A,0x1A,0x1A,
	0x1B,0x1B,0x1B,0x1B,0x1B,0x1B,0x1B,
	0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,
	0x1D,0x1D,0x1D,0x1D,0x1D,0x1D,0x1D,
	0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,
	0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
	0x20,0x20,0x20,0x20,0x20,0x20,0x20,
	0x21,0x21,0x21,0x21,0x21,0x21,0x21,
	0x22,0x22,0x22,0x22,0x22,0x22,0x22,
	0x23,0x23,0x23,0x23,0x23,0x23,0x23,
	0x24,0x24,0x24,0x24,0x24,0x24,0x24,
	0x25,0x25,0x25,0x25,0x25,0x25,0x25,
	0x26,0x26,0x26,0x26,0x26,0x26,0x26,
	0x27,0x27,0x27,0x27,0x27,0x27,0x27,
};

const unsigned char HGR_MAP_ROWPIXEL2SHIFT[HGR_FULLPAGE_WIDTH] = {
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,
};

// Row byte masks
// HGR_MASK_SINGLEBIT - 8-bit bitmask for single bit
// HGR_MASK_ALLPIXELS - 8-bit bitmask representing all drawing pixels set

const unsigned char HGR_MASK_SINGLEBIT[8] = {1, 2, 4, 8, 16, 32, 64, 128};
const unsigned char HGR_MASK_ALLPIXELS = 0x7F;

// Switch to given page and clear screen
//
////////////////////////////////////////////////////////////////////////////////
void hgr_init_page(unsigned char pagenum)
{
  __asm__ ("bit $C050"); // Initiate graphics mode
  __asm__ ("bit $C057"); // Select hi-res mode

  if (pagenum == 1)
  {
    __asm__ ("bit $C054"); // Select page 1
    __asm__ ("bit $C052"); // Select full-graphics mode

    memset((unsigned char *)HGR_PAGE1_BASEADDR, 0, 0x2000); // Clear page 1
  }
#ifdef HGRPAGE2
  else if (pagenum == 2)
  {
    __asm__ ("bit $C055"); // Select page 2

    memset((unsigned char *)HGR_PAGE2_BASEADDR, 0, 0x2000); // Clear page 1
  }
#endif // HGRPAGE2
}

// Draw (via XOR) horizontal line on given page
//
////////////////////////////////////////////////////////////////////////////////
void hgr_xor_hline(unsigned char pagenum, unsigned short y, unsigned short x1, unsigned char x2)
{
  unsigned char *page_row;
  unsigned char row_byte_offset1 = HGR_MAP_ROWPIXEL2BYTE[x1]; // Determine drawing row byte position (for x1)
  unsigned char row_byte_offset2 = HGR_MAP_ROWPIXEL2BYTE[x2]; // Determine drawing row byte position (for x2)
  unsigned char row_byte_idx;

  if (pagenum == 1)
  {
    page_row = (unsigned char*)HGR_SCREEN_PAGE1_ROWADDR[y];
  }
#ifdef HGRPAGE2
  else if (pagenum == 2)
  {
    page_row = (unsigned char*)HGR_SCREEN_PAGE2_ROWADDR[y];
  }
#endif // HGRPAGE2
  else return;

  for (row_byte_idx=row_byte_offset1; row_byte_idx<=row_byte_offset2; ++row_byte_idx)
  {
    unsigned char pixel_mask = HGR_MASK_ALLPIXELS;

    if (row_byte_idx == row_byte_offset1) // Toggle off left-end pixels
    {
      unsigned char bitshifts = HGR_MAP_ROWPIXEL2SHIFT[row_byte_idx];
      pixel_mask >> bitshifts;
      pixel_mask << bitshifts;
    }
    else if (row_byte_idx == row_byte_offset2) // Toggle off right-end pixels
    {
      unsigned char bitshifts = HGR_MAP_ROWPIXEL2SHIFT[row_byte_idx] + 1;
      pixel_mask << bitshifts;
      pixel_mask >> bitshifts;
    }

    page_row[row_byte_idx] ^= pixel_mask;
  }
}

// Draw (via XOR) vertical line on given page
//
////////////////////////////////////////////////////////////////////////////////
void hgr_xor_vline(unsigned char pagenum, unsigned short x, unsigned short y1, unsigned char y2)
{
  unsigned char **page_rows;
  unsigned char row_byte_offset = HGR_MAP_ROWPIXEL2BYTE[x]; // Determine drawing row byte position
  unsigned char pixel_mask = HGR_MASK_SINGLEBIT[HGR_MAP_ROWPIXEL2SHIFT[x]]; // Lookup bitmask for remainder
  unsigned char row;

  if (pagenum == 1)
  {
    page_rows = (unsigned char**)HGR_SCREEN_PAGE1_ROWADDR;
  }
#ifdef HGRPAGE2
  else if (pagenum == 2)
  {
    page_rows = (unsigned char**)HGR_SCREEN_PAGE2_ROWADDR;
  }
#endif // HGRPAGE2
  else return;

  for (row = y1; row <= y2; row++)
  {
    unsigned char *row_byte = &page_rows[row][row_byte_offset]; // Lookup dest. address
    *row_byte ^= pixel_mask; // XOR mask with destination
  }
}

// Draw (via XOR) a pixel on the given page
//
////////////////////////////////////////////////////////////////////////////////
void hgr_xor_pixel(unsigned char pagenum, unsigned short x, unsigned char y)
{
  hgr_xor_vline(pagenum, x, y, y); // Draw line with 1-pixel height
}

// Graphics rendering operation

typedef enum
{
  OP_DRAW,
  OP_XOR,
  OP_ERASE,
  OP_COLLCHECK
} GraphicsOperation;

// Render a sprite with the given graphics operation on the given page
//
////////////////////////////////////////////////////////////////////////////////
unsigned char hgr_render_sprite(unsigned char pagenum, unsigned char sprite_type, unsigned char shape_num, unsigned short x, unsigned char y, unsigned char op)
{
  unsigned char i, j;
  unsigned char **page_rows;
  unsigned char *shape_bitmap;
  unsigned char width_bytes;
  unsigned char height_pixels;
  unsigned char shape_shift_offset = HGR_MAP_ROWPIXEL2SHIFT[x]; // Determine shifted bitmap offset
  unsigned char row_byte_offset = HGR_MAP_ROWPIXEL2BYTE[x]; // Determine drawing row byte position

  if (pagenum == 1)
  {
    page_rows = (unsigned char**)HGR_SCREEN_PAGE1_ROWADDR;
  }
#ifdef HGRPAGE2
  else if (pagenum == 2)
  {
    page_rows = (unsigned char**)HGR_SCREEN_PAGE2_ROWADDR;
  }
#endif // HGRPAGE2
  else return 0;

  if (sprite_type == SPRITE_TYPE_SHIP)
  {
    shape_bitmap = (unsigned char*)SPRITE_SHIP_BITMAP[shape_num][shape_shift_offset];
    width_bytes = SPRITE_SHIP_WIDTHBYTES;
    height_pixels = SPRITE_SHIP_HEIGHTPIXELS;
  }
  else if (sprite_type == SPRITE_TYPE_ROID_SMALL)
  {
    shape_bitmap = (unsigned char*)SPRITE_ROID_SMALL_BITMAP[shape_num][shape_shift_offset];
    width_bytes = SPRITE_ROID_SMALL_WIDTHBYTES;
    height_pixels = SPRITE_ROID_SMALL_HEIGHTPIXELS;
  }
  else if (sprite_type == SPRITE_TYPE_ROID_MEDIUM)
  {
    shape_bitmap = (unsigned char*)SPRITE_ROID_MEDIUM_BITMAP[shape_num][shape_shift_offset];
    width_bytes = SPRITE_ROID_MEDIUM_WIDTHBYTES;
    height_pixels = SPRITE_ROID_MEDIUM_HEIGHTPIXELS;
  }
  else if (sprite_type == SPRITE_TYPE_ROID_LARGE)
  {
    shape_bitmap = (unsigned char*)SPRITE_ROID_LARGE_BITMAP[shape_num][shape_shift_offset];
    width_bytes = SPRITE_ROID_LARGE_WIDTHBYTES;
    height_pixels = SPRITE_ROID_LARGE_HEIGHTPIXELS;
  }
  else if (sprite_type == SPRITE_TYPE_BULLET)
  {
    shape_bitmap = (unsigned char*)SPRITE_BULLET_BITMAP[shape_shift_offset];
    width_bytes = SPRITE_BULLET_WIDTHBYTES;
    height_pixels = SPRITE_BULLET_HEIGHTPIXELS;
  }
  else if (sprite_type == SPRITE_TYPE_ICON)
  {
    shape_bitmap = (unsigned char*)SPRITE_ICON_BITMAP[shape_num][0];
    width_bytes = SPRITE_ICON_WIDTHBYTES;
    height_pixels = SPRITE_ICON_HEIGHTPIXELS;
  }
  else if (sprite_type == SPRITE_TYPE_CHAR)
  {
    shape_bitmap = (unsigned char*)SPRITE_CHAR_BITMAP[shape_num][0];
    width_bytes = SPRITE_CHAR_WIDTHBYTES;
    height_pixels = SPRITE_CHAR_HEIGHTPIXELS;
  }
  else if (sprite_type == SPRITE_TYPE_GAMEOVER)
  {
    shape_bitmap = (unsigned char*)SPRITE_GAMEOVER_BITMAP[shape_num][0];
    width_bytes = SPRITE_GAMEOVER_WIDTHBYTES;
    height_pixels = SPRITE_GAMEOVER_HEIGHTPIXELS;
  }
  else return 0;

  for (i = 0; i < height_pixels; ++i)
  {
    unsigned char *page_ptr = &page_rows[y][row_byte_offset];

    for (j = 0; j < width_bytes; ++j)
    {
      unsigned char shape_byte = *shape_bitmap++;

      switch (op)
      {
        case OP_DRAW:
          *page_ptr++ = shape_byte;
          break;
        case OP_XOR:
          *page_ptr++ ^= shape_byte;
          break;
        case OP_ERASE:
          *page_ptr++ &= ~shape_byte;
          break;
        case OP_COLLCHECK:
          if (*page_ptr++ & shape_byte) {
            hgr_collision_colpixel = ((row_byte_offset + j) * 7) + 4;
            hgr_collision_rowpixel = y;
            return 1;
          }
          break;
      }
    }

    ++y;
  }

  return 0;
}

// Render sprite via directly drawing bitmap on given page
//
////////////////////////////////////////////////////////////////////////////////
unsigned char hgr_draw_sprite(unsigned char pagenum, unsigned char sprite_type, unsigned char shape_num, unsigned short x, unsigned char y)
{
  return hgr_render_sprite(pagenum, sprite_type, shape_num, x, y, OP_DRAW);
}

// Render sprite via XORing with corresponding page positions for given page
//
////////////////////////////////////////////////////////////////////////////////
unsigned char hgr_xor_sprite(unsigned char pagenum, unsigned char sprite_type, unsigned char shape_num, unsigned short x, unsigned char y)
{
  return hgr_render_sprite(pagenum, sprite_type, shape_num, x, y, OP_XOR);
}

// Erase sprite via ANDing complement shape bytes with corresponding page positions for given page
//
////////////////////////////////////////////////////////////////////////////////
unsigned char hgr_erase_sprite(unsigned char pagenum, unsigned char sprite_type, unsigned char shape_num, unsigned short x, unsigned char y)
{
  return hgr_render_sprite(pagenum, sprite_type, shape_num, x, y, OP_ERASE);
}

// Check if sprite for this position will collide with anything for given page
//
////////////////////////////////////////////////////////////////////////////////
unsigned char hgr_collision_sprite(unsigned char pagenum, unsigned char sprite_type, unsigned char shape_num, unsigned short x, unsigned char y)
{
  return hgr_render_sprite(pagenum, sprite_type, shape_num, x, y, OP_COLLCHECK);
}

#endif // __HGR_C__
