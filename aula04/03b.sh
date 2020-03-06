#!/bin/bash

while read line
do
    lista+=($line)
done < $1

valor=${lista[0]}
length=${#lista[@]}
x="0"

while (($x < $length))
do
    for i in ${lista[@]}; do
        if (($i < $valor)); then
            valor=$i
        fi
    done
    listaOrdenada+=($valor)
    lista=(${lista[@]/$valor})
    x=$(($x + 1))
    valor=${lista[0]}
done

for i in ${listaOrdenada[@]}; do
    echo $i 
done



