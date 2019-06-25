#include<stdio.h>
#include<stdlib.h>
#include"matriz.h"

int main(void){
	//Variaveis
	int mn1, mn2, i, j,novoElem;
	int lin1, col1, lin2, col2;
	float soma, *elem;
	char nomeBin1[20],nomeBin2[20];

	//matrizes
	float *mtrz1, *mtrz2,*mtrzRes;

	//arquivos
	FILE* arqBin1;
	FILE* arqBin2;

	elem = (float*) malloc(sizeof(float));

	//Menu
	puts("============================================");
	puts("=============OPERADOR DE MATRIZ=============");
	puts("============================================");
	puts("Escolha um dos numeros abaixo: ");
	puts("1. Carregar uma matriz do teclado");
	puts("2. Carregar uma matriz de um arquivo binario");
	puts("3. sair");
	scanf("%d",&mn1);

	//switch do menu1
	switch(mn1){
		case 1:
		system("cls"); //limpa a tela do usuario
		//sub-menu
		puts("Escolha a baixo o que deseja fazer:");
		printf("1. Imprimir a matriz na tela \n2. Alterar um elemento da matriz \n3. Salvar a matriz em um arquivo binario \n4. somar a matriz \n5. somar elementos adjacentes da matriz \n6. multiplicar matriz \n7. transpor a matriz \n8. verificar matriz identidade \n9. verificar matriz triangular superior \n10. verificar matriz triangular inferior \n11.sair \n");
		scanf("%d",&mn2);
		//switch do menu 2
		switch(mn2){
			//IMPRIMIR MATRIZ
			case 1:
				system("cls");
				//recebe linhas e colunas da matriz
				printf("digite as dimencoes de linha e coluna da matriz: ");
				scanf("%d %d",&lin1,&col1);
				
				//cria a matriz vazia
				mtrz1 = criaMatriz (lin1, col1);
				
				//carrega a matriz do teclado
				carregaMatrizTeclado (mtrz1, lin1, col1);
				
				//imprime a matriz ja preenchida
				imprimeMatriz (mtrz1,lin1, col1);
				
				//libera o espaço da matriz antes alocado
				destroiMatriz(mtrz1);
			break;

			//ALTERA ELEMENTO MATRIZ
			case 2:
				system("cls");
				//recebe linhas e colunas da matriz
				printf("digite as dimencoes de linha e coluna da matriz: ");
				scanf("%d %d",&lin1,&col1);

				//cria a matriz e carrega ela do teclado
				mtrz1 = criaMatriz(lin1,col1);
				carregaMatrizTeclado(mtrz1,lin1,col1);

				//pergunta qual posicao que quer ser mudada e o novo elemento
				printf("digite a posicao do elemento e o novo elemento para troca: \n");
				scanf("%d %d %d",&i,&j,&novoElem);
				
				//confere se o elemento existe, caso exista, o programa continua funcionando, se nao ele eh finalizado
				if((leElementoMatriz (mtrz1, lin1, col1, i, j, elem)) != 1){
					printf("elemento nao existente, programa finalizado. \n");
				}else{
					//altera o elemento na matriz
					alteraElementoMatriz (mtrz1,lin1,col1, i, j, novoElem);
					//imprime a matriz ja preenchida
					imprimeMatriz(mtrz1,lin1,col1);
					
					//libera o espaço da matriz antes alocado
					destroiMatriz(mtrz1);
				}
			break;

			//SALVA MATRIZ EM BINARIO
			case 3:
				system("cls");
				printf("digite as dimencoes de linha e coluna da matriz: ");
				scanf("%d %d",&lin1,&col1);
				getchar();
				
				//recebe o nome do arquivo
				printf("Digite o nome do arquivo que queira salvar(em .dat): ");
				scanf("%19[^\n]",nomeBin1);

				//cria a matriz e carrega ela do teclado
				mtrz1 = criaMatriz(lin1,col1);
				carregaMatrizTeclado(mtrz1,lin1,col1);

				//chama a funcao para salvar a matriz
				salvaMatrizBinario (mtrz1, lin1, col1, nomeBin1);
				
				//libera o espaço da matriz antes alocado
				destroiMatriz(mtrz1);
			break;

			//SOMA MATRIZ
			case 4:
				system("cls");
				printf("digite a dimencao da linha e coluna das duas matrizes: ");
				scanf("%d %d",&lin1,&col1);

				//cria a matriz e carrega ela do teclado
				mtrz1 = criaMatriz(lin1,col1);
				mtrz2 = criaMatriz(lin1,col1);	
				carregaMatrizTeclado(mtrz1,lin1,col1);
				carregaMatrizTeclado(mtrz2,lin1,col1);
				
				//chama a matriz soma de matriz e poem na matriz resultante	
				mtrzRes = somaMatrizes (mtrz1, mtrz2, lin1, col1);

				//imprime a matriz ja preenchida
				imprimeMatriz(mtrzRes,lin1,col1);

				//libera o espaço das matrizes antes alocado
				destroiMatriz(mtrz1);
				destroiMatriz(mtrz2);
				destroiMatriz(mtrzRes);
			break;

			//SOMA ELEMENTOS MATRIZ
			case 5:
				system("cls");
				printf("digite as dimencoes de linha e coluna da matriz: ");
				scanf("%d %d",&lin1,&col1);

				//cria a matriz e carrega ela do teclado
				mtrz1 = criaMatriz(lin1,col1);
				carregaMatrizTeclado(mtrz1,lin1,col1);

				//recebe a posicao do elemento para somar suas adjacencias
				printf("Digite a posicao do elemento para soma das adjacencias:");
				scanf("%d %d",&i,&j);

				//confere se a posicao do elemento existe, caso não, o programa e finalizado
				if((leElementoMatriz (mtrz1, lin1, col1, i, j, elem)) != 1){
					printf("elemento nao existente, programa finalizado. \n");
				}else{
					//chama a funcao de soma de adjacencias para somar os elementos adjacentes do elemento selecionado e aloca-los na soma
					somaAdjacentesElementoMatriz (mtrz1, lin1, col1, i, j, &soma);
					
					//printar a soma das adjacencias
					printf("a soma eh: %0.2f \n", soma);

					//libera o espaço da matriz antes alocado
					destroiMatriz(mtrz1);
				}
			break;

			//MULTIPLICA MATRIZ 
			case 6:
				system("cls");
				//recebe linhas e colunas das matrizes
				printf("digite as dimencoes de linha e coluna da matriz 1: ");
				scanf("%d %d",&lin1,&col1);
				printf("digite as dimencoes de linha e coluna da matriz 2: ");
				scanf("%d %d",&lin2,&col2);

				//confere se a linha da primeira matriz eh igual a coluna da segunda matriz, o mesmo com a linha da segunda com a coluna da primeira
				if(lin1 != col2 && lin2 != col1){
					printf("O tamanho das linhas da primeira matriz são diferentes das colunas da matriz 2, programa encerrado.");
					return 0;
				}else{
					//cria a matriz e carrega ela do teclado
					mtrz1 = criaMatriz(lin1,col1);
					mtrz2 = criaMatriz(lin2,col2);
					carregaMatrizTeclado(mtrz1,lin1,col1);
					carregaMatrizTeclado(mtrz2,lin2,col2);

					//chama a funcao para multiplicar as matrizes 1 e 2 e retorna na matriz resultante
					mtrzRes = multiplicaMatrizes (mtrz1, mtrz2, lin1, col1, col2);

					//imprime a matriz ja preenchida
					imprimeMatriz(mtrzRes,lin1,col2);

					//libera o espaço da matriz antes alocado
					destroiMatriz(mtrz1);
					destroiMatriz(mtrz2);
					destroiMatriz(mtrzRes);
				}
			break;

			//TRANSPOR MATRIZ
			case 7:
				system("cls");
				//recebe linha e coluna da matriz
				printf("digite as dimencoes de linha e coluna da matriz: ");
				scanf("%d %d",&lin1,&col1);

				//cria a matriz e carrega ela do teclado
				mtrz1 = criaMatrizZero (lin1, col1);
				carregaMatrizTeclado(mtrz1,lin1,col1);
			
				//chama a funcao para transpor a matriz 1 para a 2
				mtrz2 = transpostaMatriz (mtrz1, col1, lin1);

				//imprime a matriz ja preenchida
				imprimeMatriz(mtrz2,col1,lin1);
				
				//libera o espaço das matrizes antes alocado
				destroiMatriz(mtrz1);
				destroiMatriz(mtrz2);
			break;

			//VERIFICA MATRIZ IDENTIDADE
			case 8:
				system("cls");
				//recebe linha e coluna da matriz
				printf("digite as dimencoes de linha e coluna da matriz: ");
				scanf("%d %d",&lin1,&col1);
				
				//cria a matriz e carrega ela do teclado
				mtrz1 = criaMatriz(lin1,col1);
				carregaMatrizTeclado(mtrz1,lin1,col1);

				//chama a funcao para conferir a identidade, se for 1 a matriz e identidade, 0 ela nao eh
				if((ehMatrizIdentidade (mtrz1, lin1, col1) == 1)){
					printf("e matriz identidade! \n");
				}else{
					printf("nao e matriz identidade! \n");
				}

				//libera o espaço da matriz antes alocado
				destroiMatriz(mtrz1);
			break;

			//VERIFICA MATRIZ TRIANGULAR SUPERIOR
			case 9:
				system("cls");
				//recebe linha e coluna da matriz
				printf("digite as dimencoes de linha e coluna da matriz: ");
				scanf("%d %d",&lin1,&col1);

				//cria a matriz e carrega ela do teclado
				mtrz1 = criaMatriz(lin1,col1);
				carregaMatrizTeclado(mtrz1,lin1,col1);

				//chama a funcao para conferir a triangularidade superior, se for 1 a matriz e triangular superior, 0 ela nao eh
				if((ehMatrizTriangularSuperior (mtrz1, lin1, col1)) == 1){
					printf("eh matriz triangular superior \n");
				}else{
					printf("nao eh matriz triangular superior \n");
				}

				//libera o espaço da matriz antes alocado
				destroiMatriz(mtrz1);
			break;

			//VERIFICA MATRIZ TRIANGULAR INFERIOR		
			case 10:
				system("cls");
				printf("digite as dimencoes de linha e coluna da matriz: ");
				scanf("%d %d",&lin1,&col1);

				//cria a matriz e carrega ela do teclado
				mtrz1 = criaMatriz(lin1,col1);
				carregaMatrizTeclado(mtrz1,lin1,col1);

				//chama a funcao para conferir a triangularidade inferior, se for 1 a matriz e triangular inferior, 0 ela nao eh
				if((ehMatrizTriangularInferior(mtrz1, lin1, col1)) == 1){
					printf("eh matriz triangular inferior \n");
				}else{
					printf("nao eh matriz triangular inferior \n");
				}

				//libera o espaço da matriz antes alocado
				destroiMatriz(mtrz1);
			break;

			//SAIR
			case 11:
				system("cls");
				puts("obrigado, volte sempre !");
				system("pause");
				return 0;
			break;
		}

		break;
							//-----MENU 2 !!!!!
		case 2:
		system("cls");
		//sub-menu
		puts("Escolha a baixo o que deseja fazer:");
		printf("1. Imprimir a matriz na tela \n2. Alterar um elemento da matriz \n3. somar a matriz \n4. somar elementos adjacentes da matriz \n5. multiplicar matriz \n6. transpor a matriz \n7. verificar matriz identidade \n8. verificar matriz triangular superior \n9. verificar matriz triangular inferior \n10.sair \n");
		scanf("%d",&mn2);
		//switch do menu 2
		switch(mn2){
			//IMPRIMIR MATRIZ
			case 1:
				system("cls");
				getchar();
				//recebe o nome do arquivo binario
				printf("digite o nome do arquivo binario: ");
				scanf("%19[^\n]",nomeBin1);

				//abre o arquivo para leitura binaria
				arqBin1 = fopen(nomeBin1,"rb");

				//recebe a matriz do arquivo
				mtrz1 = carregaMatrizBinario(arqBin1,&lin1,&col1);
				
				//imprime a matriz ja preenchida
				imprimeMatriz(mtrz1,lin1,col1);
				
				//libera o espaço da matriz antes alocado
				destroiMatriz(mtrz1);

				//fecha o arquivo para leitura binaria
				fclose(arqBin1);
			break;

			//ALTERA ELEMENTO MATRIZ
			case 2:
				system("cls");
				getchar();
				//recebe o nome do arquivo binario
				printf("digite o nome do arquivo binario: ");
				scanf("%19[^\n]",nomeBin1);

				//abre o arquivo para leitura binaria
				arqBin1 = fopen(nomeBin1,"rb");

				//recebe a matriz do arquivo
				mtrz1 = carregaMatrizBinario(arqBin1,&lin1,&col1);

				//pergunta qual posicao que quer ser mudada e o novo elemento
				printf("digite a posicao do elemento e o novo elemento para troca: \n");
				scanf("%d %d %d",&i,&j,&novoElem);

				//confere se o elemento existe, caso exista, o programa continua funcionando, se nao ele eh finalizado
				if((leElementoMatriz (mtrz1, lin1, col1, i, j, elem)) != 1){
					printf("elemento nao existente, programa finalizado. \n");
				}else{
					//altera o elemento na matriz
					alteraElementoMatriz (mtrz1,lin1,col1, i, j, novoElem);
					//imprime a matriz ja preenchida
					imprimeMatriz(mtrz1,lin1,col1);
					
					//libera o espaço da matriz antes alocado
					destroiMatriz(mtrz1);
					//fecha o arquivo para leitura binaria
					fclose(arqBin1);
				}
			break;

			//SOMA MATRIZ
			case 3:
				system("cls");
				getchar();
				//recebe o nome dos dois arquivos binarios
				printf("digite o nome do primeiro arquivo binario: ");
				scanf("%19[^\n]",nomeBin1);
				getchar();
				printf("digite o nome do segundo arquivo binario: ");
				scanf("%19[^\n]",nomeBin2);
				getchar();

				//abre os arquivos para leitura binaria
				arqBin1 = fopen(nomeBin1,"rb");
				arqBin2 = fopen(nomeBin2,"rb");

				//recebe a matriz do arquivo
				mtrz1 = carregaMatrizBinario(arqBin1,&lin1,&col1);
				mtrz2 = carregaMatrizBinario(arqBin2,&lin1,&col1);

				//cria matriz resultante
				mtrzRes = criaMatrizZero(lin1,col1);

				//chama a matriz soma de matriz e poem na matriz resultante	
				mtrzRes = somaMatrizes(mtrz1,mtrz2,lin1,col1);

				//imprime a matriz ja preenchida
				imprimeMatriz(mtrzRes,lin1,col1);

				//libera o espaço da matriz antes alocado
				destroiMatriz(mtrz1);
				destroiMatriz(mtrz2);
				destroiMatriz(mtrzRes);
				
				//fecha os arquivos para leitura binaria
				fclose(arqBin1);
				fclose(arqBin2);
			break;

			//SOMA ELEMENTOS MATRIZ
			case 4:
				system("cls");
				getchar();
				//recebe o nome do arquivo binario
				printf("digite o nome do arquivo binario: ");
				scanf("%19[^\n]",nomeBin1);

				//recebe a posiçao do elemento para somar suas adjacencias
				printf("digite a posicao do elemento para a soma(Ex: 1 2): ");
				scanf("%d %d",&i,&j);

				//abre o arquivo para leitura binaria
				arqBin1 = fopen(nomeBin1,"rb");

				//recebe a matriz do arquivo
				mtrz1 = carregaMatrizBinario(arqBin1,&lin1,&col1);

				//confere se a posicao do elemento existe, caso não, o programa e finalizado
				if((leElementoMatriz (mtrz1, lin1, col1, i, j, elem)) != 1){
					printf("elemento nao existente, programa finalizado. \n");
				}else{
					//chama a funcao de soma de adjacencias para somar os elementos adjacentes do elemento selecionado e aloca-los na soma
					somaAdjacentesElementoMatriz (mtrz1, lin1, col1, i, j, &soma);
					
					//printar a soma das adjacencias
					printf("a soma eh: %0.2f \n", soma);

					//libera o espaço da matriz antes alocado
					destroiMatriz(mtrz1);

					//fecha os arquivos para leitura binaria
					fclose(arqBin1);
				}
			break;

			//MULTIPLICA MATRIZ
			case 5:
				system("cls");
				getchar();
				//recebe o nome dos dois arquivos binarios
				printf("digite o nome do primeiro arquivo binario: ");
				scanf("%19[^\n]",nomeBin1);
				getchar();
				printf("digite o nome do segundo arquivo binario: ");
				scanf("%19[^\n]",nomeBin2);
				getchar();

				//abre os arquivos para leitura binaria
				arqBin1 = fopen(nomeBin1,"rb");
				arqBin2 = fopen(nomeBin2,"rb");

				//recebe a matriz do arquivo
				mtrz1 = carregaMatrizBinario(arqBin1,&lin1,&col1);
				mtrz2 = carregaMatrizBinario(arqBin2,&lin2,&col2);

				//confere se a linha da primeira matriz eh igual a coluna da segunda matriz, o mesmo com a linha da segunda com a coluna da primeira
				if(lin1 != col2 && lin2 != col1){
					printf("O tamanho das linhas da primeira matriz são diferentes das colunas da matriz 2, programa encerrado.");
					return 0;
				}else{
					//chama a funcao para multiplicar as matrizes 1 e 2 e retorna na matriz resultante
					mtrzRes = multiplicaMatrizes (mtrz1, mtrz2, lin1, col1, col2);

					//imprime a matriz ja preenchida
					imprimeMatriz(mtrzRes,lin1,col1);

					//libera o espaço da matriz antes alocado
					destroiMatriz(mtrz1);
					destroiMatriz(mtrz2);
					destroiMatriz(mtrzRes);
				
					//fecha os arquivos para leitura binaria
					fclose(arqBin1);
					fclose(arqBin2);
				}
			break;

			//TRANSPOR MATRIZ
			case 6:
				system("cls");
				getchar();
				//recebe o nome do arquivo binario
				printf("digite o nome do arquivo binario: ");
				scanf("%19[^\n]",nomeBin1);
				getchar();

				//abre o arquivo para leitura binaria
				arqBin1 = fopen(nomeBin1,"rb");

				//recebe a matriz do arquivo
				mtrz1 = carregaMatrizBinario(arqBin1,&lin1,&col1);
				
				//chama a funcao para transpor a matriz 1 para a 2 com a coluna e a linha trocadas
				mtrz2 = transpostaMatriz (mtrz1, col1, lin1);

				//imprime a matriz ja preenchida
				imprimeMatriz(mtrz2,col1,lin1);
				
				//libera o espaço da matriz antes alocado
				destroiMatriz(mtrz1);
				destroiMatriz(mtrz2);
				
				//fecha os arquivos para leitura binaria
				fclose(arqBin1);

			break;

			//VERIFICA MATRIZ IDENTIDADE
			case 7:
				system("cls");
				getchar();
				//recebe o nome do arquivo binario
				printf("digite o nome do arquivo binario: ");
				scanf("%19[^\n]",nomeBin1);
				getchar();

				//abre o arquivo para leitura binaria
				arqBin1 = fopen(nomeBin1,"rb");
				
				//recebe a matriz do arquivo
				mtrz1 = carregaMatrizBinario(arqBin1,&lin1,&col1);

				//chama a funcao para conferir a identidade, se for 1 a matriz e identidade, 0 ela nao eh
				if((ehMatrizIdentidade (mtrz1, lin1, col1) == 1)){
					printf("e matriz identidade! \n");
				}else{
					printf("nao e matriz identidade! \n");
				}

				//libera o espaço da matriz antes alocado
				destroiMatriz(mtrz1);

				//fecha os arquivos para leitura binaria
				fclose(arqBin1);
			break;

			//VERIFICA MATRIZ TRIANGULAR SUPERIOR
			case 8:
				system("cls");
				getchar();
				//recebe o nome do arquivo binario
				printf("digite o nome do arquivo binario: ");
				scanf("%19[^\n]",nomeBin1);
				//abre o arquivo para leitura binaria
				arqBin1 = fopen(nomeBin1,"rb");
				
				mtrz1 = carregaMatrizBinario(arqBin1,&lin1,&col1);
				
				//chama a funcao para conferir a triangularidade superior, se for 1 a matriz e triangular superior, 0 ela nao eh
				if((ehMatrizTriangularSuperior (mtrz1, lin1, col1)) == 1){
					printf("eh matriz triangular superior \n");
				}else{
					printf("nao eh matriz triangular superior \n");
				}

				//libera o espaço da matriz antes alocado
				destroiMatriz(mtrz1);

				//fecha os arquivos para leitura binaria
				fclose(arqBin1);
			break;
			//VERIFICA MATRIZ TRIANGULAR INFERIOR		
			case 9:
				system("cls");
				getchar();
				//recebe o nome do arquivo binario
				printf("digite o nome do arquivo binario: ");
				scanf("%19[^\n]",nomeBin1);
				//abre o arquivo para leitura binaria
				arqBin1 = fopen(nomeBin1,"rb");
				
				mtrz1 = carregaMatrizBinario(arqBin1,&lin1,&col1);
					
				//chama a funcao para conferir a triangularidade inferior, se for 1 a matriz e triangular inferior, 0 ela nao eh
				if((ehMatrizTriangularInferior(mtrz1, lin1, col1)) == 1){
					printf("eh matriz triangular inferior \n");
				}else{
					printf("nao eh matriz triangular inferior \n");
				}

				//libera o espaço da matriz antes alocado
				destroiMatriz(mtrz1);

				//fecha os arquivos para leitura binaria
				fclose(arqBin1);

			break;
			//SAIR
			case 10:
				system("cls");
				puts("obrigado, volte sempre !");
				system("pause");
				return 0;
			break;
		}

		break;
		case 3:
			system("cls");
			puts("obrigado, volte sempre !");
			system("pause");
			return 0;
		break;
	}
	system("pause");
	return 0;
}