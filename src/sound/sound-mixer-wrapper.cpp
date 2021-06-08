//
// Created by samea on 05.06.2021.
//

#include "sound-mixer-wrapper.h"
#include "sound-generator.h"

Mixer* CreateSoundMixerClass()
{
    return new Mixer();
}

void DisposeSoundMixerClass(Mixer* ptr) {
    if (ptr != nullptr)
    {
        delete ptr;
        ptr = nullptr;
    }
}

void TextMix2SinWaves(Mixer *ptr, int samplesCount1, double frequencyOfTone1, float gain1, int samplesCount2, double frequencyOfTone2, float gain2, SoundMixerCallBack callBack) {
    Generator* generator = new Generator(16000);

    vector<double> wave1 = generator->getSineWave(samplesCount1, frequencyOfTone1);
    vector<unsigned char> sound1 = generator->get16BitPcm(wave1);

    vector<double> wave2 = generator->getSineWave(samplesCount2, frequencyOfTone2);
    vector<unsigned char> sound2 = generator->get16BitPcm(wave2);

    vector<unsigned char> result = ptr->mix(sound1, gain1, sound2, gain2);

    if (callBack) {
        callBack(result.data(), result.size());
    }
}

void TextMixSinWaveWithSoundSample(Mixer *ptr, int samples1, double frequencyOfTone1, float gain1, unsigned char* wave2, int size2, float gain2, SoundMixerCallBack callBack) {
    Generator* generator = new Generator(16000);

    vector<double> wave1 = generator->getSineWave(samples1, frequencyOfTone1);
    vector<unsigned char> sound1 = generator->get16BitPcm(wave1);

    vector<unsigned char> sound2;
    sound2.resize(size2);
    for (int i = 0; i < size2; i++) {
        sound2[i] = wave2[i];
    }

    vector<unsigned char> result = ptr->mix(sound1, gain1, sound2, gain2);

    if (callBack) {
        callBack(result.data(), result.size());
    }
}

void TextMix2SoundSamples(Mixer *ptr, unsigned char* wave1, int size1, float gain1, unsigned char* wave2, int size2, float gain2, SoundMixerCallBack callBack) {
    vector<unsigned char> sound1;
    sound1.resize(size1);
    for (int i = 0; i < size1; i++) {
        sound1[i] = wave1[i];
    }

    vector<unsigned char> sound2;
    sound2.resize(size2);
    for (int i = 0; i < size2; i++) {
        sound2[i] = wave2[i];
    }

    vector<unsigned char> result = ptr->mix(sound1, gain1, sound2, gain2);

    if (callBack) {
        callBack(result.data(), result.size());
    }
}