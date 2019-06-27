SECTIONS
{
	. = 0x7c00;
	.text 0x7c00 : { *(.text) }
	.data 0x7c00 : {
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

