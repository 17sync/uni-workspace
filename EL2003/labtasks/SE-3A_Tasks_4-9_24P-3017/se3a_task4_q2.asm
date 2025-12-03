[org 0x0100]

jmp start

m1AL: db 0
m1AH: db 0
m1BL: db 0
m1BH: db 0
m1CL: db 0

start:
    mov al, 25
    mov bl, 15

    mov [m1AL], al
    add al, bl
    mov ah, al

    mov al, [m1AL]
    sub al, bl
    mov bh, al

    mov [m1AH], ah
    add ah, bh
    mov cl, ah

    mov al, [m1AL]      ; just so the registers have the correct final values
    mov ah, [m1AH]      ; though the question already requires us to store them in memory so it doesn't really matter

    mov [m1BL], bl
    mov [m1BH], bh
    mov [m1CL], cl

    mov ax, 0x4c00
    int 0x21