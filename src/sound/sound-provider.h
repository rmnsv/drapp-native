//
// Created by samea on 03.06.2021.
//

#ifndef DRAPP_NATIVE_SOUND_PROVIDER_H
#define DRAPP_NATIVE_SOUND_PROVIDER_H

#include <map>
#include "sound-wave.h"

using namespace std;

namespace DrappNative {
    namespace Sound {
        class Provider {
        private:
            map<int, SoundWave> _sounds;
        public:
            Provider();
            ~Provider();
            int putSound(unsigned char* wave, int size);
            SoundWave getSound(int id);
        };
    }
}

#endif //DRAPP_NATIVE_SOUND_PROVIDER_H
