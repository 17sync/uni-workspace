[org 0x100]

jmp start

fib:
    cmp ax, 1
    jg recurse
    ret

recurse:
    push ax
    dec ax
    call fib
    mov bx, ax
    pop ax
    sub ax, 2
    call fib
    add ax, bx
    ret

start:
    mov cx, 7          ; N
    xor dx, dx         ; dx=i=0

next:
    mov ax,dx
    call fib
    push ax           ; store result on stack instead of memory

    inc dx
    cmp dx,cx
    jl next

    mov ax, 0x4c00       ; terminate program
    int 0x21
