#ifndef BITLIB_BITLIB_H
#define BITLIB_BITLIB_H

#include <string.h>

#define UNSIGNED

#ifdef UNSIGNED
#define U
typedef unsigned long ULONG;
typedef unsigned long long ULLONG;
#endif

#ifdef SIGNED
#define S
typedef long ULONG;
typedef long long ULLONG;
#endif

ULONG   bit_set_bit(ULONG targ, ULONG mask, ULLONG shift);
ULONG   bit_unset_bit(ULONG targ, ULONG mask, ULLONG shift);
ULONG   bit_toggle_bit(ULONG targ, ULONG mask, ULLONG shift);
ULONG   bit_extract_bfield(ULONG targ, ULONG mask, ULLONG shift);
ULONG   bit_set_bfield(ULONG targ, ULONG src, ULONG mask, ULLONG shift);
void    bit_bswap(ULONG *x, ULONG *y);
void    bit_set_min(ULONG *targ, ULONG x, ULONG y);
void    bit_merge_sorted(ULONG * restrict A, ULONG * restrict B, ULONG * restrict C,
                   size_t asz, size_t bsz);
ULONG   bit_bmodulo(ULONG x, ULONG z);
void    bit_round_to_pow2(ULONG *n);

#endif