SECTIONS
{
	. = 0x7c00;
	.text : { *(.text) }
	.data : {
		*(.data)
		*(.rodata)
		*(.bss)
	}
	.boot_signature : {
		FILL(0x00)
		. = 0x7dfe;
		BYTE(0x55)
		BYTE(0xAA)
	}
}

