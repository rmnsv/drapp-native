#include "metronome_wrapper.h"

Metronome* CreateMethonome()
{
    return new Metronome();
}

void DisposeMetronome(Metronome* ptr)
{
    if (ptr != nullptr)
    {
        delete ptr;
        ptr = nullptr;
    }
}

/*
double DrumMathBpmToMs(DrumMath *ptr, int bpm)
{
    return ptr->BpmToMs(bpm);
}*/