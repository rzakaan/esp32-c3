#!/bin/sh

INS_DIR=~/workspace/esp
if [[ $OSTYPE == 'darwin'* ]]; then
        brew install cmake ninja dfu-util
        mkdir -p $INS_DIR
        cd $INS_DIR
        git clone --recursive https://github.com/espressif/esp-idf.git

else
fi
