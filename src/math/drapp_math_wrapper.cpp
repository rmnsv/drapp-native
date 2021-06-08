#include "drapp_math_wrapper.h"

DrumMath* CreateDrumMathClass()
{
    return new DrumMath();
}

void DisposeDrumMathClass(DrumMath* ptr)
{
    if (ptr != nullptr)
    {
        delete ptr;
        ptr = nullptr;
    }
}

double DrumMathBpmToMs(DrumMath *ptr, int bpm)
{
    return ptr->BpmToMs(bpm);
}