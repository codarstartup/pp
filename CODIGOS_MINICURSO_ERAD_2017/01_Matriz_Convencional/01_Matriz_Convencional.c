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

int main (int argc, char *argv[]) {
	int **matA,**matB,**matC; 
	int m,n,i,j,k; // m(linhas) e n (colunas)
	int clockBegin;
	double timeElapsed;
	if(argc!=3){
		printf("Digite %s M_Linhas N_Colunas\n\n", argv[0]);
		exit(0);
	}
	m=atoi(argv[1]);
	n=atoi(argv[2]);
	
	/*ALOCA AS MATRIZES*/
	matA=(int**)calloc(m, sizeof(int*));
	for(i=0;i<m;i++){
		matA[i]=(int*)calloc(n, sizeof(int));
	}
	matB=(int**)calloc(m, sizeof(int*));
	for(i=0;i<m;i++){
		matB[i]=(int*)calloc(n, sizeof(int));
	}
	matC=(int**)calloc(m, sizeof(int*));
	for(i=0;i<m;i++){
		matC[i]=(int*)calloc(n, sizeof(int));
	}
	
	#ifdef IMPRIME
	printf("Antes da inicializacao!\n");
	imprime(m, n, matA);
	imprime(m, n, matB);
	imprime(m, n, matC);
	printf("\n");
	#endif

	/*POPULA AS MATRIZES A e B*/
	for (i=0;i<m;i++){
		for(j=0;j<n;j++){
			matA[i][j]=i+j;
		}
	}
	for (i=0;i<m;i++){
		for(j=0;j<n;j++){
			matB[i][j]=i+j;
		}
	}

	#ifdef IMPRIME
	printf("Depois da inicializacao!\n");
	imprime(m, n, matA);
	imprime(m, n, matB);
	imprime(m, n, matC);
	printf("\n");
	#endif
	
	/*MULTIPLICA AS MATRIZES A e B*/
	clockBegin = omp_get_wtime();
	for (i=0;i<m;i++){
		for(j=0;j<n;j++){
			for(k=0; k<m; k++){
				matC[i][j]+= matA[i][k]*matB[k][j];
			}
		}
	}
	timeElapsed = (omp_get_wtime() - clockBegin);	
			
	#ifdef IMPRIME
	printf("Depois da Multiplicacao!\n");
	imprime(m, n, matA);
	imprime(m, n, matB);
	imprime(m, n, matC);
	printf("\n");
	#endif
	
	printf("%5lf\n", timeElapsed);

	/*DESALOCA AS MATRIZES*/
	for(i=0;i<m;i++){
		free(matA[i]);
	}
	for(i=0;i<m;i++){
		free(matB[i]);
	}
	for(i=0;i<m;i++){
		free(matC[i]);
	}
	free(matA);
	free(matB);
	free(matC);
	return 0;
}

