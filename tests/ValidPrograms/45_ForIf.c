#include <stdint.h>

void main() {
   int32_t a;
   int32_t b;
   b = 1;
   for (a=0;a<10;a=a+1) {
      if (a%2==0) {
         b = b+1;
      }
   }
}
