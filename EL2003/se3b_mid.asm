[org 0x0100]

    jmp start

    baseTimes: dw 120, 105, 130, 95, 150, 100
    violations: db 1, 3, 0, 2, 1, 4
    finalTimes: dw 0, 0, 0, 0, 0, 0
    fastestTime: dw 0

    start:
    mov cx, 0 
    
    calculateFinalTimes:
        xor ax, ax
        mov al, 5

        mov bl, [violations+cx]
        mul bl

        add ax, [baseTimes+cx]
        mov [finalTimes+cx], ax

        add cx, 1
        cmp cx, 6
        jne calculateFinalTimes

    mov cx, 0
    xor ax, ax
    mov ax, [finalTimes]

    findFastestTime:
        mov bx, [finalTimes+cx]
        cmp ax, bx

        jae noswap

        mov ax, bx

        noswap:
        add cx, 2
        cmp cx, 12
        jne findFastestTime

    mov [fastestTime], ax

    mov ax, 0x4c00
    int 0x21