cmake_minimum_required(VERSION 3.17)
project(drapp_native)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/src/sequencer/)
include_directories(${PROJECT_SOURCE_DIR}/src/sound/)
add_executable(drapp_native ./test/exec/sequencer-launcher.cpp ./src/sequencer/doubly-linked-item.cpp ./src/sequencer/doubly-linked-list.cpp ./src/sequencer/player.cpp ./src/sequencer/sequencer.cpp src/sequencer/sound-set.cpp ./src/sequencer/track.cpp src/sequencer/util.h src/sequencer/util.cpp src/sound/sound-generator.cpp src/sound/sound-generator.h src/sound/sound-generator-wrapper.h src/sound/sound-generator-wrapper.cpp src/sound/sound-provider.h src/sound/sound-provider.cpp src/sound/sound-provider-wrapper.h src/sound/sound-provider-wrapper.cpp src/sound/sound-wave.h src/sound/sound-wave.cpp src/sound/sound-mixer.h src/sound/sound-mixer.cpp src/sound/sound-mixer-wrapper.h src/sound/sound-mixer-wrapper.cpp)