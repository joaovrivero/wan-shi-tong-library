#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

int main()
{

	Lista listaLivros;
	Fila filaLivrosRetirados;
	inicializarLista(&listaLivros);
	inicializarFila(&filaLivrosRetirados);

	int opcao, livrosRetirados = 0;

	do
	{

		printf("\n=================================== ## WAN SHI TONG'S LIBRARY ## ===================================\n");
		printf("\n");
		printf("==================================================\n");
		printf("##		1. Adicionar livro\n");
		printf("==================================================\n");
		printf("##		2. Exibir lista de livros\n");
		printf("==================================================\n");
		printf("##		3. Retirar livro\n");
		printf("==================================================\n");
		printf("##		4. Exibir livros retirados\n");
		printf("==================================================\n");
		printf("##		5. Devolver livro\n");
		printf("==================================================\n");
		printf("##		6. Sair\n");
		printf("==================================================\n");
		printf("\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao);

		switch (opcao)
		{

		case 1:
		{
			Livro novoLivro;
			printf("Digite o titulo do livro: ");
			scanf(" %[^\n]", novoLivro.titulo);
			printf("Digite o autor do livro: ");
			scanf(" %[^\n]", novoLivro.autor);
			printf("Digite o genero do livro: ");
			scanf(" %[^\n]", novoLivro.genero);

			adicionaLivro(&listaLivros, novoLivro);
		}
		break;

		case 2:

			if (listaLivros.inicio != NULL)
			{
				exibirLista(&listaLivros);
			}
			else
			{
				printf("A lista de livros esta vazia\n");
			}
			break;

		case 3:
			if (livrosRetirados < 3)
			{
				retirarLivro(&listaLivros, &filaLivrosRetirados);
				livrosRetirados++;
			}
			else
			{
				printf("voce atingiu o limite de 3 livros retirados.\n");
			}
			break;

		case 4:
			exibirFilaRetirados(&filaLivrosRetirados);
			break;

		case 5:
			if (livrosRetirados > 0)
			{
				devolverLivro(&listaLivros, &filaLivrosRetirados);
				livrosRetirados--;
			}
			else
			{
				printf("nenhum livro foi retirado para ser devolvido.\n");
			}
			break;

		case 6:
			printf("Saindo da biblioteca, boa leitura!\n");
			break;

		default:
			printf("Opcao invalida! tente novamente.\n");
		}
	} while (opcao != 6);
	return 0;
}
