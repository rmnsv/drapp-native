//
// Created by samea on 01.06.2021.
//

#include "sound-generator-wrapper.h"

Generator* CreateSoundGeneratorClass(int sampleRate)
{
    return new Generator(sampleRate);
}

void DisposeSoundGeneratorClass(Generator* ptr) {
    if (ptr != nullptr)
    {
        delete ptr;
        ptr = nullptr;
    }
}

void TestGetSineWave16BitPcm(Generator *ptr, int samples, double frequencyOfTone, SoundGeneratorCallBack callBack) {
    vector<unsigned char> sound = ptr->get16BitPcm(ptr->getSineWave(samples, frequencyOfTone));
    if (callBack) {
        callBack(sound.data(), sound.size());
    }
}