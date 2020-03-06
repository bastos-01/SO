#!/bin/bash
# select structure to create menus
PS3="Escolha uma opção"
teste="0"
contador="0"
for a in $@; do
contador=$((contador + 1))
done
select arg in $@; do
for x in $@ 
do  
    if (("$REPLY" <= "$contador" )); then
    teste="1"
    fi
done
if [[ "$teste" == "1" ]]; then
    echo "You picked $arg ($REPLY)."
    teste="0"
else
    echo "argumento invalido"
fi
done 