#include "track.h"
#include <vector>
#include <iostream>

using namespace std;

namespace SequencerNative {
    
    Track::Track() {}

    Track::Track(int length) {

        _measurementsCount = 32;
        s_set = new SequencerNative::SoundSet();

        for (int i = 0; i < length; i++) {
            notes.push_back(0);
        }
    }

    Track::Track(int length, int measurementsCount) {

        _measurementsCount = measurementsCount;
        s_set = new SequencerNative::SoundSet();

        for (int i = 0; i < length; i++) {
            notes.push_back(0);
        }
    }

    Track::Track(const Track &refTrack) {
        s_set = refTrack.s_set;
        notes = refTrack.notes;
    }

    Track::~Track() {} //TODO: fix error

    Track& Track::operator=(Track &rvalueTrack) {
        if (this != &rvalueTrack) {
            this->s_set = rvalueTrack.s_set;
            this->notes = rvalueTrack.notes;
        }
        return *this;
    }

    void Track::setNote(int index, int value) {
        //TODO: check value and generify it. 
        if (index < 0 || index >= notes.size()) {
            cerr << "Set note: whoops out of index!" << endl;
            return;
        }

        notes[index] = value;
    }

    void Track::playNoteAt(int index) {
        if (index < 0 || index >= notes.size()) {
            cerr << "Set note: whoops out of index!" << endl;
            return;
        }

        if (notes[index] != 0) {
            if (s_set == nullptr) {
                cerr << "No sound set assigned for track!"; // get track name here.
                return;
            }
            s_set->playSound(notes[index]);
        }
    }

    void Track::linkSoundSet(SequencerNative::SoundSet& newSset) {
        s_set = &newSset;
    }

    int Track::getLength() {
        return notes.size();
    }

    string Track::getSoundSetName() {
        return s_set->getName();
    }
}