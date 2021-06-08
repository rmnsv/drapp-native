#include "doubly-linked-list.h"
#include <string>

namespace SequencerNative {
    class Sequencer {
    private:
        friend class interaction;
        friend class player;

        int length;
        int bpm;

        DoublyLinkedList trackList;

    public:
        Sequencer();
        Sequencer(int new_length, int new_bpm);
        Sequencer(Sequencer &ref_sequencer);
        ~Sequencer();

        Sequencer& operator=(Sequencer &rvalue_sequencer);

        void addTrack();
        void addTrack(SoundSet& sset);
        void addTrack(Track& track);
        void removeTrack(int index);
        void clear();
        int getBpm();
        void setBpm(int new_bpm);
        int getLength();
        void setLength(int new_length);
        bool soundSetExists(string sset_name);
        int getTracksCount();
        void triggerTrack(int trackIndex, int noteIndex);
    };
}