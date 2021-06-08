//
// Created by samea on 05.06.2021.
//

#include "sound-mixer.h"
#include <climits>

namespace DrappNative {
    namespace Sound {
        Mixer::Mixer() = default;

        Mixer::~Mixer() = default;

        vector<unsigned char> Mixer::mix(vector<unsigned char> wave1, float gain1, vector<unsigned char> wave2, float gain2) {
            int size1 = wave1.size();
            int size2 = wave2.size();

            int sizeOfLonger = (size1 > size2) ? size1 : size2;

            vector<unsigned char> mixed;
            //vector<unsigned char> mixed_normalized;

            mixed.resize(sizeOfLonger);
            //mixed_normalized.resize(sizeOfLonger);

            //char peak = CHAR_MIN;

            for (int i = 0; i < sizeOfLonger; i++) {
                char mixedValue;
                if (i < size1 && i < size2) {
                    char value1 = wave1[i] - 128;
                    char value2 = wave2[i] - 128;
                    float gainedValue1 = gain1 * (float) value1;
                    float gainedValue2 = gain2 * (float) value2;
                    mixedValue = clip(gainedValue1 + gainedValue2);
                    /*
                    if (mixedValue > peak) {
                        peak = mixedValue;
                    }*/
                    mixed[i] = mixedValue + 128;
                } else if (i >= size1) {
                    char value = wave2[i] - 128;
                    float gainedValue = gain2 * (float) value;
                    mixed[i] = (char) gainedValue + (char) (128 * gain1);
                } else {
                    char value = wave1[i] - 128;
                    float gainedValue = gain1 * (float) value;
                    mixed[i] = (char) gainedValue + (char) (128 * gain2);
                }
            }

            /* seems like not working
            for (int i = 0; i < sizeOfLonger; i++) {
                mixed_normalized[i] = (CHAR_MAX * mixed[i] / peak) + 128;
            }
            */

            return mixed;
        }

        char Mixer::clip(float input) {
            if (input > CHAR_MAX)
                return CHAR_MAX;
            if (input < CHAR_MIN)
                return CHAR_MIN;
            return (char) input;
        }
    }
}