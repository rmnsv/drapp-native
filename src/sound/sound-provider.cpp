//
// Created by samea on 03.06.2021.
//

#include "sound-provider.h"

namespace DrappNative {
    namespace Sound {
        Provider::Provider() = default;

        Provider::~Provider() = default;

        int Provider::putSound(unsigned char* wave, int size) {
            int nextId = _sounds.size();
            SoundWave* newSoundWave = new SoundWave(wave, size);
            _sounds[nextId] = *newSoundWave;
            return nextId;
        }

        SoundWave Provider::getSound(int id) {
            if (_sounds.find(id) != _sounds.end()) {
                return _sounds[id];
            } else {
                exit(-1);
            }
        }
    }
}