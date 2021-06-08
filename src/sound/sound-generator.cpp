//
// Created by samea on 31.05.2021.
//

#include "sound-generator.h"

#include "sound-set.h"
#include <array>
#include <cmath>
#include <climits>

namespace DrappNative {
    namespace Sound {
        Generator::Generator() {
            _sampleRate = 8000;
        }

        Generator::Generator(int sampleRate) {
            _sampleRate = sampleRate;
        }

        Generator::~Generator() = default;

        vector<double> Generator::getSineWave(int samples, double frequencyOfTone) {
            vector<double> wave;
            wave.reserve(samples);
            for (int i = 0; i < samples; i++) {
                wave.push_back(sin(2 * PI * i / (_sampleRate / frequencyOfTone)));
            }
            return wave;
        }

        vector<unsigned char> Generator::get16BitPcm(vector<double> wave) {
            vector<unsigned char> generatedSound;
            int waveSize = wave.size();
            generatedSound.resize(waveSize * 2);
            int index = 0;
            for (int i = 0; i < waveSize; i++) {
                // scale to maximum amplitude
                auto maxSample = (short) ((wave[i] * SHRT_MAX));
                // in 16 bit wav PCM, first byte is the low order byte
                generatedSound.at(index++) = (unsigned char) (maxSample & 0x00ff);
                generatedSound.at(index++) = (unsigned char) ((maxSample & 0xff00) >> 8);

            }
            return generatedSound;
        }
    }
}