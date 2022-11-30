#include "descriptor_tables.h"
#include "common.h"

extern void gdt_flush(uint32_t);

static void init_gdt();
static void gdt_set_gate(uint8_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity);

gdt_entry_t gdt[5];
gdt_pointer_t gdtp;

void init_descriptor_tables()
{
    init_gdt();
}

static void init_gdt()
{
    gdtp.limit = (sizeof(gdt_entry_t) * 3) - 1;
    gdtp.base = (uint32_t)&gdt;

     gdt_set_gate(0, 0, 0, 0, 0);                // Null segment
     gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment
     gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment



    gdt_flush((uint32_t)&gdtp);

}

static void gdt_set_gate(uint8_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity)
{
    gdt[num].base_low = (base & 0xFFFF);
    gdt[num].base_middle = (base >> 16) & 0xFF;
    gdt[num].base_high = (base >> 24) & 0xFF;

    gdt[num].limit_low = (limit & 0xFFFF);
    gdt[num].granularity = (limit >> 16) & 0x0F;

    gdt[num].granularity |= granularity & 0xF0;
    gdt[num].access = access;

}