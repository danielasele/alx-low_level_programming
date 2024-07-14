#!/bin/bash
wget -p .. https://raw.githubusercontent.com/danielasele/alx-low_level_programing/master/0x18-dynamic_libraries/libgiga.so
export LD_PRELOAD="$PWD/../libgiga.so"
