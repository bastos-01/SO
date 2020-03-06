#!/bin/bash
# For all the files in a folder, show their properties
if [ $# -ne 1 ]
then
    echo "número de argumentos inválido"
elif [ ! -d "$1" ]
then    
    echo "não é diretoria"
else
    for f in $1/*; do
    file "$f"
    done 
fi