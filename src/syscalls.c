#include <sys/stat.h>

// Minimal heap stub for newlib — no dynamic allocation, just satisfies the linker
void* _sbrk(int incr) {
    extern char _end;           // defined in your linker script
    static char* heap_end = 0;
    if (heap_end == 0) heap_end = &_end;
    heap_end += incr;
    return (void*)(heap_end - incr);
}