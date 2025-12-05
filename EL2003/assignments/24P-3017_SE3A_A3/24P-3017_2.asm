[org 0x0100]

jmp start

rollNo: db '24P-3017' 
length: dw 8

clearScreen:
		mov word [es:di], 0x0720
		add di, 2
		cmp di, 1994               
		jne clearScreen
	ret

start:
	mov cx, [length]                   
	mov ax, 0xB800
	mov es, ax
	mov di, 0

	call clearScreen                  
	
	mov si, rollNo                    
	mov ah, 0x07                       

displayRollNo:
		mov al, [si]               
		mov [es:di], ax
		add di, 2                  
		add si, 1                  

		loop displayRollNo         

	call clearScreen

    mov ax, 0x4c00
    int 0x21