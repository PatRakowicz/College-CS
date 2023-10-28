SECTION .data
    x: dd 2
    y: dd 0       ; Initializing y to 0

SECTION .bss
    z: resd 1     ; reserving space for z
    a: resd 1     ; reserving space for a

SECTION .text

global _start

_start:
    nop
	;y = x + 4
	mov eax, [x]  ; Load x from memory into eax
	add eax, 4    ; do x + 4
	mov [y], eax  ; Move eax to y

	;z = y - (x + 1)
	mov eax, [y]       ; eax = y
	mov ecx, [x]       ; ecx = x
	add ecx, 1         ; ecx = x + 1
	sub eax, ecx       ; eax = y - (x + 1)
	mov [z], eax       ; z = y - (x + 1)

	;a = (x + z) * (y / 2) + z^2
	mov eax, [x]       ; eax = x
	add eax, [z]       ; eax = x + z
	mov ebx, [y]       ; ebx = y
	shr ebx, 1         ; ebx = y / 2 using right shift

	mul ebx            ; edx:eax = eax * ebx = (x + z) * (y / 2)
	mov ebx, [z]       ; ebx = z

	imul ebx, [z]      ; ebx = z^2
	add eax, ebx       ; eax = (x + z) * (y / 2) + z^2
	mov [a], eax       ; a = (x + z) * (y / 2) + z^2

	;x = a + z
	mov eax, [a]       ; eax = a
	add eax, [z]       ; eax = a + z
	mov [x], eax       ; x = a + z

	; Move variables into registers
	mov eax, [x]
	mov ebx, [y]
	mov ecx, [z]
	mov edx, [a]
