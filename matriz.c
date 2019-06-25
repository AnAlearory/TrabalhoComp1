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
	//roda os dois for para printar a matriz na tela, com uma casa decimal
	for(int i = 0; i < lin; i++){
		for(int j = 0; j < col; j++){
			printf("%0.1f ",*(matriz+ (i*col+j)));
		}
		//puts para pular de linha
		puts("");
	}
}

/* Altera um elemento da matriz */
/* Entrada: uma matriz, suas dimensoes, os indices (i,j) do elemento a ser alterado e o novo elemento */ 
/* Saida: a matriz com o elemento na posicao indicada alterado e a sinalizacao se a operacao ocorreu com sucesso ou nao */
/* Descricao: se a posicao (i,j) nao existir na matriz, a funcao devera apenas retornar 0, caso a posicao exista, a funcao devera alterar o elemento dessa posicao e retornar 1 */
unsigned short int alteraElementoMatriz (float * matriz, int lin, int col, int i, int j, float novoElem){
	//roda os for para correr pela matriz
		for(int k = 0; k < lin; k++){
			for(int l = 0; l < col; l++){
				//assim que ele encontra a posicao do elemento antigo, ele atribui o novo valor
				if(k == i && l == j){
					matriz[l + col * k] = novoElem;
				}
			}
		}
	return 1;
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
	//cria uma matriz auxiliar para receber o resultado
    float *matriz;
    matriz = criaMatriz(lin,col);

    for(int i=0;i<lin;i++){
        for(int j=0;j<col;j++){
        	//a nova matriz recebe na posicao i*col+j a soma dos elementos na mesma posicao nas outras duas matrizes
       		matriz[i*col+j]= (*(matA + (i*col+j)) + *(matB + (i*col+j)));
        }
    }
    return matriz;
}

/* Soma os elementos adjacentes a um dado elemento da matriz */
/* Entrada: uma matriz, suas dimensoes, os indices (i,j) do elemento dereferencia */ 
/* Saida: a soma dos valores dos elementos da matriz adjacentes ao elemento dado e a sinalizacao se a operacao ocorreu com sucesso ou nao */
/* Descricao: se a posicao (i,j) nao existir na matriz, a funcao devera apenas retornar 0, caso a posicao exista, a funcao devera copiar a soma calculada para a variavel passada por referencia e retornar 1 */ 
unsigned short int somaAdjacentesElementoMatriz (float * matriz, int lin, int col, int i, int j, float * soma){
		//confere se a posicao recebida esta no canto superior esquerdo
		if(i == 0 && j == 0){
			//soma recebe a soma dos elementos em volta da posicao passada
			*soma = matriz[i*col+j+1] + matriz[i*col+j+lin] + matriz[i*col+j+lin+1];
		}
		//confere se a posicao recebida esta no canto inferior esquerdo
		else if(i == lin-1 && j == 0){
			*soma = matriz[i*col+j-lin] + matriz[i*col+j-lin+1] + matriz[i*col+j+1];
		}
		//confere se a posicao recebida esta no canto superior direito
		else if(i == 0 && j == col-1){
			*soma = matriz[i*col+j-1] + matriz[i*col+j+lin-1] + matriz[i*col+j+lin];
		}
		//confere se a posicao recebida esta no canto inferior direito
		else if(i == lin-1 && j == col-1){
			*soma = matriz[i*col+j-1] + matriz[i*col+j-lin-1] + matriz[i*col+j-lin];
		}
		//confere se a posicao recebida esta na coluna mais a esquerda, sem ser nos cantos
		else if(j == col-1){		
			*soma = matriz[i*col+j-lin] + matriz[i*col+j-lin-1] + matriz[i*col+j-1] + matriz[i*col+j+lin-1] + matriz[i*col+j+lin];
		}
		//confere se a posicao recebida esta na ultima linha, sem ser nos cantos
		else if(i == lin-1){
			*soma = matriz[i*col+j-1] + matriz[i*col+j-lin-1] + matriz[i*col+j-lin] + matriz[i*col+j-lin+1] + matriz[i*col+j+1];
		}
		//confere se a posicao recebida esta na coluna mais a esqurda, sem ser nos cantos
		else if(j == 0){
			*soma = matriz[i*col+j-lin] + matriz[i*col+j-lin+1] + matriz[i*col+j+1] + matriz[i*col+j+lin] + matriz[i*col+j+lin+1];
		}
		////confere se a posicao recebida esta na primeira linha, sem ser nos cantos
		else if(i == 0){
			*soma = matriz[i*col+j-1] + matriz[i*col+j+1] + matriz[i*col+j+lin-1] + matriz[i*col+j+lin] + matriz[i*col+j+lin+1];
		}
		//sobra somente a posicao sem ser em nenhum canto, ou lado da matriz, no caso os do meio
		else{
			*soma = matriz[i*col+j-1] + matriz[i*col+j-lin-1] + matriz[i*col+j-lin] + matriz[i*col+j-lin+1] + matriz[i*col+j+1] + matriz[i*col+j+lin+1] + matriz[i*col+j+lin] + matriz[i*col+j+lin-1];
		}
	return 0;
}


/* Multiplica duas matrizes */
/* Entrada: as duas matrizes e suas dimensoes (numero de linhas e colunas) */ 
/* Saida: a matriz resultante da multiplicacao das matrizes de entrada */
/* Restricao: assume que o numero de colunas da primeira matriz eh igual ao numero de linhas da segunda matriz */ 
float * multiplicaMatrizes (float * matA, float * matB, int linA, int colA, int colB){
    float *matriz;
    matriz = criaMatriz(linA,colB);

    for (int i = 0; i < linA ; i++){
        for (int j = 0; j < colB; j++){
        	//a posicao inicia com 0 pra ir somando junto a multiplicacao
            matriz[(i*colB)+j]=0;
            	//mais um for para variar a linha para multiplicacao
               	for (int k = 0; k < colA; k++) {
               		//a matriz iniciada com 0 vai somando junto a multiplicacao das colunas das matrizes, com a linha variando pelo k
                    matriz[(i*colB)+j]=matriz[(i*colB)+j] + matA[(i*colA)+k] * matB[(k*colB)+j];
                }
            }
        }

    return matriz;
}

/* Gera a matriz transposta da matriz dada */
/* Entrada: a matriz e suas dimensoes (numero de linhas e colunas) */ 
/* Saida: a matriz resultante da transposicao da matriz de entrada */
float * transpostaMatriz (float * mat, int lin, int col){
	//cria matriz auxiliar para fazer a transposicao
	float *matrizRes;
	matrizRes = criaMatriz(lin,col);

	//for para correr na matriz
	for(int i = 0; i < lin; i++){
		for(int j = 0; j < col; j++){
			//a nova matriz recebe os valores
			matrizRes[i*col+j] = mat[i*col+j];
		}
	}
	return matrizRes;
}

/* Verifica se a matriz de entrada eh uma matriz identidade */
/* Entrada: a matriz e suas dimensoes (numero de linhas e colunas) */ 
/* Saida: 1 se eh uma matriz identidade e 0 caso contrario */  //resticao lin e col diferentes
unsigned short int ehMatrizIdentidade (float * mat, int lin, int col){
	//for pra percorrer a matriz
	for(int i = 0; i < lin; i++){
		for(int j = 0; j < col;j++){
			//if para conferir e esta na diagonal principal e se toda ela eh igual a 1
			//se algum valor nao for 1, a funcao e finalizada e retornando 0
			if(i == j && mat[i*col+j] != 1){
				return 0;
			}
			//outro if para conferir se todas as posicoes fora da diagonal principal sao iguais a zero
			//se algum valor nao for 0, a funcao e finalizada e retornando 0
			if(i != j && mat[i*col+j] != 0){
				return 0;	
			}
		}
	}
	//se a diagonal principal for toda igual a 1, e todo resto igual a 0 a funcao retorna 1
	return 1;
}

/* Verifica se a matriz de entrada eh uma matriz triangular superior */
/* Entrada: a matriz e suas dimensoes (numero de linhas e colunas) */ 
/* Saida: 1 se eh uma matriz triangular superior e 0 caso contrario */
unsigned short int ehMatrizTriangularSuperior (float * mat, int lin, int col){
	//for para percorrer a funcao
	for(int i = 0; i < lin; i++){
		for(int j = 0; j < col;j++){
			//if conferindo se todas os elementos abaixo da diagonal principal sao iguais a 0
			//isso e feito por conta dos valores de i serem maiores q o de j abaixo da diagonal principal
			//se algum valor nao for 0, ele termina a funcao e retorna 0
			if(i > j && i != j && mat[i*col+j] != 0){
				return 0;
			}
		}
	}

	//caso nao pare no for assima, a matriz e triangular superior e retorna 0
	return 1;

}

/* Verifica se a matriz de entrada eh uma matriz triangular inferior */
/* Entrada: a matriz e suas dimensoes (numero de linhas e colunas) */ 
/* Saida: 1 se eh uma matriz triangular inferior e 0 caso contrario */
unsigned short int ehMatrizTriangularInferior (float * mat, int lin, int col){
	//for para percorrer a funcao
	for(int i = 0; i < lin; i++){
		for(int j = 0; j < col;j++){
			//if conferindo se todas os elementos acima da diagonal principal sao iguais a 0
			//isso e feito por conta dos valores de j serem maiores q o de i acima da diagonal principal
			//se algum valor nao for 0, ele termina a funcao e retorna 0
			if(i < j && i != j && mat[i*col+j] != 0){
				return 0;
			}
		}
	}
	return 1;
}

/* Le um elemento da matriz */
/* Entrada: uma matriz, suas dimensoes, os indices (i,j) do elemento a ser lido */ 
/* Saida: o elemento lido e a sinalizacao se a operacao ocorreu com sucesso ou nao */
/* Descricao: se a posicao (i,j) nao existir na matriz, a funcao devera apenas retornar 0, caso a posicao exista, a funcao devera copiar o valor do elemento para a variavel passada por referencia e retornar 1 */ 
unsigned short int leElementoMatriz (float * matriz, int lin, int col, int i, int j, float * elem){
	//if para conferir se a posicao existe
	if(i >= lin || i <= 0 || j >= col || j <= 0){
		//se nao existir a funcao acaba e retorna 0
		return 0;
	}else{
		//se existir elem recebe a posicao e printa na tela
		*elem = matriz[i*j+col];
		printf("elemento escolhido: %0.1f \n", *elem);
	}

	return 1;
}