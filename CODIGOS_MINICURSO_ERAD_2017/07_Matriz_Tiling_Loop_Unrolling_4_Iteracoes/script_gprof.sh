#!/bin/bash
gcc -pg -o programa 07_Matriz_Tiling_Loop_Unrolling_4_Iteracoes.c -fopenmp -O2
source ../default.sh
NUM_ALG=10
mkdir Gprof
for ((i=1; i <= $NUM_ALG; i++))
do
	for ((j=1; j <= $TAM; j++))
	do
		echo "Executando Multiplicacao $i - $j..."
		./programa $ORDEM $ORDEM $i $BLOCO >> saida$i.txt
		gprof -p programa &> $i.Gprof_multiplicacao_$j.txt
		mv $i.Gprof_multiplicacao_$j.txt Gprof
	done
done
rm gmon.out
rm programa

gcc -o programa Calculo_Med_DesvPad_DesvRel.c -lm
echo "Executando Calculos..."

for ((i=1; i <= $NUM_ALG; i++))
do
	./programa $TAM saida$i.txt
	rm saida$i.txt
done
echo "Execucao finalizada!"
rm programa

