[org 0x0100]

jmp start

numbers: dw 15, 25, 35, 45, 55
in_range: db 0

start:
    mov cx, 0               ; shifer plus loop counter
    mov bl, 0               ; in_range counter

    rangeCheck:
        mov ax, [numbers+cx]
        cmp ax, 20
        jb outOfRange

        cmp ax, 40
        ja outOfRange

        inc bl              ; only if ax!<20 && ax!>40 (which is similar to 20<=ax<=40)

        outOfRange:
        add cx, 2
        cmp cx, 10

        jne rangeCheck

    mov [in_range], bl

    mov ax, 0x4c00
    int 0x21
        