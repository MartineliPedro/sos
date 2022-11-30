.global gdt_flush
.type gdt_flush, @function

.global idt_flush
.type idt_flush, @function

gdt_flush:
    mov 4(%esp), %eax
    lgdt (%eax)

    movw $0x10, %ax
    movw %ax, %ds
    movw %ax, %es
    movw %ax, %fs
    movw %ax, %gs
    movw %ax, %ss

    ljmp $0x0008, $flush_end
flush_end:
    ret

idt_flush:
    mov 4(%esp), %eax
    lidt (%eax)
ret
