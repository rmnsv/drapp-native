//
// Created by samea on 01.06.2021.
//

#ifndef DRAPP_NATIVE_SOUND_GENERATOR_WRAPPER_H
#define DRAPP_NATIVE_SOUND_GENERATOR_WRAPPER_H

#include "sound-generator.h"

using namespace DrappNative::Sound;

extern "C" {
    typedef void (__stdcall * SoundGeneratorCallBack)(unsigned char*, int);

    Generator* CreateSoundGeneratorClass(int sampleRate);
    void DisposeSoundGeneratorClass(Generator* ptr);
    void TestGetSineWave16BitPcm(Generator *ptr, int samples, double frequencyOfTone, SoundGeneratorCallBack callBack);
}

#endif //DRAPP_NATIVE_SOUND_GENERATOR_WRAPPER_H
