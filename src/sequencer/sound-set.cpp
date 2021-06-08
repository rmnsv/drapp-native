#include "sound-set.h"
#include <iostream>

namespace SequencerNative {

    SoundSet::SoundSet() {
        _name = "Noname";
    }

    SoundSet::SoundSet(string newName) {
        _name = newName;
    }

    SoundSet::SoundSet(SoundSet &refTrack) {
        _name = refTrack._name;
    }

    SoundSet::~SoundSet() {}

    string SoundSet::getName() {
        return _name;
    }

    void SoundSet::setName(string newName) {
        _name = newName;
    }

    void SoundSet::playSound(int index) {
        std::cout << "    Playing " << index << " of " + _name << std::endl;
    }
}