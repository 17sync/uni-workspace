[org 0x0100]

jmp start

matrix: dw 1, 2, 3, 4, 5, 6
element: dw 0                   ; [matrix + (row x columns + column) x 2] = [matrix + 10] = 6

start:
    mov bx, matrix
    mov ax, 1           ; row
    mov cx, 3           ; columns

    mul cx              ; row x columns 
    add ax, 2           ; row x columns + column

    shl ax              ; (row x columns + column) x 2
    add bx, ax          ; matrix + (row x columns +column) x 2 :. bx now points to [matrix + 10] 

    mov ax, [bx]        
    mov [element], ax

    mov ax, 0x4c00
    int 0x21