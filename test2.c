#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long popcount(void *s, long count);
long popcount_sse4(void *s, long count);

static void rand_buf(char *buf, int count)
{
    int i;
    for (i = 0; i < count; ++i)
    {
        buf[i] = (char)(rand() & 0xFF);
    }
}

static void bench_mark(
        const char *label,
        long (*func)(void *, long),
        char *buf,
        int count)
{
    clock_t start, end;
    long retval;
    int i;

    retval = (*func)(buf, count);
    start = clock();
    for (i = 0; i < 100; ++i)
        (*func)(buf, count);
    end = clock();
    printf("%s: %d clock (retval=%d)\n", label, end - start, retval);
}

int
main(int argc, char** argv)
{
    srand(time(NULL));
    int count = 1000 * 1000 * 100;
    if (argc >= 2)
        count = atoi(argv[1]);
    printf("count=%d\n", count);

    char *buf = (char *)malloc(count);
    if (!buf)
        return 1;
    rand_buf(buf, count);
    printf("initialized.\n");

    bench_mark("popcount", popcount, buf, count);
    bench_mark("popcount_sse4", popcount_sse4, buf, count);

    return 0;
}
