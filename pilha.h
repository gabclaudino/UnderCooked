#ifndef PILHA_H
#define PILHA_H

/*define o tamanho do mapa*/
#define COL 21
#define LIN 7
/*tamanho maximo da pilha*/
#define MAXPILHA 50
/*tamanho maximo da fila*/
#define MAXFILA 50
/*tamanho maximo do pedido*/
#define MAXPEDIDO 10


/*no da pilha*/
struct NoPilha{
    char valor;
    struct NoPilha *prox;
};

/*struct da pilha a base de uma lista simples*/
struct pilha{
    struct NoPilha *topo;
    int tam;
};

struct pilha *criaPilha();

int pilhaCheia(struct pilha *p);

int pilhaVazia(struct pilha *p);

void pushPilha(struct pilha *p, char x);

void pilhaPop(struct pilha *p);

void destroiPilha(struct pilha *p);

void imprimirUltimo(struct pilha *p);

void preenchePilha(struct pilha *p, char x);

void imprimeRefeicao(struct pilha *p);

#endif