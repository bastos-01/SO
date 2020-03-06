#!/bin/bash
if [ $# -lt 1 ]
then
	echo "Não foi colocado nenhum argumento!"
elif [ $# -gt 1 ]
then 
	echo "Precisa de passar apenas 1 argumento!"
else
	if [ $1 -ge 5 ] && [ $1 -le 10 ] 
	then 
		echo "Número maior do que 5 e menor que 10"
	else
		echo "Numero não está entre 5 e 10"
	fi
fi


