#include "sequencer.h"

using namespace std;

namespace SequencerNative {

    class Player {
        private:

        public:
        Player();
        ~Player();

        void play(Sequencer& s);
    };
}