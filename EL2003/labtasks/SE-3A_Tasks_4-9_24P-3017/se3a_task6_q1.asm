[org 0x0100]

jmp start

marks: db 75
letter_grade: db 0

start:
    mov al, [marks]

    cmp al, 85
    jae A 
    cmp al, 70
    jae B 
    cmp al, 60
    jae C 
    
    mov [letter_grade], 70      ; F
    jmp end 
    A: mov [letter_grade], 65   ; A
    jmp end 
    B: mov [letter_grade], 66   ; B
    jmp end 
    C: mov [letter_grade], 67   ; C
    jmp end

    end:

    mov ax, 0x4c00
    int 0x21