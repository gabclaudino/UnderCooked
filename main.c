#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcs.h"
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

void main(){
    /*cria a matriz do mapa e preenche*/
    char mapa[LIN][COL];
    criaMapa(mapa);

    /*funcao srand para semente aleatoria*/
    srand(time(NULL));

    /*cria e aloca memoria para o chapeiro*/
    struct chapeiro *c = criaChapeiro();


    /*cria e aloca memoria para pilhas de ingredientes, e preenche-as com o ingrediente necessario*/
    struct pilha *paobaixo = criaPilha();
    char p = 'p';
    preenchePilha(paobaixo, p);

    struct pilha *paocima = criaPilha();
    char P = 'P';
    preenchePilha(paocima, P);

    struct pilha *hamburger = criaPilha();
    char H = 'H';
    preenchePilha(hamburger, H);

    struct pilha *queijo = criaPilha();
    char Q = 'Q';
    preenchePilha(queijo, Q);

    struct pilha *salada = criaPilha();
    char S = 'S';
    preenchePilha(salada, S);

    struct pilha *fritas = criaPilha();
    char F = 'F';
    preenchePilha(fritas, F);

    struct pilha *refri = criaPilha();
    char R = 'R';
    preenchePilha(refri, R);


    /*cria e aloca fila de clientes*/
    struct fila *clientes = iniciaFila();


    /*gera os pedidos aleatoriamente*/
    /*adiciona na fila um valor aleatorio de 0 a 5, sendo cada um deles um tipo de pedido*/
    int i;
    for(i=0;i<MAXPEDIDO;i++)
        queue(clientes,(rand() % 5));

    /* 0 - X-BURGUER*/
    /* 1 - X-SALADA*/
    /* 2 - COMBO 1*/
    /* 3 - COMBO 2*/
    /* 4 - COMBO VEGETARIANO*/
    /* 5 - COMBO VEGANO*/


    /* pilha que sera usada para a refeicao*/
    struct pilha *pedido = criaPilha();

    /*variaveis para condicao de game over
    gop = game over por pedidos errados
    gol = game over por pedidos jogados no lixo*/
    /*se gop = 3 ou gol = 5 o jogo da "game over"*/
    int gop = 0;
    int gol = 0;

    /*variavel para contar quantos pedidos foram retirados fa fila*/
    int contapedidos = 0;

    /*laco de repeticao para realizar as acoes*/
    /*enquanto o jogador nao entregar 3 pedidos errados, ou jogar 5 pedidos no lixo, 
    ou nao terminar a fila de pedidos, o laco continua rodando*/
    while((gol != 5) && (gop != 3) && (filaVazia(clientes) != 1))
    {
        printf("\n");
        /*imprime quantos pedidos foram entregues errados ate o momento*/
        printf("Pedidos entregues errados: %d\n", gop);
        /*imprime quantos pedidos foram jogados no lixo ate o momento*/
        printf("Pedidos jogados no lixo: %d\n", gol);
        /*imprime o mapa*/
        imprimeMapa(mapa);
        /*imprime os 5 primeiros pedidos*/
        imprimePedidos(clientes,contapedidos);
        /*imprime como esta a refeicao no momento, quais ingredientes estao empilhados*/
        imprimeRefeicao(pedido);
        /*chama a funcao para movimentar o chapeiro*/
        movimento(mapa,c);
        /*retira o "enter" que fica no buffer do teclado, para nao bugar na proxima vez que for digitar a tecla*/
        getchar();
        /*verifica se o chapeiro esta em alguma bancada e se sim, realiza a funcao que ela faz*/
        adicionaAoPedido(mapa,c,pedido,clientes,paobaixo,paocima,hamburger,queijo,salada,fritas,refri,&gop,&gol,&contapedidos);
    }

    /*verifica se o jogo foi ganho ou perdido*/
    /*se foram 5 pedidos jogados no lixo ou 3 pedidos entregues errados o jogador perde*/
    if((gol == 5) || (gop == 3))
        printf("Ooooops voce Perdeu ! \n");
    /*caso tenha terminado a fila de pedidos com gop < 5 e gol < 3 o jogador ganha*/
    else
        printf("Parabens voce ganhou ! \n");

    /*da free em todos os mallocs*/
    free(c);
    destroiPilha(paobaixo);
    destroiPilha(paocima);
    destroiPilha(hamburger);
    destroiPilha(queijo);
    destroiPilha(salada);
    destroiPilha(fritas);
    destroiPilha(refri);
    destroiFila(clientes);
    destroiPilha(pedido);
}