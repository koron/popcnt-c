#include <stdint.h>
#include <memory.h>

/*
 * http://stackoverflow.com/questions/6427473/how-to-generate-a-sse4-2-popcnt-machine-instruction
 */
long popcount_sse4(void *s, long count)
{
    long n = 0;
    while (count >= sizeof(uint64_t))
    {
        n += __builtin_popcountll(*((uint64_t*)s));
        count -= sizeof(uint64_t);
        s += sizeof(uint64_t);
    }
    uint64_t remain = 0;
    memcpy(&remain, s, count);
    return n + __builtin_popcountll(remain);
}
