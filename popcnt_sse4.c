#include <stdint.h>
#include <memory.h>
#include <popcntintrin.h>

/* 32bits version. */
long popcount_sse4(void *s, long count)
{
    long n = 0;
    long c;
    uint32_t v;
    while (count >= sizeof(uint32_t))
    {
        v = *(uint32_t*)s;
        __asm__("popcnt %1,%0" : "=r"(c) : "r"(v));
        n += c;

        count -= sizeof(uint32_t);
        s += sizeof(uint32_t);
    }
    uint32_t remain = 0;
    memcpy(&remain, s, count);
    __asm__("popcnt %1,%0" : "=r"(c) : "r"(remain));
    return n + c;
}
