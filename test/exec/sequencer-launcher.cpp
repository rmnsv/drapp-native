#include <iostream>
#include "player.h"
#include "util.h"
#include "sound-generator.h"
#include "sound-generator-wrapper.h"
#include "sound-mixer.h"

using namespace std;
using namespace SequencerNative;
using namespace DrappNative;

static void soundGenCallback(unsigned char* bytes, int size) {
    cout << "Callback was invoked." << endl;
}

int main() {
    cout << "Sequencer test program." << endl;

    // --- SoundSet init. ---

    SoundSet* sset1 = new SoundSet;

    cout << sset1->getName() << endl;

    sset1->setName("BigBangSet");
    cout << sset1->getName() << endl;

    SoundSet* sset2 = new SoundSet(*sset1);

    sset2->setName("FastFurSet");

    cout << sset1->getName() << " " << sset2->getName() << endl;

    // --- Track init. ---

    Track* track1 = new Track(6);
    Track* track2 = new Track(6);

    track1->linkSoundSet(*sset1);
    track2->linkSoundSet(*sset2);

    cout << track1->getSoundSetName() << endl;
    cout << track2->getSoundSetName() << endl;

    track1->setNote(0, 7);
    track1->setNote(2, 8);
    track1->setNote(4, 7);

    track2->setNote(1, 33);
    track2->setNote(4, 44);
    track2->setNote(4, 55);

    cout << "Track length: " << track1->getLength() << endl;

    // --- Sequencer init. ---

    Sequencer* seq1 = new Sequencer(5, 120);

    seq1->addTrack(*track1);
    seq1->addTrack(*track2);

    cout << seq1->getTracksCount() << endl;
    cout << seq1->getLength() << endl;
    cout << seq1->getBpm() << endl;

    // --- Util check. ---

    cout << "Util check." << endl;

    cout << Util::measurementsToFactor(64) << endl;
    cout << Util::measurementsToFactor(32) << endl;
    cout << Util::measurementsToFactor(16) << endl;
    cout << Util::measurementsToFactor(8) << endl;
    cout << Util::measurementsToFactor(4) << endl;
    cout << Util::measurementsToFactor(2) << endl;
    cout << Util::measurementsToFactor(1) << endl;

    // --- Player init. ---

    cout << "Player init." << endl;

    Player* plr1 = new Player();

    //plr1->play(*seq1);

    // --- Sound generator init. ---

    cout << "Sound generator init." << endl;

    Sound::Generator* generator = new Sound::Generator(8000);

    vector<double> sineWave1 = generator->getSineWave(2000, 783.99);
    vector<unsigned char> sound1 = generator->get16BitPcm(sineWave1);

    vector<double> sineWave2 = generator->getSineWave(3500, 523.25);
    vector<unsigned char> sound2 = generator->get16BitPcm(sineWave2);

    SoundGeneratorCallBack cb = soundGenCallback;

    TestGetSineWave16BitPcm(generator, 2000, 783.99, cb);

    Sound::Mixer* mixer = new Mixer();

    vector<unsigned char> mixed1 = mixer->mix(sound1, 0.5, sound2, 0.5);
}