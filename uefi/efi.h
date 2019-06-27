#include <stdint.h>

typedef void* Handle;
typedef uint64_t UINTN;

struct TableHeader {
  uint64_t signature;
  uint32_t revision;
  uint32_t header_size;
  uint32_t crc32;
  uint32_t reserved;
};

class SimpleTextInputProtocol;
class RuntimeServices;
class BootServices;
class ConfigurationTable;

int main();

struct SimpleTextOutputProtocol {
  uint64_t _buf;
  uint64_t (*output_string)(SimpleTextOutputProtocol*, const wchar_t*);
  uint64_t (*test_string)(SimpleTextOutputProtocol*, wchar_t*);
  uint64_t (*query_mode)(SimpleTextOutputProtocol*,
                         wchar_t*,
                         uint64_t* columns,
                         uint64_t* rows);
  uint64_t (*set_mode)(SimpleTextOutputProtocol*, uint64_t);
  uint64_t (*set_attribute)(SimpleTextOutputProtocol*, uint64_t Attribute);
  uint64_t (*clear_screen)(SimpleTextOutputProtocol*);
};

struct SystemTable {
  TableHeader header;
  wchar_t* firmware_vendor;
  uint32_t firmware_revision;
  Handle console_in_handle;
  SimpleTextInputProtocol* con_in;
  Handle console_out_handle;
  SimpleTextOutputProtocol* con_out;
  Handle standard_error_handle;
  SimpleTextOutputProtocol* std_err;
  RuntimeServices* runtime_services;
  BootServices* boot_services;
  UINTN number_of_table_entries;
  ConfigurationTable* configuration_table;
};

SystemTable *efi_system_table;

void EFIPutChar(wchar_t c) {
  wchar_t buf[2];
  buf[0] = c;
  buf[1] = 0;
  efi_system_table->con_out->output_string(efi_system_table->con_out, buf);
}

void puts(const char *s) {
  while(*s) {
    EFIPutChar(*s);
    s++;
  }
}

