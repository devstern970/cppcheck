// Test with command:
// ./cppcheck --addon=misra --inline-suppr addons/test/misra/misra-ctu-*-test.c

#include "misra-ctu-test.h"

MISRA_2_3_B  misra_2_3_b;

// cppcheck-suppress misra-c2012-5.6
typedef int MISRA_5_6_VIOLATION;
static MISRA_5_6_VIOLATION misra_5_6_x;

