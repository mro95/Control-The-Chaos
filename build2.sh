#!/bin/bash
cd build;
cmake ..;
make;
cd ../;
./build/ControlTheChaos/ControlTheChaos;
