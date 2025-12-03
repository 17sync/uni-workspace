[org 0x100]

jmp start

matrix: dw 3,8,12,3, 8,15,3,2, 2,11,7,3, 10,5,9,6
Nsize: dw 4

diagonalSum:
    xor ax, ax            ; AX=total sum
    xor bx, bx            ; BX=i=0
    mov dx, [Nsize]       ; DX=N

diagLoop:
    mov cx, bx            ; primary diagonal
    mov di, bx            ; DI=i
    mul dx               
    add ax, di            
    shl ax, 1             ; convert to byte offset
    mov di, ax
    add word ax, [si+di]  ; add primary element

    mov ax, dx            ; secondary diagnol
    dec ax               
    sub ax, bx            
    mul dx               
    add ax, bx            
    shl ax, 1             
    mov di, ax
    add word ax, [si+di]  ; add secondary element

    inc bx
    cmp bx, dx
    jl diagLoop        ; continue while i<N

    ret


start:
    mov si, matrix
    call diagonalSum

    mov ax, 0x4c00
    int 0x21
