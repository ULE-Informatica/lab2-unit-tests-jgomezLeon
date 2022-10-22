#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h> 

unsigned int wrapFunctionAdd(unsigned int ui_a, unsigned int ui_b) {
  unsigned int usum;
  if (UINT_MAX - ui_a < ui_b) {
    fprintf(stderr,"Wrap in wrapFunctionAdd \n");
    return -1;
  }

  usum = ui_a + ui_b;
  return usum;
  
  
}

unsigned int wrapFunctionMul(unsigned int ui_a, unsigned int ui_b) {
  if (ui_a != 0  && (ui_b > (UINT_MAX/ui_a))) {
    fprintf(stderr,"Wrap in wrapFunctionMul \n");
    return -1;
  }
  unsigned umul = ui_a;
  umul *= ui_b;
  return umul;
}

uint32_t wrapFunctionShift(uint32_t ui_a, unsigned int ui_b) {
  if (ui_b >= __builtin_popcount(UINT_MAX) - __builtin_popcount(ui_a))
  {
    fprintf(stderr,"Wrap in wrapFunctionShift \n");
    return -1;
  }
  uint32_t uShift = ui_a << ui_b | ui_a >> (32 - ui_b); 
  return uShift;
}
