#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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

/*aloca memoria para fila e define cabececa, cauda e tamanho*/
struct fila *iniciaFila(){
    struct fila *f;
    /*se o malloc falhar, retorna NULL e nao realiza as outras operacaoes*/
    f = (struct fila *) malloc(sizeof(struct fila));
    if(f == NULL)
    {
        printf("erro ao alocar fila \n");
        return NULL;
    }
    /*define os ponteios e o tamanho inicial da fila*/
    f->ini = NULL;
    f->fim = NULL;
    f->tam = 0;
    return f;
}

/*retorna 1 se a fila esta cheia, 0 caso contrario*/
int filaCheia(struct fila *f){
    if(f->tam == MAXFILA)
        return 1;
    return 0;
}

/*retorna 1 se a fila esta vazia, 0 caso contrario*/
int filaVazia(struct fila *f){
    if(f->tam == 0)
        return 1;
    return 0;
}

/*enfilera elemento no fim da fila, incrementando o indice da cauda e adicionando o elemento no indice incrementado*/
void queue(struct fila *f, int x){
    /*se a fila esta cheia, nao consegue empilhar*/
    if(filaCheia(f) == 1)
    {
        printf("Fila cheia! \n");
        return;
    }
    /*cria um novo no para inserir na fila*/
    struct NoFila *novo = (struct NoFila *) malloc(sizeof(struct NoFila));
    /*atribiu o valor passado como parametro para o novo no*/
    novo->valor = x;
    /*define os ponteiros para proximo e anterior*/
    novo->prox = NULL;
    novo->ant = NULL;
    /*se a fila esta vazia, entao o fim o e inicio terao o mesmo valor ao inserir*/
    if(filaVazia(f) == 1)
    {
        f->ini = novo;
        f->fim = novo;
    }
    /*se a fila nao esta vazia, manipulacao dos ponteiros para inserir o novo elemento*/
    else
    {
        novo->ant = f->fim;
        f->fim->prox = novo;
        f->fim = novo;
    }
    /*incrementa o tamnho da fila*/
    f->tam++;
}

/*desenfilera o primeiro elemento, incrementando o indice da cabeca*/
void dequeue(struct fila *f){
    /*se a fila esta vazia nao tem como desenfilerar*/
    if(filaVazia(f) == 1)
    {
        printf("fila vazia \n");
        return;
    }
    /*aponta o antigo inicio para o proximo, e define o anterior para null*/
    struct NoFila *aux = f->ini;
    f->ini = f->ini->prox;
    f->ini->ant = NULL;
    /*libera o no que foi desenfilerado*/
    free(aux);
    /*dininui o tamanho da fila*/
    f->tam--;
}

/*imprime o primeiro elemento da fila*/
/*foi usado apenas para testes*/
void imprimeCabeca(struct fila *f){
    if(filaVazia(f) == 1)
    {
        printf("Fila Vazia \n");
        return;
    }
    printf("%d \n", f->fim->valor);
}

/*zera toda a fila e da Free*/
void destroiFila(struct fila *f){
    /*enquanto o inicio da fila nao for nulo, vai desenfileirando*/
    while(f->ini != NULL)
        dequeue(f);
    /*libera a memoria da fila*/
    free(f);
}
