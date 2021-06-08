//
// Created by samea on 16.05.2021.
//

#include "util.h"
#include <cmath>

namespace SequencerNative {
    int Util::measurementsToFactor(int measurementCount) {
        return maxMeasurementsCount / measurementCount;
    }
}