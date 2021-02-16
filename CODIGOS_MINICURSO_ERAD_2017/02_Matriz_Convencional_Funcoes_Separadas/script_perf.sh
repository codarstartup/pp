#!/bin/bash
gcc -o programa 02_Matriz_Convencional_Funcoes_Separadas.c -fopenmp -O2
source ../default.sh
mkdir Perf
for ((j=1; j <= $TAM; j++))
do
	echo "Executando Multiplicacao $j..."
	perf stat -e L1-dcache-loads,L1-dcache-load-misses ./programa $ORDEM $ORDEM &> Perf_multiplicacao_$j.txt
	mv Perf_multiplicacao_$j.txt Perf
done
rm programa
echo "Execucao finalizada!"
