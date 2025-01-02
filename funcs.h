#ifndef FUNCS_H
#define FUNCS_H

#include "pilha.h"
#include "fila.h"

/*define o tamanho do mapa*/
#define COL 21
#define LIN 7
/*tamanho maximo da pilha*/
#define MAXPILHA 50
/*tamanho maximo da fila*/
#define MAXFILA 50
/*tamanho maximo do pedido*/
#define MAXPEDIDO 10


/*chapeiro que tem linha e coluna para se localizar no mapa*/
struct chapeiro{
    int linha;
    int coluna;
};


struct chapeiro *criaChapeiro();

void criaMapa(char m[LIN][COL]);

void imprimeMapa(char m[LIN][COL]);

void trocabaixo(char m[LIN][COL], struct chapeiro *c);

void trocacima(char m[LIN][COL], struct chapeiro *c);

void trocadir(char m[LIN][COL], struct chapeiro *c);

void trocaesq(char m[LIN][COL], struct chapeiro *c);

void andacima(char m[LIN][COL], struct chapeiro *c);

void andabaixo(char m[LIN][COL], struct chapeiro *c);

void andadir(char m[LIN][COL], struct chapeiro *c);

void andaesq(char m[LIN][COL], struct chapeiro *c);

void movimento(char m[LIN][COL], struct chapeiro *c);

void destroiRefeicao(struct pilha *p);

void verificaRefeicao(struct pilha *pedido, struct fila *clientes, int *gop);

void adicionaAoPedido(char m[LIN][COL], struct chapeiro *c, struct pilha *pedido, struct fila *clientes, struct pilha *p, struct pilha *P, struct pilha *H, struct pilha *Q, struct pilha *S, struct pilha *F, struct pilha *R, int *gop, int *gol, int *i);

void imprimePedidos(struct fila *clientes, int i);

#endif