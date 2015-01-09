section .text

global start
start:
    push dword 4
    mov eax, 0x1
    sub esp, 4
    int 0x80
