#!/bin/bash

cd 01_Matriz_Convencional
echo "01_Matriz_Convencional"
echo " "
bash script_execucao.sh
cd ..

cd 02_Matriz_Convencional_Funcoes_Separadas
echo "02_Matriz_Convencional_Funcoes_Separadas"
echo " "
bash script_gprof.sh
cd ..

cd 03_Matriz_Convencional_Loop_Interchange
echo "03_Matriz_Convencional_Loop_Interchange"
echo " "
bash script_gprof.sh
cd ..

cd 04_Matriz_Convencional_Loop_Unrolling_4_Iteracoes
echo "04_Matriz_Convencional_Loop_Unrolling_4_Iteracoes"
echo " "
bash script_gprof.sh
cd ..

cd 05_Matriz_Tiling
echo "05_Matriz_Tiling"
echo " "
bash script_gprof.sh
cd ..

cd 06_Matriz_Tiling_Loop_Interchange
echo "06_Matriz_Tiling_Loop_Interchange"
echo " "
bash script_gprof.sh
cd ..

cd 07_Matriz_Tiling_Loop_Unrolling_4_Iteracoes
echo "07_Matriz_Tiling_Loop_Unrolling_4_Iteracoes"
echo " "
bash script_gprof.sh
cd ..

cd 08_Matriz_Convencional_Loop_Unrolling_4_Iteracoes_PARALELA
echo "08_Matriz_Convencional_Loop_Unrolling_4_Iteracoes_PARALELA"
echo " "
bash script_gprof.sh
cd ..

cd 09_Matriz_Tiling_Loop_Unrolling_4_Iteracoes_PARALELA
echo "09_Matriz_Tiling_Loop_Unrolling_4_Iteracoes_PARALELA"
echo " "
bash script_gprof.sh
cd ..

