#include <stdio.h>

long popcount(void *s, long count);
long popcount_sse4(void *s, long count);

int
main(int argc, char** argv)
{
    int data = 0xaa;

    printf("popcount()=%d\n", popcount(&data, sizeof(data)));
    printf("popcount_sse4()=%d\n", popcount_sse4(&data, sizeof(data)));

    return 0;
}
