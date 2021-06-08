//
// Created by samea on 03.06.2021.
//

#ifndef DRAPP_NATIVE_SOUND_PROVIDER_WRAPPER_H
#define DRAPP_NATIVE_SOUND_PROVIDER_WRAPPER_H

#include "sound-provider.h"

using namespace DrappNative::Sound;

extern "C" {
    typedef void (__stdcall * SoundProviderCallBack)(unsigned char*, int);

    Provider* CreateSoundProviderClass();
    void DisposeSoundProviderClass(Provider* ptr);
    int PutSound(Provider *ptr, unsigned char* wave, int size);
    void GetSound(Provider *ptr, int id, SoundProviderCallBack callBack);
}

#endif //DRAPP_NATIVE_SOUND_PROVIDER_WRAPPER_H
