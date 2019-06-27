// Based on https://dev.krzaq.cc/post/writing-cpp17-for-16bit-x86/
void hello() {
  const char* s = "Hello, world!";
  char* textBuffer = reinterpret_cast<char*>(0xB8000);
  // This code will not run successfuly on the real machine
  // because it is accessing addr 0xB8000 which is beyond the segment limit (64KiB)
  // However, This code works on QEMU because QEMU does not check the segment limit every time...
  while (*s) {
    *textBuffer = *s;
    textBuffer += 2;
    s++;
  }
  for (;;) {
  }
}
