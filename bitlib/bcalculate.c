#include "bitlib.h"

ULONG   bit_bmodulo(ULONG x, ULONG z)
{
    ULONG res;

    res = x - (z & -(x >= z));
    return (res);
}

void    bit_round_to_pow2(ULONG *n)
{
    --(*n);
    *n |= *n >> 1;
    *n |= *n >> 2;
    *n |= *n >> 4;
    *n |= *n >> 8;
    *n |= *n >> 16;
    *n |= *n >> 32;
    ++(*n);
}

