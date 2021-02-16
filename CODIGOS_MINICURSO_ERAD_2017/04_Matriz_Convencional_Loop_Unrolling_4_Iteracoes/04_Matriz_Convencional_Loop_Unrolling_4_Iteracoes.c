#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <sys/time.h>
#include <omp.h>
//#define IMPRIME

void imprime(int m, int n, int **matriz){
	int i, j;
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

void inicializa(int m, int n, int **matriz){
	int i, j;
	for (i=0;i<m;i++){
		for(j=0;j<n;j++){
			matriz[i][j]=i+j;
		}
	}
}

//ORDEM I J K O_QUARTO_MELHOR
void multiplica1(int m, int n, int **matA, int **matB, int **matC){
	int i, j, k, som;
	for (i=0;i<m;i++){
		for(j=0;j<n;j++){
			for(k=0; k<m; k+=4){
				matC[i][j]+= matA[i][k]*matB[k][j];
				matC[i][j]+= matA[i][k+1]*matB[k+1][j];
				matC[i][j]+= matA[i][k+2]*matB[k+2][j];
				matC[i][j]+= matA[i][k+3]*matB[k+3][j];
			}
		}
	}
}

//ORDEM J I K O_TERCEIRO_MELHOR
void multiplica2(int m, int n, int **matA, int **matB, int **matC){
	int i, j, k, som;
	for (j=0;j<m;j++){
		for(i=0;i<n;i++){
			for(k=0; k<m; k+=4){
				matC[i][j]+= matA[i][k]*matB[k][j];
				matC[i][j]+= matA[i][k+1]*matB[k+1][j];
				matC[i][j]+= matA[i][k+2]*matB[k+2][j];
				matC[i][j]+= matA[i][k+3]*matB[k+3][j];
			}
		}
	}
}

//ORDEM J K I O_SEXTO_MELHOR
void multiplica3(int m, int n, int **matA, int **matB, int **matC){
	int i, j, k, som;
	for (j=0;j<m;j++){
		for(k=0;k<n;k+=4){
			for(i=0; i<m; i++){
				matC[i][j]+= matA[i][k]*matB[k][j];
				matC[i][j]+= matA[i][k+1]*matB[k+1][j];
				matC[i][j]+= matA[i][k+2]*matB[k+2][j];
				matC[i][j]+= matA[i][k+3]*matB[k+3][j];
			}
		}
	}
}

//ORDEM K J I O_QUINTO_MELHOR
void multiplica4(int m, int n, int **matA, int **matB, int **matC){
	int i, j, k, som;
	for (k=0;k<m;k+=4){
		for(j=0;j<n;j++){
			for(i=0; i<m; i++){
				matC[i][j]+= matA[i][k]*matB[k][j];
				matC[i][j]+= matA[i][k+1]*matB[k+1][j];
				matC[i][j]+= matA[i][k+2]*matB[k+2][j];
				matC[i][j]+= matA[i][k+3]*matB[k+3][j];
			}
		}
	}
}

//ORDEM I K J O_PRIMEIRO_MELHOR
void multiplica5(int m, int n, int **matA, int **matB, int **matC){
	int i, j, k, som;
	for (i=0;i<m;i++){
		for(k=0;k<n;k+=4){
			for(j=0; j<m; j++){
				matC[i][j]+= matA[i][k]*matB[k][j];
				matC[i][j]+= matA[i][k+1]*matB[k+1][j];
				matC[i][j]+= matA[i][k+2]*matB[k+2][j];
				matC[i][j]+= matA[i][k+3]*matB[k+3][j];
			}
		}
	}
}

//ORDEM K I J O_SEGUNDO_MELHOR
void multiplica6(int m, int n, int **matA, int **matB, int **matC){
	int i, j, k, som;
	for (k=0;k<m;k+=4){
		for(i=0;i<n;i++){
			for(j=0; j<m; j++){
				matC[i][j]+= matA[i][k]*matB[k][j];
				matC[i][j]+= matA[i][k+1]*matB[k+1][j];
				matC[i][j]+= matA[i][k+2]*matB[k+2][j];
				matC[i][j]+= matA[i][k+3]*matB[k+3][j];
			}
		}
	}
}

int **aloca(int m, int n, int **matriz){
	int i;
	matriz=(int**)calloc(m, sizeof(int*));
	for(i=0;i<m;i++){
		matriz[i]=(int*)calloc(n, sizeof(int));
	}
	return matriz;
}

void desaloca(int m, int n, int **matriz){
	int i;
	for(i=0;i<m;i++){
		free(matriz[i]);
	}
	free(matriz);
}

int main (int argc, char *argv[]) {
	int **matA,**matB,**matC; 
	int m,n,i,j,k, algoritmo; // m(linhas) e n (colunas)
	int clockBegin;
	double timeElapsed;
	if(argc!=4){
		printf("Digite %s M_Linhas N_Colunas Interchange\n\n", argv[0]);
		exit(0);
	}
	m=atoi(argv[1]);
	n=atoi(argv[2]);
	algoritmo=atoi(argv[3]);
	
	if(m<4 || n<4){
		printf("Valor invalido! A menor ordem aceita deve ter o tamanho do Unroll (Neste caso e 4)!\n\n");
		exit(0);
	}
	
	/*ALOCA AS MATRIZES*/
	matA=aloca(m, n, matA);
	matB=aloca(m, n, matB);
	matC=aloca(m, n, matC);
	
	#ifdef IMPRIME
	printf("Antes da inicializacao!\n");
	imprime(m, n, matA);
	imprime(m, n, matB);
	imprime(m, n, matC);
	printf("\n");
	#endif

	/*POPULA AS MATRIZES A e B*/
	inicializa(m, n, matA);
	inicializa(m, n, matB);

	#ifdef IMPRIME
	printf("Depois da inicializacao!\n");
	imprime(m, n, matA);
	imprime(m, n, matB);
	imprime(m, n, matC);
	printf("\n");
	#endif
	
	/*MULTIPLICA AS MATRIZES A e B*/
	clockBegin = omp_get_wtime();
	switch (algoritmo){
		case 1: //ORDEM I J K O_QUARTO_MELHOR
			clockBegin = omp_get_wtime();
			multiplica1(m, n, matA, matB, matC);
			timeElapsed = (omp_get_wtime() - clockBegin);	
			printf("%5lf\n", timeElapsed);
			break;
		case 2: //ORDEM J I K O_TERCEIRO_MELHOR
			clockBegin = omp_get_wtime();
			multiplica2(m, n, matA, matB, matC);
			timeElapsed = (omp_get_wtime() - clockBegin);	
			printf("%5lf\n", timeElapsed);
			break;
		case 3: //ORDEM J K I O_SEXTO_MELHOR
			clockBegin = omp_get_wtime();
			multiplica3(m, n, matA, matB, matC);
			timeElapsed = (omp_get_wtime() - clockBegin);	
			printf("%5lf\n", timeElapsed);
			break;
		case 4: //ORDEM K J I O_QUINTO_MELHOR
			clockBegin = omp_get_wtime();
			multiplica4(m, n, matA, matB, matC);
			timeElapsed = (omp_get_wtime() - clockBegin);	
			printf("%5lf\n", timeElapsed);
			break;
		case 5: //ORDEM I K J O_PRIMEIRO_MELHOR
			clockBegin = omp_get_wtime();
			multiplica5(m, n, matA, matB, matC);
			timeElapsed = (omp_get_wtime() - clockBegin);	
			printf("%5lf\n", timeElapsed);
			break;
		case 6: //ORDEM K I J O_SEGUNDO_MELHOR
			clockBegin = omp_get_wtime();
			multiplica6(m, n, matA, matB, matC);
			timeElapsed = (omp_get_wtime() - clockBegin);	
			printf("%5lf\n", timeElapsed);
			break;
		default:
			printf("Opcao Invalida! Tente Novamente!\n\n");
			break;
	}
	timeElapsed = (omp_get_wtime() - clockBegin);	
			
	#ifdef IMPRIME
	printf("Depois da Multiplicacao!\n");
	imprime(m, n, matA);
	imprime(m, n, matB);
	imprime(m, n, matC);
	printf("\n");
	#endif

	/*DESALOCA AS MATRIZES*/
	desaloca(m, n, matA);
	desaloca(m, n, matB);
	desaloca(m, n, matC);
	return 0;
}

