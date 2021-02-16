#!/bin/bash

#Especificacoes:
#O tamanho pode ser escolhido conforme o usuario decidir, e aconselhavel gerar cerca de 30 execucoes para a media estabilizar.
#O bloco deve ser par, multiplo da Ordem Matricial, ter no maximo o tamanho da Ordem Matricial e no minimo o tamanho do Unrolling (Neste caso e 4)!
#A menor ordem aceita deve ter o tamanho do Unroll (Neste caso e 4)!
#A maquina utilizada deve possuir o numero de threads selecionado, veja com "lscpu" no terminal.

TAM=5 				#Numero de execucoes
ORDEM=8				#Ordem da Matriz Quadrada
BLOCO=4				#Blocos para a tecnica de Tiling
N_THREADS=2			#Numero de Threads

#Definidos os parametros execute o script_geral.sh para gerar todos os resultados.
