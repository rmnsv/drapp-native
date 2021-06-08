//
// Created by samea on 04.06.2021.
//

#ifndef DRAPP_NATIVE_SOUND_WAVE_H
#define DRAPP_NATIVE_SOUND_WAVE_H

namespace DrappNative {
    namespace Sound {
        class SoundWave {
        private:
                unsigned char* _wave;
                int _size;
        public:
            SoundWave();
            SoundWave(unsigned char* wave, int size);
            ~SoundWave();
            unsigned char* getWave();
            int getSize();
        };
    }
}

#endif //DRAPP_NATIVE_SOUND_WAVE_H
