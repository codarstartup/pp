#!/bin/bash
gcc -pg -o programa 02_Matriz_Convencional_Funcoes_Separadas.c -fopenmp -O2
source ../default.sh
mkdir Gprof
for ((j=1; j <= $TAM; j++))
do
	echo "Executando Multiplicacao $j..."
	./programa $ORDEM $ORDEM >> saida.txt
	gprof -p programa &> Gprof_multiplicacao_$j.txt
	mv Gprof_multiplicacao_$j.txt Gprof
done
rm gmon.out
rm programa

gcc -o programa Calculo_Med_DesvPad_DesvRel.c -lm
echo "Executando Calculos..."
./programa $TAM saida.txt
rm saida.txt
echo "Execucao finalizada!"
rm programa

