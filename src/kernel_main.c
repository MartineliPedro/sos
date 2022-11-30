#include <stddef.h>
#include <stdint.h>

#include "monitor.h"
#include "descriptor_tables.h"

void kmain(void)
{   
    init_descriptor_tables();

    outb(COM1, 'x');        

    for(;;);


}