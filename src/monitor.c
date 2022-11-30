#include "monitor.h"

#include <stdint.h>

#define VGA_MEMORY 0xb8000
#define VGA_HIGH_CURSOR_BYTE 14
#define VGA_LOW_CURSOR_BYTE 15

#define CHAR_BACKSPACE 0x08
#define CHAR_TAB 0x09

int cursor_x, cursor_y = 0;

static void move_cursor()
{
    uint16_t cursor_location = cursor_y * 80 + cursor_x;
    outb(VGA_3D4, VGA_HIGH_CURSOR_BYTE);
    outb(VGA_3D5, get_high_16(cursor_location));
    outb(VGA_3D4, VGA_LOW_CURSOR_BYTE);
    outb(VGA_3D5, get_low_16(cursor_location));
}



void monitor_putc(char c)
{
    uint16_t attribute = ((0 << 4) | (15 & 0x0F)) << 8;
    uint16_t* vga_location;

    if (c == CHAR_BACKSPACE && cursor_x)
    {
        cursor_x--;
    }
    else if (c == CHAR_TAB)
    {
        cursor_x = (cursor_x + 8) & ~(8 - 1);
    }
    else if (c == '\r')
    {
        cursor_x = 0;
    }
    else if (c == '\n')
    {
        cursor_x = 0;
        cursor_y++;
    }
    else if (c >= ' ')
    {
        vga_location = (uint16_t*)(VGA_MEMORY + (cursor_y * 80 + cursor_x));
        *vga_location = c | attribute;
        cursor_x++;
    }
    move_cursor();
}
void monitor_clearscr()
{
}
void monitor_writestring(const char *string)
{
}