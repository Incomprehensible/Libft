#include "bitlib.h"

ULONG   bit_popcount(ULONG targ)
{
    struct BMASK MSK;

    memset(MSK, 0, sizeof(MSK));
    MSK.M5 = ~((-1) << 32);
    MSK.M4 = MSK.M5 ^ (MSK.M5 << 16);
    MSK.M3 = MSK.M4 ^ (MSK.M4 << 8);
    MSK.M2 = MSK.M3 ^ (MSK.M3 << 4);
    MSK.M1 = MSK.M2 ^ (MSK.M2 << 2);
    MSK.M0 = MSK.M1 ^ (MSK.M1 << 1);

    targ = ((targ >> 1) & MSK.M0) + (targ & MSK.M0);
    targ = ((targ >> 2) & MSK.M1) + (targ & MSK.M1);
    targ = ((targ >> 4) + targ) & MSK.M2;
    targ = ((targ >> 8) + targ) & MSK.M3;
    targ = ((targ >> 16) + targ) & MSK.M4;
    targ = ((targ >> 32) + targ) & MSK.M5;
    return (targ);
}
