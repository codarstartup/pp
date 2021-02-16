#!/bin/bash
gcc -o programa 02_Matriz_Convencional_Funcoes_Separadas.c -fopenmp -O2
source ../default.sh
mkdir PCM
for ((j=1; j <= $TAM; j++))
do
	echo "Executando Multiplicacao $j..."
	sudo ../Intel_PCM/pcm-master/./pcm.x -- programa $ORDEM $ORDEM &> PCM_multiplicacao_$j.txt
	mv PCM_multiplicacao_$j.txt PCM
done
rm programa
echo "Execucao finalizada!"
