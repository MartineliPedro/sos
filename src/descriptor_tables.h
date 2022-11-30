#ifndef DESC_TABLES_H
#define DESC_TABLES_H

#include <stdint.h>

typedef struct GDT_ENTRY_STRUCT
{
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;

} __attribute__((packed)) gdt_entry_t;

typedef struct GDT_POINTER_STRUCT
{
    uint16_t limit;
    uint32_t base;

} __attribute__((packed)) gdt_pointer_t;

typedef struct IDT_ENTRY_STRUCT
{

} __attribute__((packed)) idt_entry_t;

typedef struct IDT_POINTER_STRUCT
{

} __attribute__((packed)) idt_pointer_t;

void init_descriptor_tables(void);

#endif