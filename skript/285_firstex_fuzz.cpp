#include "285_firstex.h"
 #include <cstddef>
 #include <cstdint>

 extern "C"
 int LLVMFuzzerTestOneInput(const uint8_t *Data,
 size_t Size) {
 int val = 0;
for (size_t i=0; i < Size; ++i) {
 val += Data[i]; // alles einfliessen lassen
 }
 fun(val);
 return 0;
 }
