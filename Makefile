CSRC = $(shell find . -type f -name '*.c')
SSRC = $(shell find . -type f -name '*.s')
OBJECTS = $(CSRC:.c=.o) $(SSRC:.s=.o)

ASMPARAMS = 
CPARAMS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra
LDPARAMS = -ffreestanding -O2 -nostdlib

.PHONY: kernel.bin kernel.iso mb-check clean run run-dbg

kernel.bin: $(OBJECTS)
	$$HOME/opt/cross/bin/i686-elf-gcc -T linker.ld -o $@  $(LDPARAMS) $^ -lgcc
	rm -rf $(OBJECTS)
	
kernel.iso: kernel.bin
	mkdir -p iso/boot/grub

	cp kernel.bin iso/boot/kernel.bin
	cp grub.cfg iso/boot/grub/grub.cfg
	grub-mkrescue -o $@ iso

	rm -rf iso
	rm -rf $(OBJECTS)


run: kernel.iso
	qemu-system-i386 -cdrom kernel.iso

run-dbg: kernel.iso
	qemu-system-i386 -cdrom kernel.iso -d cpu

# Debug

mb-check:
	grub-file --is-x86-multiboot kernel.bin
	$$?
	



clean:
	rm -rf $(OBJECTS)
	rm -f kernel.bin
	rm -f kernel.iso

%.o: %.s
	$$HOME/opt/cross/bin/i686-elf-as $< -o $@

%.o: %.c
	$$HOME/opt/cross/bin/i686-elf-gcc -c $< -o $@ $(CPARAMS)
	
	