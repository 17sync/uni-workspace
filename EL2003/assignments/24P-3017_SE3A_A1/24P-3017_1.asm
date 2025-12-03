[org 0x0100]

jmp start

initialInt: db 53
reversedInt: db 0

start:
    mov cx, 8               ; byte reversal
    mov al, [initialInt]
    mov bl, 0
    
    reverseBits:
        shr al, 1
        rcr bl, 1

        sub cx, 1
        jnz reverseBits

    mov [reversedInt], bl       ; question says to store the result in a register, i'll store it in memory anyways
    
    mov ax, 0x4c00
    int 0x21
