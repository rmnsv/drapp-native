#ifndef SOUNDSET_H
#define SOUNDSET_H

#include <string>

using namespace std;

namespace SequencerNative {
    class SoundSet {
    private:
        string _name;
    public:
        SoundSet();
        SoundSet(string newName);
        SoundSet(SoundSet &refTrack);
        ~SoundSet();
        string getName();
        void setName(string newName);
        void playSound(int index);
    };
}

#endif