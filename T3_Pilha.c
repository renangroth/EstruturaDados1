#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50

typedef struct __produto
{
    int cod;
    char nome[TAM];
    float preco;
} tp_produto;

typedef struct __pilha
{
    tp_produto *info;
    int topo;
} tp_pilha;

int estadoPilha(tp_pilha* pilha, int n)
{
    if(pilha->topo == (n-1))
    {
        //Pilha Cheia
        return 0;
    }
    else if(pilha->topo == -1)
    {
        //Pilha Vazia
        return -1;
    }
    //Aceita a entrada
    return 1;
}

void mostraEstado(int v, int n, tp_pilha* pilha)
{
    if(v == 0)
        printf("Pilha Cheia\n\n");

    else if(v == -1)
        printf("Pilha vazia\n\n");
}

void display(tp_pilha* pilha, int n)
{
    int v = estadoPilha(pilha, n);
    int i;

    if(v == -1)
        mostraEstado(v, n,  pilha);
    else
    {
        printf("Produtos:\n");
        for(i = pilha->topo; i >= 0; i--)
        {
            printf("Codigo: %d\n", ((pilha->info)+i)->cod);
            printf("Nome: %s", ((pilha->info)+i)->nome);
            printf("Preco: %.2f\n\n", ((pilha->info)+i)->preco);
        }
    }
}

void push(tp_pilha* pilha, int n)
{
    int v = estadoPilha(pilha, n);

    if(!v)
    {
        mostraEstado(v, n, pilha);
    }
    else
    {
        pilha->topo += 1;
        printf("Informe o codigo do produto: ");
        scanf("%d", &(((pilha->info)+(pilha->topo))->cod));
        fflush(stdin);
        printf("Informe o nome do produto: ");
        fgets(((pilha->info)+(pilha->topo))->nome, TAM, stdin);
        fflush(stdin);
        printf("Informe o preco do produto: ");
        scanf("%f", &(((pilha->info)+(pilha->topo))->preco));
    }
}

void pop(tp_pilha* pilha, int n)
{
    int v = estadoPilha(pilha, n);

    if(v != -1){
        pilha->topo -= 1;
        printf("Produto excluido com sucesso! \n");
    }

    else
        mostraEstado(v, n, pilha);
}

int main()
{
    int opcao, n;
    printf("Informe a quantidade de produtos que serao inseridos: ");
    scanf("%d", &n);
    fflush(stdin);
    system("clear || cls");
    tp_pilha* pilha = (tp_pilha*)malloc(sizeof(tp_pilha));
    pilha->info = (tp_produto*)malloc(sizeof(tp_produto)*n);
    pilha->topo = -1;

    do
    {
        printf("1- Inserir um produto\n");
        printf("2- Excluir o ultimo produto\n");
        printf("3- Listar todos os produtos\n");
        printf("0- Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);
        system("clear || cls");
        switch(opcao)
        {
        case 1:
            push(pilha, n);
            break;
        case 2:
            pop(pilha, n);
            break;
        case 3:
            display(pilha, n);
            break;
        }
    }
    while(opcao);

    return 0;
}
