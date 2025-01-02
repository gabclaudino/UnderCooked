#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pilha.h"

/*define o tamanho do mapa*/
#define COL 21
#define LIN 7
/*tamanho maximo da pilha*/
#define MAXPILHA 50
/*tamanho maximo da fila*/
#define MAXFILA 50
/*tamanho maximo do pedido*/
#define MAXPEDIDO 10

/*aloca memoria para a pilha e define o topo e tamanho*/
struct pilha *criaPilha(){
    /*aloca memoria para pilha, se falhar retorna NULL*/
    struct pilha *p = (struct pilha *) malloc(sizeof(struct pilha));
    if (p == NULL)
    {
        printf("Erro ao aolcar memoria para pilha! \n");
        return NULL;
    }
    /*define o ponteiro para o topo*/
    p->topo = NULL;
    /*define o tamanho inicial da fila*/
    p->tam = 0;
    return p;
}

/*retorna 1 se a pilha esta cheia, 0 caso contrario*/
int pilhaCheia(struct pilha *p){
    if(p->tam == MAXPILHA)
        return 1;
    return 0;
}

/*retorna 1 se a pilha esta vazia, 0 caso contrario*/
int pilhaVazia(struct pilha *p){
    if(p->tam == 0)
        return 1;
    return 0;
}

/*adiciona o valor na pilha seguindo sua politica*/
void pushPilha(struct pilha *p, char x){
    /*se a pilha esta cheia nao tem como empilhar*/
    if(pilhaCheia(p) == 1)
    {
        printf("Pilha cheia! \n");
        return;
    }
    /*cria o novo no para guardar o valor a sem empilhado*/
    struct NoPilha *novo = (struct NoPilha *) malloc(sizeof(struct NoPilha));
    if (novo == NULL)
    {
        printf("Erro ao alocar memoria para no da pilha! \n");
        return;
    }
    /*colocando o novo valor criado no topo da pilha*/
    novo->valor = x;
    novo->prox = p->topo;
    p->topo = novo;
    /*incrementa o tamanho da pilha*/
    p->tam++;
}

/*remove o ultimo valor adicionado na pilha*/
void pilhaPop(struct pilha *p){
    /*se a pihla esta vazia nao tem como desempilhar*/
    if(pilhaVazia(p) == 1)
    {
        printf("pilha vazia! \n");
        return;
    }
    /*no auxiliar para excluir o valor antigo e apontar o topo para o novo valor*/
    struct NoPilha *aux = p->topo;
    p->topo = aux->prox;
    aux->prox = NULL;
    /*diminui o tamanho da pilha*/
    p->tam--;
    /*libera a memoria do no que foi desempilhado*/
    free(aux);
}

/*desempilha toda a pilha e libera a memoria alocada*/
void destroiPilha(struct pilha *p){
    /*vai desenpilhando ate o topo apontar para nulo*/
    while(p->topo != NULL)
        pilhaPop(p);
    /*libera a memoria da pilha*/
    free(p);
}

/*imprime o topo da pilha*/
/*usado apenas para teste*/
void imprimirUltimo(struct pilha *p){
    /*se a pihla esta vazia, imprme pilha vazia*/
    if(pilhaVazia(p) == 1)
        printf("Pilha vazia \n");
    /*renao imprime o topo*/
    else
        printf("%c \n", p->topo->valor);
}

/*imprime a refeicao atual na tela*/
void imprimeRefeicao(struct pilha *p){
    /*utiliza um no auxiliar par apercorrer a pilha inteira*/
    struct NoPilha *aux;
    aux = p->topo;
    printf("Refeicao : ");
    /*enquanto o no for != de nulo, imprime o char*/
    while(aux != NULL)
    {
        printf("%c ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

/*preenche a pilha com o char passado por x*/
void preenchePilha(struct pilha *p, char x){
    /*variavel auxiliar para preencher a pilha ate o valor maximo definido*/
    int i;
    /*vai enfileirando o char passado por parametro ate o valor maximo*/
    for(i=0;i<MAXPILHA;i++)
        pushPilha(p,x);
}
