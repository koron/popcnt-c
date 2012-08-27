#include <stdint.h>
#include <memory.h>
#include <smmintrin.h>

long popcount_gnu32(void *s, long count)
{
    long n = 0;

    while (count >= sizeof(uint32_t))
    {
        n += _mm_popcnt_u32(*(uint32_t*)s);
        count -= sizeof(uint32_t);
        s += sizeof(uint32_t);
    }

    uint32_t remain = 0;
    memcpy(&remain, s, count);
    n += _mm_popcnt_u32(remain);
    return n;
}

#ifdef __x86_64__
long popcount_gnu64(void *s, long count)
{
    long n = 0;

    while (count >= sizeof(uint64_t))
    {
        n += _mm_popcnt_u64(*(uint64_t*)s);
        count -= sizeof(uint64_t);
        s += sizeof(uint64_t);
    }

    uint64_t remain = 0;
    memcpy(&remain, s, count);
    n += _mm_popcnt_u64(remain);
    return n;
}
#endif
