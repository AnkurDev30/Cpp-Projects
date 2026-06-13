#!/bin/bash

make

if [ $? -eq 0 ]
then
    ./output/app
else
    echo "Build Failed"
fi