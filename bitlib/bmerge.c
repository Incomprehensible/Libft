#include "bitlib.h"
#define SIGNED

// note: use version with branching on machines using clang -03 for more optimization
// takes two sorted arrays and merges them into one

void bit_merge_sorted(ULONG * restrict A, ULONG * restrict B, ULONG * restrict C,
        size_t asz, size_t bsz)
{
    ULONG min;
    ULONG cmp;

    while (asz && bsz)
    {
        cmp = (*A <= *B);
        bit_set_min(&min, *A, *B);
        *C++ = min;
        A += cmp;
        B += !cmp;
        asz -= cmp;
        bsz -= !cmp;
    }
    while (asz--)
        *C++ = *A++;
    while (bsz--)
        *C++ = *B++;
}
