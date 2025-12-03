[org 0x0100]

	mov al,[num1]
	mov bl , [num2]
	mul bl

	mov [result], ax

	mov ax, 0x4c00
	int 0x21


num1: db 10
num2: db 2
result: dw 0

