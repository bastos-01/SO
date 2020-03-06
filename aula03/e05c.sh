#!/bin/bash
if [ $# -ne 1 ]
then
    echo "número de argumentos inválido"
elif [ ! -d "$1" ]
then    
    echo "não é diretoria"
else
    for f in $1/*; do
    mv "$f" "${f%.*}""_new"".txt" #como por como prefixo????
    done 
fi