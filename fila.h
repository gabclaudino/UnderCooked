#ifndef FILA_H
#define FILA_H

/*define o tamanho do mapa*/
#define COL 21
#define LIN 7
/*tamanho maximo da pilha*/
#define MAXPILHA 50
/*tamanho maximo da fila*/
#define MAXFILA 50
/*tamanho maximo do pedido*/
#define MAXPEDIDO 10

/*no da fila*/
struct NoFila{
    int valor;
    struct NoFila *prox;
    struct NoFila *ant;
};

/*struct da fila a base de uma lista duplamente encadeada*/
struct fila{
    struct NoFila *ini;
    struct NoFila *fim;
    int tam;
};

struct fila *iniciaFila();

int filaCheia(struct fila *f);

int filaVazia(struct fila *f);

void queue(struct fila *f, int x);

void dequeue(struct fila *f);

void imprimeCabeca(struct fila *f);

void destroiFila(struct fila *f);

#endif
