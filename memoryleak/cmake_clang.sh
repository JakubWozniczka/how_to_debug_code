export ASAN_OPTIONS=detect_leaks=1
CXX=clang++ CC=clang ASAN_OPTIONS=detect_leaks=1 cmake ..
