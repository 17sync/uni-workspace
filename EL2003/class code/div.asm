[org 0x0100]

	mov ax,[num1]
	mov bl , [num2]
	div bl

	mov [result], ax

	mov ax, 0x4c00
	int 0x21


num1: dw 10
num2: db 2
result: dw 0

