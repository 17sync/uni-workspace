[org 0x0100]

jmp start

data: db 5, 3, 5, 7, 5, 2, 5
freq_count: db 0

start:
    mov cl, 0       ; loop counter plus shifter
    mov al, 5
    mov bl, 0       ; repitition counter

    countRepititions:
        cmp al, [data+cx]
        jne skip

        inc bl      ; could also do inc byte[freq_count] but manually incrementing is easier to follow

        skip:
        add cl, 2
        cmp cl, 14
        
        jne countRepititions

    mov [freq_count], bl 

    mov ax, 0x4c00
    int 0x21