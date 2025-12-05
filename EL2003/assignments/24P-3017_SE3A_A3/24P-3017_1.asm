[org 0x100]

jmp start

n  : dw 6        
sum : dw 0        

factorial:
    mov ax, 1         
    cmp cx, 0
   je done
   
fact_loop:
    mul cx             
    loop fact_loop
    
done:
    ret

summation:
    xor bx, bx         
    mov si, 1  
           
sum_loop:
    mov cx, si         
    call factorial     
    add bx, ax         
     inc si 
    
   cmp si, [n]       
     jbe sum_loop      
    mov [sum], bx     
     ret

start:
    call summation   
      
  mov ax, 0x4C00     
  int 0x21