#include "player.h"
#include <chrono>
#include <thread>

using namespace std;

namespace SequencerNative {
    Player::Player() {}

    Player::~Player() {}

    void Player::play(Sequencer& s) {
        int i = 0;
        int sleep_time = 60000 / s.getBpm();

        time_t timer;

        while (i < 5) { //TODO: ?????
            for (int i = 0; i < s.getLength(); i++) {
                cout << i;
                cout << "-------------------------------->>>" << endl;
                for (int j = 0; j < s.getTracksCount(); j++) {
                    //
                    s.triggerTrack(j, i);
                }
                cout << i;
                cout << "--------------------------------<<<\n." << endl;
                this_thread::sleep_for(chrono::milliseconds(sleep_time));
            }
            i++;
        }
    }
}