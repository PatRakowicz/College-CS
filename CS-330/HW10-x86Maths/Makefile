hello_world: hello_world.o
	ld -m elf_i386 -o hello_world hello_world.o 

hello_world.o: hello_world.asm
	nasm -f elf -g -F stabs hello_world.asm
