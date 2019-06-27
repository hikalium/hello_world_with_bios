// Based on https://dev.krzaq.cc/post/writing-cpp17-for-16bit-x86/
void hello() {
  // text mode text buffer begins at 0xB8000
  const char* s = "Hello, world!";
  char* textBuffer = reinterpret_cast<char*>(0xB8000);
  while (*s) {
    *textBuffer = *s;
    textBuffer += 2;
    s++;
  }
  for (;;) {
  }
}
