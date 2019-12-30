#include "bitlib.h"

ULONG   bit_set_bit(ULONG targ, ULONG mask, ULLONG shift)
{
    return (targ | ((ULONG)1 << shift));
}
ULONG   bit_unset_bit(ULONG targ, ULONG mask, ULLONG shift)
{
    return (targ & ~((ULONG)1 << shift));
}

ULONG   bit_toggle_bit(ULONG targ, ULONG mask, ULLONG shift)
{
    return (targ ^ ((ULONG)1 << shift));
}

ULONG   bit_extract_bfield(ULONG targ, ULONG mask, ULLONG shift)
{
    return ((targ & mask) >> shift);
}

ULONG   bit_set_bfield(ULONG targ, ULONG src, ULONG mask, ULLONG shift)
{
    return ((targ & ~mask) | ((src << shift) & mask));
}

void    bit_bswap(ULONG *x, ULONG *y)
{
    *x ^= *y ^= *x;
}

void    bit_set_min(ULONG *targ, ULONG x, ULONG y)
{
    *targ = y ^ ((x ^ y) & -(x < y));
}