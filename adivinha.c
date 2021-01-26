#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TENTATIVAS_FACIL 40
#define TENTATIVAS_MEDIO 15
#define TENTATIVAS_DIFICIL 3

int main()
{

	{
		printf("/***IsDR\n");
		printf("*                .___.__      .__       .__            \n");
		printf("*    _____     __| _/|__|__  _|__| ____ |  |__ _____   \n");
		printf("*    \\__  \\   / __ | |  \\  \\/ /  |/    \\|  |  \\__   \\  \n");
		printf("*     / __ \\_/ /_/ | |  |\\   /|  |   |  \\   Y  \\/ __ \\_\n");
		printf("*    (____  /\\____ | |__| \\_/ |__|___|  /___|  (____  /\n");
		printf("*         \\/      \\/                  \\/     \\/     \\/ \n");
		printf(" */\n");

		int chute;
		int acertou = 0;
		int tentativas = 1;
		double pontos = 1000;
		int nivel;
		int total_tentativas;
		int tentativas_personalizadas;
		int numero_personalizado;
		int numerosecreto;

		printf("Qual o nivel de dificuldade?\n");
		printf("(1) Facil (2) Medio (3) Dificil (4) Personalizado\n\n");
		printf("Escolha: ");
		scanf("%d", &nivel);

		switch (nivel)
		{
		case 1:
			total_tentativas = TENTATIVAS_FACIL;
			break;
		case 2:
			total_tentativas = TENTATIVAS_MEDIO;
			break;
		case 3:
			total_tentativas = TENTATIVAS_DIFICIL;
			break;
		default:
			while (numero_personalizado < 1 || numero_personalizado > 1500)
			{
				printf("Escolha a quantidade de numeros entre 1 e 1500: ");
				scanf("%d", &numero_personalizado);
			}
			while (tentativas_personalizadas < 1 || tentativas_personalizadas > 99)
			{
				printf("Escolha a quantidade de tentativas entre 1 e 99: ");
				scanf("%d", &tentativas_personalizadas);
				total_tentativas = tentativas_personalizadas;
			}

			break;
		}

		srand(time(0));
		if (nivel <= 3)
		{
			numerosecreto = rand() % 100;
		}
		else
		{
			numerosecreto = rand() % numero_personalizado;
		}

		int outravariavel = pontos * 7;

		for (int i = 1; i <= total_tentativas; i++)
		{
			printf("\n->Tentativa %d de %d\n", i, total_tentativas);
			printf("=>Chute um numero: ");
			scanf("%d", &chute);

			if (chute < 0)
			{
				printf("Voce nao pode chutar numeros negativos.\n");
				i--;
				continue;
			}
			printf("Seu %do. chute foi %d\n", tentativas, chute);

			acertou = chute == numerosecreto;
			int maior = chute > numerosecreto;

			if (acertou)
			{
				break;
			}
			else if (maior)
			{
				printf("\nSeu chute foi maior do que o numero secreto\n");
			}
			else
			{
				printf("\nSeu chute foi menor do que o numero secreto\n");
			}
			tentativas++;

			double pontos_perdidos = abs(chute - numerosecreto) / 2.0;
			pontos = pontos - pontos_perdidos;
		}
		printf("\n");
		if (acertou)
		{
			printf("              OOOOOOOOOOO               \n");
			printf("          OOOOOOOOOOOOOOOOOOO           \n");
			printf("       OOOOOO  OOOOOOOOO  OOOOOO        \n");
			printf("     OOOOOO      OOOOO      OOOOOO      \n");
			printf("   OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
			printf("  OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
			printf(" OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
			printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
			printf(" OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
			printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
			printf("  OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
			printf("   OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
			printf("     OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
			printf("       OOOOOO   OOOOOOOOO   OOOOOO      \n");
			printf("          OOOOOO         OOOOOO         \n");
			printf("              OOOOOOOOOOOOO             \n");
			printf("\nParabens! Voce acertou!\n");
			printf("Voce fez %.2f pontos. Ate a proxima!\n\n", pontos);
		}
		else
		{

			printf("       \\|/ ____ \\|/    \n");
			printf("        @~/ ,. \\~@      \n");
			printf("       /_( \\__/ )_\\    \n");
			printf("          \\__U_/        \n");

			printf("\nVoce perdeu! Tente novamente!\n\n");
		}
	}
	printf("Obrigado por jogar.\n");
};