#include<stdio.h>
#include<stdlib.h>

int main(void){
	//Variaveis
	int mn1, mn2, i, j;
	int lin1, col1, lin2, col2;
	char nomeBin1[20],nomeBin2[20];

	//matrizes
	int *mtrz1, *mtrz2;

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
		printf("1. Imprimir a matriz na tela \n2. Alterar um elemento da matriz \n3. Salvar a matriz em um arquivo binario \n4. somar a matriz \n5.somar elementos adjacentes da matriz \n6. multiplicar matriz \n7. transpor a matriz \n8. verificar matriz identidade \n9. verificar matriz triangular superior \n10. verificar matriz triangular inferior \n11.sair \n");
		scanf("%d",&mn2);
		//switch do menu 2
		switch(mn2){
			//IMPRIMIR MATRIZ
			case 1:
				system("cls");
				//recebe linhas e colunas da matriz
				printf("digite as dimencoes de linha e coluna da matriz: ");
				scanf("%d %d",&lin1,&col1);
					printf("%d %d teste \n",lin1,col1 );
					//FUNCAO CRIA MATRIZ
					//FUNCAO CARREGA MATRIZ TECLADO
					//FUNCAO IMPRIME MATRIZ
					//DESTROI MATRIZ

			break;
			//ALTERA ELEMENTO MATRIZ
			case 2:
				system("cls");
				//recebe linhas e colunas da matriz
				printf("digite as dimencoes de linha e coluna da matriz: ");
				scanf("%d %d",&lin1,&col1);
				printf("%d %d teste \n",lin1,col1 );
					//FUNCAO CRIA MATRIZ
					//FUNCAO CARREGA MATRIZ TECLADO
					//FUNCAO TROCA ELEMENTO MATRIZ
					//FUNCAO IMPRIME MATRIZ
					//FUNCAO DESTROI MATRIZ
			break;
			//SALVA MATRIZ EM BINARIO
			case 3:
				system("cls");
				printf("digite as dimencoes de linha e coluna da matriz: ");
				scanf("%d %d",&lin1,&col1);
				printf("%d %d teste \n",lin1,col1 );
					//FUNCAO CRIA MATRIZ
					//FUNCAO CARREGA MATRIZ TECLADO
					//FUNCAO SALVA MATRIZ TECLADO
					//FUNCAO DESTROI MATRIZ
			break;
			//SOMA MATRIZ
			case 4:
				system("cls");
				printf("digite as dimencoes de linha e coluna da matriz 1: ");
				scanf("%d %d",&lin1,&col1);
				printf("digite as dimencoes de linha e coluna da matriz 2: ");
				scanf("%d %d",&lin2,&col2);
				if(lin1 != lin2 && col1 != col2){
					printf("As dimencoes das matrizes são diferentes, programa encerrado.");
					return 0;
				}else{
					printf("%d %d teste \n",lin1,col1 );
					printf("%d %d teste \n",lin2,col2 );
					//FUNCAO CRIA MATRIZ 1
					//FUNCAO CRIA MATRIZ 2
					//FUNCAO SOMA MATRIZ
					//FUNCAO IMPRIME MATRIZ RESULTADO
					//FUNCAO DESTROI MATRIZ 1 2 E RESULTADO
				}
			break;
			//SOMA ELEMENTOS MATRIZ
			case 5:
				system("cls");
				printf("digite as dimencoes de linha e coluna da matriz: ");
				scanf("%d %d",&lin1,&col1);
				printf("%d %d teste \n",lin1,col1 );
					//FUNCAO CRIA MATRIZ
					//FUNCAO LE MATRIZ
					//FUNCAO SOMA ELEMENTOS MATRIZ
					//FUNCAO IMPRIME MATRIZ RESULTADO
					//FUNCAO DESTROI MATRIZ
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
					printf("%d %d teste \n",lin1,col1 );
					printf("%d %d teste \n",lin2,col2 );
					//FUNCAO CRIA MATRIZ 1
					//FUNCAO CRIA MATRIZ 2
					//FUNCAO MULTIPLICA MATRIZ
					//FUNCAO IMPRIME MATRIZ RESULTADO
					//FUNCAO DESTROI MATRIZ 1 2 E RESULTADO
				}
			break;
			//TRANSPOR MATRIZ
			case 7:
				system("cls");
				printf("digite as dimencoes de linha e coluna da matriz: ");
				scanf("%d %d",&lin1,&col1);
				printf("%d %d teste \n",lin1,col1 );
					//FUNCAO CRIA MATRIZ
					//FUNCAO CRIA MATRIZ ZERO
					//FUNCAO TRANSPOR MATRIZ
					//FUNCAO IMPRIME MATRIZ 2
					//FUNCAO DESTROI MATRIZ 1 E 2

			break;
			//VERIFICA MATRIZ IDENTIDADE
			case 8:
				system("cls");
				printf("digite as dimencoes de linha e coluna da matriz: ");
				scanf("%d %d",&lin1,&col1);
				printf("%d %d teste \n",lin1,col1 );
					//FUNCAO CRIA MATRIZ
					//FUNCAO MATRIZ IDENTIDADE
					//RESULTADO
					//FUNCAO DESTROI MATRIZ
			break;
			//VERIFICA MATRIZ TRIANGULAR SUPERIOR
			case 9:
				system("cls");
				printf("digite as dimencoes de linha e coluna da matriz: ");
				scanf("%d %d",&lin1,&col1);
				printf("%d %d teste \n",lin1,col1 );
					//FUNCAO CRIA MATRIZ
					//FUNCAO MATRIZ TRIANGULAR SUPERIOR
					//RESULTADO
					//FUNCAO DESTROI MATRIZ
			break;
			//VERIFICA MATRIZ TRIANGULAR INFERIOR		
			case 10:
				system("cls");
				printf("digite as dimencoes de linha e coluna da matriz: ");
				scanf("%d %d",&lin1,&col1);
				printf("%d %d teste \n",lin1,col1 );
					//FUNCAO CRIA MATRIZ
					//FUNCAO MATRIZ TRIANGULAR INFERIOR
					//RESULTADO
					//FUNCAO DESTROI MATRIZ
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
					printf("%s teste \n",nomeBin1);
					//FUNCAO CRIA MATRIZ ZERADA
					//FUNCAO CARREGA MATRIZ BINARIO
					//FUNCAO IMPRIME MATRIZ
					//DESTROI MATRIZ

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
				printf("%s teste \n",nomeBin1);
					//FUNCAO CRIA MATRIZ ZERADA
					//FUNCAO CARREGA MATRIZ BINARIA
					//FUNCAO TROCA ELEMENTO MATRIZ
					//FUNCAO IMPRIME MATRIZ
					//FUNCAO DESTROI MATRIZ
			break;
			//SOMA MATRIZ
			case 3:
				system("cls");
				getchar();
				//recebe o nome dos dois arquivos binarios
				printf("digite o nome do primeiro arquivo binario: ");
				scanf("%19[^\n]",nomeBin1);
				printf("digite o nome do segundo arquivo binario: ");
				scanf("%19[^\n]",nomeBin2);
				//abre os arquivos para leitura binaria
				arqBin1 = fopen(nomeBin1,"rb");
				arqBin2 = fopen(nomeBin2,"rb");
				//verifica se a dimensoes são iguais
					printf("%s teste \n",nomeBin1);
					printf("%s teste \n",nomeBin2);
					//FUNCAO CRIA MATRIZ ZERADA 1
					//FUNCAO CARREGA MATRIZ BINARIA 1
					//FUNCAO CRIA MATRIZ ZERADA 2
					//FUNCAO CARREGA MATRIZ BINARIA 2
					//FUNCAO SOMA MATRIZ
					//FUNCAO IMPRIME MATRIZ RESULTADO
					//FUNCAO DESTROI MATRIZ 1 2 E RESULTADO
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
				printf("%s teste \n",nomeBin1);
					//FUNCAO CRIA MATRIZ ZERADA
					//FUNCAO CARREGA MATRIZ BINARIA
					//FUNCAO LE ELEMENTO MATRIZ
					//FUNCAO SOMA ELEMENTOS MATRIZ
					//FUNCAO IMPRIME MATRIZ RESULTADO
					//FUNCAO DESTROI MATRIZ
			break;
			//MULTIPLICA MATRIZ
			case 5:
				system("cls");
				getchar();
				//recebe o nome dos dois arquivos binarios
				printf("digite o nome do primeiro arquivo binario: ");
				scanf("%19[^\n]",nomeBin1);
				printf("digite o nome do segundo arquivo binario: ");
				scanf("%19[^\n]",nomeBin2);
				//abre os arquivos para leitura binaria
				arqBin1 = fopen(nomeBin1,"rb");
				arqBin2 = fopen(nomeBin2,"rb");

					printf("%s teste \n",nomeBin1);
					printf("%s teste \n",nomeBin2);
					//FUNCAO CRIA MATRIZ ZERADA 1
					//FUNCAO CARREGA MATRIZ BINARIA 1
					//FUNCAO CRIA MATRIZ 2
					//FUNCAO CARREGA MATRIZ BINARIA 2
					//FUNCAO MULTIPLICA MATRIZ
					//FUNCAO IMPRIME MATRIZ RESULTADO
					//FUNCAO DESTROI MATRIZ 1 2 E RESULTADO
			break;
			//TRANSPOR MATRIZ
			case 6:
				system("cls");
				getchar();
				//recebe o nome do arquivo binario
				printf("digite o nome do arquivo binario: ");
				scanf("%19[^\n]",nomeBin1);
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
				//abre o arquivo para leitura binaria
				arqBin1 = fopen(nomeBin1,"rb");
				printf("%s teste \n",nomeBin1);
					//FUNCAO CRIA MATRIZ ZERADA
					//FUNCAO CARREGA MATRIZ BINARIA
					//FUNCAO MATRIZ IDENTIDADE
					//RESULTADO
					//FUNCAO DESTROI MATRIZ
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
				printf("%s teste \n",nomeBin1);
					//FUNCAO CRIA MATRIZ ZERADA
					//FUNCAO CARREGA MATRIZ BINARIA
					//FUNCAO MATRIZ TRIANGULAR SUPERIOR
					//RESULTADO
					//FUNCAO DESTROI MATRIZ
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
				printf("%s teste \n",nomeBin1);
					//FUNCAO CRIA MATRIZ ZERADA
					//FUNCAO CARREGA MATRIZ BINARIA
					//FUNCAO MATRIZ TRIANGULAR INFERIOR
					//RESULTADO
					//FUNCAO DESTROI MATRIZ
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