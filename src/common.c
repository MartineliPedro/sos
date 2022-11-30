#include "common.h"

void outb(uint16_t port, uint8_t value)
{
    __asm__ volatile("outb %1, %0": : "dN"(port), "a"(value));
}

uint8_t inb(uint16_t port)
{
    uint8_t ret;
   asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
   return ret;
}


uint8_t get_high_16(uint16_t value)
{
    return (value >> 8) & 0xFF;
}
uint8_t get_low_16(uint16_t value)
{
    return value & 0xFF;
}

uint16_t get_high_32(uint32_t value)
{
    return (value >> 16) & 0xFFFF;
}
uint16_t get_low_32(uint32_t value)
{
    return value & 0xFFFF;
}