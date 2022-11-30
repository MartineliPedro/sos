.set FLAGS, (1<<0 | 1<<1) 
.set MAGIC, 0x1badb002
.set CHECKSUM, -(MAGIC + FLAGS)


.section .multiboot
    .align 4
    .long MAGIC
    .long FLAGS
    .long CHECKSUM

.section .bss
    .align 16
    stack_start:
        .skip 16384 
    stack_end:

.section .text
    .global _start
    .type _start, @function

    _start:
        mov $stack_start, %esp 

        call kmain


        cli
        hlt

.size _start, . - _start
