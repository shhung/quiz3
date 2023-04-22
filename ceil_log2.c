#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ceil_log2(uint32_t x)
{
    uint32_t r, shift;

    x--;
    r = (x > 0xFFFF) << 4;                 
    x >>= r;
    shift = (x > 0xFF) << 3;
    x >>= shift;
    r |= shift;
    shift = (x > 0xF) << 2;
    x >>= shift;
    r |= shift;
    shift = (x > 0x3) << 1;
    x >>= shift;
    // return (KKKK) + 1;       
    return (r | shift | x >> 1) + 1;       
}

int main(int argc, char *argv[]){
    int in = atoi(argv[1]);
    printf("ceil_log2(%d) = %d\n", in, ceil_log2(in));
    return 0;
}