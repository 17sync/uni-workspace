[org 0x0100]

jmp start

array: db 7, 5, 4, 2

start:
    mov si, array       ; always points to the start of the array
    mov cx, 3           ; size-1 since the last iteration is just one element

outerloop:
    mov bx, si          
    mov di, si
    mov dx, cx          ; counter for finding minimum

innerloop:
    add di, 1
    mov al, [di]
    mov ah, [bx]

    cmp al, ah
    jae skip

    mov bx, di

skip:
    dec dx
    jnz innerloop

    mov al, [si]        ; swap minimum with first element
    mov ah, [bx]
    mov [si], ah
    mov [bx], al

    add si, 1           ; start moves one byte forward
    sub cx, 1
    jnz outerloop

    mov ax, 0x4c00
    int 0x21
