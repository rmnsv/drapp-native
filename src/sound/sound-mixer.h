//
// Created by samea on 05.06.2021.
//

#ifndef DRAPP_NATIVE_SOUND_MIXER_H
#define DRAPP_NATIVE_SOUND_MIXER_H

#include "sound-wave.h"
#include <vector>

using namespace std;

namespace DrappNative {
    namespace Sound {
        class Mixer {
        private:
            char clip(float input);
        public:
            Mixer();
            ~Mixer();
            vector<unsigned char> mix(vector<unsigned char> wave1, float gain1, vector<unsigned char> wave2, float gain2);
        };
    }
}

#endif //DRAPP_NATIVE_SOUND_MIXER_H
