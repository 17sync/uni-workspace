[org 0x0100]

jmp start

number: dw 1234
digit_sum: dw 0

start:
    mov ax, [number]
    mov bx, 10
    mov cx, 0               ; holds sum

    sumDigits:
        xor dx, dx
        
        div bx
        add cx, dx

        cmp ax, 0           ; while(quotient!=0)
        jne sumDigits

    mov [digit_sum], cx

    mov ax, 0x4c00
    int 0x21