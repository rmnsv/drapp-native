echo "------ Build started (Exe) ------"
echo ""

g++.exe -g $(find ./src/sequencer/ -type f -iregex ".*\.cpp") ./test/exec/sequencer-launcher.cpp -o ./bin/test.exe -I./src/sequencer
./bin/test.exe