#!/bin/bash
gcc -o programa 05_Matriz_Tiling.c -fopenmp -O2
source ../default.sh
NUM_ALG=7
mkdir Perf
for ((i=1; i <= $NUM_ALG; i++))
do
	for ((j=1; j <= $TAM; j++))
	do
		echo "Executando Multiplicacao $i - $j..."
		perf stat -e L1-dcache-loads,L1-dcache-load-misses ./programa $ORDEM $ORDEM $i $BLOCO &> $i.Perf_multiplicacao_$j.txt
		mv $i.Perf_multiplicacao_$j.txt Perf
	done
done
rm programa
echo "Execucao finalizada!"
