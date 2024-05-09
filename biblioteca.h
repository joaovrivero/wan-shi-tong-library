#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define SUCESSO 0
#define ESTA_VAZIA 1
#define LIVRO_EXISTE 2
#define FALHA_ALOCACAO 3


typedef struct {
	char titulo[100];
	char autor[100];
	char genero[50];
} Livro;

typedef struct Nodo {
	Livro livro;
	struct Nodo* proximo;
} Nodo;

typedef struct {
	Nodo* inicio;
} Lista;

typedef struct {
	Nodo* inicio;
	Nodo* fim;
} Fila;

void inicializarLista(Lista* lista);
void inicializarFila(Fila* fila);
int adicionaLivro(Lista* lista, Livro livro);
void exibirLista(Lista* lista);
int enfileirarLivro(Fila* fila, Livro livro);
int desenfileirarLivro(Fila* fila, Livro* livro);
void retirarLivro(Lista* listaLivros, Fila* filaLivrosRetirados);
void devolverLivro(Lista* listaLivros, Fila* filaLivrosRetirados);
void exibirFilaRetirados(Fila* filaLivrosRetirados);
int filaVazia(Fila* fila);


#endif
