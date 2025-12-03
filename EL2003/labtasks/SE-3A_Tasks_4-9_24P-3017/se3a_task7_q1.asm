[org 0x0100]

jmp start

base: db 3
exponent: db 4
power_result: dw 0

start:
    mov cl, 0       ; loop counter
    mov al, 3
    mov bl, 3

    calculatePower:
        mul bl

        add cl, 1
        cmp cl, [exponent]

        jne calculatePower

    mov [power_result], ax

    mov ax, 0x4c00
    int 0x21
        