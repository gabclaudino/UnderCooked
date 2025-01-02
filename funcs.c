#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcs.h"

#define COL 21
#define LIN 7
#define MAXPILHA 50
#define MAXFILA 50
#define MAXPEDIDO 10


/*aloca o chapeiro de define a posicao inicial no mapa*/
struct chapeiro *criaChapeiro(){
    /*realiza o malloc, se falha ao alocar printa ERRO e retorna NULL*/
    struct chapeiro *c = malloc(sizeof(struct chapeiro));
    if(c == NULL){
        printf("erro ao alocar chapeiro! \n");
        return NULL;
    }
    /*define a posicao inicial do chapeiro*/
    c->linha = 2;
    c->coluna = 10;
}


/*funcao para preencher o mapa da cozinha*/
/*sim esta um nojo kkkkkkkkkk*/
/*tentei fazer parecer menos feio, porem sempre dava algum erro*/
void criaMapa(char m[LIN][COL]){
    int i;
    m[0][0] = '#';
    for(i=1;i<=8;i++)
        m[0][i] = '-';
    m[0][9] = '|';
    m[0][10] = '@';
    m[0][11] = '|';
    for(i=12;i<=19;i++)
        m[0][i] = '-';
    m[0][20] = '#';
    m[1][0] = '|';
    m[1][1] = ' ';
    m[1][2] = '[';
    m[1][3] = 'R';
    m[1][4] = ']';
    for(i=5;i<=19;i++)
        m[1][i] = ' ';
    m[1][20] = '|';
    m[2][0] = '|';
    m[2][1] = ' ';
    m[2][2] = '[';
    m[2][3] = 'F';
    m[2][4] = ']';
    m[2][5] = ' ';
    m[2][6] = ' ';
    m[2][7] = ' ';
    m[2][8] = ' ';
    m[2][9] = ' ';
    m[2][10] = '&';
    m[2][11] = ' ';
    m[2][12] = ' ';
    m[2][13] = ' ';
    m[2][14] = ' ';
    m[2][15] = ' ';
    m[2][16] = ' ';
    m[2][17] = ' ';
    m[2][18] = ' ';
    m[2][19] = 'o';
    m[2][20] = '|';
    m[3][0] = '|';
    i = 1;
    while(i<20)
    {
        m[3][i] = ' ';
        i++; 
    }
    m[3][20] = '|';
    m[4][0] = '|';
    m[4][1] = ' ';
    m[4][2] = ' ';
    m[4][3] = ' ';
    m[4][4] = ' ';
    m[4][5] = ' ';
    m[4][6] = ' ';
    m[4][7] = ' ';
    m[4][8] = ' ';
    m[4][9] = ' ';
    m[4][10] = ' ';
    m[4][11] = ' ';
    m[4][12] = ' ';
    m[4][13] = ' ';
    m[4][14] = ' ';
    m[4][15] = ' ';
    m[4][16] = ' ';
    m[4][17] = ' ';
    m[4][18] = ' ';
    m[4][19] = ' ';
    m[4][20] = '|';
    m[5][0] = '|';
    m[5][1] = '[';
    m[5][2] = 'p';
    m[5][3] = ']';
    m[5][4] = ' ';
    m[5][5] = '[';
    m[5][6] = 'H';
    m[5][7] = ']';
    m[5][8] = ' ';
    m[5][9] = '[';
    m[5][10] = 'Q';
    m[5][11] = ']';
    m[5][12] = ' ';
    m[5][13] = '[';
    m[5][14] = 'S';
    m[5][15] = ']';
    m[5][16] = ' ';
    m[5][17] = '[';
    m[5][18] = 'P';
    m[5][19] = ']';
    m[5][20] = '|';
    m[6][0] = '#';
    for(i=1;i<=19;i++)
        m[6][i] = '-';
    m[6][20] = '#';
}


/*imprimir o mapa na tela*/
void imprimeMapa(char m[LIN][COL]){
    /*variaves para me movimentar pela matriz*/
    int i;
    int j;
    /*for que vai passando por todas as linhas*/
    for(i=0;i<LIN;i++)
    {
        /*for que vai passando por todas as colunas*/
        for(j=0;j<COL;j++)
            printf("%c", m[i][j]);
        printf("\n");
    }   
    printf("\n");
}


/*funcao para trocar o caracter do chapeiro pelo de baixo*/
/*troca o chapeiro pelo caracter que esta na mesma coluna, porem na linha de baixo*/
void trocabaixo(char m[LIN][COL], struct chapeiro *c){
    char temp = m[c->linha][c->coluna];
    m[c->linha][c->coluna] = m[c->linha + 1][c->coluna];
    m[c->linha + 1][c->coluna] = temp;
}

/*funcao para trocar o caracter do chapeiro pelo de cima*/
/*troca o chapeiro pelo caracter que esta na mesma coluna, porem na linha de cima*/
void trocacima(char m[LIN][COL], struct chapeiro *c){
    char temp = m[c->linha][c->coluna];
    m[c->linha][c->coluna] = m[c->linha -1][c->coluna];
    m[c->linha - 1][c->coluna] = temp;
}

/*funcao para trocar o caracter do chapeiro pelo da direita*/
/*troca o chapeiro pelo caracter que esta na mesma linha, porem na coluna da direita */
void trocadir(char m[LIN][COL], struct chapeiro *c){
    char temp = m[c->linha][c->coluna];
    m[c->linha][c->coluna] = m[c->linha][c->coluna + 1];
    m[c->linha][c->coluna + 1] = temp;
}

/*funcao para trocar o caracter do chapeiro pelo da esquerda*/
/*troca o chapeiro pelo caracater que esta na mesma lisnha, porem na coluna da esquerda*/
void trocaesq(char m[LIN][COL], struct chapeiro *c){
    char temp = m[c->linha][c->coluna];
    m[c->linha][c->coluna] = m[c->linha][c->coluna - 1];
    m[c->linha][c->coluna - 1] = temp;
}


/*funcao de andar para cima, verifica se eh possivel andar para cima, se sim chama a trocacima(), 
caso contrario printa lugar bloqueado e nao realiza a troca */
void andacima(char m[LIN][COL], struct chapeiro *c){
    if(m[c->linha -1][c->coluna] == (' '))
    {
        trocacima(m,c);
        c->linha = c->linha - 1;
    }
    else{
        printf("Lugar Bloqueado !\n");
        return;
    }
}

/*funcao de andar para baixo, verifica se eh possivel andar para baixo, se sim chama a trocabaixo(), 
caso contrario printa lugar bloqueado e nao realiza a troca */
void andabaixo(char m[LIN][COL], struct chapeiro *c){
    if(m[c->linha +1][c->coluna] == (' '))
    {
        trocabaixo(m,c);
        c->linha = c->linha + 1;
    }
    else
    {
        printf("Lugar Bloqueado !\n");
        return;
    }
}

/*funcao de andar para direita, verifica se eh possivel andar para direita, se sim chama a trocadir(), 
caso contrario printa lugar bloqueado e nao realiza a troca */
void andadir(char m[LIN][COL], struct chapeiro *c){
    if(m[c->linha][c->coluna + 1] == (' '))
    {
        trocadir(m,c);
        c->coluna = c->coluna + 1;
    }
    else
    {
        printf("Lugar Bloqueado !\n");
        return;
    }
}

/*funcao de andar para esquerda, verifica se eh possivel andar para esquerda, se sim chama a trocaesq(), 
caso contrario printa lugar bloqueado e nao realiza a troca */
void andaesq(char m[LIN][COL], struct chapeiro *c){
    if(m[c->linha][c->coluna - 1] == (' '))
    {
        trocaesq(m,c);
        c->coluna = c->coluna - 1;
    }
    else
    {
        printf("Lugar Bloqueado !\n");
        return;
    }
}

/*funcao que movimenta o caracter do chapeiro pelo mapa, reconhece de a tecla eh w,a,s,d
e realiza o movimento, caso a tecla nao seja uma dessas, printa tecla invalida*/
void movimento(char m[LIN][COL], struct chapeiro *c){
    /*variavel que vai ser lida do teclado*/
    char op;
    /*le a variavel op do teclado*/
    scanf("%c", &op);
    /*se for pressionado w, anda para cima*/
    if(op == 'w')
        andacima(m,c);
    /*se for pressionado a, anda para a esquerda*/
    else if(op == 'a')
        andaesq(m,c);
    /*se for pressionado s, anda para baixo*/
    else if(op == 's')
        andabaixo(m,c);
    /*se for pressionado d, anda para direita*/
    else if(op == 'd')
        andadir(m,c);
    /*se a tecla pressionada nao for w,a,s,d printa erro e nao realiza nenhum movimento*/
    else
        printf("Tecla invalida! \n");
}

/*limpa a pilha do pedido e reseta a pilha*/
void destroiRefeicao(struct pilha *p){
    /*vai desenpilhado todos os valores da pilha ate ficar vazia*/
    while(p->topo != NULL)
        pilhaPop(p);
}   

/*funcao para quando for realizar a entrega no "@" verifica se o pedido que foi montado
esta correto de acordo com o que o cliente pediu*/
/*para isso, veririca qual o valor no inicio da fila, que se refere a cada um dos pedidos(esta comentado no main.c qual numero se refea aqual),
feito isso, vai verificando posicao por posicao da pilha da refeicao, desde o topo ate a base, desepilhando o elemento*/
/*se entrgue correto destroi a refeicao em maos do chapeiro e desenfilera o pedido da fila, 
se entregue errado o jogados acumula +1 ponto de gop(game over por pedido errado)*/
void verificaRefeicao(struct pilha *pedido, struct fila *clientes, int *gop){
    /*Veririfca se o X-burguer foi montado corretamente*/
    /*comeca verificando pelo topo da pilha, caso alguma posicao esteja com o ingrediente errado, entra no else e retorna,*/
    if(clientes->ini->valor == 0)
    {
        if(pedido->topo->valor == 'P')
        {
            pilhaPop(pedido);
            if(pedido->topo->valor == 'Q')
            {
                pilhaPop(pedido);
                if(pedido->topo->valor == 'H')
                {
                    pilhaPop(pedido);
                    if(pedido->topo->valor == 'p')
                    {
                        /*se o topo da Pilha, apos passar por todas as verificacoes, estiver apontando para NULL,
                        significa que a pilha esta vazia e entao o a refeicao esta correta*/
                        pilhaPop(pedido);
                        if(pedido->topo == NULL)
                        {
                            printf("\n Pedido entregue com sucesso !");
                            /*limpa a pilha da refeicao*/
                            destroiRefeicao(pedido);
                            /*desenfilera o cliente da fila*/
                            dequeue(clientes);
                            return;
                        }
                        /*caso a refeicao esteja errada o jogador recebe +1 ponto por pedido entregue errado*/
                        else
                        {
                            printf("O pedido esta errado ! \n");
                            /*limpa a pilha da refeicao*/
                            destroiRefeicao(pedido);
                            /*desenfilera o cliente da fila*/
                            dequeue(clientes);
                            /*adiciona o ponto por pedido entregue errado*/
                            *gop = *gop + 1;
                            return;
                        }
                    }
                    else
                    {
                        printf("O pedido esta errado ! \n");
                        destroiRefeicao(pedido);
                        dequeue(clientes);
                        *gop = *gop + 1;
                        return;
                    }
                }
                else
                {
                    printf("O pedido esta errado ! \n");
                    destroiRefeicao(pedido);
                    dequeue(clientes);
                    *gop = *gop + 1;
                    return;    
                }
            }
            else
            {
                printf("O pedido esta errado ! \n");
                destroiRefeicao(pedido);
                dequeue(clientes);
                *gop = *gop + 1;
                return;
            }

        }
        else
        {
            printf("O pedido esta errado ! \n");
            destroiRefeicao(pedido);
            dequeue(clientes);
            *gop = *gop + 1;
            return;    
        }
    }
    /*aplica o mesmo algoritmo do exemplo passado, porem vai mudando o elemento que deve ser veririfacado
    de a cordo com o pedido que foi feito, isso vale para todas as 6 variacoes de pedidos*/
    /*veririca se o X-salada foi montado corretamente*/
    else if(clientes->ini->valor == 1){
        if(pedido->topo->valor == 'P')
        {
            pilhaPop(pedido);
            if(pedido->topo->valor == 'S')
            {
                pilhaPop(pedido);
                if(pedido->topo->valor == 'H')
                {
                    pilhaPop(pedido);
                    if(pedido->topo->valor == 'p')
                    {
                        pilhaPop(pedido);
                        if(pedido->topo == NULL)
                        {
                            printf("\n Pedido entregue com sucesso !");
                            destroiRefeicao(pedido);
                            dequeue(clientes);
                            return;
                        }
                        else
                        {
                            printf("O pedido esta errado ! \n");
                            destroiRefeicao(pedido);
                            dequeue(clientes);
                            *gop = *gop + 1;
                            return;
                        }
                    }
                    else
                    {
                        printf("O pedido esta errado ! \n");
                        destroiRefeicao(pedido);
                        dequeue(clientes);
                        *gop = *gop + 1;
                        return;
                    }
                }
                else
                {
                    printf("O pedido esta errado ! \n");
                    destroiRefeicao(pedido);
                    dequeue(clientes);
                    *gop = *gop + 1;
                    return;    
                }
            }
            else
            {
                printf("O pedido esta errado ! \n");
                destroiRefeicao(pedido);
                dequeue(clientes);
                *gop = *gop + 1;
                return;
            }

        }
        else
        {
            printf("O pedido esta errado ! \n");
            destroiRefeicao(pedido);
            dequeue(clientes);
            *gop = *gop + 1;
            return;    
        }
    }
    /*verifica se o combo 1 foi montado corretamente*/
    else if(clientes->ini->valor == 2)
    {
        if(pedido->topo->valor == 'R')
        {
            pilhaPop(pedido);
            if(pedido->topo->valor == 'F')
            {
                pilhaPop(pedido);
                if(pedido->topo->valor == 'P')
                {
                    pilhaPop(pedido);
                    if(pedido->topo->valor == 'Q')
                    {
                        pilhaPop(pedido);
                        if(pedido->topo->valor == 'H')
                        {
                            pilhaPop(pedido);
                            if(pedido->topo->valor == 'p')
                            {
                                pilhaPop(pedido);
                                if(pedido->topo == NULL)
                                {
                                    printf("\n Pedido entregue com sucesso !");
                                    destroiRefeicao(pedido);
                                    dequeue(clientes);
                                    return;       
                                }
                                else
                                {
                                    printf("O pedido esta errado ! \n");
                                    destroiRefeicao(pedido);
                                    dequeue(clientes);
                                    *gop = *gop + 1;
                                    return;
                                }        
                            }
                            else
                            {
                                printf("O pedido esta errado ! \n");
                                destroiRefeicao(pedido);
                                dequeue(clientes);
                                *gop = *gop + 1;
                                return;
                            }
                        }
                        else
                        {
                            printf("O pedido esta errado ! \n");
                            destroiRefeicao(pedido);
                            dequeue(clientes);
                            *gop = *gop + 1;
                            return;
                        }
                    }
                    else
                    {
                        printf("O pedido esta errado ! \n");
                        destroiRefeicao(pedido);
                        dequeue(clientes);
                        *gop = *gop + 1;
                        return;
                    }
                }
                else
                {
                    printf("O pedido esta errado ! \n");
                    destroiRefeicao(pedido);
                    dequeue(clientes);
                    *gop = *gop + 1;
                    return;    
                }
            }
            else
            {
                printf("O pedido esta errado ! \n");
                destroiRefeicao(pedido);
                dequeue(clientes);
                *gop = *gop + 1;
                return;
            }

        }
        else
        {
            printf("O pedido esta errado ! \n");
            destroiRefeicao(pedido);
            dequeue(clientes);
            *gop = *gop + 1;
            return;    
        }
    }
    /*verifica se o combo 2 foi montado corretamente*/
    else if(clientes->ini->valor == 3)
    {
        if(pedido->topo->valor == 'R')
        {
            pilhaPop(pedido);
            if(pedido->topo->valor == 'F')
            {
                pilhaPop(pedido);
                if(pedido->topo->valor == 'P')
                {
                    pilhaPop(pedido);
                    if(pedido->topo->valor == 'S')
                    {
                        pilhaPop(pedido);
                        if(pedido->topo->valor == 'H')
                        {
                            pilhaPop(pedido);
                            if(pedido->topo->valor == 'p')
                            {
                                pilhaPop(pedido);
                                if(pedido->topo == NULL)
                                {
                                    printf("\n Pedido entregue com sucesso !");
                                    destroiRefeicao(pedido);
                                    dequeue(clientes);
                                    return;       
                                }
                                else
                                {
                                    printf("O pedido esta errado ! \n");
                                    destroiRefeicao(pedido);
                                    dequeue(clientes);
                                    *gop = *gop + 1;
                                    return;
                                }        
                            }
                            else
                            {
                                printf("O pedido esta errado ! \n");
                                destroiRefeicao(pedido);
                                dequeue(clientes);
                                *gop = *gop + 1;
                                return;
                            }
                        }
                        else
                        {
                            printf("O pedido esta errado ! \n");
                            destroiRefeicao(pedido);
                            dequeue(clientes);
                            *gop = *gop + 1;
                            return;
                        }
                    }
                    else
                    {
                        printf("O pedido esta errado ! \n");
                        destroiRefeicao(pedido);
                        dequeue(clientes);
                        *gop = *gop + 1;
                        return;
                    }
                }
                else
                {
                    printf("O pedido esta errado ! \n");
                    destroiRefeicao(pedido);
                    dequeue(clientes);
                    *gop = *gop + 1;
                    return;    
                }
            }
            else
            {
                printf("O pedido esta errado ! \n");
                destroiRefeicao(pedido);
                dequeue(clientes);
                *gop = *gop + 1;
                return;
            }

        }
        else
        {
            printf("O pedido esta errado ! \n");
            destroiRefeicao(pedido);
            dequeue(clientes);
            *gop = *gop + 1;
            return;    
        }
    }
    /*verifica se o combo vegetariano foi montado corretamente*/
    else if(clientes->ini->valor == 4)
    {
        if(pedido->topo->valor == 'R')
        {
            pilhaPop(pedido);
            if(pedido->topo->valor == 'F')
            {
                pilhaPop(pedido);
                if(pedido->topo->valor == 'P')
                {
                    pilhaPop(pedido);
                    if(pedido->topo->valor == 'Q')
                    {
                        pilhaPop(pedido);
                        if(pedido->topo->valor == 'p')
                        {
                            pilhaPop(pedido);
                            if(pedido->topo == NULL)
                            {
                                printf("\n Pedido entregue com sucesso !");
                                destroiRefeicao(pedido);
                                dequeue(clientes);
                                return;  
                            }
                            else
                            {
                                printf("O pedido esta errado ! \n");
                                destroiRefeicao(pedido);
                                dequeue(clientes);
                                *gop = *gop + 1;
                            return;
                            }
                        }
                        else
                        {
                            printf("O pedido esta errado ! \n");
                            destroiRefeicao(pedido);
                            dequeue(clientes);
                            *gop = *gop + 1;
                            return;
                        }
                    }
                    else
                    {
                        printf("O pedido esta errado ! \n");
                        destroiRefeicao(pedido);
                        dequeue(clientes);
                        *gop = *gop + 1;
                        return;
                    }
                }
                else
                {
                    printf("O pedido esta errado ! \n");
                    destroiRefeicao(pedido);
                    dequeue(clientes);
                    *gop = *gop + 1;
                    return;    
                }
            }
            else
            {
                printf("O pedido esta errado ! \n");
                destroiRefeicao(pedido);
                dequeue(clientes);
                *gop = *gop + 1;
                return;
            }

        }
        else
        {
            printf("O pedido esta errado ! \n");
            destroiRefeicao(pedido);
            dequeue(clientes);
            *gop = *gop + 1;
            return;    
        }
    }
    /*verifica se o combo vegano foi montado corretamente*/
    else
    {
        if(pedido->topo->valor == 'R')
        {
            pilhaPop(pedido);
            if(pedido->topo->valor == 'F')
            {
                pilhaPop(pedido);
                if(pedido->topo->valor == 'S')
                {
                    pilhaPop(pedido);
                    if(pedido->topo == NULL)
                    {
                        printf("\n Pedido entregue com sucesso !");
                        destroiRefeicao(pedido);
                        dequeue(clientes);
                        return;
                    }
                    else
                    {
                        printf("O pedido esta errado ! \n");
                        destroiRefeicao(pedido);
                        dequeue(clientes);
                        *gop = *gop + 1;
                        return;
                    }
                }
                else
                {
                    printf("O pedido esta errado ! \n");
                    destroiRefeicao(pedido);
                    dequeue(clientes);
                    *gop = *gop + 1;
                    return;    
                }
            }
            else
            {
                printf("O pedido esta errado ! \n");
                destroiRefeicao(pedido);
                dequeue(clientes);
                *gop = *gop + 1;
                return;
            }

        }
        else
        {
            printf("O pedido esta errado ! \n");
            destroiRefeicao(pedido);
            dequeue(clientes);
            *gop = *gop + 1;
            return;    
        }
    }
}


/*funcao para realizar as acoes pelo mapa, empilhar ingreditente, jogar no lixo e entregar pedido*/
void adicionaAoPedido(char m[LIN][COL], struct chapeiro *c, struct pilha *pedido, struct fila *clientes, struct pilha *p, struct pilha *P, struct pilha *H, struct pilha *Q, struct pilha *S, struct pilha *F, struct pilha *R, int *gop, int *gol, int *i){
    
    /*verifica se o chapeiro esta encostado na bancada do pao de baixo*/
    if(m[c->linha + 1][c->coluna] == 'p')
    {
        /*se sim empilha o pao de baixo na pilha da refeicao */
        pushPilha(pedido,p->topo->valor);
        /*desempilha o pao de baixo da pilha de pao de baixo*/
        pilhaPop(p);
    }
    /*verifica se o chapeiro esta encostado na bancada do pao de cima*/
    else if(m[c->linha + 1][c->coluna] == 'P')
    {
        /*se sim empilha o pao de cima na pilha da refeicao*/
        pushPilha(pedido,P->topo->valor);
        /*desempilha o pao de cima da pilha do pao de cima*/
        pilhaPop(P);
    }
    /*verifica se o chapeiro esta encostado na bancada do queijo*/
    else if(m[c->linha + 1][c->coluna] == 'Q')
    {
        /*se sim empilha o queijo na pilha da refeicao*/
        pushPilha(pedido,Q->topo->valor);
        /*desempihla o queijo da pilha de queijo*/
        pilhaPop(Q);
    }
    /*verifica se o chapeiro esta encostado na bancada da salada*/
    else if(m[c->linha + 1][c->coluna] == 'S')
    {
        /*se sim empilha a salada na pilha da refeicao*/
        pushPilha(pedido,S->topo->valor);
        /*desempilha a salada da pilha de salada*/
        pilhaPop(S);
    }
    /*verifica se o chapeiro esta encostado na bancada de hamburguer*/
    else if(m[c->linha + 1][c->coluna] == 'H')
    {
        /*se sim empilha o hamburguer na pilha da refeicao*/
        pushPilha(pedido,H->topo->valor);
        /*desempilha o hamburguer da pilha de hamburguer*/
        pilhaPop(H);
    }
    /*verifica se o chapeiro esta encostado na bancada de refri*/
    else if(m[c->linha][c->coluna - 2] == 'R')
    {
        /*se sim empilha o refri na pilha da refeicao*/
        pushPilha(pedido,R->topo->valor);
        /*desempilha o refri da pilha de refri*/
        pilhaPop(R);
    }
    /*verifica se o chapeiro esta encostado na bancada de fritas*/
    else if(m[c->linha][c->coluna - 2] == 'F')
    {
        /*se sim empilha as fritas na pilha da refeicao*/
        pushPilha(pedido,F->topo->valor);
        /*desempilha as fritas da pilha de fritas*/
        pilhaPop(F);
    }
    /*verifica se o chapeiro esta encostado no lixeiro*/
    else if(m[c->linha][c->coluna + 1] == 'o')
    {
        /*se a refeicao nao esta vazia, nao tem como jogar no lixo*/
        if(pilhaVazia(pedido) != 1)
        {
            /*printa q o peidido foi jogado no lixo*/
            printf("Pedido jogado no lixo ! \n");
            /*destroi a refeicao*/
            destroiRefeicao(pedido);
            /*o jogador rece +1 ponto por pedido jogado no lixo*/
            *gol = *gol + 1;
        }
    }
    /*chama a funcao de verificar se o pedido esta correto*/
    else if(m[c->linha -1][c->coluna] == '@')
    {
        /*so verifica se a pilha da refeicao nao estiver vazia*/   
        if(pilhaVazia(pedido) == 1)
            return;
        /*se nao esta vazia faz a verificaco da refeicao chamando a funcao veriricaRefeicao()*/
        verificaRefeicao(pedido,clientes,gop);
        /*incrementa a variavel para saber quantos pedidos foram retirados da fila*/
        *i = *i + 1;
    }
}

/*imprime os pedidos restantes dos clientes*/
void imprimePedidos(struct fila *clientes, int i){
    /*var para imprimir apenas os 5 primeiros na tela*/
    int cont = 0;
    /*no auxiliar para ir passando pelas posicoes da fila e veriricar qual pedido eh*/
    struct NoFila *aux = clientes->ini;
    /*laco que vai imprimir os 5 primeiros pedidos, ou se forem menos e 5, os restantes*/
    while((aux != NULL) && (cont<5))
    {
        /*verifica qual o pedido do cliente*/
        /*se o valor = 0, entao eh x-burguer*/
        if(aux->valor == 0)
            printf("[Cliente %d | X-Burguer] - p H Q P \n \n", i+1);
        /*se o valor = 1, entao eh x-salada*/
        else if(aux->valor == 1)
            printf("[Cliente %d | X-Salada] - p H S P \n \n", i+1);
        /*se o valor = 2, entao eh combo 1*/
        else if(aux->valor == 2)
            printf("[Cliente %d | Combo 1] - p H Q P F R \n \n", i+1);
        /*se o valor = 3, entao eh combo 2*/
        else if(aux->valor == 3)
            printf("[Cliente %d | Combo 2] - p H S P F R \n \n", i+1);
        /*se o valor = 4, entao eh vegetariano*/
        else if(aux->valor == 4)
            printf("[Cliente %d | Vegetariano] - p Q P F R \n \n", i+1);
        /*se o valor = 5, entao eh vegano*/
        else
            printf("[Cliente %d | Vegano] - S F R \n \n", i+1);
        /*passa para o proxima posicao da fila*/
        aux = aux->prox;
        /*incrementa a variavel para saber quantos pedidos foram impresos na tela*/
        cont++;
        /*varivel para saber qual a ordem do pedido*/
        i++;
    }
}


