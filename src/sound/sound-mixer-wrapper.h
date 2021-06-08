//
// Created by samea on 05.06.2021.
//

#ifndef DRAPP_NATIVE_SOUND_MIXER_WRAPPER_H
#define DRAPP_NATIVE_SOUND_MIXER_WRAPPER_H

#include "sound-mixer.h"

using namespace DrappNative::Sound;

extern "C" {
    typedef void (__stdcall * SoundMixerCallBack)(unsigned char*, int);

    Mixer* CreateSoundMixerClass();
    void DisposeSoundMixerClass(Mixer* ptr);
    void TextMix2SinWaves(Mixer *ptr, int samplesCount1, double frequencyOfTone1, float gain1, int samplesCount2, double frequencyOfTone2, float gain2, SoundMixerCallBack callBack);
    void TextMixSinWaveWithSoundSample(Mixer *ptr, int samples1, double frequencyOfTone1, float gain1, unsigned char* wave2, int size2, float gain2, SoundMixerCallBack callBack);
    void TextMix2SoundSamples(Mixer *ptr, unsigned char* wave1, int size1, float gain1, unsigned char* wave2, int size2, float gain2, SoundMixerCallBack callBack);
}

#endif //DRAPP_NATIVE_SOUND_MIXER_WRAPPER_H
