//
// Created by samea on 16.05.2021.
//

#ifndef DRAPP_NATIVE_UTIL_H
#define DRAPP_NATIVE_UTIL_H

namespace SequencerNative {
    class Util {
    private:
        static const int maxMeasurementsCount = 64;
    public:
        static int measurementsToFactor(int measurementCount);
    };
}

#endif //DRAPP_NATIVE_UTIL_H
