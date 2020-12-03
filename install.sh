#!/bin/bash
PT=$PWD
mkdir $PWD/SDL
tar -xf SDL2-2.0.12.tar
cd SDL2-2.0.12
./configure --prefix=$PT/SDL
make -j4
make install
cd ..
unzip SDL2_image-2.0.5.zip
cd SDL2_image-2.0.5
./configure --prefix=$PT/SDL
make -j4
make install
cd ..
make re
