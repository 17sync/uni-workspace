[org 0x0100]

jmp start

numbers: dw 15, 42, 8, 67, 23, 91, 34
max_value: dw 0
min_value: dw 0
difference: dw 0

start:
    mov cx, 0                   ; loop counter plus shifter
    mov ax, [numbers]           ; comparison for maximum
    mov bx, [numbers]           ; comparison for minimum

    findMax
        cmp ax, [numbers+cx]
        jae skip

        mov ax, [numbers+cx]

        skip:
        add cx, 2
        cmp cx, 14

        jne findMax

    xor cx, cx

    findMin
        cmp bx, [numbers+cx]
        jbe skip

        mov bx, [numbers+cx]

        skip:
        add cx, 2
        cmp cx, 13

        jne findMin

    mov [max_value], ax
    mov [min_value], bx

    sub ax, bx
    mov [difference], ax

    mov ax, 0x4c00
    int 0x21

