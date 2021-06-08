//
// Created by samea on 03.06.2021.
//

#include "sound-provider-wrapper.h"

Provider* CreateSoundProviderClass() {
    return new Provider();
}

void DisposeSoundProviderClass(Provider* ptr) {
    if (ptr != nullptr) {
        delete ptr;
        ptr = nullptr;
    }
}

int PutSound(Provider *ptr, unsigned char* wave, int size) {
    return ptr->putSound(wave, size);
}

void GetSound(Provider *ptr, int id, SoundProviderCallBack callBack) {
    SoundWave wave = ptr->getSound(id);
    if (callBack) {
        callBack(wave.getWave(), wave.getSize());
    }
}