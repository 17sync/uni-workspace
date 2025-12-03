[org 0x0100]

jmp start

arr1: db 1, 3, 9, 2, 4, 8, 7, 1, 6, 5     
arr2: db 11, 8, 4, 9, 3, 5, 8             

sum1: dw 0                                
min2: db 0                                
result: db 0                             

start:
    mov cx, 5                              ; first half=5 
    mov si, arr1
    mov ax, 0
s1:
    add al, [si]                           ; byte into AX
    adc ah, 0                              ; carry into AH
    inc si                                 ; next element
    dec cx
    jnz s1
    mov [sum1], ax

    mov cx, 5                              ; next 5
    mov ax, 0
s2:
    add al, [si]
    adc ah, 0
    inc si
    dec cx
    jnz s2
    mov [sum2], ax

    mov bl, [arr2]                         ; assume first element is min
    mov cx, 7
    mov si, arr2
m1:
    mov al, [si]                           ; load current element
    cmp al, bl
    jae m2                                 ; if al>=min, skip
    mov bl, al                             ; al is new minimum
m2:
    inc si
    dec cx
    jnz m1
    mov [min2], bl

    mov ax, [sum1]
    mov dx, [sum2]
    cmp ax, dx
    ja g1                                  ; if sum1>sum2, keep AX
    mov ax, dx                             ; otherwise use sum2
g1:
    mov bl, [min2]
    xor dx, dx                             
    div bl                                 
    mov [result], al

    mov ax, 0x4c00
    int 0x21
