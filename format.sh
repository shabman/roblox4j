# !/bin/bash
# Format recursive

find ./include -iname '*.h' | xargs clang-format -i
find ./src -iname '*.cpp' | xargs clang-format -i