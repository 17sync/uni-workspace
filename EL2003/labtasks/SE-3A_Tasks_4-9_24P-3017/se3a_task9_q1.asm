[org 0x0100]

jmp start

num1: dw 48
num2: dw 18
gcd_result: dw 0

start:
    mov ax, [num1]
    mov bx, [num2]

commonFactor:
    cmp bx, 0           ; until remainder!=0 which is stored in bx
    je end

    xor dx, dx
    div bx

    mov ax, bx                  
    mov bx, dx
    jmp commonFactor

end:

mov [gcd_result], ax

mov ax, 0x4c00
int 0x21