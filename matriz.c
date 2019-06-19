#include<stdio.h>
#include<stdlib.h>


/* Cria uma matriz de float vazia */
/* Entrada: dimensoes da matriz (numero de linhas e colunas) */ 
/* Saida: a matriz criada (ponteiro para float) */ 
float * criaMatriz (int lin, int col){
	//cria uma matriz de float
	float *matriz;
	//aloca o espaco vazio para a matriz
	matriz = (float*) malloc(sizeof(float)*lin*col);
	//retorna a matriz
	return matriz;
}

/* Cria e inicializa uma matriz de float com todos os elementos iguais a zero */
/* Entrada: dimensoes da matriz (numero de linhas e colunas) */ 
/* Saida: a matriz criada (ponteiro para float) com seus elementos iguais a zero */ 
float * criaMatrizZero (int lin, int col){
	//cria a matrizZero
	float *matrizZero;
	//aloca o espaco da matriz com zeros
	matrizZero = (float*) calloc(lin*col,sizeof(float));
	//retorna a matriz
	return matrizZero;
}

/* Destroi uma matriz previamente alocada (libera o espaco de memoria ocupado por ela) */
/* Entrada: matriz (ponteiro para float) */ 
/* Saida: <vazio> */ 
void destroiMatriz(float * matriz){
	//limpa a alocacao da matriz na memoria
	free(matriz);
}

/* Carrega uma matriz da entrada padrao (teclado) */ 
/* Entrada: uma matriz e suas dimensoes */ 
/* Saida: a matriz com todos os seus valores alterados (lidos da entrada padrao) */ 
void carregaMatrizTeclado (float * matriz, int lin, int col){
	//roda os dois for para andar pelas linhas e colunas da matriz e preenchelas
	printf("Digite os valores da matriz: \n");
	for(int i = 0; i < lin; i++){
		for(int j = 0; j < col; j++){
			scanf("%f",matriz+(i*col+j));
		}
	}
}

/* Carrega uma matriz de um arquivo binario */ 
/* Entrada: o descritor do arquivo binario de onde a matriz sera carregada (previamente aberto para leitura binaria) */ 
/* Saida: a matriz criada e carregada do arquivo de entrada */
/* Restricao: assume que o arquivo de entrada tem o seguinte conteudo: numero de linhas da matriz (int), numero de colunas da matriz (int), sequencia de elementos da matriz, linha por linha (float) */ 
float * carregaMatrizBinario (FILE * descArquivo,int *lin,int *col){
	//cria a matriz de float
	float *matrizBin;
	//dois fread para receber o valor da linha e coluna
	fread(lin,sizeof(int),1,descArquivo);
	fread(col,sizeof(int),1,descArquivo);
	//inicializa a matriz vazia
	matrizBin = (float*) malloc(sizeof(float)*(*lin)*(*col));
	//um for para ler cada linha da matriz, o tamanho da linha e o valor de colunas
	fread(matrizBin,sizeof(float),(*(col))*(*(lin)),descArquivo);

	
	//retorna a matriz criada
	return matrizBin;
}

/* Imprime uma matriz na tela */ 
/* Entrada: uma matriz e suas dimensoes */ 
/* Saida: a matriz impressa na tela */ 
/* Descricao: devera exibir cada linha da matriz em uma linha separada na tela, separando os elementos de cada linha com um espaco em branco
*/
void imprimeMatriz (float * matriz, int lin, int col){
	printf("Imprimindo sua matriz: \n");
	for(int i = 0; i < lin; i++){
		for(int j = 0; j < col; j++){
			printf("%0.1f ",*(matriz+ (i*col+j)));
		}
		puts("");
	}
}

/* Altera um elemento da matriz */
/* Entrada: uma matriz, suas dimensoes, os indices (i,j) do elemento a ser alterado e o novo elemento */ 
/* Saida: a matriz com o elemento na posicao indicada alterado e a sinalizacao se a operacao ocorreu com sucesso ou nao */
/* Descricao: se a posicao (i,j) nao existir na matriz, a funcao devera apenas retornar 0, caso a posicao exista, a funcao devera alterar o elemento dessa posicao e retornar 1 */
unsigned short int alteraElementoMatriz (float * matriz, int lin, int col, int i, int j, float novoElem){
	if(i > lin || j > col){
		printf("o tamanho indicado e maior que a matriz, finalizando troca\n");
		return 0;
	}else{
		for(int k = 0; k < lin; k++){
			for(int l = 0; l < col; l++){
				if(k == i && l == j){
					matriz[l + col * k] = novoElem;
				}
			}
		}
	}
	return 0;
}

/* Salva uma matriz em um arquivo binario */ 
/* Entrada: uma matriz, suas dimensoes e o nome do arquivo de saida */ 
/* Saida: <vazio> */ 
/* Descricao: o arquivo de saida devera ter o seguinte conteudo: numero de linhas da matriz (int), numero de colunas da matriz (int), sequencia de elementos da matriz, linha por linha (float) */ 
void salvaMatrizBinario (float * matriz, int lin, int col, char * nomeArquivo){
	FILE* arq;
	arq = fopen(nomeArquivo,"wb");
	getchar();
	//dois fread para receber o valor da linha e coluna
	if((fwrite(&lin,sizeof(int),1,arq)) != 1){
		puts("linha nao salva corretamente");
	}
	if((fwrite(&col,sizeof(int),1,arq))!= 1){
		puts("coluna nao salva corretamente");
	}
	//um for para ler cada linha da matriz, o tamanho da linha e o valor de colunas
	fwrite(matriz,sizeof(float),col*lin,arq);

	printf("Matriz salva com sucesso \n");
}

/* Soma duas matrizes */
/* Entrada: as duas matrizes e suas dimensoes (numero de linhas e colunas) */ 
/* Saida: a matriz resultante da soma das matrizes de entrada */
/* Restricao: assume que as dimensoes das matrizes de entrada sao identicas */ 
float * somaMatrizes (float * matA, float * matB, int lin, int col){
	int i,j;
    float *matriz;

    matriz = (float*) malloc(sizeof(float)*lin*col);

    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
       		matriz[i*col+j]= (*(matA + (i*col+j)) + *(matB + (i*col+j)));
        }
    }
    return matriz;
}

/* Multiplica duas matrizes */
/* Entrada: as duas matrizes e suas dimensoes (numero de linhas e colunas) */ 
/* Saida: a matriz resultante da multiplicacao das matrizes de entrada */
/* Restricao: assume que o numero de colunas da primeira matriz eh igual ao numero de linhas da segunda matriz */ 
float * multiplicaMatrizes (float * matA, float * matB, int linA, int colA, int colB){
	int i,j,k;
    float mult,soma = 0;
    float *matriz;
    matriz = (float*)malloc(sizeof(float)*linA*colA);

    for(i=0;i<linA;i++){
        for(j=0;j<colB;j++){
            for(k=0;k<colA;k++){
                mult = *(matA+(i*colA+k))* *(matB+k*colB);
                soma = soma+mult;
            }
            matriz[i*colA+j] = soma;
            soma=0;
        }
    }
    return matriz;
}