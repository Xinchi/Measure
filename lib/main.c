#include "tsc.h"
#include <stdio.h>

int main()
{
    unsigned long diff;
    diff = test_tsc_overhead();
    printf("%ld\n",diff);
    return 0;
}
