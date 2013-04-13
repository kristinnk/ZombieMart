#!/bin/bash
echo ">===========================<"
echo "> Creating build directory. <"
echo ">===========================<"
mkdir build
echo ">==============================<"
echo "> Moving into build directory. <"
echo ">==============================<"
cd build
echo ">====================<"
echo "> Cmake preperation. <"
echo ">====================<"
cmake ..
echo ">============<"
echo "> Compiling. <"
echo ">============<"
make
