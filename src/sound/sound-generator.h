//
// Created by samea on 31.05.2021.
//

#include <vector>

#ifndef DRAPP_NATIVE_SOUND_GENERATOR_H
#define DRAPP_NATIVE_SOUND_GENERATOR_H

#define PI 3.14159265

using namespace std;

namespace DrappNative {
    namespace Sound {
        class Generator {
        private:
            int _sampleRate;
        public:
            Generator();
            explicit Generator(int sampleRate);
            ~Generator();
            vector<double> getSineWave(int samples, double frequencyOfTone);
            vector<unsigned char> get16BitPcm(vector<double> wave);
    };
} }

#endif //DRAPP_NATIVE_SOUND_GENERATOR_H
