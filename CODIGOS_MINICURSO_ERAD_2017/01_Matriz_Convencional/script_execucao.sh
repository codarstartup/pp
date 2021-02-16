#!/bin/bash
gcc -o programa 01_Matriz_Convencional.c -fopenmp -O2
source ../default.sh
for ((j=1; j <= $TAM; j++))
do
	echo "Executando Multiplicacao $j..."
	./programa $ORDEM $ORDEM &> saida.txt
done
rm programa

gcc -o programa Calculo_Med_DesvPad_DesvRel.c -lm
echo "Executando Calculos..."
./programa $TAM saida.txt
rm saida.txt
echo "Execucao finalizada!"
rm programa
