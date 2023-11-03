section .bss
input resb 2          ; Reserve two bytes for the input (one for the character, one for the newline)

section .data
prompt db "ENTER A NUMBER: ", 0
too_low db "TOO LOW!", 0xA 	; 0xA is newline
too_high db "TOO HIGH!", 0xA
correct db "GOT IT!", 0xA
game_over db "GAME OVER!", 0xA
magic_number db 7    ; The magic number is 7
max_tries db 3       ; Limit of attempts

section .text
global _start

_start:
    mov ecx, max_tries  ; Set the number of tries

get_input:
    ; Print the prompt
    mov eax, 4          ; sys_write
    mov ebx, 1          ; file descriptor (stdout)
    mov ecx, prompt     ; message to print
    mov edx, 17         ; message length
    int 0x80            ; make kernel call

    ; Read a single digit from the user
    mov eax, 3          ; sys_read
    mov ebx, 0          ; file descriptor (stdin)
    mov ecx, input      ; buffer to store input
    mov edx, 2          ; read two bytes (one for the character, one for the newline)
    int 0x80            ; make kernel call

    ; Convert ASCII character to integer
    sub byte [input], '0'

    ; Compare input with the magic number
    mov al, [input]         ; Move the input into al
    movzx ebx, byte [magic_number] ; Move magic_number into ebx with zero-extension
    cmp al, bl              ; Compare the two values
    je correct_guess
    jl lower_guess
    ; If not lower, it's higher
higher_guess:
    ; Print "TOO HIGH!"
    mov eax, 4
    mov ebx, 1
    mov ecx, too_high
    mov edx, 9
    int 0x80
    jmp decrement_tries

lower_guess:
    ; Print "TOO LOW!"
    mov eax, 4
    mov ebx, 1
    mov ecx, too_low
    mov edx, 9
    int 0x80

decrement_tries:
    dec ecx                ; Decrement the counter
    jz game_over_label     ; If zero, jump to game over

    ; Otherwise, prompt for input again
    jmp get_input          ; Jump back to get input

game_over_label:
    ; Print "GAME OVER!" and exit
    mov eax, 4
    mov ebx, 1
    mov ecx, game_over
    mov edx, 10           ; length of "GAME OVER!" + newline
    int 0x80

    jmp exit

correct_guess:
    ; Print "GOT IT!"
    mov eax, 4
    mov ebx, 1
    mov ecx, correct
    mov edx, 7
    int 0x80

exit:
    ; Exit the program
    mov eax, 1
    xor ebx, ebx
    int 0x80

