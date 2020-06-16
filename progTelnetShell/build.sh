#! /usr/bin/env bash

arg1=$1

if [ $arg1 == "gen" ]
then
  make -f makefile all;
  nm telnet_shell > prog_symbol;
elif [ $arg1 == "clean" ]
then
  make -f makefile clean;
  rm prog_symbol;
else
  echo "build.sh param err!";
fi

