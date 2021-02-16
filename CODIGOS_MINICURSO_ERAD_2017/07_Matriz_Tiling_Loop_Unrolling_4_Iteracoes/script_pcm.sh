#!/bin/bash
gcc -o programa 07_Matriz_Tiling_Loop_Unrolling_4_Iteracoes.c -fopenmp -O2
source ../default.sh
NUM_ALG=10
mkdir PCM
for ((i=1; i <= $NUM_ALG; i++))
do
	for ((j=1; j <= $TAM; j++))
	do
		echo "Executando Multiplicacao $i - $j..."
		sudo ../Intel_PCM/pcm-master/./pcm.x -- programa $ORDEM $ORDEM $i $BLOCO &> $i.PCM_multiplicacao_$j.txt
		mv $i.PCM_multiplicacao_$j.txt PCM
	done
done
rm programa
echo "Execucao finalizada!"
