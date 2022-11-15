// include the libraries
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "fastmod.h"

// use the fastmod namespace
using namespace fastmod;

//start 64-bit fastmod for 64-bit cpu
bool testunsigned64(uint64_t min, uint64_t max, bool verbose)
{
    for (uint64_t d = min; (d <= max) && (d >= min); d++)
    {
        if (d == 0)
        {
            // print skipping 0
            printf("skipping d = 0\n");
            continue;
        }

        __uint128_t M64 = computeM_u64(d);
        if (verbose)
        {
            // print the M64 value
            printf("d = %" PRIu64 " (unsigned 64-bit) ", d);
        }
        else
        {   
            // print .
            printf(".");
        }
        fflush(NULL);
        for (uint64_t a64 = UINT64_C(0x10000000000000) /* 1 << 52 */; a64 < UINT64_C(0x10000000000000) + UINT64_C(0x10000); ++a64)
        {
            uint64_t computedFastMod = fastmod_u64(a64, M64, d);
            uint64_t computedMod = a64 % d;
            if (computedMod != computedFastMod)
            {
                // print error
                printf("(bad u64 fastmod) problem with divisor %" PRIu64 " and dividend %" PRIu64 " \n",d, a64);
                printf("expected %" PRIu64 " mod %" PRIu64 " =%" PRIu64 " \n", a 64, d, computedMod);
                printf("got %" PRIu64 " mod %" PRIu64 " =%" PRIu64 " \n", a 64, d, computedFastMod);
                return false;
            }
        }
        if (verbose)
        {
            // print ok
            printf("ok!\n");
        }
    }
    if (verbose)
    {
        // print the interval
        printf("Unsigned 64-bit fastmod test passed with divisor in interval[%" PRIu64 ", %" PRIu64 "].\n", min, max);
    }
    
    return true;
}

