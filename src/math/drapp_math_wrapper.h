#include "drapp_math.h"

using namespace DrappNative;

extern "C" {
    DrumMath* CreateDrumMathClass();
    void DisposeDrumMathClass(DrumMath* ptr);
    double DrumMathBpmToMs(DrumMath *ptr, int bpm);
}