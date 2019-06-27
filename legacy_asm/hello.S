.intel_syntax noprefix

.text

mov ax, 0
mov ss, ax
mov sp, 0x7c00
mov ds, ax
mov es, ax

lea si, [hello_msg]
hello_loop:	// si: addr of string to put
	mov al, [si]
	inc si
	cmp al, 0
	je hello_end
	mov bx, 15	// black bg, white fg
	mov ah, 0x0e
	int 0x10 // INT 0x10, AH=0x0E: Teletype output
	jmp hello_loop
hello_end:
	jmp die

hello_msg:
	.asciz "\nHello, world!\n"

die:
	cli
	hlt
	jmp die
	

