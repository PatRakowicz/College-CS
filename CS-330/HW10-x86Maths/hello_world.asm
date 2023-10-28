SECTION .data

MSG: db "HELLO WORLD!",10
LEN: equ $-MSG

SECTION .bss
SECTION .text

global _start

_start:
  nop
  mov eax,4
  mov ebx,1
  mov ecx,MSG
  mov edx,LEN
  int 80H
  
  mov eax,1
  mov ebx,0
  int 80H

