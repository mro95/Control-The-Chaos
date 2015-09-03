#!/bin/bash
cd build
cmake ..
make;
if [[ "$?" == 0 ]]; then
    cd ControlTheChaos
    ./ControlTheChaos
fi
