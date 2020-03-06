#!/bin/bash
echo "introduza 2 números: "
read numero1 
read numero2
function comparar(){
    if [[ "$numero1" == "$numero2" ]]; then
        c="Números iguais"
    elif [[ "$numero1" < "$numero2" ]]; then
        c="$numero2 maior que $numero1"
    else c="$numero1 maior que $numero2"
    fi 
    return 0
}

comparar $numero1 $numero2
echo $c