#include <iostream>
#include <stdio.h> // strandart in out
#include <stdlib.h>// strandart library 
#include <math.h> // funções math
#include <locale.h> // title case
#define LIN 6 
#define COL 6
#include <time.h>
#include <ctype.h>
#include <unistd.h>


void ClearTabuleiro(char tabuleiro[LIN][COL])
{
	
	for(int aux = 0; aux < LIN; aux++)
	{
		for(int aux2 = 0; aux2 < COL; aux2++)
		{
			tabuleiro[aux][aux2] = ' ';
		}
	}
}

void ImprimirTabuleiro(char tabuleiro[LIN][COL])
	{
		
 printf("   A    B    C    D    E    F ");
		for(int aux = 0; aux < LIN; aux++)
		{
			printf("\n --------------------------------\n");
			printf("%d", aux);
			for(int aux2 = 0; aux2 < COL; aux2++)
			{
				printf("| %c |", tabuleiro[aux][aux2]);
			}
		}
		printf("\n --------------------------------\n");
	
	}

int ValidarColuna(char coluna)
{
	if(coluna =='A'){
		return 0;
	}
	else if(coluna =='B'){
		return 1;
	}
	else if(coluna =='C'){
		return 2;
	}
	else if(coluna =='D'){
		return 3;
	}
	else if(coluna =='E'){
		return 4;
	}
	else if(coluna =='F'){
		return 5;
	}
	else{
		return 6;
	}
	
}

int main() {
	

	srand(time(NULL));
	int ColunaRobo;
	int LinhaRobo;  // num aleatorio
	char Robo[COL][LIN];
	ClearTabuleiro(Robo); 
	char RoboTabuleiro[LIN][COL];
	ClearTabuleiro(RoboTabuleiro);
	// var para o robo
	
	int linha;
	char coluna;
	char Jogador[COL][LIN];
	ClearTabuleiro(Jogador);
	
	// variaveis para jogador
	
	setlocale(LC_ALL, "Portuguese"); 
	char tabuleiro[LIN][COL];
	ClearTabuleiro(tabuleiro);
	
	// tabuleiro para o jogador jogar

	// tabuleiro robo preencher
	for(int aux = 0; aux < 6; aux++)
	{
		ColunaRobo = rand()%6; 
		LinhaRobo = rand()%6; 
		
		if(Robo[LinhaRobo][ColunaRobo] == ' ')
		{
		Robo[LinhaRobo][ColunaRobo] = 'N'; // gera psoição aleatoria de navio
		}
		else{
			aux--;
		}
	
	}

	// tabuleiro jogador preencher
	for(int aux = 0; aux < 6 ; aux++)
	{
		ImprimirTabuleiro(Jogador);
		
		printf("\nInsira a posição do %dº navio", aux+1);
		printf("\nLinha:");
			scanf("%d", &linha);
			
		printf("\nColuna:");
			scanf(" %c", &coluna);
			coluna = toupper(coluna); 
		// inserir  navio jogador
			
		if(coluna == 'A')
		{
			if(Jogador[linha][0]  == ' ')
			{
			    Jogador[linha][0] = 'X';
			    system("cls");
			}
			else
			{

			    system("cls");
			    printf(" \n Por favor, tente novamente, creio que deu algum problema ao inserir :/ \n");
			    aux--;
		    }
			
		}
		else if(coluna== 'B')
		{
			if(Jogador[linha][1]  == ' ')
			{
			    Jogador[linha][1]  = 'X';
			    system("cls");
			}
			else
			{
			    system("cls");
			    printf(" \n Por favor, tente novamente, creio que deu algum problema ao inserir :/ \n");
			    aux--;
		    }
		}
		else if(coluna == 'C')
		{
			if(Jogador[linha][2]  == ' ')
			{
			   Jogador[linha][2] = 'X';
			    system("cls");
			}
			else
			{
			    system("cls");
			    printf(" \nPor favor, tente novamente, creio que deu algum problema ao inserir :/ \n");
			    aux--;
		    }
		}
		else if(coluna== 'D')
		{
			if(Jogador[linha][3] == ' ')
			{
			    Jogador[linha][3] = 'X';
			    system("cls");
			}
			else
			{
			    system("cls");
			    printf("\nPor favor, tente novamente, creio que deu algum problema ao inserir :/ \n");
			    aux--;
		    }
		}
		else if(coluna == 'E')
		{
			if(Jogador[linha][4] == ' ')
			{
			    Jogador[linha][4] = 'X';
			    system("cls");
			}
			else
			{
			    system("cls");
			     printf("\nPor favor, tente novamente, creio que deu algum problema ao inserir :/ \n");
			     aux--;
		    }
		}
		else if(coluna == 'F')
		{
			if(Jogador[linha][5] == ' ')
			{
			    Jogador[linha][5] = 'X';
			    system("cls");
			}
			else
			{
			    system("cls");
			    printf("\nPor favor, tente novamente, creio que deu algum problema ao inserir :/ \n");
			     aux--;
		    }
		}
		else
		{
			system("cls");
			printf("\nPor favor, tente novamente, creio que deu algum problema ao inserir :/ \n");
			aux--;
		}
	}
	
	
	// jogo em si
	
	int PntJogador;
	PntJogador = 0;
	int PntRobo;
	PntRobo = 0;
	int InC;
	while(PntJogador < 6 && PntRobo < 6 )
	{
		
		for(int aux = 0; aux < 1; aux ++)
		{
			system("cls");
			printf("\nPontos robo %d", PntRobo);
			printf("\nPontos jogador %d\n", PntJogador);
		ImprimirTabuleiro(tabuleiro);
		printf("\nInsira a linha a qual você quer atacar  ");
			scanf(" %d", &linha);
			
		printf("\nInsira a coluna a qual você quer atacar  ");
			scanf(" %c", &coluna);
			coluna = toupper(coluna);	
			// jogador insere dados de ataque
		InC = ValidarColuna(coluna);
		if( InC >= 0 && InC< 6 && linha >= 0 && linha < 6  && tabuleiro[linha][InC] == ' ')
		{
			tabuleiro[linha][InC] = 'O';
			system("cls");
			break;
		}
		else
		{
			system("cls");
			printf("\nVocê inseriu uma posição invalida, por favor tente novamente\n");
			aux --; // validação se foi uma posição valida
		}
		}
		
		// jogada de ataque robo
		for(int aux = 0; aux < 1; aux ++)
		{ // jogada de robo 
			
		ColunaRobo = rand()%6; 
		LinhaRobo = rand()%6;
		
		if(RoboTabuleiro[LinhaRobo][ColunaRobo] == ' ')
		{
			RoboTabuleiro[LinhaRobo][ColunaRobo] = 'N'; // gera psoição aleatoria de navio
			break;
		}
		else
		{
			aux--;
			continue;
		}
		}
		
		
		// verificação se alguem acertou alguem
		if(	Robo[linha][InC] != ' '  )
		{// validar se o jogador acertou o inimigo
			printf("\n Barco inimigo ao chão");
			tabuleiro[linha][InC] = 'X' ;
			PntJogador ++;
		}
		else
		{	
			printf("\nErrou Feio");
		}

		if(	Jogador[LinhaRobo][ColunaRobo] != ' '  )
		{// validar se o jogador acertou o inimigo
			printf("\n O robo acertou o seu barco benhê");
			RoboTabuleiro[LinhaRobo][ColunaRobo] = 'X' ;
			PntRobo ++;
		}
		else
		{
			printf("\nO robo passou longe do seu barco ! Uffaaa");
			
		}
		
		sleep(2);

}

// final de jogo
	system("cls");
	if(PntJogador == 6)
	{
		printf("\nParabens! VocÊ ganhou !");
	}
	else if ( PntRobo == 6)
	{
		printf("\n Ih parceiro você perdeu!");
	}
}