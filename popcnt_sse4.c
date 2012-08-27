#include <stdint.h>
#include <memory.h>

/* 32bits version. */
long popcount_sse4(void *s, long count)
{
    long n = 0;

    while (count >= sizeof(uint32_t))
    {
        __asm__("popcnt %1,%%eax\n\t"
                "add %%eax,%0\n\t"
                : "+r"(n)
                : "r"(*(uint32_t*)s)
                : "eax");

        count -= sizeof(uint32_t);
        s += sizeof(uint32_t);
    }

    uint32_t remain = 0;
    memcpy(&remain, s, count);
    __asm__("popcnt %1,%%eax\n\t"
            "add %%eax,%0\n\t"
            : "+r"(n)
            : "r"(remain)
            : "eax");

    return n;
}
