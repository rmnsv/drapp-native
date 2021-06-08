#include "metronome.h"

using namespace DrappNative;

extern "C" {
    Metronome* CreateMetronome();
    void DisposeMetronome(Metronome* ptr);
    //double DrumMathBpmToMs(DrumMath *ptr, int bpm);
}