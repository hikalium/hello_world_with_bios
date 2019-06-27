.intel_syntax noprefix

.text

mov ax, 0
mov ss, ax
mov sp, 0x7c00
mov ds, ax
mov es, ax

lea si, [msg]

puts:	// si: addr of string to put
	mov al, [si]
	inc si
	cmp al, 0
	je end_puts
	mov ah, 0x0e
	mov bx, 15
	int 0x10
	jmp puts
end_puts:

die:
	cli
	hlt
	jmp die
	

msg:
	.asciz "\nHello, world!\n"
