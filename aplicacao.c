#include<stdio.h>
#include<stdlib.h>
#include"matriz.h"

int main(void){
	//Variaveis
	int mn1, mn2, i, j,novoElem;
	int lin1, col1, lin2, col2;
	float soma;
	char nomeBin1[20],nomeBin2[20];

	//matrizes
	float *mtrz1, *mtrz2,*mtrzRes;

	//arquivos
	FILE* arqBin1;
	FILE* arqBin2;

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
				//altera o elemento na matriz
				alteraElementoMatriz (mtrz1,lin1,col1, i, j, novoElem);

				imprimeMatriz(mtrz1,lin1,col1);
				destroiMatriz(mtrz1);

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

				mtrz1 = criaMatriz(lin1,col1);
				carregaMatrizTeclado(mtrz1,lin1,col1);
				//chama a funcao para salvar a matriz
				salvaMatrizBinario (mtrz1, lin1, col1, nomeBin1);
				destroiMatriz(mtrz1);
			break;
			//SOMA MATRIZ
			case 4:
				system("cls");
				printf("digite as dimencoes de linha e coluna das duas matrizes: ");
				scanf("%d %d",&lin1,&col1);
					mtrz1 = criaMatriz(lin1,col1);
					mtrz2 = criaMatriz(lin1,col1);
					mtrzRes = criaMatriz(lin1,col1);
					carregaMatrizTeclado(mtrz1,lin1,col1);
					carregaMatrizTeclado(mtrz2,lin1,col1);
					mtrzRes = somaMatrizes (mtrz1, mtrz2, lin1, col1);
					imprimeMatriz(mtrzRes,lin1,col1);
					destroiMatriz(mtrz1);
					destroiMatriz(mtrz2);
					destroiMatriz(mtrzRes);
			break;
			//SOMA ELEMENTOS MATRIZ
			case 5:
				system("cls");
				printf("digite as dimencoes de linha e coluna da matriz: ");
				scanf("%d %d",&lin1,&col1);

				mtrz1 = criaMatriz(lin1,col1);
				carregaMatrizTeclado(mtrz1,lin1,col1);

				printf("Digite a posicao do elemento para soma das adjacencias:");
				scanf("%d %d",&i,&j);

				somaAdjacentesElementoMatriz (mtrz1, lin1, col1, i, j, &soma);
				printf("a soma eh: %0.2f \n", soma);
				destroiMatriz(mtrz1);
			break;
			//MULTIPLICA MATRIZ
			case 6:
				system("cls");
				printf("digite as dimencoes de linha e coluna da matriz 1: ");
				scanf("%d %d",&lin1,&col1);
				printf("digite as dimencoes de linha e coluna da matriz 2: ");
				scanf("%d %d",&lin2,&col2);
				if(lin1 != col2 && lin2 != col1){
					printf("O tamanho das linhas da primeira matriz são diferentes das colunas da matriz 2, programa encerrado.");
					return 0;
				}else{
					mtrz1 = criaMatriz(lin1,col1);
					mtrz2 = criaMatriz(lin1,col1);
					mtrzRes = criaMatriz(lin1,col1);
					carregaMatrizTeclado(mtrz1,lin1,col1);
					carregaMatrizTeclado(mtrz2,lin1,col1);
					//chama a funcao para multiplicar as matrizes 1 e 2 e retorna na matriz resultante
					mtrzRes = multiplicaMatrizes (mtrz1, mtrz2, lin1, col1, col2);
					imprimeMatriz(mtrzRes,lin1,col1);
					destroiMatriz(mtrz1);
					destroiMatriz(mtrz2);
					destroiMatriz(mtrzRes);
				}
			break;
			//TRANSPOR MATRIZ
			case 7:
				system("cls");
				printf("digite as dimencoes de linha e coluna da matriz: ");
				scanf("%d %d",&lin1,&col1);
				printf("%d %d teste \n",lin1,col1 );
					mtrz1 = criaMatrizZero (lin1, col1);
					carregaMatrizTeclado(mtrz1,lin1,col1);
					//chama a funcao para transpor a matriz 1 para a 2
					mtrz2 =transpostaMatriz (mtrz1, lin1, col1);
					imprimeMatriz(mtrz2,col1,lin1);
					destroiMatriz(mtrz1);
					destroiMatriz(mtrz2);

			break;
			//VERIFICA MATRIZ IDENTIDADE
			case 8:
				system("cls");
				printf("digite as dimencoes de linha e coluna da matriz: ");
				scanf("%d %d",&lin1,&col1);
					mtrz1 = criaMatriz(lin1,col1);
					carregaMatrizTeclado(mtrz1,lin1,col1);
					if((ehMatrizIdentidade (mtrz1, lin1, col1) == 1)){
						printf("e matriz identidade! \n");
					}else{
						printf("nao e matriz identidade! \n");
					}
					destroiMatriz(mtrz1);

			break;
			//VERIFICA MATRIZ TRIANGULAR SUPERIOR
			case 9:
				system("cls");
				printf("digite as dimencoes de linha e coluna da matriz: ");
				scanf("%d %d",&lin1,&col1);
					mtrz1 = criaMatriz(lin1,col1);
					carregaMatrizTeclado(mtrz1,lin1,col1);
					if((ehMatrizTriangularSuperior (mtrz1, lin1, col1)) == 1){
						printf("eh matriz triangular superior \n");
					}else{
						printf("nao eh matriz triangular superior \n");
					}
					destroiMatriz(mtrz1);
			break;
			//VERIFICA MATRIZ TRIANGULAR INFERIOR		
			case 10:
				system("cls");
				printf("digite as dimencoes de linha e coluna da matriz: ");
				scanf("%d %d",&lin1,&col1);
					mtrz1 = criaMatriz(lin1,col1);
					carregaMatrizTeclado(mtrz1,lin1,col1);
					if((ehMatrizTriangularInferior(mtrz1, lin1, col1)) == 1){
						printf("eh matriz triangular inferior \n");
					}else{
						printf("nao eh matriz triangular inferior \n");
					}
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
				mtrz1 = carregaMatrizBinario(arqBin1,&lin1,&col1);
				imprimeMatriz(mtrz1,lin1,col1);
				destroiMatriz(mtrz1);
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
				mtrz1 = carregaMatrizBinario(arqBin1,&lin1,&col1);

				printf("digite a posicao do elemento e o novo elemento para troca: \n");
				scanf("%d %d %d",&i,&j,&novoElem);
				alteraElementoMatriz (mtrz1, lin1, col1, i, j, novoElem);
				salvaMatrizBinario(mtrz1,lin1,col1,nomeBin1);

				imprimeMatriz(mtrz1,lin1,col1);
				destroiMatriz(mtrz1);
				fclose(arqBin1);
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
				mtrz1 = carregaMatrizBinario(arqBin1,&lin1,&col1);
				mtrz2 = carregaMatrizBinario(arqBin2,&lin1,&col1);
				mtrzRes = criaMatrizZero(lin1,col1);

				mtrzRes = somaMatrizes(mtrz1,mtrz2,lin1,col1);
				imprimeMatriz(mtrzRes,lin1,col1);

				destroiMatriz(mtrz1);
				destroiMatriz(mtrz2);
				destroiMatriz(mtrzRes);
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
				mtrz1 = carregaMatrizBinario(arqBin1,&lin1,&col1);
				//FUNCAO LE ELEMENTO MATRIZ
				somaAdjacentesElementoMatriz (mtrz1, lin1, col1, i, j, &soma);
				printf("a soma eh: %0.2f \n", soma);
				destroiMatriz(mtrz1);
				fclose(arqBin1);
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

				mtrz1 = carregaMatrizBinario(arqBin1,&lin1,&col1);
				mtrz2 = carregaMatrizBinario(arqBin2,&lin2,&col2);
				mtrzRes = criaMatrizZero(lin1,col1);
				
				mtrzRes = multiplicaMatrizes (mtrz1, mtrz2, lin1, col1, col2);

				imprimeMatriz(mtrzRes,lin1,col1);
				destroiMatriz(mtrz1);
				destroiMatriz(mtrz2);
				destroiMatriz(mtrzRes);
				fclose(arqBin1);
				fclose(arqBin2);
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
				printf("%s teste \n",nomeBin1);
					//FUNCAO CRIA MATRIZ ZERADA
					//FUNCAO CARREGA MATRIZ BINARIA
					//FUNCAO CRIA MATRIZ ZERO
					//FUNCAO TRANSPOR MATRIZ
					//FUNCAO IMPRIME MATRIZ 1 2
					//FUNCAO DESTROI MATRIZ 1 E 2

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
				
				mtrz1 = carregaMatrizBinario(arqBin1,&lin1,&col1);

				if((ehMatrizIdentidade (mtrz1, lin1, col1) == 1)){
					printf("e matriz identidade! \n");
				}else{
					printf("nao e matriz identidade! \n");
				}

				destroiMatriz(mtrz1);
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
				
				if((ehMatrizTriangularSuperior (mtrz1, lin1, col1)) == 1){
					printf("eh matriz triangular superior \n");
				}else{
					printf("nao eh matriz triangular superior \n");
				}

				destroiMatriz(mtrz1);
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
					
				if((ehMatrizTriangularInferior(mtrz1, lin1, col1)) == 1){
					printf("eh matriz triangular inferior \n");
				}else{
					printf("nao eh matriz triangular inferior \n");
				}

				destroiMatriz(mtrz1);
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