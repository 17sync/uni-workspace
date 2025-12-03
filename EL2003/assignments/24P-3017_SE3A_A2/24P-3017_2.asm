[org 0x100]

jmp start

X: dw 20
Y: dw 15

calcGCD:
    cmp bx, 0        ; base condition
    je retX

    cmp ax, bx
    jl swapXY

    sub ax, bx
    push bx
    call calcGCD    ; recursive call
    pop bx
    ret

swapXY:
    xchg ax, bx
    push bx
    call GCD
    pop bx
    ret

retX:
    ret

start:

    mov ax, [X]      
    mov bx, [Y]   

    call calcGCD

    mov ax, 0x4c00
    int 0x21
