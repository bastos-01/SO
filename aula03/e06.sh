#!/bin/bash
#This script opens 4 terminal windows. 
i="0"
until [[ $i -ge 4 ]]; do
    echo "ola"
    xterm &
    i=$(($i+1))
done
