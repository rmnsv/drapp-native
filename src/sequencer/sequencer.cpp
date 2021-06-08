#include "sequencer.h"

namespace SequencerNative {
    Sequencer::Sequencer() {}

    Sequencer::Sequencer(int newLength, int newBpm) {
        length = newLength;
        bpm = newBpm;
    }

    Sequencer::Sequencer(Sequencer &refSequencer) {
        length = refSequencer.length;
        bpm = refSequencer.bpm;
    }

    Sequencer::~Sequencer() {}

    Sequencer& Sequencer::operator=(Sequencer &rvalueSequencer) {
        if (this != &rvalueSequencer) {
            this->length = rvalueSequencer.length;
            this->bpm = rvalueSequencer.bpm;
        }

        return *this;
    }

    void Sequencer::addTrack() {
        Track* newTrack = new Track(length);
        trackList.insertFront(*newTrack);
    }

    void Sequencer::addTrack(SoundSet& sset) {
        Track* newTrack = new Track(length);
        newTrack->linkSoundSet(sset);
        trackList.insertFront(*newTrack);
    }

    void Sequencer::addTrack(Track& track) {
        trackList.insertFront(track);
    }

    void Sequencer::removeTrack(int index) {
        trackList.removeAt(index);
    }

    void Sequencer::clear() {
        int size = trackList.size();

        for (int i = 0; i < size; i++) {
            trackList.removeFront();
        }
    }

    int Sequencer::getBpm() {
        return bpm;
    }

    void Sequencer::setBpm(int newBpm) {
        bpm = newBpm;
    }

    int Sequencer::getLength() {
        return length;
    }

    void Sequencer::setLength(int newLength) {
        length = newLength;
    }

    bool Sequencer::soundSetExists(string ssetName) {
        bool found = false;
        for (int i = 0; i < trackList.size(); i++) {
            if (trackList.getDataAt(i).getSoundSetName() == ssetName) {
                found = true;
                break;
            }
        }
        return found;
    }

    int Sequencer::getTracksCount() {
        return trackList.size();
    }

    void Sequencer::triggerTrack(int trackIndex, int noteIndex) {
        trackList
            .getDataAt(trackIndex)
            .playNoteAt(noteIndex);
    }
}