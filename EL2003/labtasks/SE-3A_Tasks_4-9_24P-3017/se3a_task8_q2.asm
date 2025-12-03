[org 0x0100]

jmp start

data: dw 8, 3, 12, 7, 5
temp: 0

start:
    mov ax, [data+1]        
    mov [temp], ax
    mov ax, [data+2]
    mov [data+1], ax
    mov ax, [temp]
    mov [data+2], ax

    mov ax, 0x4c00
    int 0x21

; wow i figured this out earlier for no reason at all 
; well can't say it was for "no reason" now