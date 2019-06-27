CXX=/usr/local/opt/llvm/bin/clang++
LD=/usr/local/opt/llvm/bin/ld.lld
hello.bin : hello.o hello.ld
	$(LD) \
		--oformat binary \
		-T hello.ld \
		-o $@ hello.o
	hexdump -C $@
hello.o : hello.cc
	$(CXX) -c --target=x86_64-elf \
		-nostdlib -fomit-frame-pointer \
		-fno-builtin -nodefaultlibs \
		-Oz -std=c++17 -m16 hello.cc -o $@
run : hello.bin
	qemu-system-x86_64 -hda hello.bin
clean : 
	-rm *.o
	-rm *.bin
