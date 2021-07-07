#! /usr/bin/env bash

arg1=$1

CC=gcc

if [ $arg1 == "pc" ]
then
  make -f makefile all;
elif [ $arg1 == "rpi3b" ]
then
  make -f makefile 3b;
elif [ $arg1 == "rpi4b" ]
then
  make -f makefile 4b;
e
elif [ $arg1 == "clean" ]
then
  make -f makefile clean;
else
  echo "build.sh param err!";
fi

