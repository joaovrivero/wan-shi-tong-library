#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

void inicializarLista(Lista* lista) {
	
	lista->inicio = NULL;
}

void inicializarFila(Fila* fila) {
	
	fila->inicio = NULL;
	fila->fim = NULL;
}

int adicionaLivro(Lista* lista, Livro livro) {
	
	Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
	if (novoNodo == NULL) {
		printf("Erro ao alocar memoria\n");
		return FALHA_ALOCACAO;
	}
	
	Nodo* atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->livro.titulo, livro.titulo) == 0 &&
            strcmp(atual->livro.autor, livro.autor) == 0 &&
            strcmp(atual->livro.genero, livro.genero) == 0) {
            free(novoNodo);
            return LIVRO_EXISTE;
        }
        atual = atual->proximo;
    }
	
	novoNodo->livro = livro;
	novoNodo->proximo = lista->inicio;
	lista->inicio = novoNodo;
	
	return SUCESSO;
}

void exibirLista(Lista* lista) {
	if (lista->inicio == NULL) {
		printf("a lista de livros esta vazia.\n");
		return;
	}
	
	Nodo* atual = lista->inicio;
	printf("========== Lista de Livros ==========\n");
	while(atual != NULL) {
		printf("Titulo: %s\n", atual->livro.titulo);
		printf("Autor: %s\n", atual->livro.autor);
		printf("Genero: %s\n", atual->livro.genero);
		printf("=========================\n");
		atual = atual->proximo;
	}
}

int enfileirarLivro(Fila* fila, Livro livro) {
	
	Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
	if (novoNodo == NULL) {
		printf("Erro ao alocar memoria\n");
		return FALHA_ALOCACAO;
	}
	
	novoNodo->livro = livro;
	novoNodo->proximo = NULL;
	
	if (fila->inicio == NULL) {
		fila->inicio = novoNodo;
		fila->fim = novoNodo;
	} else {
		fila->fim->proximo = novoNodo;
		fila->fim = novoNodo;
	}
	
	return SUCESSO;
}

int desenfileirarLivro(Fila* fila, Livro* livro) {
	if (fila->inicio == NULL) {
		printf("Erro: a fila esta vazia\n");
		return ESTA_VAZIA;
	}
	
	Nodo* primeiro = fila->inicio;
	*livro = primeiro->livro;
	fila->inicio = primeiro->proximo;
	free(primeiro);
	
	return SUCESSO;
}

void retirarLivro(Lista* listaLivros, Fila* filaLivrosRetirados) {
    if (listaLivros->inicio != NULL) {
        
        exibirLista(listaLivros);

        Livro livroRetirado;
        printf("Digite o titulo do livro retirado: ");
        if (scanf(" %[^\n]", livroRetirado.titulo) != 1) {
        	printf("erro ao ler o titulo do livro\n");
        	return;
		}

        Nodo* atual = listaLivros->inicio;
        Nodo* anterior = NULL;

        while (atual != NULL && strcmp(atual->livro.titulo, livroRetirado.titulo) != 0) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (atual != NULL) {
            
            if (anterior == NULL) {
                
                listaLivros->inicio = atual->proximo;
            } else {
                
                anterior->proximo = atual->proximo;
            }

            
            enfileirarLivro(filaLivrosRetirados, atual->livro);

            
            free(atual);

            printf("Livro retirado com sucesso!\n");
        } else {
            printf("Livro não encontrado na lista!\n");
        }
    } else {
        printf("A lista de livros está vazia\n");
    }
}

void devolverLivro(Lista* listaLivros, Fila* filaLivrosRetirados) {
    if (!filaVazia(filaLivrosRetirados)) {
        Livro livroDevolvido;
        int resultado = desenfileirarLivro(filaLivrosRetirados, &livroDevolvido);

        if (resultado == SUCESSO) {
            
            adicionaLivro(listaLivros, livroDevolvido);
            printf("Livro \"%s\" devolvido com sucesso!\n", livroDevolvido.titulo);
        } else {
            printf("Erro ao desenfileirar livro retirado\n");
        }
    } else {
        printf("A fila de livros retirados está vazia!\n");
    }
}

void exibirFilaRetirados(Fila* filaLivrosRetirados) {
    if (filaLivrosRetirados->inicio == NULL) {
        printf("A fila de livros retirados esta vazia.\n");
        return;
    }

    Nodo* atual = filaLivrosRetirados->inicio;
    printf("========== Livros Retirados ==========\n");

    while (atual != NULL) {
        printf("Titulo: %s\n", atual->livro.titulo);
        printf("Autor: %s\n", atual->livro.autor);
        printf("Genero: %s\n", atual->livro.genero);
        printf("=========================\n");
        atual = atual->proximo;
    }
}

int filaVazia(Fila* fila) {
    return (fila->inicio == NULL);
}




