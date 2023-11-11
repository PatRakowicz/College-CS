section .bss
    buffer resb 81         ; Reserve 81 bytes for buffer
    stack resb 81          ; Stack for keeping track of brackets

section .data
    errorMsg db 'ERROR: Unbalanced brackets', 0xA  ; Error message
    errorMsgLen equ $ - errorMsg                    ; Error message length

section .text
global _start

_start:
    ; Read input from user
    mov eax, 3               ; syscall number for sys_read
    mov ebx, 0               ; file descriptor 0 is stdin
    mov ecx, buffer          ; pointer to buffer
    mov edx, 80              ; number of bytes to read
    int 0x80                 ; interrupt

    ; Check for balanced brackets
    xor esi, esi             ; Clear ESI register for buffer index
    xor edi, edi             ; Clear EDI register for stack index

check_loop:
    mov al, byte [buffer + esi]  ; Load next byte from buffer
    cmp al, 0                ; Check for null terminator
    je  check_done           ; If end of buffer, jump to check_done
    cmp al, '('
    je  push_stack
    cmp al, '['
    je  push_stack
    cmp al, '{'
    je  push_stack
    cmp al, ')'
    je  pop_stack
    cmp al, ']'
    je  pop_stack
    cmp al, '}'
    je  pop_stack
    ; If current character is not a bracket, just move to the next character
    inc esi
    jmp check_loop

push_stack:
    mov [stack + edi], al    ; Push bracket onto stack
    inc edi                  ; Increment stack index
    inc esi                  ; Increment buffer index
    jmp check_loop

pop_stack:
    dec edi                  ; Decrement stack index
    cmp edi, 0
    jl  unbalanced           ; If stack index is negative, brackets are unbalanced
    mov dl, [stack + edi]    ; Pop bracket from stack
    ; Check if brackets match
    cmp al, ')'
    je  compare_round
    cmp al, ']'
    je  compare_square
    cmp al, '}'
    je  compare_curly

compare_round:
    cmp dl, '('
    jne unbalanced
    jmp continue_check

compare_square:
    cmp dl, '['
    jne unbalanced
    jmp continue_check

compare_curly:
    cmp dl, '{'
    jne unbalanced

continue_check:
    inc esi                  ; Increment buffer index
    jmp check_loop

check_done:
    cmp edi, 0               ; Check if stack is empty
    jne unbalanced           ; If not, brackets are unbalanced

    ; If brackets are balanced, write the entire line to stdout
    mov eax, 4               ; syscall number for sys_write
    mov ebx, 1               ; file descriptor 1 is stdout
    mov ecx, buffer          ; pointer to buffer
    mov edx, esi             ; number of bytes to write from buffer
    int 0x80                 ; interrupt
    jmp exit

unbalanced:
    ; If unbalanced, write error message to stdout
    mov eax, 4               ; syscall number for sys_write
    mov ebx, 1               ; file descriptor 1 is stdout
    mov ecx, errorMsg        ; pointer to error message
    mov edx, errorMsgLen     ; error message length
    int 0x80                 ; interrupt

exit:
    ; Exit the program
    mov eax, 1               ; syscall number for sys_exit
    xor ebx, ebx             ; return 0 status
    int 0x80                 ; interrupt

