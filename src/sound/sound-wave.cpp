//
// Created by samea on 04.06.2021.
//

#include "sound-wave.h"

namespace DrappNative {
    namespace Sound {
        SoundWave::SoundWave() = default;

        SoundWave::SoundWave(unsigned char *wave, int size) {
            _wave = wave;
            _size = size;
        }

        SoundWave::~SoundWave() = default;

        unsigned char* SoundWave::getWave() {
            return _wave;
        }

        int SoundWave::getSize() {
            return _size;
        }
    }
}