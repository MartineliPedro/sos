#ifndef COMMON_H
#define COMMON_H

#define VGA_3D4 0x3d4
#define VGA_3D5 0x3d5

#define COM1 0x3f8

#include <stdint.h>

void outb(uint16_t port, uint8_t value);
uint8_t inb(uint16_t port);


uint8_t get_high_16(uint16_t value);
uint8_t get_low_16(uint16_t value);
uint16_t get_high_32(uint32_t value);
uint16_t get_low_32(uint32_t value);

#endif