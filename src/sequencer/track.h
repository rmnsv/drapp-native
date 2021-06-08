#include "sound-set.h"
#include <vector>
#include <iostream>

using namespace std;

namespace SequencerNative {
    class Track {

    private:
        friend class sequencer;
        
        SequencerNative::SoundSet *s_set;
        vector<int> notes;
        int _measurementsCount;

    public:
        Track();
        Track(int length);
        Track(int length, int measurementsCount);
        Track(const Track &refTrack);
        ~Track();

        Track& operator=(Track &rvalueTrack);

        void setNote(int index, int value);
        void playNoteAt(int index);
        void linkSoundSet(SequencerNative::SoundSet& newSoundSet);
        int getLength();
        string getSoundSetName();
    };
}