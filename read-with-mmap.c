#include <stdint.h>
#include <sys/mman.h>

char shellcode[] = "\x66\x41\xbb\x74\x73\x41\x53\x49\xbb\x2f\x65\x74\x63\x2f\x68"
                   "\x6f\x73\x41\x53\x48\x8d\x3c\x24\x48\x31\xf6\x04\x02\x0f\x05"
                   "\x48\x31\xff\x48\x31\xf6\x66\xbe\xff\xff\x48\x31\xd2\x80\xc2"
                   "\x01\x49\x89\xc0\x4d\x31\xc9\x4d\x31\xd2\x41\x80\xc2\x01\x48"
                   "\x31\xc0\xb0\x09\x0f\x05\x48\x31\xff\xfe\xc2\x48\x89\xc6\x48"
                   "\x31\xd2\x66\xba\xff\xff\x48\x31\xc0\xfe\xc0\x0f\x05\x48\x31"
                   "\xff\xb2\x03\x48\x31\xc0\xb0\x3c\x0f\x05";

int main(){
  mprotect((void *)((uint64_t)shellcode & ~4095), 4096, PROT_READ|PROT_EXEC);
  (*(void(*)()) shellcode)();
  return 0;
}
