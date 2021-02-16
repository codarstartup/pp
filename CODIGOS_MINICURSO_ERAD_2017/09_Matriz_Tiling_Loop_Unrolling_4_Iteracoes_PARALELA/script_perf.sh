#!/bin/bash
gcc -o programa 09_Matriz_Tiling_Loop_Unrolling_4_Iteracoes_PARALELA.c -fopenmp -O2
source ../default.sh
NUM_ALG=10
mkdir Perf
for ((i=1; i <= $NUM_ALG; i++))
do
	for ((j=1; j <= $TAM; j++))
	do
		echo "Executando Multiplicacao $i - $j..."
		perf stat -e L1-dcache-loads,L1-dcache-load-misses ./programa $ORDEM $ORDEM $i $N_THREADS $BLOCO &> $i.Perf_multiplicacao_$j.txt
		mv $i.Perf_multiplicacao_$j.txt Perf
	done
done
rm programa
echo "Execucao finalizada!"
