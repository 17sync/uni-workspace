[org 0x0100]

jmp start

arr: dw 1, 2, 3, 4, 5

start:
    mov cx, 0       ; shifter plus counter

    swapValues:
        mov ax, [arr+cx]
        mov dx, [arr+8-cx]

        mov [arr+8-cx], ax
        mov [arr+cx], dx

        add cx, 2
        cmp cx, 4
        
        jne swapValues

    mov ax, 0x4c00
    int 0x21

    
    ; if we use a memory location "temp" that is not a register
    ; mov ax, [arr+cx]
    ; mov [temp], ax
    ; mov ax, [arr+8-cx]
    ; mov [arr+cx], ax
    ; mov ax, [temp]
    ; mov [arr+8-cx], ax
    ; possible but tedious and i'd prefer not to use this method
    ; question says "temporary memory location" does not specify that it should be a "label" or "variable" 