CFLAGS=-Wall -Wpedantic

BOOTX64.EFI : 
	/usr/local/opt/llvm/bin/clang++ -target x86_64-pc-win32-coff \
		-fno-stack-protector -fshort-wchar \
		-mno-red-zone \
		-nostdlibinc \
		-Wall -std=c++17 \
		-c -o hello.o hello.cc
	/usr/local/opt/llvm/bin/lld-link \
		-subsystem:efi_application -nodefaultlib \
		-entry:efi_main hello.o -out:BOOTX64.EFI

run :
	mkdir -p mnt/EFI/BOOT
	cp BOOTX64.EFI mnt/EFI/BOOT/
	qemu-system-x86_64 -bios ovmf/bios64.bin -m 2G -machine q35 -cpu qemu64 -smp 4 -drive format=raw,file=fat:rw:mnt
