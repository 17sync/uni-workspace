[org 0x0100]

jmp start

result: db 0

start:
    mov ax, 8
    mov bx, 12
    
    add ax, bx
    shl al, 1           ; result < 255

    sub al, 5
    mov [result], al

    mov ax, 0x4c00
    int 0x21
