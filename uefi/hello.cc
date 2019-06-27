#include "efi.h"

void efi_main(Handle image_handle, SystemTable* system_table) {
  efi_system_table = system_table;
  puts("Hello, world! From UEFI!");
  for(;;);
};
