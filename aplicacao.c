#include<stdio.h>
#include<stdlib.h>

int main(void){
	//Variaveis
	int mn1,mn2;
	int lin1,col1,lin2,col2;
	//matrizes
	int *mtrz1,*mtrz2;

	//arquivos


	//Menu
	puts("============================================");
	puts("=============OPERADOR DE MATRIZ=============");
	puts("============================================");
	puts("Escolha um dos numeros abaixo: ");
	Puts("1. Carregar uma matriz do teclado");
	puts("2. Carregar uma matriz de um arquivo binario");
	puts("3. sair");
	scanf("%d",&mn1);

	//switch do menu1
	switch(mn1){
		case 1:
		system("cls"); //limpa a tela do usuario
		//sub-menu
		puts("Escolha a baixo o que deseja fazer:");
		printf("1. Imprimir a matriz na tela \n
				2. Alterar um elemento da matriz\n
				3. Salvar a matriz em um arquivo binario\n
				4. somar a matriz\n
				5. somar elementos adjacentes da matriz
				6. multiplicar matriz\n
				7. transpor a matriz\n
				8. verificar matriz identidade\n
				9. verificar matriz triangular superior\n
				10. verificar matriz triangular inferior\n
				11.sair\n");
		scanf("%d",&mn2);
		//switch do menu 2
		switch(mn2){
			//IMPRIMIR MATRIZ
			case 1:
				system("cls");
				//recebe linhas e colunas da matriz
				printf("digite as dimencoes de linha e coluna da matriz: ");
				scanf("%d %d",lin,col);
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
				scanf("%d %d",lin1,col1);
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
				scanf("%d %d",lin1,col1);
					//FUNCAO CRIA MATRIZ
					//FUNCAO CARREGA MATRIZ TECLADO
					//FUNCAO SALVA MATRIZ TECLADO
					//FUNCAO DESTROI MATRIZ
			break;
			//SOMA MATRIZ
			case 4:
				system("cls");
				printf("digite as dimencoes de linha e coluna da matriz 1: ");
				scanf("%d %d",lin1,col1);
				printf("digite as dimencoes de linha e coluna da matriz 2: ");
				scanf("%d %d",lin2,col2);
				if(lin1 != lin2 && col1 != col2){
					printf("As dimencoes das matrizes são diferentes, programa encerrado.");
					return 0;
				}else{
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
				scanf("%d %d",lin1,col1);

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
				scanf("%d %d",lin1,col1);
				printf("digite as dimencoes de linha e coluna da matriz 2: ");
				scanf("%d %d",lin2,col2);
				if(lin1 != col2 && lin2 != col1){
					printf("O tamanho das linhas da primeira matriz são diferentes das colunas da matriz 2, programa encerrado.");
					return 0;
				}else{
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
				scanf("%d %d",lin1,col1);

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
				scanf("%d %d",lin1,col1);

					//FUNCAO CRIA MATRIZ
					//FUNCAO MATRIZ IDENTIDADE
					//RESULTADO
					//FUNCAO DESTROI MATRIZ
			break;
			//VERIFICA MATRIZ TRIANGULAR SUPERIOR
			case 9:
				system("cls");
				printf("digite as dimencoes de linha e coluna da matriz: ");
				scanf("%d %d",lin1,col1);

					//FUNCAO CRIA MATRIZ
					//FUNCAO MATRIZ TRIANGULAR SUPERIOR
					//RESULTADO
					//FUNCAO DESTROI MATRIZ
			break;
			//VERIFICA MATRIZ TRIANGULAR INFERIOR		
			case 10:
				system("cls");
				printf("digite as dimencoes de linha e coluna da matriz: ");
				scanf("%d %d",lin1,col1);

					//FUNCAO CRIA MATRIZ
					//FUNCAO MATRIZ TRIANGULAR INFERIOR
					//RESULTADO
					//FUNCAO DESTROI MATRIZ
			break;
			//SAIR
			case 11:
				system("cls");
			break;
		}

		break;

		case 2:
		system("cls");

		break;
	}
	system("pause");
	return 0;
}