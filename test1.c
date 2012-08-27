#include <stdio.h>
#include <string.h>

long popcount(void *s, long count);
long popcount_sse4(void *s, long count);

int
main(int argc, char** argv)
{
    char data[] = "Hello World! Hello POPCOUNT!";

    int len = strlen(data);
    if (argc >= 2) {
        len = atoi(argv[1]);
    }

    printf("len=%d\n", len);
    printf("popcount()=%d\n", popcount(data, len));
    printf("popcount_sse4()=%d\n", popcount_sse4(data, len));

    return 0;
}
